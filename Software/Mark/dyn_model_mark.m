%% esempio online %%
close all
clear all
clc

%% PARAMETERS %% 

% syms mr mp Lr Lp Ir Ip g0 La Ra J k
%%
% Rod %
mr = 0.095 ;    % kg
Lr = 0.085 ;    % m
Ir = (mr*(Lr/2)^2)/12 ; % = 1.4299e-05 kg*m^2
% Pendulum %
mp = 0.024 ;    % kg
Lp = 0.129/2 ;    % m !!! mind that in the eqs I consider already the half
Ip = (mp*Lp^2)/12 ; % = 8.3205e-06 kg*m^2
% gravity acc %
g0 = 9.81 ; % m/s^2

% MotorDC %
J = 4e-6 ;  % kg*m^2
Ra = 8.4 ;  % ohm
La = 1.16e-3 ;  % H
k = 42e-3 ;     % N*m/A

param = [mr mp Lr Lp Ir Ip g0]' ;

syms theta theta_dot theta_ddot phi phi_dot phi_ddot Va

%% DYN MODEL %%

a1 = mr*(Lr/2)^2 + mp*(Lr^2+(Lp*sin(phi))^2) + Ir ;
b1 = mp*Lr*Lp*cos(phi) ;
c1 = b1 ;
d1 = mp*Lp^2+Ip ;

e = (-2*mp*Lp^2*sin(phi)*cos(phi)*theta_dot*phi_dot) + ( mp*Lr*Lp*sin(phi)*theta_dot^2 ) - (k^2/Ra)*theta_dot + (k/Ra)*Va ;
f = ( mp*Lp^2*sin(phi)*cos(phi)*theta_dot^2 ) + ( mp*g0*Lp*sin(phi) ) ;

B = [a1 b1;
     b1 d1] ;
ne = [e f]' ;
q_ddot = B\ne ;

%% DYN MODEL B,C,g %%
H = [(mr*(Lr/2)^2)+(mp*(Lr^2+(Lp^2*(sin(phi))^2)))+Ir            mp*Lr*Lp*cos(phi);
                     mp*Lr*Lp*cos(phi)                              (mp*Lp^2)+Ip] ;

Q = [mp*Lp^2*sin(phi)*cos(phi)*phi_dot                      (mp*Lp^2*sin(phi)*cos(phi)*theta_dot)-(mp*Lr*Lp*sin(phi)*theta_dot);
     -mp*Lp^2*sin(phi)*cos(phi)*theta_dot                                                   0                                   ] ;

g = [           0     ;
     -mp*g0*Lp*sin(phi)] ;
tau = [((k/Ra)*Va)-((k^2/Ra)*theta_dot);
                    0                   ] ;

