%%  ROTATIONAL INVERTED PENDULUM %%
close all
clear all
clc

% PARAMETERS %% 

% Rod %
mr = 0.095 ;    % kg
Lr = 0.085 ;    % m
% Ir = (mr*Lr^2)/3 ; % = 2.2879e-04 kg*m^2 using Huyhens-Steiner
Ir = 9.6e-5; % = from estimation
% Pendulum %
mp = 0.024 ;    % kg
Lp = 0.129 ;    % m 
Ip = (mp*Lp^2)/12 ; % = 3.3282e-05 kg*m^2 wrt the COG
% Ip = 2.4573e-5; % from Renzo estimator
% alfa = 1.46e-5 ;    % renzo estimation
% alfa = 1.247559e-6 ;  % from my estimation
% alfa = 1.46e-5 ; % from renzo estimator
alfa = 1e-5 ;   % a compromise, just take into account that the damping is more linear than exp below 10 deg
% alfa = 0 ;  % for robustness test
% gravity acc %
g0 = 9.81 ; % m/s^2



% MotorDC %
J = 4e-6 ;  % kg*m^2
J_hub = 0.6e-6 ;
Ra = 8.4 ;  % ohm
La = 1.16e-3 ;  % H
%beta = (J+J_hub)/19e-3 ; % 1st estimation from tau_mecc = 19ms
beta = 1.295e-5 ; % estimation from theta_inf and DC gain of the CL plant, but it changing w/ the speed
% beta = 0 ;  % for robustness test
K = 42e-3 ;     % N*m/A

a = (Ra*beta)+K^2 ;
num_dcm = K/a ;
den_dcm = [La^2/a La*(Ra+beta)/a 1] ;
G_dcm = tf(num_dcm, den_dcm) ;

figure
bode(G_dcm)
title("DC Motor Bode Diagram")
disp("DC Syst poles and dcgain")
pole(G_dcm)
dcgain(G_dcm)

Ir_tot = Ir+J+J_hub ;
Ip_tot = (mp*(Lp/2)^2)+Ip ;

% Disturbance on theta
Ld = 0.40*Lr ;  % we assume that the cable disturbance is acting in the position where it is attached along the rod

% Initial state
theta_init = 0 ;
theta_dot_init = 0 ;
phi_init = 0 ;
phi_dot_init = 0 ;


%% DYN MODEL B,C,g (EULERO-LAGRANGE METHOD) %%
syms theta theta_dot theta_ddot phi phi_dot phi_ddot Va
% phi = pendulum angle
% theta = rod angle
% NT: the phi starts at the lower side and >0 C.C.W. and theta is >0 C.W.

% (BUT! in the physical model the phi and theta are measured in different
% way so pay attention on the reference vauels for them !!!)

H = [(mp*(Lr^2+((Lp/2)^2*(sin(phi))^2)))+Ir_tot            -mp*Lr*Lp*cos(phi)/2;
                     -mp*Lr*Lp*cos(phi)/2                              (mp*(Lp/2)^2)+Ip] ;

Q = [mp*(Lp/2)^2*sin(phi)*cos(phi)*phi_dot+beta                      (mp*(Lp/2)^2*sin(phi)*cos(phi)*theta_dot)-(mp*Lr*(Lp/2)*sin(phi)*phi_dot);
     -mp*(Lp/2)^2*sin(phi)*cos(phi)*theta_dot                                                   alfa                                   ] ;

g = [           0     ;
     mp*g0*(Lp/2)*sin(phi)] ;

Te = ((K/Ra)*Va)-((K^2/Ra)*theta_dot) ;

tau = [Te;
       0 ] ;
% the modeling of the cable disturbance is more effective in the Simulink model where we can use directly the angles at each time                                    
kt = 0.035 ;    % elastic coeff                   
kc = 10e-3 ;    % damping coeff
Tr_theta = ((kt*theta)+(kc*theta_dot))*Ld ;     % torque acting on the rod due to the sensor cable

