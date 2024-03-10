%% Parameters
L0 = 0.085;      % Arm lengh
l1 = 0.12886/2;  % Distance from rotary hinge to COG of the pendulum
m0 = 0.095;      % Arm mass
m1 = 0.024;      % Pendulum mass
I0 = 8.2282e-5;  % Mr*r^2/3; % arm moment of inertia
I1 = 1.2495e-4;  % pendulum moment of inertia, to be verified
Br = 2.0052e-5;  % viscous damping pendulum, to be estimated
Bp = 6e-5;       % viscous damping rotary arm, to be estimated
g = 9.81;        % Gravity

%% TF of the Model
M = [m1*L0^2 + I0 , -L0*l1*m1;-L0*l1*m1, m1*l1^2 + I1]; % Linear point Matrices
C = [Bp, 0 ; 0, Br];
K = [0, 0; 0, g*l1*m1];

M_2 = [m1*L0^2 + I0 , +L0*l1*m1;+L0*l1*m1, m1*l1^2 + I1]; % Non linear point Matrices
C_2 = [Bp, 0 ; 0, Br];
K_2 = [0, 0; 0, -g*l1*m1];

s = tf('s');
TF_stable = (M*s*s+C*s+K)^-1;
TF_unstable = (M_2*s*s+C_2*s+K_2)^-1;

[num1_stable, den1_stable] = tfdata(TF_stable(1,1), 'v');
[num2_stable, den2_stable] = tfdata(TF_stable(2,1), 'v');
[num3_stable, den3_stable] = tfdata(TF_stable(1,2), 'v');
[num4_stable, den4_stable] = tfdata(TF_stable(2,2), 'v');

[num1_unstable, den1_unstable] = tfdata(TF_unstable(1,1), 'v');
[num2_unstable, den2_unstable] = tfdata(TF_unstable(2,1), 'v');
[num3_unstable, den3_unstable] = tfdata(TF_unstable(1,2), 'v');
[num4_unstable, den4_unstable] = tfdata(TF_unstable(2,2), 'v');

bode(TF_stable);
grid            % We can see that at 10 Hz of movement from Motor movement
                % to Pendulum movement we have a resonance
bode(TF_unstable);
grid
%% SS Model
% A = [0,
%      0,
%      0,
%      0,];
% B = [];
% C = [1 0 0 0;
%      0 0 1 0];
% D = [0;
%      0];