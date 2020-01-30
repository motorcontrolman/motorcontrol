clear all;
Simulation_Step = 10e-5;

%% Motor Paramater
Pn = 4;
Ke = 0.002;
Jm = 2e-4;
Dm = 1e-4;
Ld = 2e-5;
Lq = 4e-5;
R = 2e-3;
omega = 100;

%% Controller Paramater

% Speed Controller
Fspd = 5;% Bandwidth[Hz]
tau_spd = 1/Fspd/2/pi;% Time Constant[sec]

% Current Controller
Fc = 20;% Bandwidth[Hz]
tau = 1/Fc/2/pi;% Time Constant[sec]

% High Frequency Voltage Injection
HF = 400;% Frequency[Hz]
w0 = HF * 2 * pi;% Angular Frequency[rad/s]
Vh = 0.1;% Voltage Amplitude[V]
Qvalue = 1;% Q Factor of Band Path Filter

% Position & Speed Estimator(PLL)
wpll =  20 * 2 * pi;  % Pole Placement[rad/s]
kp = 2 * wpll; % P Gain
ki = wpll^2; % I Gain
wlpf =  20 * 2 * pi;  % Cutoff Angular Frequency[rad/s]