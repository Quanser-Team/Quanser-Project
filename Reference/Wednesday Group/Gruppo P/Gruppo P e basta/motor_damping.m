clc 
clear all

%%
Kt = 0.042;             % torque constant
Km = 0.042;             % back emf constant, to be verified
Rm = 8.4;               % terminal resistance

%%

current1=current.signals.values;
velocity1=velocity.signals.values;

disp('current')
mean_current=mean(current1)

disp('velocity')
mean_vel=mean(velocity1)

c_tilde=Kt*mean_current/mean_vel;

c=c_tilde-Kt*Kt/Rm