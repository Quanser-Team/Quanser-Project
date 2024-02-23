/*
 * Swingup_energy.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Swingup_energy".
 *
 * Model version              : 9.23
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Dec 14 17:36:20 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Swingup_energy.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Swingup_energy_private.h"
#include <string.h>
#include "Swingup_energy_dt.h"

/* Block signals (default storage) */
B_Swingup_energy_T Swingup_energy_B;

/* Continuous states */
X_Swingup_energy_T Swingup_energy_X;

/* Block states (default storage) */
DW_Swingup_energy_T Swingup_energy_DW;

/* Real-time model */
static RT_MODEL_Swingup_energy_T Swingup_energy_M_;
RT_MODEL_Swingup_energy_T *const Swingup_energy_M = &Swingup_energy_M_;

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
  Swingup_energy_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Swingup_energy_output(void)
{
  /* local block i/o variables */
  real_T rtb_SmoothSignalGenerator;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_countstorad;
  real_T u;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(Swingup_energy_M)) {
    /* set solver stop time */
    if (!(Swingup_energy_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Swingup_energy_M->solverInfo,
                            ((Swingup_energy_M->Timing.clockTickH0 + 1) *
        Swingup_energy_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Swingup_energy_M->solverInfo,
                            ((Swingup_energy_M->Timing.clockTick0 + 1) *
        Swingup_energy_M->Timing.stepSize0 +
        Swingup_energy_M->Timing.clockTickH0 *
        Swingup_energy_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Swingup_energy_M)) {
    Swingup_energy_M->Timing.t[0] = rtsiGetT(&Swingup_energy_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Swingup_energy_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: Swingup_energy/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (Swingup_energy_DW.HILReadEncoderTimebase_Task, 1,
         &Swingup_energy_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        rtb_countstorad = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
      } else {
        rtb_countstorad = Swingup_energy_DW.HILReadEncoderTimebase_Buffer;
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: Swingup_energy/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Swingup_energy_DW.HILInitialize_Card,
        &Swingup_energy_P.HILReadEncoder_channels, 1,
        &Swingup_energy_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
      } else {
        rtb_DiscreteTimeIntegrator = Swingup_energy_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/counts to rad1' */
    Swingup_energy_B.countstorad1 = Swingup_energy_P.countstorad1_Gain *
      rtb_DiscreteTimeIntegrator;

    /* Gain: '<Root>/counts to rad' */
    rtb_countstorad *= Swingup_energy_P.countstorad_Gain;

    /* Sum: '<Root>/Add1' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Swingup_energy_B.Add1 = rtb_countstorad - Swingup_energy_P.Constant3_Value;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn1'
   */
  Swingup_energy_B.Gain = (Swingup_energy_P.TransferFcn1_C *
    Swingup_energy_X.TransferFcn1_CSTATE + Swingup_energy_P.TransferFcn1_D *
    Swingup_energy_B.countstorad1) * Swingup_energy_P.Gain_Gain;

  /* Gain: '<Root>/Gain1' */
  Swingup_energy_B.Gain1 = Swingup_energy_P.Gain1_Gain * Swingup_energy_B.Gain;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  Swingup_energy_B.VectorConcatenate[0] = Swingup_energy_B.Gain1;

  /* TransferFcn: '<Root>/Transfer Fcn' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  Swingup_energy_B.VectorConcatenate[1] = Swingup_energy_P.TransferFcn_C *
    Swingup_energy_X.TransferFcn_CSTATE;
  Swingup_energy_B.VectorConcatenate[1] += Swingup_energy_P.TransferFcn_D *
    Swingup_energy_B.Add1;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  Swingup_energy_B.VectorConcatenate[2] = Swingup_energy_B.countstorad1;
  if (rtmIsMajorTimeStep(Swingup_energy_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
     *  Concatenate: '<Root>/Vector Concatenate'
     */
    /* MATLAB Function 'MATLAB Function3': '<S5>:1' */
    if (Swingup_energy_B.Add1 < -4.71238898038469) {
      /* '<S5>:1:3' */
      /* '<S5>:1:4' */
      Swingup_energy_B.VectorConcatenate[3] = Swingup_energy_B.Add1 +
        6.2831853071795862;
    } else {
      /* '<S5>:1:6' */
      Swingup_energy_B.VectorConcatenate[3] = Swingup_energy_B.Add1;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function3' */

    /* Gain: '<S1>/Gain1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    Swingup_energy_B.Gain1_d = Swingup_energy_P.Gain1_Gain_a *
      Swingup_energy_P.Constant2_Value;
  }

  /* Sum: '<Root>/Add' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   *  Constant: '<Root>/Constant'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  /* MATLAB Function 'MATLAB Function': '<S2>:1' */
  /* '<S2>:1:4' */
  Swingup_energy_B.Add = Swingup_energy_B.Gain1_d - (((Swingup_energy_P.K_pp[0] *
    Swingup_energy_B.VectorConcatenate[0] + Swingup_energy_P.K_pp[1] *
    Swingup_energy_B.VectorConcatenate[1]) + Swingup_energy_P.K_pp[2] *
    Swingup_energy_B.VectorConcatenate[2]) + Swingup_energy_P.K_pp[3] *
    Swingup_energy_B.VectorConcatenate[3]);

  /* Saturate: '<Root>/Saturation' */
  if (Swingup_energy_B.Add > Swingup_energy_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    Swingup_energy_B.Saturation = Swingup_energy_P.Saturation_UpperSat;
  } else if (Swingup_energy_B.Add < Swingup_energy_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    Swingup_energy_B.Saturation = Swingup_energy_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    Swingup_energy_B.Saturation = Swingup_energy_B.Add;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(Swingup_energy_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function2' */
    Swingup_energy_B.y = Swingup_energy_B.Add1;

    /* MATLAB Function 'MATLAB Function2': '<S4>:1' */
    /* '<S4>:1:3' */
    Swingup_energy_B.y = cos(Swingup_energy_B.y);
  }

  /* Switch: '<Root>/Switch' */
  /* MATLAB Function 'MATLAB Function1': '<S3>:1' */
  /* '<S3>:1:4' */
  /* '<S3>:1:7' */
  /* '<S3>:1:19' */
  /* '<S3>:1:21' */
  /* '<S3>:1:24' */
  /* '<S3>:1:25' */
  /* '<S3>:1:27' */
  if (Swingup_energy_B.y >= Swingup_energy_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' */
    Swingup_energy_B.Switch = Swingup_energy_B.Saturation;
  } else {
    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Concatenate: '<Root>/Vector Concatenate'
     */
    rtb_DiscreteTimeIntegrator = cos(Swingup_energy_B.VectorConcatenate[3]);
    u = Swingup_energy_B.VectorConcatenate[1] * rtb_DiscreteTimeIntegrator;
    if (rtIsNaN(u)) {
      u = (rtNaN);
    } else if (u < 0.0) {
      u = -1.0;
    } else {
      u = (u > 0.0);
    }

    rtb_DiscreteTimeIntegrator = ((Swingup_energy_B.VectorConcatenate[1] *
      Swingup_energy_B.VectorConcatenate[1] * 1.66048996E-5 +
      0.015169399200000003 * rtb_DiscreteTimeIntegrator) - 0.015169399200000003)
      * 100.0 * u;

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* Saturate: '<Root>/Saturation2' */
    if (rtb_DiscreteTimeIntegrator > Swingup_energy_P.Saturation2_UpperSat) {
      /* Switch: '<Root>/Switch' */
      Swingup_energy_B.Switch = Swingup_energy_P.Saturation2_UpperSat;
    } else if (rtb_DiscreteTimeIntegrator <
               Swingup_energy_P.Saturation2_LowerSat) {
      /* Switch: '<Root>/Switch' */
      Swingup_energy_B.Switch = Swingup_energy_P.Saturation2_LowerSat;
    } else {
      /* Switch: '<Root>/Switch' */
      Swingup_energy_B.Switch = rtb_DiscreteTimeIntegrator;
    }

    /* End of Saturate: '<Root>/Saturation2' */
  }

  /* End of Switch: '<Root>/Switch' */

  /* Saturate: '<Root>/Saturation1' */
  if (Swingup_energy_B.Switch > Swingup_energy_P.Saturation1_UpperSat) {
    /* Saturate: '<Root>/Saturation1' */
    Swingup_energy_B.Saturation1 = Swingup_energy_P.Saturation1_UpperSat;
  } else if (Swingup_energy_B.Switch < Swingup_energy_P.Saturation1_LowerSat) {
    /* Saturate: '<Root>/Saturation1' */
    Swingup_energy_B.Saturation1 = Swingup_energy_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation1' */
    Swingup_energy_B.Saturation1 = Swingup_energy_B.Switch;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(Swingup_energy_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Swingup_energy/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Swingup_energy_DW.HILInitialize_Card,
        &Swingup_energy_P.HILWriteAnalog_channels, 1,
        &Swingup_energy_B.Saturation1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
      }
    }

    /* Gain: '<S7>/Gain' */
    Swingup_energy_B.Gain_n = Swingup_energy_P.Gain_Gain_k *
      Swingup_energy_B.countstorad1;

    /* Gain: '<S6>/Gain' */
    Swingup_energy_B.Gain_f[0] = Swingup_energy_P.Gain_Gain_a *
      Swingup_energy_B.Gain1_d;
    Swingup_energy_B.Gain_f[1] = Swingup_energy_P.Gain_Gain_a * rtb_countstorad;

    /* Abs: '<S9>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(Swingup_energy_B.Switch);

    /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
     *  Constant: '<S9>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      Swingup_energy_P.StallMonitor_control_threshold);

    /* Abs: '<S9>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(Swingup_energy_B.Gain);

    /* Logic: '<S9>/Logical Operator' incorporates:
     *  Constant: '<S9>/motion threshold'
     *  RelationalOperator: '<S9>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <=
       Swingup_energy_P.StallMonitor_motion_threshold));

    /* Logic: '<S9>/Logical Operator1' */
    Swingup_energy_B.LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    if (Swingup_energy_B.LogicalOperator1 &&
        (Swingup_energy_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      Swingup_energy_DW.DiscreteTimeIntegrator_DSTATE =
        Swingup_energy_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator = Swingup_energy_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S9>/Relational Operator2' incorporates:
     *  Constant: '<S9>/control threshold1'
     */
    Swingup_energy_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
      Swingup_energy_P.StallMonitor_duration_s);

    /* Stop: '<S10>/Stop Simulation' incorporates:
     *  Constant: '<S11>/Constant'
     *  RelationalOperator: '<S11>/Compare'
     */
    if (Swingup_energy_B.RelationalOperator2 != Swingup_energy_P.Constant_Value)
    {
      rtmSetStopRequested(Swingup_energy_M, 1);
    }

    /* End of Stop: '<S10>/Stop Simulation' */

    /* DataTypeConversion: '<S9>/Data Type Conversion' */
    Swingup_energy_B.DataTypeConversion = rtb_RelationalOperator1;

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */
    /* S-Function Block: Swingup_energy/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * Swingup_energy_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed =
        (Swingup_energy_P.SmoothSignalGenerator_Amplitude !=
         Swingup_energy_DW.SmoothSignalGenerator_RWORK.Amp || w !=
         Swingup_energy_DW.SmoothSignalGenerator_RWORK.W);

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
      real_T y_sin = Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos = Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_SmoothSignalGenerator =
        Swingup_energy_DW.SmoothSignalGenerator_RWORK.Amp * y_sin;

      /* Compute the new sin and cos values */
      Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
        Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
        Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
        Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
        Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

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
        if (y_sin == 0 || Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t ==
            0 || (y_sin < 0) !=
            (Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t < 0)) {
          if (fabs(Swingup_energy_DW.SmoothSignalGenerator_RWORK.Amp *
                   Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t) <
              Swingup_energy_P.SmoothSignalGenerator_Amplitude) {
            x = asin(Swingup_energy_DW.SmoothSignalGenerator_RWORK.Amp *
                     Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t /
                     Swingup_energy_P.SmoothSignalGenerator_Amplitude);
            Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(w *
              0.0005);
            Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(w *
              0.0005);
            Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0)) {
              Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -cos(x);
            } else {
              Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.0005;
            Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0) {
              Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
            } else {
              Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
            }

            Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(x);
            Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(x);
          }

          Swingup_energy_DW.SmoothSignalGenerator_RWORK.Amp =
            Swingup_energy_P.SmoothSignalGenerator_Amplitude;
          Swingup_energy_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }
  }
}

/* Model update function */
void Swingup_energy_update(void)
{
  if (rtmIsMajorTimeStep(Swingup_energy_M)) {
    /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
    Swingup_energy_DW.DiscreteTimeIntegrator_DSTATE +=
      Swingup_energy_P.DiscreteTimeIntegrator_gainval *
      Swingup_energy_B.DataTypeConversion;
    Swingup_energy_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      Swingup_energy_B.LogicalOperator1;
  }

  if (rtmIsMajorTimeStep(Swingup_energy_M)) {
    rt_ertODEUpdateContinuousStates(&Swingup_energy_M->solverInfo);
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
  if (!(++Swingup_energy_M->Timing.clockTick0)) {
    ++Swingup_energy_M->Timing.clockTickH0;
  }

  Swingup_energy_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Swingup_energy_M->solverInfo);

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
    if (!(++Swingup_energy_M->Timing.clockTick1)) {
      ++Swingup_energy_M->Timing.clockTickH1;
    }

    Swingup_energy_M->Timing.t[1] = Swingup_energy_M->Timing.clockTick1 *
      Swingup_energy_M->Timing.stepSize1 + Swingup_energy_M->Timing.clockTickH1 *
      Swingup_energy_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Swingup_energy_derivatives(void)
{
  XDot_Swingup_energy_T *_rtXdot;
  _rtXdot = ((XDot_Swingup_energy_T *) Swingup_energy_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = Swingup_energy_P.TransferFcn1_A *
    Swingup_energy_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Swingup_energy_B.countstorad1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = Swingup_energy_P.TransferFcn_A *
    Swingup_energy_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Swingup_energy_B.Add1;
}

/* Model initialize function */
void Swingup_energy_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Swingup_energy/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &Swingup_energy_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Swingup_energy_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
      return;
    }

    if ((Swingup_energy_P.HILInitialize_AIPStart && !is_switching) ||
        (Swingup_energy_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Swingup_energy_DW.HILInitialize_Card,
        &Swingup_energy_P.HILInitialize_AIChannels, 1U,
        &Swingup_energy_P.HILInitialize_AILow,
        &Swingup_energy_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_energy_P.HILInitialize_AOPStart && !is_switching) ||
        (Swingup_energy_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Swingup_energy_DW.HILInitialize_Card,
        &Swingup_energy_P.HILInitialize_AOChannels, 1U,
        &Swingup_energy_P.HILInitialize_AOLow,
        &Swingup_energy_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_energy_P.HILInitialize_AOStart && !is_switching) ||
        (Swingup_energy_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Swingup_energy_DW.HILInitialize_Card,
        &Swingup_energy_P.HILInitialize_AOChannels, 1U,
        &Swingup_energy_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }

    if (Swingup_energy_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Swingup_energy_DW.HILInitialize_Card,
         &Swingup_energy_P.HILInitialize_AOChannels, 1U,
         &Swingup_energy_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Swingup_energy_DW.HILInitialize_Card,
      NULL, 0U, &Swingup_energy_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
      return;
    }

    if ((Swingup_energy_P.HILInitialize_DOStart && !is_switching) ||
        (Swingup_energy_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Swingup_energy_DW.HILInitialize_Card,
        &Swingup_energy_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Swingup_energy_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }

    if (Swingup_energy_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Swingup_energy_DW.HILInitialize_Card,
         &Swingup_energy_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &Swingup_energy_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_energy_P.HILInitialize_EIPStart && !is_switching) ||
        (Swingup_energy_P.HILInitialize_EIPEnter && is_switching)) {
      Swingup_energy_DW.HILInitialize_QuadratureModes[0] =
        Swingup_energy_P.HILInitialize_EIQuadrature;
      Swingup_energy_DW.HILInitialize_QuadratureModes[1] =
        Swingup_energy_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Swingup_energy_DW.HILInitialize_Card,
         Swingup_energy_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Swingup_energy_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_energy_P.HILInitialize_EIStart && !is_switching) ||
        (Swingup_energy_P.HILInitialize_EIEnter && is_switching)) {
      Swingup_energy_DW.HILInitialize_InitialEICounts[0] =
        Swingup_energy_P.HILInitialize_EIInitial;
      Swingup_energy_DW.HILInitialize_InitialEICounts[1] =
        Swingup_energy_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Swingup_energy_DW.HILInitialize_Card,
        Swingup_energy_P.HILInitialize_EIChannels, 2U,
        &Swingup_energy_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_energy_P.HILInitialize_OOStart && !is_switching) ||
        (Swingup_energy_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Swingup_energy_DW.HILInitialize_Card,
        Swingup_energy_P.HILInitialize_OOChannels, 3U,
        Swingup_energy_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }

    if (Swingup_energy_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Swingup_energy_DW.HILInitialize_Card,
         Swingup_energy_P.HILInitialize_OOChannels, 3U,
         Swingup_energy_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Swingup_energy/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Swingup_energy_DW.HILInitialize_Card,
      Swingup_energy_P.HILReadEncoderTimebase_SamplesI,
      &Swingup_energy_P.HILReadEncoderTimebase_Channels, 1,
      &Swingup_energy_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Swingup_energy_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Swingup_energy_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */

  /* S-Function Block: Swingup_energy/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / Swingup_energy_P.SmoothSignalGenerator_Frequency;
    Swingup_energy_DW.SmoothSignalGenerator_RWORK.Amp =
      Swingup_energy_P.SmoothSignalGenerator_Amplitude;
    Swingup_energy_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      Swingup_energy_P.SmoothSignalGenerator_Frequency;
    Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (Swingup_energy_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (Swingup_energy_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (Swingup_energy_P.SmoothSignalGenerator_InitialPh);
    Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (Swingup_energy_P.SmoothSignalGenerator_InitialPh);
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Swingup_energy_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Swingup_energy_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator' */
  Swingup_energy_DW.DiscreteTimeIntegrator_DSTATE =
    Swingup_energy_P.DiscreteTimeIntegrator_IC;
  Swingup_energy_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void Swingup_energy_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Swingup_energy/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Swingup_energy_DW.HILInitialize_Card);
    hil_monitor_stop_all(Swingup_energy_DW.HILInitialize_Card);
    is_switching = false;
    if ((Swingup_energy_P.HILInitialize_AOTerminate && !is_switching) ||
        (Swingup_energy_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Swingup_energy_P.HILInitialize_DOTerminate && !is_switching) ||
        (Swingup_energy_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Swingup_energy_P.HILInitialize_OOTerminate && !is_switching) ||
        (Swingup_energy_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Swingup_energy_DW.HILInitialize_Card
                         , &Swingup_energy_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Swingup_energy_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Swingup_energy_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Swingup_energy_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Swingup_energy_P.HILInitialize_DOFinal
                         , Swingup_energy_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Swingup_energy_DW.HILInitialize_Card,
            &Swingup_energy_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Swingup_energy_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Swingup_energy_DW.HILInitialize_Card,
            &Swingup_energy_P.HILInitialize_DOChannels,
            num_final_digital_outputs, (t_boolean *)
            &Swingup_energy_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Swingup_energy_DW.HILInitialize_Card,
            Swingup_energy_P.HILInitialize_OOChannels, num_final_other_outputs,
            Swingup_energy_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Swingup_energy_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Swingup_energy_DW.HILInitialize_Card);
    hil_monitor_delete_all(Swingup_energy_DW.HILInitialize_Card);
    hil_close(Swingup_energy_DW.HILInitialize_Card);
    Swingup_energy_DW.HILInitialize_Card = NULL;
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
  Swingup_energy_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Swingup_energy_update();
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
  Swingup_energy_initialize();
}

void MdlTerminate(void)
{
  Swingup_energy_terminate();
}

/* Registration function */
RT_MODEL_Swingup_energy_T *Swingup_energy(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Swingup_energy_M, 0,
                sizeof(RT_MODEL_Swingup_energy_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Swingup_energy_M->solverInfo,
                          &Swingup_energy_M->Timing.simTimeStep);
    rtsiSetTPtr(&Swingup_energy_M->solverInfo, &rtmGetTPtr(Swingup_energy_M));
    rtsiSetStepSizePtr(&Swingup_energy_M->solverInfo,
                       &Swingup_energy_M->Timing.stepSize0);
    rtsiSetdXPtr(&Swingup_energy_M->solverInfo, &Swingup_energy_M->derivs);
    rtsiSetContStatesPtr(&Swingup_energy_M->solverInfo, (real_T **)
                         &Swingup_energy_M->contStates);
    rtsiSetNumContStatesPtr(&Swingup_energy_M->solverInfo,
      &Swingup_energy_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Swingup_energy_M->solverInfo,
      &Swingup_energy_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Swingup_energy_M->solverInfo,
      &Swingup_energy_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Swingup_energy_M->solverInfo,
      &Swingup_energy_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Swingup_energy_M->solverInfo, (&rtmGetErrorStatus
      (Swingup_energy_M)));
    rtsiSetRTModelPtr(&Swingup_energy_M->solverInfo, Swingup_energy_M);
  }

  rtsiSetSimTimeStep(&Swingup_energy_M->solverInfo, MAJOR_TIME_STEP);
  Swingup_energy_M->intgData.f[0] = Swingup_energy_M->odeF[0];
  Swingup_energy_M->contStates = ((real_T *) &Swingup_energy_X);
  rtsiSetSolverData(&Swingup_energy_M->solverInfo, (void *)
                    &Swingup_energy_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Swingup_energy_M->solverInfo, false);
  rtsiSetSolverName(&Swingup_energy_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Swingup_energy_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Swingup_energy_M points to
       static memory which is guaranteed to be non-NULL" */
    Swingup_energy_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Swingup_energy_M->Timing.sampleTimes =
      (&Swingup_energy_M->Timing.sampleTimesArray[0]);
    Swingup_energy_M->Timing.offsetTimes =
      (&Swingup_energy_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Swingup_energy_M->Timing.sampleTimes[0] = (0.0);
    Swingup_energy_M->Timing.sampleTimes[1] = (0.0005);

    /* task offsets */
    Swingup_energy_M->Timing.offsetTimes[0] = (0.0);
    Swingup_energy_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Swingup_energy_M, &Swingup_energy_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Swingup_energy_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Swingup_energy_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Swingup_energy_M, -1);
  Swingup_energy_M->Timing.stepSize0 = 0.0005;
  Swingup_energy_M->Timing.stepSize1 = 0.0005;

  /* External mode info */
  Swingup_energy_M->Sizes.checksums[0] = (2726450178U);
  Swingup_energy_M->Sizes.checksums[1] = (3773360446U);
  Swingup_energy_M->Sizes.checksums[2] = (2399443072U);
  Swingup_energy_M->Sizes.checksums[3] = (4151263181U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Swingup_energy_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Swingup_energy_M->extModeInfo,
      &Swingup_energy_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Swingup_energy_M->extModeInfo,
                        Swingup_energy_M->Sizes.checksums);
    rteiSetTPtr(Swingup_energy_M->extModeInfo, rtmGetTPtr(Swingup_energy_M));
  }

  Swingup_energy_M->solverInfoPtr = (&Swingup_energy_M->solverInfo);
  Swingup_energy_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&Swingup_energy_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&Swingup_energy_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Swingup_energy_M->blockIO = ((void *) &Swingup_energy_B);
  (void) memset(((void *) &Swingup_energy_B), 0,
                sizeof(B_Swingup_energy_T));

  {
    Swingup_energy_B.countstorad1 = 0.0;
    Swingup_energy_B.Gain = 0.0;
    Swingup_energy_B.Gain1 = 0.0;
    Swingup_energy_B.Add1 = 0.0;
    Swingup_energy_B.VectorConcatenate[0] = 0.0;
    Swingup_energy_B.VectorConcatenate[1] = 0.0;
    Swingup_energy_B.VectorConcatenate[2] = 0.0;
    Swingup_energy_B.VectorConcatenate[3] = 0.0;
    Swingup_energy_B.Gain1_d = 0.0;
    Swingup_energy_B.Add = 0.0;
    Swingup_energy_B.Saturation = 0.0;
    Swingup_energy_B.Switch = 0.0;
    Swingup_energy_B.Saturation1 = 0.0;
    Swingup_energy_B.Gain_n = 0.0;
    Swingup_energy_B.Gain_f[0] = 0.0;
    Swingup_energy_B.Gain_f[1] = 0.0;
    Swingup_energy_B.DataTypeConversion = 0.0;
    Swingup_energy_B.y = 0.0;
  }

  /* parameters */
  Swingup_energy_M->defaultParam = ((real_T *)&Swingup_energy_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Swingup_energy_X;
    Swingup_energy_M->contStates = (x);
    (void) memset((void *)&Swingup_energy_X, 0,
                  sizeof(X_Swingup_energy_T));
  }

  /* states (dwork) */
  Swingup_energy_M->dwork = ((void *) &Swingup_energy_DW);
  (void) memset((void *)&Swingup_energy_DW, 0,
                sizeof(DW_Swingup_energy_T));
  Swingup_energy_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  Swingup_energy_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Swingup_energy_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Swingup_energy_DW.SmoothSignalGenerator_RWORK.Amp = 0.0;
  Swingup_energy_DW.SmoothSignalGenerator_RWORK.W = 0.0;
  Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = 0.0;
  Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = 0.0;
  Swingup_energy_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0.0;
  Swingup_energy_DW.SmoothSignalGenerator_RWORK.Cos_w_t = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Swingup_energy_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Swingup_energy_M->Sizes.numContStates = (2);/* Number of continuous states */
  Swingup_energy_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Swingup_energy_M->Sizes.numY = (0);  /* Number of model outputs */
  Swingup_energy_M->Sizes.numU = (0);  /* Number of model inputs */
  Swingup_energy_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Swingup_energy_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Swingup_energy_M->Sizes.numBlocks = (59);/* Number of blocks */
  Swingup_energy_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  Swingup_energy_M->Sizes.numBlockPrms = (112);/* Sum of parameter "widths" */
  return Swingup_energy_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
