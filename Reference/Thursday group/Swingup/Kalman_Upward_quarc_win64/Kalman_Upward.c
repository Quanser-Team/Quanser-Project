/*
 * Kalman_Upward.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Kalman_Upward".
 *
 * Model version              : 9.24
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Dec  5 16:37:51 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Kalman_Upward.h"
#include "rtwtypes.h"
#include "Kalman_Upward_private.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "Kalman_Upward_dt.h"

/* Block signals (default storage) */
B_Kalman_Upward_T Kalman_Upward_B;

/* Continuous states */
X_Kalman_Upward_T Kalman_Upward_X;

/* Block states (default storage) */
DW_Kalman_Upward_T Kalman_Upward_DW;

/* Real-time model */
static RT_MODEL_Kalman_Upward_T Kalman_Upward_M_;
RT_MODEL_Kalman_Upward_T *const Kalman_Upward_M = &Kalman_Upward_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Kalman_Upward_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model output function */
void Kalman_Upward_output(void)
{
  /* local block i/o variables */
  real_T rtb_SmoothSignalGenerator;
  __m128d tmp_1;
  real_T rtb_Akxhatkk1[3];
  real_T rtb_y_n[3];
  real_T rtb_y_n_0[3];
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_HILReadEncoderTimebase;
  real_T rtb_MemoryX_idx_0;
  real_T rtb_MemoryX_idx_1;
  real_T rtb_MemoryX_idx_2;
  real_T tmp;
  real_T tmp_0;
  int32_T i;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(Kalman_Upward_M)) {
    /* set solver stop time */
    if (!(Kalman_Upward_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Kalman_Upward_M->solverInfo,
                            ((Kalman_Upward_M->Timing.clockTickH0 + 1) *
        Kalman_Upward_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Kalman_Upward_M->solverInfo,
                            ((Kalman_Upward_M->Timing.clockTick0 + 1) *
        Kalman_Upward_M->Timing.stepSize0 + Kalman_Upward_M->Timing.clockTickH0 *
        Kalman_Upward_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Kalman_Upward_M)) {
    Kalman_Upward_M->Timing.t[0] = rtsiGetT(&Kalman_Upward_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Kalman_Upward_DW.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Kalman_Upward_DW.EnabledSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(Kalman_Upward_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: Kalman_Upward/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (Kalman_Upward_DW.HILReadEncoderTimebase_Task, 1,
         &Kalman_Upward_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        rtb_HILReadEncoderTimebase = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase =
          Kalman_Upward_DW.HILReadEncoderTimebase_Buffer;
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: Kalman_Upward/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Kalman_Upward_DW.HILInitialize_Card,
        &Kalman_Upward_P.HILReadEncoder_channels, 1,
        &Kalman_Upward_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
      } else {
        rtb_DiscreteTimeIntegrator = Kalman_Upward_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/counts to rad1' */
    Kalman_Upward_B.countstorad1 = Kalman_Upward_P.countstorad1_Gain *
      rtb_DiscreteTimeIntegrator;

    /* Gain: '<Root>/counts to rad' */
    Kalman_Upward_B.countstorad = Kalman_Upward_P.countstorad_Gain *
      rtb_HILReadEncoderTimebase;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Sum: '<Root>/Add1'
     */
    Kalman_Upward_B.Sum = Kalman_Upward_B.countstorad -
      Kalman_Upward_P.Constant3_Value;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn1'
   */
  Kalman_Upward_B.Gain = (Kalman_Upward_P.TransferFcn1_C *
    Kalman_Upward_X.TransferFcn1_CSTATE + Kalman_Upward_P.TransferFcn1_D *
    Kalman_Upward_B.countstorad1) * Kalman_Upward_P.Gain_Gain;

  /* Gain: '<Root>/Gain1' */
  Kalman_Upward_B.Gain1 = Kalman_Upward_P.Gain1_Gain * Kalman_Upward_B.Gain;

  /* TransferFcn: '<Root>/Transfer Fcn' */
  rtb_HILReadEncoderTimebase = Kalman_Upward_P.TransferFcn_C *
    Kalman_Upward_X.TransferFcn_CSTATE + Kalman_Upward_P.TransferFcn_D *
    Kalman_Upward_B.Sum;

  /* Quantizer: '<Root>/Quantizer' incorporates:
   *  SignalConversion generated from: '<Root>/Vector Concatenate'
   * */
  Kalman_Upward_B.Quantizer[0] = rt_roundd_snf(Kalman_Upward_B.Gain1 /
    Kalman_Upward_P.ts) * Kalman_Upward_P.ts;
  Kalman_Upward_B.Quantizer[1] = rt_roundd_snf(rtb_HILReadEncoderTimebase /
    Kalman_Upward_P.ts) * Kalman_Upward_P.ts;
  Kalman_Upward_B.Quantizer[2] = rt_roundd_snf(Kalman_Upward_B.countstorad1 /
    Kalman_Upward_P.ts) * Kalman_Upward_P.ts;
  Kalman_Upward_B.Quantizer[3] = rt_roundd_snf(Kalman_Upward_B.Sum /
    Kalman_Upward_P.ts) * Kalman_Upward_P.ts;
  if (rtmIsMajorTimeStep(Kalman_Upward_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  ZeroOrderHold: '<Root>/Zero-Order Hold'
     */
    /* MATLAB Function 'MATLAB Function1': '<S4>:1' */
    /* '<S4>:1:2' */
    rtb_y_n[0] = Kalman_Upward_B.Quantizer[0];
    rtb_y_n[1] = Kalman_Upward_B.Quantizer[1];
    rtb_y_n[2] = Kalman_Upward_B.Quantizer[3];

    /* Delay: '<S2>/MemoryX' incorporates:
     *  Constant: '<S2>/X0'
     */
    if (Kalman_Upward_DW.icLoad) {
      Kalman_Upward_DW.MemoryX_DSTATE[0] = Kalman_Upward_P.X0_Value[0];
      Kalman_Upward_DW.MemoryX_DSTATE[1] = Kalman_Upward_P.X0_Value[1];
      Kalman_Upward_DW.MemoryX_DSTATE[2] = Kalman_Upward_P.X0_Value[2];
    }

    rtb_MemoryX_idx_0 = Kalman_Upward_DW.MemoryX_DSTATE[0];
    rtb_MemoryX_idx_1 = Kalman_Upward_DW.MemoryX_DSTATE[1];
    rtb_MemoryX_idx_2 = Kalman_Upward_DW.MemoryX_DSTATE[2];

    /* Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S61>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&Kalman_Upward_M->solverInfo)) {
      /* Constant: '<S2>/Enable' */
      if (Kalman_Upward_P.Enable_Value) {
        Kalman_Upward_DW.EnabledSubsystem_MODE = true;
      } else if (Kalman_Upward_DW.EnabledSubsystem_MODE) {
        /* Disable for Product: '<S61>/Product2' incorporates:
         *  Outport: '<S61>/deltax'
         */
        Kalman_Upward_B.Product2[0] = Kalman_Upward_P.deltax_Y0;
        Kalman_Upward_B.Product2[1] = Kalman_Upward_P.deltax_Y0;
        Kalman_Upward_B.Product2[2] = Kalman_Upward_P.deltax_Y0;
        Kalman_Upward_DW.EnabledSubsystem_MODE = false;
      }
    }

    if (Kalman_Upward_DW.EnabledSubsystem_MODE) {
      for (i = 0; i <= 0; i += 2) {
        /* Sum: '<S61>/Add1' incorporates:
         *  Constant: '<S2>/C'
         *  Delay: '<S2>/MemoryX'
         *  Product: '<S61>/Product'
         */
        tmp_1 = _mm_loadu_pd(&rtb_y_n[i]);
        _mm_storeu_pd(&rtb_y_n_0[i], _mm_sub_pd(tmp_1, _mm_add_pd(_mm_add_pd
          (_mm_mul_pd(_mm_loadu_pd(&Kalman_Upward_P.C_Value[i + 3]), _mm_set1_pd
                      (Kalman_Upward_DW.MemoryX_DSTATE[1])), _mm_mul_pd
           (_mm_loadu_pd(&Kalman_Upward_P.C_Value[i]), _mm_set1_pd
            (Kalman_Upward_DW.MemoryX_DSTATE[0]))), _mm_mul_pd(_mm_loadu_pd
          (&Kalman_Upward_P.C_Value[i + 6]), _mm_set1_pd
          (Kalman_Upward_DW.MemoryX_DSTATE[2])))));
      }

      /* Sum: '<S61>/Add1' incorporates:
       *  Constant: '<S2>/C'
       *  Delay: '<S2>/MemoryX'
       *  Product: '<S61>/Product'
       */
      for (i = 2; i < 3; i++) {
        rtb_y_n_0[i] = rtb_y_n[i] - ((Kalman_Upward_P.C_Value[i + 3] *
          Kalman_Upward_DW.MemoryX_DSTATE[1] + Kalman_Upward_P.C_Value[i] *
          Kalman_Upward_DW.MemoryX_DSTATE[0]) + Kalman_Upward_P.C_Value[i + 6] *
          Kalman_Upward_DW.MemoryX_DSTATE[2]);
      }

      for (i = 0; i <= 0; i += 2) {
        /* Product: '<S61>/Product2' incorporates:
         *  Constant: '<S8>/KalmanGainM'
         */
        _mm_storeu_pd(&Kalman_Upward_B.Product2[i], _mm_set1_pd(0.0));
        tmp_1 = _mm_loadu_pd(&Kalman_Upward_B.Product2[i]);
        _mm_storeu_pd(&Kalman_Upward_B.Product2[i], _mm_add_pd(_mm_mul_pd
          (_mm_loadu_pd(&Kalman_Upward_P.KalmanGainM_Value[i]), _mm_set1_pd
           (rtb_y_n_0[0])), tmp_1));
        tmp_1 = _mm_loadu_pd(&Kalman_Upward_B.Product2[i]);
        _mm_storeu_pd(&Kalman_Upward_B.Product2[i], _mm_add_pd(_mm_mul_pd
          (_mm_loadu_pd(&Kalman_Upward_P.KalmanGainM_Value[i + 3]), _mm_set1_pd
           (rtb_y_n_0[1])), tmp_1));
        tmp_1 = _mm_loadu_pd(&Kalman_Upward_B.Product2[i]);
        _mm_storeu_pd(&Kalman_Upward_B.Product2[i], _mm_add_pd(_mm_mul_pd
          (_mm_loadu_pd(&Kalman_Upward_P.KalmanGainM_Value[i + 6]), _mm_set1_pd
           (rtb_y_n_0[2])), tmp_1));
      }

      for (i = 2; i < 3; i++) {
        /* Product: '<S61>/Product2' incorporates:
         *  Constant: '<S8>/KalmanGainM'
         */
        Kalman_Upward_B.Product2[i] = 0.0;
        Kalman_Upward_B.Product2[i] += Kalman_Upward_P.KalmanGainM_Value[i] *
          rtb_y_n_0[0];
        Kalman_Upward_B.Product2[i] += Kalman_Upward_P.KalmanGainM_Value[i + 3] *
          rtb_y_n_0[1];
        Kalman_Upward_B.Product2[i] += Kalman_Upward_P.KalmanGainM_Value[i + 6] *
          rtb_y_n_0[2];
      }

      if (rtsiIsModeUpdateTimeStep(&Kalman_Upward_M->solverInfo)) {
        srUpdateBC(Kalman_Upward_DW.EnabledSubsystem_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S35>/Enabled Subsystem' */

    /* Sum: '<S35>/Add' incorporates:
     *  Delay: '<S2>/MemoryX'
     */
    Kalman_Upward_B.Add[0] = Kalman_Upward_B.Product2[0] +
      Kalman_Upward_DW.MemoryX_DSTATE[0];
    Kalman_Upward_B.Add[1] = Kalman_Upward_B.Product2[1] +
      Kalman_Upward_DW.MemoryX_DSTATE[1];
    Kalman_Upward_B.Add[2] = Kalman_Upward_B.Product2[2] +
      Kalman_Upward_DW.MemoryX_DSTATE[2];

    /* Gain: '<S1>/Gain1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    Kalman_Upward_B.Gain1_d = Kalman_Upward_P.Gain1_Gain_a *
      Kalman_Upward_P.Constant2_Value;
  }

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function3'
   *  ManualSwitch: '<Root>/Manual Switch'
   *  SignalConversion generated from: '<Root>/Vector Concatenate'
   * */
  /* MATLAB Function 'MATLAB Function3': '<S6>:1' */
  /* '<S6>:1:2' */
  /* '<S6>:1:3' */
  /* '<S6>:1:4' */
  /* '<S6>:1:5' */
  /* MATLAB Function 'MATLAB Function': '<S3>:1' */
  /* '<S3>:1:5' */
  if (Kalman_Upward_P.ManualSwitch_CurrentSetting == 1) {
    rtb_DiscreteTimeIntegrator = Kalman_Upward_B.Add[0];
    rtb_HILReadEncoderTimebase = Kalman_Upward_B.Add[1];
    tmp = Kalman_Upward_B.countstorad1;
    tmp_0 = Kalman_Upward_B.Add[2];
  } else {
    rtb_DiscreteTimeIntegrator = Kalman_Upward_B.Gain1;
    tmp = Kalman_Upward_B.countstorad1;
    tmp_0 = Kalman_Upward_B.Sum;
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  ManualSwitch: '<Root>/Manual Switch'
   */
  Kalman_Upward_B.Add_e = Kalman_Upward_B.Gain1_d - (((Kalman_Upward_P.K_pp[0] *
    rtb_DiscreteTimeIntegrator + Kalman_Upward_P.K_pp[1] *
    rtb_HILReadEncoderTimebase) + Kalman_Upward_P.K_pp[2] * tmp) +
    Kalman_Upward_P.K_pp[3] * tmp_0);

  /* Saturate: '<Root>/Saturation' */
  if (Kalman_Upward_B.Add_e > Kalman_Upward_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    Kalman_Upward_B.Saturation = Kalman_Upward_P.Saturation_UpperSat;
  } else if (Kalman_Upward_B.Add_e < Kalman_Upward_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    Kalman_Upward_B.Saturation = Kalman_Upward_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    Kalman_Upward_B.Saturation = Kalman_Upward_B.Add_e;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Switch: '<Root>/Switch' */
  if (Kalman_Upward_B.countstorad >= Kalman_Upward_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' */
    Kalman_Upward_B.Switch = Kalman_Upward_B.Saturation;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Kalman_Upward_B.Switch = Kalman_Upward_P.Constant1_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Step: '<Root>/Step' incorporates:
   *  Step: '<Root>/Step1'
   */
  rtb_DiscreteTimeIntegrator = Kalman_Upward_M->Timing.t[0];
  if (rtb_DiscreteTimeIntegrator < Kalman_Upward_P.Step_Time) {
    tmp = Kalman_Upward_P.Step_Y0;
  } else {
    tmp = Kalman_Upward_P.Step_YFinal;
  }

  /* Step: '<Root>/Step1' */
  if (rtb_DiscreteTimeIntegrator < Kalman_Upward_P.Step1_Time) {
    rtb_DiscreteTimeIntegrator = Kalman_Upward_P.Step1_Y0;
  } else {
    rtb_DiscreteTimeIntegrator = Kalman_Upward_P.Step1_YFinal;
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  Step: '<Root>/Step'
   *  Step: '<Root>/Step1'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum3'
   */
  rtb_HILReadEncoderTimebase = (tmp + rtb_DiscreteTimeIntegrator) +
    Kalman_Upward_B.Switch;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_HILReadEncoderTimebase > Kalman_Upward_P.Saturation1_UpperSat) {
    /* Saturate: '<Root>/Saturation1' */
    Kalman_Upward_B.Saturation1 = Kalman_Upward_P.Saturation1_UpperSat;
  } else if (rtb_HILReadEncoderTimebase < Kalman_Upward_P.Saturation1_LowerSat)
  {
    /* Saturate: '<Root>/Saturation1' */
    Kalman_Upward_B.Saturation1 = Kalman_Upward_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation1' */
    Kalman_Upward_B.Saturation1 = rtb_HILReadEncoderTimebase;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(Kalman_Upward_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Kalman_Upward/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Kalman_Upward_DW.HILInitialize_Card,
        &Kalman_Upward_P.HILWriteAnalog_channels, 1,
        &Kalman_Upward_B.Saturation1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
      }
    }

    /* MATLAB Function: '<Root>/MATLAB Function2' */
    /* MATLAB Function 'MATLAB Function2': '<S5>:1' */
    /* '<S5>:1:2' */
    Kalman_Upward_B.y = Kalman_Upward_B.Add[2];

    /* Abs: '<S62>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(Kalman_Upward_B.Switch);

    /* RelationalOperator: '<S62>/Relational Operator1' incorporates:
     *  Constant: '<S62>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      Kalman_Upward_P.StallMonitor_control_threshold);

    /* Abs: '<S62>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(Kalman_Upward_B.Gain);

    /* Logic: '<S62>/Logical Operator' incorporates:
     *  Constant: '<S62>/motion threshold'
     *  RelationalOperator: '<S62>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <=
       Kalman_Upward_P.StallMonitor_motion_threshold));

    /* Logic: '<S62>/Logical Operator1' */
    Kalman_Upward_B.LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    if (Kalman_Upward_B.LogicalOperator1 &&
        (Kalman_Upward_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      Kalman_Upward_DW.DiscreteTimeIntegrator_DSTATE =
        Kalman_Upward_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator = Kalman_Upward_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S62>/Relational Operator2' incorporates:
     *  Constant: '<S62>/control threshold1'
     */
    Kalman_Upward_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
      Kalman_Upward_P.StallMonitor_duration_s);

    /* Stop: '<S63>/Stop Simulation' incorporates:
     *  Constant: '<S64>/Constant'
     *  RelationalOperator: '<S64>/Compare'
     */
    if (Kalman_Upward_B.RelationalOperator2 != Kalman_Upward_P.Constant_Value) {
      rtmSetStopRequested(Kalman_Upward_M, 1);
    }

    /* End of Stop: '<S63>/Stop Simulation' */

    /* DataTypeConversion: '<S62>/Data Type Conversion' */
    Kalman_Upward_B.DataTypeConversion = rtb_RelationalOperator1;

    /* MATLAB Function 'Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn': '<S58>:1' */
    for (i = 0; i <= 0; i += 2) {
      /* Product: '<S28>/A[k]*xhat[k|k-1]' incorporates:
       *  Constant: '<S2>/A'
       */
      _mm_storeu_pd(&rtb_Akxhatkk1[i], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&Kalman_Upward_P.A_Value[i + 6]), _mm_set1_pd(rtb_MemoryX_idx_2)),
        _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&Kalman_Upward_P.A_Value[i + 3]),
        _mm_set1_pd(rtb_MemoryX_idx_1)), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
        (&Kalman_Upward_P.A_Value[i]), _mm_set1_pd(rtb_MemoryX_idx_0)),
        _mm_set1_pd(0.0)))));
    }

    /* Product: '<S28>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S2>/A'
     */
    for (i = 2; i < 3; i++) {
      rtb_Akxhatkk1[i] = (Kalman_Upward_P.A_Value[i + 3] * rtb_MemoryX_idx_1 +
                          Kalman_Upward_P.A_Value[i] * rtb_MemoryX_idx_0) +
        Kalman_Upward_P.A_Value[i + 6] * rtb_MemoryX_idx_2;
    }
  }

  /* Quantizer: '<Root>/Quantizer1' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  Kalman_Upward_B.Quantizer1 = rt_roundd_snf(Kalman_Upward_B.Switch /
    Kalman_Upward_P.ts) * Kalman_Upward_P.ts;
  if (rtmIsMajorTimeStep(Kalman_Upward_M)) {
    /* Outputs for Enabled SubSystem: '<S28>/MeasurementUpdate' incorporates:
     *  EnablePort: '<S59>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&Kalman_Upward_M->solverInfo)) {
      /* Constant: '<S2>/Enable' */
      if (Kalman_Upward_P.Enable_Value) {
        Kalman_Upward_DW.MeasurementUpdate_MODE = true;
      } else if (Kalman_Upward_DW.MeasurementUpdate_MODE) {
        /* Disable for Product: '<S59>/Product3' incorporates:
         *  Outport: '<S59>/L*(y[k]-yhat[k|k-1])'
         */
        Kalman_Upward_B.Product3[0] = Kalman_Upward_P.Lykyhatkk1_Y0;
        Kalman_Upward_B.Product3[1] = Kalman_Upward_P.Lykyhatkk1_Y0;
        Kalman_Upward_B.Product3[2] = Kalman_Upward_P.Lykyhatkk1_Y0;
        Kalman_Upward_DW.MeasurementUpdate_MODE = false;
      }
    }

    if (Kalman_Upward_DW.MeasurementUpdate_MODE) {
      for (i = 0; i <= 0; i += 2) {
        /* Sum: '<S59>/Sum' incorporates:
         *  Constant: '<S2>/C'
         *  Constant: '<S2>/D'
         *  Product: '<S59>/C[k]*xhat[k|k-1]'
         *  ZeroOrderHold: '<Root>/Zero-Order Hold1'
         */
        tmp_1 = _mm_loadu_pd(&rtb_y_n[i]);
        _mm_storeu_pd(&rtb_y_n_0[i], _mm_sub_pd(tmp_1, _mm_add_pd(_mm_mul_pd
          (_mm_loadu_pd(&Kalman_Upward_P.D_Value[i]), _mm_set1_pd
           (Kalman_Upward_B.Quantizer1)), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
          (&Kalman_Upward_P.C_Value[i + 6]), _mm_set1_pd(rtb_MemoryX_idx_2)),
          _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&Kalman_Upward_P.C_Value[i + 3]),
          _mm_set1_pd(rtb_MemoryX_idx_1)), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
          (&Kalman_Upward_P.C_Value[i]), _mm_set1_pd(rtb_MemoryX_idx_0)),
          _mm_set1_pd(0.0)))))));
      }

      for (i = 2; i < 3; i++) {
        /* Sum: '<S59>/Sum' incorporates:
         *  Constant: '<S2>/C'
         *  Constant: '<S2>/D'
         *  Product: '<S59>/C[k]*xhat[k|k-1]'
         *  Product: '<S59>/D[k]*u[k]'
         *  Sum: '<S59>/Add1'
         *  ZeroOrderHold: '<Root>/Zero-Order Hold1'
         */
        rtb_y_n_0[i] = rtb_y_n[i] - (((Kalman_Upward_P.C_Value[i + 3] *
          rtb_MemoryX_idx_1 + Kalman_Upward_P.C_Value[i] * rtb_MemoryX_idx_0) +
          Kalman_Upward_P.C_Value[i + 6] * rtb_MemoryX_idx_2) +
          Kalman_Upward_P.D_Value[i] * Kalman_Upward_B.Quantizer1);
      }

      for (i = 0; i <= 0; i += 2) {
        /* Product: '<S59>/Product3' incorporates:
         *  Constant: '<S8>/KalmanGainL'
         */
        _mm_storeu_pd(&Kalman_Upward_B.Product3[i], _mm_set1_pd(0.0));

        /* Product: '<S59>/Product3' incorporates:
         *  Constant: '<S8>/KalmanGainL'
         */
        tmp_1 = _mm_loadu_pd(&Kalman_Upward_B.Product3[i]);

        /* Product: '<S59>/Product3' incorporates:
         *  Constant: '<S8>/KalmanGainL'
         */
        _mm_storeu_pd(&Kalman_Upward_B.Product3[i], _mm_add_pd(_mm_mul_pd
          (_mm_loadu_pd(&Kalman_Upward_P.KalmanGainL_Value[i]), _mm_set1_pd
           (rtb_y_n_0[0])), tmp_1));

        /* Product: '<S59>/Product3' incorporates:
         *  Constant: '<S8>/KalmanGainL'
         */
        tmp_1 = _mm_loadu_pd(&Kalman_Upward_B.Product3[i]);

        /* Product: '<S59>/Product3' incorporates:
         *  Constant: '<S8>/KalmanGainL'
         */
        _mm_storeu_pd(&Kalman_Upward_B.Product3[i], _mm_add_pd(_mm_mul_pd
          (_mm_loadu_pd(&Kalman_Upward_P.KalmanGainL_Value[i + 3]), _mm_set1_pd
           (rtb_y_n_0[1])), tmp_1));

        /* Product: '<S59>/Product3' incorporates:
         *  Constant: '<S8>/KalmanGainL'
         */
        tmp_1 = _mm_loadu_pd(&Kalman_Upward_B.Product3[i]);

        /* Product: '<S59>/Product3' incorporates:
         *  Constant: '<S8>/KalmanGainL'
         */
        _mm_storeu_pd(&Kalman_Upward_B.Product3[i], _mm_add_pd(_mm_mul_pd
          (_mm_loadu_pd(&Kalman_Upward_P.KalmanGainL_Value[i + 6]), _mm_set1_pd
           (rtb_y_n_0[2])), tmp_1));
      }

      for (i = 2; i < 3; i++) {
        /* Product: '<S59>/Product3' incorporates:
         *  Constant: '<S8>/KalmanGainL'
         */
        Kalman_Upward_B.Product3[i] = 0.0;
        Kalman_Upward_B.Product3[i] += Kalman_Upward_P.KalmanGainL_Value[i] *
          rtb_y_n_0[0];
        Kalman_Upward_B.Product3[i] += Kalman_Upward_P.KalmanGainL_Value[i + 3] *
          rtb_y_n_0[1];
        Kalman_Upward_B.Product3[i] += Kalman_Upward_P.KalmanGainL_Value[i + 6] *
          rtb_y_n_0[2];
      }

      if (rtsiIsModeUpdateTimeStep(&Kalman_Upward_M->solverInfo)) {
        srUpdateBC(Kalman_Upward_DW.MeasurementUpdate_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S28>/MeasurementUpdate' */

    /* Sum: '<S28>/Add' incorporates:
     *  Constant: '<S2>/B'
     *  Product: '<S28>/B[k]*u[k]'
     *  Product: '<S59>/Product3'
     *  ZeroOrderHold: '<Root>/Zero-Order Hold1'
     */
    Kalman_Upward_B.Add_j[0] = (Kalman_Upward_P.B_Value[0] *
      Kalman_Upward_B.Quantizer1 + rtb_Akxhatkk1[0]) + Kalman_Upward_B.Product3
      [0];
    Kalman_Upward_B.Add_j[1] = (Kalman_Upward_P.B_Value[1] *
      Kalman_Upward_B.Quantizer1 + rtb_Akxhatkk1[1]) + Kalman_Upward_B.Product3
      [1];
    Kalman_Upward_B.Add_j[2] = (Kalman_Upward_P.B_Value[2] *
      Kalman_Upward_B.Quantizer1 + rtb_Akxhatkk1[2]) + Kalman_Upward_B.Product3
      [2];

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */
    /* S-Function Block: Kalman_Upward/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * Kalman_Upward_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed =
        (Kalman_Upward_P.SmoothSignalGenerator_Amplitude !=
         Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Amp || w !=
         Kalman_Upward_DW.SmoothSignalGenerator_RWORK.W);

      /*
         Discrete-time:

         y_sin = sin(w*(t + dt)) = sin(w*t)*cos(w*dt) + cos(w*t)*sin(w*dt)
         y_cos = cos(w*(t + dt)) = cos(w*t)*cos(w*dt) - sin(w*t)*sin(w*dt)

         Since dt is fixed and known (the sampling period), we can compute the
         output at the next time step, t + dt, from the previous time step, t,
         simply by applying the formulae above where sin(w*dt) and cos(w*dt) are constant.

         Now, suppose the amplitude or frequency is changed. Then when the current
         value of the output is less than the new amplitude, we need to solve the
         equation:
         1. A1 * y_sin = A2 * sin(x)
         whence:
         x  = asin(A1*y_sin/A2)
         We can then compute a new value of sin(x) and cos(x).
       */
      real_T y_sin = Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos = Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_SmoothSignalGenerator =
        Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Amp * y_sin;

      /* Compute the new sin and cos values */
      Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
        Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
        Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
        Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
        Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

      /*
         If the amplitude or frequency parameter changes, then adjust the
         sine wave parameters such that the sine wave output is continuous.
       */
      if (params_changed) {
        real_T x;

        /*
           Only adjust the amplitude once the current amplitude crosses zero. Otherwise
           we get strange behaviour when continuously modifying the input amplitude and
           frequency using input signals.
         */
        if (y_sin == 0 || Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t ==
            0 || (y_sin < 0) !=
            (Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t < 0)) {
          if (fabs(Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Amp *
                   Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t) <
              Kalman_Upward_P.SmoothSignalGenerator_Amplitude) {
            x = asin(Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Amp *
                     Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t /
                     Kalman_Upward_P.SmoothSignalGenerator_Amplitude);
            Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(w *
              0.0005);
            Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(w *
              0.0005);
            Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0)) {
              Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -cos(x);
            } else {
              Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.0005;
            Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0) {
              Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
            } else {
              Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
            }

            Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(x);
            Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(x);
          }

          Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Amp =
            Kalman_Upward_P.SmoothSignalGenerator_Amplitude;
          Kalman_Upward_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }
  }
}

