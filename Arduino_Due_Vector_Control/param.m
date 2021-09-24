clear all;
isEmbedded = swichSimulationMode('Emb');

Ts = 100e-6; % 制御周期
Simulation_Step = Ts/2; %シミュレーション周期 トリガ生成の都合上、Ts/2に設定

%% Motor Param
Pn = 6;
Ra = 0.75;%テスタで計測すると倍ぐらいな気がする。
La = 1.2e-3 * Ra;%時定数ベースで決定
Ke = 4.50E-03; %線間電圧より
Dm = 2e-4;
Jm = Dm * 0.01;%時定数だいたい0,1sより


% Motor Model
s = tf('s');
Ps_ele = 1/(La*s + Ra);
Pz_ele = c2d(Ps_ele, Ts);
Ps_mecha = 1/(Jm*s + Dm);
Pz_mecha = c2d(Ps_mecha, Ts);

%% Controller Setting
% Speed Controller
omega_ref = 600;%200; %rad/s

LockTime = 0.1;%[sec]
AccelTime = 1;%[sec]
TotalTime = LockTime + AccelTime;%[sec]

% Current Controller
tauCurrent = 0.1;
Kp = La / tauCurrent;
Ki_Ts = Ra / tauCurrent * Ts;

% HPF
% LPF: y(n) = k_LPF*y(n-1) + (1 - k_LPF)*u(n)
tauHPF = 1;
k_LPF = tauHPF / (tauHPF + Ts);



%% Power Source
Vdc = 10;

%% Control Board(Arduino Due)
% PWM Setting
DUTY_COUNTER_PERIOD = 4200 - 1;
DUTY_COUNTER_PERIOD_HALF = ( DUTY_COUNTER_PERIOD + 1 )/2;
DUTY_COUNTER_PERIOD_BASE = 2100;%最高周波数10kHz

% DAC Setting
DAC_PULSE_MAX = 4096;
DAC_ANALOG_MAX_0ch = 4;
DAC_ANALOG_MAX_1ch = 4;

%% Driver Board
% pulseを[A]に変換するゲイン 正負反転、6A/2V、3.3V/2048のため
CurrentLSB = -1 * (1/ 0.1) * (3.3 / 2048);
CurrentLSB_INV = 1/CurrentLSB;

EncoderLSB =  1/400;%2 * pi / 400;

% 電流オフセット
Iu_ad_offset = 2020;
Iv_ad_offset = 2022;
Iw_ad_offset = 2020;

%% Data Type Define
omegaRefMAX = 1000;
dqCurrentMAX = 30;
dqVoltageMAX = 30;

fixedTypeOmegaRef = getDataTypeFromMaxAndSign('s', 16, omegaRefMAX);
fixedTypeOmegaRefTs = getDataTypeFromMaxAndSign('s', 16, omegaRefMAX * Ts);
fixedTypeDqCurrent = getDataTypeFromMaxAndSign('s', 16, dqCurrentMAX);
fixedTypeDqVoltage = getDataTypeFromMaxAndSign('s', 16, dqVoltageMAX);
fixedTypeTwoPi = getDataTypeFromMaxAndSign('s', 16, 2 * pi);
ufixedTypeTwoPi = getDataTypeFromMaxAndSign('u', 16, 2 * pi);
fixedTypeMaxOne = getDataTypeFromMaxAndSign('s', 16, 1);
ufixedTypeMaxOne = getDataTypeFromMaxAndSign('u', 16, 1);
ufixedTypeMaxTwenty = getDataTypeFromMaxAndSign('u', 16, 20);
fixedTypeMaxTenThousandth = getDataTypeFromMaxAndSign('s', 16, 1/10000);
fixedTypeMaxTsDivAccelTime = getDataTypeFromMaxAndSign('s', 16, 1/(AccelTime/Ts));
