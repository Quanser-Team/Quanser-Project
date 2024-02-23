clear all; close all; clc;

%Inverted pendulum model parameters: run this block to initialise simscape
%pendulum model parameters

% DC Motor Parameters
kt = 0.042;   % torque constant
km = 0.042;   % motor back-emf constant
R = 8.4;      % motor resistance
L = 0.85e-3;  % motor inductance

% Inverted Pendulum Parameters: lengths are in [cm] and mass in [kg]
base_size = 7;    % length of pendulum base cube

% Rotary arm parameters
rod_rad = 1;          % rotary arm radius
rod_length = 8.5;     % rotary arm length
rod_mass = 0.095;     % rotary arm mass

% Pendulum parameters
p_rad = 1;          % pendulum radius
p_length = 12.9;    % pendulum length
p_mass = 0.024;     % pendulum mass

rt1 = base_size/2;
rt2 = rod_length-0.4;
rt4 = p_length/2;
D_r = 0.0015/2;     % damping coeff. of rotary arm
D_p = 0.0005/2;     % damping coeff. of pendulum

% Initial pendulum intial angle in degrees
% 180 corresponds to upright position
% can also be selected in the simulink model
alpha_0 = 170;

