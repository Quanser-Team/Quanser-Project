%% Damping estimation

t=Phi_5.time;
Phi=Phi_5.signals.values(:,2);

Phi= Phi-mean(Phi);

figure()
plot(t,Phi);
xlabel('time[s]');
ylabel('angle[deg]');
grid on, box on;

N = findpicks(Phi_5);
hold on
plot()
