/*
 * Test_LQR.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Test_LQR".
 *
 * Model version              : 9.13
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Oct 19 18:42:33 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Test_LQR.h"
#include "rtwtypes.h"
#include <math.h>
#include "Test_LQR_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Test_LQR_dt.h"

/* Block signals (default storage) */
B_Test_LQR_T Test_LQR_B;

/* Block states (default storage) */
DW_Test_LQR_T Test_LQR_DW;

/* Real-time model */
static RT_MODEL_Test_LQR_T Test_LQR_M_;
RT_MODEL_Test_LQR_T *const Test_LQR_M = &Test_LQR_M_;

/* Model output function */
void Test_LQR_output(void)
{
  real_T rtb_Derivative1;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_HILReadEncoderTimebase;
  real_T tmp;
  real_T *lastU;
  boolean_T rtb_RelationalOperator1;

  /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Test_LQR/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_read_encoder(Test_LQR_DW.HILReadEncoderTimebase_Task, 1,
      &Test_LQR_DW.HILReadEncoderTimebase_Buffer);
    if (result < 0) {
      rtb_HILReadEncoderTimebase = 0;
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
    } else {
      rtb_HILReadEncoderTimebase = Test_LQR_DW.HILReadEncoderTimebase_Buffer;
    }
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: Test_LQR/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(Test_LQR_DW.HILInitialize_Card,
      &Test_LQR_P.HILReadEncoder_channels, 1, &Test_LQR_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
    } else {
      rtb_DiscreteTimeIntegrator = Test_LQR_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/counts to rad1' */
  Test_LQR_B.countstorad1 = Test_LQR_P.countstorad1_Gain *
    rtb_DiscreteTimeIntegrator;

  /* Derivative: '<Root>/Derivative1' incorporates:
   *  Derivative: '<Root>/Derivative'
   */
  tmp = Test_LQR_M->Timing.t[0];
  if ((Test_LQR_DW.TimeStampA >= tmp) && (Test_LQR_DW.TimeStampB >= tmp)) {
    rtb_Derivative1 = 0.0;
  } else {
    rtb_Derivative1 = Test_LQR_DW.TimeStampA;
    lastU = &Test_LQR_DW.LastUAtTimeA;
    if (Test_LQR_DW.TimeStampA < Test_LQR_DW.TimeStampB) {
      if (Test_LQR_DW.TimeStampB < tmp) {
        rtb_Derivative1 = Test_LQR_DW.TimeStampB;
        lastU = &Test_LQR_DW.LastUAtTimeB;
      }
    } else if (Test_LQR_DW.TimeStampA >= tmp) {
      rtb_Derivative1 = Test_LQR_DW.TimeStampB;
      lastU = &Test_LQR_DW.LastUAtTimeB;
    }

    rtb_Derivative1 = (Test_LQR_B.countstorad1 - *lastU) / (tmp -
      rtb_Derivative1);
  }

  /* End of Derivative: '<Root>/Derivative1' */

  /* Gain: '<Root>/Gain' */
  Test_LQR_B.Gain = Test_LQR_P.Gain_Gain * rtb_Derivative1;

  /* Gain: '<Root>/counts to rad' */
  Test_LQR_B.countstorad = Test_LQR_P.countstorad_Gain *
    rtb_HILReadEncoderTimebase;

  /* Derivative: '<Root>/Derivative' */
  if ((Test_LQR_DW.TimeStampA_j >= tmp) && (Test_LQR_DW.TimeStampB_a >= tmp)) {
    rtb_HILReadEncoderTimebase = 0.0;
  } else {
    rtb_Derivative1 = Test_LQR_DW.TimeStampA_j;
    lastU = &Test_LQR_DW.LastUAtTimeA_m;
    if (Test_LQR_DW.TimeStampA_j < Test_LQR_DW.TimeStampB_a) {
      if (Test_LQR_DW.TimeStampB_a < tmp) {
        rtb_Derivative1 = Test_LQR_DW.TimeStampB_a;
        lastU = &Test_LQR_DW.LastUAtTimeB_p;
      }
    } else if (Test_LQR_DW.TimeStampA_j >= tmp) {
      rtb_Derivative1 = Test_LQR_DW.TimeStampB_a;
      lastU = &Test_LQR_DW.LastUAtTimeB_p;
    }

    rtb_HILReadEncoderTimebase = (Test_LQR_B.countstorad - *lastU) / (tmp -
      rtb_Derivative1);
  }

  /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */
  /* MATLAB Function 'MATLAB Function': '<S2>:1' */
  /* '<S2>:1:4' */
  /* S-Function Block: Test_LQR/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T w = TWO_PI * Test_LQR_P.SmoothSignalGenerator_Frequency;
    boolean_T params_changed = (Test_LQR_P.SmoothSignalGenerator_Amplitude !=
      Test_LQR_DW.SmoothSignalGenerator_RWORK.Amp || w !=
      Test_LQR_DW.SmoothSignalGenerator_RWORK.W);

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
    real_T y_sin = Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
    real_T y_cos = Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

    /* Produce the output(s) */
    rtb_DiscreteTimeIntegrator = Test_LQR_DW.SmoothSignalGenerator_RWORK.Amp *
      y_sin;

    /* Compute the new sin and cos values */
    Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
      Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
      Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
    Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
      Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
      Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

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
      if (y_sin == 0 || Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t == 0 ||
          (y_sin < 0) != (Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t < 0))
      {
        if (fabs(Test_LQR_DW.SmoothSignalGenerator_RWORK.Amp *
                 Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t) <
            Test_LQR_P.SmoothSignalGenerator_Amplitude) {
          x = asin(Test_LQR_DW.SmoothSignalGenerator_RWORK.Amp *
                   Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t /
                   Test_LQR_P.SmoothSignalGenerator_Amplitude);
          Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(w * 0.0005);
          Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(w * 0.0005);
          Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

          /*
             There are always two solutions for the phase. Choose the solution
             that matches the slope as well as the amplitude.
           */
          if ((cos(x) < 0) != (Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t <
                               0)) {
            Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -cos(x);
          } else {
            Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos(x);
          }
        } else {
          /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
          x = w * 0.0005;
          Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

          /* Make sure cosine output is also continuous */
          if (Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0) {
            Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
          } else {
            Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
          }

          Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(x);
          Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(x);
        }

        Test_LQR_DW.SmoothSignalGenerator_RWORK.Amp =
          Test_LQR_P.SmoothSignalGenerator_Amplitude;
        Test_LQR_DW.SmoothSignalGenerator_RWORK.W = w;
      }
    }
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  Gain: '<Root>/Amplitude (deg)'
   */
  Test_LQR_B.Gain1 = Test_LQR_P.Amplitudedeg_Gain * rtb_DiscreteTimeIntegrator *
    Test_LQR_P.Gain1_Gain_a;

  /* Sum: '<Root>/Add' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain1'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  SignalConversion generated from: '<Root>/Vector Concatenate'
   * */
  Test_LQR_B.Add = Test_LQR_B.Gain1 - (((Test_LQR_P.Gain1_Gain * Test_LQR_B.Gain
    * Test_LQR_P.K_pp[0] + Test_LQR_P.K_pp[1] * rtb_HILReadEncoderTimebase) +
    Test_LQR_P.K_pp[2] * Test_LQR_B.countstorad1) + Test_LQR_P.K_pp[3] *
    Test_LQR_B.countstorad);

  /* Saturate: '<Root>/Saturation' */
  if (Test_LQR_B.Add > Test_LQR_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    Test_LQR_B.Saturation = Test_LQR_P.Saturation_UpperSat;
  } else if (Test_LQR_B.Add < Test_LQR_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    Test_LQR_B.Saturation = Test_LQR_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    Test_LQR_B.Saturation = Test_LQR_B.Add;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Test_LQR/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Test_LQR_DW.HILInitialize_Card,
      &Test_LQR_P.HILWriteAnalog_channels, 1, &Test_LQR_B.Saturation);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
    }
  }

  /* Gain: '<S4>/Gain' */
  Test_LQR_B.Gain_n = Test_LQR_P.Gain_Gain_k * Test_LQR_B.countstorad1;

  /* Gain: '<S3>/Gain' */
  Test_LQR_B.Gain_f[0] = Test_LQR_P.Gain_Gain_a * Test_LQR_B.Gain1;
  Test_LQR_B.Gain_f[1] = Test_LQR_P.Gain_Gain_a * Test_LQR_B.countstorad;

  /* Abs: '<S6>/Abs' */
  rtb_DiscreteTimeIntegrator = fabs(Test_LQR_B.Saturation);

  /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
   *  Constant: '<S6>/control threshold'
   */
  rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
    Test_LQR_P.StallMonitor_control_threshold);

  /* Abs: '<S6>/Abs1' */
  rtb_DiscreteTimeIntegrator = fabs(Test_LQR_B.Gain);

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S6>/motion threshold'
   *  RelationalOperator: '<S6>/Relational Operator'
   */
  rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
    (rtb_DiscreteTimeIntegrator <= Test_LQR_P.StallMonitor_motion_threshold));

  /* Logic: '<S6>/Logical Operator1' */
  Test_LQR_B.LogicalOperator1 = !rtb_RelationalOperator1;

  /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  if (Test_LQR_B.LogicalOperator1 &&
      (Test_LQR_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    Test_LQR_DW.DiscreteTimeIntegrator_DSTATE =
      Test_LQR_P.DiscreteTimeIntegrator_IC;
  }

  rtb_DiscreteTimeIntegrator = Test_LQR_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */

  /* RelationalOperator: '<S6>/Relational Operator2' incorporates:
   *  Constant: '<S6>/control threshold1'
   */
  Test_LQR_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
    Test_LQR_P.StallMonitor_duration_s);

  /* Stop: '<S7>/Stop Simulation' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   */
  if (Test_LQR_B.RelationalOperator2 != Test_LQR_P.Constant_Value) {
    rtmSetStopRequested(Test_LQR_M, 1);
  }

  /* End of Stop: '<S7>/Stop Simulation' */

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  Test_LQR_B.DataTypeConversion = rtb_RelationalOperator1;
}

