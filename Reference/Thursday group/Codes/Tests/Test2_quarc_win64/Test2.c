/*
 * Test2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Test2".
 *
 * Model version              : 9.4
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Sep 28 18:39:01 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Test2.h"
#include "rtwtypes.h"
#include <math.h>
#include "Test2_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Test2_dt.h"

/* Block signals (default storage) */
B_Test2_T Test2_B;

/* Continuous states */
X_Test2_T Test2_X;

/* Block states (default storage) */
DW_Test2_T Test2_DW;

/* Real-time model */
static RT_MODEL_Test2_T Test2_M_;
RT_MODEL_Test2_T *const Test2_M = &Test2_M_;

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
  Test2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Test2_output(void)
{
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_Saturation;
  real_T rtb_countstorad;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(Test2_M)) {
    /* set solver stop time */
    if (!(Test2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Test2_M->solverInfo, ((Test2_M->Timing.clockTickH0
        + 1) * Test2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Test2_M->solverInfo, ((Test2_M->Timing.clockTick0 +
        1) * Test2_M->Timing.stepSize0 + Test2_M->Timing.clockTickH0 *
        Test2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Test2_M)) {
    Test2_M->Timing.t[0] = rtsiGetT(&Test2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Test2_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: Test2/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(Test2_DW.HILReadEncoderTimebase_Task, 1,
        &Test2_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        rtb_countstorad = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
      } else {
        rtb_countstorad = Test2_DW.HILReadEncoderTimebase_Buffer;
      }
    }

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */
    /* S-Function Block: Test2/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * Test2_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed = (Test2_P.SmoothSignalGenerator_Amplitude !=
        Test2_DW.SmoothSignalGenerator_RWORK.Amp || w !=
        Test2_DW.SmoothSignalGenerator_RWORK.W);

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
      real_T y_sin = Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos = Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_Saturation = Test2_DW.SmoothSignalGenerator_RWORK.Amp * y_sin;

      /* Compute the new sin and cos values */
      Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
        Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
        Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
        Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
        Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

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
        if (y_sin == 0 || Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t == 0 ||
            (y_sin < 0) != (Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t < 0)) {
          if (fabs(Test2_DW.SmoothSignalGenerator_RWORK.Amp *
                   Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t) <
              Test2_P.SmoothSignalGenerator_Amplitude) {
            x = asin(Test2_DW.SmoothSignalGenerator_RWORK.Amp *
                     Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t /
                     Test2_P.SmoothSignalGenerator_Amplitude);
            Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(w * 0.002);
            Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(w * 0.002);
            Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) != (Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t <
                                 0)) {
              Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -cos(x);
            } else {
              Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.002;
            Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0) {
              Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
            } else {
              Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
            }

            Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(x);
            Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(x);
          }

          Test2_DW.SmoothSignalGenerator_RWORK.Amp =
            Test2_P.SmoothSignalGenerator_Amplitude;
          Test2_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }

    /* Gain: '<S1>/Gain1' incorporates:
     *  Gain: '<Root>/Amplitude (deg)'
     */
    rtb_Saturation = Test2_P.Amplitudedeg_Gain * rtb_Saturation *
      Test2_P.Gain1_Gain;

    /* Gain: '<Root>/counts to rad' */
    rtb_countstorad *= Test2_P.countstorad_Gain;

    /* Gain: '<S4>/Slider Gain' incorporates:
     *  Sum: '<Root>/Sum'
     */
    Test2_B.SliderGain = (rtb_Saturation - rtb_countstorad) *
      Test2_P.ProportionalGain_gain;

    /* Gain: '<Root>/Negative Feedback' */
    Test2_B.NegativeFeedback = Test2_P.NegativeFeedback_Gain * rtb_countstorad;
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<S3>/Slider Gain'
   *  TransferFcn: '<Root>/Servo Velocity'
   */
  Test2_B.Sum1 = (Test2_P.ServoVelocity_C * Test2_X.ServoVelocity_CSTATE +
                  Test2_P.ServoVelocity_D * Test2_B.NegativeFeedback) *
    Test2_P.DerivativeGain_gain + Test2_B.SliderGain;
  if (rtmIsMajorTimeStep(Test2_M)) {
    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: Test2/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Test2_DW.HILInitialize_Card,
        &Test2_P.HILReadEncoder_channels, 1, &Test2_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
      } else {
        rtb_DiscreteTimeIntegrator = Test2_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/counts to rad1' */
    rtb_DiscreteTimeIntegrator *= Test2_P.countstorad1_Gain;

    /* Gain: '<S6>/Gain' */
    Test2_B.Gain = Test2_P.Gain_Gain * rtb_DiscreteTimeIntegrator;

    /* Gain: '<S5>/Gain' */
    Test2_B.Gain_f[0] = Test2_P.Gain_Gain_a * rtb_Saturation;
    Test2_B.Gain_f[1] = Test2_P.Gain_Gain_a * rtb_countstorad;

    /* Abs: '<S8>/Abs' */
    rtb_Saturation = fabs(Test2_B.Sum1);

    /* RelationalOperator: '<S8>/Relational Operator1' incorporates:
     *  Constant: '<S8>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_Saturation >=
      Test2_P.StallMonitor_control_threshold);

    /* Gain: '<Root>/Negative Feedback1' */
    Test2_B.NegativeFeedback1 = Test2_P.NegativeFeedback1_Gain *
      rtb_DiscreteTimeIntegrator;
  }

  /* TransferFcn: '<Root>/Servo Velocity1' */
  Test2_B.ServoVelocity1 = Test2_P.ServoVelocity1_C *
    Test2_X.ServoVelocity1_CSTATE;
  Test2_B.ServoVelocity1 += Test2_P.ServoVelocity1_D * Test2_B.NegativeFeedback1;
  if (rtmIsMajorTimeStep(Test2_M)) {
    /* Abs: '<S8>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(Test2_B.ServoVelocity1);

    /* Logic: '<S8>/Logical Operator' incorporates:
     *  Constant: '<S8>/motion threshold'
     *  RelationalOperator: '<S8>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <= Test2_P.StallMonitor_motion_threshold));

    /* Logic: '<S8>/Logical Operator1' */
    Test2_B.LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    if (Test2_B.LogicalOperator1 && (Test2_DW.DiscreteTimeIntegrator_PrevRese <=
         0)) {
      Test2_DW.DiscreteTimeIntegrator_DSTATE = Test2_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator = Test2_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S8>/Relational Operator2' incorporates:
     *  Constant: '<S8>/control threshold1'
     */
    Test2_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
      Test2_P.StallMonitor_duration_s);

    /* Stop: '<S9>/Stop Simulation' incorporates:
     *  Constant: '<S10>/Constant'
     *  RelationalOperator: '<S10>/Compare'
     */
    if (Test2_B.RelationalOperator2 != Test2_P.Constant_Value) {
      rtmSetStopRequested(Test2_M, 1);
    }

    /* End of Stop: '<S9>/Stop Simulation' */

    /* DataTypeConversion: '<S8>/Data Type Conversion' */
    Test2_B.DataTypeConversion = rtb_RelationalOperator1;

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator1' */
    /* S-Function Block: Test2/Smooth Signal Generator1 (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * Test2_P.SmoothSignalGenerator1_Frequenc;
      boolean_T params_changed = (Test2_P.SmoothSignalGenerator1_Amplitud !=
        Test2_DW.SmoothSignalGenerator1_RWORK.Amp || w !=
        Test2_DW.SmoothSignalGenerator1_RWORK.W);

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
      real_T y_sin = Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t;
      real_T y_cos = Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_Saturation = Test2_DW.SmoothSignalGenerator1_RWORK.Amp * y_sin;

      /* Compute the new sin and cos values */
      Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = y_sin *
        Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt + y_cos *
        Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt;
      Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = y_cos *
        Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt - y_sin *
        Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt;

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
        if (y_sin == 0 || Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t == 0 ||
            (y_sin < 0) != (Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t < 0))
        {
          if (fabs(Test2_DW.SmoothSignalGenerator1_RWORK.Amp *
                   Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t) <
              Test2_P.SmoothSignalGenerator1_Amplitud) {
            x = asin(Test2_DW.SmoothSignalGenerator1_RWORK.Amp *
                     Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t /
                     Test2_P.SmoothSignalGenerator1_Amplitud);
            Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt = sin(w * 0.002);
            Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt = cos(w * 0.002);
            Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) != (Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t <
                                 0)) {
              Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = -cos(x);
            } else {
              Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.002;
            Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t < 0) {
              Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = -1;
            } else {
              Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = +1;
            }

            Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt = sin(x);
            Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt = cos(x);
          }

          Test2_DW.SmoothSignalGenerator1_RWORK.Amp =
            Test2_P.SmoothSignalGenerator1_Amplitud;
          Test2_DW.SmoothSignalGenerator1_RWORK.W = w;
        }
      }
    }

    /* Gain: '<S2>/Gain1' */
    rtb_Saturation *= Test2_P.Gain1_Gain_j;

    /* Saturate: '<Root>/Saturation' */
    if (rtb_Saturation > Test2_P.Saturation_UpperSat) {
      rtb_Saturation = Test2_P.Saturation_UpperSat;
    } else if (rtb_Saturation < Test2_P.Saturation_LowerSat) {
      rtb_Saturation = Test2_P.Saturation_LowerSat;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Test2/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Test2_DW.HILInitialize_Card,
        &Test2_P.HILWriteAnalog_channels, 1, &rtb_Saturation);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void Test2_update(void)
{
  if (rtmIsMajorTimeStep(Test2_M)) {
    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
    Test2_DW.DiscreteTimeIntegrator_DSTATE +=
      Test2_P.DiscreteTimeIntegrator_gainval * Test2_B.DataTypeConversion;
    Test2_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)Test2_B.LogicalOperator1;
  }

  if (rtmIsMajorTimeStep(Test2_M)) {
    rt_ertODEUpdateContinuousStates(&Test2_M->solverInfo);
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
  if (!(++Test2_M->Timing.clockTick0)) {
    ++Test2_M->Timing.clockTickH0;
  }

  Test2_M->Timing.t[0] = rtsiGetSolverStopTime(&Test2_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Test2_M->Timing.clockTick1)) {
      ++Test2_M->Timing.clockTickH1;
    }

    Test2_M->Timing.t[1] = Test2_M->Timing.clockTick1 *
      Test2_M->Timing.stepSize1 + Test2_M->Timing.clockTickH1 *
      Test2_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Test2_derivatives(void)
{
  XDot_Test2_T *_rtXdot;
  _rtXdot = ((XDot_Test2_T *) Test2_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Servo Velocity' */
  _rtXdot->ServoVelocity_CSTATE = Test2_P.ServoVelocity_A *
    Test2_X.ServoVelocity_CSTATE;
  _rtXdot->ServoVelocity_CSTATE += Test2_B.NegativeFeedback;

  /* Derivatives for TransferFcn: '<Root>/Servo Velocity1' */
  _rtXdot->ServoVelocity1_CSTATE = Test2_P.ServoVelocity1_A *
    Test2_X.ServoVelocity1_CSTATE;
  _rtXdot->ServoVelocity1_CSTATE += Test2_B.NegativeFeedback1;
}

/* Model initialize function */
void Test2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Test2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0", &Test2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Test2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test2_M, _rt_error_message);
      return;
    }

    if ((Test2_P.HILInitialize_AIPStart && !is_switching) ||
        (Test2_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Test2_DW.HILInitialize_Card,
        &Test2_P.HILInitialize_AIChannels, 1U,
        &Test2_P.HILInitialize_AILow, &Test2_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }

    if ((Test2_P.HILInitialize_AOPStart && !is_switching) ||
        (Test2_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Test2_DW.HILInitialize_Card,
        &Test2_P.HILInitialize_AOChannels, 1U,
        &Test2_P.HILInitialize_AOLow, &Test2_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }

    if ((Test2_P.HILInitialize_AOStart && !is_switching) ||
        (Test2_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Test2_DW.HILInitialize_Card,
        &Test2_P.HILInitialize_AOChannels, 1U, &Test2_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }

    if (Test2_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Test2_DW.HILInitialize_Card, &Test2_P.HILInitialize_AOChannels, 1U,
         &Test2_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Test2_DW.HILInitialize_Card, NULL, 0U,
      &Test2_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test2_M, _rt_error_message);
      return;
    }

    if ((Test2_P.HILInitialize_DOStart && !is_switching) ||
        (Test2_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Test2_DW.HILInitialize_Card,
        &Test2_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Test2_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }

    if (Test2_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Test2_DW.HILInitialize_Card, &Test2_P.HILInitialize_DOChannels, 1U, (
          const t_digital_state *) &Test2_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }

    if ((Test2_P.HILInitialize_EIPStart && !is_switching) ||
        (Test2_P.HILInitialize_EIPEnter && is_switching)) {
      Test2_DW.HILInitialize_QuadratureModes[0] =
        Test2_P.HILInitialize_EIQuadrature;
      Test2_DW.HILInitialize_QuadratureModes[1] =
        Test2_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(Test2_DW.HILInitialize_Card,
        Test2_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &Test2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }

    if ((Test2_P.HILInitialize_EIStart && !is_switching) ||
        (Test2_P.HILInitialize_EIEnter && is_switching)) {
      Test2_DW.HILInitialize_InitialEICounts[0] =
        Test2_P.HILInitialize_EIInitial;
      Test2_DW.HILInitialize_InitialEICounts[1] =
        Test2_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Test2_DW.HILInitialize_Card,
        Test2_P.HILInitialize_EIChannels, 2U,
        &Test2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }

    if ((Test2_P.HILInitialize_OOStart && !is_switching) ||
        (Test2_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Test2_DW.HILInitialize_Card,
        Test2_P.HILInitialize_OOChannels, 3U, Test2_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }

    if (Test2_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Test2_DW.HILInitialize_Card, Test2_P.HILInitialize_OOChannels, 3U,
         Test2_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Test2/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Test2_DW.HILInitialize_Card,
      Test2_P.HILReadEncoderTimebase_SamplesI,
      &Test2_P.HILReadEncoderTimebase_Channels, 1,
      &Test2_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Test2_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Test2_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test2_M, _rt_error_message);
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */

  /* S-Function Block: Test2/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / Test2_P.SmoothSignalGenerator_Frequency;
    Test2_DW.SmoothSignalGenerator_RWORK.Amp =
      Test2_P.SmoothSignalGenerator_Amplitude;
    Test2_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      Test2_P.SmoothSignalGenerator_Frequency;
    Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (Test2_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (Test2_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      ((Test2_P.SmoothSignalGenerator_InitialPh));
    Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      ((Test2_P.SmoothSignalGenerator_InitialPh));
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator1' */

  /* S-Function Block: Test2/Smooth Signal Generator1 (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / Test2_P.SmoothSignalGenerator1_Frequenc;
    Test2_DW.SmoothSignalGenerator1_RWORK.Amp =
      Test2_P.SmoothSignalGenerator1_Amplitud;
    Test2_DW.SmoothSignalGenerator1_RWORK.W = TWO_PI *
      Test2_P.SmoothSignalGenerator1_Frequenc;
    Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt = sin
      (Test2_DW.SmoothSignalGenerator1_RWORK.W * 0.002);
    Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt = cos
      (Test2_DW.SmoothSignalGenerator1_RWORK.W * 0.002);
    Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = sin
      ((Test2_P.SmoothSignalGenerator1_InitialP));
    Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = cos
      ((Test2_P.SmoothSignalGenerator1_InitialP));
  }

  /* InitializeConditions for TransferFcn: '<Root>/Servo Velocity' */
  Test2_X.ServoVelocity_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Servo Velocity1' */
  Test2_X.ServoVelocity1_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' */
  Test2_DW.DiscreteTimeIntegrator_DSTATE = Test2_P.DiscreteTimeIntegrator_IC;
  Test2_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void Test2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Test2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Test2_DW.HILInitialize_Card);
    hil_monitor_stop_all(Test2_DW.HILInitialize_Card);
    is_switching = false;
    if ((Test2_P.HILInitialize_AOTerminate && !is_switching) ||
        (Test2_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Test2_P.HILInitialize_DOTerminate && !is_switching) ||
        (Test2_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Test2_P.HILInitialize_OOTerminate && !is_switching) ||
        (Test2_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Test2_DW.HILInitialize_Card
                         , &Test2_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Test2_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Test2_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Test2_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Test2_P.HILInitialize_DOFinal
                         , Test2_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Test2_DW.HILInitialize_Card,
            &Test2_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Test2_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Test2_DW.HILInitialize_Card,
            &Test2_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Test2_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Test2_DW.HILInitialize_Card,
            Test2_P.HILInitialize_OOChannels, num_final_other_outputs,
            Test2_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Test2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Test2_DW.HILInitialize_Card);
    hil_monitor_delete_all(Test2_DW.HILInitialize_Card);
    hil_close(Test2_DW.HILInitialize_Card);
    Test2_DW.HILInitialize_Card = NULL;
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
  Test2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Test2_update();
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
  Test2_initialize();
}

void MdlTerminate(void)
{
  Test2_terminate();
}

/* Registration function */
RT_MODEL_Test2_T *Test2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Test2_M, 0,
                sizeof(RT_MODEL_Test2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Test2_M->solverInfo, &Test2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Test2_M->solverInfo, &rtmGetTPtr(Test2_M));
    rtsiSetStepSizePtr(&Test2_M->solverInfo, &Test2_M->Timing.stepSize0);
    rtsiSetdXPtr(&Test2_M->solverInfo, &Test2_M->derivs);
    rtsiSetContStatesPtr(&Test2_M->solverInfo, (real_T **) &Test2_M->contStates);
    rtsiSetNumContStatesPtr(&Test2_M->solverInfo, &Test2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Test2_M->solverInfo,
      &Test2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Test2_M->solverInfo,
      &Test2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Test2_M->solverInfo,
      &Test2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Test2_M->solverInfo, (&rtmGetErrorStatus(Test2_M)));
    rtsiSetRTModelPtr(&Test2_M->solverInfo, Test2_M);
  }

  rtsiSetSimTimeStep(&Test2_M->solverInfo, MAJOR_TIME_STEP);
  Test2_M->intgData.f[0] = Test2_M->odeF[0];
  Test2_M->contStates = ((real_T *) &Test2_X);
  rtsiSetSolverData(&Test2_M->solverInfo, (void *)&Test2_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Test2_M->solverInfo, false);
  rtsiSetSolverName(&Test2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Test2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Test2_M points to
       static memory which is guaranteed to be non-NULL" */
    Test2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Test2_M->Timing.sampleTimes = (&Test2_M->Timing.sampleTimesArray[0]);
    Test2_M->Timing.offsetTimes = (&Test2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Test2_M->Timing.sampleTimes[0] = (0.0);
    Test2_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Test2_M->Timing.offsetTimes[0] = (0.0);
    Test2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Test2_M, &Test2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Test2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Test2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Test2_M, -1);
  Test2_M->Timing.stepSize0 = 0.002;
  Test2_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  Test2_M->Sizes.checksums[0] = (1315150066U);
  Test2_M->Sizes.checksums[1] = (2553260911U);
  Test2_M->Sizes.checksums[2] = (1963107433U);
  Test2_M->Sizes.checksums[3] = (2767190260U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Test2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Test2_M->extModeInfo,
      &Test2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Test2_M->extModeInfo, Test2_M->Sizes.checksums);
    rteiSetTPtr(Test2_M->extModeInfo, rtmGetTPtr(Test2_M));
  }

  Test2_M->solverInfoPtr = (&Test2_M->solverInfo);
  Test2_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Test2_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Test2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Test2_M->blockIO = ((void *) &Test2_B);
  (void) memset(((void *) &Test2_B), 0,
                sizeof(B_Test2_T));

  {
    Test2_B.SliderGain = 0.0;
    Test2_B.NegativeFeedback = 0.0;
    Test2_B.Sum1 = 0.0;
    Test2_B.Gain = 0.0;
    Test2_B.Gain_f[0] = 0.0;
    Test2_B.Gain_f[1] = 0.0;
    Test2_B.NegativeFeedback1 = 0.0;
    Test2_B.ServoVelocity1 = 0.0;
    Test2_B.DataTypeConversion = 0.0;
  }

  /* parameters */
  Test2_M->defaultParam = ((real_T *)&Test2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Test2_X;
    Test2_M->contStates = (x);
    (void) memset((void *)&Test2_X, 0,
                  sizeof(X_Test2_T));
  }

  /* states (dwork) */
  Test2_M->dwork = ((void *) &Test2_DW);
  (void) memset((void *)&Test2_DW, 0,
                sizeof(DW_Test2_T));
  Test2_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  Test2_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Test2_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Test2_DW.SmoothSignalGenerator_RWORK.Amp = 0.0;
  Test2_DW.SmoothSignalGenerator_RWORK.W = 0.0;
  Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = 0.0;
  Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = 0.0;
  Test2_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0.0;
  Test2_DW.SmoothSignalGenerator_RWORK.Cos_w_t = 0.0;
  Test2_DW.SmoothSignalGenerator1_RWORK.Amp = 0.0;
  Test2_DW.SmoothSignalGenerator1_RWORK.W = 0.0;
  Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt = 0.0;
  Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt = 0.0;
  Test2_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = 0.0;
  Test2_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Test2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Test2_M->Sizes.numContStates = (2);  /* Number of continuous states */
  Test2_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Test2_M->Sizes.numY = (0);           /* Number of model outputs */
  Test2_M->Sizes.numU = (0);           /* Number of model inputs */
  Test2_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  Test2_M->Sizes.numSampTimes = (2);   /* Number of sample times */
  Test2_M->Sizes.numBlocks = (42);     /* Number of blocks */
  Test2_M->Sizes.numBlockIO = (10);    /* Number of block outputs */
  Test2_M->Sizes.numBlockPrms = (108); /* Sum of parameter "widths" */
  return Test2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
