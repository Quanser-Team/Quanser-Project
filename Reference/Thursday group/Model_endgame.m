%%Final version of the model

close all
clear all
clc
%%
%Variables
% For the moment of inertia of the arm (j0) we just added the moment of
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
d_theta = 8.7409e-05;  %NOTE: for estimation of this check proper code on onedrive;


% Motor parameters
Jm = 4*10^(-6); %Rotor inertia
kt = 0.042; %Torque constant
Rm = 8.4; %Terminal Resistance
Lm = 1.16*10^(-3); %Rotor Inductance
j0 = m0*l0^2/2 + Jm;
j1 = m1*(l1_tot*2)^2/12;
lx = 0; 
g = 9.81;
k_theta=1.1719e-04;

% Matrices

%Damping
Damp = [d_theta, 0; 0, d_phi];
% 
% % % Around pi (DOWNWARD)
% M = [m1*l0^2 + j0 + m0*lx^2, -l0*l1*m1; -l0*l1*m1, m1*l1^2 + j1];
% K = [0, 0; 0, g*l1*m1];


% % Around 0 (UPWARD)
M = [m1*l0^2 + j0 + m0*lx^2, l0*l1*m1; l0*l1*m1, m1*l1^2 + j1];
K = [k_theta, 0; 0, -g*l1*m1];

% Control Gains
kp = 6;
ki = 5;
kd = 5;

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
% %%
% % Pole Placement 
% % Select the pole and then run the simulink model
% ic = [0 0 0 0.5];
% p = [-1.2 -7.5 -18 -30];
% % p_obs = [-0.5 -4 -8 -12];
% % k_trans = place(A',C',p_obs);
% % k_pp_obs = k_trans';
% K_pp = place(A,B,p);
% A_star=A-B*K_pp;   %new state matrix
% eig(A_star)       %check that eig(A)=p;
%%

% LQR 
% Lqr implementation 
ic = [0 0 0 0];
thetadot0 = 0;
phidot0 = 10;
theta0 = 0;
phi0 = 0;
Q = [0 0 0 0;
    0 0 0 0;
    0 0 62 0;
    0 0 0 2];
R = 10;
[K_pp, S, P] = lqr(A,B,Q,R);

% % Kalman
% ts = 0.0005;
% ic = [0 0 0.1];
% A_k = [A(1,1) A(1,2) A(1,4);A(2,1) A(2,2) A(2,4);A(4,1) A(4,2) A(4,4)];
% B_k = [B(1) B(2) B(4)]';
% [V,D_i] = eig(A_k);
% I = [1 0 0 ; 0 1 0 ; 0 0 1];
% Ad = real(V*(D_i^ts)*inv(V));
% Bd = A_k\(Ad-I)*B_k;
% Cd = eye(3);
% Dd = zeros(3,1);
% Kalman_ss = ss(Ad,Bd,Cd,Dd);
% 
% Ti=0:ts:40;
% NN=length(Ti);
% Q=0.01;
% R=0.01;
% w=sqrt(Q)*rand(NN,1);
% v=sqrt(R)*rand(NN,1);
% 
% w=[Ti',w];
% v=[Ti',v];

%%
figure()
t=phi_obs.time;
Phi_obs = phi_obs.signals.values(:,1);
phi = Phi.signals.values(1,1,:);
hold on
plot(t,Phi)
holdo n
plot(t,Phi_obs)
grid on, box on;
%% Checking whether the theorical responces and the actual ones are similar

figure()
t=Phi.time;
Phi=Phi.signals.values;
% Phi=Phi.*pi/180;
Theta=theta.signals.values(:,1);
plot(t,Phi)
hold on
phi_obs=phi_obs.signals.values(:);
% % phi=phi_obs.*pi/180;
plot(t,phi_obs)
% grid on, box on;
legend('Phi','Phi_Kalman')
%%
figure()
Theta=Theta.signals.values(:,1);
% Theta_model=Theta_model.signals.values(:,1);
% hold on
plot(t,Theta)
% plot(t,Theta_model)
% grid on, box on;
% %% Motor rotor parameters estimation 
% m=0.053;
% r=0.0248;
% J=1/2*m*r^2;
% chi=0.2606;
% omega_n=2.6815;
% 
% %Estimation of the parameters 
% k_theta= omega_n^2*J;
% d_theta=2*J*omega_n;


%% Linear MPC

mpc_model = ss(A,B,C,D);

mpc_model.InputName = {'Voltage'};
mpc_model.OutputName = {'theta_dot', 'phi_dot', 'theta', 'phi'};
mpc_model.StateName = {'theta_dot', 'phi_dot', 'theta', 'phi'};
mpc_model.InputGroup.MV = 1;
mpc_model.OutputGroup.MO = [1 2 3 4];


