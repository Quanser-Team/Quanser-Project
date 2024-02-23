/*
 * Swingup_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Swingup_test".
 *
 * Model version              : 9.22
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Dec  5 15:31:44 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Swingup_test.h"
#include "rtwtypes.h"
#include <math.h>
#include "Swingup_test_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Swingup_test_dt.h"

/* Block signals (default storage) */
B_Swingup_test_T Swingup_test_B;

/* Continuous states */
X_Swingup_test_T Swingup_test_X;

/* Block states (default storage) */
DW_Swingup_test_T Swingup_test_DW;

/* Real-time model */
static RT_MODEL_Swingup_test_T Swingup_test_M_;
RT_MODEL_Swingup_test_T *const Swingup_test_M = &Swingup_test_M_;

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
  Swingup_test_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Swingup_test_output(void)
{
  /* local block i/o variables */
  real_T rtb_SmoothSignalGenerator;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_countstorad;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(Swingup_test_M)) {
    /* set solver stop time */
    if (!(Swingup_test_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Swingup_test_M->solverInfo,
                            ((Swingup_test_M->Timing.clockTickH0 + 1) *
        Swingup_test_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Swingup_test_M->solverInfo,
                            ((Swingup_test_M->Timing.clockTick0 + 1) *
        Swingup_test_M->Timing.stepSize0 + Swingup_test_M->Timing.clockTickH0 *
        Swingup_test_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Swingup_test_M)) {
    Swingup_test_M->Timing.t[0] = rtsiGetT(&Swingup_test_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Swingup_test_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: Swingup_test/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(Swingup_test_DW.HILReadEncoderTimebase_Task,
        1, &Swingup_test_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        rtb_countstorad = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
      } else {
        rtb_countstorad = Swingup_test_DW.HILReadEncoderTimebase_Buffer;
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: Swingup_test/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Swingup_test_DW.HILInitialize_Card,
        &Swingup_test_P.HILReadEncoder_channels, 1,
        &Swingup_test_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
      } else {
        rtb_DiscreteTimeIntegrator = Swingup_test_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/counts to rad1' */
    Swingup_test_B.countstorad1 = Swingup_test_P.countstorad1_Gain *
      rtb_DiscreteTimeIntegrator;

    /* Gain: '<Root>/counts to rad' */
    rtb_countstorad *= Swingup_test_P.countstorad_Gain;

    /* Sum: '<Root>/Add1' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Swingup_test_B.Add1 = rtb_countstorad - Swingup_test_P.Constant3_Value;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn1'
   */
  Swingup_test_B.Gain = (Swingup_test_P.TransferFcn1_C *
    Swingup_test_X.TransferFcn1_CSTATE + Swingup_test_P.TransferFcn1_D *
    Swingup_test_B.countstorad1) * Swingup_test_P.Gain_Gain;

  /* Gain: '<Root>/Gain1' */
  Swingup_test_B.Gain1 = Swingup_test_P.Gain1_Gain * Swingup_test_B.Gain;

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *) Swingup_test_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Swingup_test_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = Swingup_test_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = Swingup_test_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[500]) {
      currTimeIndex = 499;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Swingup_test_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          Swingup_test_B.FromWorkspace = pDataValues[currTimeIndex];
        } else {
          Swingup_test_B.FromWorkspace = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        Swingup_test_B.FromWorkspace = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 501;
      }
    }
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Clock: '<Root>/Clock'
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain3'
   *  SignalConversion generated from: '<Root>/Vector Concatenate'
   *  Sum: '<Root>/Add'
   *  Switch: '<Root>/Switch1'
   *  TransferFcn: '<Root>/Transfer Fcn'
   * */
  if (Swingup_test_B.Add1 >= Swingup_test_P.Switch_Threshold) {
    rtb_DiscreteTimeIntegrator = (((Swingup_test_P.Constant_Value[1] -
      (Swingup_test_P.TransferFcn_C * Swingup_test_X.TransferFcn_CSTATE +
       Swingup_test_P.TransferFcn_D * Swingup_test_B.Add1)) *
      Swingup_test_P.K_pp[1] + (Swingup_test_P.Constant_Value[0] -
      Swingup_test_B.Gain1) * Swingup_test_P.K_pp[0]) +
      (Swingup_test_P.Constant_Value[2] - Swingup_test_B.countstorad1) *
      Swingup_test_P.K_pp[2]) + (Swingup_test_P.Constant_Value[3] -
      Swingup_test_B.Add1) * Swingup_test_P.K_pp[3];
  } else if (Swingup_test_M->Timing.t[0] >= Swingup_test_P.Switch1_Threshold) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_DiscreteTimeIntegrator = Swingup_test_P.Constant1_Value;
  } else {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Gain: '<Root>/Gain4'
     */
    rtb_DiscreteTimeIntegrator = Swingup_test_P.Gain4_Gain *
      Swingup_test_B.FromWorkspace;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Gain: '<Root>/Gain2' */
  Swingup_test_B.Gain2 = Swingup_test_P.Gain2_Gain * rtb_DiscreteTimeIntegrator;

  /* Saturate: '<Root>/Saturation1' */
  if (Swingup_test_B.Gain2 > Swingup_test_P.Saturation1_UpperSat) {
    /* Saturate: '<Root>/Saturation1' */
    Swingup_test_B.Saturation1 = Swingup_test_P.Saturation1_UpperSat;
  } else if (Swingup_test_B.Gain2 < Swingup_test_P.Saturation1_LowerSat) {
    /* Saturate: '<Root>/Saturation1' */
    Swingup_test_B.Saturation1 = Swingup_test_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation1' */
    Swingup_test_B.Saturation1 = Swingup_test_B.Gain2;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(Swingup_test_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Swingup_test/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Swingup_test_DW.HILInitialize_Card,
        &Swingup_test_P.HILWriteAnalog_channels, 1, &Swingup_test_B.Saturation1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
      }
    }

    /* Gain: '<S3>/Gain' */
    Swingup_test_B.Gain_n = Swingup_test_P.Gain_Gain_k *
      Swingup_test_B.countstorad1;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_DiscreteTimeIntegrator = Swingup_test_P.Gain1_Gain_a *
      Swingup_test_P.Constant2_Value;

    /* Gain: '<S2>/Gain' */
    Swingup_test_B.Gain_f[0] = Swingup_test_P.Gain_Gain_a *
      rtb_DiscreteTimeIntegrator;
    Swingup_test_B.Gain_f[1] = Swingup_test_P.Gain_Gain_a * rtb_countstorad;

    /* Abs: '<S5>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(Swingup_test_B.Gain2);

    /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
     *  Constant: '<S5>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      Swingup_test_P.StallMonitor_control_threshold);

    /* Abs: '<S5>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(Swingup_test_B.Gain);

    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Constant: '<S5>/motion threshold'
     *  RelationalOperator: '<S5>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <=
       Swingup_test_P.StallMonitor_motion_threshold));

    /* Logic: '<S5>/Logical Operator1' */
    Swingup_test_B.LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    if (Swingup_test_B.LogicalOperator1 &&
        (Swingup_test_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      Swingup_test_DW.DiscreteTimeIntegrator_DSTATE =
        Swingup_test_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator = Swingup_test_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S5>/Relational Operator2' incorporates:
     *  Constant: '<S5>/control threshold1'
     */
    Swingup_test_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
      Swingup_test_P.StallMonitor_duration_s);

    /* Stop: '<S6>/Stop Simulation' incorporates:
     *  Constant: '<S7>/Constant'
     *  RelationalOperator: '<S7>/Compare'
     */
    if (Swingup_test_B.RelationalOperator2 != Swingup_test_P.Constant_Value_j) {
      rtmSetStopRequested(Swingup_test_M, 1);
    }

    /* End of Stop: '<S6>/Stop Simulation' */

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    Swingup_test_B.DataTypeConversion = rtb_RelationalOperator1;

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */
    /* S-Function Block: Swingup_test/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * Swingup_test_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed = (Swingup_test_P.SmoothSignalGenerator_Amplitude
        != Swingup_test_DW.SmoothSignalGenerator_RWORK.Amp || w !=
        Swingup_test_DW.SmoothSignalGenerator_RWORK.W);

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
      real_T y_sin = Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos = Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_SmoothSignalGenerator =
        Swingup_test_DW.SmoothSignalGenerator_RWORK.Amp * y_sin;

      /* Compute the new sin and cos values */
      Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
        Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
        Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
        Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
        Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

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
        if (y_sin == 0 || Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t ==
            0 || (y_sin < 0) !=
            (Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t < 0)) {
          if (fabs(Swingup_test_DW.SmoothSignalGenerator_RWORK.Amp *
                   Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t) <
              Swingup_test_P.SmoothSignalGenerator_Amplitude) {
            x = asin(Swingup_test_DW.SmoothSignalGenerator_RWORK.Amp *
                     Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t /
                     Swingup_test_P.SmoothSignalGenerator_Amplitude);
            Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(w *
              0.0005);
            Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(w *
              0.0005);
            Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0)) {
              Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -cos(x);
            } else {
              Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.0005;
            Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0) {
              Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
            } else {
              Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
            }

            Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(x);
            Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(x);
          }

          Swingup_test_DW.SmoothSignalGenerator_RWORK.Amp =
            Swingup_test_P.SmoothSignalGenerator_Amplitude;
          Swingup_test_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }
  }
}

