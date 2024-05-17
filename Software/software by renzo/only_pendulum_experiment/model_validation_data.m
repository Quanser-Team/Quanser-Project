%% preparation %%
close all
clear all
clc

%% data %%

% mechanical parameters

mp_ = 0.024; % pendulum mass
Lp = 0.129; % pendulum length
lp_ = 0.95*Lp/2; % pendulum CoM distance
rp = 0.0098/2; % pendulum radius
%Jp_ = 2.44e-5;  % pendulum moment of inertia 
Jp_ = (1/12)*mp_*(3*rp^2 + Lp^2); % pendulum moment of inertia

g_ = 9.81; % gravity acc

Bp_ = 1.25e-5;


V1 = (mp_*lp_^2 + Jp_);
V2 = lp_*mp_;

%% prepare the data for simulink %%

load('11phi.mat');

time_vector_alpha = phi(1,:);
alpha_vector = (pi/180)*phi(2,:);

% Define the initial time (change this to your actual initial time)
initialTime = 1.966;
endTime =  50;

% Find the index corresponding to the initial time
startIndex = find(time_vector_alpha >= initialTime, 1);
endIndex = find(time_vector_alpha >= endTime, 1);

% Cut the time and data vectors at the initial time
cutTimes = time_vector_alpha(startIndex:endIndex);
cutData = alpha_vector(startIndex:endIndex);

% Translate the time vector so that the initial time is 0
cutTimesTranslated = cutTimes - initialTime;

alpha_0 = cutData(1); %set the initial condition for the simulink model

ts_for_simulink = timeseries(cutData,cutTimesTranslated);

tiledlayout(2, 1)
nexttile
plot(time_vector_alpha,alpha_vector);
title('measured data')
nexttile
plot(cutTimesTranslated,cutData);
title('cut data')

open("parameter_estimation_simulink.slx")


