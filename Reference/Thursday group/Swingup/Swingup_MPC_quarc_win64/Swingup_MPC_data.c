/*
 * Swingup_MPC_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Swingup_MPC".
 *
 * Model version              : 9.21
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Nov 23 16:39:49 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Swingup_MPC.h"

/* Block parameters (default storage) */
P_Swingup_MPC_T Swingup_MPC_P = {
  /* Mask Parameter: StallMonitor_control_threshold
   * Referenced by: '<S29>/control threshold'
   */
  5.0,

  /* Mask Parameter: StallMonitor_duration_s
   * Referenced by: '<S29>/control threshold1'
   */
  0.05,

  /* Mask Parameter: StallMonitor_motion_threshold
   * Referenced by: '<S29>/motion threshold'
   */
  0.3,

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  0U,

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<Root>/HIL Write Analog'
   */
  0U,

  /* Mask Parameter: StopwithMessage_message_icon
   * Referenced by: '<S30>/Show Message on Host'
   */
  1,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 1.0, 0.0, 0.0 },

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  3.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -3.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  15.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -15.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 1.0, 0.0 },

  /* Expression: watchdog_other_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0.0, 0.0, 1.0 },

  /* Expression: 2*pi/512/4
   * Referenced by: '<Root>/counts to rad1'
   */
  0.0030679615757712823,

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S1>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 2*pi/512/4
   * Referenced by: '<Root>/counts to rad'
   */
  0.0030679615757712823,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S5>/Rate Transition'
   */
  0.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  -150.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  -22500.0,

  /* Computed Parameter: TransferFcn1_D
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  150.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S29>/Discrete-Time Integrator'
   */
  0.0005,

  /* Expression: 0
   * Referenced by: '<S29>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -150.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -22500.0,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<Root>/Transfer Fcn'
   */
  150.0,

  /* Expression: ones(PredictionHorizon+1,1)
   * Referenced by: '<S7>/ones'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /* Expression: initial_phase
   * Referenced by: '<Root>/Smooth Signal Generator'
   */
  0.0,

  /* Expression: i_amplitude
   * Referenced by: '<Root>/Smooth Signal Generator'
   */
  0.0,

  /* Expression: i_frequency
   * Referenced by: '<Root>/Smooth Signal Generator'
   */
  1.0,

  /* Expression: [0 0 0 0]
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/md_zero'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/mv.target_zero'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/mv.min_zero'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/mv.max_zero'
   */
  0.0,

  /* Expression: zeros(4,1)
   * Referenced by: '<S2>/y.min_zero'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(4,1)
   * Referenced by: '<S2>/y.max_zero'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/dmv.min_zero'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/dmv.max_zero'
   */
  0.0,

  /* Expression: zeros(4,1)
   * Referenced by: '<S2>/x.min_zero'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(4,1)
   * Referenced by: '<S2>/x.max_zero'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(4,1)
   * Referenced by: '<S2>/y.wt_zero'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/mv.wt_zero'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/dmv.wt_zero'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/ecr.wt_zero'
   */
  0.0,

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/params_zero'
   */
  0.0,

  /* Expression: 2:max(2,PredictionHorizon)
   * Referenced by: '<S7>/Constant1'
   */
  { 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0,
    16.0, 17.0, 18.0, 19.0, 20.0 },

  /* Expression: min(3,PredictionHorizon+1):(PredictionHorizon+1)
   * Referenced by: '<S7>/Constant'
   */
  { 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0,
    17.0, 18.0, 19.0, 20.0, 21.0 },

  /* Expression: zeros(1,1)
   * Referenced by: '<S2>/e.init_zero'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain2'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<Root>/Saturation1'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<Root>/Saturation1'
   */
  -5.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<Root>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_DOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  0U,

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_OOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 11000U, 11001U, 11002U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<Root>/HIL Read Encoder Timebase'
   */
  1U,

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<Root>/HIL Read Encoder Timebase'
   */
  2000U,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S31>/Constant'
   */
  false,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<Root>/HIL Read Encoder Timebase'
   */
  true,

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<Root>/HIL Write Analog'
   */
  false,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<Root>/HIL Read Encoder Timebase'
   */
  1U
};
