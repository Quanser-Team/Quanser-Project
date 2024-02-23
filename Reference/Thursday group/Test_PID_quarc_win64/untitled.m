clc
clear all
close all
t=Phi.time;
Phi=Phi.signals.values(:,2);
plot(t,Phi);
grid on, box on;
