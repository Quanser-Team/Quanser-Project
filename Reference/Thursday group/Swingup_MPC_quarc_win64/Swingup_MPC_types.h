/*
 * Swingup_MPC_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Swingup_MPC".
 *
 * Model version              : 9.21
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Nov 16 17:12:02 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Swingup_MPC_types_h_
#define RTW_HEADER_Swingup_MPC_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_sG8JZ69axY52WWR6RKyApQC
#define struct_tag_sG8JZ69axY52WWR6RKyApQC

struct tag_sG8JZ69axY52WWR6RKyApQC
{
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationEq;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
  real_T firstOrderOpt;
  boolean_T hasObjective;
};

#endif                                 /* struct_tag_sG8JZ69axY52WWR6RKyApQC */

#ifndef typedef_sG8JZ69axY52WWR6RKyApQC_Swing_T
#define typedef_sG8JZ69axY52WWR6RKyApQC_Swing_T

typedef struct tag_sG8JZ69axY52WWR6RKyApQC sG8JZ69axY52WWR6RKyApQC_Swing_T;

#endif                             /* typedef_sG8JZ69axY52WWR6RKyApQC_Swing_T */

#ifndef struct_tag_s7RdrPWkr8UPAUyTdDJkLaG
#define struct_tag_s7RdrPWkr8UPAUyTdDJkLaG

struct tag_s7RdrPWkr8UPAUyTdDJkLaG
{
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
};

#endif                                 /* struct_tag_s7RdrPWkr8UPAUyTdDJkLaG */

#ifndef typedef_s7RdrPWkr8UPAUyTdDJkLaG_Swing_T
#define typedef_s7RdrPWkr8UPAUyTdDJkLaG_Swing_T

typedef struct tag_s7RdrPWkr8UPAUyTdDJkLaG s7RdrPWkr8UPAUyTdDJkLaG_Swing_T;

#endif                             /* typedef_s7RdrPWkr8UPAUyTdDJkLaG_Swing_T */

#ifndef struct_tag_somzaGboVhDG7PNQS6E98jD
#define struct_tag_somzaGboVhDG7PNQS6E98jD

struct tag_somzaGboVhDG7PNQS6E98jD
{
  char_T SolverName[7];
  int32_T MaxIterations;
  real_T StepTolerance;
  real_T OptimalityTolerance;
  real_T ConstraintTolerance;
  real_T ObjectiveLimit;
  real_T PricingTolerance;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
  boolean_T RemainFeasible;
  boolean_T IterDisplayQP;
};

#endif                                 /* struct_tag_somzaGboVhDG7PNQS6E98jD */

#ifndef typedef_somzaGboVhDG7PNQS6E98jD_Swing_T
#define typedef_somzaGboVhDG7PNQS6E98jD_Swing_T

typedef struct tag_somzaGboVhDG7PNQS6E98jD somzaGboVhDG7PNQS6E98jD_Swing_T;

#endif                             /* typedef_somzaGboVhDG7PNQS6E98jD_Swing_T */

#ifndef struct_tag_sttYSJM5GCi2c1Eu0R50efC
#define struct_tag_sttYSJM5GCi2c1Eu0R50efC

struct tag_sttYSJM5GCi2c1Eu0R50efC
{
  real_T iterations;
  real_T funcCount;
  char_T algorithm[3];
  real_T constrviolation;
  real_T stepsize;
  real_T lssteplength;
  real_T firstorderopt;
};

#endif                                 /* struct_tag_sttYSJM5GCi2c1Eu0R50efC */

#ifndef typedef_sttYSJM5GCi2c1Eu0R50efC_Swing_T
#define typedef_sttYSJM5GCi2c1Eu0R50efC_Swing_T

typedef struct tag_sttYSJM5GCi2c1Eu0R50efC sttYSJM5GCi2c1Eu0R50efC_Swing_T;

#endif                             /* typedef_sttYSJM5GCi2c1Eu0R50efC_Swing_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_real_T */

#ifndef typedef_emxArray_real_T_Swingup_MPC_T
#define typedef_emxArray_real_T_Swingup_MPC_T

typedef struct emxArray_real_T emxArray_real_T_Swingup_MPC_T;

#endif                               /* typedef_emxArray_real_T_Swingup_MPC_T */

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_xgaiQX2t1f8Iwfqw2xCGq
#define struct_tag_xgaiQX2t1f8Iwfqw2xCGq

