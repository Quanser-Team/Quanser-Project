%% preparation %%
close all
clear all
clc


%% Nonlinear system computation %%

syms t theta(t) alpha(t) tau Lr lp Jr_ex mp Jp g Bp Br

Xx = Lr*cos(theta)+lp*sin(alpha)*sin(theta);
Xy = -Lr*sin(theta)+lp*sin(alpha)*cos(theta);
Xz = -lp*cos(alpha);

Xx_dot = diff(Xx,t);
Xy_dot = diff(Xy,t);
Xz_dot = diff(Xz,t);

Vcm_square = simplify(Xx_dot^2 + Xy_dot^2 + Xz_dot^2);

% Kinetic Energy
Ttotal = simplify(1/2*Jr_ex*diff(theta,t)^2+1/2*mp*Vcm_square+1/2*Jp*diff(alpha,t)^2);   
% Gravitational Potential Energy
Utotal = -mp*g*lp*(cos(alpha));

Ltotal = Ttotal - Utotal;

% Lagrange Equations
eq1 = simplify(diff(diff(Ltotal,diff(theta,t)),t)-diff(Ltotal,theta)) - tau + Br*diff(theta,t);
eq2 = simplify(diff(diff(Ltotal,diff(alpha,t)),t)-diff(Ltotal,alpha)) + Bp*diff(alpha,t);

%% Adding DC motor model

syms Va Ke Kc Ra

eq1 = subs(eq1, tau , (Kc/Ra)*Va-(Kc*Ke/Ra)*diff(theta,t));


%% Linearized Model 

% Unstable Point, pendulum upwards
% theta_0 = 0;
% thetadot_0 = 0;
% thetadotdot_0 = 0;
% alpha_0 = pi;  % Pendulum UPWARDS
% alphadot_0 = 0;
% alphadotdot_0 = 0;
% Va_0 = 0; 


%  Stable Point, pendulum downwards
theta_0 = 0;
thetadot_0 = 0;
thetadotdot_0 = 0;
alpha_0 = 0;  % Pendulum DOWNWARDS
alphadot_0 = 0;
alphadotdot_0 = 0;
Va_0 = 0;


eq1_lin = linearize_function(eq1, theta, alpha, t, theta_0, alpha_0, thetadot_0, alphadot_0, thetadotdot_0, alphadotdot_0);
eq2_lin = linearize_function(eq2, theta, alpha, t, theta_0, alpha_0, thetadot_0, alphadot_0, thetadotdot_0, alphadotdot_0);

%% Compute the linearized model state space matrices %%

syms dx1(t) dx2(t) dx3(t) dx4(t)

% theta=dx1  alpha=dx2  theta_dot=dx3 alpha_dot=dx4

m11 = 1;              
m12 = 0;
m13 = 0;
m14 = 0;

m21 = 0;
m22 = 1;
m23 = 0;
m24 = 0;

m31 = 0;
m32 = 0;
m33 = diff(eq1_lin,diff(theta,t,t));
m34 = diff(eq1_lin,diff(alpha,t,t));

m41 = 0;
m42 = 0;
m43 = diff(eq2_lin,diff(theta,t,t));
m44 = diff(eq2_lin,diff(alpha,t,t));

n11 = 0;              
n12 = 0;
n13 = -1;
n14 = 0;

n21 = 0;
n22 = 0;
n23 = 0;
n24 = -1;

n31 = diff(eq1_lin,theta);
n32 = diff(eq1_lin,alpha);
n33 = diff(eq1_lin,diff(theta,t));
n34 = diff(eq1_lin,diff(alpha,t));

n41 = diff(eq2_lin,theta);
n42 = diff(eq2_lin,alpha);
n43 = diff(eq2_lin,diff(theta,t));
n44 = diff(eq2_lin,diff(alpha,t));

p11 = 0;
p21 = 0;
p31 = diff(eq1_lin,Va);
p41 = diff(eq2_lin,Va);

M = [m11,m12,m13,m14;
     m21,m22,m23,m24;
     m31,m32,m33,m34;
     m41,m42,m43,m44];
N = [n11,n12,n13,n14;
     n21,n22,n23,n24;
     n31,n32,n33,n34;
     n41,n42,n43,n44];
P = [p11;
     p21;
     p31;
     p41];


A = M^(-1)*(-N);
B = M^(-1)*(-P);
C = [1,0,0,0;
     0,1,0,0;
     0,0,1,0;
     0,0,0,1];
D = [0;
     0;
     0;
     0];

%% data %%

% mechanical parameters

mr = 0.09183; % rotary arm mass
mh = 0.0106; % rotary hub mass
Lr_ = 0.09; % rotary arm length
Jh = 0.6e-6; % module attachment moment of inertia
Jr_ex_ = 9e-5;
Br_ = 0;

mp_ = 0.02421; % pendulum mass
Lp = 0.129; % pendulum length
lp_ = 0.95*Lp/2; % pendulum CoM distance
rp = 0.0098/2; % pendulum radius
Jp_ = (1/12)*mp_*(3*rp^2 + Lp^2); % pendulum moment of inertia 
%Jp_ = 2.44e-5; 
%Bp_ = 1.25e-5;
Bp_ = 0;

g_ = 9.81; % gravity acc

% DC motor parameters

Kc_ = 0.042; % torque constant
Ke_ = 0.042; % back-emf constant
Ra_ = 8.4; % armature resistance


%% state space representation

A = double(subs(A,[Lr lp Jr_ex mp Jp g Ke Kc Ra Br Bp],[Lr_ lp_ Jr_ex_ mp_ Jp_ g_ Ke_ Kc_ Ra_ Br_ Bp_]));
B = double(subs(B,[Lr lp Jr_ex mp Jp g Ke Kc Ra Br Bp],[Lr_ lp_ Jr_ex_ mp_ Jp_ g_ Ke_ Kc_ Ra_ Br_ Bp_]));

sys = ss(A,B,C,D)

eigenvalues = eig(A)

%% Transfer Function of the linearized system %%


G_tot = tf(sys)   % compute the transfer function matrix  
figure 
bode(G_tot)  % Plot the two Bode diagrams of the two transfer functions that we want ( from Va to theta and from Va to alpha)
pole(G_tot(2))
zero(G_tot(2))

%% %% Pole Placement in phi_bar == 180 %%
close all
rank(ctrb(A,B))     % == 4 so OK!

% Desired poles
 P = [0.5+10.5i 0.5-10.5i -50 -100] ;
% P = [-3, -3+4i, -3-4i, -115] ;
K = place(A,B,P) ;

syst_cl = tf(ss(A-B*K,B,C,D))
figure
% step(syst_cl)
impulse(syst_cl)
ss_gain = 1/dcgain(syst_cl) 

%% MPC

% nx = 4;
% ny = 1;
% nu = 1;
% nlobj = nlmpc(nx,ny,nu)
% nlobj.Model.StateFcn = "QUBE2_Mechanical_Formulation";
% nlobj.Model.IsContinuousTime = true;
% nlobj.Model.OutputFcn = @(x,u,Ts) [x(1); x(3)];

