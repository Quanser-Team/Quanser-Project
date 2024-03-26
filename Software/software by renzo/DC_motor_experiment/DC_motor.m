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
Jh = 0.6e-6; % motor hub inertia 
Br = 0; % damping coeff.


%% State Space representation %%


A =[ -Ra/L ,      -Ke/L;
   Kc/(Jm+Jh) , -Br/(Jm+Jh)];

B = [1/L;
      0];

C = [1,0;
     0,1];

D = [0;0];

sys_complete = ss(A,B,C,D)

eigenvalues = eig(A)

%% Transfer Function %%


G_tot = tf(sys_complete)   % compute the transfer function matrix  
% figure 
% bode(G_tot)  % Plot the two Bode diagrams of the two transfer functions that we want ( from Va to theta and from Va to alpha)

%% Neglecting electrical dynamics %%

A1 =[ (-Br-Kc*Ke/Ra)/(Jh+Jm)];

B1 = [ (Kc/Ra)/(Jm+Jh)];

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
omega_vector =(pi/180)*omega(2,:); % converted in rad/s

figure
plot(time_vector_omega,omega_vector);
xlabel('Time');
ylabel('measured velocity');
grid on;


%% Analyze data and compute the damping coefficient from the steady state values%

%the input voltage is a square wave of amplitude +-1V and frequency 0.25Hz

% Find the steady state velocities value
positive_steady_st_values = [];
for i=1:length(omega_vector)
   if ((omega_vector(i)<23) && (omega_vector(i)>22.1))
       positive_steady_st_values = [positive_steady_st_values,omega_vector(i)];
   end
end
positive_st_st_vel = mean(positive_steady_st_values);

Va = 1; % the constant input voltage
omega_m = positive_st_st_vel % the measured constant velocity
Br = (Kc/(Ra*omega_m))*Va - (Ke*Kc/Ra)

