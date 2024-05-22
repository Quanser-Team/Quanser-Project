clear all
close all

%% Motor
% Resistance
Rm = 9.7; % nominal value = 8.4;
% Current-torque (N-m/A)
kt = 0.042;
% Back-emf constant (V-s/rad)
km = kt;
%
%% Rotary Arm
% Mass (kg)
mr = 0.095;
% Total length (m)
r = 0.085;
% Moment of inertia about pivot (kg-m^2)
Jr = mr*r^2/3;
% Equivalent Viscous Damping Coefficient (N-m-s/rad)
br = 1e-3; % damping tuned heuristically to match QUBE-Servo 2 response
% 
%% Pendulum Link
% Mass (kg)
mp = 0.024;
% Total length (m)
Lp = 0.129;
% Pendulum center of mass (m)
l = Lp/2;
% Moment of inertia about pivot (kg-m^2)
Jp = mp*Lp^2/3;
% Equivalent Viscous Damping Coefficient (N-m-s/rad)
bp = 5e-5; % damping tuned heuristically to match QUBE-Sero 2 response
% Gravity Constant
g = 9.81;

%% load exp data %

path = 'exp_data/sqwv05V05Hz';

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


