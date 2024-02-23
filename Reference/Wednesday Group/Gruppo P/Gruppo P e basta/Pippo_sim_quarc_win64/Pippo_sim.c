/*
 * Pippo_sim.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Pippo_sim".
 *
 * Model version              : 9.10
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Oct 25 19:04:16 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pippo_sim.h"
#include "rtwtypes.h"
#include "Pippo_sim_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Pippo_sim_dt.h"

/* Block signals (default storage) */
B_Pippo_sim_T Pippo_sim_B;

/* Continuous states */
X_Pippo_sim_T Pippo_sim_X;

/* Block states (default storage) */
DW_Pippo_sim_T Pippo_sim_DW;

/* Real-time model */
static RT_MODEL_Pippo_sim_T Pippo_sim_M_;
RT_MODEL_Pippo_sim_T *const Pippo_sim_M = &Pippo_sim_M_;

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
  Pippo_sim_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Pippo_sim_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder4;
  real_T rtb_HILReadEncoder2;
  real_T rtb_HILReadEncoderTimebase2;
  if (rtmIsMajorTimeStep(Pippo_sim_M)) {
    /* set solver stop time */
    if (!(Pippo_sim_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Pippo_sim_M->solverInfo,
                            ((Pippo_sim_M->Timing.clockTickH0 + 1) *
        Pippo_sim_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Pippo_sim_M->solverInfo,
                            ((Pippo_sim_M->Timing.clockTick0 + 1) *
        Pippo_sim_M->Timing.stepSize0 + Pippo_sim_M->Timing.clockTickH0 *
        Pippo_sim_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Pippo_sim_M)) {
    Pippo_sim_M->Timing.t[0] = rtsiGetT(&Pippo_sim_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Pippo_sim_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase2' */

    /* S-Function Block: Pippo_sim/HIL Read Encoder Timebase2 (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(Pippo_sim_DW.HILReadEncoderTimebase2_Task,
        1, &Pippo_sim_DW.HILReadEncoderTimebase2_Buffer);
      if (result < 0) {
        rtb_HILReadEncoderTimebase2 = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase2 =
          Pippo_sim_DW.HILReadEncoderTimebase2_Buffer;
      }
    }

    /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
    rtb_HILReadEncoder2 = (Pippo_sim_DW.clockTickCounter <
      Pippo_sim_P.PulseGenerator1_Duty) && (Pippo_sim_DW.clockTickCounter >= 0) ?
      Pippo_sim_P.PulseGenerator1_Amp : 0.0;
    if (Pippo_sim_DW.clockTickCounter >= Pippo_sim_P.PulseGenerator1_Period -
        1.0) {
      Pippo_sim_DW.clockTickCounter = 0;
    } else {
      Pippo_sim_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

    /* Sum: '<Root>/Sum2' incorporates:
     *  Gain: '<Root>/Amplitude (deg)1'
     *  Gain: '<Root>/counts to rad3'
     *  Gain: '<S1>/Gain1'
     */
    Pippo_sim_B.Sum2 = Pippo_sim_P.Amplitudedeg1_Gain * rtb_HILReadEncoder2 *
      Pippo_sim_P.Gain1_Gain - Pippo_sim_P.countstorad3_Gain *
      rtb_HILReadEncoderTimebase2;
  }

  /* Gain: '<S3>/Slider Gain' incorporates:
   *  TransferFcn: '<Root>/Servo Velocity2'
   */
  rtb_HILReadEncoderTimebase2 = (Pippo_sim_P.ServoVelocity2_C *
    Pippo_sim_X.ServoVelocity2_CSTATE + Pippo_sim_P.ServoVelocity2_D *
    Pippo_sim_B.Sum2) * Pippo_sim_P.DerivativeGain2_gain;
  if (rtmIsMajorTimeStep(Pippo_sim_M)) {
    /* Gain: '<S4>/Slider Gain' */
    Pippo_sim_B.SliderGain = Pippo_sim_P.ProportionalGain1_gain *
      Pippo_sim_B.Sum2;

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder2' */

    /* S-Function Block: Pippo_sim/HIL Read Encoder2 (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Pippo_sim_DW.HILInitialize_Card,
        &Pippo_sim_P.HILReadEncoder2_channels, 1,
        &Pippo_sim_DW.HILReadEncoder2_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder2 = Pippo_sim_DW.HILReadEncoder2_Buffer;
      }
    }

    /* Gain: '<Root>/counts to rad5' */
    Pippo_sim_B.countstorad5 = Pippo_sim_P.countstorad5_Gain *
      rtb_HILReadEncoder2;
  }

  /* Step: '<Root>/Step2' */
  if (Pippo_sim_M->Timing.t[0] < Pippo_sim_P.Step2_Time) {
    rtb_HILReadEncoder2 = Pippo_sim_P.Step2_Y0;
  } else {
    rtb_HILReadEncoder2 = Pippo_sim_P.Step2_YFinal;
  }

  /* Sum: '<Root>/Sum5' incorporates:
   *  Step: '<Root>/Step2'
   */
  Pippo_sim_B.Sum5 = rtb_HILReadEncoder2 - Pippo_sim_B.countstorad5;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<S2>/Slider Gain'
   *  Gain: '<S5>/Slider Gain'
   *  Sum: '<Root>/Sum4'
   *  Sum: '<Root>/Sum6'
   *  TransferFcn: '<Root>/Servo Velocity1'
   */
  Pippo_sim_B.Sum3 = ((Pippo_sim_P.ServoVelocity1_C *
                       Pippo_sim_X.ServoVelocity1_CSTATE +
                       Pippo_sim_P.ServoVelocity1_D * Pippo_sim_B.Sum5) *
                      Pippo_sim_P.DerivativeGain1_gain +
                      Pippo_sim_P.ProportionalGain2_gain * Pippo_sim_B.Sum5) +
    (rtb_HILReadEncoderTimebase2 + Pippo_sim_B.SliderGain);
  if (rtmIsMajorTimeStep(Pippo_sim_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog2' */

    /* S-Function Block: Pippo_sim/HIL Write Analog2 (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Pippo_sim_DW.HILInitialize_Card,
        &Pippo_sim_P.HILWriteAnalog2_channels, 1, &Pippo_sim_B.Sum3);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder4' */

    /* S-Function Block: Pippo_sim/HIL Read Encoder4 (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Pippo_sim_DW.HILInitialize_Card,
        &Pippo_sim_P.HILReadEncoder4_channels, 1,
        &Pippo_sim_DW.HILReadEncoder4_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder4 = Pippo_sim_DW.HILReadEncoder4_Buffer;
      }
    }
  }
}

/* Model update function */
void Pippo_sim_update(void)
{
  if (rtmIsMajorTimeStep(Pippo_sim_M)) {
    rt_ertODEUpdateContinuousStates(&Pippo_sim_M->solverInfo);
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
  if (!(++Pippo_sim_M->Timing.clockTick0)) {
    ++Pippo_sim_M->Timing.clockTickH0;
  }

  Pippo_sim_M->Timing.t[0] = rtsiGetSolverStopTime(&Pippo_sim_M->solverInfo);

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
    if (!(++Pippo_sim_M->Timing.clockTick1)) {
      ++Pippo_sim_M->Timing.clockTickH1;
    }

    Pippo_sim_M->Timing.t[1] = Pippo_sim_M->Timing.clockTick1 *
      Pippo_sim_M->Timing.stepSize1 + Pippo_sim_M->Timing.clockTickH1 *
      Pippo_sim_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Pippo_sim_derivatives(void)
{
  XDot_Pippo_sim_T *_rtXdot;
  _rtXdot = ((XDot_Pippo_sim_T *) Pippo_sim_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Servo Velocity2' */
  _rtXdot->ServoVelocity2_CSTATE = Pippo_sim_P.ServoVelocity2_A *
    Pippo_sim_X.ServoVelocity2_CSTATE;
  _rtXdot->ServoVelocity2_CSTATE += Pippo_sim_B.Sum2;

  /* Derivatives for TransferFcn: '<Root>/Servo Velocity1' */
  _rtXdot->ServoVelocity1_CSTATE = Pippo_sim_P.ServoVelocity1_A *
    Pippo_sim_X.ServoVelocity1_CSTATE;
  _rtXdot->ServoVelocity1_CSTATE += Pippo_sim_B.Sum5;
}

/* Model initialize function */
void Pippo_sim_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Pippo_sim/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0", &Pippo_sim_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Pippo_sim_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
      return;
    }

    if ((Pippo_sim_P.HILInitialize_AIPStart && !is_switching) ||
        (Pippo_sim_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Pippo_sim_DW.HILInitialize_Card,
        &Pippo_sim_P.HILInitialize_AIChannels, 1U,
        &Pippo_sim_P.HILInitialize_AILow, &Pippo_sim_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }

    if ((Pippo_sim_P.HILInitialize_AOPStart && !is_switching) ||
        (Pippo_sim_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Pippo_sim_DW.HILInitialize_Card,
        &Pippo_sim_P.HILInitialize_AOChannels, 1U,
        &Pippo_sim_P.HILInitialize_AOLow, &Pippo_sim_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }

    if ((Pippo_sim_P.HILInitialize_AOStart && !is_switching) ||
        (Pippo_sim_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Pippo_sim_DW.HILInitialize_Card,
        &Pippo_sim_P.HILInitialize_AOChannels, 1U,
        &Pippo_sim_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }

    if (Pippo_sim_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Pippo_sim_DW.HILInitialize_Card, &Pippo_sim_P.HILInitialize_AOChannels,
         1U, &Pippo_sim_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Pippo_sim_DW.HILInitialize_Card, NULL,
      0U, &Pippo_sim_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
      return;
    }

    if ((Pippo_sim_P.HILInitialize_DOStart && !is_switching) ||
        (Pippo_sim_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Pippo_sim_DW.HILInitialize_Card,
        &Pippo_sim_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Pippo_sim_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }

    if (Pippo_sim_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Pippo_sim_DW.HILInitialize_Card, &Pippo_sim_P.HILInitialize_DOChannels,
         1U, (const t_digital_state *) &Pippo_sim_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }

    if ((Pippo_sim_P.HILInitialize_EIPStart && !is_switching) ||
        (Pippo_sim_P.HILInitialize_EIPEnter && is_switching)) {
      Pippo_sim_DW.HILInitialize_QuadratureModes[0] =
        Pippo_sim_P.HILInitialize_EIQuadrature;
      Pippo_sim_DW.HILInitialize_QuadratureModes[1] =
        Pippo_sim_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(Pippo_sim_DW.HILInitialize_Card,
        Pippo_sim_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &Pippo_sim_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }

    if ((Pippo_sim_P.HILInitialize_EIStart && !is_switching) ||
        (Pippo_sim_P.HILInitialize_EIEnter && is_switching)) {
      Pippo_sim_DW.HILInitialize_InitialEICounts[0] =
        Pippo_sim_P.HILInitialize_EIInitial;
      Pippo_sim_DW.HILInitialize_InitialEICounts[1] =
        Pippo_sim_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Pippo_sim_DW.HILInitialize_Card,
        Pippo_sim_P.HILInitialize_EIChannels, 2U,
        &Pippo_sim_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }

    if ((Pippo_sim_P.HILInitialize_OOStart && !is_switching) ||
        (Pippo_sim_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Pippo_sim_DW.HILInitialize_Card,
        Pippo_sim_P.HILInitialize_OOChannels, 3U,
        Pippo_sim_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }

    if (Pippo_sim_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Pippo_sim_DW.HILInitialize_Card, Pippo_sim_P.HILInitialize_OOChannels,
         3U, Pippo_sim_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase2' */

  /* S-Function Block: Pippo_sim/HIL Read Encoder Timebase2 (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Pippo_sim_DW.HILInitialize_Card,
      Pippo_sim_P.HILReadEncoderTimebase2_Samples,
      &Pippo_sim_P.HILReadEncoderTimebase2_Channel, 1,
      &Pippo_sim_DW.HILReadEncoderTimebase2_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Pippo_sim_DW.HILReadEncoderTimebase2_Task, (t_buffer_overflow_mode)
         (Pippo_sim_P.HILReadEncoderTimebase2_Overflo - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
    }
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  Pippo_sim_DW.clockTickCounter = 0;

  /* InitializeConditions for TransferFcn: '<Root>/Servo Velocity2' */
  Pippo_sim_X.ServoVelocity2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Servo Velocity1' */
  Pippo_sim_X.ServoVelocity1_CSTATE = 0.0;
}

/* Model terminate function */
void Pippo_sim_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Pippo_sim/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Pippo_sim_DW.HILInitialize_Card);
    hil_monitor_stop_all(Pippo_sim_DW.HILInitialize_Card);
    is_switching = false;
    if ((Pippo_sim_P.HILInitialize_AOTerminate && !is_switching) ||
        (Pippo_sim_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Pippo_sim_P.HILInitialize_DOTerminate && !is_switching) ||
        (Pippo_sim_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Pippo_sim_P.HILInitialize_OOTerminate && !is_switching) ||
        (Pippo_sim_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Pippo_sim_DW.HILInitialize_Card
                         , &Pippo_sim_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Pippo_sim_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Pippo_sim_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Pippo_sim_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Pippo_sim_P.HILInitialize_DOFinal
                         , Pippo_sim_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Pippo_sim_DW.HILInitialize_Card,
            &Pippo_sim_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Pippo_sim_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Pippo_sim_DW.HILInitialize_Card,
            &Pippo_sim_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Pippo_sim_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Pippo_sim_DW.HILInitialize_Card,
            Pippo_sim_P.HILInitialize_OOChannels, num_final_other_outputs,
            Pippo_sim_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Pippo_sim_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Pippo_sim_DW.HILInitialize_Card);
    hil_monitor_delete_all(Pippo_sim_DW.HILInitialize_Card);
    hil_close(Pippo_sim_DW.HILInitialize_Card);
    Pippo_sim_DW.HILInitialize_Card = NULL;
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
  Pippo_sim_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Pippo_sim_update();
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
  Pippo_sim_initialize();
}

void MdlTerminate(void)
{
  Pippo_sim_terminate();
}

/* Registration function */
RT_MODEL_Pippo_sim_T *Pippo_sim(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Pippo_sim_M, 0,
                sizeof(RT_MODEL_Pippo_sim_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Pippo_sim_M->solverInfo,
                          &Pippo_sim_M->Timing.simTimeStep);
    rtsiSetTPtr(&Pippo_sim_M->solverInfo, &rtmGetTPtr(Pippo_sim_M));
    rtsiSetStepSizePtr(&Pippo_sim_M->solverInfo, &Pippo_sim_M->Timing.stepSize0);
    rtsiSetdXPtr(&Pippo_sim_M->solverInfo, &Pippo_sim_M->derivs);
    rtsiSetContStatesPtr(&Pippo_sim_M->solverInfo, (real_T **)
                         &Pippo_sim_M->contStates);
    rtsiSetNumContStatesPtr(&Pippo_sim_M->solverInfo,
      &Pippo_sim_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Pippo_sim_M->solverInfo,
      &Pippo_sim_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Pippo_sim_M->solverInfo,
      &Pippo_sim_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Pippo_sim_M->solverInfo,
      &Pippo_sim_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Pippo_sim_M->solverInfo, (&rtmGetErrorStatus
      (Pippo_sim_M)));
    rtsiSetRTModelPtr(&Pippo_sim_M->solverInfo, Pippo_sim_M);
  }

  rtsiSetSimTimeStep(&Pippo_sim_M->solverInfo, MAJOR_TIME_STEP);
  Pippo_sim_M->intgData.f[0] = Pippo_sim_M->odeF[0];
  Pippo_sim_M->contStates = ((real_T *) &Pippo_sim_X);
  rtsiSetSolverData(&Pippo_sim_M->solverInfo, (void *)&Pippo_sim_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Pippo_sim_M->solverInfo, false);
  rtsiSetSolverName(&Pippo_sim_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Pippo_sim_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Pippo_sim_M points to
       static memory which is guaranteed to be non-NULL" */
    Pippo_sim_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Pippo_sim_M->Timing.sampleTimes = (&Pippo_sim_M->Timing.sampleTimesArray[0]);
    Pippo_sim_M->Timing.offsetTimes = (&Pippo_sim_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Pippo_sim_M->Timing.sampleTimes[0] = (0.0);
    Pippo_sim_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Pippo_sim_M->Timing.offsetTimes[0] = (0.0);
    Pippo_sim_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Pippo_sim_M, &Pippo_sim_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Pippo_sim_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Pippo_sim_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Pippo_sim_M, -1);
  Pippo_sim_M->Timing.stepSize0 = 0.002;
  Pippo_sim_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  Pippo_sim_M->Sizes.checksums[0] = (2315780554U);
  Pippo_sim_M->Sizes.checksums[1] = (19124193U);
  Pippo_sim_M->Sizes.checksums[2] = (455256592U);
  Pippo_sim_M->Sizes.checksums[3] = (1910302638U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Pippo_sim_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Pippo_sim_M->extModeInfo,
      &Pippo_sim_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Pippo_sim_M->extModeInfo, Pippo_sim_M->Sizes.checksums);
    rteiSetTPtr(Pippo_sim_M->extModeInfo, rtmGetTPtr(Pippo_sim_M));
  }

  Pippo_sim_M->solverInfoPtr = (&Pippo_sim_M->solverInfo);
  Pippo_sim_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Pippo_sim_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Pippo_sim_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Pippo_sim_M->blockIO = ((void *) &Pippo_sim_B);

  {
    Pippo_sim_B.Sum2 = 0.0;
    Pippo_sim_B.SliderGain = 0.0;
    Pippo_sim_B.countstorad5 = 0.0;
    Pippo_sim_B.Sum5 = 0.0;
    Pippo_sim_B.Sum3 = 0.0;
  }

  /* parameters */
  Pippo_sim_M->defaultParam = ((real_T *)&Pippo_sim_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Pippo_sim_X;
    Pippo_sim_M->contStates = (x);
    (void) memset((void *)&Pippo_sim_X, 0,
                  sizeof(X_Pippo_sim_T));
  }

  /* states (dwork) */
  Pippo_sim_M->dwork = ((void *) &Pippo_sim_DW);
  (void) memset((void *)&Pippo_sim_DW, 0,
                sizeof(DW_Pippo_sim_T));
  Pippo_sim_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Pippo_sim_DW.HILInitialize_FilterFrequency[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Pippo_sim_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Pippo_sim_M->Sizes.numContStates = (2);/* Number of continuous states */
  Pippo_sim_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Pippo_sim_M->Sizes.numY = (0);       /* Number of model outputs */
  Pippo_sim_M->Sizes.numU = (0);       /* Number of model inputs */
  Pippo_sim_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Pippo_sim_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Pippo_sim_M->Sizes.numBlocks = (22); /* Number of blocks */
  Pippo_sim_M->Sizes.numBlockIO = (5); /* Number of block outputs */
  Pippo_sim_M->Sizes.numBlockPrms = (99);/* Sum of parameter "widths" */
  return Pippo_sim_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
