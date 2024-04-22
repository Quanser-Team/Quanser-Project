%% esempio online %%
close all
clear all
clc

% PARAMETERS %% 

% syms mr mp Lr Lp Ir Ip g0 La Ra J k

% Rod %
mr = 0.095 ;    % kg
Lr = 0.085 ;    % m
%Ir = (mr*Lr^2)/3 ; % = 2.2879e-04 kg*m^2 using Huyhens-Steiner
Ir = 9.6e-5; % = from estimation
% Pendulum %
mp = 0.024 ;    % kg
Lp = 0.129 ;    % m !!! mind that in the eqs I consider already the half
Ip = (mp*Lp^2)/12 ; % = 3.3282e-05 kg*m^2
%Ip = 2.4573e-5; % from Renzo estimator
% gravity acc %
g0 = 9.81 ; % m/s^2

%alfa = 1.46e-5 ;    % renzo estimation
% alfa = 1.247559e-6 ;  % from my estimation
% alfa = 1.46e-5 from renzo estimator
alfa = 1e-5 ;   % a compromise, just take into account that the damping is more linear than exp below 10 deg

param = [mr mp Lr Lp Ir Ip g0]' ;

syms theta theta_dot theta_ddot phi phi_dot phi_ddot Va

% DC PM Motor %%

% MotorDC %
J = 4e-6 ;  % kg*m^2
J_hub = 0.6e-6 ;
Ra = 8.4 ;  % ohm
La = 1.16e-3 ;  % H
%beta = (J+J_hub)/19e-3 ; % 1st estimation from tau_mecc = 19ms
beta = 1.295e-5 ; % estimation from theta_inf and DC gain of the CL plant
K = 42e-3 ;     % N*m/A

a = (Ra*beta)+K^2 ;
num_dcm = K/a ;
den_dcm = [La^2/a La*(Ra+beta)/a 1] ;
G_dcm = tf(num_dcm, den_dcm) ;

figure
bode(G_dcm)
pole(G_dcm)
dcgain(G_dcm)

%semplified since tau_el >> tau_mecc
% b = K^2+(Ra*beta) ;
% G_dcm_sempl = tf(K/b, [(La*Ra)/b 1])
% figure
% bode(G_dcm_sempl)
% pole(G_dcm_sempl)
% dcgain(G_dcm_sempl)

Ir_tot = Ir+J+J_hub ;       % = 2.333917e-04 mostly he same w/o considering the hub
                            % = 1.0060e-04
Ip_tot = (mp*(Lp/2)^2)+Ip ;     % = 1.33128e-04
                                % = 1.24419e-04

% Disturbance on theta

dist = 0.03 ;
Ld = 0.40*Lr ;
%%

% Initial state
theta_init = 0 ;
theta_dot_init = 0 ;
phi_init = pi;
phi_dot_init = 0 ;

% DYN MODEL B,C,g %%

% NT: the phi starts at the lower side and >0 C.C.W. and theta is >0 C.W.
% BUT! in the physical model the phi and theta are measured in different
% way so pay attention on the reference vauels for them !!!
H = [(mp*(Lr^2+((Lp/2)^2*(sin(phi))^2)))+Ir_tot            -mp*Lr*Lp*cos(phi)/2;
                     -mp*Lr*Lp*cos(phi)/2                              (mp*(Lp/2)^2)+Ip] ;

Q = [mp*(Lp/2)^2*sin(phi)*cos(phi)*phi_dot+beta                      (mp*(Lp/2)^2*sin(phi)*cos(phi)*theta_dot)-(mp*Lr*(Lp/2)*sin(phi)*phi_dot);
     -mp*(Lp/2)^2*sin(phi)*cos(phi)*theta_dot                                                   alfa                                   ] ;

g = [           0     ;
     mp*g0*(Lp/2)*sin(phi)] ;
Te = ((K/Ra)*Va)-((K^2/Ra)*theta_dot) ;
tau = [Te;
       0 ] ;
                                    % 0.08727rad = 5deg
    kt = 0.035 ;                    % 0.1745rad = 10deg
    kc = 10e-3 ;


