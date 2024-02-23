% IMPORTANT: Make sure you run setup_rotpen.m first. You need the (A,B)
% state-space matrices.
%
%% Find Tranformation Matrix W
% Characteristic equation: s^4 + a_4*s^3 + a_3*s^2 + a_2*s + a_1
a = poly(A);
% 
% Companion matrices (Ac, Bc)
Ac = [  0 1 0 0;
        0 0 1 0;
        0 0 0 1;
        -a(5) -a(4) -a(3) -a(2)];
%
Bc = [0; 0; 0; 1];
%
% Controllability
T = 0;
% Controllability of companion matrices
Tc = 0;
% Transformation matrices
W = 0;
%
%% Find Gain
% Companion state-feedback control gain
Kc = [0 0 0 0];
% Convert back from companion form
K = [0 0 0 0]
%
%% Closed-loop System Poles
% Find poles of closed-loop system. 
% Verify that they are the same as the desired poles.
cls_poles = [0 0 0 0]
