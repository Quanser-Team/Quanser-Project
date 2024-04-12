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
Jr = 9.5958e-5; % rod inertia computed manually
Br = 2.5592e-5; % damping coeff. estimated in previous experiments
k = 1e-6;


%% Neglecting electrical dynamics %%

A =[    0,                    1;
    -k/(Jm+Jr) , (-Br-Kc*Ke/Ra)/(Jm+Jr)];

B = [       0;
    (Kc/Ra)/(Jm+Jr)];

C = [1,0;
     0,1];

D = [0 ; 0];

sys_partial = ss(A,B,C,D)

eigenvalues = eig(A)

%% Transfer Function %%


G_partial = tf(sys_partial)   % compute the transfer function matrix  
% figure 
% bode(G_partial)  % Plot the two Bode diagrams of the two transfer functions that we want ( from Va to theta and from Va to alpha)


%% Load and plot the experimental data

%the motor+rod system was fed a +-1V square wave at 2Hz

load('current4.mat');
load('omega4.mat');
load("input4.mat");

time_vector_current = current(1,:);
current_vector = current(2,:);

figure
plot(time_vector_current,current_vector);
xlabel('Time');
ylabel('measured current');
grid on;

time_vector_omega = omega(1,:);
omega_vector =(pi/180)*omega(2,:); % converted in rad/s

figure
plot(time_vector_omega,omega_vector);
xlabel('Time');
ylabel('measured velocity');
grid on;

time_vector_input = input(1,:);
input_vector =(pi/180)*input(2,:); % converted in rad/s

figure
plot(time_vector_input,input_vector);
xlabel('Time');
ylabel('input voltage');
grid on;


%open("motor_and_rod_model_simulink.slx")