Tr_theta = ((kt*theta)+(kc*theta_dot))*Ld ;

q_ddot = H\[tau - Q*[theta_dot phi_dot]' - g - 0*[Tr_theta 0]'] ;


% SS Reppr %
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

% LINEARIZATION USING diff() %%

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
% TF of the Linearized Syst from the evaluated Matrices %%

% !!! Make sure to execute the 'vpa()' funct in orde to have the result,
% otherwise there will be a problem executing other operation with the 
% Matrices !!!
% it will provide the Matrices with the proper results value and not
% operation 
%A = vpa(A, 6) ;
%B = vpa(B, 6) ;

% or use double
A = double(A) ;
B = double(B) ;
G_ol = tf(ss(A, B, C, D)) 
figure
bode(G_ol)
eig(A)

dcgain(G_ol)

%% Delay

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

opts = pidtuneOptions('PhaseMargin', 90, 'DesignFocus', 'reference-tracking') ;
R_theta = pidtune(delay*G_ol(1), 'PID', 30 , opts) 
%L= R_theta*G_ol(1);

figure
%step(L/(1+L))
step(feedback(R_theta*G_ol(1), 1))  % compact form
% impulse(feedback(R_theta*G_ol(1), 1))     %impulse
Kp_theta = R_theta.Kp ;
Ki_theta = R_theta.Ki ;
Kd_theta = R_theta.Kd ;

%% Reg Theta w/ Pole/Zero Cancellation %%
% phi = 0° %
close all

num_theta = cell2mat(G_ol.Numerator(1,1))
den_theta = cell2mat(G_ol.Denominator(1,1))

s = tf('s') ;
R_theta = (1e6/s) / (G_ol(1)*(s+1e4)) ;
L_theta= R_theta*G_ol(1);

figure
bode(L_theta)
figure
bode(L_theta/(1+L_theta))
figure
%step(L/(1+L))
step(feedback(R_theta*G_ol(1), 1))  % compact form

num_R_theta = cell2mat(R_theta.Numerator)
den_R_theta = cell2mat(R_theta.Denominator)

%% Reg Theta w/ Pole/Zero Cancellation %%
% phi = 180° %
close all

num_theta = cell2mat(G_ol.Numerator(1,1))
den_theta = cell2mat(G_ol.Denominator(1,1))

s = tf('s') ;
R_theta = 10000*(s+15.2022)*(s+0.8115) / (s*(s+0.1)*(s+10.7180)) ;
L_theta= R_theta*G_ol(1);

figure
bode(L_theta)

figure
%step(L/(1+L))
step(feedback(R_theta*G_ol(1), 1))  % compact form

num_R_theta = cell2mat(R_theta.Numerator)
den_R_theta = cell2mat(R_theta.Denominator)

%% regolatore theta from scratch/trial & error %%
%   phi_init = 0°   %
close all
pole(G_ol(1))   % see how many unstable poles
figure
bode(G_ol(1))
% see the model Properties of the G_ol(1) si extract the num and den for
% Simulink block
num_theta = cell2mat(G_ol.Numerator(1,1))
den_theta = cell2mat(G_ol.Denominator(1,1))

% Filtered Derivative PID
Kp_theta = 0.5 ;
Ki_theta = 0.1 ;
Kd_theta = 1.5 ;
N = 100 ;   % where the D action is filtered
R_theta = Kp_theta + (Ki_theta/s) + (Kd_theta*N/(1+(N/s))) ;
figure
bode(R_theta)
L_theta= R_theta*G_ol(1);
figure
bode(L_theta)
% fc = 9 rad/s
figure
%step(L/(1+L))
step(feedback(R_theta*G_ol(1), 1))  % compact form
% impulse(feedback(R_theta*G_ol(1), 1))     %impulse

%% regolatore theta using Ziegler-Nichols Method %%
%   phi_init = 0°   %
close all
pole(G_ol(1))   % see how many unstable poles
G_ol(1)
% see the model Properties of the G_ol(1) si extract the num and den for
% Simulink block
num_theta = cell2mat(G_ol.Numerator(1,1))
den_theta = cell2mat(G_ol.Denominator(1,1))

