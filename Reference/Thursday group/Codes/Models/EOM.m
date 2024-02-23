clear
clc
close all

%% Nonlinear EOM
syms t theta(t) phi(t) l0 l1 m0 m1 j0 j1 lx g;
x = l0*cos(theta)+l1*sin(phi)*sin(theta);
y = -l0*sin(theta) + l1*sin(phi)*cos(theta);
z = l1*cos(phi);

xdot = diff(x, t);
ydot = diff(y, t);
zdot = diff(z, t);

v1_squared = simplify(xdot^2 + ydot^2 + zdot^2);
v0_squared = (lx*diff(theta,t))^2;

% Kinetic energy
Ek = simplify(m0*v0_squared/2 + (j0*diff(theta,t)^2)/2 + m1*v1_squared/2 + (j1*diff(phi,t)^2)/2);

% Potential Energy
Vg = m1*g*l1*cos(phi);

% Lagrange Equations
eq1 = simplify(diff(diff(Ek,diff(theta,t)),t)-diff(Ek,theta)+diff(Vg,theta));
eq2 = simplify(diff(diff(Ek,diff(phi,t)),t)-diff(Ek,phi)+diff(Vg,phi));

% The full nonlinear system it's eq1 = T; eq2 = 0.

%% Linearized EOM
% Equilibrium points
theta0 = pi;
phi0 = pi;
thetadot0 = 0;
phidot0 = 0;
thetadotdot0 = 0;
phidotdot0 = 0;

eq1_lin = linearize_function(eq1, theta, phi, t, theta0, phi0, thetadot0, phidot0, thetadotdot0, phidotdot0);
eq2_lin = linearize_function(eq2, theta, phi, t, theta0, phi0, thetadot0, phidot0, thetadotdot0, phidotdot0);

%% Matrix form 
M = [m1*l0^2 + j0 + m0*lx^2, l0*l1*m1;l0*l1*m1, m1*l1^2 + j1];
K = [0, 0; 0, g*l1*m1];

% Equations in form M*[thetadotdot; phidotdot] + K[theta;phi] = [T, 0]

