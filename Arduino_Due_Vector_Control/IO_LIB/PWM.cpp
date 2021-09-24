#include <Arduino.h>
#include "PWM.h"

uint16_t CounterPeriod;


void pwmInit(){
    
    uint16_t DeadTime;
     
    CounterPeriod = 4200 - 1;
    DeadTime = 20;
    
    //PWM Power ON
    REG_PMC_PCER1=PMC_PCER1_PID36;
    
    //PWMの設定
    REG_PWM_CPRD0 = CounterPeriod;
    REG_PWM_CPRD1 = CounterPeriod;
    REG_PWM_CPRD2 = CounterPeriod;
    REG_PWM_CPRD3 = CounterPeriod;
    
    //REG_PWM_CDTY0 = 2000;
    REG_PWM_CDTY1 = 2100;
    REG_PWM_CDTY2 = 2100;
    REG_PWM_CDTY3 = 2100;
    
    //デッドタイム、プリスケーラの設定、センターアラインド
    REG_PWM_CMR0 = PWM_CMR_CALG | PWM_CMR_CPRE_MCK;
    REG_PWM_CMR1 = PWM_CMR_DTE | PWM_CMR_CALG | PWM_CMR_CPRE_MCK;
    REG_PWM_CMR2 = PWM_CMR_DTE | PWM_CMR_CALG | PWM_CMR_CPRE_MCK;
    REG_PWM_CMR3 = PWM_CMR_DTE | PWM_CMR_CALG | PWM_CMR_CPRE_MCK;
    
    //PWMHおよびPWMLのデッドタイム設定
    REG_PWM_DT1 = PWM_DT_DTH(DeadTime) | PWM_DT_DTL(DeadTime);
    REG_PWM_DT2 = PWM_DT_DTH(DeadTime) | PWM_DT_DTL(DeadTime);
    REG_PWM_DT3 = PWM_DT_DTH(DeadTime) | PWM_DT_DTL(DeadTime);
    
    //PWMの同期設定 なくても動くかも右→むしろあると動かない？
    //REG_PWM_SCM = PWM_SCM_SYNC1 | PWM_SCM_SYNC2 | PWM_SCM_SYNC3;
    
    //PIOのディセーブルレジスタ
    REG_PIOC_PDR = PIO_PDR_P9 | PIO_PDR_P8 | PIO_PDR_P7 | PIO_PDR_P6 | PIO_PDR_P5 | PIO_PDR_P4;
    //ペリフェラルABセレクタ
    REG_PIOC_ABSR |= PIO_ABSR_P9 | PIO_ABSR_P8 | PIO_ABSR_P7 | PIO_ABSR_P6 | PIO_ABSR_P5 | PIO_ABSR_P4;

    //AD変換のためのPWMイベントライン設定                                                             
    PWM->PWM_CMP[0].PWM_CMPM = PWM_CMPM_CEN;                       // PWM0の比較を有効化
    PWM->PWM_ELMR[1] = PWM_ELMR_CSEL0;                             // PWMイベントライン1にPWM0を設定
    PWM->PWM_CMP[0].PWM_CMPV = PWM_CMPV_CV(CounterPeriod - 10);  // PWM0のDUTYを設定
      
    // PWM Enable Register PWM１~３の開始 ここで同時開始しているから同期取れている？
    REG_PWM_ENA = PWM_ENA_CHID3 | PWM_ENA_CHID2 | PWM_ENA_CHID1 | PWM_ENA_CHID0;
    
}

void pwmWrite(uint16_t uDuty, uint16_t vDuty, uint16_t wDuty){
    REG_PWM_CDTY1 = uDuty;
    REG_PWM_CDTY2 = vDuty;
    REG_PWM_CDTY3 = wDuty;

}