q_ddot = H\[tau - Q*[theta_dot phi_dot]' - g] ;

%% SS Reppr %
syms x1 x2 x3 x4 x
x =[x1 x2 x3 x4]' ;
syst = subs(q_ddot, [theta theta_dot phi phi_dot], [x1 x2 x3 x4]);

dx1 = x2 ;
dx2 = syst(1) ;
dx3 = x4 ;
dx4 = syst(2) ;

dx = [dx1 dx2 dx3 dx4]' ;

%% Equilibria %%

equilibrium = [0 == dx] ;
% Operating Point
x1_bar = 0 ;
x2_bar = 0 ;
x3_bar = pi ;    % phi_bar 
x4_bar = 0 ;

systeqs = subs(equilibrium, [x1 x2 x3 x4], [x1_bar x2_bar x3_bar x4_bar]) ;
sol = solve(systeqs, Va) ;
Va_bar = double(sol) ;

%% LINEARIZATION USING diff() %%

A11 = diff(dx1, x1) ;
A12 = diff(dx1, x2) ;
A13 = diff(dx1, x3) ;
A14 = diff(dx1, x4) ;

A21 = diff(dx2, x1) ;
A22 = diff(dx2, x2) ;
A23 = diff(dx2, x3) ;
A24 = diff(dx2, x4) ;

A31 = diff(dx3, x1) ;
A32 = diff(dx3, x2) ;
A33 = diff(dx3, x3) ;
A34 = diff(dx3, x4) ;

A41 = diff(dx4, x1) ;
A42 = diff(dx4, x2) ;
A43 = diff(dx4, x3) ;
A44 = diff(dx4, x4) ;

A = subs([A11 A12 A13 A14;
     A21 A22 A23 A24;
     A31 A32 A33 A34;
     A41 A42 A43 A44], [x1 x2 x3 x4 Va], [x1_bar x2_bar x3_bar x4_bar Va_bar]) ;

B = subs([   diff(dx1, Va);
        diff(dx2, Va);
        diff(dx3, Va);
        diff(dx4, Va)], [x1 x2 x3 x4 Va], [x1_bar x2_bar x3_bar x4_bar Va_bar]) ;

C = [1 0 0 0;       % y = [theta phi]' 
     0 0 1 0] ;

D = [0;
     0] ;
%% TF of the Linearized Syst from the evaluated Matrices %%

% !!! Make sure to execute the 'vpa()' funct in orde to have the result,
% otherwise there will be a problem executing other operation with the 
% Matrices !!!
% it will provide the Matrices with the proper results value and not
% operation 
%A = vpa(A, 6) ;
%B = vpa(B, 6) ;

A = double(A) ;
B = double(B) ;
G_ol = tf(ss(A, B, C, D)) 
figure
bode(G_ol)
eig(A)

%% DElay

s = tf('s') ;
tau = 0 ;
delay = exp(-tau*s) ;
delay_tf = pade(delay, 1) ;

%% regolatore theta  %%
pole(G_ol(1))   % see how many unstable poles
G_ol(1)
% see the model Properties of the G_ol(1) si extract the num and den for
% Simulink block
num_theta = cell2mat(G_ol.Numerator(1,1))
den_theta = cell2mat(G_ol.Denominator(1,1))

opts = pidtuneOptions('PhaseMargin', 60) ;
R_theta = pidtune(delay*G_ol(1), 'PID', 30 , opts) 
%L= R_theta*G_ol(1);
figure
%step(L/(1+L))
step(feedback(R_theta*G_ol(1), 1))  % compact form
% impulse(feedback(R_theta*G_ol(1), 1))     %impulse
Kp_theta = R_theta.Kp ;
Ki_theta = R_theta.Ki ;
Kd_theta = R_theta.Kd ;

%% Regolatore phi %%
s = tf('s') ;
G_t2p = G_ol(2) / G_ol(1)
%figure
%bode(G_t2p)
num_phi = cell2mat(G_t2p.Numerator)
den_phi = cell2mat(G_t2p.Denominator)
pole(G_t2p)     %see how many unstable poles

opts = pidtuneOptions('PhaseMargin',60 , 'DesignFocus', 'disturbance-rejection') ;
R_phi = pidtune(G_t2p, 'PID', 3, opts)
figure
step(feedback(R_phi*G_t2p, 1))
% figure
% bode (R_phi*G_t2p)
Kp_phi = R_phi.Kp ;
Ki_phi = R_phi.Ki ;
Kd_phi = R_phi.Kd ;


%% Linearized Model (ALternative way!) %%
% % directly form the Simulink Model extract the Linearized Model using 'linmod'
% 
% [A, B, C, D] = linmod('dyn_model') ;
% G_ol = tf(ss(A, B, C, D)) 
% figure
% bode (G_ol)
% 
% Gtp = G_ol(2) * (1/G_ol(1)) ;     % G(s) from theta to phi

%% Pole Placement in phi_bar == 180 %%

rank(ctrb(A,B))     % == 4 so OK!

% Desired poles
P = [-1 -3 -20 -30] ;
K = place(A,B,P) ;
eig(A-B*K)

syst_cl = tf(ss(A-B*K,B,C,D))
figure
step(syst_cl)
ss_gain = 1/dcgain(syst_cl) 

%% %% Pole Placement in phi_bar == 0 %%

rank(ctrb(A,B))     % == 4 so OK!

% Desired poles
P = [-0.5 -15 -25 -30] ;
K = place(A,B,P) ;
eig(A-B*K)

syst_cl = tf(ss(A-B*K,B,C,D))
figure
step(syst_cl)
ss_gain = 1/dcgain(syst_cl) 



%% KALMAN FILTER
% for the estimation of phi_dot (theta_dot is given by encoder)
%analog procedure of pole placement to find L


Ob = obsv(A,C);         %check on the observability
rank_Ob= rank(Ob);
P_filter= [-10 -30 -200 -300];               %poli dell'observer, quelli del PPx10
L = (place(A',C',P))' ;







