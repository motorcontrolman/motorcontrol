# 概要
Arduino Dueと[TIの3相GANインバータ](https://www.tij.co.jp/tool/jp/BOOSTXL-3PHGANINV)を使って、
[日本電産の500円モータ](https://ja.aliexpress.com/item/1005001686327895.html)をMATLAB/Simulinkのオートコードでベクトル制御します。

# 環境
1. Ardiono Due
2. [TIの3相GANインバータ](https://www.tij.co.jp/tool/jp/BOOSTXL-3PHGANINV)
3. [日本電産の500円モータ](https://ja.aliexpress.com/item/1005001686327895.html)
4. MATLAB/Simulink R2021a, Home Edition
5. Simulink Support Package for Arduino Hardware
6. MATLAB Support for MinGW-w64 C/C++ Compiler

(上記、(平田先生のGit)[https://github.com/mhirata-dev/arduino_due_motor_control_simulink]をパ…参考に記載しました。)

# ピン接続
Qiitaに書いてます。
マイコン側　https://qiita.com/motorcontrolman/items/ef6670f9dff0f63cdc50
インバータ側　https://qiita.com/motorcontrolman/items/95560fd38545637fad2a

# 実行方法
①モデル　Vector_Control_Lib.slx　を開きます。
②param.m　を実行します。
`isEmbedded = swichSimulationMode('Emb');` とすることでコード生成モードとなります。
`isEmbedded = swichSimulationMode('Sim');` とすることでシミュレーションモードとなります。

③コード生成モードの場合、ビルド、配布および起動ボタンを押してコード生成します。

![image](https://user-images.githubusercontent.com/53783776/134696570-d77da93e-80f2-44aa-81d8-d38442561d88.png)

シミュレーションモードの場合は通常のシミュレーション実行を行います。
