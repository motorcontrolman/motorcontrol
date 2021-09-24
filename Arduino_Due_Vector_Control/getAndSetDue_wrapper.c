
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#ifndef MATLAB_MEX_FILE
#include <arduino.h>
//#include "Encoder.h"
//#include "Encoder.cpp"
//#include "PWM.h"
//#include "PWM.cpp"
//#include "ADC.h"
//#include "ADC.cpp"
//#include "DAC.h"
//#include "DAC.cpp"
extern int16_t enc_count;
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 3
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void getAndSetDue_Outputs_wrapper(const uint16_T *Duty,
			const uint16_T *DAC,
			uint16_T *Iuvw,
			uint16_T *Encoder,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* このサンプルは、出力を入力と等しく設定します
 y0[0] = u0[0]; 
 複素信号の場合は、次を使用します: y0[0].re = u0[0].re; 
 y0[0].im = u0[0].im;
 y1[0].re = u1[0].re;
 y1[0].im = u1[0].im;
 */
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void getAndSetDue_Update_wrapper(const uint16_T *Duty,
			const uint16_T *DAC,
			uint16_T *Iuvw,
			uint16_T *Encoder,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
    uint16_T encCount;
    
    //Encoder[0] = 0;
    pwmWrite(Duty[0], Duty[1], Duty[2]);
    encCount = encoderRead();
    
    Encoder[0] = encCount;
    Iuvw[0] = IuRead();
    Iuvw[1] = IvRead();
    Iuvw[2] = IwRead();
    //pwmWrite(encCount,encCount,encCount)
    //REG_PWM_CDTY1 = Duty[0];
    //REG_PWM_CDTY2 = Duty[1];
    //REG_PWM_CDTY3 = Duty[2];
    dacWrite(DAC[0], DAC[1]);
    PIOB->PIO_ODSR ^= PIO_ODSR_P27;
#endif
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

