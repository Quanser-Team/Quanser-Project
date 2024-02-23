clc;
clear;
close all;

set(0,'defaulttextinterpreter','latex');
set(0,'defaultAxesFontSize',14)
set(groot,'defaultAxesFontName','Times New Roman')
set(groot, 'DefaultFigurePosition', [200,90,0.75.*989,0.75*705.5])

%% LOAD PARAMETERS
load("Perfect_param.mat")

%% STATE-SPACE FROM TRANSFER FUNCTION

J1_star = Jr + Mp*Lr^2;
r1_star = Br + Km^2/Rm;
J2_star = (5*Mp*Lp^2)/12;
c = Mp*Lr*Lp/2;
% 
% theta_num = [2*J2_star*Km, 2*Bp*Km, -Mp*g*Lp*Km];
% alfa_num = [2*Km*c, 0, 0];
% 
% num = [theta_num; alfa_num];
% den = [-2*Rm*c^2+2*J1_star*J2_star*Rm, 2*Rm*Bp*J1_star+2*Rm*J2_star*r1_star, 2*Rm*Bp*r1_star-J1_star*Mp*Lp*g*Rm, -Rm*Mp*Lp*g*r1_star, 0];
% 
% theta = tf(theta_num, den);
% alfa = tf(alfa_num, den);
% 
% [A,B,C,D] = tf2ss(num, den);
% 
% sys = ss(A,B,C,D);
% step(sys);
% autovalori_OL = eig(A);


%% STATE SPACE OF UNSTABLE MODEL

Jt = J1_star*J2_star-c^2;
A = [0 0 1 0;
    0 0 0 1;
    0 Mp*g*Lp*c/(2*Jt) -r1_star*J2_star/Jt -Bp*c/Jt;
    0 Mp*g*Lp*J1_star/(2*Jt) -r1_star*c/Jt -Bp*J1_star/Jt];

B = [0; 0; Km*J2_star/(Rm*Jt); Km*c/(Rm*Jt)];

C = [1 0 0 0;
     0 1 0 0];

D = [0;0]; 

eig(A);
sys = ss(A,B,C,D);

%% LQR CONTROL

% Normalizing the variables
% theta_max = pi/4;       % rad
% theta_dot_max = 2*pi;   % rad/s
% alfa_max = pi/18;       % rad (10 gradi)
% alfa_dot_max = pi;      % rad/s
% u_max = 5;              % Volt

Q = diag([7 5 3 1]);

% Q(1,1) = Q(1,1)/theta_max^2; 
% Q(2,2) = Q(2,2)/alfa_max^2; 
% Q(3,3) = Q(3,3)/theta_dot_max^2; 
% Q(4,4) = Q(4,4)/alfa_dot_max^2; 
% 
% R = 8/u_max^2;

R = 8;

[K,S,P] = lqr(sys,Q,R);

%% POLE PLACEMENT
% p = [-2.6+3.04i, -2.6-3.04i, -40, -45];         % desired poles location
% 
% K = place(A,B,p); 
% eig(A-B*K)

%%  KALMAN FILTER 

Q = 1;         % covariance delle disturbances, ipotesi di load disturbances solo su theta
R = 0.1;       % covariance del noise sulla misurazione di theta e alfa

Ktheta = 0.5;       % gain sul noise di theta
Kalfa = 0.2;        % gain sul noise di alfa      
Kw = 2;             % gain of load disturbances

Ts = 0.002;         % sample time



