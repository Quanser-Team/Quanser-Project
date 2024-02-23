clc
close all
clear
%%
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
period = 2*pi*sqrt(l1_tot^3*2/(3*g*l1));

% Initial and final time
t0 = 0; 
tf = 3;

% initial and final states
% pi/6 -pi/4 pi
th_i = 0;
th_f = 0;
phi_i = 0;
phi_f = 100*pi/180;
thp_i = 0;
thp_f = 0;
phip_i = 5;
phip_f = 0;

% Boundary conditions
x_i = [thp_i; phip_i; th_i; phi_i];                   % initial values for states
x_f = [thp_f;phip_f; th_f; phi_f];

nx = 4; % Number of states
nu = 1; % number of inputs
N = 501; % number of temporal steps
h = tf/(N-1); % temporal discretization



nlobj = nlmpc(nx,nx,nu);
Ts = 0.1;
nlobj.Ts = Ts;
nlobj.Model.IsContinuousTime = true;
nlobj.PredictionHorizon = 20;
nlobj.ControlHorizon = 1;
nlobj.Model.StateFcn = 'dx_fun';
nlobj.Weights.ManipulatedVariables = 0.0;
nlobj.OV(3).Min = -pi/2;
nlobj.OV(3).Max = pi/2;
nlobj.MV.Min = -5;
nlobj.MV.Max = 5;
nlobj.Weights.OutputVariables = [0.0 0.0 0.5 1];
%nlobj.Jacobian.OutputFcn =@(x,u) eye(4);

x0 = [0.1;0.2;-pi/2;0.3];
u0 = 0.4;
validateFcns(nlobj,x0,u0);


%% Simscape

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
alpha_0 = 0;









