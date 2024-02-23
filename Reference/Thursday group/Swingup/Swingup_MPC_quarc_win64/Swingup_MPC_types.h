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
 * C source code generated on : Thu Nov 23 16:39:49 2023
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
#ifndef struct_tag_qTpAvLBgQITVWp1VxBLjqC
#define struct_tag_qTpAvLBgQITVWp1VxBLjqC

struct tag_qTpAvLBgQITVWp1VxBLjqC
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

#endif                                 /* struct_tag_qTpAvLBgQITVWp1VxBLjqC */

#ifndef typedef_s_qTpAvLBgQITVWp1VxBLjqC_Swin_T
#define typedef_s_qTpAvLBgQITVWp1VxBLjqC_Swin_T

typedef struct tag_qTpAvLBgQITVWp1VxBLjqC s_qTpAvLBgQITVWp1VxBLjqC_Swin_T;

#endif                             /* typedef_s_qTpAvLBgQITVWp1VxBLjqC_Swin_T */

#ifndef struct_tag_so3ZGLWMMN8Q28W2ErSGbFF
#define struct_tag_so3ZGLWMMN8Q28W2ErSGbFF

struct tag_so3ZGLWMMN8Q28W2ErSGbFF
{
  real_T Ts;
  real_T CurrentStates[4];
  real_T LastMV;
  real_T References[80];
  real_T MVTarget[20];
  real_T PredictionHorizon;
  real_T NumOfStates;
  real_T NumOfOutputs;
  real_T NumOfInputs;
  real_T MVIndex;
  real_T InputPassivityIndex;
  real_T OutputPassivityIndex;
  boolean_T PassivityUsePredictedX;
};

#endif                                 /* struct_tag_so3ZGLWMMN8Q28W2ErSGbFF */

#ifndef typedef_so3ZGLWMMN8Q28W2ErSGbFF_Swing_T
#define typedef_so3ZGLWMMN8Q28W2ErSGbFF_Swing_T

typedef struct tag_so3ZGLWMMN8Q28W2ErSGbFF so3ZGLWMMN8Q28W2ErSGbFF_Swing_T;

#endif                             /* typedef_so3ZGLWMMN8Q28W2ErSGbFF_Swing_T */

#ifndef struct_tag_HcZpBg4ijmZp2DBuNmIQbD
#define struct_tag_HcZpBg4ijmZp2DBuNmIQbD

struct tag_HcZpBg4ijmZp2DBuNmIQbD
{
  real_T x[4];
  real_T lastMV;
  real_T ref[80];
  real_T OutputWeights[80];
  real_T MVWeights[20];
  real_T MVRateWeights[20];
  real_T ECRWeight;
  real_T OutputMin[80];
  real_T OutputMax[80];
  real_T StateMin[80];
  real_T StateMax[80];
  real_T MVMin[20];
  real_T MVMax[20];
  real_T MVRateMin[20];
  real_T MVRateMax[20];
  real_T MVScaledTarget[20];
};

#endif                                 /* struct_tag_HcZpBg4ijmZp2DBuNmIQbD */

#ifndef typedef_s_HcZpBg4ijmZp2DBuNmIQbD_Swin_T
#define typedef_s_HcZpBg4ijmZp2DBuNmIQbD_Swin_T

typedef struct tag_HcZpBg4ijmZp2DBuNmIQbD s_HcZpBg4ijmZp2DBuNmIQbD_Swin_T;

#endif                             /* typedef_s_HcZpBg4ijmZp2DBuNmIQbD_Swin_T */

#ifndef struct_tag_qkxBnUvz31UmrF1NWMEspH
#define struct_tag_qkxBnUvz31UmrF1NWMEspH

struct tag_qkxBnUvz31UmrF1NWMEspH
{
  s_HcZpBg4ijmZp2DBuNmIQbD_Swin_T runtimedata;
  so3ZGLWMMN8Q28W2ErSGbFF_Swing_T userdata;
};

