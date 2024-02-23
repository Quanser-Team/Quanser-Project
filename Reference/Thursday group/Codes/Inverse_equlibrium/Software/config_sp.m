%% CONFIG_SP
%
% Sets the model variables of the Quanser Single Pendulum module depending 
% on the length/type specified (e.g. short, medium, long, or rotary arm).
%
% ************************************************************************
% Input parameters:
% PEND_TYPE     Type of pendulum
% ROTPEN_OPTION Either ROTPEN or ROTPEN-E.
%
% ************************************************************************
% Output parameters:
% g             Gravitational constant                         (m/s^2)
% Mp            Pendulum Mass with T-fitting                   (kg)
% Lp            Full Length of the pendulum (w/ T-fitting)     (m)
% lp            Distance from pivot to centre Of gravity       (m)
% Jp            Pendulum moment of inertia                     (kg.m^2)
% Bp            Viscous damping coefficient as seen at the 
%               pendulum axis                                  (N.m.s/rad)
%
% Copyright (C) 2020 Quanser Consulting Inc.
% Quanser Consulting Inc.
%
%%
%
function [ g, Mp, Lp, lp, Jp, Bp, RtpnOp, RtpnOff ] = config_sp( PEND_TYPE )
% Calculate useful conversion factors
[ K_R2D, K_D2R, K_IN2M, K_M2IN, K_RDPS2RPM, K_RPM2RDPS, K_OZ2N, K_N2OZ, K_LBS2N, K_N2LBS, K_G2MS, K_MS2G ] = calc_conversion_constants ();    
% Gravity Constant
g = 9.81;
%
if strcmp( PEND_TYPE, 'LONG_24IN')
    % Pendulum Mass (with T-fitting)
    Mp = 0.230;
    % Pendulum Full Length (with T-fitting, from axis of rotation to tip)
    Lp = ( 25 + 1 / 4 ) * K_IN2M;  % = 0.6413;
    % Distance from Pivot to Centre Of Gravity
    lp = 13 * K_IN2M; %13 * K_IN2M;  % = 0.3302
    % Pendulum Moment of Inertia (kg.m^2) - approximation
    Jp = Mp * Lp^2 / 12;  % = 7.8838 e-3
    % Equivalent Viscous Damping Coefficient (N.m.s/rad)
    Bp = 0.0024;    
elseif ( strcmp( PEND_TYPE, 'MEDIUM_12IN') )
    % Assumption: 2-DOF Gantry is used with MEDIUM sized pendulum.
    % Pendulum Mass (with T-fitting)
    Mp = 0.127;
    % Pendulum Full Length (with T-fitting, from axis of rotation to tip)
    Lp = ( 13 + 1 / 4 ) * K_IN2M;
    % Distance from Pivot to Centre Of Gravity: calculated experimentally
    lp = ( 6 + 1 / 8 ) * K_IN2M;
    % Pendulum Moment of Inertia (kg.m^2) - approximation
    Jp = Mp * Lp^2 / 12; 
    % Equivalent Viscous Damping Coefficient (N.m.s/rad)
    Bp = 0.0024;
elseif strcmp( PEND_TYPE, 'SHORT_7IN')
    % Pendulum Mass (with T-fitting)
    Mp = 0.097;
    % Pendulum Full Length (with T-fitting, from axis of rotation to tip)
    Lp = (7 + 7 / 8) * K_IN2M;
    % Distance from Pivot to Centre Of Gravity: estimated
    lp = (6 + 7 / 16) * K_IN2M ;
    % Pendulum Moment of Inertia (kg.m^2)
    Jp = Mp * Lp^2 / 12;
    % Equivalent Viscous Damping Coefficient (N.m.s/rad)
    Bp = 0.0024;
elseif strcmp( PEND_TYPE, 'ROTARY_ARM')
    % Arm Mass (with two thumb screws)
    Mp = 0.257;
    % Full Length of Arm (from axis of rotation to tip)
    Lp = 8.5 * K_IN2M; 
    % Distance from Pivot to Centre Of Gravity: calculated experimentally
    lp = (2 + 7/16) * K_IN2M;
    % Pendulum Moment of Inertia (kg.m^2) - approximation
    Jp = Mp * Lp^2 / 12;
    % Equivalent Viscous Damping Coefficient (N.m.s/rad)
    Bp = 0.0024;
else 
    error( 'Error: Set the type of pendulum.' )
end % end of IF statement
%
%
%
end % end of function
