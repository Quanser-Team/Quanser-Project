clc
clear all
close all

%% PARAMETERS ESTIMATION by the use of concetrated mass (the small disc)

load("theta_test1.mat")

Jm = 4.0e-6;
Jd =  0.16e-6;
Jmod = 0.6e-6;  %modulo 
Kt = 0.042;       %N*m/A
Rm = 8.4;
Kp = 5;


theta = theta_test.signals.values(1:400, 2);
time = theta_test.time(1:400)-40;
theta_mean = mean(theta);
theta_m = theta - theta_mean;

yupper = hilbert(theta_m);
yupper = abs(yupper);
ExpDecay = fit(time,yupper,'exp1');
figure(10)
plot(time, theta_m)
hold on
a = ExpDecay.a;
b = ExpDecay.b;
ExpDecay_f = a*exp(b*time);
plot (time, ExpDecay_f)
omega_0 = Kt*Kp/(Rm*(Jmod+Jm+Jd));
r_star = -b*2*(Jd+Jm+Jmod);
r = r_star-Kt^2/Rm;
H = -b/omega_0;

