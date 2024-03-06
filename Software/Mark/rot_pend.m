function y = rot_pend(u, mr, mp, Lr, Lp, Ir, Ip, g0)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
% u(1) = Va
x1 = u(2) ; % theta
x2 = u(3) ; % theta_dot
x3 = u(4) ; % phi
x4 = u(5) ; % phi_dot

a = mr*(Lr/2)^2 + mp*(Lr^2+(Lp*sin(x3))^2) + Ir ;
b = mp*Lr*Lp*cos(x3) ;
%c = b ;
d = mp*Lp^2+Ip ;

e = (-2*mp*Lp^2*sin(x3)*cos(x3)*x2*x4) + ( mp*Lr*Lp*sin(x3)*x2^2 ) + u(1) ;
f = ( mp*Lp^2*sin(x3)*cos(x3)*x2^2 ) + ( mp*g0*Lp*sin(x3) ) ;

B = [a b;
     b d] ;
ne = [e f]' ;
q_ddot = B\ne ;

y(1) = x2 ;
y(2) = q_ddot(1) ;
y(3) = x4 ;
y(4) = q_ddot(2) ;

end