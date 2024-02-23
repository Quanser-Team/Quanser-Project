/*
 * MPC_linear_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MPC_linear".
 *
 * Model version              : 9.22
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Tue Dec  5 15:25:11 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MPC_linear_types_h_
#define RTW_HEADER_MPC_linear_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_WTmPWsEMvOzNnnAVv5fQNC_
#define DEFINED_TYPEDEF_FOR_struct_WTmPWsEMvOzNnnAVv5fQNC_

typedef struct {
  int32_T MaxIterations;
  real_T ConstraintTolerance;
  boolean_T UseWarmStart;
} struct_WTmPWsEMvOzNnnAVv5fQNC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_WHjMt45Sk148iktWsfFxl_
#define DEFINED_TYPEDEF_FOR_struct_WHjMt45Sk148iktWsfFxl_

typedef struct {
  int32_T MaxIterations;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T ComplementarityTolerance;
  real_T StepTolerance;
} struct_WHjMt45Sk148iktWsfFxl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_lnQ9KXdSZFplhcBp5LBCc_
#define DEFINED_TYPEDEF_FOR_struct_lnQ9KXdSZFplhcBp5LBCc_

typedef struct {
  int32_T MaxIterations;
  real_T ConstraintTolerance;
  real_T DiscreteConstraintTolerance;
  boolean_T RoundingAtRootNode;
  int32_T MaxPendingNodes;
} struct_lnQ9KXdSZFplhcBp5LBCc;

#endif

/* Parameters (default storage) */
typedef struct P_MPC_linear_T_ P_MPC_linear_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_MPC_linear_T RT_MODEL_MPC_linear_T;

#endif                                 /* RTW_HEADER_MPC_linear_types_h_ */