/* Model update function */
void Test_LQR_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative1' */
  if (Test_LQR_DW.TimeStampA == (rtInf)) {
    Test_LQR_DW.TimeStampA = Test_LQR_M->Timing.t[0];
    lastU = &Test_LQR_DW.LastUAtTimeA;
  } else if (Test_LQR_DW.TimeStampB == (rtInf)) {
    Test_LQR_DW.TimeStampB = Test_LQR_M->Timing.t[0];
    lastU = &Test_LQR_DW.LastUAtTimeB;
  } else if (Test_LQR_DW.TimeStampA < Test_LQR_DW.TimeStampB) {
    Test_LQR_DW.TimeStampA = Test_LQR_M->Timing.t[0];
    lastU = &Test_LQR_DW.LastUAtTimeA;
  } else {
    Test_LQR_DW.TimeStampB = Test_LQR_M->Timing.t[0];
    lastU = &Test_LQR_DW.LastUAtTimeB;
  }

  *lastU = Test_LQR_B.countstorad1;

  /* End of Update for Derivative: '<Root>/Derivative1' */

  /* Update for Derivative: '<Root>/Derivative' */
  if (Test_LQR_DW.TimeStampA_j == (rtInf)) {
    Test_LQR_DW.TimeStampA_j = Test_LQR_M->Timing.t[0];
    lastU = &Test_LQR_DW.LastUAtTimeA_m;
  } else if (Test_LQR_DW.TimeStampB_a == (rtInf)) {
    Test_LQR_DW.TimeStampB_a = Test_LQR_M->Timing.t[0];
    lastU = &Test_LQR_DW.LastUAtTimeB_p;
  } else if (Test_LQR_DW.TimeStampA_j < Test_LQR_DW.TimeStampB_a) {
    Test_LQR_DW.TimeStampA_j = Test_LQR_M->Timing.t[0];
    lastU = &Test_LQR_DW.LastUAtTimeA_m;
  } else {
    Test_LQR_DW.TimeStampB_a = Test_LQR_M->Timing.t[0];
    lastU = &Test_LQR_DW.LastUAtTimeB_p;
  }

  *lastU = Test_LQR_B.countstorad;

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  Test_LQR_DW.DiscreteTimeIntegrator_DSTATE +=
    Test_LQR_P.DiscreteTimeIntegrator_gainval * Test_LQR_B.DataTypeConversion;
  Test_LQR_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    Test_LQR_B.LogicalOperator1;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Test_LQR_M->Timing.clockTick0)) {
    ++Test_LQR_M->Timing.clockTickH0;
  }

  Test_LQR_M->Timing.t[0] = Test_LQR_M->Timing.clockTick0 *
    Test_LQR_M->Timing.stepSize0 + Test_LQR_M->Timing.clockTickH0 *
    Test_LQR_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++Test_LQR_M->Timing.clockTick1)) {
      ++Test_LQR_M->Timing.clockTickH1;
    }

    Test_LQR_M->Timing.t[1] = Test_LQR_M->Timing.clockTick1 *
      Test_LQR_M->Timing.stepSize1 + Test_LQR_M->Timing.clockTickH1 *
      Test_LQR_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Test_LQR_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Test_LQR/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0", &Test_LQR_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Test_LQR_DW.HILInitialize_Card, " ",
      2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Test_LQR_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
      return;
    }

    if ((Test_LQR_P.HILInitialize_AIPStart && !is_switching) ||
        (Test_LQR_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Test_LQR_DW.HILInitialize_Card,
        &Test_LQR_P.HILInitialize_AIChannels, 1U,
        &Test_LQR_P.HILInitialize_AILow, &Test_LQR_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((Test_LQR_P.HILInitialize_AOPStart && !is_switching) ||
        (Test_LQR_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Test_LQR_DW.HILInitialize_Card,
        &Test_LQR_P.HILInitialize_AOChannels, 1U,
        &Test_LQR_P.HILInitialize_AOLow, &Test_LQR_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((Test_LQR_P.HILInitialize_AOStart && !is_switching) ||
        (Test_LQR_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Test_LQR_DW.HILInitialize_Card,
        &Test_LQR_P.HILInitialize_AOChannels, 1U,
        &Test_LQR_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }

    if (Test_LQR_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Test_LQR_DW.HILInitialize_Card, &Test_LQR_P.HILInitialize_AOChannels,
         1U, &Test_LQR_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Test_LQR_DW.HILInitialize_Card, NULL, 0U,
      &Test_LQR_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
      return;
    }

    if ((Test_LQR_P.HILInitialize_DOStart && !is_switching) ||
        (Test_LQR_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Test_LQR_DW.HILInitialize_Card,
        &Test_LQR_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Test_LQR_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }

    if (Test_LQR_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Test_LQR_DW.HILInitialize_Card, &Test_LQR_P.HILInitialize_DOChannels,
         1U, (const t_digital_state *) &Test_LQR_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((Test_LQR_P.HILInitialize_EIPStart && !is_switching) ||
        (Test_LQR_P.HILInitialize_EIPEnter && is_switching)) {
      Test_LQR_DW.HILInitialize_QuadratureModes[0] =
        Test_LQR_P.HILInitialize_EIQuadrature;
      Test_LQR_DW.HILInitialize_QuadratureModes[1] =
        Test_LQR_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(Test_LQR_DW.HILInitialize_Card,
        Test_LQR_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &Test_LQR_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((Test_LQR_P.HILInitialize_EIStart && !is_switching) ||
        (Test_LQR_P.HILInitialize_EIEnter && is_switching)) {
      Test_LQR_DW.HILInitialize_InitialEICounts[0] =
        Test_LQR_P.HILInitialize_EIInitial;
      Test_LQR_DW.HILInitialize_InitialEICounts[1] =
        Test_LQR_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Test_LQR_DW.HILInitialize_Card,
        Test_LQR_P.HILInitialize_EIChannels, 2U,
        &Test_LQR_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }

    if ((Test_LQR_P.HILInitialize_OOStart && !is_switching) ||
        (Test_LQR_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Test_LQR_DW.HILInitialize_Card,
        Test_LQR_P.HILInitialize_OOChannels, 3U,
        Test_LQR_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }

    if (Test_LQR_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Test_LQR_DW.HILInitialize_Card, Test_LQR_P.HILInitialize_OOChannels, 3U,
         Test_LQR_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Test_LQR/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Test_LQR_DW.HILInitialize_Card,
      Test_LQR_P.HILReadEncoderTimebase_SamplesI,
      &Test_LQR_P.HILReadEncoderTimebase_Channels, 1,
      &Test_LQR_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Test_LQR_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Test_LQR_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */

  /* S-Function Block: Test_LQR/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / Test_LQR_P.SmoothSignalGenerator_Frequency;
    Test_LQR_DW.SmoothSignalGenerator_RWORK.Amp =
      Test_LQR_P.SmoothSignalGenerator_Amplitude;
    Test_LQR_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      Test_LQR_P.SmoothSignalGenerator_Frequency;
    Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (Test_LQR_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (Test_LQR_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (Test_LQR_P.SmoothSignalGenerator_InitialPh);
    Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (Test_LQR_P.SmoothSignalGenerator_InitialPh);
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  Test_LQR_DW.TimeStampA = (rtInf);
  Test_LQR_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Test_LQR_DW.TimeStampA_j = (rtInf);
  Test_LQR_DW.TimeStampB_a = (rtInf);

  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  Test_LQR_DW.DiscreteTimeIntegrator_DSTATE =
    Test_LQR_P.DiscreteTimeIntegrator_IC;
  Test_LQR_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void Test_LQR_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Test_LQR/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Test_LQR_DW.HILInitialize_Card);
    hil_monitor_stop_all(Test_LQR_DW.HILInitialize_Card);
    is_switching = false;
    if ((Test_LQR_P.HILInitialize_AOTerminate && !is_switching) ||
        (Test_LQR_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Test_LQR_P.HILInitialize_DOTerminate && !is_switching) ||
        (Test_LQR_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Test_LQR_P.HILInitialize_OOTerminate && !is_switching) ||
        (Test_LQR_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Test_LQR_DW.HILInitialize_Card
                         , &Test_LQR_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Test_LQR_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Test_LQR_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Test_LQR_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Test_LQR_P.HILInitialize_DOFinal
                         , Test_LQR_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Test_LQR_DW.HILInitialize_Card,
            &Test_LQR_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Test_LQR_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Test_LQR_DW.HILInitialize_Card,
            &Test_LQR_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Test_LQR_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Test_LQR_DW.HILInitialize_Card,
            Test_LQR_P.HILInitialize_OOChannels, num_final_other_outputs,
            Test_LQR_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Test_LQR_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Test_LQR_DW.HILInitialize_Card);
    hil_monitor_delete_all(Test_LQR_DW.HILInitialize_Card);
    hil_close(Test_LQR_DW.HILInitialize_Card);
    Test_LQR_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Test_LQR_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Test_LQR_update();
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
  Test_LQR_initialize();
}

void MdlTerminate(void)
{
  Test_LQR_terminate();
}

/* Registration function */
RT_MODEL_Test_LQR_T *Test_LQR(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Test_LQR_M, 0,
                sizeof(RT_MODEL_Test_LQR_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Test_LQR_M->solverInfo,
                          &Test_LQR_M->Timing.simTimeStep);
    rtsiSetTPtr(&Test_LQR_M->solverInfo, &rtmGetTPtr(Test_LQR_M));
    rtsiSetStepSizePtr(&Test_LQR_M->solverInfo, &Test_LQR_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Test_LQR_M->solverInfo, (&rtmGetErrorStatus
      (Test_LQR_M)));
    rtsiSetRTModelPtr(&Test_LQR_M->solverInfo, Test_LQR_M);
  }

  rtsiSetSimTimeStep(&Test_LQR_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Test_LQR_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Test_LQR_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Test_LQR_M points to
       static memory which is guaranteed to be non-NULL" */
    Test_LQR_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Test_LQR_M->Timing.sampleTimes = (&Test_LQR_M->Timing.sampleTimesArray[0]);
    Test_LQR_M->Timing.offsetTimes = (&Test_LQR_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Test_LQR_M->Timing.sampleTimes[0] = (0.0);
    Test_LQR_M->Timing.sampleTimes[1] = (0.0005);

    /* task offsets */
    Test_LQR_M->Timing.offsetTimes[0] = (0.0);
    Test_LQR_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Test_LQR_M, &Test_LQR_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Test_LQR_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Test_LQR_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Test_LQR_M, -1);
  Test_LQR_M->Timing.stepSize0 = 0.0005;
  Test_LQR_M->Timing.stepSize1 = 0.0005;

  /* External mode info */
  Test_LQR_M->Sizes.checksums[0] = (3629708661U);
  Test_LQR_M->Sizes.checksums[1] = (1054634547U);
  Test_LQR_M->Sizes.checksums[2] = (705549715U);
  Test_LQR_M->Sizes.checksums[3] = (3594978772U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Test_LQR_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Test_LQR_M->extModeInfo,
      &Test_LQR_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Test_LQR_M->extModeInfo, Test_LQR_M->Sizes.checksums);
    rteiSetTPtr(Test_LQR_M->extModeInfo, rtmGetTPtr(Test_LQR_M));
  }

  Test_LQR_M->solverInfoPtr = (&Test_LQR_M->solverInfo);
  Test_LQR_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&Test_LQR_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&Test_LQR_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Test_LQR_M->blockIO = ((void *) &Test_LQR_B);
  (void) memset(((void *) &Test_LQR_B), 0,
                sizeof(B_Test_LQR_T));

  {
    Test_LQR_B.countstorad1 = 0.0;
    Test_LQR_B.Gain = 0.0;
    Test_LQR_B.countstorad = 0.0;
    Test_LQR_B.Gain1 = 0.0;
    Test_LQR_B.Add = 0.0;
    Test_LQR_B.Saturation = 0.0;
    Test_LQR_B.Gain_n = 0.0;
    Test_LQR_B.Gain_f[0] = 0.0;
    Test_LQR_B.Gain_f[1] = 0.0;
    Test_LQR_B.DataTypeConversion = 0.0;
  }

  /* parameters */
  Test_LQR_M->defaultParam = ((real_T *)&Test_LQR_P);

  /* states (dwork) */
  Test_LQR_M->dwork = ((void *) &Test_LQR_DW);
  (void) memset((void *)&Test_LQR_DW, 0,
                sizeof(DW_Test_LQR_T));
  Test_LQR_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  Test_LQR_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Test_LQR_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Test_LQR_DW.TimeStampA = 0.0;
  Test_LQR_DW.LastUAtTimeA = 0.0;
  Test_LQR_DW.TimeStampB = 0.0;
  Test_LQR_DW.LastUAtTimeB = 0.0;
  Test_LQR_DW.TimeStampA_j = 0.0;
  Test_LQR_DW.LastUAtTimeA_m = 0.0;
  Test_LQR_DW.TimeStampB_a = 0.0;
  Test_LQR_DW.LastUAtTimeB_p = 0.0;
  Test_LQR_DW.SmoothSignalGenerator_RWORK.Amp = 0.0;
  Test_LQR_DW.SmoothSignalGenerator_RWORK.W = 0.0;
  Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = 0.0;
  Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = 0.0;
  Test_LQR_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0.0;
  Test_LQR_DW.SmoothSignalGenerator_RWORK.Cos_w_t = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Test_LQR_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Test_LQR_M->Sizes.numContStates = (0);/* Number of continuous states */
  Test_LQR_M->Sizes.numY = (0);        /* Number of model outputs */
  Test_LQR_M->Sizes.numU = (0);        /* Number of model inputs */
  Test_LQR_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Test_LQR_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Test_LQR_M->Sizes.numBlocks = (47);  /* Number of blocks */
  Test_LQR_M->Sizes.numBlockIO = (11); /* Number of block outputs */
  Test_LQR_M->Sizes.numBlockPrms = (100);/* Sum of parameter "widths" */
  return Test_LQR_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