struct tag_xgaiQX2t1f8Iwfqw2xCGq
{
  emxArray_real_T_Swingup_MPC_T *FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_;
  real_T workspace2_;
};

#endif                                 /* struct_tag_xgaiQX2t1f8Iwfqw2xCGq */

#ifndef typedef_s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
#define typedef_s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T

typedef struct tag_xgaiQX2t1f8Iwfqw2xCGq s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T;

#endif                             /* typedef_s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T */

#ifndef struct_tag_sXyXDxkiKhsfpX9ivkpx9WG
#define struct_tag_sXyXDxkiKhsfpX9ivkpx9WG

struct tag_sXyXDxkiKhsfpX9ivkpx9WG
{
  real_T Ts;
  real_T CurrentStates[4];
  real_T LastMV;
  real_T References[40];
  real_T MVTarget[10];
  real_T PredictionHorizon;
  real_T NumOfStates;
  real_T NumOfOutputs;
  real_T NumOfInputs;
  real_T MVIndex;
  real_T InputPassivityIndex;
  real_T OutputPassivityIndex;
  boolean_T PassivityUsePredictedX;
};

#endif                                 /* struct_tag_sXyXDxkiKhsfpX9ivkpx9WG */

#ifndef typedef_sXyXDxkiKhsfpX9ivkpx9WG_Swing_T
#define typedef_sXyXDxkiKhsfpX9ivkpx9WG_Swing_T

typedef struct tag_sXyXDxkiKhsfpX9ivkpx9WG sXyXDxkiKhsfpX9ivkpx9WG_Swing_T;

#endif                             /* typedef_sXyXDxkiKhsfpX9ivkpx9WG_Swing_T */

#ifndef struct_tag_GSKgPzH92oA7AAcXEvWMnG
#define struct_tag_GSKgPzH92oA7AAcXEvWMnG

struct tag_GSKgPzH92oA7AAcXEvWMnG
{
  real_T x[4];
  real_T lastMV;
  real_T ref[40];
  real_T OutputWeights[40];
  real_T MVWeights[10];
  real_T MVRateWeights[10];
  real_T ECRWeight;
  real_T OutputMin[40];
  real_T OutputMax[40];
  real_T StateMin[40];
  real_T StateMax[40];
  real_T MVMin[10];
  real_T MVMax[10];
  real_T MVRateMin[10];
  real_T MVRateMax[10];
  real_T MVScaledTarget[10];
};

#endif                                 /* struct_tag_GSKgPzH92oA7AAcXEvWMnG */

#ifndef typedef_s_GSKgPzH92oA7AAcXEvWMnG_Swin_T
#define typedef_s_GSKgPzH92oA7AAcXEvWMnG_Swin_T

typedef struct tag_GSKgPzH92oA7AAcXEvWMnG s_GSKgPzH92oA7AAcXEvWMnG_Swin_T;

#endif                             /* typedef_s_GSKgPzH92oA7AAcXEvWMnG_Swin_T */

#ifndef struct_tag_OOgWGXXQYnSElkPXvuQxeH
#define struct_tag_OOgWGXXQYnSElkPXvuQxeH

struct tag_OOgWGXXQYnSElkPXvuQxeH
{
  s_GSKgPzH92oA7AAcXEvWMnG_Swin_T runtimedata;
  sXyXDxkiKhsfpX9ivkpx9WG_Swing_T userdata;
};

#endif                                 /* struct_tag_OOgWGXXQYnSElkPXvuQxeH */

#ifndef typedef_s_OOgWGXXQYnSElkPXvuQxeH_Swin_T
#define typedef_s_OOgWGXXQYnSElkPXvuQxeH_Swin_T

typedef struct tag_OOgWGXXQYnSElkPXvuQxeH s_OOgWGXXQYnSElkPXvuQxeH_Swin_T;

#endif                             /* typedef_s_OOgWGXXQYnSElkPXvuQxeH_Swin_T */

#ifndef struct_tag_nbRAEDqd29YaGE2WwvwFdC
#define struct_tag_nbRAEDqd29YaGE2WwvwFdC

struct tag_nbRAEDqd29YaGE2WwvwFdC
{
  s_OOgWGXXQYnSElkPXvuQxeH_Swin_T workspace;
};

#endif                                 /* struct_tag_nbRAEDqd29YaGE2WwvwFdC */

#ifndef typedef_anonymous_function_Swingup_MP_T
#define typedef_anonymous_function_Swingup_MP_T