#endif                                 /* struct_tag_qkxBnUvz31UmrF1NWMEspH */

#ifndef typedef_s_qkxBnUvz31UmrF1NWMEspH_Swin_T
#define typedef_s_qkxBnUvz31UmrF1NWMEspH_Swin_T

typedef struct tag_qkxBnUvz31UmrF1NWMEspH s_qkxBnUvz31UmrF1NWMEspH_Swin_T;

#endif                             /* typedef_s_qkxBnUvz31UmrF1NWMEspH_Swin_T */

#ifndef struct_tag_tvEvHCn0wi7SCY9ZSaRZTD
#define struct_tag_tvEvHCn0wi7SCY9ZSaRZTD

struct tag_tvEvHCn0wi7SCY9ZSaRZTD
{
  s_qkxBnUvz31UmrF1NWMEspH_Swin_T workspace;
};

#endif                                 /* struct_tag_tvEvHCn0wi7SCY9ZSaRZTD */

#ifndef typedef_anonymous_function_Swingup_MP_T
#define typedef_anonymous_function_Swingup_MP_T

typedef struct tag_tvEvHCn0wi7SCY9ZSaRZTD anonymous_function_Swingup_MP_T;

#endif                             /* typedef_anonymous_function_Swingup_MP_T */

#ifndef struct_tag_ChG2XBHAAYPsHMx2ZdpsWG
#define struct_tag_ChG2XBHAAYPsHMx2ZdpsWG

struct tag_ChG2XBHAAYPsHMx2ZdpsWG
{
  anonymous_function_Swingup_MP_T value;
};

#endif                                 /* struct_tag_ChG2XBHAAYPsHMx2ZdpsWG */

#ifndef typedef_coder_internal_stickyStruct_1_T
#define typedef_coder_internal_stickyStruct_1_T

typedef struct tag_ChG2XBHAAYPsHMx2ZdpsWG coder_internal_stickyStruct_1_T;

#endif                             /* typedef_coder_internal_stickyStruct_1_T */

#ifndef struct_tag_d5BSowRyftcwkzOBHAeGWC
#define struct_tag_d5BSowRyftcwkzOBHAeGWC

struct tag_d5BSowRyftcwkzOBHAeGWC
{
  anonymous_function_Swingup_MP_T value;
  coder_internal_stickyStruct_1_T next;
};

#endif                                 /* struct_tag_d5BSowRyftcwkzOBHAeGWC */

#ifndef typedef_coder_internal_stickyStruct_2_T
#define typedef_coder_internal_stickyStruct_2_T

typedef struct tag_d5BSowRyftcwkzOBHAeGWC coder_internal_stickyStruct_2_T;

#endif                             /* typedef_coder_internal_stickyStruct_2_T */

#ifndef struct_tag_SOPEZoxF4Vgo9E0StfvdmD
#define struct_tag_SOPEZoxF4Vgo9E0StfvdmD

struct tag_SOPEZoxF4Vgo9E0StfvdmD
{
  coder_internal_stickyStruct_2_T next;
};

#endif                                 /* struct_tag_SOPEZoxF4Vgo9E0StfvdmD */

#ifndef typedef_coder_internal_stickyStruct_3_T
#define typedef_coder_internal_stickyStruct_3_T

typedef struct tag_SOPEZoxF4Vgo9E0StfvdmD coder_internal_stickyStruct_3_T;

#endif                             /* typedef_coder_internal_stickyStruct_3_T */

#ifndef struct_tag_mOaU32fo3g312tPJCAqQiE
#define struct_tag_mOaU32fo3g312tPJCAqQiE

struct tag_mOaU32fo3g312tPJCAqQiE
{
  int32_T value;
  coder_internal_stickyStruct_3_T next;
};

#endif                                 /* struct_tag_mOaU32fo3g312tPJCAqQiE */

#ifndef typedef_coder_internal_stickyStruct_4_T
#define typedef_coder_internal_stickyStruct_4_T

