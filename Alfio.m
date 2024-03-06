% Parameters init

L0 = 5;  % Lunghezza totale braccio dal motore al cardine
l1 = 10; % Lunghezza del pendolo dal cardine al centro di massa
L1 = 20; % Lunghezza totale del pendolo
theta0 = 10; % Angolo del braccio
theta1 = 10; % Angolo del pendolo
m1 = 5; % Massa del pendolo
I0 = 5; % Inerzia del braccio
I1 = 500; % Inerzia del pendolo


% Cinematica del modello

Xx = L0*cos(theta0)-l1*sin(theta1)*sin(theta0);
Xy = L0*sin(theta0)+l1*sin(theta1)+cos(theta0);
Xz = l1*cos(theta1);

Xcm = [Xx; Xy; Xz];
Vcm = diff(Xcm);
theta0_2 = diff(theta0);
theta1_2 = diff(theta1);

Vcm_2 = Vcm'*Vcm;

% Momenti di inerzia

I0 = ;
I1 = m1*(1/12*L1^2+l1^2);

% Energia del modello

Ttotal = 1/2*I0*theta0_2^2+1/2*m1*Vcm_2+1/2*I1*theta1_2^2;   % Energia cinetica totale del sistema
Utotal = m1*g*l1*(cos(theta1)-1);
Ltotal = Ttotal - Utotal;




