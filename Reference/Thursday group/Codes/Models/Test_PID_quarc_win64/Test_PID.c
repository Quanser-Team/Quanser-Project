/*
 * Test_PID.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Test_PID".
 *
 * Model version              : 9.9
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Oct 19 18:23:24 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Test_PID.h"
#include "rtwtypes.h"
#include <math.h>
#include "Test_PID_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Test_PID_dt.h"

/* Block signals (default storage) */
B_Test_PID_T Test_PID_B;

/* Continuous states */
X_Test_PID_T Test_PID_X;

/* Block states (default storage) */
DW_Test_PID_T Test_PID_DW;

/* Real-time model */
static RT_MODEL_Test_PID_T Test_PID_M_;
RT_MODEL_Test_PID_T *const Test_PID_M = &Test_PID_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Test_PID_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Test_PID_output(void)
{
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_Gain1;
  real_T rtb_Sum;
  real_T rtb_countstorad;
  real_T u0;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(Test_PID_M)) {
    /* set solver stop time */
    if (!(Test_PID_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Test_PID_M->solverInfo,
                            ((Test_PID_M->Timing.clockTickH0 + 1) *
        Test_PID_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Test_PID_M->solverInfo,
                            ((Test_PID_M->Timing.clockTick0 + 1) *
        Test_PID_M->Timing.stepSize0 + Test_PID_M->Timing.clockTickH0 *
        Test_PID_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Test_PID_M)) {
    Test_PID_M->Timing.t[0] = rtsiGetT(&Test_PID_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Test_PID_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: Test_PID/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(Test_PID_DW.HILReadEncoderTimebase_Task, 1,
        &Test_PID_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        rtb_countstorad = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
      } else {
        rtb_countstorad = Test_PID_DW.HILReadEncoderTimebase_Buffer;
      }
    }

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator1' */
    /* S-Function Block: Test_PID/Smooth Signal Generator1 (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * Test_PID_P.SmoothSignalGenerator1_Frequenc;
      boolean_T params_changed = (Test_PID_P.SmoothSignalGenerator1_Amplitud !=
        Test_PID_DW.SmoothSignalGenerator1_RWORK.Amp || w !=
        Test_PID_DW.SmoothSignalGenerator1_RWORK.W);

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
      real_T y_sin = Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t;
      real_T y_cos = Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_Gain1 = Test_PID_DW.SmoothSignalGenerator1_RWORK.Amp * y_sin;

      /* Compute the new sin and cos values */
      Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = y_sin *
        Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt + y_cos *
        Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt;
      Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = y_cos *
        Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt - y_sin *
        Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt;

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
        if (y_sin == 0 || Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t == 0 ||
            (y_sin < 0) != (Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t < 0))
        {
          if (fabs(Test_PID_DW.SmoothSignalGenerator1_RWORK.Amp *
                   Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t) <
              Test_PID_P.SmoothSignalGenerator1_Amplitud) {
            x = asin(Test_PID_DW.SmoothSignalGenerator1_RWORK.Amp *
                     Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t /
                     Test_PID_P.SmoothSignalGenerator1_Amplitud);
            Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt = sin(w * 0.0005);
            Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt = cos(w * 0.0005);
            Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t < 0)) {
              Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = -cos(x);
            } else {
              Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.0005;
            Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t < 0) {
              Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = -1;
            } else {
              Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = +1;
            }

            Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt = sin(x);
            Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt = cos(x);
          }

          Test_PID_DW.SmoothSignalGenerator1_RWORK.Amp =
            Test_PID_P.SmoothSignalGenerator1_Amplitud;
          Test_PID_DW.SmoothSignalGenerator1_RWORK.W = w;
        }
      }
    }

    /* Gain: '<S1>/Gain1' incorporates:
     *  Gain: '<Root>/Amplitude (deg)'
     */
    rtb_Gain1 = Test_PID_P.Amplitudedeg_Gain * rtb_Gain1 * Test_PID_P.Gain1_Gain;

    /* Gain: '<Root>/counts to rad' */
    rtb_countstorad *= Test_PID_P.countstorad_Gain;

    /* Sum: '<Root>/Sum' */
    rtb_Sum = rtb_Gain1 - rtb_countstorad;

    /* Gain: '<S42>/Proportional Gain' */
    Test_PID_B.ProportionalGain = Test_PID_P.PIDController_P * rtb_Sum;

    /* Gain: '<S31>/Derivative Gain' */
    Test_PID_B.DerivativeGain = Test_PID_P.PIDController_D * rtb_Sum;
  }

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  Integrator: '<S32>/Filter'
   *  Sum: '<S32>/SumD'
   */
  Test_PID_B.FilterCoefficient = (Test_PID_B.DerivativeGain -
    Test_PID_X.Filter_CSTATE) * Test_PID_P.PIDController_N;

  /* Sum: '<S46>/Sum' incorporates:
   *  Integrator: '<S37>/Integrator'
   */
  u0 = (Test_PID_B.ProportionalGain + Test_PID_X.Integrator_CSTATE) +
    Test_PID_B.FilterCoefficient;

  /* Saturate: '<Root>/Saturation' */
  if (u0 > Test_PID_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    Test_PID_B.Saturation = Test_PID_P.Saturation_UpperSat;
  } else if (u0 < Test_PID_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    Test_PID_B.Saturation = Test_PID_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    Test_PID_B.Saturation = u0;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(Test_PID_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Test_PID/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Test_PID_DW.HILInitialize_Card,
        &Test_PID_P.HILWriteAnalog_channels, 1, &Test_PID_B.Saturation);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: Test_PID/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Test_PID_DW.HILInitialize_Card,
        &Test_PID_P.HILReadEncoder_channels, 1,
        &Test_PID_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
      } else {
        rtb_DiscreteTimeIntegrator = Test_PID_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/counts to rad1' */
    Test_PID_B.countstorad1 = Test_PID_P.countstorad1_Gain *
      rtb_DiscreteTimeIntegrator;

    /* Gain: '<S4>/Gain' */
    Test_PID_B.Gain = Test_PID_P.Gain_Gain * Test_PID_B.countstorad1;
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  Test_PID_B.TransferFcn1 = 0.0;
  Test_PID_B.TransferFcn1 += Test_PID_P.TransferFcn1_C *
    Test_PID_X.TransferFcn1_CSTATE;
  if (rtmIsMajorTimeStep(Test_PID_M)) {
    /* Gain: '<S3>/Gain' */
    Test_PID_B.Gain_f[0] = Test_PID_P.Gain_Gain_a * rtb_Gain1;
    Test_PID_B.Gain_f[1] = Test_PID_P.Gain_Gain_a * rtb_countstorad;

    /* Abs: '<S54>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(Test_PID_B.Saturation);

    /* RelationalOperator: '<S54>/Relational Operator1' incorporates:
     *  Constant: '<S54>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      Test_PID_P.StallMonitor_control_threshold);
  }

  /* Gain: '<Root>/Negative Feedback1' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn'
   */
  Test_PID_B.NegativeFeedback1 = (Test_PID_P.TransferFcn_C *
    Test_PID_X.TransferFcn_CSTATE + Test_PID_P.TransferFcn_D *
    Test_PID_B.countstorad1) * Test_PID_P.NegativeFeedback1_Gain;
  if (rtmIsMajorTimeStep(Test_PID_M)) {
    /* Abs: '<S54>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(Test_PID_B.NegativeFeedback1);

    /* Logic: '<S54>/Logical Operator' incorporates:
     *  Constant: '<S54>/motion threshold'
     *  RelationalOperator: '<S54>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <= Test_PID_P.StallMonitor_motion_threshold));

    /* Logic: '<S54>/Logical Operator1' */
    Test_PID_B.LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */
    if (Test_PID_B.LogicalOperator1 &&
        (Test_PID_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      Test_PID_DW.DiscreteTimeIntegrator_DSTATE =
        Test_PID_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator = Test_PID_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S54>/Relational Operator2' incorporates:
     *  Constant: '<S54>/control threshold1'
     */
    Test_PID_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
      Test_PID_P.StallMonitor_duration_s);

    /* Stop: '<S55>/Stop Simulation' incorporates:
     *  Constant: '<S56>/Constant'
     *  RelationalOperator: '<S56>/Compare'
     */
    if (Test_PID_B.RelationalOperator2 != Test_PID_P.Constant_Value) {
      rtmSetStopRequested(Test_PID_M, 1);
    }

    /* End of Stop: '<S55>/Stop Simulation' */

    /* DataTypeConversion: '<S54>/Data Type Conversion' */
    Test_PID_B.DataTypeConversion = rtb_RelationalOperator1;

    /* Gain: '<S34>/Integral Gain' */
    Test_PID_B.IntegralGain = Test_PID_P.PIDController_I * rtb_Sum;
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<Root>/Gain'
   */
  Test_PID_B.Sum1 = Test_PID_B.Saturation - Test_PID_P.kt *
    Test_PID_B.NegativeFeedback1;
}

/* Model update function */
void Test_PID_update(void)
{
  if (rtmIsMajorTimeStep(Test_PID_M)) {
    /* Update for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */
    Test_PID_DW.DiscreteTimeIntegrator_DSTATE +=
      Test_PID_P.DiscreteTimeIntegrator_gainval * Test_PID_B.DataTypeConversion;
    Test_PID_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      Test_PID_B.LogicalOperator1;
  }

  if (rtmIsMajorTimeStep(Test_PID_M)) {
    rt_ertODEUpdateContinuousStates(&Test_PID_M->solverInfo);
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
  if (!(++Test_PID_M->Timing.clockTick0)) {
    ++Test_PID_M->Timing.clockTickH0;
  }

  Test_PID_M->Timing.t[0] = rtsiGetSolverStopTime(&Test_PID_M->solverInfo);

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
    if (!(++Test_PID_M->Timing.clockTick1)) {
      ++Test_PID_M->Timing.clockTickH1;
    }

    Test_PID_M->Timing.t[1] = Test_PID_M->Timing.clockTick1 *
      Test_PID_M->Timing.stepSize1 + Test_PID_M->Timing.clockTickH1 *
      Test_PID_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Test_PID_derivatives(void)
{
  XDot_Test_PID_T *_rtXdot;
  _rtXdot = ((XDot_Test_PID_T *) Test_PID_M->derivs);

  /* Derivatives for Integrator: '<S37>/Integrator' */
  _rtXdot->Integrator_CSTATE = Test_PID_B.IntegralGain;

  /* Derivatives for Integrator: '<S32>/Filter' */
  _rtXdot->Filter_CSTATE = Test_PID_B.FilterCoefficient;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = Test_PID_P.TransferFcn1_A *
    Test_PID_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Test_PID_B.Sum1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = Test_PID_P.TransferFcn_A *
    Test_PID_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Test_PID_B.countstorad1;
}

/* Model initialize function */
void Test_PID_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Test_PID/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0", &Test_PID_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_PID_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Test_PID_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_PID_M, _rt_error_message);
      return;
    }

    if ((Test_PID_P.HILInitialize_AIPStart && !is_switching) ||
        (Test_PID_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Test_PID_DW.HILInitialize_Card,
        &Test_PID_P.HILInitialize_AIChannels, 1U,
        &Test_PID_P.HILInitialize_AILow, &Test_PID_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }

    if ((Test_PID_P.HILInitialize_AOPStart && !is_switching) ||
        (Test_PID_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Test_PID_DW.HILInitialize_Card,
        &Test_PID_P.HILInitialize_AOChannels, 1U,
        &Test_PID_P.HILInitialize_AOLow, &Test_PID_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }

    if ((Test_PID_P.HILInitialize_AOStart && !is_switching) ||
        (Test_PID_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Test_PID_DW.HILInitialize_Card,
        &Test_PID_P.HILInitialize_AOChannels, 1U,
        &Test_PID_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }

    if (Test_PID_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Test_PID_DW.HILInitialize_Card, &Test_PID_P.HILInitialize_AOChannels,
         1U, &Test_PID_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Test_PID_DW.HILInitialize_Card, NULL, 0U,
      &Test_PID_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_PID_M, _rt_error_message);
      return;
    }

    if ((Test_PID_P.HILInitialize_DOStart && !is_switching) ||
        (Test_PID_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Test_PID_DW.HILInitialize_Card,
        &Test_PID_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Test_PID_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }

    if (Test_PID_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Test_PID_DW.HILInitialize_Card, &Test_PID_P.HILInitialize_DOChannels,
         1U, (const t_digital_state *) &Test_PID_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }

    if ((Test_PID_P.HILInitialize_EIPStart && !is_switching) ||
        (Test_PID_P.HILInitialize_EIPEnter && is_switching)) {
      Test_PID_DW.HILInitialize_QuadratureModes[0] =
        Test_PID_P.HILInitialize_EIQuadrature;
      Test_PID_DW.HILInitialize_QuadratureModes[1] =
        Test_PID_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(Test_PID_DW.HILInitialize_Card,
        Test_PID_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &Test_PID_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }

    if ((Test_PID_P.HILInitialize_EIStart && !is_switching) ||
        (Test_PID_P.HILInitialize_EIEnter && is_switching)) {
      Test_PID_DW.HILInitialize_InitialEICounts[0] =
        Test_PID_P.HILInitialize_EIInitial;
      Test_PID_DW.HILInitialize_InitialEICounts[1] =
        Test_PID_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Test_PID_DW.HILInitialize_Card,
        Test_PID_P.HILInitialize_EIChannels, 2U,
        &Test_PID_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }

    if ((Test_PID_P.HILInitialize_OOStart && !is_switching) ||
        (Test_PID_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Test_PID_DW.HILInitialize_Card,
        Test_PID_P.HILInitialize_OOChannels, 3U,
        Test_PID_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }

    if (Test_PID_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Test_PID_DW.HILInitialize_Card, Test_PID_P.HILInitialize_OOChannels, 3U,
         Test_PID_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Test_PID/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Test_PID_DW.HILInitialize_Card,
      Test_PID_P.HILReadEncoderTimebase_SamplesI,
      &Test_PID_P.HILReadEncoderTimebase_Channels, 1,
      &Test_PID_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Test_PID_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Test_PID_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Test_PID_M, _rt_error_message);
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator1' */

  /* S-Function Block: Test_PID/Smooth Signal Generator1 (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / Test_PID_P.SmoothSignalGenerator1_Frequenc;
    Test_PID_DW.SmoothSignalGenerator1_RWORK.Amp =
      Test_PID_P.SmoothSignalGenerator1_Amplitud;
    Test_PID_DW.SmoothSignalGenerator1_RWORK.W = TWO_PI *
      Test_PID_P.SmoothSignalGenerator1_Frequenc;
    Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt = sin
      (Test_PID_DW.SmoothSignalGenerator1_RWORK.W * 0.0005);
    Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt = cos
      (Test_PID_DW.SmoothSignalGenerator1_RWORK.W * 0.0005);
    Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = sin
      (Test_PID_P.SmoothSignalGenerator1_InitialP);
    Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = cos
      (Test_PID_P.SmoothSignalGenerator1_InitialP);
  }

  /* InitializeConditions for Integrator: '<S37>/Integrator' */
  Test_PID_X.Integrator_CSTATE = Test_PID_P.PIDController_InitialConditio_p;

  /* InitializeConditions for Integrator: '<S32>/Filter' */
  Test_PID_X.Filter_CSTATE = Test_PID_P.PIDController_InitialConditionF;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Test_PID_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Test_PID_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S54>/Discrete-Time Integrator' */
  Test_PID_DW.DiscreteTimeIntegrator_DSTATE =
    Test_PID_P.DiscreteTimeIntegrator_IC;
  Test_PID_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void Test_PID_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Test_PID/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Test_PID_DW.HILInitialize_Card);
    hil_monitor_stop_all(Test_PID_DW.HILInitialize_Card);
    is_switching = false;
    if ((Test_PID_P.HILInitialize_AOTerminate && !is_switching) ||
        (Test_PID_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Test_PID_P.HILInitialize_DOTerminate && !is_switching) ||
        (Test_PID_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Test_PID_P.HILInitialize_OOTerminate && !is_switching) ||
        (Test_PID_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Test_PID_DW.HILInitialize_Card
                         , &Test_PID_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Test_PID_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Test_PID_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Test_PID_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Test_PID_P.HILInitialize_DOFinal
                         , Test_PID_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Test_PID_DW.HILInitialize_Card,
            &Test_PID_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Test_PID_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Test_PID_DW.HILInitialize_Card,
            &Test_PID_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Test_PID_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Test_PID_DW.HILInitialize_Card,
            Test_PID_P.HILInitialize_OOChannels, num_final_other_outputs,
            Test_PID_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Test_PID_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Test_PID_DW.HILInitialize_Card);
    hil_monitor_delete_all(Test_PID_DW.HILInitialize_Card);
    hil_close(Test_PID_DW.HILInitialize_Card);
    Test_PID_DW.HILInitialize_Card = NULL;
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
  Test_PID_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Test_PID_update();
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
  Test_PID_initialize();
}

void MdlTerminate(void)
{
  Test_PID_terminate();
}

/* Registration function */
RT_MODEL_Test_PID_T *Test_PID(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Test_PID_M, 0,
                sizeof(RT_MODEL_Test_PID_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Test_PID_M->solverInfo,
                          &Test_PID_M->Timing.simTimeStep);
    rtsiSetTPtr(&Test_PID_M->solverInfo, &rtmGetTPtr(Test_PID_M));
    rtsiSetStepSizePtr(&Test_PID_M->solverInfo, &Test_PID_M->Timing.stepSize0);
    rtsiSetdXPtr(&Test_PID_M->solverInfo, &Test_PID_M->derivs);
    rtsiSetContStatesPtr(&Test_PID_M->solverInfo, (real_T **)
                         &Test_PID_M->contStates);
    rtsiSetNumContStatesPtr(&Test_PID_M->solverInfo,
      &Test_PID_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Test_PID_M->solverInfo,
      &Test_PID_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Test_PID_M->solverInfo,
      &Test_PID_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Test_PID_M->solverInfo,
      &Test_PID_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Test_PID_M->solverInfo, (&rtmGetErrorStatus
      (Test_PID_M)));
    rtsiSetRTModelPtr(&Test_PID_M->solverInfo, Test_PID_M);
  }

  rtsiSetSimTimeStep(&Test_PID_M->solverInfo, MAJOR_TIME_STEP);
  Test_PID_M->intgData.f[0] = Test_PID_M->odeF[0];
  Test_PID_M->contStates = ((real_T *) &Test_PID_X);
  rtsiSetSolverData(&Test_PID_M->solverInfo, (void *)&Test_PID_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Test_PID_M->solverInfo, false);
  rtsiSetSolverName(&Test_PID_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Test_PID_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Test_PID_M points to
       static memory which is guaranteed to be non-NULL" */
    Test_PID_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Test_PID_M->Timing.sampleTimes = (&Test_PID_M->Timing.sampleTimesArray[0]);
    Test_PID_M->Timing.offsetTimes = (&Test_PID_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Test_PID_M->Timing.sampleTimes[0] = (0.0);
    Test_PID_M->Timing.sampleTimes[1] = (0.0005);

    /* task offsets */
    Test_PID_M->Timing.offsetTimes[0] = (0.0);
    Test_PID_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Test_PID_M, &Test_PID_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Test_PID_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Test_PID_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Test_PID_M, -1);
  Test_PID_M->Timing.stepSize0 = 0.0005;
  Test_PID_M->Timing.stepSize1 = 0.0005;

  /* External mode info */
  Test_PID_M->Sizes.checksums[0] = (96660718U);
  Test_PID_M->Sizes.checksums[1] = (1943079243U);
  Test_PID_M->Sizes.checksums[2] = (314535757U);
  Test_PID_M->Sizes.checksums[3] = (2048634942U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Test_PID_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Test_PID_M->extModeInfo,
      &Test_PID_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Test_PID_M->extModeInfo, Test_PID_M->Sizes.checksums);
    rteiSetTPtr(Test_PID_M->extModeInfo, rtmGetTPtr(Test_PID_M));
  }

  Test_PID_M->solverInfoPtr = (&Test_PID_M->solverInfo);
  Test_PID_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&Test_PID_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&Test_PID_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Test_PID_M->blockIO = ((void *) &Test_PID_B);
  (void) memset(((void *) &Test_PID_B), 0,
                sizeof(B_Test_PID_T));

  {
    Test_PID_B.ProportionalGain = 0.0;
    Test_PID_B.DerivativeGain = 0.0;
    Test_PID_B.FilterCoefficient = 0.0;
    Test_PID_B.Saturation = 0.0;
    Test_PID_B.countstorad1 = 0.0;
    Test_PID_B.Gain = 0.0;
    Test_PID_B.TransferFcn1 = 0.0;
    Test_PID_B.Gain_f[0] = 0.0;
    Test_PID_B.Gain_f[1] = 0.0;
    Test_PID_B.NegativeFeedback1 = 0.0;
    Test_PID_B.DataTypeConversion = 0.0;
    Test_PID_B.IntegralGain = 0.0;
    Test_PID_B.Sum1 = 0.0;
  }

  /* parameters */
  Test_PID_M->defaultParam = ((real_T *)&Test_PID_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Test_PID_X;
    Test_PID_M->contStates = (x);
    (void) memset((void *)&Test_PID_X, 0,
                  sizeof(X_Test_PID_T));
  }

  /* states (dwork) */
  Test_PID_M->dwork = ((void *) &Test_PID_DW);
  (void) memset((void *)&Test_PID_DW, 0,
                sizeof(DW_Test_PID_T));
  Test_PID_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  Test_PID_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Test_PID_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Test_PID_DW.SmoothSignalGenerator1_RWORK.Amp = 0.0;
  Test_PID_DW.SmoothSignalGenerator1_RWORK.W = 0.0;
  Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_dt = 0.0;
  Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_dt = 0.0;
  Test_PID_DW.SmoothSignalGenerator1_RWORK.Sin_w_t = 0.0;
  Test_PID_DW.SmoothSignalGenerator1_RWORK.Cos_w_t = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Test_PID_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Test_PID_M->Sizes.numContStates = (4);/* Number of continuous states */
  Test_PID_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Test_PID_M->Sizes.numY = (0);        /* Number of model outputs */
  Test_PID_M->Sizes.numU = (0);        /* Number of model inputs */
  Test_PID_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Test_PID_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Test_PID_M->Sizes.numBlocks = (49);  /* Number of blocks */
  Test_PID_M->Sizes.numBlockIO = (14); /* Number of block outputs */
  Test_PID_M->Sizes.numBlockPrms = (107);/* Sum of parameter "widths" */
  return Test_PID_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