% Ku = 5e4 ;
% Tu = 5.353e-3 ;
% 
% Kp_theta = 0.6*Ku ;
% Ti = Tu/2 ;
% Ki_theta = Kp_theta/Ti ;
% Td = Tu/8 ;
% Kd_theta = Kp_theta*Td ;

% Kp_theta = 0.6*Ku ;
% Ki_theta = 1.2*Ku/Tu ;
% Kd_theta = 3*Ku*Tu/40 ;

Kp_theta = 100 ;
Ki_theta = 0 ;
Kd_theta = 0 ;

N = 100 ;   % where the D action is filtered
R_theta = Kp_theta + (Ki_theta/s) + (Kd_theta*N/(1+(N/s))) ;
figure
bode(R_theta)
L_theta= R_theta*G_ol(1);
figure
bode(L_theta)
pole(L_theta/(1+L_theta))
% fc = 9 rad/s
figure
%step(L/(1+L))
step(feedback(R_theta*G_ol(1), 1))  % compact form
% impulse(feedback(R_theta*G_ol(1), 1))     %impulse

%% regolatore theta from scratch/trial & error %%
%   phi_init = 180°   %
close all
pole(G_ol(1))   % see how many unstable poles
G_ol(1)
% see the model Properties of the G_ol(1) si extract the num and den for
% Simulink block
num_theta = cell2mat(G_ol.Numerator(1,1))
den_theta = cell2mat(G_ol.Denominator(1,1))

% Filtered Derivative PID
Kp_theta = 0.5 ;
Ki_theta = 0.1 ;
Kd_theta = 1.5 ;
N = 100 ;   % where the D action is filtered
R_theta = Kp_theta + (Ki_theta/s) + (Kd_theta*N/(1+(N/s))) ;
figure
bode(R_theta)
L_theta= R_theta*G_ol(1);
figure
bode(L_theta)
% fc = 9 rad/s
figure
%step(L/(1+L))
step(feedback(R_theta*G_ol(1), 1))  % compact form

% figure
% impulse(feedback(R_theta*G_ol(1), 1))     %impulse


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

%% Reg Phi w/ Pole/Zero Cancellation %%
close all
% phi_init = 180° %
G_t2p = G_ol(2) / G_ol(1)
num_phi = cell2mat(G_t2p.Numerator)
den_phi = cell2mat(G_t2p.Denominator)

s = tf('s') ;
R_phi = 10*(s+10.718) / (s+0.1) ;
L_phi= R_phi*G_t2p ;

figure
bode(L_phi)

figure
%step(L/(1+L))
step(feedback(R_phi*G_t2p, 1))  % compact form

num_R_phi = cell2mat(R_phi.Numerator)
den_R_phi = cell2mat(R_phi.Denominator)


%% Reg Phi w/ Pole/Zero Cancellation %%
close all
% phi_init = 0° %
G_t2p = G_ol(2) / G_ol(1)
num_phi = cell2mat(G_t2p.Numerator)
den_phi = cell2mat(G_t2p.Denominator)

s = tf('s') ;
R_phi = 1e3 / ((s+1)*(s+1e3)*G_t2p) ;    %% Mind that wc_phi << wc_theta
L_phi= R_phi*G_t2p ;

figure
bode(L_phi)

figure
%step(L/(1+L))
step(feedback(R_phi*G_t2p, 1))  % compact form

num_R_phi = cell2mat(R_phi.Numerator)
den_R_phi = cell2mat(R_phi.Denominator)

%% Regolatore phi from scratch/trial & error %%
%   phi_init = 0°   %
close all
G_t2p = G_ol(2) / G_ol(1)
figure
bode(G_t2p)
title("theta to phi Bode Diagram")
num_phi = cell2mat(G_t2p.Numerator)
den_phi = cell2mat(G_t2p.Denominator)
pole(G_t2p)     %see how many unstable poles

Kp_phi = 0 ;
Ki_phi = 7.5 ;
Kd_phi = 0 ;

