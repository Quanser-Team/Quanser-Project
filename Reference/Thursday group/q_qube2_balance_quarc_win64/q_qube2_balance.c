/*
 * q_qube2_balance.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "q_qube2_balance".
 *
 * Model version              : 1.40
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Feb 23 10:49:35 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "q_qube2_balance.h"
#include "rtwtypes.h"
#include "q_qube2_balance_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>
#include <string.h>
#include "q_qube2_balance_dt.h"

/* Block signals (default storage) */
B_q_qube2_balance_T q_qube2_balance_B;

/* Continuous states */
X_q_qube2_balance_T q_qube2_balance_X;

/* Block states (default storage) */
DW_q_qube2_balance_T q_qube2_balance_DW;

/* Real-time model */
static RT_MODEL_q_qube2_balance_T q_qube2_balance_M_;
RT_MODEL_q_qube2_balance_T *const q_qube2_balance_M = &q_qube2_balance_M_;

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
  q_qube2_balance_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model output function */
void q_qube2_balance_output(void)
{
  real_T rtb_Armcountstorad;
  real_T rtb_Bias;
  if (rtmIsMajorTimeStep(q_qube2_balance_M)) {
    /* set solver stop time */
    if (!(q_qube2_balance_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&q_qube2_balance_M->solverInfo,
                            ((q_qube2_balance_M->Timing.clockTickH0 + 1) *
        q_qube2_balance_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&q_qube2_balance_M->solverInfo,
                            ((q_qube2_balance_M->Timing.clockTick0 + 1) *
        q_qube2_balance_M->Timing.stepSize0 +
        q_qube2_balance_M->Timing.clockTickH0 *
        q_qube2_balance_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(q_qube2_balance_M)) {
    q_qube2_balance_M->Timing.t[0] = rtsiGetT(&q_qube2_balance_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(q_qube2_balance_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

    /* S-Function Block: q_qube2_balance/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (q_qube2_balance_DW.HILReadEncoderTimebase_Task, 1,
         &q_qube2_balance_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        rtb_Armcountstorad = 0;
        rtb_Bias = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
      } else {
        rtb_Armcountstorad = q_qube2_balance_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_Bias = q_qube2_balance_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Bias: '<S6>/Bias' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Gain: '<S6>/Pendulum:  counts to rad'
     *  Math: '<S6>/Math Function'
     */
    rtb_Bias = rt_modd_snf(q_qube2_balance_P.Pendulumcountstorad_Gain * rtb_Bias,
      q_qube2_balance_P.Constant1_Value) + q_qube2_balance_P.Bias_Bias;

    /* Gain: '<S4>/Gain' */
    q_qube2_balance_B.Gain = q_qube2_balance_P.Gain_Gain * rtb_Bias;

    /* Constant: '<Root>/Constant' */
    q_qube2_balance_B.Constant = q_qube2_balance_P.Constant_Value;

    /* Gain: '<S6>/Arm: counts to rad' */
    rtb_Armcountstorad *= q_qube2_balance_P.Armcountstorad_Gain;

    /* Gain: '<S3>/Gain' */
    q_qube2_balance_B.Gain_i = q_qube2_balance_P.Gain_Gain_e *
      rtb_Armcountstorad;

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Abs: '<Root>/|alpha|'
     *  Constant: '<S2>/Constant'
     */
    q_qube2_balance_B.Compare = (uint8_T)(fabs(rtb_Bias) <=
      q_qube2_balance_P.EnableBalanceControl_const);

    /* Gain: '<Root>/kp_theta' incorporates:
     *  Gain: '<S1>/Gain1'
     *  Sum: '<Root>/Sum1'
     */
    q_qube2_balance_B.kp_theta = (q_qube2_balance_P.Gain1_Gain *
      q_qube2_balance_B.Constant - rtb_Armcountstorad) *
      q_qube2_balance_P.kp_theta_Gain;

    /* Gain: '<Root>/-theta' */
    q_qube2_balance_B.theta = q_qube2_balance_P.theta_Gain * rtb_Armcountstorad;

    /* Gain: '<Root>/-alpha' */
    q_qube2_balance_B.alpha = q_qube2_balance_P.alpha_Gain * rtb_Bias;

    /* Gain: '<Root>/kp_alpha' */
    q_qube2_balance_B.kp_alpha = q_qube2_balance_P.kp_alpha_Gain *
      q_qube2_balance_B.alpha;
  }

  /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' */
  if (q_qube2_balance_B.Compare == 0) {
    /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' incorporates:
     *  Constant: '<Root>/u = 0V'
     */
    q_qube2_balance_B.EnableBalanceControlSwitch = q_qube2_balance_P.u0V_Value;
  } else {
    /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' incorporates:
     *  Gain: '<Root>/kd_alpha'
     *  Gain: '<Root>/kd_theta'
     *  Sum: '<Root>/Add'
     *  TransferFcn: '<Root>/alpha_dot'
     *  TransferFcn: '<Root>/theta_dot'
     */
    q_qube2_balance_B.EnableBalanceControlSwitch =
      (((q_qube2_balance_P.theta_dot_C * q_qube2_balance_X.theta_dot_CSTATE +
         q_qube2_balance_P.theta_dot_D * q_qube2_balance_B.theta) *
        q_qube2_balance_P.kd_theta_Gain + q_qube2_balance_B.kp_theta) +
       q_qube2_balance_B.kp_alpha) + (q_qube2_balance_P.alpha_dot_C *
      q_qube2_balance_X.alpha_dot_CSTATE + q_qube2_balance_P.alpha_dot_D *
      q_qube2_balance_B.alpha) * q_qube2_balance_P.kd_alpha_Gain;
  }

  /* End of MultiPortSwitch: '<Root>/Enable Balance Control Switch' */
  if (rtmIsMajorTimeStep(q_qube2_balance_M)) {
  }

  /* Gain: '<S5>/For +ve CCW' */
  q_qube2_balance_B.ForveCCW = q_qube2_balance_P.ForveCCW_Gain *
    q_qube2_balance_B.EnableBalanceControlSwitch;
  if (rtmIsMajorTimeStep(q_qube2_balance_M)) {
    /* S-Function (hil_write_analog_block): '<S5>/HIL Write Analog' */

    /* S-Function Block: q_qube2_balance/Rotary Pendulum Interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(q_qube2_balance_DW.HILInitialize_Card,
        &q_qube2_balance_P.HILWriteAnalog_channels, 1,
        &q_qube2_balance_B.ForveCCW);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void q_qube2_balance_update(void)
{
  if (rtmIsMajorTimeStep(q_qube2_balance_M)) {
    rt_ertODEUpdateContinuousStates(&q_qube2_balance_M->solverInfo);
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
  if (!(++q_qube2_balance_M->Timing.clockTick0)) {
    ++q_qube2_balance_M->Timing.clockTickH0;
  }

  q_qube2_balance_M->Timing.t[0] = rtsiGetSolverStopTime
    (&q_qube2_balance_M->solverInfo);

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
    if (!(++q_qube2_balance_M->Timing.clockTick1)) {
      ++q_qube2_balance_M->Timing.clockTickH1;
    }

    q_qube2_balance_M->Timing.t[1] = q_qube2_balance_M->Timing.clockTick1 *
      q_qube2_balance_M->Timing.stepSize1 +
      q_qube2_balance_M->Timing.clockTickH1 *
      q_qube2_balance_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void q_qube2_balance_derivatives(void)
{
  XDot_q_qube2_balance_T *_rtXdot;
  _rtXdot = ((XDot_q_qube2_balance_T *) q_qube2_balance_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = q_qube2_balance_P.theta_dot_A *
    q_qube2_balance_X.theta_dot_CSTATE;
  _rtXdot->theta_dot_CSTATE += q_qube2_balance_B.theta;

  /* Derivatives for TransferFcn: '<Root>/alpha_dot' */
  _rtXdot->alpha_dot_CSTATE = q_qube2_balance_P.alpha_dot_A *
    q_qube2_balance_X.alpha_dot_CSTATE;
  _rtXdot->alpha_dot_CSTATE += q_qube2_balance_B.alpha;
}

/* Model initialize function */
void q_qube2_balance_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_qube2_balance/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &q_qube2_balance_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(q_qube2_balance_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
      return;
    }

    if ((q_qube2_balance_P.HILInitialize_AIPStart && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(q_qube2_balance_DW.HILInitialize_Card,
        &q_qube2_balance_P.HILInitialize_AIChannels, 1U,
        &q_qube2_balance_P.HILInitialize_AILow,
        &q_qube2_balance_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_balance_P.HILInitialize_AOPStart && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges
        (q_qube2_balance_DW.HILInitialize_Card,
         &q_qube2_balance_P.HILInitialize_AOChannels, 1U,
         &q_qube2_balance_P.HILInitialize_AOLow,
         &q_qube2_balance_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_balance_P.HILInitialize_AOStart && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(q_qube2_balance_DW.HILInitialize_Card,
        &q_qube2_balance_P.HILInitialize_AOChannels, 1U,
        &q_qube2_balance_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }

    if (q_qube2_balance_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (q_qube2_balance_DW.HILInitialize_Card,
         &q_qube2_balance_P.HILInitialize_AOChannels, 1U,
         &q_qube2_balance_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(q_qube2_balance_DW.HILInitialize_Card,
      NULL, 0U, &q_qube2_balance_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
      return;
    }

    if ((q_qube2_balance_P.HILInitialize_DOStart && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(q_qube2_balance_DW.HILInitialize_Card,
        &q_qube2_balance_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &q_qube2_balance_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }

    if (q_qube2_balance_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (q_qube2_balance_DW.HILInitialize_Card,
         &q_qube2_balance_P.HILInitialize_DOChannels, 1U, (const t_digital_state
          *) &q_qube2_balance_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_balance_P.HILInitialize_EIPStart && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_EIPEnter && is_switching)) {
      q_qube2_balance_DW.HILInitialize_QuadratureModes[0] =
        q_qube2_balance_P.HILInitialize_EIQuadrature;
      q_qube2_balance_DW.HILInitialize_QuadratureModes[1] =
        q_qube2_balance_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (q_qube2_balance_DW.HILInitialize_Card,
         q_qube2_balance_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &q_qube2_balance_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_balance_P.HILInitialize_EIStart && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_EIEnter && is_switching)) {
      q_qube2_balance_DW.HILInitialize_InitialEICounts[0] =
        q_qube2_balance_P.HILInitialize_EIInitial;
      q_qube2_balance_DW.HILInitialize_InitialEICounts[1] =
        q_qube2_balance_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(q_qube2_balance_DW.HILInitialize_Card,
        q_qube2_balance_P.HILInitialize_EIChannels, 2U,
        &q_qube2_balance_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }

    if ((q_qube2_balance_P.HILInitialize_OOStart && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(q_qube2_balance_DW.HILInitialize_Card,
        q_qube2_balance_P.HILInitialize_OOChannels, 3U,
        q_qube2_balance_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }

    if (q_qube2_balance_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (q_qube2_balance_DW.HILInitialize_Card,
         q_qube2_balance_P.HILInitialize_OOChannels, 3U,
         q_qube2_balance_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

  /* S-Function Block: q_qube2_balance/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (q_qube2_balance_DW.HILInitialize_Card,
       q_qube2_balance_P.HILReadEncoderTimebase_SamplesI,
       q_qube2_balance_P.HILReadEncoderTimebase_Channels, 2,
       &q_qube2_balance_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (q_qube2_balance_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (q_qube2_balance_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/theta_dot' */
  q_qube2_balance_X.theta_dot_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/alpha_dot' */
  q_qube2_balance_X.alpha_dot_CSTATE = 0.0;
}

/* Model terminate function */
void q_qube2_balance_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: q_qube2_balance/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(q_qube2_balance_DW.HILInitialize_Card);
    hil_monitor_stop_all(q_qube2_balance_DW.HILInitialize_Card);
    is_switching = false;
    if ((q_qube2_balance_P.HILInitialize_AOTerminate && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((q_qube2_balance_P.HILInitialize_DOTerminate && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((q_qube2_balance_P.HILInitialize_OOTerminate && !is_switching) ||
        (q_qube2_balance_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(q_qube2_balance_DW.HILInitialize_Card
                         , &q_qube2_balance_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &q_qube2_balance_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , q_qube2_balance_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &q_qube2_balance_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *)
                         &q_qube2_balance_P.HILInitialize_DOFinal
                         , q_qube2_balance_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(q_qube2_balance_DW.HILInitialize_Card,
            &q_qube2_balance_P.HILInitialize_AOChannels,
            num_final_analog_outputs, &q_qube2_balance_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(q_qube2_balance_DW.HILInitialize_Card,
            &q_qube2_balance_P.HILInitialize_DOChannels,
            num_final_digital_outputs, (t_boolean *)
            &q_qube2_balance_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(q_qube2_balance_DW.HILInitialize_Card,
            q_qube2_balance_P.HILInitialize_OOChannels, num_final_other_outputs,
            q_qube2_balance_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(q_qube2_balance_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(q_qube2_balance_DW.HILInitialize_Card);
    hil_monitor_delete_all(q_qube2_balance_DW.HILInitialize_Card);
    hil_close(q_qube2_balance_DW.HILInitialize_Card);
    q_qube2_balance_DW.HILInitialize_Card = NULL;
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
  q_qube2_balance_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  q_qube2_balance_update();
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
  q_qube2_balance_initialize();
}

void MdlTerminate(void)
{
  q_qube2_balance_terminate();
}

/* Registration function */
RT_MODEL_q_qube2_balance_T *q_qube2_balance(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)q_qube2_balance_M, 0,
                sizeof(RT_MODEL_q_qube2_balance_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&q_qube2_balance_M->solverInfo,
                          &q_qube2_balance_M->Timing.simTimeStep);
    rtsiSetTPtr(&q_qube2_balance_M->solverInfo, &rtmGetTPtr(q_qube2_balance_M));
    rtsiSetStepSizePtr(&q_qube2_balance_M->solverInfo,
                       &q_qube2_balance_M->Timing.stepSize0);
    rtsiSetdXPtr(&q_qube2_balance_M->solverInfo, &q_qube2_balance_M->derivs);
    rtsiSetContStatesPtr(&q_qube2_balance_M->solverInfo, (real_T **)
                         &q_qube2_balance_M->contStates);
    rtsiSetNumContStatesPtr(&q_qube2_balance_M->solverInfo,
      &q_qube2_balance_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&q_qube2_balance_M->solverInfo,
      &q_qube2_balance_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&q_qube2_balance_M->solverInfo,
      &q_qube2_balance_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&q_qube2_balance_M->solverInfo,
      &q_qube2_balance_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&q_qube2_balance_M->solverInfo, (&rtmGetErrorStatus
      (q_qube2_balance_M)));
    rtsiSetRTModelPtr(&q_qube2_balance_M->solverInfo, q_qube2_balance_M);
  }

  rtsiSetSimTimeStep(&q_qube2_balance_M->solverInfo, MAJOR_TIME_STEP);
  q_qube2_balance_M->intgData.f[0] = q_qube2_balance_M->odeF[0];
  q_qube2_balance_M->contStates = ((real_T *) &q_qube2_balance_X);
  rtsiSetSolverData(&q_qube2_balance_M->solverInfo, (void *)
                    &q_qube2_balance_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&q_qube2_balance_M->solverInfo, false);
  rtsiSetSolverName(&q_qube2_balance_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = q_qube2_balance_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "q_qube2_balance_M points to
       static memory which is guaranteed to be non-NULL" */
    q_qube2_balance_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    q_qube2_balance_M->Timing.sampleTimes =
      (&q_qube2_balance_M->Timing.sampleTimesArray[0]);
    q_qube2_balance_M->Timing.offsetTimes =
      (&q_qube2_balance_M->Timing.offsetTimesArray[0]);

    /* task periods */
    q_qube2_balance_M->Timing.sampleTimes[0] = (0.0);
    q_qube2_balance_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    q_qube2_balance_M->Timing.offsetTimes[0] = (0.0);
    q_qube2_balance_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(q_qube2_balance_M, &q_qube2_balance_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = q_qube2_balance_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    q_qube2_balance_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(q_qube2_balance_M, -1);
  q_qube2_balance_M->Timing.stepSize0 = 0.002;
  q_qube2_balance_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  q_qube2_balance_M->Sizes.checksums[0] = (2269776708U);
  q_qube2_balance_M->Sizes.checksums[1] = (2939765043U);
  q_qube2_balance_M->Sizes.checksums[2] = (1314399273U);
  q_qube2_balance_M->Sizes.checksums[3] = (1939248864U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    q_qube2_balance_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(q_qube2_balance_M->extModeInfo,
      &q_qube2_balance_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(q_qube2_balance_M->extModeInfo,
                        q_qube2_balance_M->Sizes.checksums);
    rteiSetTPtr(q_qube2_balance_M->extModeInfo, rtmGetTPtr(q_qube2_balance_M));
  }

  q_qube2_balance_M->solverInfoPtr = (&q_qube2_balance_M->solverInfo);
  q_qube2_balance_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&q_qube2_balance_M->solverInfo, 0.002);
  rtsiSetSolverMode(&q_qube2_balance_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  q_qube2_balance_M->blockIO = ((void *) &q_qube2_balance_B);
  (void) memset(((void *) &q_qube2_balance_B), 0,
                sizeof(B_q_qube2_balance_T));

  /* parameters */
  q_qube2_balance_M->defaultParam = ((real_T *)&q_qube2_balance_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &q_qube2_balance_X;
    q_qube2_balance_M->contStates = (x);
    (void) memset((void *)&q_qube2_balance_X, 0,
                  sizeof(X_q_qube2_balance_T));
  }

  /* states (dwork) */
  q_qube2_balance_M->dwork = ((void *) &q_qube2_balance_DW);
  (void) memset((void *)&q_qube2_balance_DW, 0,
                sizeof(DW_q_qube2_balance_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    q_qube2_balance_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  q_qube2_balance_M->Sizes.numContStates = (2);/* Number of continuous states */
  q_qube2_balance_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  q_qube2_balance_M->Sizes.numY = (0); /* Number of model outputs */
  q_qube2_balance_M->Sizes.numU = (0); /* Number of model inputs */
  q_qube2_balance_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  q_qube2_balance_M->Sizes.numSampTimes = (2);/* Number of sample times */
  q_qube2_balance_M->Sizes.numBlocks = (32);/* Number of blocks */
  q_qube2_balance_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  q_qube2_balance_M->Sizes.numBlockPrms = (98);/* Sum of parameter "widths" */
  return q_qube2_balance_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