/* Model update function */
void Kalman_Upward_update(void)
{
  if (rtmIsMajorTimeStep(Kalman_Upward_M)) {
    /* Update for Delay: '<S2>/MemoryX' */
    Kalman_Upward_DW.icLoad = false;
    Kalman_Upward_DW.MemoryX_DSTATE[0] = Kalman_Upward_B.Add_j[0];
    Kalman_Upward_DW.MemoryX_DSTATE[1] = Kalman_Upward_B.Add_j[1];
    Kalman_Upward_DW.MemoryX_DSTATE[2] = Kalman_Upward_B.Add_j[2];

    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    Kalman_Upward_DW.DiscreteTimeIntegrator_DSTATE +=
      Kalman_Upward_P.DiscreteTimeIntegrator_gainval *
      Kalman_Upward_B.DataTypeConversion;
    Kalman_Upward_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      Kalman_Upward_B.LogicalOperator1;
  }

  if (rtmIsMajorTimeStep(Kalman_Upward_M)) {
    rt_ertODEUpdateContinuousStates(&Kalman_Upward_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Kalman_Upward_M->Timing.clockTick0)) {
    ++Kalman_Upward_M->Timing.clockTickH0;
  }

  Kalman_Upward_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Kalman_Upward_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Kalman_Upward_M->Timing.clockTick1)) {
      ++Kalman_Upward_M->Timing.clockTickH1;
    }

    Kalman_Upward_M->Timing.t[1] = Kalman_Upward_M->Timing.clockTick1 *
      Kalman_Upward_M->Timing.stepSize1 + Kalman_Upward_M->Timing.clockTickH1 *
      Kalman_Upward_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Kalman_Upward_derivatives(void)
{
  XDot_Kalman_Upward_T *_rtXdot;
  _rtXdot = ((XDot_Kalman_Upward_T *) Kalman_Upward_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = Kalman_Upward_P.TransferFcn1_A *
    Kalman_Upward_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Kalman_Upward_B.countstorad1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = Kalman_Upward_P.TransferFcn_A *
    Kalman_Upward_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Kalman_Upward_B.Sum;
}

/* Model initialize function */
void Kalman_Upward_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Kalman_Upward/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &Kalman_Upward_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Kalman_Upward_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
      return;
    }

    if ((Kalman_Upward_P.HILInitialize_AIPStart && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Kalman_Upward_DW.HILInitialize_Card,
        &Kalman_Upward_P.HILInitialize_AIChannels, 1U,
        &Kalman_Upward_P.HILInitialize_AILow,
        &Kalman_Upward_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Upward_P.HILInitialize_AOPStart && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Kalman_Upward_DW.HILInitialize_Card,
        &Kalman_Upward_P.HILInitialize_AOChannels, 1U,
        &Kalman_Upward_P.HILInitialize_AOLow,
        &Kalman_Upward_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Upward_P.HILInitialize_AOStart && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Kalman_Upward_DW.HILInitialize_Card,
        &Kalman_Upward_P.HILInitialize_AOChannels, 1U,
        &Kalman_Upward_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }

    if (Kalman_Upward_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Kalman_Upward_DW.HILInitialize_Card,
         &Kalman_Upward_P.HILInitialize_AOChannels, 1U,
         &Kalman_Upward_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Kalman_Upward_DW.HILInitialize_Card,
      NULL, 0U, &Kalman_Upward_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
      return;
    }

    if ((Kalman_Upward_P.HILInitialize_DOStart && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Kalman_Upward_DW.HILInitialize_Card,
        &Kalman_Upward_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Kalman_Upward_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }

    if (Kalman_Upward_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Kalman_Upward_DW.HILInitialize_Card,
         &Kalman_Upward_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &Kalman_Upward_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Upward_P.HILInitialize_EIPStart && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_EIPEnter && is_switching)) {
      Kalman_Upward_DW.HILInitialize_QuadratureModes[0] =
        Kalman_Upward_P.HILInitialize_EIQuadrature;
      Kalman_Upward_DW.HILInitialize_QuadratureModes[1] =
        Kalman_Upward_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Kalman_Upward_DW.HILInitialize_Card,
         Kalman_Upward_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Kalman_Upward_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Upward_P.HILInitialize_EIStart && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_EIEnter && is_switching)) {
      Kalman_Upward_DW.HILInitialize_InitialEICounts[0] =
        Kalman_Upward_P.HILInitialize_EIInitial;
      Kalman_Upward_DW.HILInitialize_InitialEICounts[1] =
        Kalman_Upward_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Kalman_Upward_DW.HILInitialize_Card,
        Kalman_Upward_P.HILInitialize_EIChannels, 2U,
        &Kalman_Upward_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Upward_P.HILInitialize_OOStart && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Kalman_Upward_DW.HILInitialize_Card,
        Kalman_Upward_P.HILInitialize_OOChannels, 3U,
        Kalman_Upward_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }

    if (Kalman_Upward_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Kalman_Upward_DW.HILInitialize_Card,
         Kalman_Upward_P.HILInitialize_OOChannels, 3U,
         Kalman_Upward_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Kalman_Upward/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Kalman_Upward_DW.HILInitialize_Card,
      Kalman_Upward_P.HILReadEncoderTimebase_SamplesI,
      &Kalman_Upward_P.HILReadEncoderTimebase_Channels, 1,
      &Kalman_Upward_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Kalman_Upward_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Kalman_Upward_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
    }
  }

  /* Start for Enabled SubSystem: '<S35>/Enabled Subsystem' */
  Kalman_Upward_DW.EnabledSubsystem_MODE = false;

  /* End of Start for SubSystem: '<S35>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S28>/MeasurementUpdate' */
  Kalman_Upward_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S28>/MeasurementUpdate' */

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */

  /* S-Function Block: Kalman_Upward/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / Kalman_Upward_P.SmoothSignalGenerator_Frequency;
    Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Amp =
      Kalman_Upward_P.SmoothSignalGenerator_Amplitude;
    Kalman_Upward_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      Kalman_Upward_P.SmoothSignalGenerator_Frequency;
    Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (Kalman_Upward_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (Kalman_Upward_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (Kalman_Upward_P.SmoothSignalGenerator_InitialPh);
    Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (Kalman_Upward_P.SmoothSignalGenerator_InitialPh);
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Kalman_Upward_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Kalman_Upward_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Delay: '<S2>/MemoryX' */
  Kalman_Upward_DW.icLoad = true;

  /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
  Kalman_Upward_DW.DiscreteTimeIntegrator_DSTATE =
    Kalman_Upward_P.DiscreteTimeIntegrator_IC;
  Kalman_Upward_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S61>/Product2' incorporates:
   *  Outport: '<S61>/deltax'
   */
  Kalman_Upward_B.Product2[0] = Kalman_Upward_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S28>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S59>/Product3' incorporates:
   *  Outport: '<S59>/L*(y[k]-yhat[k|k-1])'
   */
  Kalman_Upward_B.Product3[0] = Kalman_Upward_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S28>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S61>/Product2' incorporates:
   *  Outport: '<S61>/deltax'
   */
  Kalman_Upward_B.Product2[1] = Kalman_Upward_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S28>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S59>/Product3' incorporates:
   *  Outport: '<S59>/L*(y[k]-yhat[k|k-1])'
   */
  Kalman_Upward_B.Product3[1] = Kalman_Upward_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S28>/MeasurementUpdate' */

  /* SystemInitialize for Enabled SubSystem: '<S35>/Enabled Subsystem' */
  /* SystemInitialize for Product: '<S61>/Product2' incorporates:
   *  Outport: '<S61>/deltax'
   */
  Kalman_Upward_B.Product2[2] = Kalman_Upward_P.deltax_Y0;

  /* End of SystemInitialize for SubSystem: '<S35>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S28>/MeasurementUpdate' */
  /* SystemInitialize for Product: '<S59>/Product3' incorporates:
   *  Outport: '<S59>/L*(y[k]-yhat[k|k-1])'
   */
  Kalman_Upward_B.Product3[2] = Kalman_Upward_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S28>/MeasurementUpdate' */
}

