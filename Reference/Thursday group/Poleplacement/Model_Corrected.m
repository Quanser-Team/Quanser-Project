clc
close all
clear

%Variables
% NOTE 1 Some of the values are the measured ones, the others are from the
% manual.
% NOTE 2 For the moment of inertia of the arm (j0) I just added the moment of
% inertia just of the arm rod (m0*l0^2/12) and the inertia of the rotor.
% Also, for now I will consider null the distance between the center of
% mass of the arm and the motor (lx).

% Arm and Pendulum parameters. 0 for the arm, 1 for the pendulum.
l0 = 0.085; 
l1_tot = 0.12886/2;
l1 = l1_tot-0.0075;
m0 = 0.095;
m1 = 0.024;
% Damping, put here values when measured
d_phi = 2.6173e-06;
d_theta = 0;

% Motor parameters
Jm = 4*10^(-6); %Rotor inertia
kt = 0.042; %Torque constant
Rm = 8.4; %Terminal Resistance
Lm = 1.16*10^(-3); %Rotor Inductance

j0 = m0*l0^2/2 + Jm;
j1 = m1*(l1_tot*2)^2/12;
lx = 0; 
g = 9.81;

% Matrices

%Damping
Damp = [d_theta, 0; 0, d_phi];

% Around pi (DOWNWARD)
M = [m1*l0^2 + j0 + m0*lx^2, l0*l1*m1; l0*l1*m1, m1*l1^2 + j1];
K = [0, 0; 0, g*l1*m1];

% Around 0 (UPWARD)
M = [m1*l0^2 + j0 + m0*lx^2, -l0*l1*m1; -l0*l1*m1, m1*l1^2 + j1];
K = [0, 0; 0, -g*l1*m1];

% Control Gains
kp = 6;
ki = 5;
kd = 5;

% Transfer functions for Pendulum_Sim
s = tf('s');
TF = (M*s*s+Damp*s+K)^-1;

[num1, den1] = tfdata(TF(1,1), 'v');
[num2, den2] = tfdata(TF(2,1), 'v');
[num3, den3] = tfdata(TF(1,2), 'v');
[num4, den4] = tfdata(TF(2,2), 'v');

% State Space for Pendulum_Statespace
A_1 = [M [0 0 0;0 0 0];
    0 0 0 0 Lm;
    0 0 1 0 0;
    0 0 0 1 0];
A_2 = [[-d_theta 0;0 -d_phi] -K [-kt;0];
    kt 0 0 0 -Rm;
    1 0 0 0 0;
    0 1 0 0 0];
B_1 = [0 0 1 0 0]';
A = A_1\A_2;
B = A_1\B_1;

% To have just phi as output, use
%C = [0 0 0 1 0];
%D = [0 0];

% To have all states as output, use
 C = eye(5);
 D = zeros(5,1);


%% Stability Analysis
kp = 6;
Td = 5/6;
Ti = 6/5;

G_star = [kt*kt*s/(Lm*s+Rm), 0;0, 0];
G = minreal(M*s*s+Damp*s+K+G_star);
v = [-kt*(1+Td*s+1/(Ti*s))/(Lm*s+Rm); 0];
GH = G\v;
GH2 = GH(2);

figure(1)
rlocus(GH2);
figure(2)
bode(GH2);
figure(3)
nyquist(GH2);

Gg = minreal(M*s*s+Damp*s+K+[kt*kt*s/(Lm*s+Rm),...
     -kt*kp*(1+Td*s+1/(Ti*s))/(Lm*s+Rm);0, 0]);
v_star = minreal([-kt*kp*(1+Td*s+1/(Ti*s))/(Lm*s+Rm); 0]);

L = minreal(Gg\v_star);



%% Pole Placement 
% For Pendulum_Poleplacement, uncomment when running the simulink model


p1 = [-1 -5 -10 -15 -20]*100;
% p = pole(L(2));
% p = p(4:8);


K_pp = place(A,B,p1);

%% Estimator

phi0 = 0;
phidot0 = 0.1;
C = [1 0 0 0 0;0 1 0 0 0;0 0 1 0 0;0 0 0 1 0];
D = zeros(4,1);
q = [-1 -2 -3 -4 -5]*1;
L = place(A',C',q);
L = L';
A_xi = (A-L*C-(B-L*D)*K_pp);
C_xi = eye(5);
D_xi = zeros(5,4);

