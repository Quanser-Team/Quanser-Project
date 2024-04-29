%% preparation %%
close all
clear all
clc

%% Data dc motor model%%

Ra = 8.4;  % armature resistance
L = 1.16e-3; % armature inductance
Ke = 0.042; % torque constant
Kc =  0.042; % back-emf constant
Jm = 4e-6; % motor inertia 
Jr = 9.5e-5; % rod inertia from param estim
Br = 0; % damping coeff. estimated in previous experiments
k = 0;


%% data complete model%%

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
Jh = 0.6e-6; % module attachment moment of inertia
%Jr_ex_ = Jr + (mr+mh)*lr^2; % rotary arm "extended" moment of inertia 
Jr_ex_ = 9.5e-5;
Br_ = 1.25e-5;

mp_ = 0.02421; % pendulum mass
Lp = 0.129; % pendulum length
lp_ = 0.95*Lp/2; % pendulum CoM distance
rp = 0.0098/2; % pendulum radius
Jp_ = (1/12)*mp_*(3*rp^2 + Lp^2); % pendulum moment of inertia 
%Jp_ = 2.44e-5; 
Bp_ = 1.25e-5;


g_ = 9.81; % gravity acc

% DC motor parameters

Kc_ = 0.042; % torque constant
Ke_ = 0.042; % back-emf constant
Ra_ = 8.4; % armature resistance

theta_0 = 0;
alpha_0 = 0;
thetadot_0 = 0;
%% Neglecting electrical dynamics %%

A1 =[           0               1;
          0  ( -Br-Kc*Ke/Ra)/(Jm+Jr)];

B1 = [        0; 
      (Kc/Ra)/(Jm+Jr)];

C1 = [1   0;
      0   1];


D1 = [0;
      0];

sys_partial = ss(A1,B1,C1,D1)

eigenvalues = eig(A1)



%% Transfer Function %%


G_partial = tf(sys_partial)   % compute the transfer function matrix  
pole(G_partial(2))
zero(G_partial(2))
figure 
bode(G_partial)  % Plot the two Bode diagrams of the two transfer functions that we want ( from Va to theta and from Va to alpha)

%% only DC motor controller param %%

k1 = (100/3)/50.51;
k2 = 10/3;

%% the linearized tf from Va to theta from the complete system %%


pole1 = -0.3661 +15.2601i;
pole2 = -0.3661 -15.2601i;
pole3 = -0.7357;

zero1 = -0.0 +10.8065i;
zero2 = -0.0 -10.8065i;

num = [34.95 0 4081  ];
den = [ 1 1.468 233.5 171.4];


lin_tf = tf(num,den)

%% second controller %%

c_poles = [0.9*zero1, 0.9*zero2, 0];
c_zeros = [1.1*pole1, 1.1*pole2, 0.85*pole3];
kc1 = 100;
kc2 = 5;

Cs = zpk(c_zeros,c_poles,kc1);

Hs = 1 - 1/Cs

%1/(1-Hs)