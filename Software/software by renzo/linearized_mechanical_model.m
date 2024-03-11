%% preparation %%
close all
clear all
clc
%% data %%

% mechanical parameters

mr = 0.095; % rotary arm mass
mh = 0.0106; % rotary hub mass
Lr = 0.085; % rotary arm length
  % rotary arm centre of mass position computation:
   l1=;
   l2=;
   l3=;
   r1=0.028/2;
   r2=0.0065/2;
   r3=;
   xg1=;
   xg2= xg1 + l1/2 + l2/2;
   xg3 = 0;
   V1=pi*r1^2*l1;
   V2=pi*r2^2*l2;
   V3=pi*r3^2*l3;
   xg = (V1*xg1 + V2*xg2 + V3*xg3)/(V1 + V2 + V3);
  % end of computations
lr = xg; % rotary arm CoM distance
  % rotary arm moment of inertia computation:
   density = (V1+V2)/mr;
   J1= (1/12)*density*V1*(3*r1^2 + l1^2);
   J2= (1/12)*density*V2*(3*r2^2 + l2^2);
   J3 = 0.6e-6;
   Jtot = (J1 + density*V1*(xg1-xg)^2) + (J2 + density*V2*(xg2-xg)^2) + J3;
   % end of computations
Jr = Jtot; % rotary arm moment of inertia
Jh = 0.6e-6; % module attachment moment of inertia
Jr_ex = Jr + (mr+mh)*lr^2 + Jh; % rotary arm "extended" moment of inertia 

mp = 0.024; % pendulum mass
Lp = 0.129; % pendulum length
lp = Lp/2; % pendulum CoM distance
rp = 0.0098/2; % pendulum radius
Jp = (1/12)*mp*(3*rp^2 + Lp^2); % pendulum moment of inertia 

% DC motor parameters

Kc = 0.042; % torque constant
Ke = 0.042; % back-emf constant
Ra = 8.4; % armature resistance

% composite parameters

a = Jr_ex + mp*Lr^2;
b = mp*Lr*lp;
c = mp*9.81*lp;
d = Jp + mp*lp^2;
e = Kc/Ra;
f = (Kc*Ke)/Ra;

%% Compute the linearized model state space representation %%

M1 = [1,0,0,0;
      0,1,0,0;
      0,0,a,b;
      0,0,b,d];
M2 = [0,0,1,0;
      0,0,0,1;
      0,0,-f,0;
      0,c,0,0];
M3 = [0;
      0;
      e;
      0];


A = M1^(-1)*M2 
B = M1^(-1)*M3
C = [1,0,0,0;
     0,1,0,0];
D = 0;

sys = ss(A,B,C,D)

eigenvalues = eig(A)






