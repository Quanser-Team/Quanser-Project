clear
clc
close all

%% Non-Linear Model
syms t theta0(t) theta1(t) L0 l1 g m1 I0 I1 Br Bp Te

Xx = L0*cos(theta0)-l1*sin(theta1)*sin(theta0);
Xy = L0*sin(theta0)+l1*sin(theta1)*cos(theta0);
Xz = l1*cos(theta1);

Xx_dot = diff(Xx,t);
Xy_dot = diff(Xy,t);
Xz_dot = diff(Xz,t);

Vcm_square = simplify(Xx_dot^2 + Xy_dot^2 + Xz_dot^2);

% Kinetic Energy
Ttotal = simplify(1/2*I0*diff(theta0,t)^2+1/2*m1*Vcm_square+1/2*I1*diff(theta1,t)^2);   
% Gravitational Potential Energy
Utotal = m1*g*l1*(cos(theta1)-1);

Ltotal = Ttotal - Utotal;

% Lagrange Equations
eq1 = simplify(diff(diff(Ltotal,diff(theta0,t)),t)-diff(Ltotal,theta0)) - Te + Bp*diff(theta0,t);
eq2 = simplify(diff(diff(Ltotal,diff(theta1,t)),t)-diff(Ltotal,theta1)) + Br*diff(theta1,t);


%% Linearized Model 

% Stable Point
theta0_0 = 0;
thetadot0_0 = 0;
thetadotdot0_0 = 0;
theta1_0 = pi;  % Pendulum DOWNWARD
thetadot1_0 = 0;
thetadotdot1_0 = 0;

eq1_lin_stable = linearize_function(eq1, theta0, theta1, t, theta0_0, theta1_0, thetadot0_0, thetadot1_0, thetadotdot0_0, thetadotdot1_0);
eq2_lin_stable = linearize_function(eq2, theta0, theta1, t, theta0_0, theta1_0, thetadot0_0, thetadot1_0, thetadotdot0_0, thetadotdot1_0);

% Unstable Point
theta0_0 = 0;
thetadot0_0 = 0;
thetadotdot0_0 = 0;
theta1_0 = 0;  % Pendulum UPWARD
thetadot1_0 = 0;
thetadotdot1_0 = 0;

eq1_lin_unstable = linearize_function(eq1, theta0, theta1, t, theta0_0, theta1_0, thetadot0_0, thetadot1_0, thetadotdot0_0, thetadotdot1_0);
eq2_lin_unstable = linearize_function(eq2, theta0, theta1, t, theta0_0, theta1_0, thetadot0_0, thetadot1_0, thetadotdot0_0, thetadotdot1_0);
