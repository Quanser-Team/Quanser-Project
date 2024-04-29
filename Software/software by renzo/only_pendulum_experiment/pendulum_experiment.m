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

mp_ = 0.02421; % pendulum mass
Lp = 0.129; % pendulum length
lp_ = 0.95*Lp/2; % pendulum CoM distance
rp = 0.0098/2; % pendulum radius
Jp_ = (1/12)*mp_*(3*rp^2 + Lp^2); % pendulum moment of inertia 

g_ = 9.81; % gravity acc

Bp_ = 1e-5;

%% Load measured data %%

load('11phi.mat');

time_vector_alpha = phi(1,:);
alpha_vector = (pi/180)*phi(2,:);

% figure
% plot(time_vector_alpha,alpha_vector);
% xlabel('Time');
% ylabel('measured current');
% grid on;

%% compute oscillation frequency from measured data %%
% zero_crossings_indexes = [];
% for i=1:length(alpha_vector)
%    if alpha_vector(i) == 0 
%       zero_crossings_indexes = [zero_crossings_indexes,i];
%    end
% end
% zero_crossings_times = [];
% for i=1:length(zero_crossings_indexes)
% 
%     zero_crossings_times = [zero_crossings_times,time_vector_alpha(zero_crossings_indexes(i))];
% end
% 
% periods_vector= [];
% for i=40:length(zero_crossings_times)
% 
%     period = zero_crossings_times(i) - zero_crossings_times(i-1);
%     if period>0.2 
%     periods_vector = [periods_vector,period];
%     end
% end
% 
% mean_period = mean(periods_vector);

%% cut the initial part of the experiment%%

% Define the initial time (change this to your actual initial time)
initialTime = 1.978;
endTime = 69;

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
% figure
% plot(cutTimesTranslated,cutData);
% xlabel('Time');
% ylabel('measured current');
% grid on;


%% estimate the damping coeff from the free motion %%

% m = mp_*lp_^2 + Jp_;
% c = Bp;
% k = g_*lp_*mp_;
% 
% w = sqrt(k/m); % undamped natural frequency
% 
% wd = (1/(2*mean_period))*(2*pi) ; % measured frequency of the free response
% 
% h = sqrt(1-(wd/w)^2);
% 
% Bp_ = h*2*m*w


%% peaks envelope curve %%


[peaks,locs] = findpeaks(cutData);
peaks_time = [];

for i=1:length(locs)
    peaks_time = [peaks_time,cutTimesTranslated(locs(i))];
end

% figure
% plot(peaks_time,peaks,'c*');
% xlabel('Time');
% ylabel('peaks');
% grid on;

tiledlayout(3, 1)
nexttile
plot(time_vector_alpha,alpha_vector);
title('measured data')
nexttile
plot(cutTimesTranslated,cutData);
title('cut data')
nexttile
plot(peaks_time,peaks,'c*');
title('peaks')


%% logarithmic decay %%

% log_decay = [];
% 
% for i=1:length(peaks)-1
%     log_decay = [log_decay,(log(peaks(i)/peaks(i+1)))];
% end
% log_decay = [log_decay,0];
% figure
% plot(peaks_time,log_decay);
% xlabel('Time');
% ylabel('peaks');
% grid on;

%% load and prepare validation data %%

% load('13phi.mat');
% 
% time_vector_alpha_val = phi(1,:);
% alpha_vector_val = (pi/180)*phi(2,:);
% 
% figure
% plot(time_vector_alpha_val,alpha_vector_val);
% xlabel('Time');
% ylabel('measured current');
% grid on;
% 
% % Define the initial time (change this to your actual initial time)
% initialTime = 2.698;
% 
% 
% % Find the index corresponding to the initial time
% startIndex = find(time_vector_alpha >= initialTime, 1);
% 
% 
% % Cut the time and data vectors at the initial time
% cutTimes_val = time_vector_alpha_val(startIndex:end);
% cutData_val = alpha_vector_val(startIndex:end);
% 
% % Translate the time vector so that the initial time is 0
% cutTimesTranslated_val = cutTimes_val - initialTime;
% 
% alpha_0_val = cutData_val(1); %set the initial condition for the simulink model
% 
% [peaks_val,locs] = findpeaks(cutData_val);
% peaks_time_val = [];
% 
% for i=1:length(locs)
%     peaks_time_val = [peaks_time_val,cutTimesTranslated_val(locs(i))];
% end
% 
% tiledlayout(3, 1)
% nexttile
% plot(time_vector_alpha_val,alpha_vector_val);
% title('measured data')
% nexttile
% plot(cutTimesTranslated_val,cutData_val);
% title('cut data')
% nexttile
% plot(peaks_time_val,peaks_val,'c*');
% title('peaks')


%% data for damping estimation and simulink model%%

m = mp_*lp_^2 + Jp_;
k = g_*lp_*mp_;
a = 0.1;
c = alpha_0;

open("parameter_estimation_simulink.slx")

%% estimate damping coeff %%

Bp_ = 2*m*a


%% update parameters with estimated values %%
% 
% Bp_ = 1.46e-5
% Jp_ = 2.4573e-5
% 
% Bp_ = 1.51e-5
% Jp_ = 2.44e-5
