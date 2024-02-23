/*
 * qube_servo2_quick_start_groupA.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "qube_servo2_quick_start_groupA".
 *
 * Model version              : 9.1
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Sep 28 16:41:14 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "qube_servo2_quick_start_groupA.h"
#include "rtwtypes.h"
#include <math.h>
#include "qube_servo2_quick_start_groupA_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "qube_servo2_quick_start_groupA_dt.h"

/* Block signals (default storage) */
B_qube_servo2_quick_start_gro_T qube_servo2_quick_start_group_B;

/* Continuous states */
X_qube_servo2_quick_start_gro_T qube_servo2_quick_start_group_X;

/* Block states (default storage) */
DW_qube_servo2_quick_start_gr_T qube_servo2_quick_start_grou_DW;

/* Real-time model */
static RT_MODEL_qube_servo2_quick_st_T qube_servo2_quick_start_grou_M_;
RT_MODEL_qube_servo2_quick_st_T *const qube_servo2_quick_start_grou_M =
  &qube_servo2_quick_start_grou_M_;

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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  qube_servo2_quick_start_groupA_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void qube_servo2_quick_start_groupA_output(void)
{
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_countstorad;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(qube_servo2_quick_start_grou_M)) {
    /* set solver stop time */
    if (!(qube_servo2_quick_start_grou_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&qube_servo2_quick_start_grou_M->solverInfo,
                            ((qube_servo2_quick_start_grou_M->Timing.clockTickH0
        + 1) * qube_servo2_quick_start_grou_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&qube_servo2_quick_start_grou_M->solverInfo,
                            ((qube_servo2_quick_start_grou_M->Timing.clockTick0
        + 1) * qube_servo2_quick_start_grou_M->Timing.stepSize0 +
        qube_servo2_quick_start_grou_M->Timing.clockTickH0 *
        qube_servo2_quick_start_grou_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(qube_servo2_quick_start_grou_M)) {
    qube_servo2_quick_start_grou_M->Timing.t[0] = rtsiGetT
      (&qube_servo2_quick_start_grou_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(qube_servo2_quick_start_grou_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: qube_servo2_quick_start_groupA/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (qube_servo2_quick_start_grou_DW.HILReadEncoderTimebase_Task, 1,
         &qube_servo2_quick_start_grou_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        rtb_countstorad = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
      } else {
        rtb_countstorad =
          qube_servo2_quick_start_grou_DW.HILReadEncoderTimebase_Buffer;
      }
    }

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */
    /* S-Function Block: qube_servo2_quick_start_groupA/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI *
        qube_servo2_quick_start_group_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed =
        (qube_servo2_quick_start_group_P.SmoothSignalGenerator_Amplitude !=
         qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Amp || w !=
         qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.W);

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
      real_T y_sin =
        qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos =
        qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_DiscreteTimeIntegrator =
        qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Amp * y_sin;

      /* Compute the new sin and cos values */
      qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t =
        y_sin *
        qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_dt +
        y_cos *
        qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t =
        y_cos *
        qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_dt -
        y_sin *
        qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

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
        if (y_sin == 0 ||
            qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t ==
            0 || (y_sin < 0) !=
            (qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t
             < 0)) {
          if (fabs
              (qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Amp *
               qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t)
              < qube_servo2_quick_start_group_P.SmoothSignalGenerator_Amplitude)
          {
            x = asin
              (qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Amp *
               qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t
               / qube_servo2_quick_start_group_P.SmoothSignalGenerator_Amplitude);
            qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_dt
              = sin(w * 0.002);
            qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_dt
              = cos(w * 0.002);
            qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t =
              sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t
                 < 0)) {
              qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t
                = -cos(x);
            } else {
              qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t
                = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.002;
            qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t =
              0;

            /* Make sure cosine output is also continuous */
            if (qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t
                < 0) {
              qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t
                = -1;
            } else {
              qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t
                = +1;
            }

            qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_dt
              = sin(x);
            qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_dt
              = cos(x);
          }

          qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Amp =
            qube_servo2_quick_start_group_P.SmoothSignalGenerator_Amplitude;
          qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }

    /* Gain: '<S1>/Gain1' incorporates:
     *  Gain: '<Root>/Amplitude (deg)'
     */
    rtb_DiscreteTimeIntegrator =
      qube_servo2_quick_start_group_P.Amplitudedeg_Gain *
      rtb_DiscreteTimeIntegrator * qube_servo2_quick_start_group_P.Gain1_Gain;

    /* Gain: '<Root>/counts to rad' */
    rtb_countstorad *= qube_servo2_quick_start_group_P.countstorad_Gain;

    /* Gain: '<S3>/Slider Gain' incorporates:
     *  Sum: '<Root>/Sum'
     */
    qube_servo2_quick_start_group_B.SliderGain = (rtb_DiscreteTimeIntegrator -
      rtb_countstorad) * qube_servo2_quick_start_group_P.ProportionalGain_gain;

    /* Gain: '<Root>/Negative Feedback' */
    qube_servo2_quick_start_group_B.NegativeFeedback =
      qube_servo2_quick_start_group_P.NegativeFeedback_Gain * rtb_countstorad;
  }

  /* TransferFcn: '<Root>/Servo Velocity' */
  qube_servo2_quick_start_group_B.ServoVelocity =
    qube_servo2_quick_start_group_P.ServoVelocity_C *
    qube_servo2_quick_start_group_X.ServoVelocity_CSTATE;
  qube_servo2_quick_start_group_B.ServoVelocity +=
    qube_servo2_quick_start_group_P.ServoVelocity_D *
    qube_servo2_quick_start_group_B.NegativeFeedback;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Gain: '<S2>/Slider Gain'
   */
  qube_servo2_quick_start_group_B.Sum1 =
    qube_servo2_quick_start_group_P.DerivativeGain_gain *
    qube_servo2_quick_start_group_B.ServoVelocity +
    qube_servo2_quick_start_group_B.SliderGain;
  if (rtmIsMajorTimeStep(qube_servo2_quick_start_grou_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: qube_servo2_quick_start_groupA/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         &qube_servo2_quick_start_group_P.HILWriteAnalog_channels, 1,
         &qube_servo2_quick_start_group_B.Sum1);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
      }
    }

    /* Gain: '<S4>/Gain' */
    qube_servo2_quick_start_group_B.Gain[0] =
      qube_servo2_quick_start_group_P.Gain_Gain * rtb_DiscreteTimeIntegrator;
    qube_servo2_quick_start_group_B.Gain[1] =
      qube_servo2_quick_start_group_P.Gain_Gain * rtb_countstorad;

    /* Abs: '<S6>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(qube_servo2_quick_start_group_B.Sum1);

    /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
     *  Constant: '<S6>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      qube_servo2_quick_start_group_P.StallMonitor_control_threshold);

    /* Abs: '<S6>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs
      (qube_servo2_quick_start_group_B.ServoVelocity);

    /* Logic: '<S6>/Logical Operator' incorporates:
     *  Constant: '<S6>/motion threshold'
     *  RelationalOperator: '<S6>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <=
       qube_servo2_quick_start_group_P.StallMonitor_motion_threshold));

    /* Logic: '<S6>/Logical Operator1' */
    qube_servo2_quick_start_group_B.LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    if (qube_servo2_quick_start_group_B.LogicalOperator1 &&
        (qube_servo2_quick_start_grou_DW.DiscreteTimeIntegrator_PrevRese <= 0))
    {
      qube_servo2_quick_start_grou_DW.DiscreteTimeIntegrator_DSTATE =
        qube_servo2_quick_start_group_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator =
      qube_servo2_quick_start_grou_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S6>/Relational Operator2' incorporates:
     *  Constant: '<S6>/control threshold1'
     */
    qube_servo2_quick_start_group_B.RelationalOperator2 =
      (rtb_DiscreteTimeIntegrator >=
       qube_servo2_quick_start_group_P.StallMonitor_duration_s);

    /* Stop: '<S7>/Stop Simulation' incorporates:
     *  Constant: '<S8>/Constant'
     *  RelationalOperator: '<S8>/Compare'
     */
    if (qube_servo2_quick_start_group_B.RelationalOperator2 !=
        qube_servo2_quick_start_group_P.Constant_Value) {
      rtmSetStopRequested(qube_servo2_quick_start_grou_M, 1);
    }

    /* End of Stop: '<S7>/Stop Simulation' */

    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    qube_servo2_quick_start_group_B.DataTypeConversion = rtb_RelationalOperator1;
  }
}

/* Model update function */
void qube_servo2_quick_start_groupA_update(void)
{
  if (rtmIsMajorTimeStep(qube_servo2_quick_start_grou_M)) {
    /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    qube_servo2_quick_start_grou_DW.DiscreteTimeIntegrator_DSTATE +=
      qube_servo2_quick_start_group_P.DiscreteTimeIntegrator_gainval *
      qube_servo2_quick_start_group_B.DataTypeConversion;
    qube_servo2_quick_start_grou_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      qube_servo2_quick_start_group_B.LogicalOperator1;
  }

  if (rtmIsMajorTimeStep(qube_servo2_quick_start_grou_M)) {
    rt_ertODEUpdateContinuousStates(&qube_servo2_quick_start_grou_M->solverInfo);
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
  if (!(++qube_servo2_quick_start_grou_M->Timing.clockTick0)) {
    ++qube_servo2_quick_start_grou_M->Timing.clockTickH0;
  }

  qube_servo2_quick_start_grou_M->Timing.t[0] = rtsiGetSolverStopTime
    (&qube_servo2_quick_start_grou_M->solverInfo);

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
    if (!(++qube_servo2_quick_start_grou_M->Timing.clockTick1)) {
      ++qube_servo2_quick_start_grou_M->Timing.clockTickH1;
    }

    qube_servo2_quick_start_grou_M->Timing.t[1] =
      qube_servo2_quick_start_grou_M->Timing.clockTick1 *
      qube_servo2_quick_start_grou_M->Timing.stepSize1 +
      qube_servo2_quick_start_grou_M->Timing.clockTickH1 *
      qube_servo2_quick_start_grou_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void qube_servo2_quick_start_groupA_derivatives(void)
{
  XDot_qube_servo2_quick_start__T *_rtXdot;
  _rtXdot = ((XDot_qube_servo2_quick_start__T *)
             qube_servo2_quick_start_grou_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Servo Velocity' */
  _rtXdot->ServoVelocity_CSTATE =
    qube_servo2_quick_start_group_P.ServoVelocity_A *
    qube_servo2_quick_start_group_X.ServoVelocity_CSTATE;
  _rtXdot->ServoVelocity_CSTATE +=
    qube_servo2_quick_start_group_B.NegativeFeedback;
}

/* Model initialize function */
void qube_servo2_quick_start_groupA_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: qube_servo2_quick_start_groupA/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &qube_servo2_quick_start_grou_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear
      (qube_servo2_quick_start_grou_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
      return;
    }

    if ((qube_servo2_quick_start_group_P.HILInitialize_AIPStart && !is_switching)
        || (qube_servo2_quick_start_group_P.HILInitialize_AIPEnter &&
            is_switching)) {
      result = hil_set_analog_input_ranges
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         &qube_servo2_quick_start_group_P.HILInitialize_AIChannels, 1U,
         &qube_servo2_quick_start_group_P.HILInitialize_AILow,
         &qube_servo2_quick_start_group_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }

    if ((qube_servo2_quick_start_group_P.HILInitialize_AOPStart && !is_switching)
        || (qube_servo2_quick_start_group_P.HILInitialize_AOPEnter &&
            is_switching)) {
      result = hil_set_analog_output_ranges
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         &qube_servo2_quick_start_group_P.HILInitialize_AOChannels, 1U,
         &qube_servo2_quick_start_group_P.HILInitialize_AOLow,
         &qube_servo2_quick_start_group_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }

    if ((qube_servo2_quick_start_group_P.HILInitialize_AOStart && !is_switching)
        || (qube_servo2_quick_start_group_P.HILInitialize_AOEnter &&
            is_switching)) {
      result = hil_write_analog
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         &qube_servo2_quick_start_group_P.HILInitialize_AOChannels, 1U,
         &qube_servo2_quick_start_group_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }

    if (qube_servo2_quick_start_group_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         &qube_servo2_quick_start_group_P.HILInitialize_AOChannels, 1U,
         &qube_servo2_quick_start_group_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (qube_servo2_quick_start_grou_DW.HILInitialize_Card, NULL, 0U,
       &qube_servo2_quick_start_group_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
      return;
    }

    if ((qube_servo2_quick_start_group_P.HILInitialize_DOStart && !is_switching)
        || (qube_servo2_quick_start_group_P.HILInitialize_DOEnter &&
            is_switching)) {
      result = hil_write_digital
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         &qube_servo2_quick_start_group_P.HILInitialize_DOChannels, 1U,
         (t_boolean *) &qube_servo2_quick_start_group_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }

    if (qube_servo2_quick_start_group_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         &qube_servo2_quick_start_group_P.HILInitialize_DOChannels, 1U, (const
          t_digital_state *)
         &qube_servo2_quick_start_group_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }

    if ((qube_servo2_quick_start_group_P.HILInitialize_EIPStart && !is_switching)
        || (qube_servo2_quick_start_group_P.HILInitialize_EIPEnter &&
            is_switching)) {
      qube_servo2_quick_start_grou_DW.HILInitialize_QuadratureModes[0] =
        qube_servo2_quick_start_group_P.HILInitialize_EIQuadrature;
      qube_servo2_quick_start_grou_DW.HILInitialize_QuadratureModes[1] =
        qube_servo2_quick_start_group_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         qube_servo2_quick_start_group_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &qube_servo2_quick_start_grou_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }

    if ((qube_servo2_quick_start_group_P.HILInitialize_EIStart && !is_switching)
        || (qube_servo2_quick_start_group_P.HILInitialize_EIEnter &&
            is_switching)) {
      qube_servo2_quick_start_grou_DW.HILInitialize_InitialEICounts[0] =
        qube_servo2_quick_start_group_P.HILInitialize_EIInitial;
      qube_servo2_quick_start_grou_DW.HILInitialize_InitialEICounts[1] =
        qube_servo2_quick_start_group_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         qube_servo2_quick_start_group_P.HILInitialize_EIChannels, 2U,
         &qube_servo2_quick_start_grou_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }

    if ((qube_servo2_quick_start_group_P.HILInitialize_OOStart && !is_switching)
        || (qube_servo2_quick_start_group_P.HILInitialize_OOEnter &&
            is_switching)) {
      result = hil_write_other
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         qube_servo2_quick_start_group_P.HILInitialize_OOChannels, 3U,
         qube_servo2_quick_start_group_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }

    if (qube_servo2_quick_start_group_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
         qube_servo2_quick_start_group_P.HILInitialize_OOChannels, 3U,
         qube_servo2_quick_start_group_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: qube_servo2_quick_start_groupA/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
       qube_servo2_quick_start_group_P.HILReadEncoderTimebase_SamplesI,
       &qube_servo2_quick_start_group_P.HILReadEncoderTimebase_Channels, 1,
       &qube_servo2_quick_start_grou_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (qube_servo2_quick_start_grou_DW.HILReadEncoderTimebase_Task,
         (t_buffer_overflow_mode)
         (qube_servo2_quick_start_group_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */

  /* S-Function Block: qube_servo2_quick_start_groupA/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 /
      qube_servo2_quick_start_group_P.SmoothSignalGenerator_Frequency;
    qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Amp =
      qube_servo2_quick_start_group_P.SmoothSignalGenerator_Amplitude;
    qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      qube_servo2_quick_start_group_P.SmoothSignalGenerator_Frequency;
    qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      ((qube_servo2_quick_start_group_P.SmoothSignalGenerator_InitialPh));
    qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      ((qube_servo2_quick_start_group_P.SmoothSignalGenerator_InitialPh));
  }

  /* InitializeConditions for TransferFcn: '<Root>/Servo Velocity' */
  qube_servo2_quick_start_group_X.ServoVelocity_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  qube_servo2_quick_start_grou_DW.DiscreteTimeIntegrator_DSTATE =
    qube_servo2_quick_start_group_P.DiscreteTimeIntegrator_IC;
  qube_servo2_quick_start_grou_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void qube_servo2_quick_start_groupA_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: qube_servo2_quick_start_groupA/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(qube_servo2_quick_start_grou_DW.HILInitialize_Card);
    hil_monitor_stop_all(qube_servo2_quick_start_grou_DW.HILInitialize_Card);
    is_switching = false;
    if ((qube_servo2_quick_start_group_P.HILInitialize_AOTerminate &&
         !is_switching) || (qube_servo2_quick_start_group_P.HILInitialize_AOExit
         && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((qube_servo2_quick_start_group_P.HILInitialize_DOTerminate &&
         !is_switching) || (qube_servo2_quick_start_group_P.HILInitialize_DOExit
         && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((qube_servo2_quick_start_group_P.HILInitialize_OOTerminate &&
         !is_switching) || (qube_servo2_quick_start_group_P.HILInitialize_OOExit
         && is_switching)) {
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
      result = hil_write(qube_servo2_quick_start_grou_DW.HILInitialize_Card
                         ,
                         &qube_servo2_quick_start_group_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         ,
                         &qube_servo2_quick_start_group_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         ,
                         qube_servo2_quick_start_group_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         ,
                         &qube_servo2_quick_start_group_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *)
                         &qube_servo2_quick_start_group_P.HILInitialize_DOFinal
                         , qube_servo2_quick_start_group_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
             &qube_servo2_quick_start_group_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &qube_servo2_quick_start_group_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
             &qube_servo2_quick_start_group_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &qube_servo2_quick_start_group_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (qube_servo2_quick_start_grou_DW.HILInitialize_Card,
             qube_servo2_quick_start_group_P.HILInitialize_OOChannels,
             num_final_other_outputs,
             qube_servo2_quick_start_group_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(qube_servo2_quick_start_grou_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(qube_servo2_quick_start_grou_DW.HILInitialize_Card);
    hil_monitor_delete_all(qube_servo2_quick_start_grou_DW.HILInitialize_Card);
    hil_close(qube_servo2_quick_start_grou_DW.HILInitialize_Card);
    qube_servo2_quick_start_grou_DW.HILInitialize_Card = NULL;
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
  qube_servo2_quick_start_groupA_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  qube_servo2_quick_start_groupA_update();
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
  qube_servo2_quick_start_groupA_initialize();
}

void MdlTerminate(void)
{
  qube_servo2_quick_start_groupA_terminate();
}

/* Registration function */
RT_MODEL_qube_servo2_quick_st_T *qube_servo2_quick_start_groupA(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)qube_servo2_quick_start_grou_M, 0,
                sizeof(RT_MODEL_qube_servo2_quick_st_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&qube_servo2_quick_start_grou_M->solverInfo,
                          &qube_servo2_quick_start_grou_M->Timing.simTimeStep);
    rtsiSetTPtr(&qube_servo2_quick_start_grou_M->solverInfo, &rtmGetTPtr
                (qube_servo2_quick_start_grou_M));
    rtsiSetStepSizePtr(&qube_servo2_quick_start_grou_M->solverInfo,
                       &qube_servo2_quick_start_grou_M->Timing.stepSize0);
    rtsiSetdXPtr(&qube_servo2_quick_start_grou_M->solverInfo,
                 &qube_servo2_quick_start_grou_M->derivs);
    rtsiSetContStatesPtr(&qube_servo2_quick_start_grou_M->solverInfo, (real_T **)
                         &qube_servo2_quick_start_grou_M->contStates);
    rtsiSetNumContStatesPtr(&qube_servo2_quick_start_grou_M->solverInfo,
      &qube_servo2_quick_start_grou_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&qube_servo2_quick_start_grou_M->solverInfo,
      &qube_servo2_quick_start_grou_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&qube_servo2_quick_start_grou_M->solverInfo,
       &qube_servo2_quick_start_grou_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&qube_servo2_quick_start_grou_M->solverInfo,
       &qube_servo2_quick_start_grou_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&qube_servo2_quick_start_grou_M->solverInfo,
                          (&rtmGetErrorStatus(qube_servo2_quick_start_grou_M)));
    rtsiSetRTModelPtr(&qube_servo2_quick_start_grou_M->solverInfo,
                      qube_servo2_quick_start_grou_M);
  }

  rtsiSetSimTimeStep(&qube_servo2_quick_start_grou_M->solverInfo,
                     MAJOR_TIME_STEP);
  qube_servo2_quick_start_grou_M->intgData.f[0] =
    qube_servo2_quick_start_grou_M->odeF[0];
  qube_servo2_quick_start_grou_M->contStates = ((real_T *)
    &qube_servo2_quick_start_group_X);
  rtsiSetSolverData(&qube_servo2_quick_start_grou_M->solverInfo, (void *)
                    &qube_servo2_quick_start_grou_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange
    (&qube_servo2_quick_start_grou_M->solverInfo, false);
  rtsiSetSolverName(&qube_servo2_quick_start_grou_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      qube_servo2_quick_start_grou_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "qube_servo2_quick_start_grou_M points to
       static memory which is guaranteed to be non-NULL" */
    qube_servo2_quick_start_grou_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    qube_servo2_quick_start_grou_M->Timing.sampleTimes =
      (&qube_servo2_quick_start_grou_M->Timing.sampleTimesArray[0]);
    qube_servo2_quick_start_grou_M->Timing.offsetTimes =
      (&qube_servo2_quick_start_grou_M->Timing.offsetTimesArray[0]);

    /* task periods */
    qube_servo2_quick_start_grou_M->Timing.sampleTimes[0] = (0.0);
    qube_servo2_quick_start_grou_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    qube_servo2_quick_start_grou_M->Timing.offsetTimes[0] = (0.0);
    qube_servo2_quick_start_grou_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(qube_servo2_quick_start_grou_M,
             &qube_servo2_quick_start_grou_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = qube_servo2_quick_start_grou_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    qube_servo2_quick_start_grou_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(qube_servo2_quick_start_grou_M, -1);
  qube_servo2_quick_start_grou_M->Timing.stepSize0 = 0.002;
  qube_servo2_quick_start_grou_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  qube_servo2_quick_start_grou_M->Sizes.checksums[0] = (1676564951U);
  qube_servo2_quick_start_grou_M->Sizes.checksums[1] = (1340911017U);
  qube_servo2_quick_start_grou_M->Sizes.checksums[2] = (1081631097U);
  qube_servo2_quick_start_grou_M->Sizes.checksums[3] = (2057348402U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    qube_servo2_quick_start_grou_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(qube_servo2_quick_start_grou_M->extModeInfo,
      &qube_servo2_quick_start_grou_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(qube_servo2_quick_start_grou_M->extModeInfo,
                        qube_servo2_quick_start_grou_M->Sizes.checksums);
    rteiSetTPtr(qube_servo2_quick_start_grou_M->extModeInfo, rtmGetTPtr
                (qube_servo2_quick_start_grou_M));
  }

  qube_servo2_quick_start_grou_M->solverInfoPtr =
    (&qube_servo2_quick_start_grou_M->solverInfo);
  qube_servo2_quick_start_grou_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&qube_servo2_quick_start_grou_M->solverInfo, 0.002);
  rtsiSetSolverMode(&qube_servo2_quick_start_grou_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  qube_servo2_quick_start_grou_M->blockIO = ((void *)
    &qube_servo2_quick_start_group_B);
  (void) memset(((void *) &qube_servo2_quick_start_group_B), 0,
                sizeof(B_qube_servo2_quick_start_gro_T));

  {
    qube_servo2_quick_start_group_B.SliderGain = 0.0;
    qube_servo2_quick_start_group_B.NegativeFeedback = 0.0;
    qube_servo2_quick_start_group_B.ServoVelocity = 0.0;
    qube_servo2_quick_start_group_B.Sum1 = 0.0;
    qube_servo2_quick_start_group_B.Gain[0] = 0.0;
    qube_servo2_quick_start_group_B.Gain[1] = 0.0;
    qube_servo2_quick_start_group_B.DataTypeConversion = 0.0;
  }

  /* parameters */
  qube_servo2_quick_start_grou_M->defaultParam = ((real_T *)
    &qube_servo2_quick_start_group_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &qube_servo2_quick_start_group_X;
    qube_servo2_quick_start_grou_M->contStates = (x);
    (void) memset((void *)&qube_servo2_quick_start_group_X, 0,
                  sizeof(X_qube_servo2_quick_start_gro_T));
  }

  /* states (dwork) */
  qube_servo2_quick_start_grou_M->dwork = ((void *)
    &qube_servo2_quick_start_grou_DW);
  (void) memset((void *)&qube_servo2_quick_start_grou_DW, 0,
                sizeof(DW_qube_servo2_quick_start_gr_T));
  qube_servo2_quick_start_grou_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  qube_servo2_quick_start_grou_DW.HILInitialize_FilterFrequency[0] = 0.0;
  qube_servo2_quick_start_grou_DW.HILInitialize_FilterFrequency[1] = 0.0;
  qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Amp = 0.0;
  qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.W = 0.0;
  qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = 0.0;
  qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = 0.0;
  qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0.0;
  qube_servo2_quick_start_grou_DW.SmoothSignalGenerator_RWORK.Cos_w_t = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    qube_servo2_quick_start_grou_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  qube_servo2_quick_start_grou_M->Sizes.numContStates = (1);/* Number of continuous states */
  qube_servo2_quick_start_grou_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  qube_servo2_quick_start_grou_M->Sizes.numY = (0);/* Number of model outputs */
  qube_servo2_quick_start_grou_M->Sizes.numU = (0);/* Number of model inputs */
  qube_servo2_quick_start_grou_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  qube_servo2_quick_start_grou_M->Sizes.numSampTimes = (2);/* Number of sample times */
  qube_servo2_quick_start_grou_M->Sizes.numBlocks = (32);/* Number of blocks */
  qube_servo2_quick_start_grou_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  qube_servo2_quick_start_grou_M->Sizes.numBlockPrms = (94);/* Sum of parameter "widths" */
  return qube_servo2_quick_start_grou_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