q_ddot = H\[tau - Q*[theta_dot phi_dot]' - g - 0*[Tr_theta 0]'] ;

% we are not considering the the model of the Disturbance here, that's why
% the moltiplication w\ 0, since the various control we implemented are
% quite robust to it and we also aimed not to complicate the Model

% SS Reppr %
% we just rewrite the equation in a State-Space form, a more familiar
% notation
syms x1 x2 x3 x4 x
syst = subs(q_ddot, [theta theta_dot phi phi_dot], [x1 x2 x3 x4]);

dx1 = x2 ;
dx2 = syst(1) ;
dx3 = x4 ;
dx4 = syst(2) ;

dx = [dx1 dx2 dx3 dx4]' ;

% Equilibria phi_bar = 0 deg %%

equilibrium = [0 == dx] ;
% Operating Points
Va_bar = 0 ;
% x1_bar = 0 ;
x2_bar = 0 ;
% x3_bar = 0 ;    % phi_bar 
x4_bar = 0 ;

systeqs = subs(equilibrium, [x2 x4 Va], [x2_bar x4_bar Va_bar]) ;
sol = solve(systeqs, [x1 x3]) ;
x1_bar = double(sol.x1) ;   % equilibrium for theta: 0+2k*pi for k=0
x3_bar = double(sol.x3) ;   % equilibrium for phi: 0+k*pi for k=0,1

%% LINEARIZATION USING diff() at phi = 0° %%
% just rewrite the equilibrium values
% Operating Points
x3_bar = 0 ;    % phi_bar = 0°

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
title("System's Bode Diagram (down position)")
disp("gain margin, phase margin, phase crossover frequency, cut-off frequency of the theta tf:")
[Gm,Pm,Wcg,Wcp] = margin(G_ol(1))

disp("System poles (down position):")
eig(A)
disp("System zeros of theta tf (down position):")
tzero(G_ol(1))
disp("System zeros of phi tf (down position):")
tzero(G_ol(2))

%% LINEARIZATION USING diff() at phi = 180°%%
% Operating Point
Va_bar_uns = Va ;
x1_bar_uns = x1_bar ;
x2_bar_uns = x2_bar ;
x3_bar_uns = pi ;    % phi_bar = 180°
x4_bar_uns = x4_bar ;

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

A_uns = subs([A11 A12 A13 A14;
     A21 A22 A23 A24;
     A31 A32 A33 A34;
     A41 A42 A43 A44], [x1 x2 x3 x4 Va], [x1_bar_uns x2_bar_uns x3_bar_uns x4_bar_uns Va_bar_uns]) ;

B_uns = subs([   diff(dx1, Va);
        diff(dx2, Va);
        diff(dx3, Va);
        diff(dx4, Va)], [x1 x2 x3 x4 Va], [x1_bar_uns x2_bar_uns x3_bar_uns x4_bar_uns Va_bar_uns]) ;

C_uns = [1 0 0 0;       % y = [theta phi]' 
     0 0 1 0] ;