N = 100 ;   % where the D action is filtered
R_phi = Kp_phi + (Ki_phi/s) + (Kd_phi*N/(1+(N/s))) ;
figure
bode(R_phi)
L_phi= R_phi*G_t2p;
figure
bode(L_phi)

figure
step(feedback(R_phi*G_t2p, 1))

figure
impulse(feedback(R_phi*G_t2p, 1))

%% Regolatore phi from scratch/trial & error %%
%   phi_init = 180°   %
close all
G_t2p = G_ol(2) / G_ol(1)
figure
bode(G_t2p)
title("theta to phi Bode Diagram")
num_phi = cell2mat(G_t2p.Numerator)
den_phi = cell2mat(G_t2p.Denominator)
pole(G_t2p)     %see how many unstable poles

Kp_phi = 0 ;
Ki_phi = 7.5 ;
Kd_phi = 0 ;

N = 100 ;   % where the D action is filtered
R_phi = Kp_phi + (Ki_phi/s) + (Kd_phi*N/(1+(N/s))) ;
figure
bode(R_phi)
L_phi= R_phi*G_t2p;
figure
bode(L_phi)

figure
step(feedback(R_phi*G_t2p, 1))

figure
impulse(feedback(R_phi*G_t2p, 1))

%% Linearized Model (ALternative way!) %%
% % directly form the Simulink Model extract the Linearized Model using 'linmod'
% 
% [A, B, C, D] = linmod('dyn_model') ;
% G_ol = tf(ss(A, B, C, D)) 
% figure
% bode (G_ol)
% 
% Gtp = G_ol(2) * (1/G_ol(1)) ;     % G(s) from theta to phi

%% Pole Placement in phi_bar == 0 %%
close all
rank(ctrb(A,B))     % == 4 so OK!

% Desired poles
P = [-5 -10 -20 -30] ;
K = place(A,B,P) ;
eig(A-B*K)

syst_cl = tf(ss(A-B*K,B,C,D))
figure
step(syst_cl)
ss_gain = 1/dcgain(syst_cl) 

%% %% Pole Placement in phi_bar == 180 %%
close all
rank(ctrb(A,B))     % == 4 so OK!

% Desired poles
P = [-5 -15 -25 -30] ;
K = place(A,B,P) ;
eig(A-B*K)

syst_cl = tf(ss(A-B*K,B,C,D))
figure
% step(syst_cl)
impulse(syst_cl)
ss_gain = 1/dcgain(syst_cl) 



%% KALMAN FILTER - State Observer
% for the estimation of phi_dot (theta_dot is given by encoder)
%analog procedure of pole placement to find L
%use this also to observe if using the Derivative block for theta_dot is
%not too different than using the Tachometer

%high q == fast observer, fst to reach the ref, but w/ some osc
%small q == slow to reach the ref, but small osc
% r == VAR of the Measurements
%high r == not reliable measurement
%small r == reliable measurment
% Q_tilde > R_tilde == Fast Observer
Q_tilde = zeros(4) ;
Q_tilde(1,1) = 10 ;   % measurment for theta
Q_tilde(2,2) = 10 ;   % // for theta_dot
Q_tilde(3,3) = 10 ;   % // for phi
Q_tilde(4,4) = 10 ;   % // for phi_dot

R_tilde = zeros(2,2) ;    % R(p,p)
R_tilde(1,1) = 0.001 ;   % da verificare
R_tilde(2,2) = 0.001 ;

Bq = sqrt(Q_tilde) ;


rank(obsv(A,C))         %check on the observability
rank(ctrb(A,Bq))

L_kf = lqr(A',C',Q_tilde,R_tilde)'

%% LQR %%
close all
Q = zeros(4) ;
Q(1,1) = 100 ;   % q for theta
Q(2,2) = 0 ;   % q for theta_dot
Q(3,3) = 100 ;   % q for phi
Q(4,4) = 0 ;   % q for phi_dot
% NT: if you want theta to go to zero q must be at least = to the q for
% phi

