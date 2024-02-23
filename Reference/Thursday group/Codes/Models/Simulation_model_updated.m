clc
close all
clear

%Variables
% NOTE1 I used the variables from the manual, NOT the measured ones
% NOTE 2 For the moment of inertia of the arm (j0) I just added the moment of
% inertia just of the arm rod (m0*l0^2/12) and the inertia of the rotor.
% Also, for now I will consider null the distance between the center of
% mass of the arm and the motor (lx).

l0 = 0.085;
l1 = 0.129/2;
m0 = 0.095;
m1 = 0.024;
% Motor parameters
Jm = 4*10^(-6); %Rotor inertia
kt = 0.042; %Torque constant
Rm = 8.4; %Terminal Resistance
Lm = 1.16; %Rotor Inductance

j0 = m0*l1^2/2 + Jm;
j1 = m1*(l1*2)^2/12;
lx = 0;
g = 9.81;

% Matrices
% Around pi
M = [m1*l0^2 + j0 + m0*lx^2, l0*l1*m1; l0*l1*m1, m1*l1^2 + j1];
K = [0, 0; 0, g*l1*m1];

% Around 0
%M = [m1*l0^2 + j0 + m0*lx^2, -l0*l1*m1; -l0*l1*m1, m1*l1^2 + j1];
%K = [0, 0; 0, -g*l1*m1];

% Control Gains
kp = 6;
ki = 0;
kd = 0.15;

% Transfer functions for Simulink
s = tf('s');
TF = (M*s*s+K)^-1;

[num1, den1] = tfdata(TF(1,1), 'v');
[num2, den2] = tfdata(TF(2,1), 'v');
[num3, den3] = tfdata(TF(1,2), 'v');
[num4, den4] = tfdata(TF(2,2), 'v');

% State Space 
A_1 = [M [0 0 0;0 0 0];
    0 0 0 0 Lm;
    0 0 1 0 0;
    0 0 0 1 0];
A_2 = [[0 0;0 0] -K [kt;0];
    -kt 0 0 0 -Rm;
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
Td = 0.15/6;
Ti = 1;

G_star = [kt*kt*s/(Lm*s+Rm), 0;0, 0];
G = (M*s*s+K+G_star);
v = [kt*(1+Td*s+1/(Ti*s))/(Lm*s+Rm); 0];
GH = G\v;
GH1 = GH(2);

figure(1)
rlocus(GH1);
figure(2)
bode(GH1);
figure(3)
nyquist(GH1);

L = 1/(1+GH1);


%% Pole Placement

p = [0 -1 -6 -7 -8]';
K_pp = place(A,B,p);