D_uns = [0;
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
A_uns = double(A_uns) ;
B_uns = double(B_uns) ;
G_ol_uns = tf(ss(A_uns, B_uns, C_uns, D_uns)) 
figure
bode(G_ol_uns)
title("System's Bode Diagram (up position)")
disp("gain margin, phase margin, phase crossover frequency, cut-off frequency of the theta tf:")
[Gm_uns,Pm_uns,Wcg_uns,Wcp_uns] = margin(G_ol_uns(1))
disp("System poles (up position):")
eig(A_uns)
disp("System zeros of theta tf (up position):")
tzero(G_ol_uns(1))
disp("System zeros of phi tf (up position):")
tzero(G_ol_uns(2))

%% regolatore theta at phi = 0 %%
% using pidtuneOptions
close all

G_ol(1)
disp("Va to theta TF poles:")
pole(G_ol(1))   % see how many unstable poles
% see the model Properties of the G_ol(1) si extract the num and den for
% Simulink block
num_theta = cell2mat(G_ol.Numerator(1,1))
den_theta = cell2mat(G_ol.Denominator(1,1))

opts = pidtuneOptions('PhaseMargin', 60, 'DesignFocus', 'reference-tracking') ;
R_theta = pidtune(G_ol(1), 'PID', 100 , opts) 
L_theta = R_theta*G_ol(1);
figure
bode(L_theta)
title("Bode diagram of L")

figure
%step(L_theta/(1+L_theta))
step(feedback(R_theta*G_ol(1), 1))  % compact form
title("Step Response for theta")

Kp_theta = R_theta.Kp ;
Ki_theta = R_theta.Ki ;
Kd_theta = R_theta.Kd ;

disp("Closed Syst poles of theta Loop")
pole(L_theta/(1+L_theta))

%% regolatore theta at phi = 180 %%
% using pidtuneOptions
G_ol_uns(1)
disp("Va to theta TF poles:")
pole(G_ol_uns(1))   % see how many unstable poles
% see the model Properties of the G_ol_uns(1) si extract the num and den for
% Simulink block
num_theta_uns = cell2mat(G_ol_uns.Numerator(1,1))
den_theta_uns = cell2mat(G_ol_uns.Denominator(1,1))

opts = pidtuneOptions('PhaseMargin', 60, 'DesignFocus', 'reference-tracking') ;
R_theta_uns = pidtune(G_ol_uns(1), 'PID', 10 , opts) 
L_theta_uns = R_theta_uns*G_ol_uns(1);

figure
%step(L_uns/(1+L_uns))
step(feedback(R_theta_uns*G_ol_uns(1), 1))  % compact form

Kp_theta_uns = R_theta_uns.Kp ;
Ki_theta_uns = R_theta_uns.Ki ;
Kd_theta_uns = R_theta_uns.Kd ;

disp("Closed Syst poles of theta Loop")
pole(L_theta_uns/(1+L_theta_uns))

%% regolatore theta from scratch/trial & error %%
%   phi = 0°   %
close all

G_ol(1)
disp("Va to theta TF poles:")
pole(G_ol(1))   % see how many unstable poles

% see the model Properties of the G_ol(1) si extract the num and den for
% Simulink block
num_theta = cell2mat(G_ol.Numerator(1,1))
den_theta = cell2mat(G_ol.Denominator(1,1))

% Filtered Derivative PID
% Kp_theta = 30 ;
% Ki_theta = 0 ;
% Kd_theta = 5 ;
% N_theta = 1000 ;   % where the D action is filtered

Kp_theta = 0.9 ;
Ki_theta = 0 ;
Kd_theta = 0.25 ;
N_theta = 100 ;   % where the D action is filtered

s = tf('s') ;
R_theta = Kp_theta + (Ki_theta/s) + (Kd_theta*N_theta/(1+(N_theta/s))) ;
figure
bode(R_theta)
title("Bode Diagram of the obtained Reg")
L_theta = R_theta*G_ol(1);

figure
bode(L_theta)
title("Bode diagram of the Loop tf")

figure
%step(L/(1+L))
step(feedback(R_theta*G_ol(1), 1))  % compact form

disp("closed loop poles:")
pole(L_theta/(1+L_theta))

%% regolatore theta from scratch/trial & error %%
%   phi = 180°   %
close all
G_ol_uns(1)
disp("Va to theta TF poles:")
pole(G_ol_uns(1))   % see how many unstable poles

% see the model Properties of the G_ol(1) si extract the num and den for
% Simulink block
num_theta = cell2mat(G_ol_uns.Numerator(1,1))
den_theta = cell2mat(G_ol_uns.Denominator(1,1))

% Filtered Derivative PID
% Kp_theta = 10 ;
% Ki_theta = 0 ;
% Kd_theta = 2 ;
% N_theta = 1000 ;   % where the D action is filtered

Kp_theta = 5 ;
Ki_theta = 0;
Kd_theta = 2 ;
N_theta = 1000 ;   % where the D action is filtered
% conclusion: it might impossible to stabilize usign PID

s = tf('s') ;
R_theta = Kp_theta + (Ki_theta/s) + (Kd_theta*N_theta/(1+(N_theta/s))) ;
figure
bode(R_theta)
title("Bode Diagram of the obtained Reg")
L_theta_uns = R_theta*G_ol_uns(1);
figure
bode(L_theta)
title("Bode diagram of the Loop tf")

figure
%step(L_theta_uns/(1+L_theta_uns))
step(feedback(R_theta*G_ol_uns(1), 1))  % compact form

disp("closed loop poles:")
pole(L_theta_uns/(1+L_theta_uns))

%% Regolatore phi at phi = 0° %%
% using pidtuneOptions
close all

G_t2p = G_ol(2) / G_ol(1)
figure
bode(G_t2p)
title("Bode Diagram of theta to phi tf")
num_phi = cell2mat(G_t2p.Numerator)
den_phi = cell2mat(G_t2p.Denominator)
disp("theta to phi tf poles:")
pole(G_t2p)     %see the poles

opts = pidtuneOptions('PhaseMargin',60 , 'DesignFocus', 'disturbance-rejection') ;
R_phi = pidtune(G_t2p, 'PID', 20, opts)
figure
bode(R_phi)
title("Bode Diagram of the obtained Reg")

figure
step(feedback(R_phi*G_t2p, 1))

figure
bode (R_phi*G_t2p)
title("Bode Diagram of the Loop tf")

Kp_phi = R_phi.Kp ;
Ki_phi = R_phi.Ki ;
Kd_phi = R_phi.Kd ;

disp("closed loop poles:")
pole(feedback(R_phi*G_t2p,1))

%% Regolatore phi from scratch/trial & error %%
%   phi = 0°   %
close all
G_t2p = G_ol(2) / G_ol(1)
figure
bode(G_t2p)
title("Bode Diagram of theta to phi tf")
num_phi = cell2mat(G_t2p.Numerator)
den_phi = cell2mat(G_t2p.Denominator)
disp("theta to phi tf poles:")
pole(G_t2p)     %see the poles

% Kp_phi = 0.1 ;
% Ki_phi = 6 ;
% Kd_phi = 0 ;
% 
% N_phi = 1000 ;   % where the D action is filtered

Kp_phi = 0 ;
Ki_phi = 7 ;
Kd_phi = 0 ;

N_phi = 100 ;   % where the D action is filtered

s = tf('s') ;
R_phi = Kp_phi + (Ki_phi/s) + (Kd_phi*N_phi/(1+(N_phi/s))) ;
figure
bode(R_phi)
title("Bode Diagram of the obtained Reg")

figure
step(feedback(R_phi*G_t2p, 1))

disp("closed loop poles:")
pole(feedback(R_phi*G_t2p,1))

%% Regolatore phi from scratch/trial & error %%
%   phi = 180°   %
close all
G_t2p_uns = G_ol_uns(2) / G_ol_uns(1)
figure
bode(G_t2p_uns)
title("Bode Diagram of theta to phi tf")
num_phi = cell2mat(G_t2p_uns.Numerator)
den_phi = cell2mat(G_t2p_uns.Denominator)
disp("theta to phi tf poles:")
pole(G_t2p_uns)     %see the poles

% Kp_phi = 100 ;
% Ki_phi = 0 ;
% Kd_phi = 20 ;

Kp_phi = 90 ;
Ki_phi = 50 ;
Kd_phi = 60 ;

N_phi = 1000 ;   % where the D action is filtered
s = tf('s') ;
R_phi = Kp_phi + (Ki_phi/s) + (Kd_phi*(N_phi/(1+(N_phi/s)))) ;
figure
bode(R_phi)
title("Bode Diagram of the obtained Reg")

figure
step(feedback(R_phi*G_t2p_uns, 1))

disp("closed loop poles:")
pole(feedback(R_phi*G_t2p_uns,1))

%% Pole Placement in phi == 0 %%
close all
rank(ctrb(A,B))     % == 4 so OK!

% Desired poles
P = [-5 -50 -70 -80] ;  % veloce 0.8s
% P = [-1 -1.2 -10 -20] ;     % phi is quick responsive, theta is sless but phi is mantained at 0
K_pp = place(A,B,P) ;
disp("desired poles:")
eig(A-B*K_pp)

syst_cl = tf(ss(A-B*K_pp,B,C,D))
figure
step(syst_cl)

figure
bode(syst_cl)
title("Bode Diagram of the stabilized syst at 0°")

% in case you wanna fix the zeros
s = tf('s') ;
R = ((abs(0.0376-10.6803i))^2/dcgain(syst_cl(1))) / ((s+0.0376-10.6803i)*(s+0.0376+10.6803i)) ;
figure
bode(R*syst_cl)
title("Bode Diagram of the stabilized syst w/ the zeros removed")

%% %% Pole Placement in phi_bar == 180 %%
close all
disp("Controllability condition")
rank(ctrb(A_uns,B_uns))     % == 4 so OK!

% Desired poles
% P = [-1 -10 -30 -50] ;
% P = [-5 -50 -70 -80] ;
% P_uns = [-0.8 -0.9 -30 -120] ;    % last tried in lab 6/05
P_uns = [-5 -5.2 -15 -120] ;        % try this one, it should be faster, maybe aggressive

K_pp_uns = place(A_uns,B_uns,P_uns) ;
disp("desired poles:")
eig(A_uns-B_uns*K_pp_uns)

syst_cl_uns = tf(ss(A_uns-B_uns*K_pp_uns,B_uns,C_uns,D_uns))
figure
step(syst_cl_uns)

figure
bode(syst_cl)
title("Bode Diagram of the stabilized syst at 180°")

%% KALMAN FILTER - State Observer 0°
close all
% for the estimation of phi_dot (theta_dot is given by encoder)
%similar procedure of pole placement to find L
%use this also to observe if using the Derivative block for theta_dot is
%not too different than using the Tachometer

%high q == fast observer, fast to reach the ref, but w/ some osc
%small q == slow to reach the ref, but small osc
% r == VAR of the Measurements
%high r == not reliable measurement
%small r == reliable measurment
% Q_tilde > R_tilde == Fast Observer
Q_tilde = zeros(4) ;
Q_tilde(1,1) = 0.1 ;   % variance of the estimated theta
Q_tilde(2,2) = 1 ;   % // theta_dot
Q_tilde(3,3) = 0.1 ;   % // phi
Q_tilde(4,4) = 1 ;   % // phi_dot

R_tilde = zeros(2,2) ;    % R(p,p)
R_tilde(1,1) = 0.001 ;   % measurments are reliable
R_tilde(2,2) = 0.001 ;

Bq = sqrt(Q_tilde) ;

disp("Observability condition")
rank(obsv(A,C))         %check on the observability

L_kf = lqr(A',C',Q_tilde,R_tilde)' ;
st_obs_lqr_syst = tf(ss(A-L_kf*C,[B-L_kf*D L_kf],eye(4),zeros(4,3))) ;
figure
step(st_obs_lqr_syst)
disp("Kalman Filter poles:")
pole(st_obs_lqr_syst)

%% KALMAN FILTER - State Observer 180°
close all
% for the estimation of phi_dot (theta_dot is given by encoder)
%analog procedure of pole placement to find L
%use this also to observe if using the Derivative block for theta_dot is
%not too different than using the Tachometer

%high q == fast observer, fast to reach the ref, but w/ some osc
%small q == slow to reach the ref, but small osc
% r == VAR of the Measurements
%high r == not reliable measurement
%small r == reliable measurment
% Q_tilde > R_tilde == Fast Observer
Q_tilde_uns = zeros(4) ;
Q_tilde_uns(1,1) = 0.1 ;   % variance of the estimated theta
Q_tilde_uns(2,2) = 10 ;   % // theta_dot
Q_tilde_uns(3,3) = 0.1 ;   % // phi
Q_tilde_uns(4,4) = 10 ;   % // phi_dot

R_tilde_uns = zeros(2,2) ;    % R(p,p)
R_tilde_uns(1,1) = 0.001 ;   % measurments are reliable
R_tilde_uns(2,2) = 0.001 ;

Bq_uns = sqrt(Q_tilde_uns) ;

disp("Observability condition")
rank(obsv(A_uns,C_uns))         %check on the observability

L_kf_uns = lqr(A_uns',C_uns',Q_tilde_uns,R_tilde_uns)'
st_obs_lqr_syst_uns = tf(ss(A_uns-L_kf_uns*C_uns,[B_uns-L_kf_uns*D_uns L_kf_uns],eye(4),zeros(4,3))) ;
figure
step(st_obs_lqr_syst_uns)
disp("Kalman Filter poles:")
pole(st_obs_lqr_syst_uns)


%% STATE OBSERVER w/ POLE PLACEMENT 0° %%
close all
disp("Observability condition")
rank(obsv(A,C))  
P_obsv = [-200 -300 -400 -500] ;
L_pp = place(A',C',P_obsv)' ;
disp("desired State Observer poles:")
eig(A-L_pp*C)

st_obs_pp_syst = tf(ss(A-L_pp*C,[B-L_pp*D L_pp],eye(4),zeros(4,3)))
figure
step(st_obs_pp_syst)


%% STATE OBSERVER w/ POLE PLACEMENT 180° %%
close all
disp("Observability condition")
rank(obsv(A,C))  
P_obsv_uns = [-200 -300 -400 -500] ;
L_pp_uns = place(A_uns',C_uns',P_obsv_uns)' ;
disp("desired State Observer poles:")
eig(A_uns-L_pp_uns*C_uns)

st_obs_pp_syst_uns = tf(ss(A_uns-L_pp_uns*C_uns,[B_uns-L_pp_uns*D_uns L_pp_uns],eye(4),zeros(4,3)))
figure
step(st_obs_pp_syst_uns)

%% LQR at phi = 0 deg %%
close all
Q = zeros(4) ;
Q(1,1) = 100 ;   % q for theta
Q(2,2) = 1 ;   % q for theta_dot
Q(3,3) = 100 ;   % q for phi
Q(4,4) = 1 ;   % q for phi_dot
% NT: if you want theta to go to zero q must be = to the q for phi

R = 0.01;
Cq = sqrt(Q) ;

disp("Controllability and Observability Condition")
rank(ctrb(A,B))     % == 4 so OK!
rank(obsv(A,Cq))    % == 4 so ok!

[K_lq S P] = lqr(A,B,Q,R) ;

cl_lq = tf(ss(A-B*K_lq,B,C,D))
disp("LQR poles:")
eig(A-B*K_lq)
figure
step(cl_lq)

figure
bode(cl_lq)
title("Bode Diagram of the stabilized syst w/ LQR")

%% LQR at phi = 180 deg %%
close all
Q_uns = zeros(4) ;
% 1st conig, nice and smooth
Q_uns(1,1) = 10 ;   % q for theta
Q_uns(2,2) = 1 ;   % q for theta_dot
Q_uns(3,3) = 10 ;   % q for phi
Q_uns(4,4) = 10 ;   % q for phi_dot
% NT: if you want theta to go to zero q must be at least = to the q for
% phi

% Q_uns(1,1) = 100 ;   % q for theta
% Q_uns(2,2) = 1 ;   % q for theta_dot
% Q_uns(3,3) = 100 ;   % q for phi
% Q_uns(4,4) = 1 ;   % q for phi_dot

R_uns = 1 ;
% R_uns = 10 ;    % for the SW-up
Cq_uns = sqrt(Q_uns) ;

disp("Controllability and Observability Condition")
rank(ctrb(A_uns,B_uns))     % == 4 so OK!
rank(obsv(A_uns,Cq_uns))    % == 4 so ok!

[K_lq_uns S P] = lqr(A_uns,B_uns,Q_uns,R_uns) ;
cl_lq_uns = tf(ss(A_uns-B_uns*K_lq_uns,B_uns,C_uns,D_uns))
disp("LQR poles")
eig(A_uns-B_uns*K_lq_uns)
figure
step(cl_lq_uns)

figure
bode(cl_lq_uns)
title("Bode Diagram of the stabilized syst w/ LQR")

%% LQR + TRAJECTORY TRACKING CONTROL phi = 180° %%
close all
Q_track_uns = zeros(4) ;
Q_track_uns(1,1) = 100 ;   % q for theta
Q_track_uns(2,2) = 1 ;   % q for theta_dot
Q_track_uns(3,3) = 10 ;   % q for phi
Q_track_uns(4,4) = 10 ;   % q for phi_dot
% NT: if you want theta to go to zero q must be at least = to the q for
% phi

R_track_uns = 1;
Cq_track_uns = sqrt(Q_track_uns) ;

disp("Controllability and Observability Condition")
rank(ctrb(A_uns,B_uns))     % == 4 so OK!
rank(obsv(A_uns,Cq_track_uns))    % == 4 so ok!

[K_lq_track_uns S_track P_track] = lqr(A_uns,B_uns,Q_track_uns,R_track_uns) ;

cl_lq_track_uns = tf(ss(A_uns-B_uns*K_lq_track_uns,B_uns,C_uns,D_uns)) 

figure
step(cl_lq_track_uns)


figure
bode(cl_lq_track_uns)
title("Bode Diagram of the Stabilized syst")

At_uns = A_uns-B_uns*K_lq_track_uns ;
Bt_uns = B_uns*K_lq_track_uns(1) ;
figure
step(At_uns,Bt_uns,C_uns,D_uns)
title("Step Response of the Trajectory Tracking Control w/ LQR for theta")

%% LQR + TRAJECTORY TRACKING CONTROL phi_bar = 0 %%
close all
Q_track = zeros(4) ;
Q_track(1,1) = 100 ;   % q for theta
Q_track(2,2) = 1 ;   % q for theta_dot
Q_track(3,3) = 10 ;   % q for phi
Q_track(4,4) = 10 ;   % q for phi_dot
% NT: if you want theta to go to zero q must be at least = to the q for
% phi

R_track = 1;
Cq_track = sqrt(Q_track) ;

disp("Controllability and Observability Condition")
rank(ctrb(A,B))     % == 4 so OK!
rank(obsv(A,Cq_track))    % == 4 so ok!

[K_lq_track S_track P_track] = lqr(A,B,Q_track,R_track) ;

cl_lq_track = tf(ss(A-B*K_lq_track,B,C,D))

figure
step(cl_lq_track)

figure
bode(cl_lq_track)
title("Bode Diagram of the Stabilized syst")

At = A-B*K_lq_track ;
Bt = B*K_lq_track(1) ;
figure
step(At,Bt,C,D)
title("Step Response of the Trajectory Tracking Control w/ LQR for theta")

%% following code lines are for Pendulum damping coeff analisys

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

%% SWING-UP %%
close all
P_sw = [0.5+10i 0.5-10i -50 -100 ] ;
% P_sw = [0.15+10i 0.15-10i -2 -5 ] ;
K_sw_pp = place(A,B,P_sw) 
figure
impulse(A-B*K_sw_pp,B,C,D)
xlim([0 10])
ylim([-pi pi])

syst_cl = tf(ss(A-B*K_sw_pp,B,C,D))
figure
bode(syst_cl)