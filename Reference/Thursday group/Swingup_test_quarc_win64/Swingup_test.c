/*
 * Swingup_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Swingup_test".
 *
 * Model version              : 9.27
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Dec 14 18:15:51 2023
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
  real_T rtb_HILReadEncoderTimebase;
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
        rtb_HILReadEncoderTimebase = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_test_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase =
          Swingup_test_DW.HILReadEncoderTimebase_Buffer;
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
    Swingup_test_B.countstorad = Swingup_test_P.countstorad_Gain *
      rtb_HILReadEncoderTimebase;

    /* Sum: '<Root>/Add1' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Swingup_test_B.Add1 = Swingup_test_B.countstorad -
      Swingup_test_P.Constant3_Value;
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  Swingup_test_B.TransferFcn1 = 0.0;
  Swingup_test_B.TransferFcn1 += Swingup_test_P.TransferFcn1_C *
    Swingup_test_X.TransferFcn1_CSTATE;
  Swingup_test_B.TransferFcn1 += Swingup_test_P.TransferFcn1_D *
    Swingup_test_B.countstorad1;

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
  if (Swingup_test_B.countstorad >= Swingup_test_P.Switch_Threshold) {
    rtb_HILReadEncoderTimebase = (((Swingup_test_P.Constant_Value[1] -
      (Swingup_test_P.TransferFcn_C * Swingup_test_X.TransferFcn_CSTATE +
       Swingup_test_P.TransferFcn_D * Swingup_test_B.Add1)) *
      Swingup_test_P.K_pp[1] + (Swingup_test_P.Constant_Value[0] -
      Swingup_test_B.TransferFcn1) * Swingup_test_P.K_pp[0]) +
      (Swingup_test_P.Constant_Value[2] - Swingup_test_B.countstorad1) *
      Swingup_test_P.K_pp[2]) + (Swingup_test_P.Constant_Value[3] -
      Swingup_test_B.Add1) * Swingup_test_P.K_pp[3];
  } else if (Swingup_test_M->Timing.t[0] >= Swingup_test_P.Switch1_Threshold) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_HILReadEncoderTimebase = Swingup_test_P.Constant1_Value;
  } else {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Gain: '<Root>/Gain4'
     */
    rtb_HILReadEncoderTimebase = Swingup_test_P.Gain4_Gain *
      Swingup_test_B.FromWorkspace;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Gain: '<Root>/Gain2' */
  Swingup_test_B.Gain2 = Swingup_test_P.Gain2_Gain * rtb_HILReadEncoderTimebase;

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
    Swingup_test_B.Gain = Swingup_test_P.Gain_Gain * Swingup_test_B.countstorad1;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_DiscreteTimeIntegrator = Swingup_test_P.Gain1_Gain *
      Swingup_test_P.Constant2_Value;

    /* Gain: '<S2>/Gain' */
    Swingup_test_B.Gain_f[0] = Swingup_test_P.Gain_Gain_a *
      rtb_DiscreteTimeIntegrator;
    Swingup_test_B.Gain_f[1] = Swingup_test_P.Gain_Gain_a *
      Swingup_test_B.countstorad;

    /* Abs: '<S5>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(Swingup_test_B.Gain2);

    /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
     *  Constant: '<S5>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      Swingup_test_P.StallMonitor_control_threshold);

    /* Abs: '<S5>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(Swingup_test_B.TransferFcn1);

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
    static real_T pTimeValues0[] = { 0.0, 0.002, 0.004, 0.006, 0.008, 0.01,
      0.012, 0.014, 0.016, 0.018000000000000002, 0.02, 0.022, 0.024,
      0.026000000000000002, 0.028, 0.03, 0.032, 0.034, 0.036000000000000004,
      0.038, 0.04, 0.042, 0.044, 0.046, 0.048, 0.05, 0.052000000000000005, 0.054,
      0.056, 0.058, 0.06, 0.062, 0.064, 0.066, 0.068, 0.07, 0.072000000000000008,
      0.074, 0.076, 0.078, 0.08, 0.082, 0.084, 0.086000000000000007, 0.088, 0.09,
      0.092, 0.094, 0.096, 0.098, 0.1, 0.10200000000000001, 0.10400000000000001,
      0.106, 0.108, 0.11, 0.112, 0.114, 0.116, 0.11800000000000001, 0.12, 0.122,
      0.124, 0.126, 0.128, 0.13, 0.132, 0.134, 0.136, 0.138, 0.14,
      0.14200000000000002, 0.14400000000000002, 0.146, 0.148, 0.15, 0.152, 0.154,
      0.156, 0.158, 0.16, 0.162, 0.164, 0.166, 0.168, 0.17, 0.17200000000000001,
      0.17400000000000002, 0.176, 0.178, 0.18, 0.182, 0.184, 0.186, 0.188, 0.19,
      0.192, 0.194, 0.196, 0.198, 0.2, 0.202, 0.20400000000000001,
      0.20600000000000002, 0.20800000000000002, 0.21, 0.212, 0.214, 0.216, 0.218,
      0.22, 0.222, 0.224, 0.226, 0.228, 0.23, 0.232, 0.234, 0.23600000000000002,
      0.23800000000000002, 0.24, 0.242, 0.244, 0.246, 0.248, 0.25, 0.252, 0.254,
      0.256, 0.258, 0.26, 0.262, 0.264, 0.266, 0.268, 0.27, 0.272, 0.274, 0.276,
      0.278, 0.28, 0.28200000000000003, 0.28400000000000003, 0.28600000000000003,
      0.28800000000000003, 0.29, 0.292, 0.294, 0.296, 0.298, 0.3, 0.302, 0.304,
      0.306, 0.308, 0.31, 0.312, 0.314, 0.316, 0.318, 0.32, 0.322, 0.324, 0.326,
      0.328, 0.33, 0.332, 0.334, 0.336, 0.338, 0.34, 0.342, 0.34400000000000003,
      0.34600000000000003, 0.34800000000000003, 0.35000000000000003, 0.352,
      0.354, 0.356, 0.358, 0.36, 0.362, 0.364, 0.366, 0.368, 0.37, 0.372, 0.374,
      0.376, 0.378, 0.38, 0.382, 0.384, 0.386, 0.388, 0.39, 0.392, 0.394, 0.396,
      0.398, 0.4, 0.402, 0.404, 0.406, 0.40800000000000003, 0.41000000000000003,
      0.41200000000000003, 0.41400000000000003, 0.41600000000000004, 0.418, 0.42,
      0.422, 0.424, 0.426, 0.428, 0.43, 0.432, 0.434, 0.436, 0.438, 0.44, 0.442,
      0.444, 0.446, 0.448, 0.45, 0.452, 0.454, 0.456, 0.458, 0.46, 0.462, 0.464,
      0.466, 0.468, 0.47000000000000003, 0.47200000000000003,
      0.47400000000000003, 0.47600000000000003, 0.47800000000000004, 0.48, 0.482,
      0.484, 0.486, 0.488, 0.49, 0.492, 0.494, 0.496, 0.498, 0.5, 0.502, 0.504,
      0.506, 0.508, 0.51, 0.512, 0.514, 0.516, 0.518, 0.52, 0.522, 0.524, 0.526,
      0.528, 0.53, 0.532, 0.534, 0.536, 0.538, 0.54, 0.542, 0.544, 0.546, 0.548,
      0.55, 0.552, 0.554, 0.556, 0.558, 0.56, 0.562, 0.56400000000000006,
      0.56600000000000006, 0.56800000000000006, 0.57000000000000006,
      0.57200000000000006, 0.57400000000000007, 0.57600000000000007,
      0.57800000000000007, 0.58000000000000007, 0.58200000000000007,
      0.58400000000000007, 0.586, 0.588, 0.59, 0.592, 0.594, 0.596, 0.598, 0.6,
      0.602, 0.604, 0.606, 0.608, 0.61, 0.612, 0.614, 0.616, 0.618, 0.62, 0.622,
      0.624, 0.626, 0.628, 0.63, 0.632, 0.634, 0.636, 0.638, 0.64, 0.642, 0.644,
      0.646, 0.648, 0.65, 0.65199999999999991, 0.65399999999999991,
      0.65599999999999992, 0.65799999999999992, 0.65999999999999992,
      0.66199999999999992, 0.66399999999999992, 0.66599999999999993,
      0.66799999999999993, 0.66999999999999993, 0.67199999999999993,
      0.67399999999999993, 0.67599999999999993, 0.67799999999999994,
      0.67999999999999994, 0.68199999999999994, 0.68399999999999994,
      0.68599999999999994, 0.688, 0.69, 0.692, 0.694, 0.696, 0.698, 0.7, 0.702,
      0.704, 0.706, 0.708, 0.71, 0.712, 0.714, 0.716, 0.718, 0.72, 0.722, 0.724,
      0.726, 0.728, 0.73, 0.732, 0.734, 0.736, 0.738, 0.74, 0.742, 0.744, 0.746,
      0.748, 0.75, 0.752, 0.754, 0.756, 0.758, 0.76, 0.762, 0.764, 0.766, 0.768,
      0.77, 0.772, 0.774, 0.776, 0.778, 0.78, 0.782, 0.784, 0.786, 0.788, 0.79,
      0.792, 0.794, 0.796, 0.798, 0.8, 0.802, 0.804, 0.806, 0.808, 0.81, 0.812,
      0.81400000000000006, 0.81600000000000006, 0.81800000000000006,
      0.82000000000000006, 0.82200000000000006, 0.82400000000000007,
      0.82600000000000007, 0.828, 0.83, 0.832, 0.834, 0.836, 0.838, 0.84, 0.842,
      0.844, 0.846, 0.848, 0.85, 0.852, 0.854, 0.856, 0.858, 0.86, 0.862, 0.864,
      0.866, 0.868, 0.87, 0.872, 0.874, 0.876, 0.878, 0.88, 0.882, 0.884, 0.886,
      0.888, 0.89, 0.892, 0.894, 0.896, 0.898, 0.9, 0.902, 0.904, 0.906, 0.908,
      0.91, 0.912, 0.914, 0.916, 0.918, 0.92, 0.922, 0.924, 0.926, 0.928,
      0.92999999999999994, 0.93199999999999994, 0.93399999999999994,
      0.93599999999999994, 0.938, 0.94, 0.942, 0.944, 0.946, 0.948, 0.95, 0.952,
      0.954, 0.956, 0.958, 0.96, 0.962, 0.964, 0.966, 0.968, 0.97, 0.972, 0.974,
      0.976, 0.978, 0.98, 0.982, 0.984, 0.986, 0.988, 0.99, 0.992, 0.994, 0.996,
      0.998, 1.0 } ;

    static real_T pDataValues0[] = { 1.8518925966685411, 3.7674544396810892,
      3.893295239243769, 4.0160734060271261, 4.1357093552839395,
      4.252123453065483, 4.3652343695202145, 4.4749604584570584,
      4.581216952442972, 4.683919206454668, 4.7829784251252034,
      4.8783046664656187, 4.9698053455441569, 5.0573850450546676,
      5.1409460675675742, 5.2203870748024217, 5.2956060086063141,
      5.36649588620353, 5.4329494344758213, 5.4948558581780462,
      5.5521061468195976, 5.60458508670776, 5.6521777084815081,
      5.6947731981417711, 5.7322588620045369, 5.7645200616630063,
      5.7914473829582906, 5.8129387440147626, 5.8288861005505419,
      5.8391956269335541, 5.843770945941686, 5.842533709386613,
      5.835404683482575, 5.822317324972885, 5.8032151392785938,
      5.778056325077066, 5.7468058394350425, 5.7094447376242385,
      5.6659729757046167, 5.6164020715719705, 5.56075974287251,
      5.4990892962143088, 5.4314526164710992, 5.3579306872570269,
      5.2786230628002571, 5.19364380523059, 5.1031253905819121, 5.0072238059965,
      4.90609926983878, 4.7999409301887157, 4.6889474385753527,
      4.573329310313583, 4.4533201559204754, 4.3291579205363915,
      4.2010870703993195, 4.06937165920897, 3.9342826699027809,
      3.7960906481870738, 3.6550707445584152, 3.5115040521950363,
      3.3656799455802608, 3.2178794573530083, 3.0683835555351475,
      2.9174654829370019, 2.7653995090407046, 2.6124545329498359,
      2.4588888675884, 2.3049578150913095, 2.1508911515378237,
      1.9969280160917324, 1.84329051495927, 1.6901679216024377,
      1.5377821130759326, 1.3863036095730956, 1.2358806677794947,
      1.0866890597039824, 0.938862812311899, 0.79253001757400354,
      0.64779524221204088, 0.50476199933900423, 0.36350613828397321,
      0.22411116445414692, 0.086620767919690034, -0.04891187012914474,
      -0.18245976491342514, -0.31400601162884573, -0.44354292068665574,
      -0.57107352506885734, -0.69660497598760673, -0.82017564108235341,
      -0.94181343967219466, -1.061569272302394, -1.1794838295412944,
      -1.2956307874400195, -1.4100734318230972, -1.5228871349265205,
      -1.6341598576494518, -1.7439788377010712, -1.8524380228371971,
      -1.9596442550694448, -2.0656963981191061, -2.1707075138449614,
      -2.2747933334956545, -2.3780734559005734, -2.4806694140808014,
      -2.5827019719942719, -2.6843045190040948, -2.7856000707135729,
      -2.886725243961862, -2.9878135707985018, -3.0889946135013111,
      -3.1904055679734631, -3.292181669229719, -3.3944586341050691,
      -3.4973685011765481, -3.6010471593431586, -3.7056218504357314,
      -3.8112253871354596, -3.9179820378050176, -4.0260149587242813,
      -4.1354403500035728, -4.246373110846446, -4.3589168433112695,
      -4.4731745620568306, -4.5892322216367445, -4.7071711739735411,
      -4.82705753448463, -4.9489485459288742, -5.0728829100687971,
      -5.1988840861968271, -5.326951921883885, -5.4570679121401016,
      -5.5891869987191312, -5.7232370973515607, -5.8591150189215551,
      -5.9966828192171793, -6.1357653134062806, -6.2761449856701228,
      -6.4175550022026657, -6.5596915300740157, -6.7021898389733936,
      -6.844625493444064, -6.9865305981906314, -7.1273551362062442,
      -7.2665045648130207, -7.4033066584741709, -7.5370368187678789,
      -7.666900665154416, -7.7920548535384322, -7.9115839449485694,
      -8.0245527526973763, -8.1299699061079522, -8.22682589409581,
      -8.3141021947010287, -8.3907818444032127, -8.4559591376724619,
      -8.5088469596651741, -8.5486397982909779, -8.5745391440013368,
      -8.5858346851690985, -8.5819381967533239, -8.5624007340088735,
      -8.5269163558382051, -8.4753486138758163, -8.407705708885544,
      -8.3241790984169768, -8.2251183640524825, -8.1110268012061155,
      -7.9825539902080234, -7.8404745006750316, -7.6856869232983005,
      -7.5191778202500981, -7.3420107728165354, -7.1552985090123435,
      -6.9601940874643029, -6.7578630511868774, -6.5494738632936134,
      -6.3361711236712548, -6.119070123535252, -5.89924760838709,
      -5.6777268423899692, -5.4554568008814863, -5.233361981486973,
      -5.0122512934782142, -4.7929088779784577, -4.5760059493192262,
      -4.3621848652531687, -4.1519910280231738, -3.9459260793047823,
      -3.7444226959724451, -3.5478406854289117, -3.3565237449892438,
      -3.1707128897300181, -2.9906373128214332, -2.8164639883244962,
      -2.648350403993097, -2.4863615731020934, -2.3305947637767561,
      -2.1810717837642106, -2.0377972048387396, -1.9007618914848989,
      -1.7699292692948889, -1.6452327132326261, -1.5265920915448272,
      -1.4139477434048544, -1.3071695958125955, -1.2061511942781493,
      -1.1107782062141114, -1.0208966767543857, -0.93638660753978131,
      -0.85709518822072384, -0.78286582580307518, -0.71353656907358953,
      -0.6489544773683289, -0.58895986855804772, -0.53337126262465306,
      -0.48202879729487647, -0.4347601620609251, -0.39139637086384921,
      -0.35176603420778968, -0.31569361007441227, -0.28299776402555071,
      -0.2535170447596255, -0.22707891978439015, -0.2035062536477304,
      -0.18262921693050602, -0.1642818077529434, -0.14829001921981402,
      -0.1344888697173707, -0.1227059861585709, -0.11278118468403782,
      -0.10454839456295469, -0.097842409700053992, -0.092502681021728386,
      -0.088369254524991073, -0.0852833542053424, -0.0830871217080752,
      -0.081624668775361425, -0.080743252019863543, -0.080289750493103246,
      -0.080113013147966955, -0.080064290405105168, -0.079996478273129251,
      -0.079763619238315486, -0.079222282497724561, -0.078230564723067011,
      -0.076648224876383633, -0.074336907793321291, -0.071160442812589847,
      -0.0669837881589685, -0.0616752744177408, -0.05510489231482768,
      -0.047143250528384639, -0.0376625621504292, -0.026540854719858165,
      -0.013654952750391726, 0.0011160543618378704, 0.017889599555536723,
      0.0367839670126073, 0.057912082240134131, 0.081389789778710073,
      0.1073207001520466, 0.13581703158073455, 0.16699418913236891,
      0.20093489617379287, 0.23776884932112427, 0.27757912248634015,
      0.32048552504444267, 0.36657157556158215, 0.41594403069124547,
      0.4686919428329081, 0.52492884662080919, 0.58474356911685854,
      0.64823498918997224, 0.71549625579599485, 0.78663717562450408,
      0.86174770734309181, 0.94092950116555274, 1.0242800961019989,
      1.1119115148861469, 1.2039070326110155, 1.3004037080311384,
      1.4014982209001137, 1.5072935688350246, 1.6179086076689082,
      1.7334479652644774, 1.8540429557740359, 1.9797988645857618,
      2.1108437196629724, 2.2472800866119771, 2.389233885782418,
      2.5368308609845296, 2.6901358405713323, 2.8492897665088179,
      3.0143623456732991, 3.185431734423104, 3.3625408192127937,
      3.5457343007239737, 3.7350009301247651, 3.9302845109733191,
      4.1315104597024259, 4.3385187815878732, 4.5510733306211266,
      4.7688544886211641, 4.991450738081844, 5.2183255209626367,
      5.4487982008899127, 5.682023489659735, 5.9169694351172266,
      6.152433680322698, 6.3869708397698632, 6.6188984671785445,
      6.8463012173322531, 7.0670254730124782, 7.2786762010106045,
      7.4786754523761463, 7.6642151975146966, 7.8324174718301149,
      7.9803341377221866, 8.1050887646427583, 8.203922179897269,
      8.2743309365721149, 8.3142807349452337, 8.3222559012893438,
      8.2972374742900659, 8.2387440296384415, 8.146885469823351,
      8.0224608609060475, 7.866865036787364, 7.6820090162108441,
      7.4702893338064049, 7.2344246275185649, 6.97737574983557,
      6.7022376653993057, 6.4121506950237466, 6.1101475901415361,
      5.7991951954798218, 5.4820182590735387, 5.1611910177949794,
      4.8389678545492636, 4.51741256474359, 4.1982820940150853,
      3.8831460897656704, 3.573283241622518, 3.2698188846680987,
      2.9735699691930719, 2.6853798934925859, 2.4057130049115281,
      2.1350057850332322, 1.873575168137364, 1.6216415800664739,
      1.3793118891189533, 1.1466223939590707, 0.9235283341181264,
      0.7100040841993952, 0.50588700385213992, 0.31108582045109245,
      0.1253766948618345, -0.051379492678985471, -0.21946111124572598,
      -0.379061623079577, -0.5303920573426375, -0.67373809848149546,
      -0.80933145772248472, -0.937370050771574, -1.0581705709939873,
      -1.1719236692333883, -1.2788923584292269, -1.3793088089322492,
      -1.47343106095576, -1.5614402828358758, -1.6436113460557158,
      -1.7201338463831446, -1.7912340014742802, -1.8571268501242966,
      -1.9180023900615997, -1.9740712423716811, -2.0255249214780422,
      -2.072547813223915, -2.1153213486678961, -2.1540356322047,
      -2.1888555405223751, -2.2199371915974786, -2.2474648201579703,
      -2.2715875786270852, -2.2924586789860504, -2.3102249844668661,
      -2.3250380669209072, -2.3370350363104571, -2.3463472033355832,
      -2.3531043041740105, -2.3574487901265524, -2.3594884156731704,
      -2.3593531453707408, -2.357153938705483, -2.3530008347098654,
      -2.3470029939393133, -2.3392716521674917, -2.3298964408585885,
      -2.318980790086143, -2.3066210393269126, -2.292900713843455,
      -2.2779121343884765, -2.2617363888093847, -2.2444548349560383,
      -2.2261444434731024, -2.2068794512797751, -2.1867321906191641,
      -2.1657663309622954, -2.1440511371287414, -2.1216467450139129,
      -2.098615457339819, -2.0750102906312464, -2.0508892765196509,
      -2.0262972518786837, -2.0012871177943854, -1.9759074576642575,
      -1.9501989892094291, -1.9242025798584796, -1.8979610993857849,
      -1.8715070650999652, -1.8448789664612057, -1.8181076516517203,
      -1.7912271523680459, -1.7642601468638821, -1.7372405220182126,
      -1.7101882987485819, -1.6831288767661048, -1.6560847689222955,
      -1.6290763746916583, -1.6021200499899442, -1.5752348108062686,
      -1.5484366575227015, -1.5217382132513135, -1.4951548182327619,
      -1.4686948644857132, -1.4423733117168072, -1.4161964904933562,
      -1.3901740298963943, -1.3643127418665353, -1.3386200020715864,
      -1.313099653813661, -1.2877572537217559, -1.2625966296550675,
      -1.2376199417189255, -1.2128292371433571, -1.1882269842943429,
      -1.1638133644216055, -1.1395874655777387, -1.115550456225108,
      -1.0916997307230765, -1.0680342436947516, -1.0445516838272046,
      -1.0212494222294024, -0.998123838414395, -0.97517205568371379,
      -0.95238938021768682, -0.92977226596434559, -0.907315276616566,
      -0.88501338031059229, -0.862861133386563, -0.840853406668819,
      -0.81898349436354467, -0.7972451831154983, -0.775632287815704,
      -0.75413793068677026, -0.73275462733418373, -0.7114758758077051,
      -0.69029390058708517, -0.66920095722634887, -0.64818978370622682,
      -0.62725171443128658, -0.60637931048278138, -0.58556376528687049,
      -0.56479688156124941, -0.54407007570859478, -0.5233747952011516,
      -0.50270177060789567, -0.48204242187888185, -0.46138751170274239,
      -0.44072794911776109, -0.4200542635904399, -0.39935724141670648,
      -0.37862746275560794, -0.35785502185202328, -0.33703042187776694,
      -0.316143596747885, -0.29518458827700494, -0.27414367928241068,
      -0.25301064303462684, -0.23177517136678927, -0.21042747021101477,
      -0.18895603034788647, -0.16735169976873407, -0.14560298173863626,
      -0.1236992901355191, -0.1016298765135258, -0.079383998086453744,
      -0.056949677934236817, -0.034316171600520064, -0.011471545697706483 } ;

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
  Swingup_test_M->Sizes.checksums[0] = (2606222410U);
  Swingup_test_M->Sizes.checksums[1] = (2250098342U);
  Swingup_test_M->Sizes.checksums[2] = (4061169052U);
  Swingup_test_M->Sizes.checksums[3] = (633094695U);

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
    Swingup_test_B.TransferFcn1 = 0.0;
    Swingup_test_B.countstorad = 0.0;
    Swingup_test_B.Add1 = 0.0;
    Swingup_test_B.FromWorkspace = 0.0;
    Swingup_test_B.Gain2 = 0.0;
    Swingup_test_B.Saturation1 = 0.0;
    Swingup_test_B.Gain = 0.0;
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
  Swingup_test_M->Sizes.numBlocks = (57);/* Number of blocks */
  Swingup_test_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  Swingup_test_M->Sizes.numBlockPrms = (114);/* Sum of parameter "widths" */
  return Swingup_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
