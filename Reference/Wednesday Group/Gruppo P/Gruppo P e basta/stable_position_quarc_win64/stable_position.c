/*
 * stable_position.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "stable_position".
 *
 * Model version              : 8.3
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Oct 25 19:02:59 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "stable_position.h"
#include "rtwtypes.h"
#include "stable_position_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>
#include <string.h>
#include "stable_position_dt.h"

/* Block signals (default storage) */
B_stable_position_T stable_position_B;

/* Continuous states */
X_stable_position_T stable_position_X;

/* Block states (default storage) */
DW_stable_position_T stable_position_DW;

/* Real-time model */
static RT_MODEL_stable_position_T stable_position_M_;
RT_MODEL_stable_position_T *const stable_position_M = &stable_position_M_;

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
  stable_position_derivatives();
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
void stable_position_output(void)
{
  real_T rtb_Armcountstorad;
  real_T rtb_MathFunction;
  if (rtmIsMajorTimeStep(stable_position_M)) {
    /* set solver stop time */
    if (!(stable_position_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&stable_position_M->solverInfo,
                            ((stable_position_M->Timing.clockTickH0 + 1) *
        stable_position_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&stable_position_M->solverInfo,
                            ((stable_position_M->Timing.clockTick0 + 1) *
        stable_position_M->Timing.stepSize0 +
        stable_position_M->Timing.clockTickH0 *
        stable_position_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(stable_position_M)) {
    stable_position_M->Timing.t[0] = rtsiGetT(&stable_position_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(stable_position_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

    /* S-Function Block: stable_position/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (stable_position_DW.HILReadEncoderTimebase_Task, 1,
         &stable_position_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        rtb_Armcountstorad = 0;
        rtb_MathFunction = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
      } else {
        rtb_Armcountstorad = stable_position_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_MathFunction = stable_position_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }

    /* Math: '<S7>/Math Function' incorporates:
     *  Constant: '<S7>/Constant1'
     *  Gain: '<S7>/Pendulum:  counts to rad'
     */
    rtb_MathFunction = rt_modd_snf(stable_position_P.Pendulumcountstorad_Gain *
      rtb_MathFunction, stable_position_P.Constant1_Value);

    /* Gain: '<S4>/Gain' */
    stable_position_B.Gain = stable_position_P.Gain_Gain * rtb_MathFunction;

    /* Constant: '<Root>/Constant1' */
    stable_position_B.Constant1 = stable_position_P.Constant1_Value_k;

    /* Gain: '<S7>/Arm: counts to rad' */
    rtb_Armcountstorad *= stable_position_P.Armcountstorad_Gain;

    /* Gain: '<S3>/Gain' */
    stable_position_B.Gain_i = stable_position_P.Gain_Gain_e *
      rtb_Armcountstorad;

    /* Gain: '<Root>/kp_theta' incorporates:
     *  Gain: '<S1>/Gain1'
     *  Sum: '<Root>/Sum1'
     */
    stable_position_B.kp_theta = (stable_position_P.Gain1_Gain *
      stable_position_B.Constant1 - rtb_Armcountstorad) *
      stable_position_P.kp_theta_Gain;

    /* Gain: '<Root>/-theta' */
    stable_position_B.theta = stable_position_P.theta_Gain * rtb_Armcountstorad;

    /* Gain: '<Root>/-alpha' */
    stable_position_B.alpha = stable_position_P.alpha_Gain * rtb_MathFunction;

    /* Gain: '<Root>/kp_alpha' */
    stable_position_B.kp_alpha = stable_position_P.kp_alpha_Gain *
      stable_position_B.alpha;
  }

  /* Gain: '<Root>/kd_theta' incorporates:
   *  TransferFcn: '<Root>/theta_dot'
   */
  rtb_Armcountstorad = (stable_position_P.theta_dot_C *
                        stable_position_X.theta_dot_CSTATE +
                        stable_position_P.theta_dot_D * stable_position_B.theta)
    * stable_position_P.kd_theta_Gain;

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/kd_alpha'
   *  TransferFcn: '<Root>/alpha_dot'
   */
  rtb_Armcountstorad = (stable_position_P.alpha_dot_C *
                        stable_position_X.alpha_dot_CSTATE +
                        stable_position_P.alpha_dot_D * stable_position_B.alpha)
    * stable_position_P.kd_alpha_Gain + ((stable_position_B.kp_theta +
    rtb_Armcountstorad) + stable_position_B.kp_alpha);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Armcountstorad > stable_position_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    stable_position_B.Saturation = stable_position_P.Saturation_UpperSat;
  } else if (rtb_Armcountstorad < stable_position_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    stable_position_B.Saturation = stable_position_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    stable_position_B.Saturation = rtb_Armcountstorad;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(stable_position_M)) {
  }

  /* Gain: '<S6>/For +ve CCW' */
  stable_position_B.ForveCCW = stable_position_P.ForveCCW_Gain *
    stable_position_B.Saturation;
  if (rtmIsMajorTimeStep(stable_position_M)) {
    /* S-Function (hil_write_analog_block): '<S6>/HIL Write Analog' */

    /* S-Function Block: stable_position/Rotary Pendulum Interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(stable_position_DW.HILInitialize_Card,
        &stable_position_P.HILWriteAnalog_channels, 1,
        &stable_position_B.ForveCCW);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void stable_position_update(void)
{
  if (rtmIsMajorTimeStep(stable_position_M)) {
    rt_ertODEUpdateContinuousStates(&stable_position_M->solverInfo);
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
  if (!(++stable_position_M->Timing.clockTick0)) {
    ++stable_position_M->Timing.clockTickH0;
  }

  stable_position_M->Timing.t[0] = rtsiGetSolverStopTime
    (&stable_position_M->solverInfo);

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
    if (!(++stable_position_M->Timing.clockTick1)) {
      ++stable_position_M->Timing.clockTickH1;
    }

    stable_position_M->Timing.t[1] = stable_position_M->Timing.clockTick1 *
      stable_position_M->Timing.stepSize1 +
      stable_position_M->Timing.clockTickH1 *
      stable_position_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void stable_position_derivatives(void)
{
  XDot_stable_position_T *_rtXdot;
  _rtXdot = ((XDot_stable_position_T *) stable_position_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = stable_position_P.theta_dot_A *
    stable_position_X.theta_dot_CSTATE;
  _rtXdot->theta_dot_CSTATE += stable_position_B.theta;

  /* Derivatives for TransferFcn: '<Root>/alpha_dot' */
  _rtXdot->alpha_dot_CSTATE = stable_position_P.alpha_dot_A *
    stable_position_X.alpha_dot_CSTATE;
  _rtXdot->alpha_dot_CSTATE += stable_position_B.alpha;
}

/* Model initialize function */
void stable_position_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: stable_position/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &stable_position_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stable_position_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(stable_position_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stable_position_M, _rt_error_message);
      return;
    }

    if ((stable_position_P.HILInitialize_AIPStart && !is_switching) ||
        (stable_position_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(stable_position_DW.HILInitialize_Card,
        &stable_position_P.HILInitialize_AIChannels, 1U,
        &stable_position_P.HILInitialize_AILow,
        &stable_position_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }

    if ((stable_position_P.HILInitialize_AOPStart && !is_switching) ||
        (stable_position_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges
        (stable_position_DW.HILInitialize_Card,
         &stable_position_P.HILInitialize_AOChannels, 1U,
         &stable_position_P.HILInitialize_AOLow,
         &stable_position_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }

    if ((stable_position_P.HILInitialize_AOStart && !is_switching) ||
        (stable_position_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(stable_position_DW.HILInitialize_Card,
        &stable_position_P.HILInitialize_AOChannels, 1U,
        &stable_position_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }

    if (stable_position_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (stable_position_DW.HILInitialize_Card,
         &stable_position_P.HILInitialize_AOChannels, 1U,
         &stable_position_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(stable_position_DW.HILInitialize_Card,
      NULL, 0U, &stable_position_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stable_position_M, _rt_error_message);
      return;
    }

    if ((stable_position_P.HILInitialize_DOStart && !is_switching) ||
        (stable_position_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(stable_position_DW.HILInitialize_Card,
        &stable_position_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &stable_position_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }

    if (stable_position_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (stable_position_DW.HILInitialize_Card,
         &stable_position_P.HILInitialize_DOChannels, 1U, (const t_digital_state
          *) &stable_position_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }

    if ((stable_position_P.HILInitialize_EIPStart && !is_switching) ||
        (stable_position_P.HILInitialize_EIPEnter && is_switching)) {
      stable_position_DW.HILInitialize_QuadratureModes[0] =
        stable_position_P.HILInitialize_EIQuadrature;
      stable_position_DW.HILInitialize_QuadratureModes[1] =
        stable_position_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (stable_position_DW.HILInitialize_Card,
         stable_position_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &stable_position_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }

    if ((stable_position_P.HILInitialize_EIStart && !is_switching) ||
        (stable_position_P.HILInitialize_EIEnter && is_switching)) {
      stable_position_DW.HILInitialize_InitialEICounts[0] =
        stable_position_P.HILInitialize_EIInitial;
      stable_position_DW.HILInitialize_InitialEICounts[1] =
        stable_position_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(stable_position_DW.HILInitialize_Card,
        stable_position_P.HILInitialize_EIChannels, 2U,
        &stable_position_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }

    if ((stable_position_P.HILInitialize_OOStart && !is_switching) ||
        (stable_position_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(stable_position_DW.HILInitialize_Card,
        stable_position_P.HILInitialize_OOChannels, 3U,
        stable_position_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }

    if (stable_position_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (stable_position_DW.HILInitialize_Card,
         stable_position_P.HILInitialize_OOChannels, 3U,
         stable_position_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(stable_position_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

  /* S-Function Block: stable_position/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (stable_position_DW.HILInitialize_Card,
       stable_position_P.HILReadEncoderTimebase_SamplesI,
       stable_position_P.HILReadEncoderTimebase_Channels, 2,
       &stable_position_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (stable_position_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (stable_position_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(stable_position_M, _rt_error_message);
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/theta_dot' */
  stable_position_X.theta_dot_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/alpha_dot' */
  stable_position_X.alpha_dot_CSTATE = 0.0;
}

/* Model terminate function */
void stable_position_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: stable_position/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(stable_position_DW.HILInitialize_Card);
    hil_monitor_stop_all(stable_position_DW.HILInitialize_Card);
    is_switching = false;
    if ((stable_position_P.HILInitialize_AOTerminate && !is_switching) ||
        (stable_position_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((stable_position_P.HILInitialize_DOTerminate && !is_switching) ||
        (stable_position_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((stable_position_P.HILInitialize_OOTerminate && !is_switching) ||
        (stable_position_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(stable_position_DW.HILInitialize_Card
                         , &stable_position_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &stable_position_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , stable_position_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &stable_position_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *)
                         &stable_position_P.HILInitialize_DOFinal
                         , stable_position_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(stable_position_DW.HILInitialize_Card,
            &stable_position_P.HILInitialize_AOChannels,
            num_final_analog_outputs, &stable_position_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(stable_position_DW.HILInitialize_Card,
            &stable_position_P.HILInitialize_DOChannels,
            num_final_digital_outputs, (t_boolean *)
            &stable_position_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(stable_position_DW.HILInitialize_Card,
            stable_position_P.HILInitialize_OOChannels, num_final_other_outputs,
            stable_position_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(stable_position_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(stable_position_DW.HILInitialize_Card);
    hil_monitor_delete_all(stable_position_DW.HILInitialize_Card);
    hil_close(stable_position_DW.HILInitialize_Card);
    stable_position_DW.HILInitialize_Card = NULL;
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
  stable_position_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  stable_position_update();
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
  stable_position_initialize();
}

void MdlTerminate(void)
{
  stable_position_terminate();
}

/* Registration function */
RT_MODEL_stable_position_T *stable_position(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)stable_position_M, 0,
                sizeof(RT_MODEL_stable_position_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&stable_position_M->solverInfo,
                          &stable_position_M->Timing.simTimeStep);
    rtsiSetTPtr(&stable_position_M->solverInfo, &rtmGetTPtr(stable_position_M));
    rtsiSetStepSizePtr(&stable_position_M->solverInfo,
                       &stable_position_M->Timing.stepSize0);
    rtsiSetdXPtr(&stable_position_M->solverInfo, &stable_position_M->derivs);
    rtsiSetContStatesPtr(&stable_position_M->solverInfo, (real_T **)
                         &stable_position_M->contStates);
    rtsiSetNumContStatesPtr(&stable_position_M->solverInfo,
      &stable_position_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&stable_position_M->solverInfo,
      &stable_position_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&stable_position_M->solverInfo,
      &stable_position_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&stable_position_M->solverInfo,
      &stable_position_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&stable_position_M->solverInfo, (&rtmGetErrorStatus
      (stable_position_M)));
    rtsiSetRTModelPtr(&stable_position_M->solverInfo, stable_position_M);
  }

  rtsiSetSimTimeStep(&stable_position_M->solverInfo, MAJOR_TIME_STEP);
  stable_position_M->intgData.f[0] = stable_position_M->odeF[0];
  stable_position_M->contStates = ((real_T *) &stable_position_X);
  rtsiSetSolverData(&stable_position_M->solverInfo, (void *)
                    &stable_position_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&stable_position_M->solverInfo, false);
  rtsiSetSolverName(&stable_position_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = stable_position_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "stable_position_M points to
       static memory which is guaranteed to be non-NULL" */
    stable_position_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    stable_position_M->Timing.sampleTimes =
      (&stable_position_M->Timing.sampleTimesArray[0]);
    stable_position_M->Timing.offsetTimes =
      (&stable_position_M->Timing.offsetTimesArray[0]);

    /* task periods */
    stable_position_M->Timing.sampleTimes[0] = (0.0);
    stable_position_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    stable_position_M->Timing.offsetTimes[0] = (0.0);
    stable_position_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(stable_position_M, &stable_position_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = stable_position_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    stable_position_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(stable_position_M, -1);
  stable_position_M->Timing.stepSize0 = 0.002;
  stable_position_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  stable_position_M->Sizes.checksums[0] = (1670500445U);
  stable_position_M->Sizes.checksums[1] = (538276601U);
  stable_position_M->Sizes.checksums[2] = (1355446936U);
  stable_position_M->Sizes.checksums[3] = (2341386863U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    stable_position_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(stable_position_M->extModeInfo,
      &stable_position_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(stable_position_M->extModeInfo,
                        stable_position_M->Sizes.checksums);
    rteiSetTPtr(stable_position_M->extModeInfo, rtmGetTPtr(stable_position_M));
  }

  stable_position_M->solverInfoPtr = (&stable_position_M->solverInfo);
  stable_position_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&stable_position_M->solverInfo, 0.002);
  rtsiSetSolverMode(&stable_position_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  stable_position_M->blockIO = ((void *) &stable_position_B);
  (void) memset(((void *) &stable_position_B), 0,
                sizeof(B_stable_position_T));

  /* parameters */
  stable_position_M->defaultParam = ((real_T *)&stable_position_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &stable_position_X;
    stable_position_M->contStates = (x);
    (void) memset((void *)&stable_position_X, 0,
                  sizeof(X_stable_position_T));
  }

  /* states (dwork) */
  stable_position_M->dwork = ((void *) &stable_position_DW);
  (void) memset((void *)&stable_position_DW, 0,
                sizeof(DW_stable_position_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    stable_position_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  stable_position_M->Sizes.numContStates = (2);/* Number of continuous states */
  stable_position_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  stable_position_M->Sizes.numY = (0); /* Number of model outputs */
  stable_position_M->Sizes.numU = (0); /* Number of model inputs */
  stable_position_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  stable_position_M->Sizes.numSampTimes = (2);/* Number of sample times */
  stable_position_M->Sizes.numBlocks = (26);/* Number of blocks */
  stable_position_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  stable_position_M->Sizes.numBlockPrms = (97);/* Sum of parameter "widths" */
  return stable_position_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
