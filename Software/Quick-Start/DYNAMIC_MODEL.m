clear all
close all
clc

% DYNAMIC MODEL

%% PARAMETERS

g0= 9.81;

%ARM(rod)

Lr = 0.085;
mr= 0.095;
Ir= 1/3*mr*Lr^2;

%PENDULUM

Lp = 0.129;
mp= 0.024;
Ip= 1/3*mp*(Lp/2)^2;


%% MATRICES

theta = sym('theta');
theta_dot = sym('theta_dot');
phi = sym('phi');
phi_dot = sym('phi_dot');
tau1= sym('tau1');

B = [Ir+mp*(Lr/2)^2+(Lp/2)^2*mp*sin(theta)^2,     Lr*(Lp/2)*mp*cos(theta);
    Lp*Lr*mp*cos(theta),                  Ip+mp*(Lp/2)^2];

C= [2*(Lp/2)^2*mp*sin(theta)*cos(theta)+theta_dot,        -Lr*(Lp/2)*mp*sin(theta)*theta_dot;
    -(Lp/2)^2*mp*sin(theta)*cos(theta)*phi_dot,             0];

g= [0; -g0*(Lp/2)*mp*sin(theta)];

tau= [tau1; 0];

%% INVERSION

q = [theta; phi];
q_dot =[theta_dot; phi_dot];

q_ddot= inv(B)*(tau - C*q_dot - g);

%% STATE SPACE REPRESENTATION

x2= theta_dot;
x4= phi_dot;

dx(1)= x2;
dx(2)= q_ddot(1);
dx(3)= x4;
dx(4)= q_ddot(2);


