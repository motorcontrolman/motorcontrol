#include <Arduino.h>
#include "Encoder.h"

int16_t enc_count = 0;
int8_t enc_6count = 0;
const int16_t pinA = 2;
const int16_t pinB = 3;
const int16_t pinZ = 4;

void encoderInit(){
  pinMode(pinA,INPUT);
  pinMode(pinB,INPUT);
  pinMode(pinZ,INPUT);
  attachInterrupt(2, enc_changedPinA, CHANGE); 
  attachInterrupt(3, enc_changedPinB, CHANGE);
  attachInterrupt(4, enc_changedPinZ, RISING); 

}

int16_t encoderRead(){
  return enc_count;
}

void count_inc(){
	++enc_count;
	if( enc_count > 68)
		enc_count = 0;
}

void count_dec(){
	--enc_count;
	if( enc_count < 0)
		enc_count = 68;
}


//pinAの割り込み処理
void enc_changedPinA()
{
  boolean D2,D3;
  D2 = (PIOB->PIO_PDSR & PIO_PDSR_P25) == PIO_PDSR_P25;
  D3 = (PIOC->PIO_PDSR & PIO_PDSR_P28) == PIO_PDSR_P28;
  
  if(D2)
  {
    if(D3) count_dec();
    else count_inc();
  } else {
    if(D3) count_inc();
    else count_dec();
  }

}

//pinBの割り込み処理
void enc_changedPinB()
{
    boolean D2,D3;
  D2 = (PIOB->PIO_PDSR & PIO_PDSR_P25) == PIO_PDSR_P25;
  D3 = (PIOC->PIO_PDSR & PIO_PDSR_P28) == PIO_PDSR_P28;
  
  if(D3)
  {
    if(D2) count_inc();
    else count_dec();
  } else {
    if(D2) count_dec();
    else count_inc();
  }

}

//pinZの割り込み処理
void enc_changedPinZ()
{
  //if( enc_count  > 55)//チャタリング対策
  boolean D4;
  D4 = (PIOC->PIO_PDSR & PIO_PDSR_P26) == PIO_PDSR_P26;

  
  if(D4){
    if( enc_count  > 58)
      enc_count = 0;
  }
    /*
  	enc_6count++;
   	if(enc_6count > 6){
  		enc_6count = 0;
  		enc_count = 0;
  	}
   
  }*/
}