R = 0.01 ;
Cq = sqrt(Q) ;

rank(ctrb(A,B))     % == 4 so OK!
rank(obsv(A,Cq))    % == 4 so ok!

[K_lq S P] = lqr(A,B,Q,R) ;

cl_lq = tf(ss(A-B*K_lq,B,C,D))
figure
step(cl_lq)
% impulse(cl_lq)
ss_gain = 1/dcgain(cl_lq) 

figure
bode(cl_lq)

figure
nyquist(cl_lq)

figure
pzmap(cl_lq)

%% phi_init = 8.791 deg cutted %%
load('12phi.mat')
t = phi(1,:)' ;
alfa_12 = 1.46e-5 ;
phi_init_12 = 8.7891 ;
tau = 2*Ip_tot/alfa_12 ;
exp_damp = phi_init_12*exp(-t/tau) ;
phi_meas = phi(2,:)' ;
phi_cut =zeros(50001,1) ;
phi_cut(1:46185) = phi_meas(3817:50001) ;


figure
plot(t, phi_cut)
hold on
plot(t,exp_damp)

phi_cut_8deg=[t';
              phi_cut'];    % to save
exp_8deg=[t';
              exp_damp'];    % to save

save("12phi_cut.mat","t", "phi_cut_8deg")
save("12phi_exp.mat","t", "exp_8deg")

%% phi_init = 2.1094 deg cutted %%
load('12phi.mat')
t = phi(1,:)' ;
alfa_12 = 1.46e-5 ;
phi_init_2deg = 2.1094 ;
tau = 2*Ip_tot/alfa_12 ;
exp_damp = phi_init_2deg*exp(-t/tau) ;
phi_meas = phi(2,:)' ;
phi_cut =zeros(50001,1) ;
phi_cut(1:34222) = phi_meas(15780:50001) ;


figure
plot(t, phi_cut)
hold on
plot(t,exp_damp)

phi_cut_2deg=[t';
              phi_cut'];    % to save
exp_2deg=[t';
              exp_damp'];    % to save

save("2degphi_cut.mat","t", "phi_cut_2deg")
save("2degphi_exp.mat","t", "exp_2deg")
hold on
retta = - (0.1716*t) + 2.1094 ;
osc = cos(11.09*t) ;
plot(t, retta.*osc)

%% phi_init = 45 deg cutted %%
load('11phi.mat')
t = phi(1,:)' ;
alfa_11 = 9.64721e-6 ;
phi_init_11 = 45 ;
tau = 2*Ip_tot/alfa_11 ;
exp_damp = phi_init_11*exp(-t/tau) ;
phi_meas = phi(2,:)' ;
phi_cut =zeros(55001,1) ;
phi_cut(1:54049) = phi_meas(953:55001) ;


figure
plot(t, phi_cut)
hold on
plot(t,exp_damp)

phi_cut_45deg=[t';
              phi_cut'];    % to save
exp_45deg=[t';
              exp_damp'];    % to save
save("11phi_cut.mat","t", "phi_cut_45deg")
save("11phi_exp.mat","t", "exp_45deg")

%% phi_init = 90 deg cutted %%
load('10phi.mat')
t = phi(1,:)' ;
alfa_10 = 1.034391e-5 ;
phi_init_10 = 90 ;
tau = 2*Ip_tot/alfa_10 ;
exp_damp = phi_init_10*exp(-t/tau) ;
phi_meas = phi(2,:)' ;
phi_cut =zeros(55001,1) ;
phi_cut(1:53759) = phi_meas(1243:55001) ;


figure
plot(t, phi_cut)
hold on
plot(t,exp_damp)

phi_cut_90deg=[t';
              phi_cut'];    % to save
exp_90deg=[t';
              exp_damp'];    % to save
save("10phi_cut.mat","t", "phi_cut_90deg")
save("10phi_exp.mat","t", "exp_90deg")

%% 
x = [2.194 8.7891 45 90] ;
y = [2.4594 7.246 14.334 19.2] ;
figure
plot(x,y)

%% seq stair
stair = 0:0.5:20 ;