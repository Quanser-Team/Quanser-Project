mr = 0.095; % rotary arm mass
mh = 0.0106; % rotary hub mass
Lr_ = 0.085; % rotary arm length
  % rotary arm centre of mass position computation:
   l1=0.05;
   l2=0.057;
   l3=0.008;
   r1=0.028/2;
   r2=0.0065/2;
   r3=0.0111;
   xg1=0.006;
   xg2= xg1 + l1/2 + l2/2;
   xg3 = 0;
   V1=pi*r1^2*l1;
   V2=pi*r2^2*l2;
   V3=pi*r3^2*l3;
   xg = (V1*xg1 + V2*xg2 + V3*xg3)/(V1 + V2 + V3);
  % end of computations
lr = xg; % rotary arm CoM distance
  % rotary arm moment of inertia computation:
   density = mr/(V1+V2);
   J1= (1/12)*density*V1*(3*r1^2 + l1^2);
   J2= (1/12)*density*V2*(3*r2^2 + l2^2);
   J3 = 0.6e-6;
   Jtot = (J1 + density*V1*(xg1-xg)^2) + (J2 + density*V2*(xg2-xg)^2) + J3;
   % end of computations
Jr = Jtot; % rotary arm moment of inertia
Jh = 0.6e-6; % module attachment moment of inertia
Jr_ex_ = Jr + (mr+mh)*lr^2 + Jh; % rotary arm "extended" moment of inertia 