typedef struct tag_nbRAEDqd29YaGE2WwvwFdC anonymous_function_Swingup_MP_T;

#endif                             /* typedef_anonymous_function_Swingup_MP_T */

#ifndef struct_tag_aQ4EGGq7ByH7oOTP7gihgG
#define struct_tag_aQ4EGGq7ByH7oOTP7gihgG

struct tag_aQ4EGGq7ByH7oOTP7gihgG
{
  anonymous_function_Swingup_MP_T value;
};

#endif                                 /* struct_tag_aQ4EGGq7ByH7oOTP7gihgG */

#ifndef typedef_coder_internal_stickyStruct_1_T
#define typedef_coder_internal_stickyStruct_1_T

typedef struct tag_aQ4EGGq7ByH7oOTP7gihgG coder_internal_stickyStruct_1_T;

#endif                             /* typedef_coder_internal_stickyStruct_1_T */

#ifndef struct_tag_NiyVezAfpEjIyDhBFLYmFH
#define struct_tag_NiyVezAfpEjIyDhBFLYmFH

struct tag_NiyVezAfpEjIyDhBFLYmFH
{
  anonymous_function_Swingup_MP_T value;
  coder_internal_stickyStruct_1_T next;
};

#endif                                 /* struct_tag_NiyVezAfpEjIyDhBFLYmFH */

#ifndef typedef_coder_internal_stickyStruct_2_T
#define typedef_coder_internal_stickyStruct_2_T

typedef struct tag_NiyVezAfpEjIyDhBFLYmFH coder_internal_stickyStruct_2_T;

#endif                             /* typedef_coder_internal_stickyStruct_2_T */

#ifndef struct_tag_VVEpaD7FHlIgmZvnLl8J7B
#define struct_tag_VVEpaD7FHlIgmZvnLl8J7B

struct tag_VVEpaD7FHlIgmZvnLl8J7B
{
  coder_internal_stickyStruct_2_T next;
};

#endif                                 /* struct_tag_VVEpaD7FHlIgmZvnLl8J7B */

#ifndef typedef_coder_internal_stickyStruct_3_T
#define typedef_coder_internal_stickyStruct_3_T

typedef struct tag_VVEpaD7FHlIgmZvnLl8J7B coder_internal_stickyStruct_3_T;

#endif                             /* typedef_coder_internal_stickyStruct_3_T */

#ifndef struct_tag_DkSMSHCUUrevSxYHo7H1nB
#define struct_tag_DkSMSHCUUrevSxYHo7H1nB

struct tag_DkSMSHCUUrevSxYHo7H1nB
{
  int32_T value;
  coder_internal_stickyStruct_3_T next;
};

#endif                                 /* struct_tag_DkSMSHCUUrevSxYHo7H1nB */

#ifndef typedef_coder_internal_stickyStruct_4_T
#define typedef_coder_internal_stickyStruct_4_T

typedef struct tag_DkSMSHCUUrevSxYHo7H1nB coder_internal_stickyStruct_4_T;

#endif                             /* typedef_coder_internal_stickyStruct_4_T */

#ifndef struct_tag_KhPQdz3hxF5gmDVCA3H5xD
#define struct_tag_KhPQdz3hxF5gmDVCA3H5xD

struct tag_KhPQdz3hxF5gmDVCA3H5xD
{
  coder_internal_stickyStruct_4_T next;
};

#endif                                 /* struct_tag_KhPQdz3hxF5gmDVCA3H5xD */

#ifndef typedef_coder_internal_stickyStruct_5_T
#define typedef_coder_internal_stickyStruct_5_T

typedef struct tag_KhPQdz3hxF5gmDVCA3H5xD coder_internal_stickyStruct_5_T;

#endif                             /* typedef_coder_internal_stickyStruct_5_T */

#ifndef struct_tag_FK1x4uGRQJQc4dUw8ORnqD
#define struct_tag_FK1x4uGRQJQc4dUw8ORnqD

struct tag_FK1x4uGRQJQc4dUw8ORnqD
{
  coder_internal_stickyStruct_5_T next;
};

#endif                                 /* struct_tag_FK1x4uGRQJQc4dUw8ORnqD */

#ifndef typedef_coder_internal_stickyStruct_6_T
#define typedef_coder_internal_stickyStruct_6_T

typedef struct tag_FK1x4uGRQJQc4dUw8ORnqD coder_internal_stickyStruct_6_T;

