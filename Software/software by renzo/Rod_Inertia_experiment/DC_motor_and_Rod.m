%% preparation %%
close all
clear all
clc

%% Data %%

Ra = 8.4;  % armature resistance
L = 1.16e-3; % armature inductance
Ke = 0.042; % torque constant
Kc =  0.042; % back-emf constant
Jm = 4e-6 + 0.6e-6; % motor inertia and hub attachment inertia
Jr = 4.98e-5; % rod inertia computed manually
Br = 1.49e-5; % damping coeff. estimated in previous experiments
k=0; %culoumb friction coeff


%% Neglecting electrical dynamics %%

A1 =[ (-Br-Kc*Ke/Ra)/(Jm+Jr)];

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

%the motor+rod system was fed a +-1V square wave at 0.1Hz

load('current2.mat');
load('omega2.mat');

init_t = 24.996;
final_t = 29.6;

time_vector_current = current(1,:);
current_vector = current(2,:);

figure
plot(time_vector_current,current_vector);
xlabel('Time');
ylabel('measured current');
grid on;

time_vector_omega = omega(1,:);
omega_vector =(pi/180)*omega(2,:); % converted in rad/s
end_index = find(time_vector_omega >= final_t, 1);
start_index = find(time_vector_omega >= init_t, 1);
time_vector_omega = time_vector_omega(start_index:end_index);
omega_vector =omega_vector(start_index:end_index);

omega0 = omega_vector(1);
time_vector_omega = time_vector_omega - time_vector_omega(1);

figure
plot(time_vector_omega,omega_vector);
xlabel('Time');
ylabel('measured velocity');
grid on;

open("motor_and_rod_model_simulink.slx")

%% estimated values %%

% Br = 2.5592e-5
% Jr = 9.5958e-5
