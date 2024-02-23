clc;
clear;

%% PARAMETERS

%----------------CONSTANTS-----------------
g = 9.81;                % accelerazione di gravità
Bp = 2.0052e-5;          % viscous damping pendulum, to be estimated
Br = 6e-5;     %1.3364e-5;  % viscous damping rotary arm, to be estimated
%----------------PENDULUM------------------
Lp = 0.129;             % pendulum lenght
l = Lp/2;
r = 0.085;              % arm lenght
Mp = 0.024;             % pendulum mass
Mr = 0.095;             % arm mass
Jr = 8.2282e-5;  %Mr*r^2/3;    % arm moment of inertia
Jp = 1.2495e-4;         % pendulum moment of inertia, to be verified
Jt = Jp*Jr-(Mp*l*r)^2;  

%----------------DC MOTOR-------------------
Kt = 0.042;             % torque constant
Km = 0.042;             % back emf constant, to be verified
Rm = 8.4;               % terminal resistance

%-----------------GAINS---------------------
Kp = 2;                 % proportional gain
Kd = 0;                 % derivative gain
Td = Kd/Kp;

%% STATE SPACE REPRESENTATION

A = [0 0 1 0;
    0 0 0 1;
    0, Mp^2*l^2*r*g/Jt, -(1/Jt)*(Jp*Br+Jp*Km^2/Rm), Mp*l*r*Bp/Jt;
    0, -Mp*g*l*Jr/Jt, (1/Jt)*(Mp*l*r*Br+Mp*l*r*Km^2/Rm), -Jp*Bp/Jt];

B = [0; 0; Jp*Km/(Jt*Rm); -Mp*r*l*Km/(Jt*Rm)];

C = [1 0 0 0;
     0 1 0 0];
D = [0; 0];

sys = ss(A,B,C,D);                   % State Space  passive system
[n, d] = ss2tf(A,B,C,D);             % extracting the states 
theta = tf(n(1,:), d(1,:)); 
alpha = tf(n(2,:), d(1,:));

N = ctrb(A,B);                       % Controllability matrix
rank = rank(N);                      % the system is fully controllable

step(sys)