#endif                             /* typedef_coder_internal_stickyStruct_6_T */

#ifndef struct_tag_pJmO3cqbJKEotffQX9RMdH
#define struct_tag_pJmO3cqbJKEotffQX9RMdH

struct tag_pJmO3cqbJKEotffQX9RMdH
{
  coder_internal_stickyStruct_6_T next;
};

#endif                                 /* struct_tag_pJmO3cqbJKEotffQX9RMdH */

#ifndef typedef_coder_internal_stickyStruct_7_T
#define typedef_coder_internal_stickyStruct_7_T

typedef struct tag_pJmO3cqbJKEotffQX9RMdH coder_internal_stickyStruct_7_T;

#endif                             /* typedef_coder_internal_stickyStruct_7_T */

#ifndef struct_tag_y1VU8Pq6UFoS5ZwObxCsqC
#define struct_tag_y1VU8Pq6UFoS5ZwObxCsqC

struct tag_y1VU8Pq6UFoS5ZwObxCsqC
{
  coder_internal_stickyStruct_7_T next;
};

#endif                                 /* struct_tag_y1VU8Pq6UFoS5ZwObxCsqC */

#ifndef typedef_coder_internal_stickyStruct_8_T
#define typedef_coder_internal_stickyStruct_8_T

typedef struct tag_y1VU8Pq6UFoS5ZwObxCsqC coder_internal_stickyStruct_8_T;

#endif                             /* typedef_coder_internal_stickyStruct_8_T */

#ifndef struct_tag_fdZY4SNsPfKpMMX8HBT7aG
#define struct_tag_fdZY4SNsPfKpMMX8HBT7aG

struct tag_fdZY4SNsPfKpMMX8HBT7aG
{
  coder_internal_stickyStruct_8_T next;
};

#endif                                 /* struct_tag_fdZY4SNsPfKpMMX8HBT7aG */

#ifndef typedef_coder_internal_stickyStruct_9_T
#define typedef_coder_internal_stickyStruct_9_T

typedef struct tag_fdZY4SNsPfKpMMX8HBT7aG coder_internal_stickyStruct_9_T;

#endif                             /* typedef_coder_internal_stickyStruct_9_T */

#ifndef struct_emxArray_real_T_120
#define struct_emxArray_real_T_120