/* Model update function */
void Swingup_test_update(void)
{
  if (rtmIsMajorTimeStep(Swingup_test_M)) {
    /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    Swingup_test_DW.DiscreteTimeIntegrator_DSTATE +=
      Swingup_test_P.DiscreteTimeIntegrator_gainval *
      Swingup_test_B.DataTypeConversion;
    Swingup_test_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      Swingup_test_B.LogicalOperator1;
  }

  if (rtmIsMajorTimeStep(Swingup_test_M)) {
    rt_ertODEUpdateContinuousStates(&Swingup_test_M->solverInfo);
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
  if (!(++Swingup_test_M->Timing.clockTick0)) {
    ++Swingup_test_M->Timing.clockTickH0;
  }

  Swingup_test_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Swingup_test_M->solverInfo);

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
    if (!(++Swingup_test_M->Timing.clockTick1)) {
      ++Swingup_test_M->Timing.clockTickH1;
    }

    Swingup_test_M->Timing.t[1] = Swingup_test_M->Timing.clockTick1 *
      Swingup_test_M->Timing.stepSize1 + Swingup_test_M->Timing.clockTickH1 *
      Swingup_test_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Swingup_test_derivatives(void)
{
  XDot_Swingup_test_T *_rtXdot;
  _rtXdot = ((XDot_Swingup_test_T *) Swingup_test_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = Swingup_test_P.TransferFcn1_A *
    Swingup_test_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Swingup_test_B.countstorad1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = Swingup_test_P.TransferFcn_A *
    Swingup_test_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Swingup_test_B.Add1;
}

/* Model initialize function */
void Swingup_test_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Swingup_test/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &Swingup_test_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Swingup_test_DW.HILInitialize_Card,
      " ", 2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Swingup_test_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
      return;
    }

    if ((Swingup_test_P.HILInitialize_AIPStart && !is_switching) ||
        (Swingup_test_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Swingup_test_DW.HILInitialize_Card,
        &Swingup_test_P.HILInitialize_AIChannels, 1U,
        &Swingup_test_P.HILInitialize_AILow,
        &Swingup_test_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_test_P.HILInitialize_AOPStart && !is_switching) ||
        (Swingup_test_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Swingup_test_DW.HILInitialize_Card,
        &Swingup_test_P.HILInitialize_AOChannels, 1U,
        &Swingup_test_P.HILInitialize_AOLow,
        &Swingup_test_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_test_P.HILInitialize_AOStart && !is_switching) ||
        (Swingup_test_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Swingup_test_DW.HILInitialize_Card,
        &Swingup_test_P.HILInitialize_AOChannels, 1U,
        &Swingup_test_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }

    if (Swingup_test_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Swingup_test_DW.HILInitialize_Card,
         &Swingup_test_P.HILInitialize_AOChannels, 1U,
         &Swingup_test_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Swingup_test_DW.HILInitialize_Card, NULL,
      0U, &Swingup_test_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
      return;
    }

    if ((Swingup_test_P.HILInitialize_DOStart && !is_switching) ||
        (Swingup_test_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Swingup_test_DW.HILInitialize_Card,
        &Swingup_test_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Swingup_test_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }

    if (Swingup_test_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Swingup_test_DW.HILInitialize_Card,
         &Swingup_test_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &Swingup_test_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_test_P.HILInitialize_EIPStart && !is_switching) ||
        (Swingup_test_P.HILInitialize_EIPEnter && is_switching)) {
      Swingup_test_DW.HILInitialize_QuadratureModes[0] =
        Swingup_test_P.HILInitialize_EIQuadrature;
      Swingup_test_DW.HILInitialize_QuadratureModes[1] =
        Swingup_test_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Swingup_test_DW.HILInitialize_Card,
         Swingup_test_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode
          *) &Swingup_test_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_test_P.HILInitialize_EIStart && !is_switching) ||
        (Swingup_test_P.HILInitialize_EIEnter && is_switching)) {
      Swingup_test_DW.HILInitialize_InitialEICounts[0] =
        Swingup_test_P.HILInitialize_EIInitial;
      Swingup_test_DW.HILInitialize_InitialEICounts[1] =
        Swingup_test_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Swingup_test_DW.HILInitialize_Card,
        Swingup_test_P.HILInitialize_EIChannels, 2U,
        &Swingup_test_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_test_P.HILInitialize_OOStart && !is_switching) ||
        (Swingup_test_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Swingup_test_DW.HILInitialize_Card,
        Swingup_test_P.HILInitialize_OOChannels, 3U,
        Swingup_test_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }

    if (Swingup_test_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Swingup_test_DW.HILInitialize_Card,
         Swingup_test_P.HILInitialize_OOChannels, 3U,
         Swingup_test_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Swingup_test/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Swingup_test_DW.HILInitialize_Card,
      Swingup_test_P.HILReadEncoderTimebase_SamplesI,
      &Swingup_test_P.HILReadEncoderTimebase_Channels, 1,
      &Swingup_test_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Swingup_test_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Swingup_test_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
    }
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06,
      0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
      0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31,
      0.32, 0.33, 0.34, 0.35000000000000003, 0.36, 0.37, 0.38, 0.39, 0.4,
      0.41000000000000003, 0.42, 0.43, 0.44, 0.45, 0.46, 0.47000000000000003,
      0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57000000000000006,
      0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68,
      0.69000000000000006, 0.70000000000000007, 0.71, 0.72, 0.73, 0.74, 0.75,
      0.76, 0.77, 0.78, 0.79, 0.8, 0.81, 0.82000000000000006,
      0.83000000000000007, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94000000000000006, 0.95000000000000007, 0.96, 0.97, 0.98, 0.99,
      1.0, 1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12,
      1.1300000000000001, 1.1400000000000001, 1.1500000000000001, 1.16, 1.17,
      1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3,
      1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.3800000000000001,
      1.3900000000000001, 1.4000000000000001, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
      1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58,
      1.59, 1.6, 1.61, 1.62, 1.6300000000000001, 1.6400000000000001,
      1.6500000000000001, 1.6600000000000001, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72,
      1.73, 1.74, 1.75, 1.76, 1.77, 1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84,
      1.85, 1.86, 1.87, 1.8800000000000001, 1.8900000000000001,
      1.9000000000000001, 1.9100000000000001, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97,
      1.98, 1.99, 2.0, 2.0100000000000002, 2.02, 2.0300000000000002, 2.04, 2.05,
      2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17,
      2.18, 2.19, 2.2, 2.21, 2.22, 2.23, 2.24, 2.25, 2.2600000000000002, 2.27,
      2.2800000000000002, 2.29, 2.3000000000000003, 2.31, 2.32, 2.33, 2.34, 2.35,
      2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.43, 2.44, 2.45, 2.46, 2.47,
      2.48, 2.49, 2.5, 2.51, 2.5199999999999996, 2.53, 2.5399999999999996, 2.55,
      2.5599999999999996, 2.57, 2.5799999999999996, 2.59, 2.5999999999999996,
      2.61, 2.6199999999999997, 2.63, 2.6399999999999997, 2.65,
      2.6599999999999997, 2.67, 2.6799999999999997, 2.69, 2.6999999999999997,
      2.7099999999999995, 2.7199999999999998, 2.7299999999999995,
      2.7399999999999998, 2.7499999999999996, 2.76, 2.7699999999999996, 2.78,
      2.7899999999999996, 2.8, 2.8099999999999996, 2.82, 2.8299999999999996,
      2.84, 2.8499999999999996, 2.86, 2.8699999999999997, 2.88,
      2.8899999999999997, 2.9, 2.9099999999999997, 2.92, 2.9299999999999997,
      2.94, 2.9499999999999997, 2.96, 2.9699999999999998, 2.9799999999999995,
      2.9899999999999998, 2.9999999999999996, 3.01, 3.0199999999999996, 3.03,
      3.04, 3.05, 3.0599999999999996, 3.07, 3.08, 3.09, 3.0999999999999996,
      3.1099999999999994, 3.1199999999999997, 3.13, 3.1399999999999997,
      3.1499999999999995, 3.1599999999999997, 3.17, 3.1799999999999997,
      3.1899999999999995, 3.1999999999999997, 3.21, 3.2199999999999998,
      3.2299999999999995, 3.2399999999999998, 3.25, 3.26, 3.2699999999999996,
      3.28, 3.29, 3.3, 3.3099999999999996, 3.32, 3.33, 3.34, 3.3499999999999996,
      3.3599999999999994, 3.3699999999999997, 3.38, 3.3899999999999997,
      3.3999999999999995, 3.4099999999999997, 3.42, 3.4299999999999997,
      3.4399999999999995, 3.4499999999999997, 3.46, 3.4699999999999998,
      3.4799999999999995, 3.4899999999999998, 3.5, 3.51, 3.5199999999999996,
      3.53, 3.54, 3.55, 3.5599999999999996, 3.57, 3.58, 3.59, 3.5999999999999996,
      3.6099999999999994, 3.6199999999999997, 3.63, 3.6399999999999997,
      3.6499999999999995, 3.6599999999999997, 3.67, 3.6799999999999997,
      3.6899999999999995, 3.6999999999999997, 3.71, 3.7199999999999998,
      3.7299999999999995, 3.7399999999999998, 3.75, 3.76, 3.7699999999999996,
      3.78, 3.79, 3.8, 3.8099999999999996, 3.82, 3.83, 3.84, 3.8499999999999996,
      3.8599999999999994, 3.8699999999999997, 3.88, 3.8899999999999997,
      3.8999999999999995, 3.9099999999999997, 3.92, 3.9299999999999997,
      3.9399999999999995, 3.9499999999999997, 3.96, 3.9699999999999998,
      3.9799999999999995, 3.9899999999999998, 4.0, 4.01, 4.02,
      4.0299999999999994, 4.04, 4.05, 4.06, 4.0699999999999994, 4.08, 4.09, 4.1,
      4.1099999999999994, 4.12, 4.13, 4.14, 4.1499999999999995, 4.16, 4.17, 4.18,
      4.1899999999999995, 4.1999999999999993, 4.21, 4.22, 4.2299999999999995,
      4.24, 4.25, 4.26, 4.27, 4.2799999999999994, 4.29, 4.3, 4.31,
      4.3199999999999994, 4.33, 4.34, 4.35, 4.3599999999999994, 4.37, 4.38, 4.39,
      4.3999999999999995, 4.41, 4.42, 4.43, 4.4399999999999995,
      4.4499999999999993, 4.46, 4.47, 4.4799999999999995, 4.49, 4.5, 4.51, 4.52,
      4.5299999999999994, 4.54, 4.55, 4.56, 4.5699999999999994, 4.58, 4.59, 4.6,
      4.6099999999999994, 4.62, 4.63, 4.64, 4.6499999999999995, 4.66, 4.67, 4.68,
      4.6899999999999995, 4.7, 4.71, 4.72, 4.7299999999999995, 4.74, 4.75, 4.76,
      4.77, 4.7799999999999994, 4.79, 4.8, 4.81, 4.8199999999999994, 4.83, 4.84,
      4.85, 4.8599999999999994, 4.87, 4.88, 4.89, 4.8999999999999995, 4.91, 4.92,
      4.93, 4.9399999999999995, 4.95, 4.96, 4.97, 4.9799999999999995, 4.99, 5.0
    } ;

    static real_T pDataValues0[] = { 0.60451446321157454, 1.1064897931087854,
      0.69325681870221767, 0.29381579809812447, -0.085842906975038047,
      -0.44278117385502463, -0.77337726491688952, -1.0743271926646243,
      -1.3434189452525904, -1.5790264259138216, -1.779283936735812,
      -1.9424408076725683, -2.0669811336763111, -2.1506635916876968,
      -2.1925968218511116, -2.1943972225366806, -2.1574295527261613,
      -2.0841598436811108, -1.9791549925197711, -1.8529705183013749,
      -1.7178493643231412, -1.5727205269263416, -1.4074575990377318,
      -1.2105335340420735, -0.97415450667031345, -0.69781394695448917,
      -0.38445584040693326, -0.042819999936643149, 0.31613556843848323,
      0.68199873803133482, 1.0435250829568274, 1.3916236615007367,
      1.7205523142789363, 2.0278661710226635, 2.3142949282052476,
      2.5825014829911219, 2.8317533707530465, 3.0545463829424917,
      3.2375171639520524, 3.3636155059931228, 3.4162950253575555,
      3.3834590422769475, 3.2597975183916605, 3.0486332133219718,
      2.7621907514634, 2.4234649387496972, 2.0631758955510313,
      1.7077664123844583, 1.3724579292908468, 1.0644859937862894,
      0.78883921979454552, 0.54281463799634144, 0.31314985321350552,
      0.091094348160177807, -0.12004308819641948, -0.31572578788845457,
      -0.49526712873034145, -0.662007825002429, -0.82490087011672319,
      -0.995268425346591, -1.1802789205612516, -1.3793268073870582,
      -1.5845543647287885, -1.7822814398818267, -1.9550832817145438,
      -2.0844721855990764, -2.1520309346889706, -2.139453782956422,
      -2.0313681577174614, -1.8217819984580137, -1.5204306160515342,
      -1.1643771416214965, -0.81710626393749863, -0.53650965727976674,
      -0.34929012443672736, -0.2520859292186497, -0.22343000173740435,
      -0.23250332317389569, -0.23933311263941917, -0.20648863202726622,
      -0.11982072300571593, 0.0074199202543919693, 0.14724450572588577,
      0.27403860387090195, 0.37693695184767428, 0.46325828852155959,
      0.5519231978331437, 0.66032972838314208, 0.79656335611064388,
      0.95940271502284968, 1.1417973836924582, 1.3341291132434061,
      1.5240844302532968, 1.6925885624091941, 1.8101873002833813,
      1.8402445805202716, 1.7496429322752651, 1.5274079351204344,
      1.2047275949059597, 0.85577706755573157, 0.56022310050777424,
      0.35867206437526933, 0.24137575378394735, 0.16683210725205844,
      0.098435658480765187, 0.021983109136085061, -0.06388060250897315,
      -0.15451200009319374, -0.23739172525568328, -0.29325807850962032,
      -0.30671216106382704, -0.2806871601521202, -0.23940233147259085,
      -0.21669703076930952, -0.240026309773648, -0.31827601052253957,
      -0.44413767427792178, -0.605457353492345, -0.79187377707220319,
      -0.99724770766718351, -1.2158616314282062, -1.43172963147016,
      -1.6123340054683946, -1.7109354989983927, -1.6842771666001102,
      -1.5113670740100509, -1.2032524009669534, -0.82328416524602732,
      -0.473034654887575, -0.22870920977356962, -0.1005267007829824,
      -0.045015348648100972, -0.010455133740280197, 0.021558450517662905,
      0.041294278577258384, 0.038652141463965839, 0.015997923077088527,
      -0.020274009553254022, -0.071141755756159858, -0.13403969568851604,
      -0.19382389895443075, -0.23222949768088771, -0.23998181982013786,
      -0.22046917722483006, -0.18108715351311205, -0.12252108788798598,
      -0.036554067124555854, 0.08907102722120698, 0.26495477154347657,
      0.49261129057036268, 0.75342026891030867, 1.0127680615068229,
      1.2273648429503417, 1.3430252548094206, 1.3150432880602692,
      1.1373339269537661, 0.85461464138217946, 0.5563680654615053,
      0.33524755953401697, 0.22340937461795946, 0.1781204903782054,
      0.13874965296508499, 0.0836527478736041, 0.028164203324235443,
      -0.008803856403026139, -0.023334457389193888, -0.016747163898487794,
      0.013911262675162836, 0.061783921223419629, 0.11129432594650837,
      0.15317865045782539, 0.18380146982883544, 0.19875232226062139,
      0.19101949756878389, 0.15233409550557381, 0.0765249496498441,
      -0.03705083480527277, -0.18154612513443139, -0.346331947099438,
      -0.52570677507474928, -0.71647400741647038, -0.90423212418242915,
      -1.0577230093951588, -1.1327584201872922, -1.0863541363518534,
      -0.90114912053574059, -0.60520488025378116, -0.27331942576686513,
      0.0094281461038566682, 0.20500756022951935, 0.33056731236320286,
      0.40854685401731505, 0.43704662737191741, 0.41484105959451995,
      0.36162908364236379, 0.2997605326762775, 0.23986805254608703,
      0.18793184762346651, 0.14212955207470546, 0.095108377841952141,
      0.045694464772331418, 0.00048004548475641742, -0.02979901323220422,
      -0.034389752185058547, -0.0073489228356293989, 0.051235584285046487,
      0.13672092922287019, 0.241584781940864, 0.35744503294087482,
      0.47449024419309316, 0.58300278767279434, 0.67168478241734242,
      0.7233817857147069, 0.714135802182125, 0.61859166039558711,
      0.42713524488967014, 0.1684448753055558, -0.084243381616756444,
      -0.25238996443271422, -0.31255366992629841, -0.30099106383638613,
      -0.26242632341914196, -0.22257565561337067, -0.1900813456847133,
      -0.15749566866654119, -0.11563526799785719, -0.06033831468498773,
      0.0047626445356283957, 0.063888112998037358, 0.096385687146349777,
      0.087283890651525281, 0.03479690274297173, -0.046236289197051791,
      -0.13546948449180699, -0.21733351775197612, -0.27850334006978611,
      -0.31617927190897821, -0.33792101501886018, -0.35111506440270029,
      -0.35988198575571861, -0.36429382430920143, -0.36165996868869987,
      -0.34501467565195709, -0.30179012089175145, -0.21808249568859026,
      -0.085535002211290456, 0.0851285002685655, 0.25147028472151861,
      0.35940133633904436, 0.39101625709462995, 0.36750922103411066,
      0.31405128883148986, 0.24760914262230044, 0.17820790097729236,
      0.11383607158118127, 0.063738389667343243, 0.036106272269987638,
      0.032226863412612355, 0.043304990325139105, 0.05419912911189799,
      0.058059040154002366, 0.061575457103946331, 0.0699915166818885,
      0.085738702611260292, 0.10847705347718137, 0.13205665211415751,
      0.1496547687411281, 0.15809602899579558, 0.157109727733709,
      0.14616180956929323, 0.12486721916206865, 0.093422403000492288,
      0.050056612707528689, -0.008589283701657166, -0.084747270058368934,
      -0.17660509612608349, -0.27297745097358084, -0.35063720610495208,
      -0.38632707434001473, -0.37573085489005903, -0.33307149400529384,
      -0.27874611939451865, -0.22544948129516987, -0.17184453174207226,
      -0.11646301478486552, -0.065237632666182266, -0.0267861695934,
      -0.0084987758843995381, -0.016775159234591622, -0.052759041080875715,
      -0.10544779941191514, -0.15846174075502517, -0.20047260162778624,
      -0.22684585332569041, -0.23765182061012174, -0.23602359842273837,
      -0.2282396568775501, -0.22120969632217, -0.21919164714147121,
      -0.22538731723053734, -0.24061771993149381, -0.26143851394637052,
      -0.28039637925678729, -0.28613672635017617, -0.26512875159917371,
      -0.20493561255630438, -0.10075781966190901, 0.035000394410440748,
      0.17284577149720351, 0.27930511468784552, 0.33438156701529431,
      0.34349240781719109, 0.32891834424177158, 0.31379095741023239,
      0.30808327007374625, 0.310093755433205, 0.31488959294094065,
      0.31220270863509236, 0.29487946939591742, 0.264507580184207,
      0.22447614432233523, 0.17899132719766711, 0.13690925154638828,
      0.10673429324597015, 0.093613772374713966, 0.10159543565207253,
      0.13190114881613391, 0.18395145841513297, 0.25647644085408444,
      0.34647894061739765, 0.4489460185850816, 0.55684188227780251,
      0.6608316961802988, 0.7487798921168779, 0.80544533656478778,
      0.81374391400020263, 0.75956426463193616, 0.64369738702457546,
      0.48757108270696076, 0.32460441036196341, 0.19024067910348488,
      0.10562679193822798, 0.0657185489182772, 0.043530872982933205,
      0.011711895639913861, -0.03265150231561241, -0.075312617356319084,
      -0.10174840011619689, -0.10539813497123715, -0.090183913657721,
      -0.0644044063708394, -0.037774965245288263, -0.018468311225486589,
      -0.012538390584353222, -0.025070672690418742, -0.057829133058380333,
      -0.10987987763285403, -0.18010229666707642, -0.2680660600362525,
      -0.37390650925535673, -0.49817251074898355, -0.64076683022528125,
      -0.79876838586309429, -0.96464692640530947, -1.1244929121940643,
      -1.2564857862961365, -1.332311563942302, -1.3257956610215633,
      -1.2275599430548123, -1.0560967991923937, -0.84490709131057629,
      -0.61938780855925035, -0.39852074659705616, -0.20187531567306616,
      -0.0420883335118876, 0.07745973695119579, 0.15721716017426038,
      0.20092468699166247, 0.21574952340325343, 0.20988537211713906,
      0.19163862408286447, 0.16844463400958923, 0.14529463465020243,
      0.12547193981482826, 0.11261260495456978, 0.11190052329109407,
      0.12958576835912228, 0.1716840793156324, 0.24316048473624177,
      0.3475871773525987, 0.48731596701171215, 0.66385144219360726,
      0.877968074219376, 1.1292552926027555, 1.4145492009616709,
      1.7244960657703208, 2.0388130982288231, 2.3203347497665567,
      2.5137143450556878, 2.5609485779381851, 2.4344774481909011,
      2.1583316594987396, 1.7910776087347651, 1.3921356239370857,
      1.0080405449950569, 0.675056845797223, 0.41479611726514365,
      0.23011045221612858, 0.11246978839574062, 0.049900329523154957,
      0.029977625366409886, 0.038180993673114394, 0.058408868326578274,
      0.079110242309762213, 0.096890837993270376, 0.11384135983434035,
      0.13216587658000975, 0.15064476969556925, 0.16421930651235286,
      0.1654158413106683, 0.14599704186386464, 0.098038909916126848,
      0.014415036978355059, -0.11116160470494631, -0.28427583720640759,
      -0.50991632823292055, -0.79257108677594268, -1.1356389954299841,
      -1.5397648314103776, -1.9986083973808892, -2.4902814603436019,
      -2.9646507787311305, -3.3335995053172445, -3.4875661601432504,
      -3.3576131480805138, -2.9747858095958222, -2.4467908631013309,
      -1.886705158682618, -1.3741782119127803, -0.9460134971385058,
      -0.61023099952787774, -0.36907586643330254, -0.22168846522298405,
      -0.15262808093770391, -0.13542520351642312, -0.14969058654069622,
      -0.18838353855440579, -0.25260358100520158, -0.34402896187790705,
      -0.4610071429891141, -0.59813794944554466, -0.74749839646183325,
      -0.89988648394773818, -1.0457944884670889, -1.1760307723193024,
      -1.2822511688123375, -1.3573018013892444, -1.3953130692451974,
      -1.3915433457754234, -1.3419259791573348, -1.2424615235405345,
      -1.0886430167759775, -0.8749260884095994, -0.59474887899973017,
      -0.24088254339260767, 0.19326484571705271, 0.712120425054626,
      1.3146431285468987, 1.9878302647804402, 2.6904399930174323,
      3.3252160644322628, 3.7246309128159276, 3.7206171192975646,
      3.2901897944834526, 2.5826553165125152, 1.7700351641273577,
      0.95019075461483093, 0.1870406445612017, -0.46955187828978817,
      -0.9996891826697113, -1.4127903338077539, -1.735501047925224,
      -1.9858314103718286, -2.15778857422225, -2.2405330295471764,
      -2.2433658282827271, -2.1889432134727467, -2.0980842234866897,
      -1.9862348988022029, -1.8637016959158996, -1.7360134136429168,
      -1.6049379201675453, -1.4694943614977545, -1.3264743444415232,
      -1.1711239240091855, -0.99847202718469985, -0.8045641340548404,
      -0.58530804149880022, -0.33329201767343242, -0.0428715030270558,
      0.24484019180473937 } ;

    Swingup_test_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    Swingup_test_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    Swingup_test_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */

  /* S-Function Block: Swingup_test/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / Swingup_test_P.SmoothSignalGenerator_Frequency;
    Swingup_test_DW.SmoothSignalGenerator_RWORK.Amp =
      Swingup_test_P.SmoothSignalGenerator_Amplitude;
    Swingup_test_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      Swingup_test_P.SmoothSignalGenerator_Frequency;
    Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (Swingup_test_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (Swingup_test_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (Swingup_test_P.SmoothSignalGenerator_InitialPh);
    Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (Swingup_test_P.SmoothSignalGenerator_InitialPh);
  }

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Swingup_test_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Swingup_test_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  Swingup_test_DW.DiscreteTimeIntegrator_DSTATE =
    Swingup_test_P.DiscreteTimeIntegrator_IC;
  Swingup_test_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void Swingup_test_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Swingup_test/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Swingup_test_DW.HILInitialize_Card);
    hil_monitor_stop_all(Swingup_test_DW.HILInitialize_Card);
    is_switching = false;
    if ((Swingup_test_P.HILInitialize_AOTerminate && !is_switching) ||
        (Swingup_test_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Swingup_test_P.HILInitialize_DOTerminate && !is_switching) ||
        (Swingup_test_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Swingup_test_P.HILInitialize_OOTerminate && !is_switching) ||
        (Swingup_test_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Swingup_test_DW.HILInitialize_Card
                         , &Swingup_test_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Swingup_test_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Swingup_test_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Swingup_test_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Swingup_test_P.HILInitialize_DOFinal
                         , Swingup_test_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Swingup_test_DW.HILInitialize_Card,
            &Swingup_test_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Swingup_test_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Swingup_test_DW.HILInitialize_Card,
            &Swingup_test_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Swingup_test_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Swingup_test_DW.HILInitialize_Card,
            Swingup_test_P.HILInitialize_OOChannels, num_final_other_outputs,
            Swingup_test_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Swingup_test_DW.HILInitialize_Card);
    hil_monitor_delete_all(Swingup_test_DW.HILInitialize_Card);
    hil_close(Swingup_test_DW.HILInitialize_Card);
    Swingup_test_DW.HILInitialize_Card = NULL;
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
  Swingup_test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Swingup_test_update();
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
  Swingup_test_initialize();
}

void MdlTerminate(void)
{
  Swingup_test_terminate();
}

/* Registration function */
RT_MODEL_Swingup_test_T *Swingup_test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Swingup_test_M, 0,
                sizeof(RT_MODEL_Swingup_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Swingup_test_M->solverInfo,
                          &Swingup_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&Swingup_test_M->solverInfo, &rtmGetTPtr(Swingup_test_M));
    rtsiSetStepSizePtr(&Swingup_test_M->solverInfo,
                       &Swingup_test_M->Timing.stepSize0);
    rtsiSetdXPtr(&Swingup_test_M->solverInfo, &Swingup_test_M->derivs);
    rtsiSetContStatesPtr(&Swingup_test_M->solverInfo, (real_T **)
                         &Swingup_test_M->contStates);
    rtsiSetNumContStatesPtr(&Swingup_test_M->solverInfo,
      &Swingup_test_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Swingup_test_M->solverInfo,
      &Swingup_test_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Swingup_test_M->solverInfo,
      &Swingup_test_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Swingup_test_M->solverInfo,
      &Swingup_test_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Swingup_test_M->solverInfo, (&rtmGetErrorStatus
      (Swingup_test_M)));
    rtsiSetRTModelPtr(&Swingup_test_M->solverInfo, Swingup_test_M);
  }

  rtsiSetSimTimeStep(&Swingup_test_M->solverInfo, MAJOR_TIME_STEP);
  Swingup_test_M->intgData.f[0] = Swingup_test_M->odeF[0];
  Swingup_test_M->contStates = ((real_T *) &Swingup_test_X);
  rtsiSetSolverData(&Swingup_test_M->solverInfo, (void *)
                    &Swingup_test_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Swingup_test_M->solverInfo, false);
  rtsiSetSolverName(&Swingup_test_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Swingup_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Swingup_test_M points to
       static memory which is guaranteed to be non-NULL" */
    Swingup_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Swingup_test_M->Timing.sampleTimes =
      (&Swingup_test_M->Timing.sampleTimesArray[0]);
    Swingup_test_M->Timing.offsetTimes =
      (&Swingup_test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Swingup_test_M->Timing.sampleTimes[0] = (0.0);
    Swingup_test_M->Timing.sampleTimes[1] = (0.0005);

    /* task offsets */
    Swingup_test_M->Timing.offsetTimes[0] = (0.0);
    Swingup_test_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Swingup_test_M, &Swingup_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Swingup_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Swingup_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Swingup_test_M, -1);
  Swingup_test_M->Timing.stepSize0 = 0.0005;
  Swingup_test_M->Timing.stepSize1 = 0.0005;

  /* External mode info */
  Swingup_test_M->Sizes.checksums[0] = (3243491387U);
  Swingup_test_M->Sizes.checksums[1] = (2940039033U);
  Swingup_test_M->Sizes.checksums[2] = (1247035944U);
  Swingup_test_M->Sizes.checksums[3] = (3389082656U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Swingup_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Swingup_test_M->extModeInfo,
      &Swingup_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Swingup_test_M->extModeInfo,
                        Swingup_test_M->Sizes.checksums);
    rteiSetTPtr(Swingup_test_M->extModeInfo, rtmGetTPtr(Swingup_test_M));
  }

  Swingup_test_M->solverInfoPtr = (&Swingup_test_M->solverInfo);
  Swingup_test_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&Swingup_test_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&Swingup_test_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Swingup_test_M->blockIO = ((void *) &Swingup_test_B);
  (void) memset(((void *) &Swingup_test_B), 0,
                sizeof(B_Swingup_test_T));

  {
    Swingup_test_B.countstorad1 = 0.0;
    Swingup_test_B.Gain = 0.0;
    Swingup_test_B.Gain1 = 0.0;
    Swingup_test_B.Add1 = 0.0;
    Swingup_test_B.FromWorkspace = 0.0;
    Swingup_test_B.Gain2 = 0.0;
    Swingup_test_B.Saturation1 = 0.0;
    Swingup_test_B.Gain_n = 0.0;
    Swingup_test_B.Gain_f[0] = 0.0;
    Swingup_test_B.Gain_f[1] = 0.0;
    Swingup_test_B.DataTypeConversion = 0.0;
  }

  /* parameters */
  Swingup_test_M->defaultParam = ((real_T *)&Swingup_test_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Swingup_test_X;
    Swingup_test_M->contStates = (x);
    (void) memset((void *)&Swingup_test_X, 0,
                  sizeof(X_Swingup_test_T));
  }

  /* states (dwork) */
  Swingup_test_M->dwork = ((void *) &Swingup_test_DW);
  (void) memset((void *)&Swingup_test_DW, 0,
                sizeof(DW_Swingup_test_T));
  Swingup_test_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  Swingup_test_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Swingup_test_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Swingup_test_DW.SmoothSignalGenerator_RWORK.Amp = 0.0;
  Swingup_test_DW.SmoothSignalGenerator_RWORK.W = 0.0;
  Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = 0.0;
  Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = 0.0;
  Swingup_test_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0.0;
  Swingup_test_DW.SmoothSignalGenerator_RWORK.Cos_w_t = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Swingup_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Swingup_test_M->Sizes.numContStates = (2);/* Number of continuous states */
  Swingup_test_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Swingup_test_M->Sizes.numY = (0);    /* Number of model outputs */
  Swingup_test_M->Sizes.numU = (0);    /* Number of model inputs */
  Swingup_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Swingup_test_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Swingup_test_M->Sizes.numBlocks = (58);/* Number of blocks */
  Swingup_test_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  Swingup_test_M->Sizes.numBlockPrms = (116);/* Sum of parameter "widths" */
  return Swingup_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
