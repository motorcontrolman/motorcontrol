clear all
Simulation_step = 1e-4;

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
Ts_ctrl = 2e-4; %制御刻み

F_hpf = 2; %ハイパスフィルタ時定数
tau = 1/ ( F_hpf* 2 * pi);
a = tau/(Ts_ctrl+tau);
b = Ts_ctrl/(Ts_ctrl+tau);

wn = 10 * 2 * pi;
zeta = 1.5;
K_Idelta = 10; %安定化ゲイン
Kp_Ia = 2 * zeta * L * wn - R;
if (Kp_Ia < 0) Kp_Ia=0; end
Ki_Ia = L * wn * wn * Ts_ctrl;
Ki_v = 0.01;
