%% preparation %%
close all
clear all
clc


%% Nonlinear equation of motion using Lagrange method %%

syms t alpha(t) lp mp Jp g Bp

Xx = lp*sin(alpha);
Xy = lp*(1-cos(alpha));

Xx_dot = diff(Xx,t);
Xy_dot = diff(Xy,t);


Vcm_square = simplify(Xx_dot^2 + Xy_dot^2);

% Kinetic Energy
Ttotal = simplify(1/2*mp*Vcm_square+1/2*Jp*diff(alpha,t)^2);   
% Gravitational Potential Energy
Utotal = mp*g*lp*(1-cos(alpha));
% Disspiative function
Dtotal = 1/2*Bp*diff(alpha,t)^2;

Ltotal = Ttotal - Utotal;

% Lagrange Equations

eq = simplify( diff(diff(Ltotal,diff(alpha,t)),t) - diff(Ltotal,alpha)) + diff(Dtotal,diff(alpha,t));

%% data %%

% mechanical parameters

mp_ = 0.024; % pendulum mass
Lp = 0.129; % pendulum length
lp_ = Lp/2; % pendulum CoM distance
rp = 0.0098/2; % pendulum radius
Jp_ = (1/12)*mp_*(3*rp^2 + Lp^2); % pendulum moment of inertia 

g_ = 9.81; % gravity acc

Bp_ = 5e-5;

%% estimate the damping coeff from the free motion %%

% m = mp_*lp_^2 + Jp_;
% c = Bp;
% k = g_*lp_*mp_;
% 
% w = sqrt(k/m); % undamped natural frequency
% 
% wd = 1 ; % measured frequency of the free response
% 
% h = sqrt(1-(wd/w)^2);
% 
% Bp_ = h*2*m*w;







