%% preparation %%
close all
clear all
clc

%% Data %%

Ra = 8.4;  % armature resistance
L = 1.16e-3; % armature inductance
%Ke = 0.042; % torque constant
Kc =  0.042; % back-emf constant
Jm = 4e-6; % motor inertia 
Jh = 0.6e-6; % motor hub inertia 
Br = 0; % damping coeff.
k = 0; %static friction coeff

%% State Space representation %%


A =[ -Ra/L ,      -Kc/L;
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

A1 =[ (-Br-Kc*Kc/Ra)/(Jh+Jm)];

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

%path = 'dati esp renzo 08-04/ramp_p_01';
path = 'dati esp renzo 08-04/ladder_m';

load(append(path,'/current.mat'));
load(append(path,'/omega.mat'));
load(append(path,'/theta.mat'));
load(append(path,'/Va.mat'));

time_vector_current = current(1,:);
current_vector = current(2,:);
%current_vector = smoothdata(current(2,:));

time_vector_omega = omega(1,:);
omega_vector =(pi/180)*omega(2,:); % converted in rad/s
end_index = find(time_vector_omega >= 18, 1);
omega_vector = omega_vector(1:end_index);
time_vector_omega = time_vector_omega(1:end_index);
%time_vector_omega = time_vector_omega(100:6000);
%omega_vector =omega_vector(100:6000); % converted in rad/s


figure
plot(time_vector_omega,omega_vector);
xlabel('Time');
ylabel('measured velocity');
grid on;

time_vector_theta = theta(1,:);
theta_vector = theta(2,:);

figure
plot(time_vector_theta,theta_vector);
xlabel('Time');
ylabel('measured angle');
grid on;

time_vector_Va = Va(1,:);
Va_vector = Va(2,:);
end_index = find(time_vector_Va >= 18, 1);
Va_vector = Va_vector(1:end_index);
time_vector_Va = time_vector_Va(1:end_index);
%time_vector_Va = time_vector_Va(100:6000);
%Va_vector =Va_vector(100:6000); % converted in rad/s

figure
plot(time_vector_Va,Va_vector);
xlabel('Time');
ylabel('input voltage');
grid on;

ts_Va = timeseries(Va_vector,time_vector_Va);

%% current offset compensation %

one_sec_index = find(time_vector_current >= 0.99, 1);
current_offset_vector = current_vector(1:one_sec_index);

current_offset = mean(current_offset_vector);

current_vector = current_vector - current_offset;

figure
plot(time_vector_current,current_vector);
xlabel('Time');
ylabel('measured current');
grid on;

%% Analyze data and compute the damping coefficient from the steady state values%

%the input voltage is a square wave of amplitude +-1V and frequency 0.25Hz

% Find the steady state velocities value
% positive_steady_st_values = [];
% for i=1:length(omega_vector)
%    if ((omega_vector(i)<23) && (omega_vector(i)>22.1))
%        positive_steady_st_values = [positive_steady_st_values,omega_vector(i)];
%    end
% end
% positive_st_st_vel = mean(positive_steady_st_values);
% 
% Va = 1; % the constant input voltage
% omega_m = positive_st_st_vel % the measured constant velocity
% Br = (Kc/(Ra*omega_m))*Va - (Ke*Kc/Ra)

%% ladder input steady state values computation %%

% ss_current = [];
% init_index = find(time_vector_current >= 1.15, 1);
% end_index = find(time_vector_current >= 1.9, 1);
% for i=1:17
%     vector = current_vector(init_index:end_index);
%     init_index = find(time_vector_current >= 1.15+i, 1);
%     end_index = find(time_vector_current >= 1.9+i, 1);
%     ss_current = [ss_current,mean(vector)];
% end
% 
% ss_omega = [];
% init_index = find(time_vector_omega >= 1.15, 1);
% end_index = find(time_vector_omega >= 1.9, 1);
% for i=1:17
%     vector = omega_vector(init_index:end_index);
%     init_index = find(time_vector_omega >= 1.15+i, 1);
%     end_index = find(time_vector_omega >= 1.9+i, 1);
%     ss_omega = [ss_omega,mean(vector)];
% end
% 
% theor_ss_current = [];
% 
% for i=1:17
%    new_val = (1/Ra)*(-0.5*i) - (Kc/Ra)*ss_omega(i); 
%    theor_ss_current = [theor_ss_current,new_val];
% 
% end