/* Model terminate function */
void Kalman_Upward_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Kalman_Upward/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Kalman_Upward_DW.HILInitialize_Card);
    hil_monitor_stop_all(Kalman_Upward_DW.HILInitialize_Card);
    is_switching = false;
    if ((Kalman_Upward_P.HILInitialize_AOTerminate && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Kalman_Upward_P.HILInitialize_DOTerminate && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Kalman_Upward_P.HILInitialize_OOTerminate && !is_switching) ||
        (Kalman_Upward_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    } else {
      num_final_other_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Kalman_Upward_DW.HILInitialize_Card
                         , &Kalman_Upward_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Kalman_Upward_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Kalman_Upward_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Kalman_Upward_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Kalman_Upward_P.HILInitialize_DOFinal
                         , Kalman_Upward_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Kalman_Upward_DW.HILInitialize_Card,
            &Kalman_Upward_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Kalman_Upward_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Kalman_Upward_DW.HILInitialize_Card,
            &Kalman_Upward_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Kalman_Upward_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Kalman_Upward_DW.HILInitialize_Card,
            Kalman_Upward_P.HILInitialize_OOChannels, num_final_other_outputs,
            Kalman_Upward_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Kalman_Upward_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Kalman_Upward_DW.HILInitialize_Card);
    hil_monitor_delete_all(Kalman_Upward_DW.HILInitialize_Card);
    hil_close(Kalman_Upward_DW.HILInitialize_Card);
    Kalman_Upward_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Kalman_Upward_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Kalman_Upward_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Kalman_Upward_initialize();
}

