clc;
clear;

%% PARAMETERS

%----------------CONSTANTS-----------------
g = 9.81;                % accelerazione di gravità
Bp = 0.01;               % viscous damping pendulum, to be estimated
Br = 0.01;               % viscous damping rotary arm, to be estimated

%----------------PENDULUM------------------
Lp = 0.129;             % pendulum lenght
l = Lp/2;
Lr = 0.085;             % arm lenght
Mp = 0.024;             % pendulum mass
Mr = 0.095;             % arm mass
Jr = Mr*Lr^2/3;          % arm moment of inertia
Jp = Mp*Lp^2/3;         % pendulum moment of inertia, to be verified 

%----------------DC MOTOR-------------------
kt = 0.042;             % torque constant
km = 0.042;             % back emf constant, to be verified
Rm = 8.4;               % terminal resistance

%-----------------GAINS---------------------
Kp = 2;                 % proportional gain
Kd = 0.1;               % derivative gain
Td = Kd/Kp;

%% STATE SPACE REPRESENTATION
% State Space Representation
Jt = Jr*Jp + Mp*(Lp/2)^2*Jr + Jp*Mp*Lr^2;
A = [0 0 1 0;
     0 0 0 1;
     0 Mp^2*(Lp/2)^2*Lr*g/Jt -Br*(Jp+Mp*(Lp/2)^2)/Jt -Mp*(Lp/2)*Lr*Bp/Jt;
     0 Mp*g*(Lp/2)*(Jr+Mp*Lr^2)/Jt -Mp*(Lp/2)*Lr*Br/Jt -Bp*(Jr+Mp*Lr^2)/Jt];
B = [0; 0; (Jp+Mp*(Lp/2)^2)/Jt; Mp*(Lp/2)*Lr/Jt];
C = eye(2,4);
D = zeros(2,1);
% Add actuator dynamics
B = kt * B / Rm;
A(3,3) = A(3,3) - kt*km/Rm*B(3);
A(4,3) = A(4,4) - kt*km/Rm*B(4);

N = ctrb(A,B);                       % Controllability matrix
rank_N = rank(N);                      % the system is fully controllable
polynomial = charpoly(A);            % polinomio caratteristico

sys = ss(A,B,C,D);
[n, d] = ss2tf(A,B,C,D);             % extracting the states 
theta = tf(n(1,:), d(1,:)); 
alpha = tf(n(2,:), d(1,:));

%% POLE PLACEMENT
lambdas = eig(A);                                       % poles of TF
P = [lambdas(1), lambdas(2), -3, lambdas(4)];           % desired poles location
K = place(A,B,P);                                       % control matrix

Acl = A - B*K;                                          % controlled A matrix

syscl = ss(Acl,B,C,D);

x0 = [0;20;0;0];
initial(syscl, x0);

figure(20)
plot(out.tout, out.simout)
%% POLE PLACEMENT WITH INTEGRAL GAIN
% 
% % Create the augmented matrixes
% Aa = [A [0 0;0 0;0 0;0 0] ; -C [0 0;0 0]];
% Ba = [B; 0; 0];
% 
% P = [lambdas(1), lambdas(2), -lambdas(3), lambdas(4), -1, -20];  % desired poles location
% 
% N = ctrb(Aa,Ba);                       % Controllability matrix
% rank_N = rank(N);
% 
% K = place(Aa,Ba,P);