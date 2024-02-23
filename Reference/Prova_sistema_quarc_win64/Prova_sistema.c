/*
 * Prova_sistema.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Prova_sistema".
 *
 * Model version              : 9.3
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Nov 22 17:54:07 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Prova_sistema.h"
#include "rtwtypes.h"
#include <math.h>
#include "Prova_sistema_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Prova_sistema_dt.h"

/* Block signals (default storage) */
B_Prova_sistema_T Prova_sistema_B;

/* Continuous states */
X_Prova_sistema_T Prova_sistema_X;

/* Block states (default storage) */
DW_Prova_sistema_T Prova_sistema_DW;

/* Real-time model */
static RT_MODEL_Prova_sistema_T Prova_sistema_M_;
RT_MODEL_Prova_sistema_T *const Prova_sistema_M = &Prova_sistema_M_;

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
  Prova_sistema_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Prova_sistema_output(void)
{
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_Gain1;
  real_T rtb_ServoVelocity;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(Prova_sistema_M)) {
    /* set solver stop time */
    if (!(Prova_sistema_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Prova_sistema_M->solverInfo,
                            ((Prova_sistema_M->Timing.clockTickH0 + 1) *
        Prova_sistema_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Prova_sistema_M->solverInfo,
                            ((Prova_sistema_M->Timing.clockTick0 + 1) *
        Prova_sistema_M->Timing.stepSize0 + Prova_sistema_M->Timing.clockTickH0 *
        Prova_sistema_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Prova_sistema_M)) {
    Prova_sistema_M->Timing.t[0] = rtsiGetT(&Prova_sistema_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Prova_sistema_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: Prova_sistema/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (Prova_sistema_DW.HILReadEncoderTimebase_Task, 1,
         &Prova_sistema_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        rtb_Gain1 = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
      } else {
        rtb_Gain1 = Prova_sistema_DW.HILReadEncoderTimebase_Buffer;
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: Prova_sistema/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Prova_sistema_DW.HILInitialize_Card,
        &Prova_sistema_P.HILReadEncoder_channels, 1,
        &Prova_sistema_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
      } else {
        rtb_DiscreteTimeIntegrator = Prova_sistema_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/counts to rad1' */
    Prova_sistema_B.countstorad1 = Prova_sistema_P.countstorad1_Gain *
      rtb_DiscreteTimeIntegrator;

    /* Gain: '<Root>/Gain7' */
    Prova_sistema_B.Gain7 = Prova_sistema_P.K[1] * Prova_sistema_B.countstorad1;

    /* Gain: '<Root>/counts to rad' */
    Prova_sistema_B.countstorad = Prova_sistema_P.countstorad_Gain * rtb_Gain1;
  }

  /* TransferFcn: '<Root>/Servo Velocity' */
  rtb_ServoVelocity = Prova_sistema_P.ServoVelocity_C *
    Prova_sistema_X.ServoVelocity_CSTATE + Prova_sistema_P.ServoVelocity_D *
    Prova_sistema_B.countstorad;

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/Gain6'
   *  TransferFcn: '<Root>/Servo Velocity1'
   */
  Prova_sistema_B.Sum = ((0.0 - Prova_sistema_B.Gain7) - Prova_sistema_P.K[2] *
    rtb_ServoVelocity) - (Prova_sistema_P.ServoVelocity1_C *
    Prova_sistema_X.ServoVelocity1_CSTATE + Prova_sistema_P.ServoVelocity1_D *
    Prova_sistema_B.countstorad1) * Prova_sistema_P.K[3];
  if (rtmIsMajorTimeStep(Prova_sistema_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Prova_sistema/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Prova_sistema_DW.HILInitialize_Card,
        &Prova_sistema_P.HILWriteAnalog_channels, 1, &Prova_sistema_B.Sum);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
      }
    }

    /* Gain: '<S3>/Gain' */
    Prova_sistema_B.Gain = Prova_sistema_P.Gain_Gain *
      Prova_sistema_B.countstorad1;

    /* Abs: '<S5>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(Prova_sistema_B.Sum);

    /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
     *  Constant: '<S5>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      Prova_sistema_P.StallMonitor_control_threshold);
  }

  /* Gain: '<Root>/ ' */
  Prova_sistema_B.u = Prova_sistema_P._Gain * rtb_ServoVelocity;
  if (rtmIsMajorTimeStep(Prova_sistema_M)) {
    /* Abs: '<S5>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(Prova_sistema_B.u);

    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Constant: '<S5>/motion threshold'
     *  RelationalOperator: '<S5>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <=
       Prova_sistema_P.StallMonitor_motion_threshold));

    /* Logic: '<S5>/Logical Operator1' */
    Prova_sistema_B.LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    if (Prova_sistema_B.LogicalOperator1 &&
        (Prova_sistema_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      Prova_sistema_DW.DiscreteTimeIntegrator_DSTATE =
        Prova_sistema_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator = Prova_sistema_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S5>/Relational Operator2' incorporates:
     *  Constant: '<S5>/control threshold1'
     */
    Prova_sistema_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
      Prova_sistema_P.StallMonitor_duration_s);

    /* Stop: '<S6>/Stop Simulation' incorporates:
     *  Constant: '<S7>/Constant'
     *  RelationalOperator: '<S7>/Compare'
     */
    if (Prova_sistema_B.RelationalOperator2 != Prova_sistema_P.Constant_Value) {
      rtmSetStopRequested(Prova_sistema_M, 1);
    }

    /* End of Stop: '<S6>/Stop Simulation' */

    /* DataTypeConversion: '<S5>/Data Type Conversion' */
    Prova_sistema_B.DataTypeConversion = rtb_RelationalOperator1;

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */
    /* S-Function Block: Prova_sistema/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * Prova_sistema_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed =
        (Prova_sistema_P.SmoothSignalGenerator_Amplitude !=
         Prova_sistema_DW.SmoothSignalGenerator_RWORK.Amp || w !=
         Prova_sistema_DW.SmoothSignalGenerator_RWORK.W);
      real_T T = TWO_PI / Prova_sistema_DW.SmoothSignalGenerator_RWORK.W;
      if (Prova_sistema_DW.SmoothSignalGenerator_RWORK.T < 0.5 * T) {
        rtb_Gain1 = Prova_sistema_DW.SmoothSignalGenerator_RWORK.Amp;
      } else {
        rtb_Gain1 = -Prova_sistema_DW.SmoothSignalGenerator_RWORK.Amp;
      }

      /*
         If the amplitude or frequency parameter changes, then adjust the
         square wave parameters such that the square wave output is continuous.
       */
      if (params_changed) {
        /*
           Change the amplitude or frequency when the sign of the output
           changes. This technique ensures that we don't get intermediate
           jumps in amplitude and we don't get higher frequencies than
           expected due to a pulse being prematurely truncated.
         */
        if (Prova_sistema_P.SmoothSignalGenerator_Amplitude == 0 || rtb_Gain1 ==
            0 || Prova_sistema_DW.SmoothSignalGenerator_RWORK.Y == 0 ||
            (rtb_Gain1 < 0) != (Prova_sistema_DW.SmoothSignalGenerator_RWORK.Y <
             0)) {
          Prova_sistema_DW.SmoothSignalGenerator_RWORK.Amp =
            Prova_sistema_P.SmoothSignalGenerator_Amplitude;
          Prova_sistema_DW.SmoothSignalGenerator_RWORK.W = w;
          T = TWO_PI / w;
          if (rtb_Gain1 >= 0) {
            Prova_sistema_DW.SmoothSignalGenerator_RWORK.T = 0;
            rtb_Gain1 = Prova_sistema_P.SmoothSignalGenerator_Amplitude;
          } else {
            Prova_sistema_DW.SmoothSignalGenerator_RWORK.T = T / 2;
            rtb_Gain1 = -Prova_sistema_P.SmoothSignalGenerator_Amplitude;
          }
        }
      }

      Prova_sistema_DW.SmoothSignalGenerator_RWORK.T += 0.002;
      if (Prova_sistema_DW.SmoothSignalGenerator_RWORK.T >= T) {
        Prova_sistema_DW.SmoothSignalGenerator_RWORK.T = 0;
      }

      Prova_sistema_DW.SmoothSignalGenerator_RWORK.Y = rtb_Gain1;
    }

    /* Gain: '<S2>/Gain' incorporates:
     *  Gain: '<Root>/Amplitude (deg)'
     *  Gain: '<S1>/Gain1'
     */
    Prova_sistema_B.Gain_f[0] = Prova_sistema_P.Amplitudedeg_Gain * rtb_Gain1 *
      Prova_sistema_P.Gain1_Gain * Prova_sistema_P.Gain_Gain_a;
    Prova_sistema_B.Gain_f[1] = Prova_sistema_P.Gain_Gain_a *
      Prova_sistema_B.countstorad;
  }
}

/* Model update function */
void Prova_sistema_update(void)
{
  if (rtmIsMajorTimeStep(Prova_sistema_M)) {
    /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
    Prova_sistema_DW.DiscreteTimeIntegrator_DSTATE +=
      Prova_sistema_P.DiscreteTimeIntegrator_gainval *
      Prova_sistema_B.DataTypeConversion;
    Prova_sistema_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      Prova_sistema_B.LogicalOperator1;
  }

  if (rtmIsMajorTimeStep(Prova_sistema_M)) {
    rt_ertODEUpdateContinuousStates(&Prova_sistema_M->solverInfo);
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
  if (!(++Prova_sistema_M->Timing.clockTick0)) {
    ++Prova_sistema_M->Timing.clockTickH0;
  }

  Prova_sistema_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Prova_sistema_M->solverInfo);

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
    if (!(++Prova_sistema_M->Timing.clockTick1)) {
      ++Prova_sistema_M->Timing.clockTickH1;
    }

    Prova_sistema_M->Timing.t[1] = Prova_sistema_M->Timing.clockTick1 *
      Prova_sistema_M->Timing.stepSize1 + Prova_sistema_M->Timing.clockTickH1 *
      Prova_sistema_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Prova_sistema_derivatives(void)
{
  XDot_Prova_sistema_T *_rtXdot;
  _rtXdot = ((XDot_Prova_sistema_T *) Prova_sistema_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Servo Velocity' */
  _rtXdot->ServoVelocity_CSTATE = Prova_sistema_P.ServoVelocity_A *
    Prova_sistema_X.ServoVelocity_CSTATE;
  _rtXdot->ServoVelocity_CSTATE += Prova_sistema_B.countstorad;

  /* Derivatives for TransferFcn: '<Root>/Servo Velocity1' */
  _rtXdot->ServoVelocity1_CSTATE = Prova_sistema_P.ServoVelocity1_A *
    Prova_sistema_X.ServoVelocity1_CSTATE;
  _rtXdot->ServoVelocity1_CSTATE += Prova_sistema_B.countstorad1;
}

/* Model initialize function */
void Prova_sistema_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Prova_sistema/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &Prova_sistema_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Prova_sistema_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
      return;
    }

    if ((Prova_sistema_P.HILInitialize_AIPStart && !is_switching) ||
        (Prova_sistema_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Prova_sistema_DW.HILInitialize_Card,
        &Prova_sistema_P.HILInitialize_AIChannels, 1U,
        &Prova_sistema_P.HILInitialize_AILow,
        &Prova_sistema_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }

    if ((Prova_sistema_P.HILInitialize_AOPStart && !is_switching) ||
        (Prova_sistema_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Prova_sistema_DW.HILInitialize_Card,
        &Prova_sistema_P.HILInitialize_AOChannels, 1U,
        &Prova_sistema_P.HILInitialize_AOLow,
        &Prova_sistema_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }

    if ((Prova_sistema_P.HILInitialize_AOStart && !is_switching) ||
        (Prova_sistema_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Prova_sistema_DW.HILInitialize_Card,
        &Prova_sistema_P.HILInitialize_AOChannels, 1U,
        &Prova_sistema_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }

    if (Prova_sistema_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Prova_sistema_DW.HILInitialize_Card,
         &Prova_sistema_P.HILInitialize_AOChannels, 1U,
         &Prova_sistema_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Prova_sistema_DW.HILInitialize_Card,
      NULL, 0U, &Prova_sistema_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
      return;
    }

    if ((Prova_sistema_P.HILInitialize_DOStart && !is_switching) ||
        (Prova_sistema_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Prova_sistema_DW.HILInitialize_Card,
        &Prova_sistema_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Prova_sistema_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }

    if (Prova_sistema_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Prova_sistema_DW.HILInitialize_Card,
         &Prova_sistema_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &Prova_sistema_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }

    if ((Prova_sistema_P.HILInitialize_EIPStart && !is_switching) ||
        (Prova_sistema_P.HILInitialize_EIPEnter && is_switching)) {
      Prova_sistema_DW.HILInitialize_QuadratureModes[0] =
        Prova_sistema_P.HILInitialize_EIQuadrature;
      Prova_sistema_DW.HILInitialize_QuadratureModes[1] =
        Prova_sistema_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Prova_sistema_DW.HILInitialize_Card,
         Prova_sistema_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Prova_sistema_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }

    if ((Prova_sistema_P.HILInitialize_EIStart && !is_switching) ||
        (Prova_sistema_P.HILInitialize_EIEnter && is_switching)) {
      Prova_sistema_DW.HILInitialize_InitialEICounts[0] =
        Prova_sistema_P.HILInitialize_EIInitial;
      Prova_sistema_DW.HILInitialize_InitialEICounts[1] =
        Prova_sistema_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Prova_sistema_DW.HILInitialize_Card,
        Prova_sistema_P.HILInitialize_EIChannels, 2U,
        &Prova_sistema_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }

    if ((Prova_sistema_P.HILInitialize_OOStart && !is_switching) ||
        (Prova_sistema_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Prova_sistema_DW.HILInitialize_Card,
        Prova_sistema_P.HILInitialize_OOChannels, 3U,
        Prova_sistema_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }

    if (Prova_sistema_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Prova_sistema_DW.HILInitialize_Card,
         Prova_sistema_P.HILInitialize_OOChannels, 3U,
         Prova_sistema_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Prova_sistema/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Prova_sistema_DW.HILInitialize_Card,
      Prova_sistema_P.HILReadEncoderTimebase_SamplesI,
      &Prova_sistema_P.HILReadEncoderTimebase_Channels, 1,
      &Prova_sistema_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Prova_sistema_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Prova_sistema_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
    }
  }

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */

  /* S-Function Block: Prova_sistema/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / Prova_sistema_P.SmoothSignalGenerator_Frequency;
    Prova_sistema_DW.SmoothSignalGenerator_RWORK.Amp =
      Prova_sistema_P.SmoothSignalGenerator_Amplitude;
    Prova_sistema_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      Prova_sistema_P.SmoothSignalGenerator_Frequency;
    Prova_sistema_DW.SmoothSignalGenerator_RWORK.T = fmod
      (Prova_sistema_P.SmoothSignalGenerator_InitialPh, TWO_PI) * T / TWO_PI;
    if (Prova_sistema_DW.SmoothSignalGenerator_RWORK.T < 0) {
      Prova_sistema_DW.SmoothSignalGenerator_RWORK.T += T;
    }

    if (Prova_sistema_DW.SmoothSignalGenerator_RWORK.T < 0.5 * T) {
      Prova_sistema_DW.SmoothSignalGenerator_RWORK.Y =
        Prova_sistema_P.SmoothSignalGenerator_Amplitude;
    } else {
      Prova_sistema_DW.SmoothSignalGenerator_RWORK.Y =
        -Prova_sistema_P.SmoothSignalGenerator_Amplitude;
    }
  }

  /* InitializeConditions for TransferFcn: '<Root>/Servo Velocity' */
  Prova_sistema_X.ServoVelocity_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Servo Velocity1' */
  Prova_sistema_X.ServoVelocity1_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  Prova_sistema_DW.DiscreteTimeIntegrator_DSTATE =
    Prova_sistema_P.DiscreteTimeIntegrator_IC;
  Prova_sistema_DW.DiscreteTimeIntegrator_PrevRese = 2;
}

/* Model terminate function */
void Prova_sistema_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Prova_sistema/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Prova_sistema_DW.HILInitialize_Card);
    hil_monitor_stop_all(Prova_sistema_DW.HILInitialize_Card);
    is_switching = false;
    if ((Prova_sistema_P.HILInitialize_AOTerminate && !is_switching) ||
        (Prova_sistema_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Prova_sistema_P.HILInitialize_DOTerminate && !is_switching) ||
        (Prova_sistema_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Prova_sistema_P.HILInitialize_OOTerminate && !is_switching) ||
        (Prova_sistema_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Prova_sistema_DW.HILInitialize_Card
                         , &Prova_sistema_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Prova_sistema_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Prova_sistema_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Prova_sistema_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Prova_sistema_P.HILInitialize_DOFinal
                         , Prova_sistema_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Prova_sistema_DW.HILInitialize_Card,
            &Prova_sistema_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Prova_sistema_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Prova_sistema_DW.HILInitialize_Card,
            &Prova_sistema_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Prova_sistema_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Prova_sistema_DW.HILInitialize_Card,
            Prova_sistema_P.HILInitialize_OOChannels, num_final_other_outputs,
            Prova_sistema_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Prova_sistema_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Prova_sistema_DW.HILInitialize_Card);
    hil_monitor_delete_all(Prova_sistema_DW.HILInitialize_Card);
    hil_close(Prova_sistema_DW.HILInitialize_Card);
    Prova_sistema_DW.HILInitialize_Card = NULL;
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
  Prova_sistema_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Prova_sistema_update();
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
  Prova_sistema_initialize();
}

void MdlTerminate(void)
{
  Prova_sistema_terminate();
}

/* Registration function */
RT_MODEL_Prova_sistema_T *Prova_sistema(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Prova_sistema_M, 0,
                sizeof(RT_MODEL_Prova_sistema_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Prova_sistema_M->solverInfo,
                          &Prova_sistema_M->Timing.simTimeStep);
    rtsiSetTPtr(&Prova_sistema_M->solverInfo, &rtmGetTPtr(Prova_sistema_M));
    rtsiSetStepSizePtr(&Prova_sistema_M->solverInfo,
                       &Prova_sistema_M->Timing.stepSize0);
    rtsiSetdXPtr(&Prova_sistema_M->solverInfo, &Prova_sistema_M->derivs);
    rtsiSetContStatesPtr(&Prova_sistema_M->solverInfo, (real_T **)
                         &Prova_sistema_M->contStates);
    rtsiSetNumContStatesPtr(&Prova_sistema_M->solverInfo,
      &Prova_sistema_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Prova_sistema_M->solverInfo,
      &Prova_sistema_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Prova_sistema_M->solverInfo,
      &Prova_sistema_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Prova_sistema_M->solverInfo,
      &Prova_sistema_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Prova_sistema_M->solverInfo, (&rtmGetErrorStatus
      (Prova_sistema_M)));
    rtsiSetRTModelPtr(&Prova_sistema_M->solverInfo, Prova_sistema_M);
  }

  rtsiSetSimTimeStep(&Prova_sistema_M->solverInfo, MAJOR_TIME_STEP);
  Prova_sistema_M->intgData.f[0] = Prova_sistema_M->odeF[0];
  Prova_sistema_M->contStates = ((real_T *) &Prova_sistema_X);
  rtsiSetSolverData(&Prova_sistema_M->solverInfo, (void *)
                    &Prova_sistema_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Prova_sistema_M->solverInfo, false);
  rtsiSetSolverName(&Prova_sistema_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Prova_sistema_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Prova_sistema_M points to
       static memory which is guaranteed to be non-NULL" */
    Prova_sistema_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Prova_sistema_M->Timing.sampleTimes =
      (&Prova_sistema_M->Timing.sampleTimesArray[0]);
    Prova_sistema_M->Timing.offsetTimes =
      (&Prova_sistema_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Prova_sistema_M->Timing.sampleTimes[0] = (0.0);
    Prova_sistema_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    Prova_sistema_M->Timing.offsetTimes[0] = (0.0);
    Prova_sistema_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Prova_sistema_M, &Prova_sistema_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Prova_sistema_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Prova_sistema_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Prova_sistema_M, -1);
  Prova_sistema_M->Timing.stepSize0 = 0.002;
  Prova_sistema_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  Prova_sistema_M->Sizes.checksums[0] = (4040441263U);
  Prova_sistema_M->Sizes.checksums[1] = (1032777953U);
  Prova_sistema_M->Sizes.checksums[2] = (398153021U);
  Prova_sistema_M->Sizes.checksums[3] = (3020918946U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Prova_sistema_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Prova_sistema_M->extModeInfo,
      &Prova_sistema_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Prova_sistema_M->extModeInfo,
                        Prova_sistema_M->Sizes.checksums);
    rteiSetTPtr(Prova_sistema_M->extModeInfo, rtmGetTPtr(Prova_sistema_M));
  }

  Prova_sistema_M->solverInfoPtr = (&Prova_sistema_M->solverInfo);
  Prova_sistema_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Prova_sistema_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Prova_sistema_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Prova_sistema_M->blockIO = ((void *) &Prova_sistema_B);
  (void) memset(((void *) &Prova_sistema_B), 0,
                sizeof(B_Prova_sistema_T));

  {
    Prova_sistema_B.countstorad1 = 0.0;
    Prova_sistema_B.Gain7 = 0.0;
    Prova_sistema_B.countstorad = 0.0;
    Prova_sistema_B.Sum = 0.0;
    Prova_sistema_B.Gain = 0.0;
    Prova_sistema_B.u = 0.0;
    Prova_sistema_B.DataTypeConversion = 0.0;
    Prova_sistema_B.Gain_f[0] = 0.0;
    Prova_sistema_B.Gain_f[1] = 0.0;
  }

  /* parameters */
  Prova_sistema_M->defaultParam = ((real_T *)&Prova_sistema_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Prova_sistema_X;
    Prova_sistema_M->contStates = (x);
    (void) memset((void *)&Prova_sistema_X, 0,
                  sizeof(X_Prova_sistema_T));
  }

  /* states (dwork) */
  Prova_sistema_M->dwork = ((void *) &Prova_sistema_DW);
  (void) memset((void *)&Prova_sistema_DW, 0,
                sizeof(DW_Prova_sistema_T));
  Prova_sistema_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  Prova_sistema_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Prova_sistema_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Prova_sistema_DW.SmoothSignalGenerator_RWORK.Amp = 0.0;
  Prova_sistema_DW.SmoothSignalGenerator_RWORK.W = 0.0;
  Prova_sistema_DW.SmoothSignalGenerator_RWORK.T = 0.0;
  Prova_sistema_DW.SmoothSignalGenerator_RWORK.Y = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Prova_sistema_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Prova_sistema_M->Sizes.numContStates = (2);/* Number of continuous states */
  Prova_sistema_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Prova_sistema_M->Sizes.numY = (0);   /* Number of model outputs */
  Prova_sistema_M->Sizes.numU = (0);   /* Number of model inputs */
  Prova_sistema_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Prova_sistema_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Prova_sistema_M->Sizes.numBlocks = (37);/* Number of blocks */
  Prova_sistema_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  Prova_sistema_M->Sizes.numBlockPrms = (103);/* Sum of parameter "widths" */
  return Prova_sistema_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