typedef struct tag_mOaU32fo3g312tPJCAqQiE coder_internal_stickyStruct_4_T;

#endif                             /* typedef_coder_internal_stickyStruct_4_T */

#ifndef struct_tag_b0Yp8UZNCGMuG3v3vWofGE
#define struct_tag_b0Yp8UZNCGMuG3v3vWofGE

struct tag_b0Yp8UZNCGMuG3v3vWofGE
{
  coder_internal_stickyStruct_4_T next;
};

#endif                                 /* struct_tag_b0Yp8UZNCGMuG3v3vWofGE */

#ifndef typedef_coder_internal_stickyStruct_5_T
#define typedef_coder_internal_stickyStruct_5_T

typedef struct tag_b0Yp8UZNCGMuG3v3vWofGE coder_internal_stickyStruct_5_T;

#endif                             /* typedef_coder_internal_stickyStruct_5_T */

#ifndef struct_tag_0qMIfs78bB1WHWoBNo12lC
#define struct_tag_0qMIfs78bB1WHWoBNo12lC

struct tag_0qMIfs78bB1WHWoBNo12lC
{
  coder_internal_stickyStruct_5_T next;
};

#endif                                 /* struct_tag_0qMIfs78bB1WHWoBNo12lC */

#ifndef typedef_coder_internal_stickyStruct_6_T
#define typedef_coder_internal_stickyStruct_6_T

typedef struct tag_0qMIfs78bB1WHWoBNo12lC coder_internal_stickyStruct_6_T;

#endif                             /* typedef_coder_internal_stickyStruct_6_T */

#ifndef struct_tag_9EHj7SjlkqYrYxJQLETAj
#define struct_tag_9EHj7SjlkqYrYxJQLETAj

struct tag_9EHj7SjlkqYrYxJQLETAj
{
  coder_internal_stickyStruct_6_T next;
};

#endif                                 /* struct_tag_9EHj7SjlkqYrYxJQLETAj */

#ifndef typedef_coder_internal_stickyStruct_7_T
#define typedef_coder_internal_stickyStruct_7_T

typedef struct tag_9EHj7SjlkqYrYxJQLETAj coder_internal_stickyStruct_7_T;

#endif                             /* typedef_coder_internal_stickyStruct_7_T */

#ifndef struct_tag_P5B85trLJF5ujtPBM3RY5D
#define struct_tag_P5B85trLJF5ujtPBM3RY5D

struct tag_P5B85trLJF5ujtPBM3RY5D
{
  coder_internal_stickyStruct_7_T next;
};

#endif                                 /* struct_tag_P5B85trLJF5ujtPBM3RY5D */

#ifndef typedef_coder_internal_stickyStruct_8_T
#define typedef_coder_internal_stickyStruct_8_T

typedef struct tag_P5B85trLJF5ujtPBM3RY5D coder_internal_stickyStruct_8_T;

#endif                             /* typedef_coder_internal_stickyStruct_8_T */

#ifndef struct_tag_IRnmDemImEDDHN0LFhu0n
#define struct_tag_IRnmDemImEDDHN0LFhu0n

struct tag_IRnmDemImEDDHN0LFhu0n
{
  coder_internal_stickyStruct_8_T next;
};

#endif                                 /* struct_tag_IRnmDemImEDDHN0LFhu0n */

#ifndef typedef_coder_internal_stickyStruct_9_T
#define typedef_coder_internal_stickyStruct_9_T

typedef struct tag_IRnmDemImEDDHN0LFhu0n coder_internal_stickyStruct_9_T;

#endif                             /* typedef_coder_internal_stickyStruct_9_T */

#ifndef struct_emxArray_real_T_240
#define struct_emxArray_real_T_240

