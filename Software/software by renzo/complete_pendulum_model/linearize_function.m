function f_linearized = linearize_function(f, x, y, t, x0, y0, xdot0, ydot0, xdotdot0, ydotdot0)
f0 = subs(f, {x, y, diff(x,t), diff(y,t), diff(x,t,t), diff(y,t,t)}, {x0, y0, xdot0, ydot0, xdotdot0, ydotdot0})

fx1 = subs(diff(f, x), {x, y, diff(x,t), diff(y,t), diff(x,t,t), diff(y,t,t)}, {x0, y0, xdot0, ydot0, xdotdot0, ydotdot0})
fx2 = subs(diff(f, diff(x,t)), {x, y, diff(x,t), diff(y,t), diff(x,t,t), diff(y,t,t)}, {x0, y0, xdot0, ydot0, xdotdot0, ydotdot0})
fx3 = subs(diff(f, diff(x,t,t)), {x, y, diff(x,t), diff(y,t), diff(x,t,t), diff(y,t,t)}, {x0, y0, xdot0, ydot0, xdotdot0, ydotdot0})

fy1 = subs(diff(f, y), {x, y, diff(x,t), diff(y,t), diff(x,t,t), diff(y,t,t)}, {x0, y0, xdot0, ydot0, xdotdot0, ydotdot0})
fy2 = subs(diff(f, diff(y,t)), {x, y, diff(x,t), diff(y,t), diff(x,t,t), diff(y,t,t)}, {x0, y0, xdot0, ydot0, xdotdot0, ydotdot0});
fy3 = subs(diff(f, diff(y,t,t)), {x, y, diff(x,t), diff(y,t), diff(x,t,t), diff(y,t,t)}, {x0, y0, xdot0, ydot0, xdotdot0, ydotdot0}); 

f_linearized = f0 + fx1*(x) + fx2*(diff(x,t))+ fy1*(y) + fy2*(diff(y,t)) + ...
               fx3*(diff(x,t,t)) + fy3*(diff(y,t,t)) ;

end