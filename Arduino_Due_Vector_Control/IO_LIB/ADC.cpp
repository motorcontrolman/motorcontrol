#include <Arduino.h>
#include "ADC.h"

uint16_t Iu_ad;
uint16_t Iv_ad;
uint16_t Iw_ad;

void adcInit(){
  PMC->PMC_PCER1 |= PMC_PCER1_PID37;                    // ADC power on

  ADC->ADC_CR = ADC_CR_SWRST;                           // Reset ADC
  ADC->ADC_MR =  ADC_MR_TRGEN_EN                       // Hardware trigger select
                  | ADC_MR_TRGSEL_ADC_TRIG5            // Trigger by PWM Event Line 1 PWMイベントライン1をトリガに設定
                  | ADC_MR_PRESCAL(1);                // ここは0でも1でもどっちでも
                  
  ADC->ADC_IER = ADC_IER_EOC7;                          // End Of Conversion interrupt enable for channel 7
  NVIC_EnableIRQ(ADC_IRQn);                             // Enable ADC interrupt
  ADC->ADC_CHER = ADC_CHER_CH7 | ADC_CHER_CH6 | ADC_CHER_CH5;                         // Enable Channel 7 = A0
}

void ADC_Handler() {

  Iu_ad = ADC->ADC_CDR[7];  // Read and clear status register //こいつを消すと動かなくなる。CH7の完了と同期しているから？
  Iv_ad = ADC->ADC_CDR[6];
  Iw_ad = ADC->ADC_CDR[5];
  //adcRead();
  
  //PIOB->PIO_ODSR = PIO_ODSR_P27;//立ち上がり時に関数コールしたいのでトグルではなくHigh設定が必要
  PIOB->PIO_ODSR ^= PIO_ODSR_P27;
  //pwmWrite(enc_count * 10, enc_count * 10, enc_count * 10);
}

uint16_t IuRead(){
  return Iu_ad;
}


uint16_t IvRead(){
  return Iv_ad;
}


uint16_t IwRead(){
  return Iw_ad;
}