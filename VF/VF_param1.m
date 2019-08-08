clear all

%% motor param
L = 0.02e-3;
Ld = L;
Lq = L;
Pn = 7;
Ke = 0.8e-3;
R = 20e-3;
J = 2e-4;
D = 1e-4;

%% control param
Fc =  1000;%Control Frequency
Tc = 1 / Fc;

F_hpf = 2; %Cutoff Frequency of HPF
tau = 1/ ( F_hpf* 2 * pi);
a = tau/(Tc+tau); %HPF Gain (Implemented as '1 - LPF',Discretized)
b = Tc/(Tc+tau);

K_Idelta = 10; %Stabilization Gain
Ki_v = 0.01; %Reactive Current Controller Gain
