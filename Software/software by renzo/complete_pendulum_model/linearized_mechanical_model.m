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


% Stable Point, pendulum downwards
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
%   % rotary arm centre of mass position computation:
%    l1=0.054;
%    l2=0.057;
%    l3=0.001;
%    r1=0.028/2;
%    r2=0.0065/2;
%    r3=0.0111;
%    xg1=0.006;
%    xg2= xg1 + l1/2 + l2/2;
%    xg3 = 0;
%    V1=pi*r1^2*l1;
%    V2=pi*r2^2*l2;
%    V3=pi*r3^2*l3;
%    xg = (V1*xg1 + V2*xg2 + V3*xg3)/(V1 + V2 + V3);
%   % end of computations
% lr = xg; % rotary arm CoM distance
%   % rotary arm moment of inertia computation:
%    density = mr/(V1+V2);
%    J1= (1/12)*density*V1*(3*r1^2 + l1^2);
%    J2= (1/12)*density*V2*(3*r2^2 + l2^2);
%    J3 = 0.6e-6;
%    Jtot = (J1 + density*V1*(xg1-xg)^2) + (J2 + density*V2*(xg2-xg)^2) + J3;
%    % end of computations
% Jr = Jtot; % rotary arm moment of inertia
Jh = 0.6e-6 + 4e-6; % module attachment moment of inertia and rotor inertia
%Jr_ex_ = Jr + (mr+mh)*lr^2; % rotary arm "extended" moment of inertia 
Jr_ex_ = 9.5e-5 + Jh; %total moment of inertia of the rod around the pivot
Br_ = 0;
%Br_ = 3.8e-6;

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


%% load exp data %

path = 'exp_data/sqwv1V5Hz';

load(append(path,'/omega.mat'));
load(append(path,'/theta.mat'));
load(append(path,'/phi.mat'));

load(append(path,'/omega_sim.mat'));
load(append(path,'/theta_sim.mat'));
load(append(path,'/phi_sim.mat'));

time_vector_omega = omega(1,:);
omega_vector =(pi/180)*omega(2,:); % converted in rad/s
ts_omega = timeseries(omega_vector,time_vector_omega);

time_vector_theta = theta(1,:);
theta_vector =(pi/180)*theta(2,:); % converted in rad
ts_theta = timeseries(theta_vector,time_vector_theta);

time_vector_phi = phi(1,:);
phi_vector =(pi/180)*phi(2,:); % converted in rad
ts_phi = timeseries(phi_vector,time_vector_phi);


