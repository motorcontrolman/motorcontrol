#include <Arduino.h>
#include "DAC.h"

void dacInit(){
  PMC->PMC_PCER1 = PMC_PCER1_PID38;                   // DACC power ON

  DACC->DACC_CR = DACC_CR_SWRST ;                     // Reset DACC

  DACC->DACC_MR =
    DACC_MR_TRGEN_DIS | // DACC in free running mode
    DACC_MR_WORD_HALF | // Half-Word transfer
    DACC_MR_TAG_EN;

  DACC->DACC_CHER = DACC_CHER_CH1 | DACC_CHER_CH0;                   // enable channel 1 = DAC1 この場合、交互に出る

}

void dacWrite(uint16_t DAC0, uint16_t DAC1){
    DACC->DACC_CDR = (0 << 12) | DAC0;
    DACC->DACC_CDR = (1 << 12) | DAC1;

}