struct emxArray_real_T_120
{
  real_T data[120];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_120 */

#ifndef typedef_emxArray_real_T_120_Swingup_M_T
#define typedef_emxArray_real_T_120_Swingup_M_T

typedef struct emxArray_real_T_120 emxArray_real_T_120_Swingup_M_T;

#endif                             /* typedef_emxArray_real_T_120_Swingup_M_T */

#ifndef struct_emxArray_real_T_245
#define struct_emxArray_real_T_245

struct emxArray_real_T_245
{
  real_T data[245];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_245 */

#ifndef typedef_emxArray_real_T_245_Swingup_M_T
#define typedef_emxArray_real_T_245_Swingup_M_T

typedef struct emxArray_real_T_245 emxArray_real_T_245_Swingup_M_T;

#endif                             /* typedef_emxArray_real_T_245_Swingup_M_T */

#ifndef struct_emxArray_real_T_449
#define struct_emxArray_real_T_449

struct emxArray_real_T_449
{
  real_T data[449];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_449 */

#ifndef typedef_emxArray_real_T_449_Swingup_M_T
#define typedef_emxArray_real_T_449_Swingup_M_T

typedef struct emxArray_real_T_449 emxArray_real_T_449_Swingup_M_T;

#endif                             /* typedef_emxArray_real_T_449_Swingup_M_T */

#ifndef struct_emxArray_int32_T_449
#define struct_emxArray_int32_T_449

struct emxArray_int32_T_449
{
  int32_T data[449];
  int32_T size;
};

#endif                                 /* struct_emxArray_int32_T_449 */

#ifndef typedef_emxArray_int32_T_449_Swingup__T
#define typedef_emxArray_int32_T_449_Swingup__T

typedef struct emxArray_int32_T_449 emxArray_int32_T_449_Swingup__T;

#endif                             /* typedef_emxArray_int32_T_449_Swingup__T */

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_k1Ho7Q1nYjseRM5cXIwEUD
#define struct_tag_k1Ho7Q1nYjseRM5cXIwEUD

struct tag_k1Ho7Q1nYjseRM5cXIwEUD
{
  int32_T nVarMax;
  int32_T mNonlinIneq;
  int32_T mNonlinEq;
  int32_T mIneq;
  int32_T mEq;
  int32_T iNonIneq0;
  int32_T iNonEq0;
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[44];
  real_T xstarsqp_old[44];
  emxArray_real_T_120_Swingup_M_T cIneq;
  emxArray_real_T_120_Swingup_M_T cIneq_old;
  real_T cEq[40];
  real_T cEq_old[40];
  emxArray_real_T_245_Swingup_M_T grad;
  emxArray_real_T_245_Swingup_M_T grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T_449_Swingup_M_T lambdasqp;
  emxArray_real_T_449_Swingup_M_T lambdaStopTest;
  emxArray_real_T_449_Swingup_M_T lambdaStopTestPrev;
  real_T steplength;
  emxArray_real_T_245_Swingup_M_T delta_x;
  emxArray_real_T_245_Swingup_M_T socDirection;
  emxArray_int32_T_449_Swingup__T workingset_old;
  emxArray_real_T_Swingup_MPC_T *JacCineqTrans_old;
  emxArray_real_T_Swingup_MPC_T *JacCeqTrans_old;
  emxArray_real_T_245_Swingup_M_T gradLag;
  emxArray_real_T_245_Swingup_M_T delta_gradLag;
  emxArray_real_T_245_Swingup_M_T xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T_449_Swingup_M_T lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T_245_Swingup_M_T searchDir;
};

#endif                                 /* struct_tag_k1Ho7Q1nYjseRM5cXIwEUD */

#ifndef typedef_s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T
#define typedef_s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T

typedef struct tag_k1Ho7Q1nYjseRM5cXIwEUD s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T;

#endif                             /* typedef_s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T */

#ifndef struct_tag_j0Ykcy5K3TT7uFOSX0kFSG
#define struct_tag_j0Ykcy5K3TT7uFOSX0kFSG

struct tag_j0Ykcy5K3TT7uFOSX0kFSG
{
  emxArray_real_T_Swingup_MPC_T *workspace_double;
  emxArray_int32_T_449_Swingup__T workspace_int;
  emxArray_int32_T_449_Swingup__T workspace_sort;
};

#endif                                 /* struct_tag_j0Ykcy5K3TT7uFOSX0kFSG */

#ifndef typedef_s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
#define typedef_s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T

typedef struct tag_j0Ykcy5K3TT7uFOSX0kFSG s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T;

#endif                             /* typedef_s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T */

#ifndef struct_emxArray_int32_T_245
#define struct_emxArray_int32_T_245

struct emxArray_int32_T_245
{
  int32_T data[245];
  int32_T size;
};

#endif                                 /* struct_emxArray_int32_T_245 */

#ifndef typedef_emxArray_int32_T_245_Swingup__T
#define typedef_emxArray_int32_T_245_Swingup__T

typedef struct emxArray_int32_T_245 emxArray_int32_T_245_Swingup__T;

#endif                             /* typedef_emxArray_int32_T_245_Swingup__T */

#ifndef struct_emxArray_boolean_T_449
#define struct_emxArray_boolean_T_449

struct emxArray_boolean_T_449
{
  boolean_T data[449];
  int32_T size;
};

#endif                                 /* struct_emxArray_boolean_T_449 */

#ifndef typedef_emxArray_boolean_T_449_Swingu_T
#define typedef_emxArray_boolean_T_449_Swingu_T

typedef struct emxArray_boolean_T_449 emxArray_boolean_T_449_Swingu_T;

#endif                             /* typedef_emxArray_boolean_T_449_Swingu_T */

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_pBvMsf7fBJa4zdfMTVPUqH
#define struct_tag_pBvMsf7fBJa4zdfMTVPUqH

struct tag_pBvMsf7fBJa4zdfMTVPUqH
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  emxArray_real_T_Swingup_MPC_T *Aineq;
  emxArray_real_T_120_Swingup_M_T bineq;
  emxArray_real_T_Swingup_MPC_T *Aeq;
  real_T beq[40];
  emxArray_real_T_245_Swingup_M_T lb;
  emxArray_real_T_245_Swingup_M_T ub;
  emxArray_int32_T_245_Swingup__T indexLB;
  emxArray_int32_T_245_Swingup__T indexUB;
  emxArray_int32_T_245_Swingup__T indexFixed;
  int32_T mEqRemoved;
  int32_T indexEqRemoved[40];
  emxArray_real_T_Swingup_MPC_T *ATwset;
  emxArray_real_T_449_Swingup_M_T bwset;
  int32_T nActiveConstr;
  emxArray_real_T_449_Swingup_M_T maxConstrWorkspace;
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  emxArray_boolean_T_449_Swingu_T isActiveConstr;
  emxArray_int32_T_449_Swingup__T Wid;
  emxArray_int32_T_449_Swingup__T Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                 /* struct_tag_pBvMsf7fBJa4zdfMTVPUqH */

#ifndef typedef_s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
#define typedef_s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T

typedef struct tag_pBvMsf7fBJa4zdfMTVPUqH s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T;

#endif                             /* typedef_s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T */

#ifndef struct_emxArray_real_T_244
#define struct_emxArray_real_T_244

struct emxArray_real_T_244
{
  real_T data[244];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_244 */

#ifndef typedef_emxArray_real_T_244_Swingup_M_T
#define typedef_emxArray_real_T_244_Swingup_M_T

typedef struct emxArray_real_T_244 emxArray_real_T_244_Swingup_M_T;

#endif                             /* typedef_emxArray_real_T_244_Swingup_M_T */

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_x5MUnC0L5qGnqHjeyMGHGF
#define struct_tag_x5MUnC0L5qGnqHjeyMGHGF

struct tag_x5MUnC0L5qGnqHjeyMGHGF
{
  emxArray_real_T_245_Swingup_M_T grad;
  emxArray_real_T_244_Swingup_M_T Hx;
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                 /* struct_tag_x5MUnC0L5qGnqHjeyMGHGF */

#ifndef typedef_s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T
#define typedef_s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T

typedef struct tag_x5MUnC0L5qGnqHjeyMGHGF s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T;

#endif                             /* typedef_s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T */

#ifndef struct_tag_qjgm7GzdZt1MoSNNUuwzWH
#define struct_tag_qjgm7GzdZt1MoSNNUuwzWH

struct tag_qjgm7GzdZt1MoSNNUuwzWH
{
  int32_T ldq;
  emxArray_real_T_Swingup_MPC_T *QR;
  emxArray_real_T_Swingup_MPC_T *Q;
  emxArray_int32_T_449_Swingup__T jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T_449_Swingup_M_T tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                 /* struct_tag_qjgm7GzdZt1MoSNNUuwzWH */

#ifndef typedef_s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T
#define typedef_s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T

typedef struct tag_qjgm7GzdZt1MoSNNUuwzWH s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T;

#endif                             /* typedef_s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T */

#ifndef struct_emxArray_real_T_80
#define struct_emxArray_real_T_80

struct emxArray_real_T_80
{
  real_T data[80];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_80 */

#ifndef typedef_emxArray_real_T_80_Swingup_MP_T
#define typedef_emxArray_real_T_80_Swingup_MP_T

typedef struct emxArray_real_T_80 emxArray_real_T_80_Swingup_MP_T;

#endif                             /* typedef_emxArray_real_T_80_Swingup_MP_T */

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_YSjtuYw7jAb651NIA2q08D
#define struct_tag_YSjtuYw7jAb651NIA2q08D

struct tag_YSjtuYw7jAb651NIA2q08D
{
  anonymous_function_Swingup_MP_T objfun;
  anonymous_function_Swingup_MP_T nonlin;
  real_T f_1;
  emxArray_real_T_80_Swingup_MP_T cIneq_1;
  real_T cEq_1[40];
  real_T f_2;
  emxArray_real_T_80_Swingup_MP_T cIneq_2;
  real_T cEq_2[40];
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T isEmptyNonlcon;
  boolean_T hasLB[44];
  boolean_T hasUB[44];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

#endif                                 /* struct_tag_YSjtuYw7jAb651NIA2q08D */

#ifndef typedef_s_YSjtuYw7jAb651NIA2q08D_Swin_T
#define typedef_s_YSjtuYw7jAb651NIA2q08D_Swin_T

typedef struct tag_YSjtuYw7jAb651NIA2q08D s_YSjtuYw7jAb651NIA2q08D_Swin_T;

#endif                             /* typedef_s_YSjtuYw7jAb651NIA2q08D_Swin_T */

/* Parameters (default storage) */
typedef struct P_Swingup_MPC_T_ P_Swingup_MPC_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Swingup_MPC_T RT_MODEL_Swingup_MPC_T;

#endif                                 /* RTW_HEADER_Swingup_MPC_types_h_ */