void MdlTerminate(void)
{
  Kalman_Upward_terminate();
}

/* Registration function */
RT_MODEL_Kalman_Upward_T *Kalman_Upward(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Kalman_Upward_M, 0,
                sizeof(RT_MODEL_Kalman_Upward_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Kalman_Upward_M->solverInfo,
                          &Kalman_Upward_M->Timing.simTimeStep);
    rtsiSetTPtr(&Kalman_Upward_M->solverInfo, &rtmGetTPtr(Kalman_Upward_M));
    rtsiSetStepSizePtr(&Kalman_Upward_M->solverInfo,
                       &Kalman_Upward_M->Timing.stepSize0);
    rtsiSetdXPtr(&Kalman_Upward_M->solverInfo, &Kalman_Upward_M->derivs);
    rtsiSetContStatesPtr(&Kalman_Upward_M->solverInfo, (real_T **)
                         &Kalman_Upward_M->contStates);
    rtsiSetNumContStatesPtr(&Kalman_Upward_M->solverInfo,
      &Kalman_Upward_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Kalman_Upward_M->solverInfo,
      &Kalman_Upward_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Kalman_Upward_M->solverInfo,
      &Kalman_Upward_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Kalman_Upward_M->solverInfo,
      &Kalman_Upward_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Kalman_Upward_M->solverInfo, (&rtmGetErrorStatus
      (Kalman_Upward_M)));
    rtsiSetRTModelPtr(&Kalman_Upward_M->solverInfo, Kalman_Upward_M);
  }

  rtsiSetSimTimeStep(&Kalman_Upward_M->solverInfo, MAJOR_TIME_STEP);
  Kalman_Upward_M->intgData.f[0] = Kalman_Upward_M->odeF[0];
  Kalman_Upward_M->contStates = ((real_T *) &Kalman_Upward_X);
  rtsiSetSolverData(&Kalman_Upward_M->solverInfo, (void *)
                    &Kalman_Upward_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Kalman_Upward_M->solverInfo, false);
  rtsiSetSolverName(&Kalman_Upward_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Kalman_Upward_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Kalman_Upward_M points to
       static memory which is guaranteed to be non-NULL" */
    Kalman_Upward_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Kalman_Upward_M->Timing.sampleTimes =
      (&Kalman_Upward_M->Timing.sampleTimesArray[0]);
    Kalman_Upward_M->Timing.offsetTimes =
      (&Kalman_Upward_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Kalman_Upward_M->Timing.sampleTimes[0] = (0.0);
    Kalman_Upward_M->Timing.sampleTimes[1] = (0.0005);

    /* task offsets */
    Kalman_Upward_M->Timing.offsetTimes[0] = (0.0);
    Kalman_Upward_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Kalman_Upward_M, &Kalman_Upward_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Kalman_Upward_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Kalman_Upward_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Kalman_Upward_M, -1);
  Kalman_Upward_M->Timing.stepSize0 = 0.0005;
  Kalman_Upward_M->Timing.stepSize1 = 0.0005;

  /* External mode info */
  Kalman_Upward_M->Sizes.checksums[0] = (3416835456U);
  Kalman_Upward_M->Sizes.checksums[1] = (1048431882U);
  Kalman_Upward_M->Sizes.checksums[2] = (2374279873U);
  Kalman_Upward_M->Sizes.checksums[3] = (1756012103U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    Kalman_Upward_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &Kalman_Upward_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&Kalman_Upward_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Kalman_Upward_M->extModeInfo,
      &Kalman_Upward_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Kalman_Upward_M->extModeInfo,
                        Kalman_Upward_M->Sizes.checksums);
    rteiSetTPtr(Kalman_Upward_M->extModeInfo, rtmGetTPtr(Kalman_Upward_M));
  }

  Kalman_Upward_M->solverInfoPtr = (&Kalman_Upward_M->solverInfo);
  Kalman_Upward_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&Kalman_Upward_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&Kalman_Upward_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Kalman_Upward_M->blockIO = ((void *) &Kalman_Upward_B);
  (void) memset(((void *) &Kalman_Upward_B), 0,
                sizeof(B_Kalman_Upward_T));

  {
    Kalman_Upward_B.countstorad1 = 0.0;
    Kalman_Upward_B.Gain = 0.0;
    Kalman_Upward_B.Gain1 = 0.0;
    Kalman_Upward_B.countstorad = 0.0;
    Kalman_Upward_B.Sum = 0.0;
    Kalman_Upward_B.Quantizer[0] = 0.0;
    Kalman_Upward_B.Quantizer[1] = 0.0;
    Kalman_Upward_B.Quantizer[2] = 0.0;
    Kalman_Upward_B.Quantizer[3] = 0.0;
    Kalman_Upward_B.Add[0] = 0.0;
    Kalman_Upward_B.Add[1] = 0.0;
    Kalman_Upward_B.Add[2] = 0.0;
    Kalman_Upward_B.Gain1_d = 0.0;
    Kalman_Upward_B.Add_e = 0.0;
    Kalman_Upward_B.Saturation = 0.0;
    Kalman_Upward_B.Switch = 0.0;
    Kalman_Upward_B.Saturation1 = 0.0;
    Kalman_Upward_B.DataTypeConversion = 0.0;
    Kalman_Upward_B.Quantizer1 = 0.0;
    Kalman_Upward_B.Add_j[0] = 0.0;
    Kalman_Upward_B.Add_j[1] = 0.0;
    Kalman_Upward_B.Add_j[2] = 0.0;
    Kalman_Upward_B.y = 0.0;
    Kalman_Upward_B.Product2[0] = 0.0;
    Kalman_Upward_B.Product2[1] = 0.0;
    Kalman_Upward_B.Product2[2] = 0.0;
    Kalman_Upward_B.Product3[0] = 0.0;
    Kalman_Upward_B.Product3[1] = 0.0;
    Kalman_Upward_B.Product3[2] = 0.0;
  }

  /* parameters */
  Kalman_Upward_M->defaultParam = ((real_T *)&Kalman_Upward_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Kalman_Upward_X;
    Kalman_Upward_M->contStates = (x);
    (void) memset((void *)&Kalman_Upward_X, 0,
                  sizeof(X_Kalman_Upward_T));
  }

  /* states (dwork) */
  Kalman_Upward_M->dwork = ((void *) &Kalman_Upward_DW);
  (void) memset((void *)&Kalman_Upward_DW, 0,
                sizeof(DW_Kalman_Upward_T));
  Kalman_Upward_DW.MemoryX_DSTATE[0] = 0.0;
  Kalman_Upward_DW.MemoryX_DSTATE[1] = 0.0;
  Kalman_Upward_DW.MemoryX_DSTATE[2] = 0.0;
  Kalman_Upward_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  Kalman_Upward_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Kalman_Upward_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Amp = 0.0;
  Kalman_Upward_DW.SmoothSignalGenerator_RWORK.W = 0.0;
  Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = 0.0;
  Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = 0.0;
  Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0.0;
  Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Cos_w_t = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Kalman_Upward_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Kalman_Upward_M->Sizes.numContStates = (2);/* Number of continuous states */
  Kalman_Upward_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Kalman_Upward_M->Sizes.numY = (0);   /* Number of model outputs */
  Kalman_Upward_M->Sizes.numU = (0);   /* Number of model inputs */
  Kalman_Upward_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Kalman_Upward_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Kalman_Upward_M->Sizes.numBlocks = (97);/* Number of blocks */
  Kalman_Upward_M->Sizes.numBlockIO = (20);/* Number of block outputs */
  Kalman_Upward_M->Sizes.numBlockPrms = (175);/* Sum of parameter "widths" */
  return Kalman_Upward_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
