/*
 * Prova_sistema_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_card),
  sizeof(t_task),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "t_card",
  "t_task",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Prova_sistema_B.countstorad1), 0, 0, 9 },

  { (char_T *)(&Prova_sistema_B.LogicalOperator1), 8, 0, 2 }
  ,

  { (char_T *)(&Prova_sistema_DW.DiscreteTimeIntegrator_DSTATE), 0, 0, 3 },

  { (char_T *)(&Prova_sistema_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&Prova_sistema_DW.HILReadEncoderTimebase_Task), 16, 0, 1 },

  { (char_T *)(&Prova_sistema_DW.SmoothSignalGenerator_RWORK.Amp), 0, 0, 1 },

  { (char_T *)(&Prova_sistema_DW.HILReadEncoder_PWORK), 11, 0, 5 },

  { (char_T *)(&Prova_sistema_DW.HILInitialize_ClockModes), 6, 0, 8 },

  { (char_T *)(&Prova_sistema_DW.DiscreteTimeIntegrator_PrevRese), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Prova_sistema_P.K[0]), 0, 0, 7 },

  { (char_T *)(&Prova_sistema_P.HILReadEncoder_channels), 7, 0, 2 },

  { (char_T *)(&Prova_sistema_P.StopwithMessage_message_icon), 2, 0, 1 },

  { (char_T *)(&Prova_sistema_P.HILInitialize_OOTerminate), 0, 0, 38 },

  { (char_T *)(&Prova_sistema_P.HILInitialize_CKChannels), 6, 0, 4 },

  { (char_T *)(&Prova_sistema_P.HILInitialize_AIChannels), 7, 0, 11 },

  { (char_T *)(&Prova_sistema_P.Constant_Value), 8, 0, 39 },

  { (char_T *)(&Prova_sistema_P.HILReadEncoderTimebase_Overflow), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  8U,
  rtPTransitions
};

/* [EOF] Prova_sistema_dt.h */
