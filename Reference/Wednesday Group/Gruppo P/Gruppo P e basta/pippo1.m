clc
clear all
close all

%% Inertia estimation
load("phi_test.mat")
phi = phi_test.signals.values;
mean_phi = mean(phi);
phi = phi-mean_phi;
time = phi_test.time;
time = time-time(1);

yupper = hilbert(phi);
yupper = abs(yupper);
ExpDecay = fit(time,yupper,'exp1');
a = ExpDecay.a;
b = ExpDecay.b;
ExpDecay_f = a*exp(b*time);
[peaks,loc] = findpeaks(phi);

figure (1)
plot (time,ExpDecay_f,time,phi);
hold on
scatter(time(loc), peaks);

%T = zeros(length(loc)-1);

for ii = 1:length(loc)-1
    T(ii) = time(loc(ii+1)) - time(loc(ii));
end

T = mean(T);        % period
f = 1/T;            % natural frequency
omega = 2*pi*f;
h =-b/(2*pi*f)      % adimensional damping
l = 0.129;
mp = 0.024;
Jp = mp*9.81*l/(2*omega^2);








