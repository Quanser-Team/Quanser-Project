
t=Phi.time;
Phi_model=Phi_model.signals.values(:,1);
Phi=Phi.signals.values(:,1);
hold on
plot(t,Phi)
plot(t,Phi_model)
grid on, box on;
%%
t=Theta.time;
Theta=Theta.signals.values(:,1);
Theta_model=Theta_model.signals.values(:,1);
hold on
plot(t,Theta)
plot(t,Theta_model)
grid on, box on;

%%
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
M = [m1*l0^2 + j0 + m0*lx^2, -l0*l1*m1; -l0*l1*m1, m1*l1^2 + j1];
K = [0, 0; 0, g*l1*m1];

% Around 0 (UPWARD)
%M = [m1*l0^2 + j0 + m0*lx^2, l0*l1*m1; l0*l1*m1, m1*l1^2 + j1];
%K = [0, 0; 0, -g*l1*m1];


% State Space for Pendulum_Statespace
A_1 = [M [0 0;0 0];
    0 0 1 0;
    0 0 0 1];
A_2 = [[-kt*kt/Rm-d_theta 0;0 -d_phi] -K;
    1 0 0 0;
    0 1 0 0];
B_1 = [kt/Rm 0 0 0]';
A = A_1\A_2;
B = A_1\B_1;

% To have all states as output, use
 C = eye(4);
 D = zeros(4,1);