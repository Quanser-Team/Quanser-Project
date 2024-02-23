function dx = dx_fun(x,u)

% Arm and Pendulum parameters. 0 for the arm, 1 for the pendulum.
l0 = 0.085; 
l1_tot = 0.12886/2;
l1 = l1_tot-0.0075;
m0 = 0.095;
m1 = 0.024;
% Damping, put here values when measured
d_phi = 2.6173e-06;
d_theta = 0;

% Motor parameters
Jm = 4*10^(-6); %Rotor inertia
kt = 0.042; %Torque constant
Rm = 8.4; %Terminal Resistance
Lm = 1.16*10^(-3); %Rotor Inductance

j0 = m0*l0^2/2 + Jm;
j1 = m1*(l1_tot*2)^2/12;
lx = 0; 
g = 9.81;

% Pendulum equations, NOT state space
% A_1 = @(x)[j0+l0^2*m1+l1^2*m1+lx^2*m0-l1^2*m1*cos(x(4))^2, -l0*l1*m1*cos(x(4));...
%     -l0*m1*l1*cos(x(4)), m1*l1^2+j1];
% 
% A_2 =@(x) [-l0*l1*m1*sin(x(4))*x(2)^2-2*l1^2*m1*cos(x(4))*sin(x(4))*x(2)*x(1);...
%     m1*cos(x(4))*sin(x(4))*l1^2*x(1)^2-g*m1*sin(x(4))*l1];

A_1 = [j0+l0^2*m1+l1^2*m1+lx^2*m0-l1^2*m1*cos(x(4))^2, -l0*l1*m1*cos(x(4)),0,0;...
    -l0*m1*l1*cos(x(4)), m1*l1^2+j1,0,0;0 0 1 0 ;0 0 0 1];

A_2 = [-l0*l1*m1*sin(x(4))*x(2)^2-2*l1^2*m1*cos(x(4))*sin(x(4))*x(2)*x(1)-kt*kt/Rm*x(1);...
    m1*cos(x(4))*sin(x(4))*l1^2*x(1)^2-g*m1*sin(x(4))*l1;x(1);x(2)];

B_1 = u*[kt/Rm 0 0 0]';

A = A_1\A_2;
B = A_1\B_1;

dx = A + B;

end