struct emxArray_real_T_240
{
  real_T data[240];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_240 */

#ifndef typedef_emxArray_real_T_240_Swingup_M_T
#define typedef_emxArray_real_T_240_Swingup_M_T

typedef struct emxArray_real_T_240 emxArray_real_T_240_Swingup_M_T;

#endif                             /* typedef_emxArray_real_T_240_Swingup_M_T */

#ifndef struct_emxArray_real_T_483
#define struct_emxArray_real_T_483

struct emxArray_real_T_483
{
  real_T data[483];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_483 */

#ifndef typedef_emxArray_real_T_483_Swingup_M_T
#define typedef_emxArray_real_T_483_Swingup_M_T

typedef struct emxArray_real_T_483 emxArray_real_T_483_Swingup_M_T;

#endif                             /* typedef_emxArray_real_T_483_Swingup_M_T */

#ifndef struct_emxArray_real_T_885
#define struct_emxArray_real_T_885

struct emxArray_real_T_885
{
  real_T data[885];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_885 */

#ifndef typedef_emxArray_real_T_885_Swingup_M_T
#define typedef_emxArray_real_T_885_Swingup_M_T

typedef struct emxArray_real_T_885 emxArray_real_T_885_Swingup_M_T;

#endif                             /* typedef_emxArray_real_T_885_Swingup_M_T */

#ifndef struct_emxArray_int32_T_885
#define struct_emxArray_int32_T_885

struct emxArray_int32_T_885
{
  int32_T data[885];
  int32_T size;
};

#endif                                 /* struct_emxArray_int32_T_885 */

#ifndef typedef_emxArray_int32_T_885_Swingup__T
#define typedef_emxArray_int32_T_885_Swingup__T

typedef struct emxArray_int32_T_885 emxArray_int32_T_885_Swingup__T;

#endif                             /* typedef_emxArray_int32_T_885_Swingup__T */

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_c7IibgiRaKfA3VsAytf19
#define struct_tag_c7IibgiRaKfA3VsAytf19

struct tag_c7IibgiRaKfA3VsAytf19
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
  real_T xstarsqp[82];
  real_T xstarsqp_old[82];
  emxArray_real_T_240_Swingup_M_T cIneq;
  emxArray_real_T_240_Swingup_M_T cIneq_old;
  real_T cEq[80];
  real_T cEq_old[80];
  emxArray_real_T_483_Swingup_M_T grad;
  emxArray_real_T_483_Swingup_M_T grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T_885_Swingup_M_T lambdasqp;
  emxArray_real_T_885_Swingup_M_T lambdaStopTest;
  emxArray_real_T_885_Swingup_M_T lambdaStopTestPrev;
  real_T steplength;
  emxArray_real_T_483_Swingup_M_T delta_x;
  emxArray_real_T_483_Swingup_M_T socDirection;
  emxArray_int32_T_885_Swingup__T workingset_old;
  emxArray_real_T_Swingup_MPC_T *JacCineqTrans_old;
  emxArray_real_T_Swingup_MPC_T *JacCeqTrans_old;
  emxArray_real_T_483_Swingup_M_T gradLag;
  emxArray_real_T_483_Swingup_M_T delta_gradLag;
  emxArray_real_T_483_Swingup_M_T xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T_885_Swingup_M_T lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T_483_Swingup_M_T searchDir;
};

#endif                                 /* struct_tag_c7IibgiRaKfA3VsAytf19 */

#ifndef typedef_s_c7IibgiRaKfA3VsAytf19_Swing_T
#define typedef_s_c7IibgiRaKfA3VsAytf19_Swing_T

typedef struct tag_c7IibgiRaKfA3VsAytf19 s_c7IibgiRaKfA3VsAytf19_Swing_T;

#endif                             /* typedef_s_c7IibgiRaKfA3VsAytf19_Swing_T */

#ifndef struct_tag_MKU8VImszW7wooGA4sgbqF
#define struct_tag_MKU8VImszW7wooGA4sgbqF

struct tag_MKU8VImszW7wooGA4sgbqF
{
  emxArray_real_T_Swingup_MPC_T *workspace_double;
  emxArray_int32_T_885_Swingup__T workspace_int;
  emxArray_int32_T_885_Swingup__T workspace_sort;
};

#endif                                 /* struct_tag_MKU8VImszW7wooGA4sgbqF */

#ifndef typedef_s_MKU8VImszW7wooGA4sgbqF_Swin_T
#define typedef_s_MKU8VImszW7wooGA4sgbqF_Swin_T

typedef struct tag_MKU8VImszW7wooGA4sgbqF s_MKU8VImszW7wooGA4sgbqF_Swin_T;

#endif                             /* typedef_s_MKU8VImszW7wooGA4sgbqF_Swin_T */

#ifndef struct_emxArray_int32_T_483
#define struct_emxArray_int32_T_483

struct emxArray_int32_T_483
{
  int32_T data[483];
  int32_T size;
};

#endif                                 /* struct_emxArray_int32_T_483 */

#ifndef typedef_emxArray_int32_T_483_Swingup__T
#define typedef_emxArray_int32_T_483_Swingup__T

typedef struct emxArray_int32_T_483 emxArray_int32_T_483_Swingup__T;

#endif                             /* typedef_emxArray_int32_T_483_Swingup__T */

#ifndef struct_emxArray_boolean_T_885
#define struct_emxArray_boolean_T_885

struct emxArray_boolean_T_885
{
  boolean_T data[885];
  int32_T size;
};

#endif                                 /* struct_emxArray_boolean_T_885 */

#ifndef typedef_emxArray_boolean_T_885_Swingu_T
#define typedef_emxArray_boolean_T_885_Swingu_T

typedef struct emxArray_boolean_T_885 emxArray_boolean_T_885_Swingu_T;

#endif                             /* typedef_emxArray_boolean_T_885_Swingu_T */

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_wNHVC0Ht50UohieFHTczdE
#define struct_tag_wNHVC0Ht50UohieFHTczdE

struct tag_wNHVC0Ht50UohieFHTczdE
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  emxArray_real_T_Swingup_MPC_T *Aineq;
  emxArray_real_T_240_Swingup_M_T bineq;
  emxArray_real_T_Swingup_MPC_T *Aeq;
  real_T beq[80];
  emxArray_real_T_483_Swingup_M_T lb;
  emxArray_real_T_483_Swingup_M_T ub;
  emxArray_int32_T_483_Swingup__T indexLB;
  emxArray_int32_T_483_Swingup__T indexUB;
  emxArray_int32_T_483_Swingup__T indexFixed;
  int32_T mEqRemoved;
  int32_T indexEqRemoved[80];
  emxArray_real_T_Swingup_MPC_T *ATwset;
  emxArray_real_T_885_Swingup_M_T bwset;
  int32_T nActiveConstr;
  emxArray_real_T_885_Swingup_M_T maxConstrWorkspace;
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
  emxArray_boolean_T_885_Swingu_T isActiveConstr;
  emxArray_int32_T_885_Swingup__T Wid;
  emxArray_int32_T_885_Swingup__T Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                 /* struct_tag_wNHVC0Ht50UohieFHTczdE */

#ifndef typedef_s_wNHVC0Ht50UohieFHTczdE_Swin_T
#define typedef_s_wNHVC0Ht50UohieFHTczdE_Swin_T

typedef struct tag_wNHVC0Ht50UohieFHTczdE s_wNHVC0Ht50UohieFHTczdE_Swin_T;

#endif                             /* typedef_s_wNHVC0Ht50UohieFHTczdE_Swin_T */

#ifndef struct_emxArray_real_T_482
#define struct_emxArray_real_T_482

struct emxArray_real_T_482
{
  real_T data[482];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_482 */

#ifndef typedef_emxArray_real_T_482_Swingup_M_T
#define typedef_emxArray_real_T_482_Swingup_M_T

typedef struct emxArray_real_T_482 emxArray_real_T_482_Swingup_M_T;

#endif                             /* typedef_emxArray_real_T_482_Swingup_M_T */

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_3NgQh2XxNZ9U1xDE2ltNMG
#define struct_tag_3NgQh2XxNZ9U1xDE2ltNMG

struct tag_3NgQh2XxNZ9U1xDE2ltNMG
{
  emxArray_real_T_483_Swingup_M_T grad;
  emxArray_real_T_482_Swingup_M_T Hx;
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

#endif                                 /* struct_tag_3NgQh2XxNZ9U1xDE2ltNMG */

#ifndef typedef_s_3NgQh2XxNZ9U1xDE2ltNMG_Swin_T
#define typedef_s_3NgQh2XxNZ9U1xDE2ltNMG_Swin_T

typedef struct tag_3NgQh2XxNZ9U1xDE2ltNMG s_3NgQh2XxNZ9U1xDE2ltNMG_Swin_T;

#endif                             /* typedef_s_3NgQh2XxNZ9U1xDE2ltNMG_Swin_T */

#ifndef struct_tag_nbxu8969ZaTcdhvQHeF5DH
#define struct_tag_nbxu8969ZaTcdhvQHeF5DH

struct tag_nbxu8969ZaTcdhvQHeF5DH
{
  int32_T ldq;
  emxArray_real_T_Swingup_MPC_T *QR;
  emxArray_real_T_Swingup_MPC_T *Q;
  emxArray_int32_T_885_Swingup__T jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T_885_Swingup_M_T tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                 /* struct_tag_nbxu8969ZaTcdhvQHeF5DH */

#ifndef typedef_s_nbxu8969ZaTcdhvQHeF5DH_Swin_T
#define typedef_s_nbxu8969ZaTcdhvQHeF5DH_Swin_T

typedef struct tag_nbxu8969ZaTcdhvQHeF5DH s_nbxu8969ZaTcdhvQHeF5DH_Swin_T;

#endif                             /* typedef_s_nbxu8969ZaTcdhvQHeF5DH_Swin_T */

#ifndef struct_emxArray_real_T_160
#define struct_emxArray_real_T_160

struct emxArray_real_T_160
{
  real_T data[160];
  int32_T size;
};

#endif                                 /* struct_emxArray_real_T_160 */

#ifndef typedef_emxArray_real_T_160_Swingup_M_T
#define typedef_emxArray_real_T_160_Swingup_M_T

typedef struct emxArray_real_T_160 emxArray_real_T_160_Swingup_M_T;

#endif                             /* typedef_emxArray_real_T_160_Swingup_M_T */

/* Custom Type definition for MATLAB Function: '<S6>/NLMPC' */
#ifndef struct_tag_zrVBpH4thjN52Kscr0JOTH
#define struct_tag_zrVBpH4thjN52Kscr0JOTH

struct tag_zrVBpH4thjN52Kscr0JOTH
{
  anonymous_function_Swingup_MP_T objfun;
  anonymous_function_Swingup_MP_T nonlin;
  real_T f_1;
  emxArray_real_T_160_Swingup_M_T cIneq_1;
  real_T cEq_1[80];
  real_T f_2;
  emxArray_real_T_160_Swingup_M_T cIneq_2;
  real_T cEq_2[80];
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T isEmptyNonlcon;
  boolean_T hasLB[82];
  boolean_T hasUB[82];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

#endif                                 /* struct_tag_zrVBpH4thjN52Kscr0JOTH */

#ifndef typedef_s_zrVBpH4thjN52Kscr0JOTH_Swin_T
#define typedef_s_zrVBpH4thjN52Kscr0JOTH_Swin_T

typedef struct tag_zrVBpH4thjN52Kscr0JOTH s_zrVBpH4thjN52Kscr0JOTH_Swin_T;

#endif                             /* typedef_s_zrVBpH4thjN52Kscr0JOTH_Swin_T */

/* Parameters (default storage) */
typedef struct P_Swingup_MPC_T_ P_Swingup_MPC_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Swingup_MPC_T RT_MODEL_Swingup_MPC_T;

#endif                                 /* RTW_HEADER_Swingup_MPC_types_h_ */
