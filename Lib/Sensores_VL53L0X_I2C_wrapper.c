
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE

#include <Arduino.h>

#include <math.h>

#include <Wire.h>
#include <Wire.cpp>
#include <twi.h>
#include <twi.c>
#include <VL53L0X.h>
#include <VL53L0X.cpp>
#define XSHUT 5
#define sensor2_newAddress 42
VL53L0X sensor1;
VL53L0X sensor2;

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
#define y_1_width 1

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
void Sensores_VL53L0X_I2C_Outputs_wrapper(int32_T *Sensor1,
			int32_T *Sensor2,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1) {
    
    /* don't do anything for mex file generation */
    # ifndef MATLAB_MEX_FILE
    
Sensor1[0] = sensor1.readRangeContinuousMillimeters();
Sensor2[0] = sensor2.readRangeContinuousMillimeters();

    # endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void Sensores_VL53L0X_I2C_Update_wrapper(int32_T *Sensor1,
			int32_T *Sensor2,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {

    /* don't do anything for mex file generation */
# ifndef MATLAB_MEX_FILE
        
 
  pinMode(XSHUT, OUTPUT);
  Wire.begin();
  
  sensor2.setAddress(sensor2_newAddress);
  pinMode(XSHUT, INPUT);                                                                                                                 
  delay(10);
  sensor1.init();
  sensor2.init();
  sensor1.setTimeout(5000);
  sensor2.setTimeout(5000);
  sensor1.startContinuous();
  sensor2.startContinuous();
 
        # endif
    
    /* initialization done */ 
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

