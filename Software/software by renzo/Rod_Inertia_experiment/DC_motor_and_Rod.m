%% preparation %%
close all
clear all
clc

%% Data %%

Ra = 8.4;  % armature resistance
L = 1.16e-3; % armature inductance
Ke = 0.042; % torque constant
Kc =  0.042; % back-emf constant
Jm = 4e-6; % motor inertia 
Jr = ; % rod inertia 
Br = ; % damping coeff.



%% Neglecting electrical dynamics %%

A1 =[ (-Br-Kc*Ke/Ra)/(Jh+Jr)];

B1 = [ (Kc/Ra)/(Jm+Jr)];

C1 = [1];

D1 = [0];

sys_partial = ss(A1,B1,C1,D1)

eigenvalues = eig(A1)

%% Transfer Function %%


G_partial = tf(sys_partial)   % compute the transfer function matrix  
% figure 
% bode(G_partial)  % Plot the two Bode diagrams of the two transfer functions that we want ( from Va to theta and from Va to alpha)


%% Load and plot the experimental data

load('current1.mat');
load('omega1.mat');

time_vector_current = current(1,:);
current_vector = current(2,:);

figure
plot(time_vector_current,current_vector);
xlabel('Time');
ylabel('measured current');
grid on;

time_vector_omega = omega(1,:);
omega_vector = omega(2,:);

figure
plot(time_vector_omega,omega_vector);
xlabel('Time');
ylabel('measured velocity');
grid on;


