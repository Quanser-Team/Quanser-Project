/*
 * Swingup_MPC.c
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

#include "Swingup_MPC.h"
#include "rtwtypes.h"
#include "Swingup_MPC_types.h"
#include <math.h>
#include <emmintrin.h>
#include <string.h>
#include "Swingup_MPC_private.h"
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <stddef.h>
#include "Swingup_MPC_dt.h"

/* Block signals (default storage) */
B_Swingup_MPC_T Swingup_MPC_B;

/* Continuous states */
X_Swingup_MPC_T Swingup_MPC_X;

/* Block states (default storage) */
DW_Swingup_MPC_T Swingup_MPC_DW;

/* Real-time model */
static RT_MODEL_Swingup_MPC_T Swingup_MPC_M_;
RT_MODEL_Swingup_MPC_T *const Swingup_MPC_M = &Swingup_MPC_M_;

/* Forward declaration for local functions */
static void Swingup_MPC_mtimes(const real_T A_data[], const int32_T A_size[2],
  real_T C_data[], int32_T C_size[2]);
static void Swingup_MPC_znlmpc_getXUe(const real_T z[44], const real_T x[4],
  real_T X[44], real_T U[11], real_T *e);
static void Swingup_MPC_mldivide_m(const real_T A[16], real_T B[4]);
static void Swi_znlmpc_computeJacobianState(const real_T f0[4], real_T x0[4],
  real_T u0, real_T Jx[16], real_T Jmv[4]);
static void Swingup_MPC_all(const boolean_T x[40], boolean_T y[4]);
static boolean_T Swingup_MPC_any(const boolean_T x[8]);
static void Swingup_eML_blk_kernel_anonFcn2(const real_T runtimedata_x[4], const
  real_T runtimedata_OutputMin[40], const real_T runtimedata_OutputMax[40],
  const real_T z[44], real_T varargout_1_data[], int32_T varargout_1_size[2],
  real_T varargout_2[40], real_T varargout_3_data[], int32_T varargout_3_size[2],
  real_T varargout_4[1760]);
static void Swingup_MPC_emxInit_real_T(emxArray_real_T_Swingup_MPC_T **pEmxArray,
  int32_T numDimensions);
static void emxInitStruct_s_k1Ho7Q1nYjseRM5(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T
  *pStruct);
static void Swingu_emxEnsureCapacity_real_T(emxArray_real_T_Swingup_MPC_T
  *emxArray, int32_T oldNumel);
static void Swingup_MPC_factoryConstruct(int32_T nVarMax, int32_T mConstrMax,
  int32_T mIneq, int32_T mNonlinIneq, s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *obj);
static void Swingup_M_factoryConstruct_h3jt(int32_T MaxVars, int32_T
  *obj_grad_size, int32_T *obj_Hx_size, boolean_T *obj_hasLinear, int32_T
  *obj_nvar, int32_T *obj_maxVar, real_T *obj_beta, real_T *obj_rho, int32_T
  *obj_objtype, int32_T *obj_prev_objtype, int32_T *obj_prev_nvar, boolean_T
  *obj_prev_hasLinear, real_T *obj_gammaScalar);
static void emxInitStruct_s_j0Ykcy5K3TT7uFO(s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *pStruct);
static void emxInitStruct_s_pBvMsf7fBJa4zdf(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *pStruct);
static void Swingup__factoryConstruct_h3jty(int32_T mIneqMax, int32_T nVarMax,
  int32_T mConstrMax, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj);
static int32_T Swingup_MP_checkVectorNonFinite(int32_T N, const real_T vec_data[],
  int32_T iv0);
static int32_T Swingup__checkVectorNonFinite_b(const real_T vec[40]);
static void evalObjAndConstrAndDerivatives(int32_T
  obj_next_next_next_next_next_va, const s_GSKgPzH92oA7AAcXEvWMnG_Swin_T
  *obj_next_next_next_next_next_ne, const s_OOgWGXXQYnSElkPXvuQxeH_Swin_T
  *obj_next_next_next_next_next__0, const real_T x[44], real_T
  grad_workspace_data[], real_T Cineq_workspace_data[], int32_T ineq0, real_T
  Ceq_workspace[40], emxArray_real_T_Swingup_MPC_T *JacIneqTrans_workspace,
  int32_T iJI_col, int32_T ldJI, emxArray_real_T_Swingup_MPC_T
  *JacEqTrans_workspace, int32_T ldJE, real_T *fval, int32_T *status);
static void Swingup_modifyOverheadPhaseOne_(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj);
static void Swingup_MPC_setProblemType(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T PROBLEM_TYPE);
static void Swingup_MPC_initActiveSet(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj);
static void emxInitStruct_s_qjgm7GzdZt1MoSN(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T
  *pStruct);
static void Swingup_MPC_factoryConstruct_h3(int32_T maxRows, int32_T maxCols,
  int32_T *obj_ldq, emxArray_real_T_Swingup_MPC_T *obj_QR,
  emxArray_real_T_Swingup_MPC_T *obj_Q, int32_T obj_jpvt_data[], int32_T
  *obj_jpvt_size, int32_T *obj_mrows, int32_T *obj_ncols, int32_T *obj_tau_size,
  int32_T *obj_minRowCol, boolean_T *obj_usedPivoting);
static void emxInitStruct_s_xgaiQX2t1f8Iwfq(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *pStruct);
static void Swingup_MP_factoryConstruct_h3j(int32_T MaxDims,
  emxArray_real_T_Swingup_MPC_T *obj_FMat, int32_T *obj_ldm, int32_T *obj_ndims,
  int32_T *obj_info, real_T *obj_scaleFactor, boolean_T *obj_ConvexCheck, real_T
  *obj_regTol_, real_T *obj_workspace_, real_T *obj_workspace2_);
static void Swingup_MPC_computeGradLag(real_T workspace_data[], int32_T ldA,
  int32_T nVar, const real_T grad_data[], int32_T mIneq, const
  emxArray_real_T_Swingup_MPC_T *AineqTrans, const emxArray_real_T_Swingup_MPC_T
  *AeqTrans, const int32_T finiteFixed_data[], int32_T mFixed, const int32_T
  finiteLB_data[], int32_T mLB, const int32_T finiteUB_data[], int32_T mUB,
  const real_T lambda_data[]);
static real_T Swingup__computePrimalFeasError(const real_T x[44], int32_T
  mLinIneq, int32_T mNonlinIneq, const real_T cIneq_data[], const real_T cEq[40],
  const int32_T finiteLB_data[], int32_T mLB, const real_T lb[44], const int32_T
  finiteUB_data[], int32_T mUB);
static void Swingup_MP_computeDualFeasError(int32_T nVar, const real_T
  gradLag_data[], boolean_T *gradOK, real_T *val);
static void Swingup_MPC_emxFree_real_T(emxArray_real_T_Swingup_MPC_T **pEmxArray);
static void Swingup_MPC_saveJacobian(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *obj,
  int32_T nVar, int32_T mIneq, const emxArray_real_T_Swingup_MPC_T
  *JacCineqTrans, int32_T ineqCol0, const emxArray_real_T_Swingup_MPC_T
  *JacCeqTrans, int32_T ldJ);
static real_T Swingup_MPC_computeComplError(const int32_T
  *fscales_lineq_constraint_size, const int32_T *fscales_cineq_constraint_size,
  const real_T xCurrent[44], int32_T mIneq, const real_T cIneq_data[], const
  int32_T finiteLB_data[], int32_T mLB, const real_T lb[44], const int32_T
  finiteUB_data[], int32_T mUB, const real_T lambda_data[], int32_T iL0);
static void Swingup_MPC_computeGradLag_b(emxArray_real_T_Swingup_MPC_T
  *workspace, int32_T ldA, int32_T nVar, const real_T grad_data[], int32_T mIneq,
  const emxArray_real_T_Swingup_MPC_T *AineqTrans, const
  emxArray_real_T_Swingup_MPC_T *AeqTrans, const int32_T finiteFixed_data[],
  int32_T mFixed, const int32_T finiteLB_data[], int32_T mLB, const int32_T
  finiteUB_data[], int32_T mUB, const real_T lambda_data[]);
static void Swingup__computeDualFeasError_e(int32_T nVar, const
  emxArray_real_T_Swingup_MPC_T *gradLag, boolean_T *gradOK, real_T *val);
static void Swingu_updateWorkingSetForNewQP(const real_T xk[44],
  s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *WorkingSet, int32_T mIneq, int32_T
  mNonlinIneq, const real_T cIneq_data[], const real_T cEq[40], int32_T mLB,
  const real_T lb[44], int32_T mUB, int32_T mFixed);
static void Swingup_MPC_xswap(int32_T n, emxArray_real_T_Swingup_MPC_T *x,
  int32_T ix0, int32_T iy0);
static real_T Swingup_MPC_xnrm2(int32_T n, const emxArray_real_T_Swingup_MPC_T
  *x, int32_T ix0);
static real_T Swingup_MPC_xzlarfg(int32_T n, real_T *alpha1,
  emxArray_real_T_Swingup_MPC_T *x, int32_T ix0);
static void Swingup_MPC_xgemv(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T ia0, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *x, int32_T ix0, real_T y_data[]);
static void Swingup_MPC_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y_data[], emxArray_real_T_Swingup_MPC_T *A, int32_T ia0, int32_T
  lda);
static void Swingup_MPC_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  emxArray_real_T_Swingup_MPC_T *C, int32_T ic0, int32_T ldc, real_T work_data[]);
static void Swingup_MPC_qrf(emxArray_real_T_Swingup_MPC_T *A, int32_T m, int32_T
  n, int32_T nfxd, real_T tau_data[]);
static void Swingup_MPC_qrpf(emxArray_real_T_Swingup_MPC_T *A, int32_T m,
  int32_T n, int32_T nfxd, real_T tau_data[], int32_T jpvt_data[]);
static void Swingup_MPC_xgeqp3(emxArray_real_T_Swingup_MPC_T *A, int32_T m,
  int32_T n, int32_T jpvt_data[], real_T tau_data[], int32_T *tau_size);
static void Swingup_MPC_factorQRE(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T mrows, int32_T ncols, int32_T ldA);
static void Swingup_MPC_xorgqr(int32_T m, int32_T n, int32_T k,
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T tau_data[]);
static void Swingup_MPC_xgemv_n(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T x_data[],
  emxArray_real_T_Swingup_MPC_T *y);
static void Swingup_MPC_sortLambdaQP(real_T lambda_data[], int32_T
  WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5], const int32_T
  WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid_data[], const int32_T
  WorkingSet_Wlocalidx_data[], emxArray_real_T_Swingup_MPC_T *workspace);
static void Swingup_MPC_test_exit(s7RdrPWkr8UPAUyTdDJkLaG_Swing_T *Flags,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, sG8JZ69axY52WWR6RKyApQC_Swing_T
  *MeritFunction, const int32_T *fscales_lineq_constraint_size, const int32_T
  *fscales_cineq_constraint_size, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *WorkingSet,
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T
  *QRManager, const real_T lb[44]);
static boolean_T Swingup_MPC_BFGSUpdate(int32_T nvar, real_T Bk[1936], const
  real_T sk_data[], real_T yk_data[], emxArray_real_T_Swingup_MPC_T *workspace);
static void Swingup_MPC_factorQRE_f(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj,
  int32_T mrows, int32_T ncols);
static void Swingup_MPC_countsort(int32_T x_data[], int32_T xLen, int32_T
  workspace_data[], int32_T xMin, int32_T xMax);
static void Swingup_MPC_removeConstr(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T idx_global);
static int32_T Swingup_MPC_RemoveDependentEq_(s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset,
  s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager);
static void Swingup_MP_RemoveDependentIneq_(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace);
static void Swingup_MPC_xgeqrf(emxArray_real_T_Swingup_MPC_T *A, int32_T m,
  int32_T n, real_T tau_data[], int32_T *tau_size);
static void Swingup_MPC_factorQR_j(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T mrows, int32_T ncols, int32_T ldA);
static void Swingup_MPC_factorQR(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj, int32_T
  mrows, int32_T ncols);
static void Swingup_MPC_xgemv_nbn(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *x, real_T y_data[]);
static void Swingup_MPC_xgemv_nb(int32_T n, const emxArray_real_T_Swingup_MPC_T *
  A, int32_T lda, const emxArray_real_T_Swingup_MPC_T *x, real_T y_data[]);
static real_T Swingup__maxConstraintViolation(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *obj, const emxArray_real_T_Swingup_MPC_T *x);
static void Swingup_MPC_xgemv_nbnh(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *x, int32_T ix0, real_T y_data[]);
static real_T Swingu_maxConstraintViolation_l(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *obj, const emxArray_real_T_Swingup_MPC_T *x, int32_T ix0);
static boolean_T Swingup_feasibleX0ForWorkingSet(emxArray_real_T_Swingup_MPC_T
  *workspace, real_T xCurrent_data[], s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager);
static void Swingup__RemoveDependentIneq__b(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace);
static void Swingup_MPC_xgemv_nbnhgm(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T x_data[], real_T
  y_data[]);
static void Swingup_MPC_xgemv_nbnhg(int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T x_data[], real_T
  y_data[]);
static real_T Swing_maxConstraintViolation_l2(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *obj, const real_T x_data[]);
static void Swingup_MPC_PresolveWorkingSet(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T
  *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace,
  s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T
  *qrmanager);
static void Swingup_MPC_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  emxArray_real_T_Swingup_MPC_T *workspace, const real_T H[1936], const real_T
  f_data[], const real_T x_data[]);
static real_T Swingup_MPC_computeFval(const s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *obj,
  emxArray_real_T_Swingup_MPC_T *workspace, const real_T H[1936], const real_T
  f_data[], const real_T x_data[]);
static void Swingup_MPC_xgemv_nbnhgms(int32_T m, int32_T n, const real_T A[1936],
  int32_T lda, const real_T x_data[], real_T y_data[]);
static void Swingup_MPC_computeGrad_StoreHx(s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *obj,
  const real_T H[1936], const real_T f_data[], const real_T x_data[]);
static real_T Swingup_MPC_computeFval_ReuseHx(const
  s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *obj, emxArray_real_T_Swingup_MPC_T *workspace,
  const real_T f_data[], const real_T x_data[]);
static void Swingup_MPC_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void Swingup_MPC_deleteColMoveEnd(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj,
  int32_T idx);
static boolean_T Swingup_MPC_strcmp(const char_T a[7]);
static void Swingup_MPC_xgemm(int32_T m, int32_T n, int32_T k, const real_T A
  [1936], int32_T lda, const emxArray_real_T_Swingup_MPC_T *B, int32_T ib0,
  int32_T ldb, emxArray_real_T_Swingup_MPC_T *C, int32_T ldc);
static void Swingup_MPC_xgemm_h(int32_T m, int32_T n, int32_T k, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T ia0, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *B, int32_T ldb, emxArray_real_T_Swingup_MPC_T
  *C, int32_T ldc);
static void Swingup_MPC_fullColLDL2_(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj,
  int32_T LD_offset, int32_T NColsRemain);
static void Swingup_MPC_partialColLDL3_(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj,
  int32_T LD_offset, int32_T NColsRemain);
static int32_T Swingup_MPC_xpotrf(int32_T n, emxArray_real_T_Swingup_MPC_T *A,
  int32_T lda);
static void Swingup_MPC_xgemv_nbnhgmsy(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T ia0, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *x, real_T y_data[]);
static void Swingup_MPC_factor(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj, const
  real_T A[1936], int32_T ndims, int32_T ldA);
static void Swingup_MPC_solve(const s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj, real_T
  rhs_data[]);
static void Swingup_MPC_factor_e(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj, const
  real_T A[1936], int32_T ndims, int32_T ldA);
static void Swingup_MPC_solve_c(const s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj,
  real_T rhs_data[]);
static void Swingup_MPC_compute_deltax(const real_T H[1936],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, const s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *cholmanager, const
  s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective, boolean_T alwaysPositiveDef);
static real_T Swingup_MPC_xnrm2_l(int32_T n, const real_T x_data[]);
static void Swingup_MPC_xgemv_nbnhgmsyw(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T x_data[],
  emxArray_real_T_Swingup_MPC_T *y);
static void Swingup_MPC_feasibleratiotest(const real_T solution_xstar_data[],
  const real_T solution_searchDir_data[], emxArray_real_T_Swingup_MPC_T
  *workspace, int32_T workingset_nVar, int32_T workingset_ldA, const
  emxArray_real_T_Swingup_MPC_T *workingset_Aineq, const real_T
  workingset_bineq_data[], const real_T workingset_lb_data[], const int32_T
  workingset_indexLB_data[], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr_data[],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
static void Swingu_checkUnboundedOrIllPosed(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T
  *solution, const s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective);
static void Swin_addBoundToActiveSetMatrix_(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T TYPE, int32_T idx_local);
static void Swingup_MPC_addAineqConstr(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T idx_local);
static void Swin_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f_data[], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, const
  s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
  updateFval);
static void Swingup_MPC_iterate(const real_T H[1936], const real_T f_data[],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset,
  s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager, s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *cholmanager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective, const char_T
  options_SolverName[7], real_T options_StepTolerance, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations);
static void Swingup_MPC_phaseone(const real_T H[1936], const real_T f_data[],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset,
  s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager, s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *cholmanager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective,
  somzaGboVhDG7PNQS6E98jD_Swing_T *options, const
  somzaGboVhDG7PNQS6E98jD_Swing_T *runTimeOptions);
static void Swingup_MPC_driver_e(const real_T H[1936], const real_T f_data[],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset,
  s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager, s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *cholmanager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective,
  somzaGboVhDG7PNQS6E98jD_Swing_T *options, somzaGboVhDG7PNQS6E98jD_Swing_T
  *runTimeOptions);
static void Swingup_MPC_addAeqConstr(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T idx_local);
static boolean_T Swingup_MPC_soc(const real_T Hessian[1936], const real_T
  grad_data[], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, const somzaGboVhDG7PNQS6E98jD_Swing_T *qpoptions);
static void Swingup_MPC_normal(const real_T Hessian[1936], const real_T
  grad_data[], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Swing_T *MeritFunction,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, const somzaGboVhDG7PNQS6E98jD_Swing_T *qpoptions);
static void Swingup_MPC_emxCopy_real_T(emxArray_real_T_Swingup_MPC_T **dst,
  emxArray_real_T_Swingup_MPC_T * const *src);
static void Swingup_MPC_emxCopy_real_T_120(emxArray_real_T_120_Swingup_M_T *dst,
  const emxArray_real_T_120_Swingup_M_T *src);
static void Swingup_MP_emxCopyMatrix_real_T(real_T dst[40], const real_T src[40]);
static void Swingup_MPC_emxCopy_real_T_245(emxArray_real_T_245_Swingup_M_T *dst,
  const emxArray_real_T_245_Swingup_M_T *src);
static void Swingup_MPC_emxCopy_int32_T_245(emxArray_int32_T_245_Swingup__T *dst,
  const emxArray_int32_T_245_Swingup__T *src);
static void Swingup_M_emxCopyMatrix_int32_T(int32_T dst[40], const int32_T src
  [40]);
static void Swingup_MPC_emxCopy_real_T_449(emxArray_real_T_449_Swingup_M_T *dst,
  const emxArray_real_T_449_Swingup_M_T *src);
static void Swingup__emxCopyMatrix_int32_T1(int32_T dst[5], const int32_T src[5]);
static void Swingup__emxCopyMatrix_int32_T2(int32_T dst[6], const int32_T src[6]);
static void Swingup_M_emxCopy_boolean_T_449(emxArray_boolean_T_449_Swingu_T *dst,
  const emxArray_boolean_T_449_Swingu_T *src);
static void Swingup_MPC_emxCopy_int32_T_449(emxArray_int32_T_449_Swingup__T *dst,
  const emxArray_int32_T_449_Swingup__T *src);
static void emxCopyStruct_s_pBvMsf7fBJa4zdf(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *dst,
  const s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *src);
static void emxFreeStruct_s_pBvMsf7fBJa4zdf(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *pStruct);
static void Swingup_MPC_relaxed(const real_T Hessian[1936], const real_T
  grad_data[], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Swing_T *MeritFunction,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, somzaGboVhDG7PNQS6E98jD_Swing_T *qpoptions);
static boolean_T Swingup_MPC_step_l(int32_T *STEP_TYPE, real_T Hessian[1936],
  const real_T lb[44], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Swing_T *MeritFunction,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, somzaGboVhDG7PNQS6E98jD_Swing_T *qpoptions);
static void Swingup_MPC_evalObjAndConstr(int32_T obj_next_next_next_next_next_va,
  const s_GSKgPzH92oA7AAcXEvWMnG_Swin_T *obj_next_next_next_next_next_ne, const
  s_OOgWGXXQYnSElkPXvuQxeH_Swin_T *obj_next_next_next_next_next__0, const real_T
  x[44], real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[40],
  real_T *fval, int32_T *status);
static void Swingup__computeLinearResiduals(const real_T x[44], int32_T nVar,
  real_T workspaceIneq_data[], const int32_T *workspaceIneq_size, int32_T
  mLinIneq, const emxArray_real_T_Swingup_MPC_T *AineqT, const real_T
  bineq_data[], int32_T ldAi);
static real_T Swingup_MPC_computeMeritFcn(real_T obj_penaltyParam, real_T fval,
  const real_T Cineq_workspace_data[], int32_T mIneq, const real_T
  Ceq_workspace[40], boolean_T evalWellDefined);
static void Swingup_MPC_linesearch(boolean_T *evalWellDefined, const real_T
  bineq_data[], int32_T WorkingSet_nVar, int32_T WorkingSet_ldA, const
  emxArray_real_T_Swingup_MPC_T *WorkingSet_Aineq,
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState, real_T MeritFunction_penaltyParam,
  real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus, real_T
  MeritFunction_phiFullStep, int32_T FcnEvaluator_next_next_next_nex, const
  s_GSKgPzH92oA7AAcXEvWMnG_Swin_T *FcnEvaluator_next_next_next_n_0, const
  s_OOgWGXXQYnSElkPXvuQxeH_Swin_T *FcnEvaluator_next_next_next_n_1, boolean_T
  socTaken, real_T *alpha, int32_T *exitflag);
static void Swingup_MPC_driver(const real_T bineq_data[], const real_T lb[44],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState, sG8JZ69axY52WWR6RKyApQC_Swing_T
  *MeritFunction, const coder_internal_stickyStruct_9_T *FcnEvaluator,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, const int32_T *fscales_lineq_constraint_size, const int32_T
  *fscales_cineq_constraint_size, real_T Hessian[1936]);
static void emxFreeStruct_s_xgaiQX2t1f8Iwfq(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *pStruct);
static void emxFreeStruct_s_qjgm7GzdZt1MoSN(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T
  *pStruct);
static void emxFreeStruct_s_j0Ykcy5K3TT7uFO(s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *pStruct);
static void emxFreeStruct_s_k1Ho7Q1nYjseRM5(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T
  *pStruct);
static void Swingup_MPC_fmincon(const s_GSKgPzH92oA7AAcXEvWMnG_Swin_T
  *fun_workspace_runtimedata, const sXyXDxkiKhsfpX9ivkpx9WG_Swing_T
  *fun_workspace_userdata, const real_T x0[44], const real_T Aineq_data[], const
  real_T bineq_data[], const int32_T *bineq_size, const real_T lb[44], const
  s_GSKgPzH92oA7AAcXEvWMnG_Swin_T *nonlcon_workspace_runtimedata, const
  sXyXDxkiKhsfpX9ivkpx9WG_Swing_T *nonlcon_workspace_userdata, real_T x[44],
  real_T *fval, real_T *exitflag, sttYSJM5GCi2c1Eu0R50efC_Swing_T *output);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Swingup_MPC_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Swingup_MPC_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (Swingup_MPC_M->Timing.TaskCounters.TID[1] == 0) {
    Swingup_MPC_M->Timing.RateInteraction.TID1_2 =
      (Swingup_MPC_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Swingup_MPC_M->Timing.perTaskSampleHits[5] =
      Swingup_MPC_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Swingup_MPC_M->Timing.TaskCounters.TID[2])++;
  if ((Swingup_MPC_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.001s, 0.0s] */
    Swingup_MPC_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
  Swingup_MPC_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_mtimes(const real_T A_data[], const int32_T A_size[2],
  real_T C_data[], int32_T C_size[2])
{
  real_T s;
  int32_T boffset;
  int32_T coffset;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T m;
  static const int8_T c[30] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };

  m = A_size[0];
  C_size[0] = A_size[0];
  C_size[1] = 3;
  for (j = 0; j < 3; j++) {
    coffset = j * m;
    boffset = j * 10;
    for (i = 0; i < m; i++) {
      s = 0.0;
      for (k = 0; k < 10; k++) {
        s += A_data[k * A_size[0] + i] * (real_T)c[boffset + k];
      }

      C_data[coffset + i] = s;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_znlmpc_getXUe(const real_T z[44], const real_T x[4],
  real_T X[44], real_T U[11], real_T *e)
{
  real_T z_0[40];
  int32_T X_tmp;
  int32_T i;
  static const int8_T y[30] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };

  for (i = 0; i < 44; i++) {
    X[i] = 0.0;
  }

  for (i = 0; i < 11; i++) {
    U[i] = 0.0;
  }

  for (i = 0; i < 10; i++) {
    U[i] = ((real_T)y[i + 10] * z[41] + (real_T)y[i] * z[40]) + (real_T)y[i + 20]
      * z[42];
  }

  *e = z[43];
  memcpy(&z_0[0], &z[0], 40U * sizeof(real_T));
  for (i = 0; i < 10; i++) {
    X_tmp = i << 2;
    X[i + 1] = z_0[X_tmp];
    X[i + 12] = z_0[X_tmp + 1];
    X[i + 23] = z_0[X_tmp + 2];
    X[i + 34] = z_0[X_tmp + 3];
  }

  X[0] = x[0];
  X[11] = x[1];
  X[22] = x[2];
  X[33] = x[3];
  U[10] = U[9];
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_mldivide_m(const real_T A[16], real_T B[4])
{
  __m128d tmp;
  real_T b_A[16];
  real_T s;
  real_T smax;
  int32_T b_ix;
  int32_T c_k;
  int32_T e;
  int32_T ix;
  int32_T iy;
  int32_T j;
  int32_T jj;
  int32_T vectorUB;
  int8_T ipiv[4];
  memcpy(&b_A[0], &A[0], sizeof(real_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    jj = j * 5;
    iy = 4 - j;
    b_ix = 0;
    ix = jj;
    smax = fabs(b_A[jj]);
    for (c_k = 2; c_k <= iy; c_k++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > smax) {
        b_ix = c_k - 1;
        smax = s;
      }
    }

    if (b_A[jj + b_ix] != 0.0) {
      if (b_ix != 0) {
        iy = j + b_ix;
        ipiv[j] = (int8_T)(iy + 1);
        smax = b_A[j];
        b_A[j] = b_A[iy];
        b_A[iy] = smax;
        smax = b_A[j + 4];
        b_A[j + 4] = b_A[iy + 4];
        b_A[iy + 4] = smax;
        smax = b_A[j + 8];
        b_A[j + 8] = b_A[iy + 8];
        b_A[iy + 8] = smax;
        smax = b_A[j + 12];
        b_A[j + 12] = b_A[iy + 12];
        b_A[iy + 12] = smax;
      }

      iy = (jj - j) + 4;
      c_k = (((((iy - jj) - 1) / 2) << 1) + jj) + 2;
      vectorUB = c_k - 2;
      for (b_ix = jj + 2; b_ix <= vectorUB; b_ix += 2) {
        tmp = _mm_loadu_pd(&b_A[b_ix - 1]);
        _mm_storeu_pd(&b_A[b_ix - 1], _mm_div_pd(tmp, _mm_set1_pd(b_A[jj])));
      }

      for (b_ix = c_k; b_ix <= iy; b_ix++) {
        b_A[b_ix - 1] /= b_A[jj];
      }
    }

    iy = jj + 4;
    b_ix = jj + 6;
    ix = 2 - j;
    for (c_k = 0; c_k <= ix; c_k++) {
      smax = b_A[iy];
      if (b_A[iy] != 0.0) {
        e = (b_ix - j) + 2;
        for (vectorUB = b_ix; vectorUB <= e; vectorUB++) {
          b_A[vectorUB - 1] += b_A[((jj + vectorUB) - b_ix) + 1] * -smax;
        }
      }

      iy += 4;
      b_ix += 4;
    }
  }

  if (ipiv[0] != 1) {
    smax = B[0];
    B[0] = B[ipiv[0] - 1];
    B[ipiv[0] - 1] = smax;
  }

  if (ipiv[1] != 2) {
    smax = B[1];
    B[1] = B[ipiv[1] - 1];
    B[ipiv[1] - 1] = smax;
  }

  if (ipiv[2] != 3) {
    smax = B[2];
    B[2] = B[ipiv[2] - 1];
    B[ipiv[2] - 1] = smax;
  }

  for (j = 0; j < 4; j++) {
    jj = j << 2;
    if (B[j] != 0.0) {
      for (iy = j + 2; iy < 5; iy++) {
        B[iy - 1] -= b_A[(iy + jj) - 1] * B[j];
      }
    }
  }

  for (j = 3; j >= 0; j--) {
    jj = j << 2;
    if (B[j] != 0.0) {
      B[j] /= b_A[j + jj];
      for (b_ix = 0; b_ix < j; b_ix++) {
        B[b_ix] -= b_A[b_ix + jj] * B[j];
      }
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swi_znlmpc_computeJacobianState(const real_T f0[4], real_T x0[4],
  real_T u0, real_T Jx[16], real_T Jmv[4])
{
  real_T A_1[16];
  real_T A[4];
  real_T tmp[4];
  real_T xa[4];
  real_T A_tmp;
  real_T a_tmp;
  real_T dx;
  int32_T Jx_tmp;
  int32_T k;
  dx = fabs(x0[0]);
  if (dx < 1.0) {
    dx = 1.0;
  }

  xa[0] = dx;
  dx = fabs(x0[1]);
  if (dx < 1.0) {
    dx = 1.0;
  }

  xa[1] = dx;
  dx = fabs(x0[2]);
  if (dx < 1.0) {
    dx = 1.0;
  }

  xa[2] = dx;
  dx = fabs(x0[3]);
  if (dx < 1.0) {
    dx = 1.0;
  }

  xa[3] = dx;
  A_1[8] = 0.0;
  A_1[12] = 0.0;
  A_1[5] = 0.0001109943968;
  A_1[9] = 0.0;
  A_1[13] = 0.0;
  A_1[2] = 0.0;
  A_1[3] = 0.0;
  A_1[6] = 0.0;
  A_1[7] = 0.0;
  A_1[10] = 1.0;
  A_1[11] = 0.0;
  A_1[14] = 0.0;
  A_1[15] = 1.0;
  for (k = 0; k < 4; k++) {
    dx = 1.0E-6 * xa[k];
    x0[k] += dx;
    a_tmp = cos(x0[3]);
    A_1[0] = 0.0005983720976 - a_tmp * a_tmp * 7.77845976E-5;
    A_1[4] = -0.0001161372 * a_tmp;
    A_1[1] = -0.00011613720000000002 * a_tmp;
    A_tmp = sin(x0[3]);
    A[0] = (-0.0001161372 * A_tmp * (x0[1] * x0[1]) - 0.0001555691952 * a_tmp *
            A_tmp * x0[1] * x0[0]) - 0.00021 * x0[0];
    A[1] = 0.024 * a_tmp * A_tmp * 0.0032410249 * (x0[0] * x0[0]) - 0.23544 *
      A_tmp * 0.05693;
    A[2] = x0[0];
    A[3] = x0[1];
    Swingup_MPC_mldivide_m(A_1, A);
    x0[k] -= dx;
    tmp[0] = u0 * 0.005;
    tmp[1] = u0 * 0.0;
    tmp[2] = u0 * 0.0;
    tmp[3] = u0 * 0.0;
    Swingup_MPC_mldivide_m(A_1, tmp);
    Jx_tmp = k << 2;
    Jx[Jx_tmp] = ((A[0] + tmp[0]) - f0[0]) / dx;
    Jx[Jx_tmp + 1] = ((A[1] + tmp[1]) - f0[1]) / dx;
    Jx[Jx_tmp + 2] = ((A[2] + tmp[2]) - f0[2]) / dx;
    Jx[Jx_tmp + 3] = ((A[3] + tmp[3]) - f0[3]) / dx;
  }

  dx = fabs(u0);
  if (dx < 1.0) {
    dx = 1.0;
  }

  dx *= 1.0E-6;
  a_tmp = u0 + dx;
  A_tmp = cos(x0[3]);
  A_1[0] = 0.0005983720976 - A_tmp * A_tmp * 7.77845976E-5;
  A_1[4] = -0.0001161372 * cos(x0[3]);
  A_1[8] = 0.0;
  A_1[12] = 0.0;
  A_1[1] = -0.00011613720000000002 * cos(x0[3]);
  A_1[5] = 0.0001109943968;
  A_1[9] = 0.0;
  A_1[13] = 0.0;
  A_1[2] = 0.0;
  A_1[3] = 0.0;
  A_1[6] = 0.0;
  A_1[7] = 0.0;
  A_1[10] = 1.0;
  A_1[11] = 0.0;
  A_1[14] = 0.0;
  A_1[15] = 1.0;
  Jmv[0] = (-0.0001161372 * sin(x0[3]) * (x0[1] * x0[1]) - 0.0001555691952 * cos
            (x0[3]) * sin(x0[3]) * x0[1] * x0[0]) - 0.00021 * x0[0];
  Jmv[1] = 0.024 * cos(x0[3]) * sin(x0[3]) * 0.0032410249 * (x0[0] * x0[0]) -
    0.23544 * sin(x0[3]) * 0.05693;
  Jmv[2] = x0[0];
  Jmv[3] = x0[1];
  Swingup_MPC_mldivide_m(A_1, Jmv);
  tmp[0] = a_tmp * 0.005;
  tmp[1] = a_tmp * 0.0;
  tmp[2] = a_tmp * 0.0;
  tmp[3] = a_tmp * 0.0;
  Swingup_MPC_mldivide_m(A_1, tmp);
  Jmv[0] = ((Jmv[0] + tmp[0]) - f0[0]) / dx;
  Jmv[1] = ((Jmv[1] + tmp[1]) - f0[1]) / dx;
  Jmv[2] = ((Jmv[2] + tmp[2]) - f0[2]) / dx;
  Jmv[3] = ((Jmv[3] + tmp[3]) - f0[3]) / dx;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_all(const boolean_T x[40], boolean_T y[4])
{
  int32_T ix;
  boolean_T exitg1;
  y[0] = true;
  y[1] = true;
  y[2] = true;
  y[3] = true;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= 10)) {
    if (!x[ix - 1]) {
      y[0] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  ix = 11;
  exitg1 = false;
  while ((!exitg1) && (ix <= 20)) {
    if (!x[ix - 1]) {
      y[1] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  ix = 21;
  exitg1 = false;
  while ((!exitg1) && (ix <= 30)) {
    if (!x[ix - 1]) {
      y[2] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  ix = 31;
  exitg1 = false;
  while ((!exitg1) && (ix <= 40)) {
    if (!x[ix - 1]) {
      y[3] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static boolean_T Swingup_MPC_any(const boolean_T x[8])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T y;
  y = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 7)) {
    if (x[k]) {
      y = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_eML_blk_kernel_anonFcn2(const real_T runtimedata_x[4], const
  real_T runtimedata_OutputMin[40], const real_T runtimedata_OutputMax[40],
  const real_T z[44], real_T varargout_1_data[], int32_T varargout_1_size[2],
  real_T varargout_2[40], real_T varargout_3_data[], int32_T varargout_3_size[2],
  real_T varargout_4[1760])
{
  __m128d tmp_3;
  real_T Jmv[400];
  real_T tmp_data[240];
  real_T varargin_2_data[240];
  real_T Jmv_0[120];
  real_T c[80];
  real_T c_data[80];
  real_T X[44];
  real_T b_X[44];
  real_T A_1[16];
  real_T val[16];
  real_T U[11];
  real_T A[4];
  real_T B[4];
  real_T Bk[4];
  real_T ic[4];
  real_T A_tmp;
  real_T A_tmp_0;
  real_T A_tmp_1;
  real_T A_tmp_2;
  real_T A_tmp_3;
  real_T A_tmp_tmp_0;
  real_T U_0;
  real_T a_tmp;
  real_T b_A_tmp;
  real_T b_A_tmp_0;
  real_T e;
  int32_T ic_0[8];
  int32_T A_tmp_tmp;
  int32_T Jx_tmp;
  int32_T i;
  int32_T varargout_2_tmp;
  int8_T Je[80];
  int8_T b_data[80];
  int8_T d_data[80];
  int8_T d[2];
  int8_T tmp_0[2];
  int8_T varargin_2[2];
  int8_T b_sizes_idx_1;
  int8_T input_sizes_idx_0;
  boolean_T icf[80];
  boolean_T tmp[40];
  boolean_T icf_0[8];
  boolean_T x[4];
  boolean_T tmp_1;
  boolean_T tmp_2;
  boolean_T y;
  static const int8_T b_b[30] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };

  real_T b_X_0[4];
  int32_T tmp_size[2];
  int32_T tmp_size_0[2];
  int32_T b_varargin_1_size_idx_0;
  int32_T d_size_idx_0;
  int32_T varargin_1_size_idx_1;
  int32_T varargout_2_tmp_tmp;
  boolean_T exitg1;
  boolean_T guard1;
  Swingup_MPC_znlmpc_getXUe(z, runtimedata_x, X, U, &e);
  for (A_tmp_tmp = 0; A_tmp_tmp < 1600; A_tmp_tmp++) {
    Swingup_MPC_B.Jx[A_tmp_tmp] = 0.0;
  }

  for (A_tmp_tmp = 0; A_tmp_tmp < 400; A_tmp_tmp++) {
    Jmv[A_tmp_tmp] = 0.0;
  }

  for (i = 0; i < 40; i++) {
    varargout_2[i] = 0.0;
  }

  ic[0] = 1.0;
  ic[1] = 2.0;
  ic[2] = 3.0;
  ic[3] = 4.0;
  for (A_tmp_tmp = 0; A_tmp_tmp < 11; A_tmp_tmp++) {
    i = A_tmp_tmp << 2;
    b_X[i] = X[A_tmp_tmp];
    b_X[i + 1] = X[A_tmp_tmp + 11];
    b_X[i + 2] = X[A_tmp_tmp + 22];
    b_X[i + 3] = X[A_tmp_tmp + 33];
  }

  for (i = 0; i < 10; i++) {
    U_0 = U[i];
    a_tmp = cos(b_X[(i << 2) + 3]);
    A_1[0] = 0.0005983720976 - a_tmp * a_tmp * 7.77845976E-5;
    A_1[4] = -0.0001161372 * a_tmp;
    A_1[8] = 0.0;
    A_1[12] = 0.0;
    A_1[1] = -0.00011613720000000002 * a_tmp;
    A_1[5] = 0.0001109943968;
    A_1[9] = 0.0;
    A_1[13] = 0.0;
    A_tmp = sin(b_X[(i << 2) + 3]);
    A_1[2] = 0.0;
    A_1[3] = 0.0;
    B[0] = U_0 * 0.005;
    A_1[6] = 0.0;
    A_1[7] = 0.0;
    B[1] = U_0 * 0.0;
    A_1[10] = 1.0;
    A_1[11] = 0.0;
    B[2] = U_0 * 0.0;
    A_1[14] = 0.0;
    A_1[15] = 1.0;
    B[3] = U_0 * 0.0;
    A_tmp_tmp = i << 2;
    A_tmp_0 = b_X[A_tmp_tmp + 1];
    A_tmp_1 = b_X[A_tmp_tmp];
    A[0] = (A_tmp_0 * A_tmp_0 * (-0.0001161372 * A_tmp) - 0.0001555691952 *
            a_tmp * A_tmp * A_tmp_0 * A_tmp_1) - A_tmp_1 * 0.00021;
    A[1] = 0.024 * a_tmp * A_tmp * 0.0032410249 * (A_tmp_1 * A_tmp_1) - 0.23544 *
      A_tmp * 0.05693;
    A[2] = A_tmp_1;
    A[3] = A_tmp_0;
    Swingup_MPC_mldivide_m(A_1, A);
    Bk[0] = B[0];
    Bk[1] = B[1];
    Bk[2] = B[2];
    Bk[3] = B[3];
    Swingup_MPC_mldivide_m(A_1, Bk);
    A_tmp_0 = A[0] + Bk[0];
    A[0] = A_tmp_0;
    A_tmp_1 = A[1] + Bk[1];
    A[1] = A_tmp_1;
    A_tmp_2 = A[2] + Bk[2];
    A[2] = A_tmp_2;
    A_tmp_3 = A[3] + Bk[3];
    A[3] = A_tmp_3;
    for (A_tmp_tmp = 0; A_tmp_tmp < 4; A_tmp_tmp++) {
      b_X_0[A_tmp_tmp] = b_X[(i << 2) + A_tmp_tmp];
    }

    Swi_znlmpc_computeJacobianState(A, b_X_0, U_0, val, Bk);
    a_tmp = cos(b_X[((i + 1) << 2) + 3]);
    A_1[0] = 0.0005983720976 - a_tmp * a_tmp * 7.77845976E-5;
    A_1[4] = -0.0001161372 * a_tmp;
    A_1[8] = 0.0;
    A_1[12] = 0.0;
    A_1[1] = -0.00011613720000000002 * a_tmp;
    A_1[5] = 0.0001109943968;
    A_1[9] = 0.0;
    A_1[13] = 0.0;
    A_1[2] = 0.0;
    A_1[3] = 0.0;
    A_1[6] = 0.0;
    A_1[7] = 0.0;
    A_1[10] = 1.0;
    A_1[11] = 0.0;
    A_1[14] = 0.0;
    A_1[15] = 1.0;
    A_tmp_tmp = (i + 1) << 2;
    A_tmp_tmp_0 = b_X[A_tmp_tmp + 3];
    A_tmp = sin(A_tmp_tmp_0);
    b_A_tmp = b_X[A_tmp_tmp + 1];
    b_A_tmp_0 = b_X[A_tmp_tmp];
    A[0] = (b_A_tmp * b_A_tmp * (-0.0001161372 * A_tmp) - 0.0001555691952 *
            a_tmp * A_tmp * b_A_tmp * b_A_tmp_0) - b_A_tmp_0 * 0.00021;
    A[1] = 0.024 * a_tmp * A_tmp * 0.0032410249 * (b_A_tmp_0 * b_A_tmp_0) -
      0.23544 * A_tmp * 0.05693;
    A[2] = b_A_tmp_0;
    A[3] = b_A_tmp;
    Swingup_MPC_mldivide_m(A_1, A);
    Swingup_MPC_mldivide_m(A_1, B);
    a_tmp = A[0] + B[0];
    varargout_2_tmp = i << 2;
    varargout_2[(int32_T)ic[0] - 1] = ((A_tmp_0 + a_tmp) * 0.0005 +
      b_X[varargout_2_tmp]) - b_A_tmp_0;
    A[0] = a_tmp;
    a_tmp = A[1] + B[1];
    varargout_2[(int32_T)ic[1] - 1] = ((A_tmp_1 + a_tmp) * 0.0005 +
      b_X[varargout_2_tmp + 1]) - b_A_tmp;
    A[1] = a_tmp;
    a_tmp = A[2] + B[2];
    varargout_2[(int32_T)ic[2] - 1] = ((A_tmp_2 + a_tmp) * 0.0005 +
      b_X[varargout_2_tmp + 2]) - b_X[A_tmp_tmp + 2];
    A[2] = a_tmp;
    a_tmp = A[3] + B[3];
    varargout_2[(int32_T)ic[3] - 1] = ((A_tmp_3 + a_tmp) * 0.0005 +
      b_X[varargout_2_tmp + 3]) - A_tmp_tmp_0;
    A[3] = a_tmp;
    for (A_tmp_tmp = 0; A_tmp_tmp < 4; A_tmp_tmp++) {
      b_X_0[A_tmp_tmp] = b_X[((i + 1) << 2) + A_tmp_tmp];
    }

    Swi_znlmpc_computeJacobianState(A, b_X_0, U_0, A_1, B);
    if (i + 1 > 1) {
      for (A_tmp_tmp = 0; A_tmp_tmp < 4; A_tmp_tmp++) {
        varargout_2_tmp = A_tmp_tmp << 2;
        Jx_tmp = (i - 1) * 160;
        Swingup_MPC_B.Jx[(((int32_T)ic[0] + 40 * A_tmp_tmp) + Jx_tmp) - 1] =
          val[varargout_2_tmp] * 0.0005;
        Swingup_MPC_B.Jx[(((int32_T)ic[1] + 40 * A_tmp_tmp) + Jx_tmp) - 1] =
          val[varargout_2_tmp + 1] * 0.0005;
        Swingup_MPC_B.Jx[(((int32_T)ic[2] + 40 * A_tmp_tmp) + Jx_tmp) - 1] =
          val[varargout_2_tmp + 2] * 0.0005;
        Swingup_MPC_B.Jx[(((int32_T)ic[3] + 40 * A_tmp_tmp) + Jx_tmp) - 1] =
          val[varargout_2_tmp + 3] * 0.0005;
        Swingup_MPC_B.Jx[(((int32_T)ic[A_tmp_tmp] + 40 * A_tmp_tmp) + 160 * (i -
          1)) - 1] = Swingup_MPC_B.Jx[((40 * A_tmp_tmp + (int32_T)ic[A_tmp_tmp])
          + Jx_tmp) - 1] + 1.0;
      }
    }

    for (A_tmp_tmp = 0; A_tmp_tmp < 4; A_tmp_tmp++) {
      Swingup_MPC_B.Jx[(((int32_T)ic[0] + 40 * A_tmp_tmp) + 160 * i) - 1] =
        A_1[A_tmp_tmp << 2] * 0.0005;
      Swingup_MPC_B.Jx[(((int32_T)ic[1] + 40 * A_tmp_tmp) + 160 * i) - 1] = A_1
        [(A_tmp_tmp << 2) + 1] * 0.0005;
      Swingup_MPC_B.Jx[(((int32_T)ic[2] + 40 * A_tmp_tmp) + 160 * i) - 1] = A_1
        [(A_tmp_tmp << 2) + 2] * 0.0005;
      Swingup_MPC_B.Jx[(((int32_T)ic[3] + 40 * A_tmp_tmp) + 160 * i) - 1] = A_1
        [(A_tmp_tmp << 2) + 3] * 0.0005;
      varargout_2_tmp_tmp = (int32_T)ic[A_tmp_tmp];
      varargout_2_tmp = ((40 * A_tmp_tmp + varargout_2_tmp_tmp) + 160 * i) - 1;
      Swingup_MPC_B.Jx[varargout_2_tmp]--;
      Jmv[(varargout_2_tmp_tmp + 40 * i) - 1] = (Bk[A_tmp_tmp] + B[A_tmp_tmp]) *
        0.0005;
    }

    ic[0] += 4.0;
    ic[1] += 4.0;
    ic[2] += 4.0;
    ic[3] += 4.0;
  }

  for (A_tmp_tmp = 0; A_tmp_tmp < 40; A_tmp_tmp++) {
    tmp[A_tmp_tmp] = rtIsInf(runtimedata_OutputMin[A_tmp_tmp]);
  }

  Swingup_MPC_all(tmp, x);
  y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    if (!x[i]) {
      y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  guard1 = false;
  if (y) {
    for (A_tmp_tmp = 0; A_tmp_tmp < 40; A_tmp_tmp++) {
      tmp[A_tmp_tmp] = rtIsInf(runtimedata_OutputMax[A_tmp_tmp]);
    }

    Swingup_MPC_all(tmp, x);
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 4)) {
      if (!x[i]) {
        y = false;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (y) {
      varargout_2_tmp_tmp = 0;
      varargin_1_size_idx_1 = 0;
      b_varargin_1_size_idx_0 = 0;
      d_size_idx_0 = 0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    for (i = 0; i < 80; i++) {
      c[i] = 0.0;
      icf[i] = true;
    }

    for (A_tmp_tmp = 0; A_tmp_tmp < 3200; A_tmp_tmp++) {
      Swingup_MPC_B.b_Jx[A_tmp_tmp] = 0.0;
    }

    memset(&Je[0], 0, 80U * sizeof(int8_T));
    ic[0] = 1.0;
    ic[1] = 2.0;
    ic[2] = 3.0;
    ic[3] = 4.0;
    for (i = 0; i < 10; i++) {
      U_0 = runtimedata_OutputMax[i];
      A_tmp_0 = runtimedata_OutputMin[i];
      icf[(int32_T)ic[0] - 1] = ((!rtIsInf(A_tmp_0)) && (!rtIsNaN(A_tmp_0)));
      x[0] = rtIsInf(U_0);
      y = rtIsNaN(U_0);
      U_0 = runtimedata_OutputMax[i + 10];
      A_tmp_0 = runtimedata_OutputMin[i + 10];
      icf[(int32_T)ic[1] - 1] = ((!rtIsInf(A_tmp_0)) && (!rtIsNaN(A_tmp_0)));
      x[1] = rtIsInf(U_0);
      tmp_1 = rtIsNaN(U_0);
      U_0 = runtimedata_OutputMax[i + 20];
      A_tmp_0 = runtimedata_OutputMin[i + 20];
      icf[(int32_T)ic[2] - 1] = ((!rtIsInf(A_tmp_0)) && (!rtIsNaN(A_tmp_0)));
      x[2] = rtIsInf(U_0);
      tmp_2 = rtIsNaN(U_0);
      U_0 = runtimedata_OutputMax[i + 30];
      A_tmp_0 = runtimedata_OutputMin[i + 30];
      icf[(int32_T)ic[3] - 1] = ((!rtIsInf(A_tmp_0)) && (!rtIsNaN(A_tmp_0)));
      icf[(int32_T)(ic[0] + 4.0) - 1] = ((!x[0]) && (!y));
      ic_0[0] = (int32_T)ic[0] - 1;
      ic_0[4] = (int32_T)(ic[0] + 4.0) - 1;
      icf[(int32_T)(ic[1] + 4.0) - 1] = ((!x[1]) && (!tmp_1));
      ic_0[1] = (int32_T)ic[1] - 1;
      ic_0[5] = (int32_T)(ic[1] + 4.0) - 1;
      icf[(int32_T)(ic[2] + 4.0) - 1] = ((!x[2]) && (!tmp_2));
      ic_0[2] = (int32_T)ic[2] - 1;
      ic_0[6] = (int32_T)(ic[2] + 4.0) - 1;
      icf[(int32_T)(ic[3] + 4.0) - 1] = ((!rtIsInf(U_0)) && (!rtIsNaN(U_0)));
      ic_0[3] = (int32_T)ic[3] - 1;
      ic_0[7] = (int32_T)(ic[3] + 4.0) - 1;
      for (A_tmp_tmp = 0; A_tmp_tmp < 8; A_tmp_tmp++) {
        icf_0[A_tmp_tmp] = icf[ic_0[A_tmp_tmp]];
      }

      if (Swingup_MPC_any(icf_0)) {
        for (A_tmp_tmp = 0; A_tmp_tmp < 16; A_tmp_tmp++) {
          A_1[A_tmp_tmp] = 0.0;
        }

        A_1[0] = 1.0;
        U_0 = X[i + 1];
        c[(int32_T)ic[0] - 1] = (runtimedata_OutputMin[i] - e) - U_0;
        A_1[5] = 1.0;
        A_tmp_0 = X[i + 12];
        c[(int32_T)ic[1] - 1] = (runtimedata_OutputMin[i + 10] - e) - A_tmp_0;
        A_1[10] = 1.0;
        A_tmp_1 = X[i + 23];
        c[(int32_T)ic[2] - 1] = (runtimedata_OutputMin[i + 20] - e) - A_tmp_1;
        A_1[15] = 1.0;
        A_tmp_2 = X[i + 34];
        c[(int32_T)ic[3] - 1] = (runtimedata_OutputMin[i + 30] - e) - A_tmp_2;
        c[(int32_T)(ic[0] + 4.0) - 1] = (U_0 - runtimedata_OutputMax[i]) - e;
        c[(int32_T)(ic[1] + 4.0) - 1] = (A_tmp_0 - runtimedata_OutputMax[i + 10])
          - e;
        c[(int32_T)(ic[2] + 4.0) - 1] = (A_tmp_1 - runtimedata_OutputMax[i + 20])
          - e;
        c[(int32_T)(ic[3] + 4.0) - 1] = (A_tmp_2 - runtimedata_OutputMax[i + 30])
          - e;
        for (A_tmp_tmp = 0; A_tmp_tmp <= 14; A_tmp_tmp += 2) {
          tmp_3 = _mm_loadu_pd(&A_1[A_tmp_tmp]);
          _mm_storeu_pd(&val[A_tmp_tmp], _mm_mul_pd(tmp_3, _mm_set1_pd(-1.0)));
        }

        for (A_tmp_tmp = 0; A_tmp_tmp < 4; A_tmp_tmp++) {
          varargout_2_tmp_tmp = A_tmp_tmp << 2;
          Swingup_MPC_B.b_Jx[(((int32_T)ic[0] + 80 * A_tmp_tmp) + 320 * i) - 1] =
            val[varargout_2_tmp_tmp];
          Swingup_MPC_B.b_Jx[(((int32_T)ic[1] + 80 * A_tmp_tmp) + 320 * i) - 1] =
            val[varargout_2_tmp_tmp + 1];
          Swingup_MPC_B.b_Jx[(((int32_T)ic[2] + 80 * A_tmp_tmp) + 320 * i) - 1] =
            val[varargout_2_tmp_tmp + 2];
          Swingup_MPC_B.b_Jx[(((int32_T)ic[3] + 80 * A_tmp_tmp) + 320 * i) - 1] =
            val[varargout_2_tmp_tmp + 3];
        }

        for (A_tmp_tmp = 0; A_tmp_tmp < 4; A_tmp_tmp++) {
          Swingup_MPC_B.b_Jx[(((int32_T)(ic[0] + 4.0) + 80 * A_tmp_tmp) + 320 *
                              i) - 1] = A_1[A_tmp_tmp << 2];
          Swingup_MPC_B.b_Jx[(((int32_T)(ic[1] + 4.0) + 80 * A_tmp_tmp) + 320 *
                              i) - 1] = A_1[(A_tmp_tmp << 2) + 1];
          Swingup_MPC_B.b_Jx[(((int32_T)(ic[2] + 4.0) + 80 * A_tmp_tmp) + 320 *
                              i) - 1] = A_1[(A_tmp_tmp << 2) + 2];
          Swingup_MPC_B.b_Jx[(((int32_T)(ic[3] + 4.0) + 80 * A_tmp_tmp) + 320 *
                              i) - 1] = A_1[(A_tmp_tmp << 2) + 3];
          Je[(int32_T)ic[A_tmp_tmp] - 1] = -1;
        }

        Je[(int32_T)(ic[0] + 4.0) - 1] = -1;
        Je[(int32_T)(ic[1] + 4.0) - 1] = -1;
        Je[(int32_T)(ic[2] + 4.0) - 1] = -1;
        Je[(int32_T)(ic[3] + 4.0) - 1] = -1;
      }

      ic[0] += 8.0;
      ic[1] += 8.0;
      ic[2] += 8.0;
      ic[3] += 8.0;
    }

    i = 0;
    for (A_tmp_tmp = 0; A_tmp_tmp < 80; A_tmp_tmp++) {
      if (icf[A_tmp_tmp]) {
        i++;
      }
    }

    varargout_2_tmp_tmp = i;
    i = 0;
    for (A_tmp_tmp = 0; A_tmp_tmp < 80; A_tmp_tmp++) {
      if (icf[A_tmp_tmp]) {
        b_data[i] = (int8_T)(A_tmp_tmp + 1);
        i++;
      }
    }

    for (A_tmp_tmp = 0; A_tmp_tmp < varargout_2_tmp_tmp; A_tmp_tmp++) {
      c_data[A_tmp_tmp] = c[b_data[A_tmp_tmp] - 1];
    }

    varargin_1_size_idx_1 = 1;
    if (varargout_2_tmp_tmp - 1 >= 0) {
      memcpy(&c[0], &c_data[0], (uint32_T)varargout_2_tmp_tmp * sizeof(real_T));
    }

    i = 0;
    for (A_tmp_tmp = 0; A_tmp_tmp < 80; A_tmp_tmp++) {
      if (icf[A_tmp_tmp]) {
        i++;
      }
    }

    d_size_idx_0 = i;
    i = 0;
    for (A_tmp_tmp = 0; A_tmp_tmp < 80; A_tmp_tmp++) {
      if (icf[A_tmp_tmp]) {
        d_data[i] = (int8_T)(A_tmp_tmp + 1);
        i++;
      }
    }

    if (d_size_idx_0 == 0) {
      b_varargin_1_size_idx_0 = 0;
      d_size_idx_0 = 0;
    } else {
      for (A_tmp_tmp = 0; A_tmp_tmp < 10; A_tmp_tmp++) {
        for (i = 0; i < 4; i++) {
          for (Jx_tmp = 0; Jx_tmp < d_size_idx_0; Jx_tmp++) {
            Swingup_MPC_B.b_Jx_data[(Jx_tmp + d_size_idx_0 * i) + (d_size_idx_0 <<
              2) * A_tmp_tmp] = Swingup_MPC_B.b_Jx[((80 * i + d_data[Jx_tmp]) +
              320 * A_tmp_tmp) - 1];
          }
        }
      }

      d[0] = (int8_T)d_size_idx_0;
      varargout_2_tmp = (int8_T)d_size_idx_0;
      for (A_tmp_tmp = 0; A_tmp_tmp < varargout_2_tmp; A_tmp_tmp++) {
        for (i = 0; i < 40; i++) {
          Swingup_MPC_B.b_Jx[i + 40 * A_tmp_tmp] = Swingup_MPC_B.b_Jx_data[d[0] *
            i + A_tmp_tmp];
        }
      }

      tmp_size_0[0] = d_size_idx_0;
      tmp_size_0[1] = 10;
      for (A_tmp_tmp = 0; A_tmp_tmp < 10; A_tmp_tmp++) {
        for (i = 0; i < d_size_idx_0; i++) {
          Swingup_MPC_B.tmp_data[i + d_size_idx_0 * A_tmp_tmp] = 0.0;
        }
      }

      Swingup_MPC_mtimes(Swingup_MPC_B.tmp_data, tmp_size_0, tmp_data, tmp_size);
      varargout_2_tmp = tmp_size[0];
      for (A_tmp_tmp = 0; A_tmp_tmp < varargout_2_tmp; A_tmp_tmp++) {
        varargin_2_data[3 * A_tmp_tmp] = tmp_data[A_tmp_tmp];
        varargin_2_data[1 + 3 * A_tmp_tmp] = tmp_data[A_tmp_tmp + tmp_size[0]];
        varargin_2_data[2 + 3 * A_tmp_tmp] = tmp_data[(tmp_size[0] << 1) +
          A_tmp_tmp];
      }

      d[0] = 40;
      if (tmp_size[0] != 0) {
        varargin_2[0] = 3;
      } else {
        varargin_2[0] = 0;
      }

      for (A_tmp_tmp = 0; A_tmp_tmp < d_size_idx_0; A_tmp_tmp++) {
        b_data[A_tmp_tmp] = Je[d_data[A_tmp_tmp] - 1];
      }

      tmp_0[0] = 1;
      b_varargin_1_size_idx_0 = varargin_2[0] + 41;
      varargout_2_tmp = (int8_T)d_size_idx_0;
      d_size_idx_0 = (int8_T)d_size_idx_0;
      for (A_tmp_tmp = 0; A_tmp_tmp < varargout_2_tmp; A_tmp_tmp++) {
        for (i = 0; i < 40; i++) {
          Swingup_MPC_B.b_varargin_1_data[i + b_varargin_1_size_idx_0 *
            A_tmp_tmp] = Swingup_MPC_B.b_Jx[d[0] * A_tmp_tmp + i];
        }
      }

      Jx_tmp = varargin_2[0];
      for (A_tmp_tmp = 0; A_tmp_tmp < varargout_2_tmp; A_tmp_tmp++) {
        for (i = 0; i < Jx_tmp; i++) {
          Swingup_MPC_B.b_varargin_1_data[(i + b_varargin_1_size_idx_0 *
            A_tmp_tmp) + 40] = varargin_2_data[varargin_2[0] * A_tmp_tmp + i];
        }
      }

      for (A_tmp_tmp = 0; A_tmp_tmp < varargout_2_tmp; A_tmp_tmp++) {
        Swingup_MPC_B.b_varargin_1_data[(varargin_2[0] + b_varargin_1_size_idx_0
          * A_tmp_tmp) + 40] = b_data[tmp_0[0] * A_tmp_tmp];
      }
    }
  }

  b_sizes_idx_1 = (int8_T)((varargout_2_tmp_tmp != 0) && (varargin_1_size_idx_1
    != 0));
  if ((b_sizes_idx_1 == 0) || ((varargout_2_tmp_tmp != 0) &&
       (varargin_1_size_idx_1 != 0))) {
    input_sizes_idx_0 = (int8_T)varargout_2_tmp_tmp;
  } else {
    input_sizes_idx_0 = 0;
  }

  varargout_1_size[0] = input_sizes_idx_0;
  varargout_1_size[1] = b_sizes_idx_1;
  varargout_2_tmp = b_sizes_idx_1;
  for (A_tmp_tmp = 0; A_tmp_tmp < varargout_2_tmp; A_tmp_tmp++) {
    if (input_sizes_idx_0 - 1 >= 0) {
      memcpy(&varargout_1_data[0], &c[0], (uint32_T)input_sizes_idx_0 * sizeof
             (real_T));
    }
  }

  if ((b_varargin_1_size_idx_0 != 0) && (d_size_idx_0 != 0)) {
    b_sizes_idx_1 = (int8_T)b_varargin_1_size_idx_0;
  } else {
    b_sizes_idx_1 = 0;
  }

  varargout_3_size[0] = b_sizes_idx_1;
  varargout_3_size[1] = (int8_T)d_size_idx_0;
  varargout_2_tmp = b_sizes_idx_1 * (int8_T)d_size_idx_0;
  if (varargout_2_tmp - 1 >= 0) {
    memcpy(&varargout_3_data[0], &Swingup_MPC_B.b_varargin_1_data[0], (uint32_T)
           varargout_2_tmp * sizeof(real_T));
  }

  for (A_tmp_tmp = 0; A_tmp_tmp < 3; A_tmp_tmp++) {
    for (i = 0; i < 40; i++) {
      varargout_2_tmp = 3 * i + A_tmp_tmp;
      Jmv_0[varargout_2_tmp] = 0.0;
      for (Jx_tmp = 0; Jx_tmp < 10; Jx_tmp++) {
        Jmv_0[varargout_2_tmp] += Jmv[40 * Jx_tmp + i] * (real_T)b_b[10 *
          A_tmp_tmp + Jx_tmp];
      }
    }
  }

  for (A_tmp_tmp = 0; A_tmp_tmp < 40; A_tmp_tmp++) {
    for (i = 0; i < 40; i++) {
      varargout_4[i + 44 * A_tmp_tmp] = Swingup_MPC_B.Jx[40 * i + A_tmp_tmp];
    }

    varargout_4[44 * A_tmp_tmp + 40] = Jmv_0[3 * A_tmp_tmp];
    varargout_4[44 * A_tmp_tmp + 41] = Jmv_0[3 * A_tmp_tmp + 1];
    varargout_4[44 * A_tmp_tmp + 42] = Jmv_0[3 * A_tmp_tmp + 2];
    varargout_4[44 * A_tmp_tmp + 43] = 0.0;
  }
}

static void Swingup_MPC_emxInit_real_T(emxArray_real_T_Swingup_MPC_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_real_T_Swingup_MPC_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_Swingup_MPC_T *)malloc(sizeof
    (emxArray_real_T_Swingup_MPC_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInitStruct_s_k1Ho7Q1nYjseRM5(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T
  *pStruct)
{
  pStruct->cIneq.size = 0;
  pStruct->cIneq_old.size = 0;
  pStruct->grad.size = 0;
  pStruct->grad_old.size = 0;
  pStruct->lambdasqp.size = 0;
  pStruct->lambdaStopTest.size = 0;
  pStruct->lambdaStopTestPrev.size = 0;
  pStruct->delta_x.size = 0;
  pStruct->socDirection.size = 0;
  pStruct->workingset_old.size = 0;
  Swingup_MPC_emxInit_real_T(&pStruct->JacCineqTrans_old, 2);
  Swingup_MPC_emxInit_real_T(&pStruct->JacCeqTrans_old, 2);
  pStruct->gradLag.size = 0;
  pStruct->delta_gradLag.size = 0;
  pStruct->xstar.size = 0;
  pStruct->lambda.size = 0;
  pStruct->searchDir.size = 0;
}

static void Swingu_emxEnsureCapacity_real_T(emxArray_real_T_Swingup_MPC_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_factoryConstruct(int32_T nVarMax, int32_T mConstrMax,
  int32_T mIneq, int32_T mNonlinIneq, s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *obj)
{
  int32_T i;
  obj->nVarMax = nVarMax;
  obj->mNonlinIneq = mNonlinIneq;
  obj->mNonlinEq = 40;
  obj->mIneq = mIneq;
  obj->mEq = 40;
  obj->iNonIneq0 = (mIneq - mNonlinIneq) + 1;
  obj->iNonEq0 = 1;
  obj->sqpFval = 0.0;
  obj->sqpFval_old = 0.0;
  obj->cIneq.size = mIneq;
  obj->cIneq_old.size = mIneq;
  obj->grad.size = nVarMax;
  obj->grad_old.size = nVarMax;
  obj->FunctionEvaluations = 0;
  obj->sqpIterations = 0;
  obj->sqpExitFlag = 0;
  obj->lambdasqp.size = mConstrMax;
  for (i = 0; i < mConstrMax; i++) {
    obj->lambdasqp.data[i] = 0.0;
  }

  obj->lambdaStopTest.size = mConstrMax;
  obj->lambdaStopTestPrev.size = mConstrMax;
  obj->steplength = 1.0;
  obj->delta_x.size = nVarMax;
  for (i = 0; i < nVarMax; i++) {
    obj->delta_x.data[i] = 0.0;
  }

  obj->socDirection.size = nVarMax;
  obj->workingset_old.size = mConstrMax;
  if (mNonlinIneq > 0) {
    i = obj->JacCineqTrans_old->size[0] * obj->JacCineqTrans_old->size[1];
    obj->JacCineqTrans_old->size[0] = nVarMax;
    obj->JacCineqTrans_old->size[1] = mNonlinIneq;
    Swingu_emxEnsureCapacity_real_T(obj->JacCineqTrans_old, i);
  } else {
    obj->JacCineqTrans_old->size[0] = 0;
    obj->JacCineqTrans_old->size[1] = 0;
  }

  i = obj->JacCeqTrans_old->size[0] * obj->JacCeqTrans_old->size[1];
  obj->JacCeqTrans_old->size[0] = nVarMax;
  obj->JacCeqTrans_old->size[1] = 40;
  Swingu_emxEnsureCapacity_real_T(obj->JacCeqTrans_old, i);
  obj->gradLag.size = nVarMax;
  obj->delta_gradLag.size = nVarMax;
  obj->xstar.size = nVarMax;
  obj->fstar = 0.0;
  obj->firstorderopt = 0.0;
  obj->lambda.size = mConstrMax;
  for (i = 0; i < mConstrMax; i++) {
    obj->lambda.data[i] = 0.0;
  }

  obj->state = 0;
  obj->maxConstr = 0.0;
  obj->iterations = 0;
  obj->searchDir.size = nVarMax;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_M_factoryConstruct_h3jt(int32_T MaxVars, int32_T
  *obj_grad_size, int32_T *obj_Hx_size, boolean_T *obj_hasLinear, int32_T
  *obj_nvar, int32_T *obj_maxVar, real_T *obj_beta, real_T *obj_rho, int32_T
  *obj_objtype, int32_T *obj_prev_objtype, int32_T *obj_prev_nvar, boolean_T
  *obj_prev_hasLinear, real_T *obj_gammaScalar)
{
  *obj_grad_size = MaxVars;
  *obj_Hx_size = MaxVars - 1;
  *obj_hasLinear = false;
  *obj_nvar = 0;
  *obj_maxVar = MaxVars;
  *obj_beta = 0.0;
  *obj_rho = 0.0;
  *obj_objtype = 3;
  *obj_prev_objtype = 3;
  *obj_prev_nvar = 0;
  *obj_prev_hasLinear = false;
  *obj_gammaScalar = 0.0;
}

static void emxInitStruct_s_j0Ykcy5K3TT7uFO(s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *pStruct)
{
  Swingup_MPC_emxInit_real_T(&pStruct->workspace_double, 2);
  pStruct->workspace_int.size = 0;
  pStruct->workspace_sort.size = 0;
}

static void emxInitStruct_s_pBvMsf7fBJa4zdf(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *pStruct)
{
  Swingup_MPC_emxInit_real_T(&pStruct->Aineq, 1);
  pStruct->bineq.size = 0;
  Swingup_MPC_emxInit_real_T(&pStruct->Aeq, 1);
  pStruct->lb.size = 0;
  pStruct->ub.size = 0;
  pStruct->indexLB.size = 0;
  pStruct->indexUB.size = 0;
  pStruct->indexFixed.size = 0;
  Swingup_MPC_emxInit_real_T(&pStruct->ATwset, 1);
  pStruct->bwset.size = 0;
  pStruct->maxConstrWorkspace.size = 0;
  pStruct->isActiveConstr.size = 0;
  pStruct->Wid.size = 0;
  pStruct->Wlocalidx.size = 0;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup__factoryConstruct_h3jty(int32_T mIneqMax, int32_T nVarMax,
  int32_T mConstrMax, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj)
{
  int32_T i;
  obj->mConstr = 0;
  obj->mConstrOrig = 0;
  obj->mConstrMax = mConstrMax;
  obj->nVar = 44;
  obj->nVarOrig = 44;
  obj->nVarMax = nVarMax;
  obj->ldA = nVarMax;
  i = obj->Aineq->size[0];
  obj->Aineq->size[0] = mIneqMax * nVarMax;
  Swingu_emxEnsureCapacity_real_T(obj->Aineq, i);
  obj->bineq.size = mIneqMax;
  i = obj->Aeq->size[0];
  obj->Aeq->size[0] = 40 * nVarMax;
  Swingu_emxEnsureCapacity_real_T(obj->Aeq, i);
  obj->lb.size = nVarMax;
  obj->ub.size = nVarMax;
  obj->indexLB.size = nVarMax;
  obj->indexUB.size = nVarMax;
  obj->indexFixed.size = nVarMax;
  obj->mEqRemoved = 0;
  i = obj->ATwset->size[0];
  obj->ATwset->size[0] = nVarMax * mConstrMax;
  Swingu_emxEnsureCapacity_real_T(obj->ATwset, i);
  obj->bwset.size = mConstrMax;
  obj->nActiveConstr = 0;
  obj->maxConstrWorkspace.size = mConstrMax;
  for (i = 0; i < 5; i++) {
    obj->sizes[i] = 0;
    obj->sizesNormal[i] = 0;
    obj->sizesPhaseOne[i] = 0;
    obj->sizesRegularized[i] = 0;
    obj->sizesRegPhaseOne[i] = 0;
  }

  for (i = 0; i < 6; i++) {
    obj->isActiveIdx[i] = 0;
    obj->isActiveIdxNormal[i] = 0;
    obj->isActiveIdxPhaseOne[i] = 0;
    obj->isActiveIdxRegularized[i] = 0;
    obj->isActiveIdxRegPhaseOne[i] = 0;
  }

  obj->isActiveConstr.size = mConstrMax;
  obj->Wid.size = mConstrMax;
  obj->Wlocalidx.size = mConstrMax;
  for (i = 0; i < 5; i++) {
    obj->nWConstr[i] = 0;
  }

  obj->probType = 3;
  obj->SLACK0 = 1.0E-5;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static int32_T Swingup_MP_checkVectorNonFinite(int32_T N, const real_T vec_data[],
  int32_T iv0)
{
  real_T allFinite_tmp;
  int32_T idx_current;
  int32_T idx_end;
  int32_T status;
  boolean_T allFinite;
  status = 1;
  allFinite = true;
  idx_current = iv0 - 2;
  idx_end = (iv0 + N) - 1;
  while (allFinite && (idx_current + 2 <= idx_end)) {
    allFinite_tmp = vec_data[idx_current + 1];
    allFinite = ((!rtIsInf(allFinite_tmp)) && (!rtIsNaN(allFinite_tmp)));
    idx_current++;
  }

  if (!allFinite) {
    if (rtIsNaN(vec_data[idx_current])) {
      status = -3;
    } else if (vec_data[idx_current] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }

  return status;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static int32_T Swingup__checkVectorNonFinite_b(const real_T vec[40])
{
  real_T allFinite_tmp;
  int32_T idx_current;
  int32_T status;
  boolean_T allFinite;
  status = 1;
  allFinite = true;
  idx_current = -1;
  while (allFinite && (idx_current + 2 <= 40)) {
    allFinite_tmp = vec[idx_current + 1];
    allFinite = ((!rtIsInf(allFinite_tmp)) && (!rtIsNaN(allFinite_tmp)));
    idx_current++;
  }

  if (!allFinite) {
    if (rtIsNaN(vec[idx_current])) {
      status = -3;
    } else if (vec[idx_current] < 0.0) {
      status = -1;
    } else {
      status = -2;
    }
  }

  return status;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void evalObjAndConstrAndDerivatives(int32_T
  obj_next_next_next_next_next_va, const s_GSKgPzH92oA7AAcXEvWMnG_Swin_T
  *obj_next_next_next_next_next_ne, const s_OOgWGXXQYnSElkPXvuQxeH_Swin_T
  *obj_next_next_next_next_next__0, const real_T x[44], real_T
  grad_workspace_data[], real_T Cineq_workspace_data[], int32_T ineq0, real_T
  Ceq_workspace[40], emxArray_real_T_Swingup_MPC_T *JacIneqTrans_workspace,
  int32_T iJI_col, int32_T ldJI, emxArray_real_T_Swingup_MPC_T
  *JacEqTrans_workspace, int32_T ldJE, real_T *fval, int32_T *status)
{
  __m128d tmp;
  real_T a__3_data[80];
  real_T X[44];
  real_T b_X[44];
  real_T gfX[40];
  real_T U[11];
  real_T gfU[10];
  real_T gfX_0[4];
  real_T ix[4];
  real_T f[3];
  real_T duk;
  real_T e;
  real_T fs;
  real_T obj_next_next_next_next_next__1;
  real_T obj_next_next_next_next_next__2;
  real_T obj_next_next_next_next_next__3;
  real_T wtUerr;
  real_T wtYerr_tmp;
  int32_T col_end;
  int32_T i;
  int32_T idx_mat;
  int32_T iu;
  boolean_T allFinite;
  static const int8_T f_0[30] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
    0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1 };

  static const int8_T g[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

  int32_T a__3_size[2];
  int32_T a__4_size[2];
  Swingup_MPC_znlmpc_getXUe(x, obj_next_next_next_next_next__0->runtimedata.x, X,
    U, &e);
  for (i = 0; i < 40; i++) {
    gfX[i] = 0.0;
  }

  for (i = 0; i < 10; i++) {
    gfU[i] = 0.0;
  }

  fs = 0.0;
  ix[0] = 1.0;
  ix[1] = 2.0;
  ix[2] = 3.0;
  ix[3] = 4.0;
  for (iu = 0; iu < 11; iu++) {
    i = iu << 2;
    b_X[i] = X[iu];
    b_X[i + 1] = X[iu + 11];
    b_X[i + 2] = X[iu + 22];
    b_X[i + 3] = X[iu + 33];
  }

  for (i = 0; i < 10; i++) {
    iu = (i + 1) << 2;
    duk = (b_X[iu] - obj_next_next_next_next_next__0->runtimedata.ref[i]) *
      obj_next_next_next_next_next__0->runtimedata.OutputWeights[i];
    wtUerr = duk * duk;
    obj_next_next_next_next_next__1 =
      obj_next_next_next_next_next__0->runtimedata.OutputWeights[i] * duk;
    wtYerr_tmp = obj_next_next_next_next_next__0->runtimedata.OutputWeights[i +
      10];
    duk = (b_X[iu + 1] - obj_next_next_next_next_next__0->runtimedata.ref[i + 10])
      * wtYerr_tmp;
    wtUerr += duk * duk;
    obj_next_next_next_next_next__2 = wtYerr_tmp * duk;
    wtYerr_tmp = obj_next_next_next_next_next__0->runtimedata.OutputWeights[i +
      20];
    duk = (b_X[iu + 2] - obj_next_next_next_next_next__0->runtimedata.ref[i + 20])
      * wtYerr_tmp;
    wtUerr += duk * duk;
    obj_next_next_next_next_next__3 = wtYerr_tmp * duk;
    wtYerr_tmp = obj_next_next_next_next_next__0->runtimedata.OutputWeights[i +
      30];
    duk = (b_X[iu + 3] - obj_next_next_next_next_next__0->runtimedata.ref[i + 30])
      * wtYerr_tmp;
    wtYerr_tmp *= duk;
    fs += duk * duk + wtUerr;
    for (iu = 0; iu < 4; iu++) {
      gfX_0[iu] = ((((real_T)g[iu + 4] * obj_next_next_next_next_next__2 +
                     (real_T)g[iu] * obj_next_next_next_next_next__1) + (real_T)
                    g[iu + 8] * obj_next_next_next_next_next__3) + (real_T)g[iu
                   + 12] * wtYerr_tmp) + gfX[(int32_T)ix[iu] - 1];
    }

    gfX[(int32_T)ix[0] - 1] = gfX_0[0];
    ix[0] += 4.0;
    gfX[(int32_T)ix[1] - 1] = gfX_0[1];
    ix[1] += 4.0;
    gfX[(int32_T)ix[2] - 1] = gfX_0[2];
    ix[2] += 4.0;
    gfX[(int32_T)ix[3] - 1] = gfX_0[3];
    ix[3] += 4.0;
    if (i + 1 == 1) {
      duk = U[i] - obj_next_next_next_next_next__0->runtimedata.lastMV;
    } else {
      duk = U[i] - U[i - 1];
    }

    wtUerr = 0.0 * U[i];
    gfU[i] += 0.0 * wtUerr;
    duk *= 0.1;
    fs = (wtUerr * wtUerr + fs) + duk * duk;
    wtUerr = 0.1 * duk;
    gfU[i] += wtUerr;
    if (i + 1 > 1) {
      gfU[i - 1] -= wtUerr;
    }
  }

  *fval = 100000.0 * e * e + fs;
  for (iu = 0; iu < 3; iu++) {
    fs = 0.0;
    for (i = 0; i < 10; i++) {
      fs += (real_T)f_0[3 * i + iu] * (2.0 * gfU[i]);
    }

    f[iu] = fs;
  }

  for (iu = 0; iu <= 38; iu += 2) {
    tmp = _mm_loadu_pd(&gfX[iu]);
    _mm_storeu_pd(&X[iu], _mm_mul_pd(_mm_set1_pd(2.0), tmp));
  }

  X[40] = f[0];
  X[41] = f[1];
  X[42] = f[2];
  X[43] = 200000.0 * e;
  memcpy(&grad_workspace_data[0], &X[0], 44U * sizeof(real_T));
  if (rtIsInf(*fval) || rtIsNaN(*fval)) {
    if (rtIsNaN(*fval)) {
      *status = -3;
    } else if (*fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  } else {
    allFinite = true;
    i = -1;
    while (allFinite && (i + 2 <= 44)) {
      e = grad_workspace_data[i + 1];
      allFinite = ((!rtIsInf(e)) && (!rtIsNaN(e)));
      i++;
    }

    if (!allFinite) {
      if (rtIsNaN(grad_workspace_data[i])) {
        *status = -3;
      } else if (grad_workspace_data[i] < 0.0) {
        *status = -1;
      } else {
        *status = -2;
      }
    } else {
      if (obj_next_next_next_next_next_va > 0) {
        Swingup_eML_blk_kernel_anonFcn2(obj_next_next_next_next_next_ne->x,
          obj_next_next_next_next_next_ne->OutputMin,
          obj_next_next_next_next_next_ne->OutputMax, x, a__3_data, a__3_size,
          gfX, Swingup_MPC_B.a__4_data, a__4_size, Swingup_MPC_B.JacEqTrans_tmp);
        iu = (uint8_T)obj_next_next_next_next_next_va;
        for (i = 0; i < iu; i++) {
          Cineq_workspace_data[(ineq0 + i) - 1] = a__3_data[i];
        }

        memcpy(&Ceq_workspace[0], &gfX[0], 40U * sizeof(real_T));
        col_end = a__4_size[0];
        for (i = 0; i < col_end; i++) {
          idx_mat = a__4_size[1];
          for (iu = 0; iu < idx_mat; iu++) {
            JacIneqTrans_workspace->data[i + ldJI * ((iJI_col + iu) - 1)] =
              Swingup_MPC_B.a__4_data[a__4_size[0] * iu + i];
          }
        }

        for (i = 0; i < 44; i++) {
          for (iu = 0; iu < 40; iu++) {
            JacEqTrans_workspace->data[i + ldJE * iu] =
              Swingup_MPC_B.JacEqTrans_tmp[44 * iu + i];
          }
        }
      } else {
        Swingup_eML_blk_kernel_anonFcn2(obj_next_next_next_next_next_ne->x,
          obj_next_next_next_next_next_ne->OutputMin,
          obj_next_next_next_next_next_ne->OutputMax, x, a__3_data, a__3_size,
          gfX, Swingup_MPC_B.a__4_data, a__4_size, Swingup_MPC_B.JacEqTrans_tmp);
        memcpy(&Ceq_workspace[0], &gfX[0], 40U * sizeof(real_T));
        for (i = 0; i < 44; i++) {
          for (iu = 0; iu < 40; iu++) {
            JacEqTrans_workspace->data[i + ldJE * iu] =
              Swingup_MPC_B.JacEqTrans_tmp[44 * iu + i];
          }
        }
      }

      *status = Swingup_MP_checkVectorNonFinite(obj_next_next_next_next_next_va,
        Cineq_workspace_data, ineq0);
      if (*status == 1) {
        *status = Swingup__checkVectorNonFinite_b(Ceq_workspace);
        if (*status == 1) {
          allFinite = true;
          i = -1;
          iu = iJI_col;
          col_end = (iJI_col + obj_next_next_next_next_next_va) - 1;
          while (allFinite && (iu <= col_end)) {
            i = -1;
            while (allFinite && (i + 2 <= 44)) {
              idx_mat = ((iu - 1) * ldJI + i) + 1;
              allFinite = ((!rtIsInf(JacIneqTrans_workspace->data[idx_mat])) &&
                           (!rtIsNaN(JacIneqTrans_workspace->data[idx_mat])));
              i++;
            }

            iu++;
          }

          if (!allFinite) {
            idx_mat = (iu - 2) * ldJI + i;
            if (rtIsNaN(JacIneqTrans_workspace->data[idx_mat])) {
              *status = -3;
            } else if (JacIneqTrans_workspace->data[idx_mat] < 0.0) {
              *status = -1;
            } else {
              *status = -2;
            }
          } else {
            i = -1;
            iu = -1;
            while (allFinite && (iu + 2 <= 40)) {
              i = -1;
              while (allFinite && (i + 2 <= 44)) {
                col_end = ((iu + 1) * ldJE + i) + 1;
                allFinite = ((!rtIsInf(JacEqTrans_workspace->data[col_end])) &&
                             (!rtIsNaN(JacEqTrans_workspace->data[col_end])));
                i++;
              }

              iu++;
            }

            if (!allFinite) {
              col_end = ldJE * iu + i;
              if (rtIsNaN(JacEqTrans_workspace->data[col_end])) {
                *status = -3;
              } else if (JacEqTrans_workspace->data[col_end] < 0.0) {
                *status = -1;
              } else {
                *status = -2;
              }
            }
          }
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_modifyOverheadPhaseOne_(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj)
{
  int32_T d;
  int32_T idx;
  int32_T idxEq;
  idxEq = (uint8_T)obj->sizes[0];
  for (idx = 0; idx < idxEq; idx++) {
    obj->ATwset->data[(obj->nVar + obj->ldA * idx) - 1] = 0.0;
  }

  for (idx = 0; idx < 40; idx++) {
    idxEq = (obj->ldA * idx + obj->nVar) - 1;
    obj->Aeq->data[idxEq] = 0.0;
    obj->ATwset->data[idxEq + obj->ldA * (obj->isActiveIdx[1] - 1)] = 0.0;
  }

  idxEq = (uint8_T)obj->sizes[2];
  for (idx = 0; idx < idxEq; idx++) {
    obj->Aineq->data[(obj->nVar + obj->ldA * idx) - 1] = -1.0;
  }

  obj->indexLB.data[obj->sizes[3] - 1] = obj->nVar;
  obj->lb.data[obj->nVar - 1] = 1.0E-5;
  idxEq = obj->isActiveIdx[2];
  d = obj->nActiveConstr;
  for (idx = idxEq; idx <= d; idx++) {
    obj->ATwset->data[(obj->nVar + obj->ldA * (idx - 1)) - 1] = -1.0;
  }

  if (obj->nWConstr[4] > 0) {
    idxEq = (uint8_T)(obj->sizesNormal[4] + 1);
    for (idx = 0; idx < idxEq; idx++) {
      obj->isActiveConstr.data[(obj->isActiveIdx[4] + idx) - 1] = false;
    }
  }

  obj->isActiveConstr.data[obj->isActiveIdx[4] - 2] = false;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_setProblemType(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T PROBLEM_TYPE)
{
  int32_T c;
  int32_T colOffsetATw;
  int32_T colOffsetAineq;
  int32_T d;
  int32_T idx_col;
  int32_T k;
  int32_T mIneq;
  int32_T offsetEq1;
  int32_T offsetEq2;
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = 44;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      mIneq = (uint8_T)obj->sizesNormal[4];
      for (colOffsetATw = 0; colOffsetATw < mIneq; colOffsetATw++) {
        obj->isActiveConstr.data[(obj->isActiveIdxNormal[4] + colOffsetATw) - 1]
          = obj->isActiveConstr.data[(obj->isActiveIdx[4] + colOffsetATw) - 1];
      }
    }

    for (c = 0; c < 5; c++) {
      obj->sizes[c] = obj->sizesNormal[c];
    }

    for (c = 0; c < 6; c++) {
      obj->isActiveIdx[c] = obj->isActiveIdxNormal[c];
    }
    break;

   case 1:
    obj->nVar = 45;
    obj->mConstr = obj->mConstrOrig + 1;
    for (c = 0; c < 5; c++) {
      obj->sizes[c] = obj->sizesPhaseOne[c];
    }

    for (c = 0; c < 6; c++) {
      obj->isActiveIdx[c] = obj->isActiveIdxPhaseOne[c];
    }

    Swingup_modifyOverheadPhaseOne_(obj);
    break;

   case 2:
    obj->nVar = obj->nVarMax - 1;
    obj->mConstr = obj->mConstrMax - 1;
    for (c = 0; c < 5; c++) {
      obj->sizes[c] = obj->sizesRegularized[c];
    }

    if (obj->probType != 4) {
      mIneq = obj->sizes[2] + 45;
      offsetEq1 = obj->sizes[2] + 44;
      offsetEq2 = obj->sizes[2] + 84;
      c = (uint8_T)obj->sizes[0];
      for (idx_col = 0; idx_col < c; idx_col++) {
        colOffsetATw = obj->ldA * idx_col;
        d = obj->nVar;
        for (colOffsetAineq = 45; colOffsetAineq <= d; colOffsetAineq++) {
          obj->ATwset->data[(colOffsetAineq + colOffsetATw) - 1] = 0.0;
        }
      }

      idx_col = (uint8_T)obj->sizes[2];
      for (colOffsetATw = 0; colOffsetATw < idx_col; colOffsetATw++) {
        colOffsetAineq = obj->ldA * colOffsetATw - 1;
        for (c = 45; c <= colOffsetATw + 44; c++) {
          obj->Aineq->data[c + colOffsetAineq] = 0.0;
        }

        obj->Aineq->data[(colOffsetATw + colOffsetAineq) + 45] = -1.0;
        d = obj->nVar;
        for (c = colOffsetATw + 46; c <= d; c++) {
          obj->Aineq->data[c + colOffsetAineq] = 0.0;
        }
      }

      for (idx_col = 0; idx_col < 40; idx_col++) {
        colOffsetAineq = obj->ldA * idx_col - 1;
        colOffsetATw = (obj->isActiveIdx[1] - 1) * obj->ldA + colOffsetAineq;
        for (c = 45; c <= offsetEq1; c++) {
          obj->Aeq->data[c + colOffsetAineq] = 0.0;
          obj->ATwset->data[c + colOffsetATw] = 0.0;
        }

        d = (mIneq + idx_col) - 1;
        for (c = mIneq; c <= d; c++) {
          obj->Aeq->data[c + colOffsetAineq] = 0.0;
          obj->ATwset->data[c + colOffsetATw] = 0.0;
        }

        c = mIneq + idx_col;
        obj->Aeq->data[c + colOffsetAineq] = -1.0;
        obj->ATwset->data[c + colOffsetATw] = -1.0;
        for (c = d + 2; c <= offsetEq2; c++) {
          obj->Aeq->data[c + colOffsetAineq] = 0.0;
          obj->ATwset->data[c + colOffsetATw] = 0.0;
        }

        for (c = mIneq + 40; c <= d + 40; c++) {
          obj->Aeq->data[c + colOffsetAineq] = 0.0;
          obj->ATwset->data[c + colOffsetATw] = 0.0;
        }

        c = mIneq + idx_col;
        obj->Aeq->data[(c + colOffsetAineq) + 40] = 1.0;
        obj->ATwset->data[(c + colOffsetATw) + 40] = 1.0;
        k = obj->nVar;
        for (c = d + 42; c <= k; c++) {
          obj->Aeq->data[c + colOffsetAineq] = 0.0;
          obj->ATwset->data[c + colOffsetATw] = 0.0;
        }
      }

      mIneq = 44;
      offsetEq1 = obj->sizesNormal[3] + 1;
      offsetEq2 = obj->sizesRegularized[3];
      for (colOffsetATw = offsetEq1; colOffsetATw <= offsetEq2; colOffsetATw++)
      {
        mIneq++;
        obj->indexLB.data[colOffsetATw - 1] = mIneq;
      }

      if (obj->nWConstr[4] > 0) {
        mIneq = (uint8_T)obj->sizesRegularized[4];
        for (colOffsetATw = 0; colOffsetATw < mIneq; colOffsetATw++) {
          obj->isActiveConstr.data[obj->isActiveIdxRegularized[4] + colOffsetATw]
            = obj->isActiveConstr.data[(obj->isActiveIdx[4] + colOffsetATw) - 1];
        }
      }

      mIneq = obj->isActiveIdx[4];
      offsetEq1 = obj->isActiveIdxRegularized[4] - 1;
      if (mIneq <= offsetEq1) {
        memset(&obj->isActiveConstr.data[mIneq + -1], 0, (uint32_T)((offsetEq1 -
                 mIneq) + 1) * sizeof(boolean_T));
      }

      mIneq = obj->sizes[2] + 124;
      for (colOffsetATw = 45; colOffsetATw <= mIneq; colOffsetATw++) {
        obj->lb.data[colOffsetATw - 1] = 0.0;
      }

      offsetEq1 = obj->isActiveIdx[2];
      offsetEq2 = obj->nActiveConstr;
      for (mIneq = offsetEq1; mIneq <= offsetEq2; mIneq++) {
        colOffsetATw = (mIneq - 1) * obj->ldA - 1;
        if (obj->Wid.data[mIneq - 1] == 3) {
          colOffsetAineq = obj->Wlocalidx.data[mIneq - 1] + 43;
          for (idx_col = 45; idx_col <= colOffsetAineq; idx_col++) {
            obj->ATwset->data[idx_col + colOffsetATw] = 0.0;
          }

          obj->ATwset->data[(obj->Wlocalidx.data[mIneq - 1] + colOffsetATw) + 44]
            = -1.0;
          colOffsetAineq = obj->Wlocalidx.data[mIneq - 1] + 45;
          c = obj->nVar;
          for (idx_col = colOffsetAineq; idx_col <= c; idx_col++) {
            obj->ATwset->data[idx_col + colOffsetATw] = 0.0;
          }
        } else {
          colOffsetAineq = obj->nVar;
          for (idx_col = 45; idx_col <= colOffsetAineq; idx_col++) {
            obj->ATwset->data[idx_col + colOffsetATw] = 0.0;
          }
        }
      }
    }

    for (c = 0; c < 6; c++) {
      obj->isActiveIdx[c] = obj->isActiveIdxRegularized[c];
    }
    break;

   default:
    obj->nVar = obj->nVarMax;
    obj->mConstr = obj->mConstrMax;
    for (c = 0; c < 5; c++) {
      obj->sizes[c] = obj->sizesRegPhaseOne[c];
    }

    for (c = 0; c < 6; c++) {
      obj->isActiveIdx[c] = obj->isActiveIdxRegPhaseOne[c];
    }

    Swingup_modifyOverheadPhaseOne_(obj);
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_initActiveSet(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj)
{
  int32_T colOffsetATw;
  int32_T f;
  int32_T iATw0;
  int32_T iAeq0;
  int32_T idx;
  int32_T idxFillStart;
  Swingup_MPC_setProblemType(obj, 3);
  idxFillStart = obj->isActiveIdx[2];
  if (idxFillStart <= obj->mConstrMax) {
    memset(&obj->isActiveConstr.data[idxFillStart + -1], 0, (uint32_T)
           ((obj->mConstrMax - idxFillStart) + 1) * sizeof(boolean_T));
  }

  obj->nWConstr[0] = obj->sizes[0];
  obj->nWConstr[1] = 40;
  obj->nWConstr[2] = 0;
  obj->nWConstr[3] = 0;
  obj->nWConstr[4] = 0;
  obj->nActiveConstr = obj->nWConstr[0] + 40;
  idxFillStart = (uint8_T)obj->sizes[0];
  for (idx = 0; idx < idxFillStart; idx++) {
    obj->Wid.data[idx] = 1;
    obj->Wlocalidx.data[idx] = idx + 1;
    obj->isActiveConstr.data[idx] = true;
    colOffsetATw = obj->ldA * idx;
    iATw0 = (uint8_T)(obj->indexFixed.data[idx] - 1);
    for (iAeq0 = 0; iAeq0 < iATw0; iAeq0++) {
      obj->ATwset->data[iAeq0 + colOffsetATw] = 0.0;
    }

    obj->ATwset->data[(obj->indexFixed.data[idx] + colOffsetATw) - 1] = 1.0;
    iATw0 = obj->indexFixed.data[idx] + 1;
    f = obj->nVar;
    for (iAeq0 = iATw0; iAeq0 <= f; iAeq0++) {
      obj->ATwset->data[(iAeq0 + colOffsetATw) - 1] = 0.0;
    }

    obj->bwset.data[idx] = obj->ub.data[obj->indexFixed.data[idx] - 1];
  }

  for (idx = 0; idx < 40; idx++) {
    colOffsetATw = obj->sizes[0] + idx;
    obj->Wid.data[colOffsetATw] = 2;
    obj->Wlocalidx.data[colOffsetATw] = idx + 1;
    obj->isActiveConstr.data[colOffsetATw] = true;
    iAeq0 = obj->ldA * idx;
    iATw0 = obj->ldA * colOffsetATw;
    f = obj->nVar - 1;
    for (idxFillStart = 0; idxFillStart <= f; idxFillStart++) {
      obj->ATwset->data[iATw0 + idxFillStart] = obj->Aeq->data[iAeq0 +
        idxFillStart];
    }

    obj->bwset.data[colOffsetATw] = obj->beq[idx];
  }
}

static void emxInitStruct_s_qjgm7GzdZt1MoSN(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T
  *pStruct)
{
  Swingup_MPC_emxInit_real_T(&pStruct->QR, 2);
  Swingup_MPC_emxInit_real_T(&pStruct->Q, 2);
  pStruct->jpvt.size = 0;
  pStruct->tau.size = 0;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_factoryConstruct_h3(int32_T maxRows, int32_T maxCols,
  int32_T *obj_ldq, emxArray_real_T_Swingup_MPC_T *obj_QR,
  emxArray_real_T_Swingup_MPC_T *obj_Q, int32_T obj_jpvt_data[], int32_T
  *obj_jpvt_size, int32_T *obj_mrows, int32_T *obj_ncols, int32_T *obj_tau_size,
  int32_T *obj_minRowCol, boolean_T *obj_usedPivoting)
{
  int32_T i;
  int32_T loop_ub;
  i = obj_QR->size[0] * obj_QR->size[1];
  obj_QR->size[0] = maxRows;
  obj_QR->size[1] = maxCols;
  Swingu_emxEnsureCapacity_real_T(obj_QR, i);
  i = obj_Q->size[0] * obj_Q->size[1];
  obj_Q->size[0] = maxRows;
  obj_Q->size[1] = maxRows;
  Swingu_emxEnsureCapacity_real_T(obj_Q, i);
  loop_ub = maxRows * maxRows;
  for (i = 0; i < loop_ub; i++) {
    obj_Q->data[i] = 0.0;
  }

  *obj_jpvt_size = maxCols;
  if (maxCols - 1 >= 0) {
    memset(&obj_jpvt_data[0], 0, (uint32_T)maxCols * sizeof(int32_T));
  }

  if (maxRows <= maxCols) {
    *obj_tau_size = maxRows;
  } else {
    *obj_tau_size = maxCols;
  }

  *obj_ldq = maxRows;
  *obj_mrows = 0;
  *obj_ncols = 0;
  *obj_minRowCol = 0;
  *obj_usedPivoting = false;
}

static void emxInitStruct_s_xgaiQX2t1f8Iwfq(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *pStruct)
{
  Swingup_MPC_emxInit_real_T(&pStruct->FMat, 2);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MP_factoryConstruct_h3j(int32_T MaxDims,
  emxArray_real_T_Swingup_MPC_T *obj_FMat, int32_T *obj_ldm, int32_T *obj_ndims,
  int32_T *obj_info, real_T *obj_scaleFactor, boolean_T *obj_ConvexCheck, real_T
  *obj_regTol_, real_T *obj_workspace_, real_T *obj_workspace2_)
{
  int32_T tmp;
  tmp = obj_FMat->size[0] * obj_FMat->size[1];
  obj_FMat->size[0] = MaxDims;
  obj_FMat->size[1] = MaxDims;
  Swingu_emxEnsureCapacity_real_T(obj_FMat, tmp);
  *obj_ldm = MaxDims;
  *obj_ndims = 0;
  *obj_info = 0;
  *obj_scaleFactor = 0.0;
  *obj_ConvexCheck = true;
  *obj_regTol_ = (rtInf);
  *obj_workspace_ = (rtInf);
  *obj_workspace2_ = (rtInf);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_computeGradLag(real_T workspace_data[], int32_T ldA,
  int32_T nVar, const real_T grad_data[], int32_T mIneq, const
  emxArray_real_T_Swingup_MPC_T *AineqTrans, const emxArray_real_T_Swingup_MPC_T
  *AeqTrans, const int32_T finiteFixed_data[], int32_T mFixed, const int32_T
  finiteLB_data[], int32_T mLB, const int32_T finiteUB_data[], int32_T mUB,
  const real_T lambda_data[])
{
  int32_T b;
  int32_T f;
  int32_T g;
  int32_T iL0;
  int32_T ix;
  int32_T tmp;
  memcpy(&workspace_data[0], &grad_data[0], (uint8_T)nVar * sizeof(real_T));
  b = (uint8_T)mFixed;
  for (iL0 = 0; iL0 < b; iL0++) {
    ix = finiteFixed_data[iL0];
    workspace_data[ix - 1] += lambda_data[iL0];
  }

  ix = mFixed;
  f = ldA * 39 + 1;
  for (iL0 = 1; ldA < 0 ? iL0 >= f : iL0 <= f; iL0 += ldA) {
    g = (iL0 + nVar) - 1;
    for (b = iL0; b <= g; b++) {
      tmp = b - iL0;
      workspace_data[tmp] += AeqTrans->data[b - 1] * lambda_data[ix];
    }

    ix++;
  }

  if (mIneq != 0) {
    ix = mFixed + 40;
    f = (mIneq - 1) * ldA + 1;
    for (iL0 = 1; ldA < 0 ? iL0 >= f : iL0 <= f; iL0 += ldA) {
      g = (iL0 + nVar) - 1;
      for (b = iL0; b <= g; b++) {
        workspace_data[b - iL0] += AineqTrans->data[b - 1] * lambda_data[ix];
      }

      ix++;
    }
  }

  iL0 = (mFixed + mIneq) + 40;
  ix = (uint16_T)mLB;
  for (b = 0; b < ix; b++) {
    f = finiteLB_data[b];
    workspace_data[f - 1] -= lambda_data[iL0 + b];
  }

  iL0 = (uint16_T)mLB - 1 < 0 ? iL0 : iL0 + (uint16_T)mLB;
  ix = (uint8_T)mUB;
  for (b = 0; b < ix; b++) {
    f = finiteUB_data[b];
    workspace_data[f - 1] += lambda_data[iL0 + b];
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingup__computePrimalFeasError(const real_T x[44], int32_T
  mLinIneq, int32_T mNonlinIneq, const real_T cIneq_data[], const real_T cEq[40],
  const int32_T finiteLB_data[], int32_T mLB, const real_T lb[44], const int32_T
  finiteUB_data[], int32_T mUB)
{
  real_T feasError;
  real_T u1;
  int32_T finiteLB;
  int32_T idx;
  int32_T mIneq;
  feasError = 0.0;
  mIneq = mNonlinIneq + mLinIneq;
  for (idx = 0; idx < 40; idx++) {
    u1 = fabs(cEq[idx]);
    if ((!(feasError >= u1)) && (!rtIsNaN(u1))) {
      feasError = u1;
    }
  }

  for (idx = 0; idx < mIneq; idx++) {
    u1 = cIneq_data[idx];
    if ((!(feasError >= u1)) && (!rtIsNaN(u1))) {
      feasError = u1;
    }
  }

  mIneq = (uint16_T)mLB;
  for (idx = 0; idx < mIneq; idx++) {
    finiteLB = finiteLB_data[idx];
    u1 = lb[finiteLB - 1] - x[finiteLB - 1];
    if ((!(feasError >= u1)) && (!rtIsNaN(u1))) {
      feasError = u1;
    }
  }

  mIneq = (uint8_T)mUB;
  for (idx = 0; idx < mIneq; idx++) {
    u1 = x[finiteUB_data[idx] - 1] - (rtInf);
    if ((!(feasError >= u1)) && (!rtIsNaN(u1))) {
      feasError = u1;
    }
  }

  return feasError;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MP_computeDualFeasError(int32_T nVar, const real_T
  gradLag_data[], boolean_T *gradOK, real_T *val)
{
  real_T u1;
  int32_T idx;
  boolean_T exitg1;
  *gradOK = true;
  *val = 0.0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= (uint8_T)nVar - 1)) {
    *gradOK = ((!rtIsInf(gradLag_data[idx])) && (!rtIsNaN(gradLag_data[idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      u1 = fabs(gradLag_data[idx]);
      if ((!(*val >= u1)) && (!rtIsNaN(u1))) {
        *val = u1;
      }

      idx++;
    }
  }
}

static void Swingup_MPC_emxFree_real_T(emxArray_real_T_Swingup_MPC_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_Swingup_MPC_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_Swingup_MPC_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_saveJacobian(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *obj,
  int32_T nVar, int32_T mIneq, const emxArray_real_T_Swingup_MPC_T
  *JacCineqTrans, int32_T ineqCol0, const emxArray_real_T_Swingup_MPC_T
  *JacCeqTrans, int32_T ldJ)
{
  emxArray_real_T_Swingup_MPC_T *y;
  int32_T b;
  int32_T iCol;
  int32_T iCol_old;
  int32_T idx_col;
  int32_T k;
  int32_T loop_ub;
  iCol = (ineqCol0 - 1) * ldJ;
  iCol_old = 0;
  b = mIneq - ineqCol0;
  Swingup_MPC_emxInit_real_T(&y, 2);
  for (idx_col = 0; idx_col <= b; idx_col++) {
    k = y->size[0] * y->size[1];
    y->size[0] = obj->JacCineqTrans_old->size[0];
    y->size[1] = obj->JacCineqTrans_old->size[1];
    Swingu_emxEnsureCapacity_real_T(y, k);
    loop_ub = obj->JacCineqTrans_old->size[0] * obj->JacCineqTrans_old->size[1];
    for (k = 0; k < loop_ub; k++) {
      y->data[k] = obj->JacCineqTrans_old->data[k];
    }

    loop_ub = (uint8_T)nVar;
    for (k = 0; k < loop_ub; k++) {
      y->data[iCol_old + k] = JacCineqTrans->data[iCol + k];
    }

    k = obj->JacCineqTrans_old->size[0] * obj->JacCineqTrans_old->size[1];
    obj->JacCineqTrans_old->size[0] = y->size[0];
    obj->JacCineqTrans_old->size[1] = y->size[1];
    Swingu_emxEnsureCapacity_real_T(obj->JacCineqTrans_old, k);
    loop_ub = y->size[0] * y->size[1];
    for (k = 0; k < loop_ub; k++) {
      obj->JacCineqTrans_old->data[k] = y->data[k];
    }

    iCol += ldJ;
    iCol_old += ldJ;
  }

  Swingup_MPC_emxFree_real_T(&y);
  iCol = 0;
  iCol_old = 0;
  b = (uint8_T)nVar;
  for (idx_col = 0; idx_col < 40; idx_col++) {
    for (k = 0; k < b; k++) {
      obj->JacCeqTrans_old->data[iCol_old + k] = JacCeqTrans->data[iCol + k];
    }

    iCol += ldJ;
    iCol_old += ldJ;
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingup_MPC_computeComplError(const int32_T
  *fscales_lineq_constraint_size, const int32_T *fscales_cineq_constraint_size,
  const real_T xCurrent[44], int32_T mIneq, const real_T cIneq_data[], const
  int32_T finiteLB_data[], int32_T mLB, const real_T lb[44], const int32_T
  finiteUB_data[], int32_T mUB, const real_T lambda_data[], int32_T iL0)
{
  real_T lbDelta;
  real_T lbLambda;
  real_T lbLambda_tmp;
  real_T nlpComplError;
  real_T u0;
  int32_T b_idx;
  int32_T finiteLB;
  int32_T iLineq0;
  int32_T idx;
  int32_T mLinIneq;
  nlpComplError = 0.0;
  if ((mIneq + mLB) + mUB > 0) {
    iLineq0 = *fscales_lineq_constraint_size;
    for (idx = 0; idx < iLineq0; idx++) {
      lbDelta = cIneq_data[idx];
      u0 = fabs(lbDelta);
      lbLambda_tmp = lambda_data[(iL0 + idx) - 1];
      lbLambda = lbLambda_tmp;
      if ((u0 <= lbLambda_tmp) || rtIsNaN(lbLambda_tmp)) {
        lbLambda = u0;
      }

      u0 = fabs(lbLambda_tmp * lbDelta);
      if ((u0 <= lbLambda) || rtIsNaN(lbLambda)) {
        lbLambda = u0;
      }

      if ((!(nlpComplError >= lbLambda)) && (!rtIsNaN(lbLambda))) {
        nlpComplError = lbLambda;
      }
    }

    iLineq0 = (iL0 + *fscales_lineq_constraint_size) - 1;
    idx = *fscales_cineq_constraint_size;
    for (b_idx = 0; b_idx < idx; b_idx++) {
      u0 = fabs(cIneq_data[*fscales_lineq_constraint_size + b_idx]);
      lbLambda_tmp = lambda_data[iLineq0 + b_idx];
      lbLambda = lbLambda_tmp;
      if ((u0 <= lbLambda_tmp) || rtIsNaN(lbLambda_tmp)) {
        lbLambda = u0;
      }

      u0 = fabs(cIneq_data[*fscales_lineq_constraint_size + b_idx] *
                lbLambda_tmp);
      if ((u0 <= lbLambda) || rtIsNaN(lbLambda)) {
        lbLambda = u0;
      }

      if ((!(nlpComplError >= lbLambda)) && (!rtIsNaN(lbLambda))) {
        nlpComplError = lbLambda;
      }
    }

    iLineq0 = (iL0 + mIneq) - 1;
    mLinIneq = iLineq0 + mLB;
    idx = (uint16_T)mLB;
    for (b_idx = 0; b_idx < idx; b_idx++) {
      finiteLB = finiteLB_data[b_idx];
      lbDelta = xCurrent[finiteLB - 1] - lb[finiteLB - 1];
      lbLambda = lambda_data[iLineq0 + b_idx];
      u0 = fabs(lbDelta);
      if ((!(u0 <= lbLambda)) && (!rtIsNaN(lbLambda))) {
        u0 = lbLambda;
      }

      lbDelta = fabs(lbDelta * lbLambda);
      if ((lbDelta <= u0) || rtIsNaN(u0)) {
        u0 = lbDelta;
      }

      if ((!(nlpComplError >= u0)) && (!rtIsNaN(u0))) {
        nlpComplError = u0;
      }
    }

    iLineq0 = (uint8_T)mUB;
    for (idx = 0; idx < iLineq0; idx++) {
      lbDelta = lambda_data[mLinIneq + idx];
      u0 = (rtInf) - xCurrent[finiteUB_data[idx] - 1];
      if ((u0 <= lbDelta) || rtIsNaN(lbDelta)) {
        lbLambda = u0;
      } else {
        lbLambda = lbDelta;
      }

      u0 = fabs(u0 * lbDelta);
      if ((u0 <= lbLambda) || rtIsNaN(lbLambda)) {
        lbLambda = u0;
      }

      if ((!(nlpComplError >= lbLambda)) && (!rtIsNaN(lbLambda))) {
        nlpComplError = lbLambda;
      }
    }
  }

  return nlpComplError;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_computeGradLag_b(emxArray_real_T_Swingup_MPC_T
  *workspace, int32_T ldA, int32_T nVar, const real_T grad_data[], int32_T mIneq,
  const emxArray_real_T_Swingup_MPC_T *AineqTrans, const
  emxArray_real_T_Swingup_MPC_T *AeqTrans, const int32_T finiteFixed_data[],
  int32_T mFixed, const int32_T finiteLB_data[], int32_T mLB, const int32_T
  finiteUB_data[], int32_T mUB, const real_T lambda_data[])
{
  int32_T f;
  int32_T g;
  int32_T i;
  int32_T iL0;
  int32_T ix;
  int32_T tmp;
  memcpy(&workspace->data[0], &grad_data[0], (uint8_T)nVar * sizeof(real_T));
  i = (uint8_T)mFixed;
  for (iL0 = 0; iL0 < i; iL0++) {
    ix = finiteFixed_data[iL0];
    workspace->data[ix - 1] += lambda_data[iL0];
  }

  ix = mFixed;
  f = ldA * 39 + 1;
  for (iL0 = 1; ldA < 0 ? iL0 >= f : iL0 <= f; iL0 += ldA) {
    g = (iL0 + nVar) - 1;
    for (i = iL0; i <= g; i++) {
      tmp = i - iL0;
      workspace->data[tmp] += AeqTrans->data[i - 1] * lambda_data[ix];
    }

    ix++;
  }

  if (mIneq != 0) {
    ix = mFixed + 40;
    f = (mIneq - 1) * ldA + 1;
    for (iL0 = 1; ldA < 0 ? iL0 >= f : iL0 <= f; iL0 += ldA) {
      g = (iL0 + nVar) - 1;
      for (i = iL0; i <= g; i++) {
        workspace->data[i - iL0] += AineqTrans->data[i - 1] * lambda_data[ix];
      }

      ix++;
    }
  }

  iL0 = (mFixed + mIneq) + 40;
  ix = (uint16_T)mLB;
  for (i = 0; i < ix; i++) {
    f = finiteLB_data[i];
    workspace->data[f - 1] -= lambda_data[iL0 + i];
  }

  iL0 = (uint16_T)mLB - 1 < 0 ? iL0 : iL0 + (uint16_T)mLB;
  ix = (uint8_T)mUB;
  for (i = 0; i < ix; i++) {
    f = finiteUB_data[i];
    workspace->data[f - 1] += lambda_data[iL0 + i];
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup__computeDualFeasError_e(int32_T nVar, const
  emxArray_real_T_Swingup_MPC_T *gradLag, boolean_T *gradOK, real_T *val)
{
  real_T u1;
  int32_T idx;
  boolean_T exitg1;
  *gradOK = true;
  *val = 0.0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= (uint8_T)nVar - 1)) {
    *gradOK = ((!rtIsInf(gradLag->data[idx])) && (!rtIsNaN(gradLag->data[idx])));
    if (!*gradOK) {
      exitg1 = true;
    } else {
      u1 = fabs(gradLag->data[idx]);
      if ((!(*val >= u1)) && (!rtIsNaN(u1))) {
        *val = u1;
      }

      idx++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingu_updateWorkingSetForNewQP(const real_T xk[44],
  s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *WorkingSet, int32_T mIneq, int32_T
  mNonlinIneq, const real_T cIneq_data[], const real_T cEq[40], int32_T mLB,
  const real_T lb[44], int32_T mUB, int32_T mFixed)
{
  int32_T g;
  int32_T i;
  int32_T iEq0;
  int32_T idx;
  int32_T iw0;
  int32_T ix0;
  int32_T nVar;
  nVar = WorkingSet->nVar;
  iw0 = WorkingSet->ldA * mFixed;
  iEq0 = 0;
  for (idx = 0; idx < 40; idx++) {
    WorkingSet->beq[idx] = -cEq[idx];
    WorkingSet->bwset.data[mFixed + idx] = WorkingSet->beq[idx];
    for (i = 0; i < nVar; i++) {
      WorkingSet->ATwset->data[iw0 + i] = WorkingSet->Aeq->data[iEq0 + i];
    }

    iw0 += WorkingSet->ldA;
    iEq0 += WorkingSet->ldA;
  }

  i = (uint8_T)mIneq;
  iw0 = ((uint8_T)mIneq / 2) << 1;
  iEq0 = iw0 - 2;
  for (idx = 0; idx <= iEq0; idx += 2) {
    _mm_storeu_pd(&WorkingSet->bineq.data[idx], _mm_mul_pd(_mm_loadu_pd
      (&cIneq_data[idx]), _mm_set1_pd(-1.0)));
  }

  for (idx = iw0; idx < i; idx++) {
    WorkingSet->bineq.data[idx] = -cIneq_data[idx];
  }

  i = (uint16_T)mLB;
  for (idx = 0; idx < i; idx++) {
    WorkingSet->lb.data[WorkingSet->indexLB.data[idx] - 1] = -lb
      [WorkingSet->indexLB.data[idx] - 1] + xk[WorkingSet->indexLB.data[idx] - 1];
  }

  i = (uint8_T)mUB;
  for (idx = 0; idx < i; idx++) {
    WorkingSet->ub.data[WorkingSet->indexUB.data[idx] - 1] = (rtInf) -
      xk[WorkingSet->indexUB.data[idx] - 1];
  }

  i = (uint8_T)mFixed;
  for (idx = 0; idx < i; idx++) {
    WorkingSet->ub.data[WorkingSet->indexFixed.data[idx] - 1] = (rtInf) -
      xk[WorkingSet->indexFixed.data[idx] - 1];
    WorkingSet->bwset.data[idx] = (rtInf) - xk[WorkingSet->indexFixed.data[idx]
      - 1];
  }

  if (WorkingSet->nActiveConstr > mFixed + 40) {
    iw0 = WorkingSet->nActiveConstr;
    for (idx = mFixed + 41; idx <= iw0; idx++) {
      switch (WorkingSet->Wid.data[idx - 1]) {
       case 4:
        WorkingSet->bwset.data[idx - 1] = WorkingSet->lb.data
          [WorkingSet->indexLB.data[WorkingSet->Wlocalidx.data[idx - 1] - 1] - 1];
        break;

       case 5:
        WorkingSet->bwset.data[idx - 1] = WorkingSet->ub.data
          [WorkingSet->indexUB.data[WorkingSet->Wlocalidx.data[idx - 1] - 1] - 1];
        break;

       default:
        WorkingSet->bwset.data[idx - 1] = WorkingSet->bineq.data
          [WorkingSet->Wlocalidx.data[idx - 1] - 1];
        if ((mNonlinIneq > 0) && (WorkingSet->Wlocalidx.data[idx - 1] >=
             mNonlinIneq)) {
          iEq0 = (idx - 1) * WorkingSet->ldA;
          ix0 = (WorkingSet->Wlocalidx.data[idx - 1] - 1) * WorkingSet->ldA;
          g = (uint8_T)nVar;
          for (i = 0; i < g; i++) {
            WorkingSet->ATwset->data[iEq0 + i] = WorkingSet->Aineq->data[ix0 + i];
          }
        }
        break;
      }
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xswap(int32_T n, emxArray_real_T_Swingup_MPC_T *x,
  int32_T ix0, int32_T iy0)
{
  real_T temp;
  int32_T k;
  int32_T temp_tmp;
  int32_T tmp;
  for (k = 0; k < n; k++) {
    temp_tmp = (ix0 + k) - 1;
    temp = x->data[temp_tmp];
    tmp = (iy0 + k) - 1;
    x->data[temp_tmp] = x->data[tmp];
    x->data[tmp] = temp;
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingup_MPC_xnrm2(int32_T n, const emxArray_real_T_Swingup_MPC_T
  *x, int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x->data[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x->data[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingup_MPC_xzlarfg(int32_T n, real_T *alpha1,
  emxArray_real_T_Swingup_MPC_T *x, int32_T ix0)
{
  __m128d tmp;
  real_T a;
  real_T tau;
  real_T xnorm;
  int32_T c;
  int32_T knt;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
  tau = 0.0;
  if (n > 0) {
    xnorm = Swingup_MPC_xnrm2(n - 1, x, ix0);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        do {
          knt++;
          scalarLB = (ix0 + n) - 2;
          vectorUB = ((((scalarLB - ix0) + 1) / 2) << 1) + ix0;
          vectorUB_tmp = vectorUB - 2;
          for (c = ix0; c <= vectorUB_tmp; c += 2) {
            tmp = _mm_loadu_pd(&x->data[c - 1]);
            _mm_storeu_pd(&x->data[c - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (9.9792015476736E+291)));
          }

          for (c = vectorUB; c <= scalarLB; c++) {
            x->data[c - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        xnorm = rt_hypotd_snf(*alpha1, Swingup_MPC_xnrm2(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        for (c = ix0; c <= vectorUB_tmp; c += 2) {
          tmp = _mm_loadu_pd(&x->data[c - 1]);
          _mm_storeu_pd(&x->data[c - 1], _mm_mul_pd(tmp, _mm_set1_pd(a)));
        }

        for (c = vectorUB; c <= scalarLB; c++) {
          x->data[c - 1] *= a;
        }

        for (c = 0; c < knt; c++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        c = (ix0 + n) - 2;
        scalarLB = ((((c - ix0) + 1) / 2) << 1) + ix0;
        vectorUB = scalarLB - 2;
        for (knt = ix0; knt <= vectorUB; knt += 2) {
          tmp = _mm_loadu_pd(&x->data[knt - 1]);
          _mm_storeu_pd(&x->data[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(a)));
        }

        for (knt = scalarLB; knt <= c; knt++) {
          x->data[knt - 1] *= a;
        }

        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T ia0, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *x, int32_T ix0, real_T y_data[])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T iy;
  int32_T iyend;
  if (n != 0) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y_data[b_iy] = 0.0;
    }

    iy = 0;
    b = (n - 1) * lda + ia0;
    for (b_iy = ia0; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      c = 0.0;
      d = (b_iy + m) - 1;
      for (iyend = b_iy; iyend <= d; iyend++) {
        c += x->data[((ix0 + iyend) - b_iy) - 1] * A->data[iyend - 1];
      }

      y_data[iy] += c;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgerc(int32_T m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y_data[], emxArray_real_T_Swingup_MPC_T *A, int32_T ia0, int32_T
  lda)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  if (!(alpha1 == 0.0)) {
    jA = ia0;
    for (j = 0; j < n; j++) {
      temp = y_data[j];
      if (temp != 0.0) {
        temp *= alpha1;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A->data[ijA - 1] += A->data[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += lda;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
  emxArray_real_T_Swingup_MPC_T *C, int32_T ic0, int32_T ldc, real_T work_data[])
{
  int32_T coltop;
  int32_T exitg1;
  int32_T ia;
  int32_T lastc;
  int32_T lastv;
  boolean_T exitg2;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C->data[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      coltop = (lastc - 1) * ldc + ic0;
      ia = coltop;
      do {
        exitg1 = 0;
        if (ia <= (coltop + lastv) - 1) {
          if (C->data[ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    Swingup_MPC_xgemv(lastv, lastc, C, ic0, ldc, C, iv0, work_data);
    Swingup_MPC_xgerc(lastv, lastc, -tau, iv0, work_data, C, ic0, ldc);
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_qrf(emxArray_real_T_Swingup_MPC_T *A, int32_T m, int32_T
  n, int32_T nfxd, real_T tau_data[])
{
  real_T work_data[449];
  real_T b_atmp;
  int32_T i;
  int32_T ii;
  int32_T lda;
  int32_T loop_ub;
  int32_T mmi;
  lda = A->size[0];
  loop_ub = A->size[1];
  for (i = 0; i < loop_ub; i++) {
    work_data[i] = 0.0;
  }

  loop_ub = (uint8_T)nfxd;
  for (i = 0; i < loop_ub; i++) {
    ii = i * lda + i;
    mmi = m - i;
    if (i + 1 < m) {
      b_atmp = A->data[ii];
      tau_data[i] = Swingup_MPC_xzlarfg(mmi, &b_atmp, A, ii + 2);
      A->data[ii] = b_atmp;
    } else {
      tau_data[i] = 0.0;
    }

    if (i + 1 < n) {
      b_atmp = A->data[ii];
      A->data[ii] = 1.0;
      Swingup_MPC_xzlarf(mmi, (n - i) - 1, ii + 1, tau_data[i], A, (ii + lda) +
                         1, lda, work_data);
      A->data[ii] = b_atmp;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_qrpf(emxArray_real_T_Swingup_MPC_T *A, int32_T m,
  int32_T n, int32_T nfxd, real_T tau_data[], int32_T jpvt_data[])
{
  real_T vn1_data[449];
  real_T vn2_data[449];
  real_T work_data[449];
  real_T s;
  real_T smax;
  real_T tmp;
  int32_T ii;
  int32_T itemp;
  int32_T j;
  int32_T ma;
  int32_T minmn;
  int32_T mmi;
  int32_T nmi;
  int32_T pvt;
  ma = A->size[0];
  if (m <= n) {
    minmn = m;
  } else {
    minmn = n;
  }

  pvt = A->size[1];
  for (j = 0; j < pvt; j++) {
    work_data[j] = 0.0;
  }

  pvt = A->size[1];
  for (j = 0; j < pvt; j++) {
    vn1_data[j] = 0.0;
  }

  pvt = A->size[1];
  for (j = 0; j < pvt; j++) {
    vn2_data[j] = 0.0;
  }

  for (j = nfxd + 1; j <= n; j++) {
    vn1_data[j - 1] = Swingup_MPC_xnrm2(m - nfxd, A, ((j - 1) * ma + nfxd) + 1);
    vn2_data[j - 1] = vn1_data[j - 1];
  }

  for (j = nfxd + 1; j <= minmn; j++) {
    ii = ((j - 1) * ma + j) - 1;
    nmi = n - j;
    mmi = m - j;
    if (nmi + 1 < 1) {
      itemp = -2;
    } else {
      itemp = -1;
      if (nmi + 1 > 1) {
        smax = fabs(vn1_data[j - 1]);
        for (pvt = 2; pvt <= nmi + 1; pvt++) {
          s = fabs(vn1_data[(j + pvt) - 2]);
          if (s > smax) {
            itemp = pvt - 2;
            smax = s;
          }
        }
      }
    }

    pvt = j + itemp;
    if (pvt + 1 != j) {
      Swingup_MPC_xswap(m, A, pvt * ma + 1, (j - 1) * ma + 1);
      itemp = jpvt_data[pvt];
      jpvt_data[pvt] = jpvt_data[j - 1];
      jpvt_data[j - 1] = itemp;
      vn1_data[pvt] = vn1_data[j - 1];
      vn2_data[pvt] = vn2_data[j - 1];
    }

    if (j < m) {
      smax = A->data[ii];
      tau_data[j - 1] = Swingup_MPC_xzlarfg(mmi + 1, &smax, A, ii + 2);
      A->data[ii] = smax;
    } else {
      tau_data[j - 1] = 0.0;
    }

    if (j < n) {
      smax = A->data[ii];
      A->data[ii] = 1.0;
      Swingup_MPC_xzlarf(mmi + 1, nmi, ii + 1, tau_data[j - 1], A, (ii + ma) + 1,
                         ma, work_data);
      A->data[ii] = smax;
    }

    for (pvt = j + 1; pvt <= n; pvt++) {
      ii = (pvt - 1) * ma + j;
      tmp = vn1_data[pvt - 1];
      if (tmp != 0.0) {
        smax = fabs(A->data[ii - 1]) / tmp;
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        s = tmp / vn2_data[pvt - 1];
        s = s * s * smax;
        if (s <= 1.4901161193847656E-8) {
          if (j < m) {
            vn1_data[pvt - 1] = Swingup_MPC_xnrm2(mmi, A, ii + 1);
            vn2_data[pvt - 1] = vn1_data[pvt - 1];
          } else {
            vn1_data[pvt - 1] = 0.0;
            vn2_data[pvt - 1] = 0.0;
          }
        } else {
          vn1_data[pvt - 1] = tmp * sqrt(smax);
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgeqp3(emxArray_real_T_Swingup_MPC_T *A, int32_T m,
  int32_T n, int32_T jpvt_data[], real_T tau_data[], int32_T *tau_size)
{
  int32_T ma;
  int32_T minmana;
  int32_T minmn;
  int32_T nfxd;
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  ma = A->size[0];
  if (A->size[0] <= A->size[1]) {
    minmana = A->size[0];
  } else {
    minmana = A->size[1];
  }

  if (m <= n) {
    minmn = m;
  } else {
    minmn = n;
  }

  *tau_size = minmana;
  for (nfxd = 0; nfxd < minmana; nfxd++) {
    tau_data[nfxd] = 0.0;
  }

  if (minmn < 1) {
    nfxd = (n / 4) << 2;
    ma = nfxd - 4;
    for (minmana = 0; minmana <= ma; minmana += 4) {
      _mm_storeu_si128((__m128i *)&jpvt_data[minmana], _mm_add_epi32
                       (_mm_add_epi32(_mm_set1_epi32(minmana), _mm_loadu_si128((
        const __m128i *)&offsets[0])), _mm_set1_epi32(1)));
    }

    for (minmana = nfxd; minmana < n; minmana++) {
      jpvt_data[minmana] = minmana + 1;
    }
  } else {
    nfxd = -1;
    for (minmana = 0; minmana < n; minmana++) {
      if (jpvt_data[minmana] != 0) {
        nfxd++;
        if (minmana + 1 != nfxd + 1) {
          Swingup_MPC_xswap(m, A, minmana * ma + 1, nfxd * ma + 1);
          jpvt_data[minmana] = jpvt_data[nfxd];
          jpvt_data[nfxd] = minmana + 1;
        } else {
          jpvt_data[minmana] = minmana + 1;
        }
      } else {
        jpvt_data[minmana] = minmana + 1;
      }
    }

    if (nfxd + 1 <= minmn) {
      nfxd++;
    } else {
      nfxd = minmn;
    }

    Swingup_MPC_qrf(A, m, n, nfxd, tau_data);
    if (nfxd < minmn) {
      Swingup_MPC_qrpf(A, m, n, nfxd, tau_data, jpvt_data);
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_factorQRE(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T mrows, int32_T ncols, int32_T ldA)
{
  int32_T b;
  int32_T idx;
  int32_T ix0;
  int32_T iy0;
  int32_T k;
  b = (uint8_T)mrows;
  for (idx = 0; idx < ncols; idx++) {
    ix0 = ldA * idx;
    iy0 = obj->ldq * idx;
    for (k = 0; k < b; k++) {
      obj->QR->data[iy0 + k] = A->data[ix0 + k];
    }
  }

  obj->usedPivoting = true;
  obj->mrows = mrows;
  obj->ncols = ncols;
  if (mrows <= ncols) {
    obj->minRowCol = mrows;
  } else {
    obj->minRowCol = ncols;
  }

  Swingup_MPC_xgeqp3(obj->QR, mrows, ncols, obj->jpvt.data, obj->tau.data,
                     &obj->tau.size);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xorgqr(int32_T m, int32_T n, int32_T k,
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T tau_data[])
{
  __m128d tmp;
  real_T work_data[449];
  int32_T d;
  int32_T i;
  int32_T ia;
  int32_T itau;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T vectorUB;
  if (n >= 1) {
    for (itau = k; itau < n; itau++) {
      ia = itau * lda;
      for (i = 0; i < m; i++) {
        A->data[ia + i] = 0.0;
      }

      A->data[ia + itau] = 1.0;
    }

    itau = k - 1;
    loop_ub = (int16_T)A->size[1];
    for (i = 0; i < loop_ub; i++) {
      work_data[i] = 0.0;
    }

    for (i = k; i >= 1; i--) {
      ia = (i - 1) * lda + i;
      if (i < n) {
        A->data[ia - 1] = 1.0;
        Swingup_MPC_xzlarf((m - i) + 1, n - i, ia, tau_data[itau], A, ia + lda,
                           lda, work_data);
      }

      if (i < m) {
        d = (ia + m) - i;
        scalarLB = ((((d - ia) / 2) << 1) + ia) + 1;
        vectorUB = scalarLB - 2;
        for (loop_ub = ia + 1; loop_ub <= vectorUB; loop_ub += 2) {
          tmp = _mm_loadu_pd(&A->data[loop_ub - 1]);
          _mm_storeu_pd(&A->data[loop_ub - 1], _mm_mul_pd(tmp, _mm_set1_pd
            (-tau_data[itau])));
        }

        for (loop_ub = scalarLB; loop_ub <= d; loop_ub++) {
          A->data[loop_ub - 1] *= -tau_data[itau];
        }
      }

      A->data[ia - 1] = 1.0 - tau_data[itau];
      d = (uint8_T)(i - 1);
      for (loop_ub = 0; loop_ub < d; loop_ub++) {
        A->data[(ia - loop_ub) - 2] = 0.0;
      }

      itau--;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv_n(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T x_data[],
  emxArray_real_T_Swingup_MPC_T *y)
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T iy;
  int32_T iyend;
  if (m != 0) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y->data[b_iy] = 0.0;
    }

    iy = 0;
    b = (n - 1) * lda + 1;
    for (b_iy = 1; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      c = 0.0;
      d = (b_iy + m) - 1;
      for (iyend = b_iy; iyend <= d; iyend++) {
        c += A->data[iyend - 1] * x_data[iyend - b_iy];
      }

      y->data[iy] += c;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_sortLambdaQP(real_T lambda_data[], int32_T
  WorkingSet_nActiveConstr, const int32_T WorkingSet_sizes[5], const int32_T
  WorkingSet_isActiveIdx[6], const int32_T WorkingSet_Wid_data[], const int32_T
  WorkingSet_Wlocalidx_data[], emxArray_real_T_Swingup_MPC_T *workspace)
{
  int32_T currentMplier;
  int32_T idxOffset;
  int32_T mAll;
  if (WorkingSet_nActiveConstr != 0) {
    mAll = (((WorkingSet_sizes[0] + WorkingSet_sizes[3]) + WorkingSet_sizes[4])
            + WorkingSet_sizes[2]) + 39;
    if ((uint16_T)(mAll + 1) - 1 >= 0) {
      memcpy(&workspace->data[0], &lambda_data[0], (uint16_T)(mAll + 1) * sizeof
             (real_T));
    }

    for (currentMplier = 0; currentMplier <= mAll; currentMplier++) {
      lambda_data[currentMplier] = 0.0;
    }

    currentMplier = 0;
    mAll = 0;
    while ((mAll + 1 <= WorkingSet_nActiveConstr) && (WorkingSet_Wid_data[mAll] <=
            2)) {
      if (WorkingSet_Wid_data[mAll] == 1) {
        idxOffset = 1;
      } else {
        idxOffset = WorkingSet_isActiveIdx[1];
      }

      lambda_data[(idxOffset + WorkingSet_Wlocalidx_data[mAll]) - 2] =
        workspace->data[currentMplier];
      currentMplier++;
      mAll++;
    }

    while (mAll + 1 <= WorkingSet_nActiveConstr) {
      switch (WorkingSet_Wid_data[mAll]) {
       case 3:
        idxOffset = WorkingSet_isActiveIdx[2];
        break;

       case 4:
        idxOffset = WorkingSet_isActiveIdx[3];
        break;

       default:
        idxOffset = WorkingSet_isActiveIdx[4];
        break;
      }

      lambda_data[(idxOffset + WorkingSet_Wlocalidx_data[mAll]) - 2] =
        workspace->data[currentMplier];
      currentMplier++;
      mAll++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_test_exit(s7RdrPWkr8UPAUyTdDJkLaG_Swing_T *Flags,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, sG8JZ69axY52WWR6RKyApQC_Swing_T
  *MeritFunction, const int32_T *fscales_lineq_constraint_size, const int32_T
  *fscales_cineq_constraint_size, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *WorkingSet,
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T
  *QRManager, const real_T lb[44])
{
  __m128d tmp_1;
  real_T nlpComplErrorTmp;
  real_T s;
  real_T smax;
  real_T tmp;
  real_T tmp_0;
  int32_T b_ix;
  int32_T iQR_diag;
  int32_T idx_max;
  int32_T idx_max_tmp;
  int32_T ix;
  int32_T mFixed;
  int32_T nVar;
  int32_T rankR;
  boolean_T dxTooSmall;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T isFeasible;
  nVar = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  idx_max_tmp = (uint16_T)((((WorkingSet->sizes[0] + WorkingSet->sizes[2]) +
    WorkingSet->sizes[3]) + WorkingSet->sizes[4]) + 40);
  if (idx_max_tmp - 1 >= 0) {
    memcpy(&TrialState->lambdaStopTest.data[0], &TrialState->lambdasqp.data[0],
           (uint32_T)idx_max_tmp * sizeof(real_T));
  }

  Swingup_MPC_computeGradLag(TrialState->gradLag.data, WorkingSet->ldA,
    WorkingSet->nVar, TrialState->grad.data, WorkingSet->sizes[2],
    WorkingSet->Aineq, WorkingSet->Aeq, WorkingSet->indexFixed.data,
    WorkingSet->sizes[0], WorkingSet->indexLB.data, WorkingSet->sizes[3],
    WorkingSet->indexUB.data, WorkingSet->sizes[4],
    TrialState->lambdaStopTest.data);
  if (WorkingSet->nVar < 1) {
    idx_max = 0;
  } else {
    idx_max = 1;
    if (WorkingSet->nVar > 1) {
      smax = fabs(TrialState->grad.data[0]);
      for (iQR_diag = 2; iQR_diag <= nVar; iQR_diag++) {
        s = fabs(TrialState->grad.data[iQR_diag - 1]);
        if (s > smax) {
          idx_max = iQR_diag;
          smax = s;
        }
      }
    }
  }

  smax = fabs(TrialState->grad.data[idx_max - 1]);
  if ((smax <= 1.0) || rtIsNaN(smax)) {
    smax = 1.0;
  }

  if (rtIsInf(smax)) {
    smax = 1.0;
  }

  MeritFunction->nlpPrimalFeasError = Swingup__computePrimalFeasError
    (TrialState->xstarsqp, WorkingSet->sizes[2] - TrialState->mNonlinIneq,
     TrialState->mNonlinIneq, TrialState->cIneq.data, TrialState->cEq,
     WorkingSet->indexLB.data, WorkingSet->sizes[3], lb,
     WorkingSet->indexUB.data, WorkingSet->sizes[4]);
  if (TrialState->sqpIterations == 0) {
    if ((MeritFunction->nlpPrimalFeasError <= 1.0) || rtIsNaN
        (MeritFunction->nlpPrimalFeasError)) {
      MeritFunction->feasRelativeFactor = 1.0;
    } else {
      MeritFunction->feasRelativeFactor = MeritFunction->nlpPrimalFeasError;
    }
  }

  isFeasible = (MeritFunction->nlpPrimalFeasError <= 1.0E-6 *
                MeritFunction->feasRelativeFactor);
  Swingup_MP_computeDualFeasError(WorkingSet->nVar, TrialState->gradLag.data,
    &Flags->gradOK, &MeritFunction->nlpDualFeasError);
  if (!Flags->gradOK) {
    Flags->done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = Swingup_MPC_computeComplError
      (fscales_lineq_constraint_size, fscales_cineq_constraint_size,
       TrialState->xstarsqp, WorkingSet->sizes[2], TrialState->cIneq.data,
       WorkingSet->indexLB.data, WorkingSet->sizes[3], lb,
       WorkingSet->indexUB.data, WorkingSet->sizes[4],
       TrialState->lambdaStopTest.data, WorkingSet->sizes[0] + 41);
    if ((MeritFunction->nlpDualFeasError >= MeritFunction->nlpComplError) ||
        rtIsNaN(MeritFunction->nlpComplError)) {
      MeritFunction->firstOrderOpt = MeritFunction->nlpDualFeasError;
    } else {
      MeritFunction->firstOrderOpt = MeritFunction->nlpComplError;
    }

    if (TrialState->sqpIterations > 1) {
      Swingup_MPC_computeGradLag_b(memspace->workspace_double, WorkingSet->ldA,
        WorkingSet->nVar, TrialState->grad.data, WorkingSet->sizes[2],
        WorkingSet->Aineq, WorkingSet->Aeq, WorkingSet->indexFixed.data,
        WorkingSet->sizes[0], WorkingSet->indexLB.data, WorkingSet->sizes[3],
        WorkingSet->indexUB.data, WorkingSet->sizes[4],
        TrialState->lambdaStopTestPrev.data);
      Swingup__computeDualFeasError_e(WorkingSet->nVar,
        memspace->workspace_double, &dxTooSmall, &s);
      nlpComplErrorTmp = Swingup_MPC_computeComplError
        (fscales_lineq_constraint_size, fscales_cineq_constraint_size,
         TrialState->xstarsqp, WorkingSet->sizes[2], TrialState->cIneq.data,
         WorkingSet->indexLB.data, WorkingSet->sizes[3], lb,
         WorkingSet->indexUB.data, WorkingSet->sizes[4],
         TrialState->lambdaStopTestPrev.data, WorkingSet->sizes[0] + 41);
      if ((s >= nlpComplErrorTmp) || rtIsNaN(nlpComplErrorTmp)) {
        tmp = s;
      } else {
        tmp = nlpComplErrorTmp;
      }

      if ((MeritFunction->nlpDualFeasError >= MeritFunction->nlpComplError) ||
          rtIsNaN(MeritFunction->nlpComplError)) {
        tmp_0 = MeritFunction->nlpDualFeasError;
      } else {
        tmp_0 = MeritFunction->nlpComplError;
      }

      if (tmp < tmp_0) {
        MeritFunction->nlpDualFeasError = s;
        MeritFunction->nlpComplError = nlpComplErrorTmp;
        MeritFunction->firstOrderOpt = tmp;
        if (idx_max_tmp - 1 >= 0) {
          memcpy(&TrialState->lambdaStopTest.data[0],
                 &TrialState->lambdaStopTestPrev.data[0], (uint32_T)idx_max_tmp *
                 sizeof(real_T));
        }
      } else if (idx_max_tmp - 1 >= 0) {
        memcpy(&TrialState->lambdaStopTestPrev.data[0],
               &TrialState->lambdaStopTest.data[0], (uint32_T)idx_max_tmp *
               sizeof(real_T));
      }
    } else if (idx_max_tmp - 1 >= 0) {
      memcpy(&TrialState->lambdaStopTestPrev.data[0],
             &TrialState->lambdaStopTest.data[0], (uint32_T)idx_max_tmp * sizeof
             (real_T));
    }

    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 * smax) &&
        (MeritFunction->nlpComplError <= 1.0E-6 * smax)) {
      Flags->done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags->done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags->done = true;
        TrialState->sqpExitFlag = -3;
      } else {
        guard1 = false;
        if (TrialState->sqpIterations > 0) {
          dxTooSmall = true;
          iQR_diag = 0;
          exitg1 = false;
          while ((!exitg1) && (iQR_diag <= (uint8_T)WorkingSet->nVar - 1)) {
            s = fabs(TrialState->xstarsqp[iQR_diag]);
            if ((s <= 1.0) || rtIsNaN(s)) {
              s = 1.0;
            }

            if (1.0E-6 * s <= fabs(TrialState->delta_x.data[iQR_diag])) {
              dxTooSmall = false;
              exitg1 = true;
            } else {
              iQR_diag++;
            }
          }

          if (dxTooSmall) {
            if (!isFeasible) {
              if (Flags->stepType != 2) {
                Flags->stepType = 2;
                Flags->failedLineSearch = false;
                Flags->stepAccepted = false;
                guard1 = true;
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = -2;
              }
            } else {
              nVar = WorkingSet->nActiveConstr - 1;
              if (WorkingSet->nActiveConstr > 0) {
                Swingu_updateWorkingSetForNewQP(TrialState->xstarsqp, WorkingSet,
                  WorkingSet->sizes[2], TrialState->mNonlinIneq,
                  TrialState->cIneq.data, TrialState->cEq, WorkingSet->sizes[3],
                  lb, WorkingSet->sizes[4], WorkingSet->sizes[0]);
                for (iQR_diag = 0; iQR_diag <= nVar; iQR_diag++) {
                  TrialState->lambda.data[iQR_diag] = 0.0;
                }

                Swingup_MPC_factorQRE(QRManager, WorkingSet->ATwset,
                                      WorkingSet->nVar,
                                      WorkingSet->nActiveConstr, WorkingSet->ldA);
                rankR = QRManager->minRowCol;
                for (nVar = 0; nVar < rankR; nVar++) {
                  iQR_diag = QRManager->ldq * nVar + nVar;
                  b_ix = QRManager->mrows - nVar;
                  for (idx_max = 0; idx_max <= b_ix - 2; idx_max++) {
                    ix = (idx_max + iQR_diag) + 1;
                    QRManager->Q->data[ix] = QRManager->QR->data[ix];
                  }
                }

                Swingup_MPC_xorgqr(QRManager->mrows, QRManager->mrows,
                                   QRManager->minRowCol, QRManager->Q,
                                   QRManager->ldq, QRManager->tau.data);
                Swingup_MPC_xgemv_n(WorkingSet->nVar, WorkingSet->nVar,
                                    QRManager->Q, QRManager->ldq,
                                    TrialState->grad.data,
                                    memspace->workspace_double);
                if (WorkingSet->nVar >= WorkingSet->nActiveConstr) {
                  idx_max = WorkingSet->nVar;
                } else {
                  idx_max = WorkingSet->nActiveConstr;
                }

                s = (real_T)idx_max * 2.2204460492503131E-16;
                if (s >= 1.4901161193847656E-8) {
                  s = 1.4901161193847656E-8;
                }

                s *= fabs(QRManager->QR->data[0]);
                if (WorkingSet->nVar <= WorkingSet->nActiveConstr) {
                  ix = WorkingSet->nVar;
                } else {
                  ix = WorkingSet->nActiveConstr;
                }

                rankR = 0;
                iQR_diag = 0;
                while ((rankR < ix) && (fabs(QRManager->QR->data[iQR_diag]) > s))
                {
                  rankR++;
                  iQR_diag = (iQR_diag + QRManager->ldq) + 1;
                }

                if (rankR != 0) {
                  for (nVar = rankR; nVar >= 1; nVar--) {
                    iQR_diag = ((nVar - 1) * QRManager->ldq + nVar) - 2;
                    memspace->workspace_double->data[nVar - 1] /= QRManager->
                      QR->data[iQR_diag + 1];
                    for (idx_max = 0; idx_max <= nVar - 2; idx_max++) {
                      b_ix = (nVar - idx_max) - 2;
                      memspace->workspace_double->data[b_ix] -=
                        memspace->workspace_double->data[nVar - 1] *
                        QRManager->QR->data[iQR_diag - idx_max];
                    }
                  }
                }

                if (WorkingSet->nActiveConstr <= ix) {
                  nVar = (uint8_T)WorkingSet->nActiveConstr;
                } else {
                  nVar = (uint8_T)ix;
                }

                for (iQR_diag = 0; iQR_diag < nVar; iQR_diag++) {
                  TrialState->lambda.data[QRManager->jpvt.data[iQR_diag] - 1] =
                    memspace->workspace_double->data[iQR_diag];
                }

                idx_max = WorkingSet->sizes[0] + 41;
                nVar = WorkingSet->sizes[0] + 39;
                for (iQR_diag = mFixed + 1; iQR_diag <= nVar; iQR_diag += 2) {
                  tmp_1 = _mm_loadu_pd(&TrialState->lambda.data[iQR_diag - 1]);
                  _mm_storeu_pd(&TrialState->lambda.data[iQR_diag - 1],
                                _mm_mul_pd(tmp_1, _mm_set1_pd(-1.0)));
                }

                for (iQR_diag = idx_max; iQR_diag <= mFixed + 40; iQR_diag++) {
                  TrialState->lambda.data[iQR_diag - 1] =
                    -TrialState->lambda.data[iQR_diag - 1];
                }

                Swingup_MPC_sortLambdaQP(TrialState->lambda.data,
                  WorkingSet->nActiveConstr, WorkingSet->sizes,
                  WorkingSet->isActiveIdx, WorkingSet->Wid.data,
                  WorkingSet->Wlocalidx.data, memspace->workspace_double);
                Swingup_MPC_computeGradLag_b(memspace->workspace_double,
                  WorkingSet->ldA, WorkingSet->nVar, TrialState->grad.data,
                  WorkingSet->sizes[2], WorkingSet->Aineq, WorkingSet->Aeq,
                  WorkingSet->indexFixed.data, WorkingSet->sizes[0],
                  WorkingSet->indexLB.data, WorkingSet->sizes[3],
                  WorkingSet->indexUB.data, WorkingSet->sizes[4],
                  TrialState->lambda.data);
                Swingup__computeDualFeasError_e(WorkingSet->nVar,
                  memspace->workspace_double, &isFeasible, &s);
                nlpComplErrorTmp = Swingup_MPC_computeComplError
                  (fscales_lineq_constraint_size, fscales_cineq_constraint_size,
                   TrialState->xstarsqp, WorkingSet->sizes[2],
                   TrialState->cIneq.data, WorkingSet->indexLB.data,
                   WorkingSet->sizes[3], lb, WorkingSet->indexUB.data,
                   WorkingSet->sizes[4], TrialState->lambda.data,
                   WorkingSet->sizes[0] + 1);
                if ((s <= 1.0E-6 * smax) && (nlpComplErrorTmp <= 1.0E-6 * smax))
                {
                  MeritFunction->nlpDualFeasError = s;
                  MeritFunction->nlpComplError = nlpComplErrorTmp;
                  if (s >= nlpComplErrorTmp) {
                    MeritFunction->firstOrderOpt = s;
                  } else {
                    MeritFunction->firstOrderOpt = nlpComplErrorTmp;
                  }

                  if (idx_max_tmp - 1 >= 0) {
                    memcpy(&TrialState->lambdaStopTest.data[0],
                           &TrialState->lambda.data[0], (uint32_T)idx_max_tmp *
                           sizeof(real_T));
                  }

                  Flags->done = true;
                  TrialState->sqpExitFlag = 1;
                } else {
                  Flags->done = true;
                  TrialState->sqpExitFlag = 2;
                }
              } else {
                Flags->done = true;
                TrialState->sqpExitFlag = 2;
              }
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          if (TrialState->sqpIterations >= 400) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          } else if (TrialState->FunctionEvaluations >= 4400) {
            Flags->done = true;
            TrialState->sqpExitFlag = 0;
          }
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static boolean_T Swingup_MPC_BFGSUpdate(int32_T nvar, real_T Bk[1936], const
  real_T sk_data[], real_T yk_data[], emxArray_real_T_Swingup_MPC_T *workspace)
{
  __m128d tmp;
  __m128d tmp_0;
  real_T curvatureS;
  real_T dotSY;
  real_T temp;
  int32_T b;
  int32_T b_ix;
  int32_T b_jA;
  int32_T b_tmp;
  int32_T ix;
  int32_T jy;
  int32_T vectorUB;
  boolean_T success;
  dotSY = 0.0;
  if (nvar >= 1) {
    b = (uint8_T)nvar;
    for (ix = 0; ix < b; ix++) {
      dotSY += sk_data[ix] * yk_data[ix];
    }
  }

  b_tmp = (uint8_T)nvar;
  for (ix = 0; ix < b_tmp; ix++) {
    workspace->data[ix] = 0.0;
  }

  ix = 0;
  jy = (nvar - 1) * 44 + 1;
  for (b = 1; b <= jy; b += 44) {
    b_ix = (b + nvar) - 1;
    for (b_jA = b; b_jA <= b_ix; b_jA++) {
      vectorUB = b_jA - b;
      workspace->data[vectorUB] += Bk[b_jA - 1] * sk_data[ix];
    }

    ix++;
  }

  curvatureS = 0.0;
  if (nvar >= 1) {
    for (b = 0; b < b_tmp; b++) {
      curvatureS += workspace->data[b] * sk_data[b];
    }
  }

  if (dotSY < 0.2 * curvatureS) {
    dotSY = 0.8 * curvatureS / (curvatureS - dotSY);
    jy = ((uint8_T)nvar / 2) << 1;
    vectorUB = jy - 2;
    for (ix = 0; ix <= vectorUB; ix += 2) {
      tmp_0 = _mm_loadu_pd(&yk_data[ix]);
      _mm_storeu_pd(&yk_data[ix], _mm_mul_pd(_mm_set1_pd(dotSY), tmp_0));
    }

    for (ix = jy; ix < b_tmp; ix++) {
      yk_data[ix] *= dotSY;
    }

    if (!(1.0 - dotSY == 0.0)) {
      jy = (nvar / 2) << 1;
      vectorUB = jy - 2;
      for (b = 0; b <= vectorUB; b += 2) {
        tmp_0 = _mm_loadu_pd(&workspace->data[b]);
        tmp = _mm_loadu_pd(&yk_data[b]);
        _mm_storeu_pd(&yk_data[b], _mm_add_pd(_mm_mul_pd(tmp_0, _mm_set1_pd(1.0
          - dotSY)), tmp));
      }

      for (b = jy; b < nvar; b++) {
        yk_data[b] += (1.0 - dotSY) * workspace->data[b];
      }
    }

    dotSY = 0.0;
    if (nvar >= 1) {
      for (ix = 0; ix < b_tmp; ix++) {
        dotSY += sk_data[ix] * yk_data[ix];
      }
    }
  }

  success = ((curvatureS > 2.2204460492503131E-16) && (dotSY >
              2.2204460492503131E-16));
  if (success) {
    curvatureS = -1.0 / curvatureS;
    if (!(curvatureS == 0.0)) {
      ix = 1;
      for (b = 0; b < b_tmp; b++) {
        if (workspace->data[b] != 0.0) {
          temp = workspace->data[b] * curvatureS;
          b_ix = nvar + ix;
          jy = (((b_ix - ix) / 2) << 1) + ix;
          vectorUB = jy - 2;
          for (b_jA = ix; b_jA <= vectorUB; b_jA += 2) {
            tmp_0 = _mm_loadu_pd(&workspace->data[b_jA - ix]);
            tmp = _mm_loadu_pd(&Bk[b_jA - 1]);
            _mm_storeu_pd(&Bk[b_jA - 1], _mm_add_pd(_mm_mul_pd(tmp_0,
              _mm_set1_pd(temp)), tmp));
          }

          for (b_jA = jy; b_jA < b_ix; b_jA++) {
            Bk[b_jA - 1] += workspace->data[b_jA - ix] * temp;
          }
        }

        ix += 44;
      }
    }

    dotSY = 1.0 / dotSY;
    if (!(dotSY == 0.0)) {
      b_jA = 1;
      for (ix = 0; ix < b_tmp; ix++) {
        if (yk_data[ix] != 0.0) {
          curvatureS = yk_data[ix] * dotSY;
          b_ix = nvar + b_jA;
          jy = (((b_ix - b_jA) / 2) << 1) + b_jA;
          vectorUB = jy - 2;
          for (b = b_jA; b <= vectorUB; b += 2) {
            tmp_0 = _mm_loadu_pd(&yk_data[b - b_jA]);
            tmp = _mm_loadu_pd(&Bk[b - 1]);
            _mm_storeu_pd(&Bk[b - 1], _mm_add_pd(_mm_mul_pd(tmp_0, _mm_set1_pd
              (curvatureS)), tmp));
          }

          for (b = jy; b < b_ix; b++) {
            Bk[b - 1] += yk_data[b - b_jA] * curvatureS;
          }
        }

        b_jA += 44;
      }
    }
  }

  return success;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_factorQRE_f(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj,
  int32_T mrows, int32_T ncols)
{
  if (mrows * ncols == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if (mrows <= ncols) {
      obj->minRowCol = mrows;
    } else {
      obj->minRowCol = ncols;
    }

    Swingup_MPC_xgeqp3(obj->QR, mrows, ncols, obj->jpvt.data, obj->tau.data,
                       &obj->tau.size);
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_countsort(int32_T x_data[], int32_T xLen, int32_T
  workspace_data[], int32_T xMin, int32_T xMax)
{
  int32_T idxEnd;
  int32_T idxEnd_tmp;
  int32_T idxStart;
  int32_T maxOffset;
  int32_T maxOffset_tmp;
  if ((xLen > 1) && (xMax > xMin)) {
    idxEnd_tmp = xMax - xMin;
    if (idxEnd_tmp >= 0) {
      memset(&workspace_data[0], 0, (uint32_T)(idxEnd_tmp + 1) * sizeof(int32_T));
    }

    maxOffset_tmp = idxEnd_tmp - 1;
    for (idxStart = 0; idxStart < xLen; idxStart++) {
      idxEnd = x_data[idxStart] - xMin;
      workspace_data[idxEnd]++;
    }

    for (idxStart = 2; idxStart <= maxOffset_tmp + 2; idxStart++) {
      workspace_data[idxStart - 1] += workspace_data[idxStart - 2];
    }

    idxStart = 1;
    idxEnd = workspace_data[0];
    for (maxOffset = 0; maxOffset <= maxOffset_tmp; maxOffset++) {
      for (idxEnd_tmp = idxStart; idxEnd_tmp <= idxEnd; idxEnd_tmp++) {
        x_data[idxEnd_tmp - 1] = maxOffset + xMin;
      }

      idxStart = workspace_data[maxOffset] + 1;
      idxEnd = workspace_data[maxOffset + 1];
    }

    for (maxOffset = idxStart; maxOffset <= idxEnd; maxOffset++) {
      x_data[maxOffset - 1] = xMax;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_removeConstr(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T idx_global)
{
  int32_T TYPE_tmp;
  int32_T b;
  int32_T idx;
  int32_T idx_global_start_tmp_tmp;
  TYPE_tmp = obj->Wid.data[idx_global - 1] - 1;
  obj->isActiveConstr.data[(obj->isActiveIdx[TYPE_tmp] + obj->
    Wlocalidx.data[idx_global - 1]) - 2] = false;
  idx_global_start_tmp_tmp = obj->nActiveConstr - 1;
  obj->Wid.data[idx_global - 1] = obj->Wid.data[obj->nActiveConstr - 1];
  obj->Wlocalidx.data[idx_global - 1] = obj->
    Wlocalidx.data[idx_global_start_tmp_tmp];
  b = (uint8_T)obj->nVar;
  for (idx = 0; idx < b; idx++) {
    obj->ATwset->data[idx + obj->ldA * (idx_global - 1)] = obj->ATwset->data
      [obj->ldA * idx_global_start_tmp_tmp + idx];
  }

  obj->bwset.data[idx_global - 1] = obj->bwset.data[idx_global_start_tmp_tmp];
  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static int32_T Swingup_MPC_RemoveDependentEq_(s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset,
  s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager)
{
  real_T qtb;
  real_T tol;
  int32_T c;
  int32_T c_tmp_tmp;
  int32_T iQR0;
  int32_T mTotalWorkingEq_tmp;
  int32_T mWorkingFixed;
  int32_T n;
  int32_T nDepInd;
  int32_T nVar;
  int32_T nVar_tmp;
  int32_T totalRank;
  boolean_T exitg1;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp > 0) {
    c_tmp_tmp = (uint8_T)workingset->nVar;
    for (totalRank = 0; totalRank < mTotalWorkingEq_tmp; totalRank++) {
      for (nVar = 0; nVar < c_tmp_tmp; nVar++) {
        qrmanager->QR->data[totalRank + qrmanager->ldq * nVar] =
          workingset->ATwset->data[workingset->ldA * totalRank + nVar];
      }
    }

    nVar = mTotalWorkingEq_tmp - workingset->nVar;
    if (nVar > 0) {
      nDepInd = nVar;
    }

    memset(&qrmanager->jpvt.data[0], 0, (uint8_T)workingset->nVar * sizeof
           (int32_T));
    Swingup_MPC_factorQRE_f(qrmanager, mTotalWorkingEq_tmp, workingset->nVar);
    tol = 100.0 * (real_T)workingset->nVar * 2.2204460492503131E-16;
    if (workingset->nVar <= mTotalWorkingEq_tmp) {
      totalRank = workingset->nVar;
    } else {
      totalRank = mTotalWorkingEq_tmp;
    }

    totalRank += (totalRank - 1) * qrmanager->ldq;
    while ((totalRank > 0) && (fabs(qrmanager->QR->data[totalRank - 1]) < tol))
    {
      totalRank = (totalRank - qrmanager->ldq) - 1;
      nDepInd++;
    }

    if (nDepInd > 0) {
      totalRank = qrmanager->minRowCol;
      for (nVar = 0; nVar < totalRank; nVar++) {
        iQR0 = qrmanager->ldq * nVar + nVar;
        n = qrmanager->mrows - nVar;
        for (c = 0; c <= n - 2; c++) {
          nVar_tmp = (c + iQR0) + 1;
          qrmanager->Q->data[nVar_tmp] = qrmanager->QR->data[nVar_tmp];
        }
      }

      Swingup_MPC_xorgqr(qrmanager->mrows, qrmanager->mrows,
                         qrmanager->minRowCol, qrmanager->Q, qrmanager->ldq,
                         qrmanager->tau.data);
      c = 0;
      exitg1 = false;
      while ((!exitg1) && (c <= nDepInd - 1)) {
        iQR0 = ((mTotalWorkingEq_tmp - c) - 1) * qrmanager->ldq;
        qtb = 0.0;
        for (nVar = 0; nVar < mTotalWorkingEq_tmp; nVar++) {
          qtb += qrmanager->Q->data[iQR0 + nVar] * workingset->bwset.data[nVar];
        }

        if (fabs(qtb) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          c++;
        }
      }
    }

    if (nDepInd > 0) {
      for (totalRank = 0; totalRank < mTotalWorkingEq_tmp; totalRank++) {
        c = qrmanager->ldq * totalRank;
        iQR0 = workingset->ldA * totalRank;
        for (nVar = 0; nVar < c_tmp_tmp; nVar++) {
          qrmanager->QR->data[c + nVar] = workingset->ATwset->data[iQR0 + nVar];
        }
      }

      for (nVar = 0; nVar < mWorkingFixed; nVar++) {
        qrmanager->jpvt.data[nVar] = 1;
      }

      nVar = workingset->nWConstr[0] + 1;
      if (nVar <= mTotalWorkingEq_tmp) {
        memset(&qrmanager->jpvt.data[nVar + -1], 0, (uint32_T)
               ((mTotalWorkingEq_tmp - nVar) + 1) * sizeof(int32_T));
      }

      Swingup_MPC_factorQRE_f(qrmanager, workingset->nVar, mTotalWorkingEq_tmp);
      for (mWorkingFixed = 0; mWorkingFixed < nDepInd; mWorkingFixed++) {
        memspace->workspace_int.data[mWorkingFixed] = qrmanager->jpvt.data
          [(mTotalWorkingEq_tmp - nDepInd) + mWorkingFixed];
      }

      Swingup_MPC_countsort(memspace->workspace_int.data, nDepInd,
                            memspace->workspace_sort.data, 1,
                            mTotalWorkingEq_tmp);
      for (totalRank = nDepInd; totalRank >= 1; totalRank--) {
        nVar = workingset->nWConstr[0] + workingset->nWConstr[1];
        if (nVar != 0) {
          c = memspace->workspace_int.data[totalRank - 1];
          if (c <= nVar) {
            if ((nVar == workingset->nActiveConstr) || (c == nVar)) {
              workingset->mEqRemoved++;
              workingset->indexEqRemoved[workingset->mEqRemoved - 1] =
                workingset->Wlocalidx.data[memspace->
                workspace_int.data[totalRank - 1] - 1];
              Swingup_MPC_removeConstr(workingset, memspace->
                workspace_int.data[totalRank - 1]);
            } else {
              workingset->mEqRemoved++;
              mTotalWorkingEq_tmp = workingset->Wid.data[c - 1] - 1;
              workingset->indexEqRemoved[workingset->mEqRemoved - 1] =
                workingset->Wlocalidx.data[c - 1];
              workingset->isActiveConstr.data[(workingset->
                isActiveIdx[workingset->Wid.data[c - 1] - 1] +
                workingset->Wlocalidx.data[c - 1]) - 2] = false;
              workingset->Wid.data[c - 1] = workingset->Wid.data[nVar - 1];
              workingset->Wlocalidx.data[c - 1] = workingset->
                Wlocalidx.data[nVar - 1];
              nVar_tmp = (uint8_T)workingset->nVar;
              for (mWorkingFixed = 0; mWorkingFixed < nVar_tmp; mWorkingFixed++)
              {
                workingset->ATwset->data[mWorkingFixed + workingset->ldA * (c -
                  1)] = workingset->ATwset->data[(nVar - 1) * workingset->ldA +
                  mWorkingFixed];
              }

              workingset->bwset.data[c - 1] = workingset->bwset.data[nVar - 1];
              nVar_tmp = workingset->nActiveConstr - 1;
              workingset->Wid.data[nVar - 1] = workingset->Wid.data
                [workingset->nActiveConstr - 1];
              workingset->Wlocalidx.data[nVar - 1] = workingset->
                Wlocalidx.data[nVar_tmp];
              c = (uint8_T)workingset->nVar;
              for (mWorkingFixed = 0; mWorkingFixed < c; mWorkingFixed++) {
                workingset->ATwset->data[mWorkingFixed + workingset->ldA * (nVar
                  - 1)] = workingset->ATwset->data[workingset->ldA * nVar_tmp +
                  mWorkingFixed];
              }

              workingset->bwset.data[nVar - 1] = workingset->bwset.data[nVar_tmp];
              workingset->nActiveConstr--;
              workingset->nWConstr[mTotalWorkingEq_tmp]--;
            }
          }
        }
      }
    }
  }

  return nDepInd;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MP_RemoveDependentIneq_(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace)
{
  real_T tol;
  int32_T c;
  int32_T ix0;
  int32_T iy0;
  int32_T nActiveConstr;
  int32_T nActiveConstr_tmp;
  int32_T nDepIneq;
  int32_T nFixedConstr;
  int32_T nVar;
  nActiveConstr_tmp = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    tol = 100.0 * (real_T)workingset->nVar * 2.2204460492503131E-16;
    for (nDepIneq = 0; nDepIneq < nFixedConstr; nDepIneq++) {
      qrmanager->jpvt.data[nDepIneq] = 1;
    }

    if (nFixedConstr + 1 <= nActiveConstr_tmp) {
      memset(&qrmanager->jpvt.data[nFixedConstr], 0, (uint32_T)
             (nActiveConstr_tmp - nFixedConstr) * sizeof(int32_T));
    }

    for (nDepIneq = 0; nDepIneq < nActiveConstr_tmp; nDepIneq++) {
      iy0 = qrmanager->ldq * nDepIneq;
      ix0 = workingset->ldA * nDepIneq;
      c = (uint8_T)nVar;
      for (nActiveConstr = 0; nActiveConstr < c; nActiveConstr++) {
        qrmanager->QR->data[iy0 + nActiveConstr] = workingset->ATwset->data[ix0
          + nActiveConstr];
      }
    }

    Swingup_MPC_factorQRE_f(qrmanager, workingset->nVar,
      workingset->nActiveConstr);
    nDepIneq = 0;
    for (nActiveConstr = workingset->nActiveConstr - 1; nActiveConstr + 1 > nVar;
         nActiveConstr--) {
      nDepIneq++;
      memspace->workspace_int.data[nDepIneq - 1] = qrmanager->
        jpvt.data[nActiveConstr];
    }

    if (nActiveConstr + 1 <= workingset->nVar) {
      nVar = qrmanager->ldq * nActiveConstr + nActiveConstr;
      while ((nActiveConstr + 1 > nFixedConstr) && (fabs(qrmanager->QR->
               data[nVar]) < tol)) {
        nDepIneq++;
        memspace->workspace_int.data[nDepIneq - 1] = qrmanager->
          jpvt.data[nActiveConstr];
        nActiveConstr--;
        nVar = (nVar - qrmanager->ldq) - 1;
      }
    }

    Swingup_MPC_countsort(memspace->workspace_int.data, nDepIneq,
                          memspace->workspace_sort.data, nFixedConstr + 1,
                          workingset->nActiveConstr);
    for (nFixedConstr = nDepIneq; nFixedConstr >= 1; nFixedConstr--) {
      Swingup_MPC_removeConstr(workingset, memspace->
        workspace_int.data[nFixedConstr - 1]);
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgeqrf(emxArray_real_T_Swingup_MPC_T *A, int32_T m,
  int32_T n, real_T tau_data[], int32_T *tau_size)
{
  int32_T i;
  int32_T minmana;
  int32_T minmn;
  if (A->size[0] <= A->size[1]) {
    minmana = A->size[0];
  } else {
    minmana = A->size[1];
  }

  if (m <= n) {
    minmn = m;
  } else {
    minmn = n;
  }

  *tau_size = minmana;
  for (i = 0; i < minmana; i++) {
    tau_data[i] = 0.0;
  }

  if (minmn >= 1) {
    Swingup_MPC_qrf(A, m, n, minmn, tau_data);
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_factorQR_j(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T mrows, int32_T ncols, int32_T ldA)
{
  int32_T b;
  int32_T idx;
  int32_T ix0;
  int32_T iy0;
  int32_T k;
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  boolean_T guard1;
  idx = mrows * ncols;
  guard1 = false;
  if (idx > 0) {
    for (idx = 0; idx < ncols; idx++) {
      ix0 = ldA * idx;
      iy0 = obj->ldq * idx;
      b = (uint8_T)mrows;
      for (k = 0; k < b; k++) {
        obj->QR->data[iy0 + k] = A->data[ix0 + k];
      }
    }

    guard1 = true;
  } else if (idx == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    k = (ncols / 4) << 2;
    ix0 = k - 4;
    for (idx = 0; idx <= ix0; idx += 4) {
      _mm_storeu_si128((__m128i *)&obj->jpvt.data[idx], _mm_add_epi32
                       (_mm_add_epi32(_mm_set1_epi32(idx), _mm_loadu_si128((
        const __m128i *)&offsets[0])), _mm_set1_epi32(1)));
    }

    for (idx = k; idx < ncols; idx++) {
      obj->jpvt.data[idx] = idx + 1;
    }

    if (mrows <= ncols) {
      obj->minRowCol = mrows;
    } else {
      obj->minRowCol = ncols;
    }

    Swingup_MPC_xgeqrf(obj->QR, mrows, ncols, obj->tau.data, &obj->tau.size);
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_factorQR(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj, int32_T
  mrows, int32_T ncols)
{
  int32_T b;
  int32_T idx;
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  int32_T scalarLB;
  int32_T vectorUB;
  obj->usedPivoting = false;
  obj->mrows = mrows;
  obj->ncols = ncols;
  b = (uint8_T)ncols;
  scalarLB = ((uint8_T)ncols / 4) << 2;
  vectorUB = scalarLB - 4;
  for (idx = 0; idx <= vectorUB; idx += 4) {
    _mm_storeu_si128((__m128i *)&obj->jpvt.data[idx], _mm_add_epi32
                     (_mm_add_epi32(_mm_set1_epi32(idx), _mm_loadu_si128((const
      __m128i *)&offsets[0])), _mm_set1_epi32(1)));
  }

  for (idx = scalarLB; idx < b; idx++) {
    obj->jpvt.data[idx] = idx + 1;
  }

  if (mrows <= ncols) {
    obj->minRowCol = mrows;
  } else {
    obj->minRowCol = ncols;
  }

  Swingup_MPC_xgeqrf(obj->QR, mrows, ncols, obj->tau.data, &obj->tau.size);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv_nbn(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *x, real_T y_data[])
{
  __m128d tmp;
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T e;
  int32_T scalarLB;
  int32_T vectorUB;
  if (n != 0) {
    b = (uint8_T)n;
    scalarLB = ((uint8_T)n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (b_iy = 0; b_iy <= vectorUB; b_iy += 2) {
      tmp = _mm_loadu_pd(&y_data[b_iy]);
      _mm_storeu_pd(&y_data[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
    }

    for (b_iy = scalarLB; b_iy < b; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    scalarLB = 0;
    vectorUB = (n - 1) * lda + 1;
    for (b_iy = 1; lda < 0 ? b_iy >= vectorUB : b_iy <= vectorUB; b_iy += lda) {
      c = 0.0;
      e = (b_iy + m) - 1;
      for (b = b_iy; b <= e; b++) {
        c += x->data[b - b_iy] * A->data[b - 1];
      }

      y_data[scalarLB] += c;
      scalarLB++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv_nb(int32_T n, const emxArray_real_T_Swingup_MPC_T *
  A, int32_T lda, const emxArray_real_T_Swingup_MPC_T *x, real_T y_data[])
{
  __m128d tmp;
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T scalarLB;
  int32_T vectorUB;
  if (n != 0) {
    b = (uint8_T)n;
    scalarLB = ((uint8_T)n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (b_iy = 0; b_iy <= vectorUB; b_iy += 2) {
      tmp = _mm_loadu_pd(&y_data[b_iy]);
      _mm_storeu_pd(&y_data[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
    }

    for (b_iy = scalarLB; b_iy < b; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    scalarLB = 0;
    vectorUB = (n - 1) * lda + 1;
    for (b_iy = 1; lda < 0 ? b_iy >= vectorUB : b_iy <= vectorUB; b_iy += lda) {
      c = 0.0;
      for (b = b_iy; b <= b_iy + 43; b++) {
        c += x->data[b - b_iy] * A->data[b - 1];
      }

      y_data[scalarLB] += c;
      scalarLB++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingup__maxConstraintViolation(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *obj, const emxArray_real_T_Swingup_MPC_T *x)
{
  real_T u1;
  real_T v;
  int32_T g;
  int32_T k;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      g = (uint16_T)obj->sizes[2];
      if (g - 1 >= 0) {
        memcpy(&obj->maxConstrWorkspace.data[0], &obj->bineq.data[0], (uint32_T)
               g * sizeof(real_T));
      }

      Swingup_MPC_xgemv_nb(obj->sizes[2], obj->Aineq, obj->ldA, x,
                           obj->maxConstrWorkspace.data);
      k = (uint8_T)obj->sizes[2];
      for (g = 0; g < k; g++) {
        obj->maxConstrWorkspace.data[g] -= x->data[g + 44];
        u1 = obj->maxConstrWorkspace.data[g];
        if ((!(v >= u1)) && (!rtIsNaN(u1))) {
          v = u1;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 40U * sizeof(real_T));
    Swingup_MPC_xgemv_nb(40, obj->Aeq, obj->ldA, x, obj->maxConstrWorkspace.data);
    for (g = 0; g < 40; g++) {
      k = obj->sizes[2] + g;
      obj->maxConstrWorkspace.data[g] = (obj->maxConstrWorkspace.data[g] -
        x->data[k + 44]) + x->data[k + 84];
      u1 = fabs(obj->maxConstrWorkspace.data[g]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  } else {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      g = (uint16_T)obj->sizes[2];
      if (g - 1 >= 0) {
        memcpy(&obj->maxConstrWorkspace.data[0], &obj->bineq.data[0], (uint32_T)
               g * sizeof(real_T));
      }

      Swingup_MPC_xgemv_nbn(obj->nVar, obj->sizes[2], obj->Aineq, obj->ldA, x,
                            obj->maxConstrWorkspace.data);
      g = (uint8_T)obj->sizes[2];
      for (k = 0; k < g; k++) {
        u1 = obj->maxConstrWorkspace.data[k];
        if ((!(v >= u1)) && (!rtIsNaN(u1))) {
          v = u1;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 40U * sizeof(real_T));
    Swingup_MPC_xgemv_nbn(obj->nVar, 40, obj->Aeq, obj->ldA, x,
                          obj->maxConstrWorkspace.data);
    for (k = 0; k < 40; k++) {
      u1 = fabs(obj->maxConstrWorkspace.data[k]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (mLB > 0) {
    g = (uint16_T)mLB;
    for (mLB = 0; mLB < g; mLB++) {
      u1 = -x->data[obj->indexLB.data[mLB] - 1] - obj->lb.data[obj->
        indexLB.data[mLB] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (mUB > 0) {
    mLB = (uint8_T)mUB;
    for (mUB = 0; mUB < mLB; mUB++) {
      u1 = x->data[obj->indexUB.data[mUB] - 1] - obj->ub.data[obj->
        indexUB.data[mUB] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (mFixed > 0) {
    mUB = (uint8_T)mFixed;
    for (mFixed = 0; mFixed < mUB; mFixed++) {
      u1 = fabs(x->data[obj->indexFixed.data[mFixed] - 1] - obj->ub.data
                [obj->indexFixed.data[mFixed] - 1]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  return v;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv_nbnh(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *x, int32_T ix0, real_T y_data[])
{
  __m128d tmp;
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T e;
  int32_T scalarLB;
  int32_T vectorUB;
  if (n != 0) {
    b = (uint8_T)n;
    scalarLB = ((uint8_T)n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (b_iy = 0; b_iy <= vectorUB; b_iy += 2) {
      tmp = _mm_loadu_pd(&y_data[b_iy]);
      _mm_storeu_pd(&y_data[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
    }

    for (b_iy = scalarLB; b_iy < b; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    scalarLB = 0;
    vectorUB = (n - 1) * lda + 1;
    for (b_iy = 1; lda < 0 ? b_iy >= vectorUB : b_iy <= vectorUB; b_iy += lda) {
      c = 0.0;
      e = (b_iy + m) - 1;
      for (b = b_iy; b <= e; b++) {
        c += x->data[((ix0 + b) - b_iy) - 1] * A->data[b - 1];
      }

      y_data[scalarLB] += c;
      scalarLB++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingu_maxConstraintViolation_l(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *obj, const emxArray_real_T_Swingup_MPC_T *x, int32_T ix0)
{
  real_T u1;
  real_T v;
  int32_T g;
  int32_T k;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      g = (uint16_T)obj->sizes[2];
      if (g - 1 >= 0) {
        memcpy(&obj->maxConstrWorkspace.data[0], &obj->bineq.data[0], (uint32_T)
               g * sizeof(real_T));
      }

      Swingup_MPC_xgemv_nbnh(44, obj->sizes[2], obj->Aineq, obj->ldA, x, ix0,
        obj->maxConstrWorkspace.data);
      k = (uint8_T)obj->sizes[2];
      for (g = 0; g < k; g++) {
        obj->maxConstrWorkspace.data[g] -= x->data[(ix0 + g) + 43];
        u1 = obj->maxConstrWorkspace.data[g];
        if ((!(v >= u1)) && (!rtIsNaN(u1))) {
          v = u1;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 40U * sizeof(real_T));
    Swingup_MPC_xgemv_nbnh(44, 40, obj->Aeq, obj->ldA, x, ix0,
      obj->maxConstrWorkspace.data);
    for (g = 0; g < 40; g++) {
      k = (ix0 + obj->sizes[2]) + g;
      obj->maxConstrWorkspace.data[g] = (obj->maxConstrWorkspace.data[g] -
        x->data[k + 43]) + x->data[k + 83];
      u1 = fabs(obj->maxConstrWorkspace.data[g]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  } else {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      g = (uint16_T)obj->sizes[2];
      if (g - 1 >= 0) {
        memcpy(&obj->maxConstrWorkspace.data[0], &obj->bineq.data[0], (uint32_T)
               g * sizeof(real_T));
      }

      Swingup_MPC_xgemv_nbnh(obj->nVar, obj->sizes[2], obj->Aineq, obj->ldA, x,
        ix0, obj->maxConstrWorkspace.data);
      g = (uint8_T)obj->sizes[2];
      for (k = 0; k < g; k++) {
        u1 = obj->maxConstrWorkspace.data[k];
        if ((!(v >= u1)) && (!rtIsNaN(u1))) {
          v = u1;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 40U * sizeof(real_T));
    Swingup_MPC_xgemv_nbnh(obj->nVar, 40, obj->Aeq, obj->ldA, x, ix0,
      obj->maxConstrWorkspace.data);
    for (k = 0; k < 40; k++) {
      u1 = fabs(obj->maxConstrWorkspace.data[k]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (mLB > 0) {
    g = (uint16_T)mLB;
    for (mLB = 0; mLB < g; mLB++) {
      u1 = -x->data[(ix0 + obj->indexLB.data[mLB]) - 2] - obj->lb.data
        [obj->indexLB.data[mLB] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (mUB > 0) {
    mLB = (uint8_T)mUB;
    for (mUB = 0; mUB < mLB; mUB++) {
      u1 = x->data[(ix0 + obj->indexUB.data[mUB]) - 2] - obj->ub.data
        [obj->indexUB.data[mUB] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (mFixed > 0) {
    mUB = (uint8_T)mFixed;
    for (mFixed = 0; mFixed < mUB; mFixed++) {
      u1 = fabs(x->data[(ix0 + obj->indexFixed.data[mFixed]) - 2] - obj->
                ub.data[obj->indexFixed.data[mFixed] - 1]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  return v;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static boolean_T Swingup_feasibleX0ForWorkingSet(emxArray_real_T_Swingup_MPC_T
  *workspace, real_T xCurrent_data[], s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager)
{
  __m128d tmp;
  __m128d tmp_0;
  emxArray_real_T_Swingup_MPC_T *B;
  real_T c;
  real_T constrViolation_basicX;
  int32_T ar;
  int32_T c_tmp;
  int32_T d;
  int32_T e;
  int32_T exitg1;
  int32_T h;
  int32_T iAcol;
  int32_T ix;
  int32_T iy;
  int32_T l;
  int32_T ldq;
  int32_T ldw;
  int32_T mWConstr;
  int32_T nVar;
  boolean_T nonDegenerateWset;
  mWConstr = workingset->nActiveConstr - 1;
  nVar = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    for (ix = 0; ix <= mWConstr; ix++) {
      workspace->data[ix] = workingset->bwset.data[ix];
      workspace->data[ix + workspace->size[0]] = workingset->bwset.data[ix];
    }

    ldw = workingset->ldA;
    if (workingset->nActiveConstr != 0) {
      iy = 0;
      d = (workingset->nActiveConstr - 1) * workingset->ldA + 1;
      for (ldq = 1; ldw < 0 ? ldq >= d : ldq <= d; ldq += ldw) {
        c = 0.0;
        e = (ldq + nVar) - 1;
        for (ix = ldq; ix <= e; ix++) {
          c += workingset->ATwset->data[ix - 1] * xCurrent_data[ix - ldq];
        }

        workspace->data[iy] -= c;
        iy++;
      }
    }

    Swingup_MPC_emxInit_real_T(&B, 2);
    if (workingset->nActiveConstr >= workingset->nVar) {
      ldw = (uint8_T)workingset->nVar;
      for (ix = 0; ix < ldw; ix++) {
        iy = qrmanager->ldq * ix;
        for (ldq = 0; ldq <= mWConstr; ldq++) {
          qrmanager->QR->data[ldq + iy] = workingset->ATwset->data
            [workingset->ldA * ldq + ix];
        }
      }

      Swingup_MPC_factorQR(qrmanager, workingset->nActiveConstr,
                           workingset->nVar);
      d = qrmanager->minRowCol;
      for (ldq = 0; ldq < d; ldq++) {
        ix = qrmanager->ldq * ldq + ldq;
        e = qrmanager->mrows - ldq;
        for (ldw = 0; ldw <= e - 2; ldw++) {
          iAcol = (ldw + ix) + 1;
          qrmanager->Q->data[iAcol] = qrmanager->QR->data[iAcol];
        }
      }

      Swingup_MPC_xorgqr(qrmanager->mrows, qrmanager->mrows,
                         qrmanager->minRowCol, qrmanager->Q, qrmanager->ldq,
                         qrmanager->tau.data);
      ldq = qrmanager->ldq;
      ldw = workspace->size[0];
      iAcol = B->size[0] * B->size[1];
      B->size[0] = workspace->size[0];
      B->size[1] = workspace->size[1];
      Swingu_emxEnsureCapacity_real_T(B, iAcol);
      iy = workspace->size[0] * workspace->size[1];
      if (iy - 1 >= 0) {
        memcpy(&B->data[0], &workspace->data[0], (uint32_T)iy * sizeof(real_T));
      }

      for (ix = 0; ldw < 0 ? ix >= ldw : ix <= ldw; ix += ldw) {
        d = ix + nVar;
        for (iy = ix + 1; iy <= d; iy++) {
          workspace->data[iy - 1] = 0.0;
        }
      }

      iy = -1;
      for (d = 0; ldw < 0 ? d >= ldw : d <= ldw; d += ldw) {
        iAcol = -1;
        ar = d + nVar;
        for (ix = d + 1; ix <= ar; ix++) {
          c = 0.0;
          for (e = 0; e <= mWConstr; e++) {
            c += qrmanager->Q->data[(e + iAcol) + 1] * B->data[(e + iy) + 1];
          }

          workspace->data[ix - 1] += c;
          iAcol += ldq;
        }

        iy += ldw;
      }

      for (mWConstr = 0; mWConstr < 2; mWConstr++) {
        iy = ldw * mWConstr - 1;
        for (ix = nVar; ix >= 1; ix--) {
          iAcol = (ix - 1) * ldq;
          if (workspace->data[ix + iy] != 0.0) {
            d = ix + iy;
            workspace->data[d] /= qrmanager->QR->data[(ix + iAcol) - 1];
            ar = (uint8_T)(ix - 1);
            for (e = 0; e < ar; e++) {
              c_tmp = (e + iy) + 1;
              workspace->data[c_tmp] -= qrmanager->QR->data[e + iAcol] *
                workspace->data[d];
            }
          }
        }
      }
    } else {
      Swingup_MPC_factorQR_j(qrmanager, workingset->ATwset, workingset->nVar,
        workingset->nActiveConstr, workingset->ldA);
      iy = qrmanager->minRowCol;
      for (ldq = 0; ldq < iy; ldq++) {
        ix = qrmanager->ldq * ldq + ldq;
        e = qrmanager->mrows - ldq;
        for (ldw = 0; ldw <= e - 2; ldw++) {
          iAcol = (ldw + ix) + 1;
          qrmanager->Q->data[iAcol] = qrmanager->QR->data[iAcol];
        }
      }

      Swingup_MPC_xorgqr(qrmanager->mrows, qrmanager->minRowCol,
                         qrmanager->minRowCol, qrmanager->Q, qrmanager->ldq,
                         qrmanager->tau.data);
      ldq = qrmanager->ldq;
      ldw = workspace->size[0];
      for (d = 0; d < 2; d++) {
        iy = ldw * d;
        for (ix = 0; ix <= mWConstr; ix++) {
          iAcol = ldq * ix;
          c_tmp = ix + iy;
          c = workspace->data[c_tmp];
          ar = (uint8_T)ix;
          for (e = 0; e < ar; e++) {
            c -= qrmanager->QR->data[e + iAcol] * workspace->data[e + iy];
          }

          workspace->data[c_tmp] = c / qrmanager->QR->data[ix + iAcol];
        }
      }

      iAcol = B->size[0] * B->size[1];
      B->size[0] = workspace->size[0];
      B->size[1] = workspace->size[1];
      Swingu_emxEnsureCapacity_real_T(B, iAcol);
      iy = workspace->size[0] * workspace->size[1];
      if (iy - 1 >= 0) {
        memcpy(&B->data[0], &workspace->data[0], (uint32_T)iy * sizeof(real_T));
      }

      for (ix = 0; ldw < 0 ? ix >= ldw : ix <= ldw; ix += ldw) {
        d = ix + nVar;
        for (iy = ix + 1; iy <= d; iy++) {
          workspace->data[iy - 1] = 0.0;
        }
      }

      iAcol = 1;
      for (ix = 0; ldw < 0 ? ix >= ldw : ix <= ldw; ix += ldw) {
        ar = -1;
        h = iAcol + mWConstr;
        for (e = iAcol; e <= h; e++) {
          l = ix + nVar;
          d = ((((l - ix) / 2) << 1) + ix) + 1;
          c_tmp = d - 2;
          for (iy = ix + 1; iy <= c_tmp; iy += 2) {
            tmp = _mm_loadu_pd(&qrmanager->Q->data[(ar + iy) - ix]);
            tmp_0 = _mm_loadu_pd(&workspace->data[iy - 1]);
            _mm_storeu_pd(&workspace->data[iy - 1], _mm_add_pd(_mm_mul_pd
              (_mm_set1_pd(B->data[e - 1]), tmp), tmp_0));
          }

          for (iy = d; iy <= l; iy++) {
            workspace->data[iy - 1] += qrmanager->Q->data[(ar + iy) - ix] *
              B->data[e - 1];
          }

          ar += ldq;
        }

        iAcol += ldw;
      }
    }

    Swingup_MPC_emxFree_real_T(&B);
    mWConstr = 0;
    do {
      exitg1 = 0;
      if (mWConstr <= (uint8_T)nVar - 1) {
        c = workspace->data[mWConstr];
        if (rtIsInf(c) || rtIsNaN(c)) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          c = workspace->data[mWConstr + workspace->size[0]];
          if (rtIsInf(c) || rtIsNaN(c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            mWConstr++;
          }
        }
      } else {
        d = (nVar / 2) << 1;
        c_tmp = d - 2;
        for (mWConstr = 0; mWConstr <= c_tmp; mWConstr += 2) {
          tmp = _mm_loadu_pd(&workspace->data[mWConstr]);
          tmp_0 = _mm_loadu_pd(&xCurrent_data[mWConstr]);
          _mm_storeu_pd(&workspace->data[mWConstr], _mm_add_pd(tmp, tmp_0));
        }

        for (mWConstr = d; mWConstr < nVar; mWConstr++) {
          workspace->data[mWConstr] += xCurrent_data[mWConstr];
        }

        c = Swingup__maxConstraintViolation(workingset, workspace);
        constrViolation_basicX = Swingu_maxConstraintViolation_l(workingset,
          workspace, workspace->size[0] + 1);
        if ((c <= 2.2204460492503131E-16) || (c < constrViolation_basicX)) {
          memcpy(&xCurrent_data[0], &workspace->data[0], (uint8_T)nVar * sizeof
                 (real_T));
        } else {
          mWConstr = (uint8_T)nVar;
          for (nVar = 0; nVar < mWConstr; nVar++) {
            xCurrent_data[nVar] = workspace->data[workspace->size[0] + nVar];
          }
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup__RemoveDependentIneq__b(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace)
{
  real_T tol;
  int32_T c;
  int32_T ix0;
  int32_T iy0;
  int32_T nActiveConstr;
  int32_T nActiveConstr_tmp;
  int32_T nDepIneq;
  int32_T nFixedConstr;
  int32_T nVar;
  nActiveConstr_tmp = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    tol = 1000.0 * (real_T)workingset->nVar * 2.2204460492503131E-16;
    for (nDepIneq = 0; nDepIneq < nFixedConstr; nDepIneq++) {
      qrmanager->jpvt.data[nDepIneq] = 1;
    }

    if (nFixedConstr + 1 <= nActiveConstr_tmp) {
      memset(&qrmanager->jpvt.data[nFixedConstr], 0, (uint32_T)
             (nActiveConstr_tmp - nFixedConstr) * sizeof(int32_T));
    }

    for (nDepIneq = 0; nDepIneq < nActiveConstr_tmp; nDepIneq++) {
      iy0 = qrmanager->ldq * nDepIneq;
      ix0 = workingset->ldA * nDepIneq;
      c = (uint8_T)nVar;
      for (nActiveConstr = 0; nActiveConstr < c; nActiveConstr++) {
        qrmanager->QR->data[iy0 + nActiveConstr] = workingset->ATwset->data[ix0
          + nActiveConstr];
      }
    }

    Swingup_MPC_factorQRE_f(qrmanager, workingset->nVar,
      workingset->nActiveConstr);
    nDepIneq = 0;
    for (nActiveConstr = workingset->nActiveConstr - 1; nActiveConstr + 1 > nVar;
         nActiveConstr--) {
      nDepIneq++;
      memspace->workspace_int.data[nDepIneq - 1] = qrmanager->
        jpvt.data[nActiveConstr];
    }

    if (nActiveConstr + 1 <= workingset->nVar) {
      nVar = qrmanager->ldq * nActiveConstr + nActiveConstr;
      while ((nActiveConstr + 1 > nFixedConstr) && (fabs(qrmanager->QR->
               data[nVar]) < tol)) {
        nDepIneq++;
        memspace->workspace_int.data[nDepIneq - 1] = qrmanager->
          jpvt.data[nActiveConstr];
        nActiveConstr--;
        nVar = (nVar - qrmanager->ldq) - 1;
      }
    }

    Swingup_MPC_countsort(memspace->workspace_int.data, nDepIneq,
                          memspace->workspace_sort.data, nFixedConstr + 1,
                          workingset->nActiveConstr);
    for (nFixedConstr = nDepIneq; nFixedConstr >= 1; nFixedConstr--) {
      Swingup_MPC_removeConstr(workingset, memspace->
        workspace_int.data[nFixedConstr - 1]);
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv_nbnhgm(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T x_data[], real_T
  y_data[])
{
  __m128d tmp;
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T e;
  int32_T scalarLB;
  int32_T vectorUB;
  if (n != 0) {
    b = (uint8_T)n;
    scalarLB = ((uint8_T)n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (b_iy = 0; b_iy <= vectorUB; b_iy += 2) {
      tmp = _mm_loadu_pd(&y_data[b_iy]);
      _mm_storeu_pd(&y_data[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
    }

    for (b_iy = scalarLB; b_iy < b; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    scalarLB = 0;
    vectorUB = (n - 1) * lda + 1;
    for (b_iy = 1; lda < 0 ? b_iy >= vectorUB : b_iy <= vectorUB; b_iy += lda) {
      c = 0.0;
      e = (b_iy + m) - 1;
      for (b = b_iy; b <= e; b++) {
        c += A->data[b - 1] * x_data[b - b_iy];
      }

      y_data[scalarLB] += c;
      scalarLB++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv_nbnhg(int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T x_data[], real_T
  y_data[])
{
  __m128d tmp;
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T scalarLB;
  int32_T vectorUB;
  if (n != 0) {
    b = (uint8_T)n;
    scalarLB = ((uint8_T)n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (b_iy = 0; b_iy <= vectorUB; b_iy += 2) {
      tmp = _mm_loadu_pd(&y_data[b_iy]);
      _mm_storeu_pd(&y_data[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
    }

    for (b_iy = scalarLB; b_iy < b; b_iy++) {
      y_data[b_iy] = -y_data[b_iy];
    }

    scalarLB = 0;
    vectorUB = (n - 1) * lda + 1;
    for (b_iy = 1; lda < 0 ? b_iy >= vectorUB : b_iy <= vectorUB; b_iy += lda) {
      c = 0.0;
      for (b = b_iy; b <= b_iy + 43; b++) {
        c += A->data[b - 1] * x_data[b - b_iy];
      }

      y_data[scalarLB] += c;
      scalarLB++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swing_maxConstraintViolation_l2(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *obj, const real_T x_data[])
{
  real_T u1;
  real_T v;
  int32_T g;
  int32_T k;
  int32_T mFixed;
  int32_T mLB;
  int32_T mUB;
  mLB = obj->sizes[3];
  mUB = obj->sizes[4];
  mFixed = obj->sizes[0];
  if (obj->probType == 2) {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      g = (uint16_T)obj->sizes[2];
      if (g - 1 >= 0) {
        memcpy(&obj->maxConstrWorkspace.data[0], &obj->bineq.data[0], (uint32_T)
               g * sizeof(real_T));
      }

      Swingup_MPC_xgemv_nbnhg(obj->sizes[2], obj->Aineq, obj->ldA, x_data,
        obj->maxConstrWorkspace.data);
      g = (uint8_T)obj->sizes[2];
      for (k = 0; k < g; k++) {
        obj->maxConstrWorkspace.data[k] -= x_data[k + 44];
        u1 = obj->maxConstrWorkspace.data[k];
        if ((!(v >= u1)) && (!rtIsNaN(u1))) {
          v = u1;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 40U * sizeof(real_T));
    Swingup_MPC_xgemv_nbnhg(40, obj->Aeq, obj->ldA, x_data,
      obj->maxConstrWorkspace.data);
    for (k = 0; k < 40; k++) {
      g = obj->sizes[2] + k;
      obj->maxConstrWorkspace.data[k] = (obj->maxConstrWorkspace.data[k] -
        x_data[g + 44]) + x_data[g + 84];
      u1 = fabs(obj->maxConstrWorkspace.data[k]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  } else {
    v = 0.0;
    if (obj->Aineq->size[0] != 0) {
      g = (uint16_T)obj->sizes[2];
      if (g - 1 >= 0) {
        memcpy(&obj->maxConstrWorkspace.data[0], &obj->bineq.data[0], (uint32_T)
               g * sizeof(real_T));
      }

      Swingup_MPC_xgemv_nbnhgm(obj->nVar, obj->sizes[2], obj->Aineq, obj->ldA,
        x_data, obj->maxConstrWorkspace.data);
      g = (uint8_T)obj->sizes[2];
      for (k = 0; k < g; k++) {
        u1 = obj->maxConstrWorkspace.data[k];
        if ((!(v >= u1)) && (!rtIsNaN(u1))) {
          v = u1;
        }
      }
    }

    memcpy(&obj->maxConstrWorkspace.data[0], &obj->beq[0], 40U * sizeof(real_T));
    Swingup_MPC_xgemv_nbnhgm(obj->nVar, 40, obj->Aeq, obj->ldA, x_data,
      obj->maxConstrWorkspace.data);
    for (k = 0; k < 40; k++) {
      u1 = fabs(obj->maxConstrWorkspace.data[k]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (mLB > 0) {
    k = (uint16_T)mLB;
    for (mLB = 0; mLB < k; mLB++) {
      u1 = -x_data[obj->indexLB.data[mLB] - 1] - obj->lb.data[obj->
        indexLB.data[mLB] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (mUB > 0) {
    mLB = (uint8_T)mUB;
    for (mUB = 0; mUB < mLB; mUB++) {
      u1 = x_data[obj->indexUB.data[mUB] - 1] - obj->ub.data[obj->
        indexUB.data[mUB] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (mFixed > 0) {
    mUB = (uint8_T)mFixed;
    for (mFixed = 0; mFixed < mUB; mFixed++) {
      u1 = fabs(x_data[obj->indexFixed.data[mFixed] - 1] - obj->ub.data
                [obj->indexFixed.data[mFixed] - 1]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  return v;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_PresolveWorkingSet(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T
  *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace,
  s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T
  *qrmanager)
{
  real_T constrViolation;
  int32_T b;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  boolean_T guard1;
  boolean_T okWorkingSet;
  solution->state = 82;
  b = Swingup_MPC_RemoveDependentEq_(memspace, workingset, qrmanager);
  if ((b != -1) && (workingset->nActiveConstr <= qrmanager->ldq)) {
    Swingup_MP_RemoveDependentIneq_(workingset, qrmanager, memspace);
    okWorkingSet = Swingup_feasibleX0ForWorkingSet(memspace->workspace_double,
      solution->xstar.data, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      Swingup__RemoveDependentIneq__b(workingset, qrmanager, memspace);
      okWorkingSet = Swingup_feasibleX0ForWorkingSet(memspace->workspace_double,
        solution->xstar.data, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        constrViolation = Swing_maxConstraintViolation_l2(workingset,
          solution->xstar.data);
        if (constrViolation > 1.0E-6) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    idxStartIneq = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
    idxEndIneq = workingset->nActiveConstr;
    for (b = idxStartIneq; b <= idxEndIneq; b++) {
      workingset->isActiveConstr.data[(workingset->isActiveIdx
        [workingset->Wid.data[b - 1] - 1] + workingset->Wlocalidx.data[b - 1]) -
        2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  emxArray_real_T_Swingup_MPC_T *workspace, const real_T H[1936], const real_T
  f_data[], const real_T x_data[])
{
  real_T c;
  int32_T b;
  int32_T beta1;
  int32_T e;
  int32_T g;
  int32_T ix;
  int32_T tmp;
  beta1 = 0;
  if (obj_hasLinear) {
    if ((uint8_T)obj_nvar - 1 >= 0) {
      memcpy(&workspace->data[0], &f_data[0], (uint8_T)obj_nvar * sizeof(real_T));
    }

    beta1 = 1;
  }

  if (obj_nvar != 0) {
    if (beta1 != 1) {
      b = (uint8_T)obj_nvar;
      for (beta1 = 0; beta1 < b; beta1++) {
        workspace->data[beta1] = 0.0;
      }
    }

    ix = 0;
    e = (obj_nvar - 1) * obj_nvar + 1;
    for (beta1 = 1; obj_nvar < 0 ? beta1 >= e : beta1 <= e; beta1 += obj_nvar) {
      c = 0.5 * x_data[ix];
      g = (beta1 + obj_nvar) - 1;
      for (b = beta1; b <= g; b++) {
        tmp = b - beta1;
        workspace->data[tmp] += H[b - 1] * c;
      }

      ix++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingup_MPC_computeFval(const s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *obj,
  emxArray_real_T_Swingup_MPC_T *workspace, const real_T H[1936], const real_T
  f_data[], const real_T x_data[])
{
  real_T val;
  int32_T b;
  int32_T c_tmp_tmp;
  int32_T idx;
  int32_T scalarLB;
  int32_T vectorUB;
  switch (obj->objtype) {
   case 5:
    val = x_data[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    Swingup_MPC_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f_data,
      x_data);
    val = 0.0;
    if (obj->nvar >= 1) {
      b = (uint8_T)obj->nvar;
      for (idx = 0; idx < b; idx++) {
        val += workspace->data[idx] * x_data[idx];
      }
    }
    break;

   default:
    Swingup_MPC_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f_data,
      x_data);
    b = obj->nvar + 1;
    c_tmp_tmp = obj->maxVar - 1;
    scalarLB = (((((obj->maxVar - obj->nvar) - 1) / 2) << 1) + obj->nvar) + 1;
    vectorUB = scalarLB - 2;
    for (idx = b; idx <= vectorUB; idx += 2) {
      _mm_storeu_pd(&workspace->data[idx - 1], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (0.5 * obj->beta), _mm_loadu_pd(&x_data[idx - 1])), _mm_set1_pd(obj->rho)));
    }

    for (idx = scalarLB; idx <= c_tmp_tmp; idx++) {
      workspace->data[idx - 1] = 0.5 * obj->beta * x_data[idx - 1] + obj->rho;
    }

    val = 0.0;
    if (obj->maxVar - 1 >= 1) {
      b = (uint8_T)(obj->maxVar - 1);
      for (idx = 0; idx < b; idx++) {
        val += workspace->data[idx] * x_data[idx];
      }
    }
    break;
  }

  return val;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv_nbnhgms(int32_T m, int32_T n, const real_T A[1936],
  int32_T lda, const real_T x_data[], real_T y_data[])
{
  int32_T b;
  int32_T b_iy;
  int32_T c;
  int32_T d;
  int32_T ix;
  int32_T tmp;
  if ((m != 0) && (n != 0)) {
    b = (uint8_T)m;
    for (b_iy = 0; b_iy < b; b_iy++) {
      y_data[b_iy] = 0.0;
    }

    ix = 0;
    c = (n - 1) * lda + 1;
    for (b_iy = 1; lda < 0 ? b_iy >= c : b_iy <= c; b_iy += lda) {
      d = (b_iy + m) - 1;
      for (b = b_iy; b <= d; b++) {
        tmp = b - b_iy;
        y_data[tmp] += A[b - 1] * x_data[ix];
      }

      ix++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_computeGrad_StoreHx(s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *obj,
  const real_T H[1936], const real_T f_data[], const real_T x_data[])
{
  __m128d tmp;
  int32_T idx;
  int32_T iy;
  int32_T maxRegVar_tmp;
  int32_T scalarLB;
  int32_T tmp_0;
  int32_T vectorUB;
  switch (obj->objtype) {
   case 5:
    iy = obj->nvar;
    for (idx = 0; idx <= iy - 2; idx++) {
      obj->grad.data[idx] = 0.0;
    }

    obj->grad.data[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    Swingup_MPC_xgemv_nbnhgms(obj->nvar, obj->nvar, H, obj->nvar, x_data,
      obj->Hx.data);
    if ((uint8_T)obj->nvar - 1 >= 0) {
      memcpy(&obj->grad.data[0], &obj->Hx.data[0], (uint8_T)obj->nvar * sizeof
             (real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      iy = obj->nvar - 1;
      scalarLB = (obj->nvar / 2) << 1;
      vectorUB = scalarLB - 2;
      for (idx = 0; idx <= vectorUB; idx += 2) {
        tmp = _mm_loadu_pd(&obj->grad.data[idx]);
        _mm_storeu_pd(&obj->grad.data[idx], _mm_add_pd(tmp, _mm_loadu_pd
          (&f_data[idx])));
      }

      for (idx = scalarLB; idx <= iy; idx++) {
        obj->grad.data[idx] += f_data[idx];
      }
    }
    break;

   default:
    maxRegVar_tmp = obj->maxVar - 1;
    Swingup_MPC_xgemv_nbnhgms(obj->nvar, obj->nvar, H, obj->nvar, x_data,
      obj->Hx.data);
    iy = obj->nvar + 1;
    scalarLB = (((((obj->maxVar - obj->nvar) - 1) / 2) << 1) + obj->nvar) + 1;
    vectorUB = scalarLB - 2;
    for (idx = iy; idx <= vectorUB; idx += 2) {
      _mm_storeu_pd(&obj->Hx.data[idx - 1], _mm_mul_pd(_mm_loadu_pd(&x_data[idx
        - 1]), _mm_set1_pd(obj->beta)));
    }

    for (idx = scalarLB; idx <= maxRegVar_tmp; idx++) {
      obj->Hx.data[idx - 1] = x_data[idx - 1] * obj->beta;
    }

    memcpy(&obj->grad.data[0], &obj->Hx.data[0], (uint8_T)(obj->maxVar - 1) *
           sizeof(real_T));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      iy = obj->nvar - 1;
      scalarLB = (obj->nvar / 2) << 1;
      vectorUB = scalarLB - 2;
      for (idx = 0; idx <= vectorUB; idx += 2) {
        tmp = _mm_loadu_pd(&obj->grad.data[idx]);
        _mm_storeu_pd(&obj->grad.data[idx], _mm_add_pd(tmp, _mm_loadu_pd
          (&f_data[idx])));
      }

      for (idx = scalarLB; idx <= iy; idx++) {
        obj->grad.data[idx] += f_data[idx];
      }
    }

    maxRegVar_tmp = (obj->maxVar - obj->nvar) - 1;
    if (maxRegVar_tmp >= 1) {
      iy = obj->nvar;
      scalarLB = (maxRegVar_tmp / 2) << 1;
      vectorUB = scalarLB - 2;
      for (idx = 0; idx <= vectorUB; idx += 2) {
        tmp_0 = iy + idx;
        tmp = _mm_loadu_pd(&obj->grad.data[tmp_0]);
        _mm_storeu_pd(&obj->grad.data[tmp_0], _mm_add_pd(tmp, _mm_set1_pd
          (obj->rho)));
      }

      for (idx = scalarLB; idx < maxRegVar_tmp; idx++) {
        tmp_0 = iy + idx;
        obj->grad.data[tmp_0] += obj->rho;
      }
    }
    break;
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingup_MPC_computeFval_ReuseHx(const
  s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *obj, emxArray_real_T_Swingup_MPC_T *workspace,
  const real_T f_data[], const real_T x_data[])
{
  __m128d tmp;
  __m128d tmp_0;
  real_T val;
  int32_T b_k;
  int32_T b_k_tmp;
  int32_T maxRegVar;
  int32_T maxRegVar_tmp_tmp;
  int32_T vectorUB;
  switch (obj->objtype) {
   case 5:
    val = x_data[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    if (obj->hasLinear) {
      b_k_tmp = (uint8_T)obj->nvar;
      maxRegVar_tmp_tmp = ((uint8_T)obj->nvar / 2) << 1;
      vectorUB = maxRegVar_tmp_tmp - 2;
      for (maxRegVar = 0; maxRegVar <= vectorUB; maxRegVar += 2) {
        tmp = _mm_loadu_pd(&obj->Hx.data[maxRegVar]);
        _mm_storeu_pd(&workspace->data[maxRegVar], _mm_add_pd(_mm_mul_pd
          (_mm_set1_pd(0.5), tmp), _mm_loadu_pd(&f_data[maxRegVar])));
      }

      for (maxRegVar = maxRegVar_tmp_tmp; maxRegVar < b_k_tmp; maxRegVar++) {
        workspace->data[maxRegVar] = 0.5 * obj->Hx.data[maxRegVar] +
          f_data[maxRegVar];
      }

      val = 0.0;
      if (obj->nvar >= 1) {
        for (b_k = 0; b_k < b_k_tmp; b_k++) {
          val += workspace->data[b_k] * x_data[b_k];
        }
      }
    } else {
      val = 0.0;
      if (obj->nvar >= 1) {
        b_k = (uint8_T)obj->nvar;
        for (maxRegVar = 0; maxRegVar < b_k; maxRegVar++) {
          val += x_data[maxRegVar] * obj->Hx.data[maxRegVar];
        }
      }

      val *= 0.5;
    }
    break;

   default:
    maxRegVar_tmp_tmp = obj->maxVar - 1;
    if (obj->hasLinear) {
      if ((uint8_T)obj->nvar - 1 >= 0) {
        memcpy(&workspace->data[0], &f_data[0], (uint8_T)obj->nvar * sizeof
               (real_T));
      }

      b_k = obj->maxVar - obj->nvar;
      for (maxRegVar = 0; maxRegVar <= b_k - 2; maxRegVar++) {
        workspace->data[obj->nvar + maxRegVar] = obj->rho;
      }

      maxRegVar = (uint8_T)(obj->maxVar - 1) - 1;
      maxRegVar_tmp_tmp = ((uint8_T)(obj->maxVar - 1) / 2) << 1;
      vectorUB = maxRegVar_tmp_tmp - 2;
      for (b_k = 0; b_k <= vectorUB; b_k += 2) {
        tmp = _mm_loadu_pd(&obj->Hx.data[b_k]);
        tmp_0 = _mm_loadu_pd(&workspace->data[b_k]);
        _mm_storeu_pd(&workspace->data[b_k], _mm_add_pd(tmp_0, _mm_mul_pd
          (_mm_set1_pd(0.5), tmp)));
      }

      for (b_k = maxRegVar_tmp_tmp; b_k <= maxRegVar; b_k++) {
        workspace->data[b_k] += 0.5 * obj->Hx.data[b_k];
      }

      val = 0.0;
      if (obj->maxVar - 1 >= 1) {
        for (b_k = 0; b_k <= maxRegVar; b_k++) {
          val += workspace->data[b_k] * x_data[b_k];
        }
      }
    } else {
      val = 0.0;
      if (obj->maxVar - 1 >= 1) {
        maxRegVar = (uint8_T)(obj->maxVar - 1);
        for (b_k = 0; b_k < maxRegVar; b_k++) {
          val += x_data[b_k] * obj->Hx.data[b_k];
        }
      }

      val *= 0.5;
      maxRegVar = obj->nvar + 1;
      for (b_k = maxRegVar; b_k <= maxRegVar_tmp_tmp; b_k++) {
        val += x_data[b_k - 1] * obj->rho;
      }
    }
    break;
  }

  return val;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T ads;
  real_T bds;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_deleteColMoveEnd(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *obj,
  int32_T idx)
{
  real_T b_s;
  real_T b_temp;
  real_T c_c;
  int32_T QRk0;
  int32_T b_ix;
  int32_T b_temp_tmp;
  int32_T b_temp_tmp_0;
  int32_T e;
  int32_T endIdx;
  int32_T i;
  int32_T idxRotGCol;
  int32_T ix;
  if (obj->usedPivoting) {
    i = 1;
    while ((i <= obj->ncols) && (obj->jpvt.data[i - 1] != idx)) {
      i++;
    }

    idx = i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt.data[idx - 1] = obj->jpvt.data[obj->ncols - 1];
    e = obj->minRowCol;
    for (endIdx = 0; endIdx < e; endIdx++) {
      obj->QR->data[endIdx + obj->ldq * (idx - 1)] = obj->QR->data[(obj->ncols -
        1) * obj->ldq + endIdx];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      if (obj->mrows - 1 <= obj->ncols) {
        endIdx = obj->mrows - 1;
      } else {
        endIdx = obj->ncols;
      }

      e = endIdx;
      idxRotGCol = (idx - 1) * obj->ldq;
      while (e >= idx) {
        b_temp = obj->QR->data[e + idxRotGCol];
        Swingup_MPC_xrotg(&obj->QR->data[(e + idxRotGCol) - 1], &b_temp, &c_c,
                          &b_s);
        obj->QR->data[e + idxRotGCol] = b_temp;
        obj->QR->data[e + obj->ldq * (e - 1)] = 0.0;
        QRk0 = obj->ldq * idx + e;
        b_ix = obj->ncols - idx;
        if (b_ix >= 1) {
          ix = QRk0 - 1;
          for (i = 0; i < b_ix; i++) {
            b_temp = obj->QR->data[ix] * c_c + obj->QR->data[QRk0] * b_s;
            obj->QR->data[QRk0] = obj->QR->data[QRk0] * c_c - obj->QR->data[ix] *
              b_s;
            obj->QR->data[ix] = b_temp;
            QRk0 += obj->ldq;
            ix += obj->ldq;
          }
        }

        i = (e - 1) * obj->ldq;
        QRk0 = obj->mrows;
        if (obj->mrows >= 1) {
          ix = obj->ldq + i;
          for (b_ix = 0; b_ix < QRk0; b_ix++) {
            b_temp_tmp = ix + b_ix;
            b_temp_tmp_0 = i + b_ix;
            b_temp = obj->Q->data[b_temp_tmp_0] * c_c + obj->Q->data[b_temp_tmp]
              * b_s;
            obj->Q->data[b_temp_tmp] = obj->Q->data[b_temp_tmp] * c_c - obj->
              Q->data[b_temp_tmp_0] * b_s;
            obj->Q->data[i + b_ix] = b_temp;
          }
        }

        e--;
      }

      for (e = idx + 1; e <= endIdx; e++) {
        i = (e - 1) * obj->ldq;
        b_temp_tmp = e + i;
        b_temp = obj->QR->data[b_temp_tmp];
        Swingup_MPC_xrotg(&obj->QR->data[(e + i) - 1], &b_temp, &c_c, &b_s);
        obj->QR->data[b_temp_tmp] = b_temp;
        QRk0 = (obj->ldq + 1) * e;
        i = obj->ncols - e;
        if (i >= 1) {
          b_ix = QRk0 - 1;
          for (idxRotGCol = 0; idxRotGCol < i; idxRotGCol++) {
            b_temp = obj->QR->data[b_ix] * c_c + obj->QR->data[QRk0] * b_s;
            obj->QR->data[QRk0] = obj->QR->data[QRk0] * c_c - obj->QR->data[b_ix]
              * b_s;
            obj->QR->data[b_ix] = b_temp;
            QRk0 += obj->ldq;
            b_ix += obj->ldq;
          }
        }

        QRk0 = (e - 1) * obj->ldq;
        idxRotGCol = obj->mrows;
        if (obj->mrows >= 1) {
          b_ix = obj->ldq + QRk0;
          for (i = 0; i < idxRotGCol; i++) {
            b_temp_tmp = b_ix + i;
            b_temp_tmp_0 = QRk0 + i;
            b_temp = obj->Q->data[b_temp_tmp_0] * c_c + obj->Q->data[b_temp_tmp]
              * b_s;
            obj->Q->data[b_temp_tmp] = obj->Q->data[b_temp_tmp] * c_c - obj->
              Q->data[b_temp_tmp_0] * b_s;
            obj->Q->data[b_temp_tmp_0] = b_temp;
          }
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static boolean_T Swingup_MPC_strcmp(const char_T a[7])
{
  int32_T ret;
  static const char_T c[7] = { 'f', 'm', 'i', 'n', 'c', 'o', 'n' };

  ret = memcmp(&a[0], &c[0], 7);
  return ret == 0;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemm(int32_T m, int32_T n, int32_T k, const real_T A
  [1936], int32_T lda, const emxArray_real_T_Swingup_MPC_T *B, int32_T ib0,
  int32_T ldb, emxArray_real_T_Swingup_MPC_T *C, int32_T ldc)
{
  __m128d tmp;
  int32_T ar;
  int32_T b;
  int32_T br;
  int32_T c;
  int32_T cr;
  int32_T d;
  int32_T ic;
  int32_T lastColC;
  int32_T scalarLB;
  int32_T vectorUB;
  if ((m != 0) && (n != 0)) {
    br = ib0;
    lastColC = (n - 1) * ldc;
    for (cr = 0; ldc < 0 ? cr >= lastColC : cr <= lastColC; cr += ldc) {
      b = cr + m;
      for (ic = cr + 1; ic <= b; ic++) {
        C->data[ic - 1] = 0.0;
      }
    }

    for (cr = 0; ldc < 0 ? cr >= lastColC : cr <= lastColC; cr += ldc) {
      ar = -1;
      c = br + k;
      for (ic = br; ic < c; ic++) {
        d = cr + m;
        scalarLB = ((((d - cr) / 2) << 1) + cr) + 1;
        vectorUB = scalarLB - 2;
        for (b = cr + 1; b <= vectorUB; b += 2) {
          tmp = _mm_loadu_pd(&C->data[b - 1]);
          _mm_storeu_pd(&C->data[b - 1], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
            (B->data[ic - 1]), _mm_loadu_pd(&A[(ar + b) - cr])), tmp));
        }

        for (b = scalarLB; b <= d; b++) {
          C->data[b - 1] += A[(ar + b) - cr] * B->data[ic - 1];
        }

        ar += lda;
      }

      br += ldb;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemm_h(int32_T m, int32_T n, int32_T k, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T ia0, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *B, int32_T ldb, emxArray_real_T_Swingup_MPC_T
  *C, int32_T ldc)
{
  real_T temp;
  int32_T ar;
  int32_T b;
  int32_T br;
  int32_T c;
  int32_T cr;
  int32_T ic;
  int32_T lastColC;
  if ((m != 0) && (n != 0)) {
    lastColC = (n - 1) * ldc;
    for (cr = 0; ldc < 0 ? cr >= lastColC : cr <= lastColC; cr += ldc) {
      b = cr + m;
      for (ic = cr + 1; ic <= b; ic++) {
        C->data[ic - 1] = 0.0;
      }
    }

    br = -1;
    for (cr = 0; ldc < 0 ? cr >= lastColC : cr <= lastColC; cr += ldc) {
      ar = ia0;
      c = cr + m;
      for (ic = cr + 1; ic <= c; ic++) {
        temp = 0.0;
        for (b = 0; b < k; b++) {
          temp += A->data[(b + ar) - 1] * B->data[(b + br) + 1];
        }

        C->data[ic - 1] += temp;
        ar += lda;
      }

      br += ldb;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_fullColLDL2_(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj,
  int32_T LD_offset, int32_T NColsRemain)
{
  __m128d tmp;
  real_T alpha1;
  real_T temp;
  real_T y;
  int32_T LD_diagOffset;
  int32_T LDimSizeP1;
  int32_T b;
  int32_T b_k;
  int32_T ijA;
  int32_T jA;
  int32_T k;
  int32_T scalarLB;
  int32_T subMatrixDim;
  int32_T vectorUB;
  LDimSizeP1 = obj->ldm;
  for (k = 0; k < NColsRemain; k++) {
    LD_diagOffset = (LDimSizeP1 + 1) * k + LD_offset;
    alpha1 = -1.0 / obj->FMat->data[LD_diagOffset - 1];
    subMatrixDim = (NColsRemain - k) - 2;
    for (b_k = 0; b_k <= subMatrixDim; b_k++) {
      obj->workspace_ = obj->FMat->data[LD_diagOffset + b_k];
    }

    y = obj->workspace_;
    if (!(alpha1 == 0.0)) {
      jA = LD_diagOffset + LDimSizeP1;
      for (b_k = 0; b_k <= subMatrixDim; b_k++) {
        if (y != 0.0) {
          temp = y * alpha1;
          b = (subMatrixDim + jA) + 1;
          scalarLB = ((((b - jA) / 2) << 1) + jA) + 1;
          vectorUB = scalarLB - 2;
          for (ijA = jA + 1; ijA <= vectorUB; ijA += 2) {
            tmp = _mm_loadu_pd(&obj->FMat->data[ijA - 1]);
            _mm_storeu_pd(&obj->FMat->data[ijA - 1], _mm_add_pd(tmp, _mm_set1_pd
              (obj->workspace_ * temp)));
          }

          for (ijA = scalarLB; ijA <= b; ijA++) {
            obj->FMat->data[ijA - 1] += obj->workspace_ * temp;
          }
        }

        jA += obj->ldm;
      }
    }

    alpha1 = 1.0 / obj->FMat->data[LD_diagOffset - 1];
    b_k = (LD_diagOffset + subMatrixDim) + 1;
    scalarLB = ((((b_k - LD_diagOffset) / 2) << 1) + LD_diagOffset) + 1;
    vectorUB = scalarLB - 2;
    for (subMatrixDim = LD_diagOffset + 1; subMatrixDim <= vectorUB;
         subMatrixDim += 2) {
      tmp = _mm_loadu_pd(&obj->FMat->data[subMatrixDim - 1]);
      _mm_storeu_pd(&obj->FMat->data[subMatrixDim - 1], _mm_mul_pd(tmp,
        _mm_set1_pd(alpha1)));
    }

    for (subMatrixDim = scalarLB; subMatrixDim <= b_k; subMatrixDim++) {
      obj->FMat->data[subMatrixDim - 1] *= alpha1;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_partialColLDL3_(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj,
  int32_T LD_offset, int32_T NColsRemain)
{
  __m128d tmp;
  real_T y;
  int32_T LD_diagOffset;
  int32_T LDimSizeP1;
  int32_T br;
  int32_T c;
  int32_T f;
  int32_T idx;
  int32_T ix;
  int32_T iy;
  int32_T k;
  int32_T lastColC;
  int32_T lda;
  int32_T numStrictLowerRows;
  int32_T scalarLB;
  int32_T subRows;
  int32_T vectorUB;
  LDimSizeP1 = obj->ldm + 1;
  for (k = 0; k < 48; k++) {
    subRows = (NColsRemain - k) - 1;
    LD_diagOffset = (LDimSizeP1 * k + LD_offset) - 1;
    for (numStrictLowerRows = 0; numStrictLowerRows <= subRows;
         numStrictLowerRows++) {
      obj->workspace_ = obj->FMat->data[LD_diagOffset + numStrictLowerRows];
    }

    for (numStrictLowerRows = 0; numStrictLowerRows < NColsRemain;
         numStrictLowerRows++) {
      obj->workspace2_ = obj->workspace_;
    }

    lda = obj->ldm;
    y = obj->workspace2_;
    if ((NColsRemain != 0) && (k != 0)) {
      ix = LD_offset + k;
      c = (k - 1) * obj->ldm + 1;
      for (numStrictLowerRows = 1; lda < 0 ? numStrictLowerRows >= c :
           numStrictLowerRows <= c; numStrictLowerRows += lda) {
        lastColC = (numStrictLowerRows + NColsRemain) - 1;
        for (idx = numStrictLowerRows; idx <= lastColC; idx++) {
          y += -obj->FMat->data[ix - 1] * obj->workspace_;
        }

        ix += obj->ldm;
      }
    }

    obj->workspace2_ = y;
    for (numStrictLowerRows = 0; numStrictLowerRows < NColsRemain;
         numStrictLowerRows++) {
      obj->workspace_ = y;
    }

    for (numStrictLowerRows = 0; numStrictLowerRows <= subRows;
         numStrictLowerRows++) {
      obj->FMat->data[LD_diagOffset + numStrictLowerRows] = obj->workspace_;
    }

    numStrictLowerRows = subRows;
    scalarLB = (subRows / 2) << 1;
    vectorUB = scalarLB - 2;
    for (subRows = 0; subRows <= vectorUB; subRows += 2) {
      iy = (subRows + LD_diagOffset) + 1;
      tmp = _mm_loadu_pd(&obj->FMat->data[iy]);
      _mm_storeu_pd(&obj->FMat->data[iy], _mm_div_pd(tmp, _mm_set1_pd(obj->
        FMat->data[LD_diagOffset])));
    }

    for (subRows = scalarLB; subRows < numStrictLowerRows; subRows++) {
      iy = (subRows + LD_diagOffset) + 1;
      obj->FMat->data[iy] /= obj->FMat->data[LD_diagOffset];
    }
  }

  for (k = 48; k <= NColsRemain - 1; k += 48) {
    scalarLB = NColsRemain - k;
    if (scalarLB >= 48) {
      LD_diagOffset = 48;
    } else {
      LD_diagOffset = scalarLB;
    }

    vectorUB = k + LD_diagOffset;
    numStrictLowerRows = vectorUB - 1;
    for (subRows = k; subRows <= numStrictLowerRows; subRows++) {
      idx = vectorUB - subRows;
      lda = (LDimSizeP1 * subRows + LD_offset) - 1;
      for (ix = 0; ix < 48; ix++) {
        obj->workspace2_ = obj->FMat->data[((LD_offset + subRows) + ix *
          obj->ldm) - 1];
      }

      lastColC = obj->ldm;
      if (idx != 0) {
        br = (obj->ldm * 47 + subRows) + 1;
        for (ix = subRows + 1; lastColC < 0 ? ix >= br : ix <= br; ix +=
             lastColC) {
          f = (ix + idx) - 1;
          for (c = ix; c <= f; c++) {
            iy = (lda + c) - ix;
            obj->FMat->data[iy] += obj->workspace_ * -obj->workspace2_;
          }
        }
      }
    }

    if (vectorUB < NColsRemain) {
      subRows = scalarLB - LD_diagOffset;
      numStrictLowerRows = ((LD_offset + LD_diagOffset) + LDimSizeP1 * k) - 1;
      for (idx = 0; idx < 48; idx++) {
        ix = (LD_offset + k) + idx * obj->ldm;
        for (lda = 0; lda < LD_diagOffset; lda++) {
          obj->workspace2_ = obj->FMat->data[(ix + lda) - 1];
        }
      }

      idx = obj->ldm;
      lda = obj->ldm;
      if ((subRows != 0) && (LD_diagOffset != 0)) {
        lastColC = (LD_diagOffset - 1) * obj->ldm + numStrictLowerRows;
        br = 0;
        for (LD_diagOffset = numStrictLowerRows; lda < 0 ? LD_diagOffset >=
             lastColC : LD_diagOffset <= lastColC; LD_diagOffset += lda) {
          br++;
          iy = idx * 47 + br;
          for (ix = br; idx < 0 ? ix >= iy : ix <= iy; ix += idx) {
            f = LD_diagOffset + subRows;
            scalarLB = ((((f - LD_diagOffset) / 2) << 1) + LD_diagOffset) + 1;
            vectorUB = scalarLB - 2;
            for (c = LD_diagOffset + 1; c <= vectorUB; c += 2) {
              tmp = _mm_loadu_pd(&obj->FMat->data[c - 1]);
              _mm_storeu_pd(&obj->FMat->data[c - 1], _mm_add_pd(tmp, _mm_set1_pd
                (-obj->workspace2_ * obj->workspace_)));
            }

            for (c = scalarLB; c <= f; c++) {
              obj->FMat->data[c - 1] += -obj->workspace2_ * obj->workspace_;
            }
          }
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static int32_T Swingup_MPC_xpotrf(int32_T n, emxArray_real_T_Swingup_MPC_T *A,
  int32_T lda)
{
  real_T c;
  real_T ssq;
  int32_T b;
  int32_T b_ix;
  int32_T b_iy;
  int32_T b_j;
  int32_T d;
  int32_T idxA1j;
  int32_T idxAjj;
  int32_T info;
  int32_T iy;
  int32_T jm1;
  int32_T nmj;
  boolean_T exitg1;
  info = 0;
  b_j = 0;
  exitg1 = false;
  while ((!exitg1) && (b_j <= n - 1)) {
    idxA1j = b_j * lda;
    idxAjj = idxA1j + b_j;
    ssq = 0.0;
    if (b_j >= 1) {
      for (nmj = 0; nmj < b_j; nmj++) {
        b_ix = idxA1j + nmj;
        ssq += A->data[b_ix] * A->data[b_ix];
      }
    }

    ssq = A->data[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = sqrt(ssq);
      A->data[idxAjj] = ssq;
      if (b_j + 1 < n) {
        nmj = (n - b_j) - 2;
        jm1 = (idxA1j + lda) + 1;
        idxAjj += lda;
        if ((b_j != 0) && (nmj + 1 != 0)) {
          iy = idxAjj;
          b = lda * nmj + jm1;
          for (b_ix = jm1; lda < 0 ? b_ix >= b : b_ix <= b; b_ix += lda) {
            c = 0.0;
            d = (b_ix + b_j) - 1;
            for (b_iy = b_ix; b_iy <= d; b_iy++) {
              c += A->data[(idxA1j + b_iy) - b_ix] * A->data[b_iy - 1];
            }

            A->data[iy] -= c;
            iy += lda;
          }
        }

        ssq = 1.0 / ssq;
        idxA1j = (lda * nmj + idxAjj) + 1;
        for (nmj = idxAjj + 1; lda < 0 ? nmj >= idxA1j : nmj <= idxA1j; nmj +=
             lda) {
          A->data[nmj - 1] *= ssq;
        }
      }

      b_j++;
    } else {
      A->data[idxAjj] = ssq;
      info = b_j + 1;
      exitg1 = true;
    }
  }

  return info;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv_nbnhgmsy(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T ia0, int32_T lda, const
  emxArray_real_T_Swingup_MPC_T *x, real_T y_data[])
{
  int32_T b;
  int32_T b_iy;
  int32_T c;
  int32_T ix;
  int32_T iyend;
  int32_T tmp;
  if (m != 0) {
    for (b_iy = 0; b_iy < m; b_iy++) {
      y_data[b_iy] = 0.0;
    }

    ix = 0;
    b = (n - 1) * lda + ia0;
    for (b_iy = ia0; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      c = (b_iy + m) - 1;
      for (iyend = b_iy; iyend <= c; iyend++) {
        tmp = iyend - b_iy;
        y_data[tmp] += A->data[iyend - 1] * x->data[ix];
      }

      ix++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_factor(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj, const
  real_T A[1936], int32_T ndims, int32_T ldA)
{
  int32_T b_k;
  int32_T idx;
  int32_T ix0;
  int32_T iy0;
  obj->ndims = ndims;
  for (idx = 0; idx < ndims; idx++) {
    ix0 = ldA * idx;
    iy0 = obj->ldm * idx;
    for (b_k = 0; b_k < ndims; b_k++) {
      obj->FMat->data[iy0 + b_k] = A[b_k + ix0];
    }
  }

  obj->info = Swingup_MPC_xpotrf(ndims, obj->FMat, obj->ldm);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_solve(const s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj, real_T
  rhs_data[])
{
  real_T temp;
  int32_T i;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T n_tmp;
  n_tmp = obj->ndims;
  if (obj->ndims != 0) {
    for (j = 0; j < n_tmp; j++) {
      jA = j * obj->ldm;
      temp = rhs_data[j];
      for (i = 0; i < j; i++) {
        temp -= obj->FMat->data[jA + i] * rhs_data[i];
      }

      rhs_data[j] = temp / obj->FMat->data[jA + j];
    }

    for (j = n_tmp; j >= 1; j--) {
      jA = ((j - 1) * obj->ldm + j) - 2;
      rhs_data[j - 1] /= obj->FMat->data[jA + 1];
      for (i = 0; i <= j - 2; i++) {
        ix = (j - i) - 2;
        rhs_data[ix] -= obj->FMat->data[jA - i] * rhs_data[j - 1];
      }
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_factor_e(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj, const
  real_T A[1936], int32_T ndims, int32_T ldA)
{
  real_T s;
  real_T smax;
  int32_T A_maxDiag_idx;
  int32_T LD_diagOffset;
  int32_T LDimSizeP1;
  int32_T exitg2;
  int32_T ix;
  int32_T iy0;
  boolean_T exitg1;
  LDimSizeP1 = obj->ldm + 1;
  obj->ndims = ndims;
  for (A_maxDiag_idx = 0; A_maxDiag_idx < ndims; A_maxDiag_idx++) {
    ix = ldA * A_maxDiag_idx;
    iy0 = obj->ldm * A_maxDiag_idx;
    for (LD_diagOffset = 0; LD_diagOffset < ndims; LD_diagOffset++) {
      obj->FMat->data[iy0 + LD_diagOffset] = A[LD_diagOffset + ix];
    }
  }

  if (ndims < 1) {
    A_maxDiag_idx = -1;
  } else {
    A_maxDiag_idx = 0;
    if (ndims > 1) {
      smax = fabs(obj->FMat->data[0]);
      for (LD_diagOffset = 2; LD_diagOffset <= ndims; LD_diagOffset++) {
        s = fabs(obj->FMat->data[(LD_diagOffset - 1) * LDimSizeP1]);
        if (s > smax) {
          A_maxDiag_idx = LD_diagOffset - 1;
          smax = s;
        }
      }
    }
  }

  smax = fabs(obj->FMat->data[obj->ldm * A_maxDiag_idx + A_maxDiag_idx]) *
    2.2204460492503131E-16;
  if (smax >= 0.0) {
    obj->regTol_ = smax;
  } else {
    obj->regTol_ = 0.0;
  }

  if (ndims > 128) {
    A_maxDiag_idx = 0;
    exitg1 = false;
    while ((!exitg1) && (A_maxDiag_idx < ndims)) {
      LD_diagOffset = LDimSizeP1 * A_maxDiag_idx + 1;
      ix = ndims - A_maxDiag_idx;
      if (A_maxDiag_idx + 48 <= ndims) {
        Swingup_MPC_partialColLDL3_(obj, LD_diagOffset, ix);
        A_maxDiag_idx += 48;
      } else {
        Swingup_MPC_fullColLDL2_(obj, LD_diagOffset, ix);
        exitg1 = true;
      }
    }
  } else {
    Swingup_MPC_fullColLDL2_(obj, 1, ndims);
  }

  if (obj->ConvexCheck) {
    LDimSizeP1 = 0;
    do {
      exitg2 = 0;
      if (LDimSizeP1 <= ndims - 1) {
        if (obj->FMat->data[obj->ldm * LDimSizeP1 + LDimSizeP1] <= 0.0) {
          obj->info = -LDimSizeP1 - 1;
          exitg2 = 1;
        } else {
          LDimSizeP1++;
        }
      } else {
        obj->ConvexCheck = false;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_solve_c(const s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *obj,
  real_T rhs_data[])
{
  real_T temp;
  int32_T b_i;
  int32_T b_j;
  int32_T c;
  int32_T ix;
  int32_T jjA;
  int32_T n_tmp;
  n_tmp = obj->ndims;
  if (obj->ndims != 0) {
    for (b_j = 0; b_j < n_tmp; b_j++) {
      jjA = b_j * obj->ldm + b_j;
      c = n_tmp - b_j;
      for (b_i = 0; b_i <= c - 2; b_i++) {
        ix = (b_i + b_j) + 1;
        rhs_data[ix] -= obj->FMat->data[(b_i + jjA) + 1] * rhs_data[b_j];
      }
    }
  }

  for (b_j = 0; b_j < n_tmp; b_j++) {
    rhs_data[b_j] /= obj->FMat->data[obj->ldm * b_j + b_j];
  }

  if (obj->ndims != 0) {
    for (b_j = n_tmp; b_j >= 1; b_j--) {
      jjA = (b_j - 1) * obj->ldm;
      temp = rhs_data[b_j - 1];
      for (b_i = n_tmp; b_i >= b_j + 1; b_i--) {
        temp -= obj->FMat->data[(jjA + b_i) - 1] * rhs_data[b_i - 1];
      }

      rhs_data[b_j - 1] = temp;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_compute_deltax(const real_T H[1936],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, const s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *cholmanager, const
  s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective, boolean_T alwaysPositiveDef)
{
  __m128d tmp;
  real_T s;
  real_T smax;
  int32_T b_ldw;
  int32_T b_mNull;
  int32_T c_mNull;
  int32_T exitg2;
  int32_T ix;
  int32_T mNull_tmp;
  int32_T nVar;
  int32_T nullStart;
  int32_T nullStartIdx;
  int32_T nullStartIdx_tmp;
  int32_T vectorUB;
  boolean_T exitg1;
  nVar = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    for (nullStart = 0; nullStart <= nVar; nullStart++) {
      solution->searchDir.data[nullStart] = 0.0;
    }
  } else {
    c_mNull = (qrmanager->mrows / 2) << 1;
    vectorUB = c_mNull - 2;
    for (nullStartIdx = 0; nullStartIdx <= vectorUB; nullStartIdx += 2) {
      tmp = _mm_loadu_pd(&objective->grad.data[nullStartIdx]);
      _mm_storeu_pd(&solution->searchDir.data[nullStartIdx], _mm_mul_pd(tmp,
        _mm_set1_pd(-1.0)));
    }

    for (nullStartIdx = c_mNull; nullStartIdx <= nVar; nullStartIdx++) {
      solution->searchDir.data[nullStartIdx] = -objective->
        grad.data[nullStartIdx];
    }

    if (qrmanager->ncols <= 0) {
      switch (objective->objtype) {
       case 5:
        break;

       case 3:
        if (alwaysPositiveDef) {
          Swingup_MPC_factor(cholmanager, H, qrmanager->mrows, qrmanager->mrows);
        } else {
          Swingup_MPC_factor_e(cholmanager, H, qrmanager->mrows,
                               qrmanager->mrows);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else if (alwaysPositiveDef) {
          Swingup_MPC_solve(cholmanager, solution->searchDir.data);
        } else {
          Swingup_MPC_solve_c(cholmanager, solution->searchDir.data);
        }
        break;

       default:
        if (alwaysPositiveDef) {
          Swingup_MPC_factor(cholmanager, H, objective->nvar, objective->nvar);
          if (cholmanager->info != 0) {
            solution->state = -6;
          } else {
            Swingup_MPC_solve(cholmanager, solution->searchDir.data);
            smax = 1.0 / objective->beta;
            nullStartIdx = objective->nvar + 1;
            b_mNull = qrmanager->mrows;
            c_mNull = ((((qrmanager->mrows - objective->nvar) / 2) << 1) +
                       objective->nvar) + 1;
            vectorUB = c_mNull - 2;
            for (nullStart = nullStartIdx; nullStart <= vectorUB; nullStart += 2)
            {
              tmp = _mm_loadu_pd(&solution->searchDir.data[nullStart - 1]);
              _mm_storeu_pd(&solution->searchDir.data[nullStart - 1], _mm_mul_pd
                            (tmp, _mm_set1_pd(smax)));
            }

            for (nullStart = c_mNull; nullStart <= b_mNull; nullStart++) {
              solution->searchDir.data[nullStart - 1] *= smax;
            }
          }
        }
        break;
      }
    } else {
      nullStartIdx_tmp = qrmanager->ldq * qrmanager->ncols + 1;
      if (objective->objtype == 5) {
        for (nullStart = 0; nullStart < mNull_tmp; nullStart++) {
          memspace->workspace_double->data[nullStart] = -qrmanager->Q->data
            [(qrmanager->ncols + nullStart) * qrmanager->ldq + nVar];
        }

        Swingup_MPC_xgemv_nbnhgmsy(qrmanager->mrows, mNull_tmp, qrmanager->Q,
          nullStartIdx_tmp, qrmanager->ldq, memspace->workspace_double,
          solution->searchDir.data);
      } else {
        if (objective->objtype == 3) {
          Swingup_MPC_xgemm(qrmanager->mrows, mNull_tmp, qrmanager->mrows, H,
                            qrmanager->mrows, qrmanager->Q, nullStartIdx_tmp,
                            qrmanager->ldq, memspace->workspace_double,
                            memspace->workspace_double->size[0]);
          Swingup_MPC_xgemm_h(mNull_tmp, mNull_tmp, qrmanager->mrows,
                              qrmanager->Q, nullStartIdx_tmp, qrmanager->ldq,
                              memspace->workspace_double,
                              memspace->workspace_double->size[0],
                              cholmanager->FMat, cholmanager->ldm);
        } else if (alwaysPositiveDef) {
          nullStartIdx = qrmanager->mrows;
          b_ldw = memspace->workspace_double->size[0];
          Swingup_MPC_xgemm(objective->nvar, mNull_tmp, objective->nvar, H,
                            objective->nvar, qrmanager->Q, nullStartIdx_tmp,
                            qrmanager->ldq, memspace->workspace_double,
                            memspace->workspace_double->size[0]);
          for (b_mNull = 0; b_mNull < mNull_tmp; b_mNull++) {
            ix = objective->nvar + 1;
            c_mNull = ((((nullStartIdx - objective->nvar) / 2) << 1) +
                       objective->nvar) + 1;
            vectorUB = c_mNull - 2;
            for (nullStart = ix; nullStart <= vectorUB; nullStart += 2) {
              tmp = _mm_loadu_pd(&qrmanager->Q->data[((b_mNull +
                qrmanager->ncols) * qrmanager->Q->size[0] + nullStart) - 1]);
              _mm_storeu_pd(&memspace->workspace_double->data[(nullStart +
                memspace->workspace_double->size[0] * b_mNull) - 1], _mm_mul_pd
                            (tmp, _mm_set1_pd(objective->beta)));
            }

            for (nullStart = c_mNull; nullStart <= nullStartIdx; nullStart++) {
              memspace->workspace_double->data[(nullStart +
                memspace->workspace_double->size[0] * b_mNull) - 1] =
                qrmanager->Q->data[((b_mNull + qrmanager->ncols) * qrmanager->
                                    Q->size[0] + nullStart) - 1] *
                objective->beta;
            }
          }

          Swingup_MPC_xgemm_h(mNull_tmp, mNull_tmp, qrmanager->mrows,
                              qrmanager->Q, nullStartIdx_tmp, qrmanager->ldq,
                              memspace->workspace_double, b_ldw,
                              cholmanager->FMat, cholmanager->ldm);
        }

        if (alwaysPositiveDef) {
          cholmanager->ndims = mNull_tmp;
          cholmanager->info = Swingup_MPC_xpotrf(mNull_tmp, cholmanager->FMat,
            cholmanager->ldm);
        } else {
          nullStart = cholmanager->ldm + 1;
          cholmanager->ndims = mNull_tmp;
          nullStartIdx = 0;
          if (mNull_tmp > 1) {
            smax = fabs(cholmanager->FMat->data[0]);
            for (b_mNull = 2; b_mNull <= mNull_tmp; b_mNull++) {
              s = fabs(cholmanager->FMat->data[(b_mNull - 1) * nullStart]);
              if (s > smax) {
                nullStartIdx = b_mNull - 1;
                smax = s;
              }
            }
          }

          smax = fabs(cholmanager->FMat->data[cholmanager->ldm * nullStartIdx +
                      nullStartIdx]) * 2.2204460492503131E-16;
          if (smax >= 0.0) {
            cholmanager->regTol_ = smax;
          } else {
            cholmanager->regTol_ = 0.0;
          }

          if (mNull_tmp > 128) {
            b_mNull = 0;
            exitg1 = false;
            while ((!exitg1) && (b_mNull < mNull_tmp)) {
              nullStartIdx = nullStart * b_mNull + 1;
              c_mNull = mNull_tmp - b_mNull;
              if (b_mNull + 48 <= mNull_tmp) {
                Swingup_MPC_partialColLDL3_(cholmanager, nullStartIdx, c_mNull);
                b_mNull += 48;
              } else {
                Swingup_MPC_fullColLDL2_(cholmanager, nullStartIdx, c_mNull);
                exitg1 = true;
              }
            }
          } else {
            Swingup_MPC_fullColLDL2_(cholmanager, 1, mNull_tmp);
          }

          if (cholmanager->ConvexCheck) {
            b_mNull = 0;
            do {
              exitg2 = 0;
              if (b_mNull <= mNull_tmp - 1) {
                if (cholmanager->FMat->data[cholmanager->ldm * b_mNull + b_mNull]
                    <= 0.0) {
                  cholmanager->info = -b_mNull - 1;
                  exitg2 = 1;
                } else {
                  b_mNull++;
                }
              } else {
                cholmanager->ConvexCheck = false;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          c_mNull = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            for (b_mNull = 0; b_mNull < mNull_tmp; b_mNull++) {
              memspace->workspace_double->data[b_mNull] = 0.0;
            }

            b_ldw = 0;
            ix = (mNull_tmp - 1) * qrmanager->ldq + nullStartIdx_tmp;
            for (nullStart = nullStartIdx_tmp; c_mNull < 0 ? nullStart >= ix :
                 nullStart <= ix; nullStart += c_mNull) {
              smax = 0.0;
              b_mNull = nullStart + nVar;
              for (nullStartIdx = nullStart; nullStartIdx <= b_mNull;
                   nullStartIdx++) {
                smax += qrmanager->Q->data[nullStartIdx - 1] *
                  objective->grad.data[nullStartIdx - nullStart];
              }

              memspace->workspace_double->data[b_ldw] -= smax;
              b_ldw++;
            }
          }

          if (alwaysPositiveDef) {
            c_mNull = cholmanager->ndims;
            if (cholmanager->ndims != 0) {
              for (nullStart = 0; nullStart < c_mNull; nullStart++) {
                b_ldw = nullStart * cholmanager->ldm;
                smax = memspace->workspace_double->data[nullStart];
                for (nullStartIdx = 0; nullStartIdx < nullStart; nullStartIdx++)
                {
                  smax -= cholmanager->FMat->data[b_ldw + nullStartIdx] *
                    memspace->workspace_double->data[nullStartIdx];
                }

                memspace->workspace_double->data[nullStart] = smax /
                  cholmanager->FMat->data[b_ldw + nullStart];
              }
            }

            b_ldw = cholmanager->ndims;
            if (cholmanager->ndims != 0) {
              for (nullStartIdx = b_ldw; nullStartIdx >= 1; nullStartIdx--) {
                ix = ((nullStartIdx - 1) * cholmanager->ldm + nullStartIdx) - 2;
                memspace->workspace_double->data[nullStartIdx - 1] /=
                  cholmanager->FMat->data[ix + 1];
                for (c_mNull = 0; c_mNull <= nullStartIdx - 2; c_mNull++) {
                  b_mNull = (nullStartIdx - c_mNull) - 2;
                  memspace->workspace_double->data[b_mNull] -=
                    memspace->workspace_double->data[nullStartIdx - 1] *
                    cholmanager->FMat->data[ix - c_mNull];
                }
              }
            }
          } else {
            b_ldw = cholmanager->ndims - 1;
            if (cholmanager->ndims != 0) {
              for (nullStartIdx = 0; nullStartIdx <= b_ldw; nullStartIdx++) {
                ix = nullStartIdx * cholmanager->ldm + nullStartIdx;
                b_mNull = b_ldw - nullStartIdx;
                for (c_mNull = 0; c_mNull < b_mNull; c_mNull++) {
                  nullStart = (c_mNull + nullStartIdx) + 1;
                  memspace->workspace_double->data[nullStart] -=
                    cholmanager->FMat->data[(c_mNull + ix) + 1] *
                    memspace->workspace_double->data[nullStartIdx];
                }
              }
            }

            nullStartIdx = cholmanager->ndims;
            for (nullStart = 0; nullStart < nullStartIdx; nullStart++) {
              memspace->workspace_double->data[nullStart] /= cholmanager->
                FMat->data[cholmanager->ldm * nullStart + nullStart];
            }

            c_mNull = cholmanager->ndims;
            if (cholmanager->ndims != 0) {
              for (nullStart = c_mNull; nullStart >= 1; nullStart--) {
                b_ldw = (nullStart - 1) * cholmanager->ldm;
                smax = memspace->workspace_double->data[nullStart - 1];
                for (nullStartIdx = c_mNull; nullStartIdx >= nullStart + 1;
                     nullStartIdx--) {
                  smax -= cholmanager->FMat->data[(b_ldw + nullStartIdx) - 1] *
                    memspace->workspace_double->data[nullStartIdx - 1];
                }

                memspace->workspace_double->data[nullStart - 1] = smax;
              }
            }
          }

          Swingup_MPC_xgemv_nbnhgmsy(qrmanager->mrows, mNull_tmp, qrmanager->Q,
            nullStartIdx_tmp, qrmanager->ldq, memspace->workspace_double,
            solution->searchDir.data);
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingup_MPC_xnrm2_l(int32_T n, const real_T x_data[])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T b;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x_data[0]);
    } else {
      scale = 3.3121686421112381E-170;
      b = (uint8_T)n;
      for (k = 0; k < b; k++) {
        absxk = fabs(x_data[k]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_xgemv_nbnhgmsyw(int32_T m, int32_T n, const
  emxArray_real_T_Swingup_MPC_T *A, int32_T lda, const real_T x_data[],
  emxArray_real_T_Swingup_MPC_T *y)
{
  __m128d tmp;
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T e;
  int32_T scalarLB;
  int32_T vectorUB;
  if (n != 0) {
    b = (uint8_T)n;
    scalarLB = ((uint8_T)n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (b_iy = 0; b_iy <= vectorUB; b_iy += 2) {
      tmp = _mm_loadu_pd(&y->data[b_iy]);
      _mm_storeu_pd(&y->data[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
    }

    for (b_iy = scalarLB; b_iy < b; b_iy++) {
      y->data[b_iy] = -y->data[b_iy];
    }

    b = 0;
    vectorUB = (n - 1) * lda + 1;
    for (b_iy = 1; lda < 0 ? b_iy >= vectorUB : b_iy <= vectorUB; b_iy += lda) {
      c = 0.0;
      e = (b_iy + m) - 1;
      for (scalarLB = b_iy; scalarLB <= e; scalarLB++) {
        c += A->data[scalarLB - 1] * x_data[scalarLB - b_iy];
      }

      y->data[b] += c;
      b++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_feasibleratiotest(const real_T solution_xstar_data[],
  const real_T solution_searchDir_data[], emxArray_real_T_Swingup_MPC_T
  *workspace, int32_T workingset_nVar, int32_T workingset_ldA, const
  emxArray_real_T_Swingup_MPC_T *workingset_Aineq, const real_T
  workingset_bineq_data[], const real_T workingset_lb_data[], const int32_T
  workingset_indexLB_data[], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr_data[],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  real_T alphaTemp;
  real_T b_c;
  real_T denomTol;
  real_T phaseOneCorrectionP;
  real_T ratio;
  real_T u0;
  int32_T d;
  int32_T e;
  int32_T f;
  int32_T ia;
  int32_T iyend;
  int32_T ldw;
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  denomTol = 2.2204460492503131E-13 * Swingup_MPC_xnrm2_l(workingset_nVar,
    solution_searchDir_data);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    d = (uint16_T)workingset_sizes[2];
    if (d - 1 >= 0) {
      memcpy(&workspace->data[0], &workingset_bineq_data[0], (uint32_T)d *
             sizeof(real_T));
    }

    Swingup_MPC_xgemv_nbnhgmsyw(workingset_nVar, workingset_sizes[2],
      workingset_Aineq, workingset_ldA, solution_xstar_data, workspace);
    ldw = workspace->size[0];
    if (workingset_sizes[2] != 0) {
      iyend = workspace->size[0] + workingset_sizes[2];
      for (d = ldw + 1; d <= iyend; d++) {
        workspace->data[d - 1] = 0.0;
      }

      iyend = ldw;
      e = (workingset_sizes[2] - 1) * workingset_ldA + 1;
      for (d = 1; workingset_ldA < 0 ? d >= e : d <= e; d += workingset_ldA) {
        b_c = 0.0;
        f = (d + workingset_nVar) - 1;
        for (ia = d; ia <= f; ia++) {
          b_c += workingset_Aineq->data[ia - 1] * solution_searchDir_data[ia - d];
        }

        workspace->data[iyend] += b_c;
        iyend++;
      }
    }

    iyend = (uint8_T)workingset_sizes[2];
    for (d = 0; d < iyend; d++) {
      ia = ldw + d;
      if ((workspace->data[ia] > denomTol) && (!workingset_isActiveConstr_data
           [(workingset_isActiveIdx[2] + d) - 1])) {
        u0 = fabs(workspace->data[d]);
        ratio = 1.0E-6 - workspace->data[d];
        if ((u0 <= ratio) || rtIsNaN(ratio)) {
          ratio = u0;
        }

        alphaTemp = ratio / workspace->data[ia];
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 3;
          *constrIdx = d + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    b_c = solution_xstar_data[workingset_nVar - 1] * (real_T)isPhaseOne;
    phaseOneCorrectionP = solution_searchDir_data[workingset_nVar - 1] * (real_T)
      isPhaseOne;
    d = workingset_sizes[3];
    for (ldw = 0; ldw <= d - 2; ldw++) {
      iyend = workingset_indexLB_data[ldw];
      alphaTemp = -solution_searchDir_data[iyend - 1] - phaseOneCorrectionP;
      if ((alphaTemp > denomTol) && (!workingset_isActiveConstr_data
           [(workingset_isActiveIdx[3] + ldw) - 1])) {
        ratio = (-solution_xstar_data[iyend - 1] - workingset_lb_data[iyend - 1])
          - b_c;
        u0 = fabs(ratio);
        if ((!(u0 <= 1.0E-6 - ratio)) && (!rtIsNaN(1.0E-6 - ratio))) {
          u0 = 1.0E-6 - ratio;
        }

        alphaTemp = u0 / alphaTemp;
        if (alphaTemp < *alpha) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = ldw + 1;
          *newBlocking = true;
        }
      }
    }

    ia = workingset_indexLB_data[workingset_sizes[3] - 1] - 1;
    b_c = -solution_searchDir_data[ia];
    if ((b_c > denomTol) && (!workingset_isActiveConstr_data
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      ratio = -solution_xstar_data[ia] - workingset_lb_data[ia];
      u0 = fabs(ratio);
      if ((!(u0 <= 1.0E-6 - ratio)) && (!rtIsNaN(1.0E-6 - ratio))) {
        u0 = 1.0E-6 - ratio;
      }

      alphaTemp = u0 / b_c;
      if (alphaTemp < *alpha) {
        *alpha = alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    if (!(*alpha <= 1.0)) {
      *alpha = 1.0;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingu_checkUnboundedOrIllPosed(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T
  *solution, const s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective)
{
  if (objective->objtype == 5) {
    if (Swingup_MPC_xnrm2_l(objective->nvar, solution->searchDir.data) > 100.0 *
        (real_T)objective->nvar * 1.4901161193847656E-8) {
      solution->state = 3;
    } else {
      solution->state = 4;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swin_addBoundToActiveSetMatrix_(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T TYPE, int32_T idx_local)
{
  int32_T b;
  int32_T colOffset;
  int32_T idx;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr.data[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid.data[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx.data[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * obj->ldA - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB.data[idx_local - 1];
    obj->bwset.data[obj->nActiveConstr - 1] = obj->ub.data[idx_bnd_local - 1];
  } else {
    idx_bnd_local = obj->indexLB.data[idx_local - 1];
    obj->bwset.data[obj->nActiveConstr - 1] = obj->lb.data[idx_bnd_local - 1];
  }

  b = (uint8_T)(idx_bnd_local - 1);
  for (idx = 0; idx < b; idx++) {
    obj->ATwset->data[(idx + colOffset) + 1] = 0.0;
  }

  obj->ATwset->data[idx_bnd_local + colOffset] = (real_T)(TYPE == 5) * 2.0 - 1.0;
  b = obj->nVar;
  for (idx = idx_bnd_local + 1; idx <= b; idx++) {
    obj->ATwset->data[idx + colOffset] = 0.0;
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset->data[obj->nVar + colOffset] = -1.0;
    break;
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_addAineqConstr(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T idx_local)
{
  int32_T b;
  int32_T iAineq0;
  int32_T iAw0;
  int32_T idx;
  obj->nWConstr[2]++;
  obj->isActiveConstr.data[(obj->isActiveIdx[2] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid.data[obj->nActiveConstr - 1] = 3;
  obj->Wlocalidx.data[obj->nActiveConstr - 1] = idx_local;
  iAineq0 = (idx_local - 1) * obj->ldA;
  iAw0 = (obj->nActiveConstr - 1) * obj->ldA;
  b = obj->nVar - 1;
  for (idx = 0; idx <= b; idx++) {
    obj->ATwset->data[iAw0 + idx] = obj->Aineq->data[iAineq0 + idx];
  }

  obj->bwset.data[obj->nActiveConstr - 1] = obj->bineq.data[idx_local - 1];
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swin_checkStoppingAndUpdateFval(int32_T *activeSetChangeID, const
  real_T f_data[], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, const
  s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *workingset, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations, boolean_T
  updateFval)
{
  real_T y_data[449];
  real_T tempMaxConstr;
  boolean_T nonDegenerateWset;
  solution->iterations++;
  if ((solution->iterations >= runTimeOptions_MaxIterations) &&
      ((solution->state != 1) || (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    solution->maxConstr = Swing_maxConstraintViolation_l2(workingset,
      solution->xstar.data);
    tempMaxConstr = solution->maxConstr;
    if (objective->objtype == 5) {
      tempMaxConstr = solution->maxConstr - solution->xstar.data[objective->nvar
        - 1];
    }

    if (tempMaxConstr > 1.0E-6) {
      if (solution->searchDir.size - 1 >= 0) {
        memcpy(&y_data[0], &solution->searchDir.data[0], (uint32_T)
               solution->searchDir.size * sizeof(real_T));
      }

      if ((uint16_T)objective->nvar - 1 >= 0) {
        memcpy(&y_data[0], &solution->xstar.data[0], (uint16_T)objective->nvar *
               sizeof(real_T));
      }

      if (solution->searchDir.size - 1 >= 0) {
        memcpy(&solution->searchDir.data[0], &y_data[0], (uint32_T)
               solution->searchDir.size * sizeof(real_T));
      }

      nonDegenerateWset = Swingup_feasibleX0ForWorkingSet
        (memspace->workspace_double, solution->searchDir.data, workingset,
         qrmanager);
      if ((!nonDegenerateWset) && (solution->state != 0)) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      tempMaxConstr = Swing_maxConstraintViolation_l2(workingset,
        solution->searchDir.data);
      if (tempMaxConstr < solution->maxConstr) {
        if ((uint8_T)objective->nvar - 1 >= 0) {
          memcpy(&solution->xstar.data[0], &solution->searchDir.data[0],
                 (uint8_T)objective->nvar * sizeof(real_T));
        }

        solution->maxConstr = tempMaxConstr;
      }
    }
  }

  if (updateFval && (options_ObjectiveLimit > (rtMinusInf))) {
    solution->fstar = Swingup_MPC_computeFval_ReuseHx(objective,
      memspace->workspace_double, f_data, solution->xstar.data);
    if ((solution->fstar < options_ObjectiveLimit) && ((solution->state != 0) ||
         (objective->objtype != 5))) {
      solution->state = 2;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_iterate(const real_T H[1936], const real_T f_data[],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset,
  s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager, s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *cholmanager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective, const char_T
  options_SolverName[7], real_T options_StepTolerance, real_T
  options_ObjectiveLimit, int32_T runTimeOptions_MaxIterations)
{
  __m128d tmp;
  __m128d tmp_0;
  real_T y_data[449];
  real_T normDelta;
  real_T s;
  real_T temp;
  int32_T activeSetChangeID;
  int32_T exitg1;
  int32_T globalActiveConstrIdx;
  int32_T iQR0;
  int32_T idx;
  int32_T idxRotGCol;
  int32_T iy;
  int32_T iyend;
  int32_T nActiveConstr;
  int32_T nVar;
  int32_T nrows;
  boolean_T guard1;
  boolean_T guard11;
  boolean_T guard2;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  nVar = workingset->nVar;
  globalActiveConstrIdx = 0;
  Swingup_MPC_computeGrad_StoreHx(objective, H, f_data, solution->xstar.data);
  solution->fstar = Swingup_MPC_computeFval_ReuseHx(objective,
    memspace->workspace_double, f_data, solution->xstar.data);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  iyend = workingset->mConstrMax;
  for (idxRotGCol = 0; idxRotGCol < iyend; idxRotGCol++) {
    solution->lambda.data[idxRotGCol] = 0.0;
  }

  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard11 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
         case 1:
          nrows = (workingset->nActiveConstr - 1) * workingset->ldA;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          iQR0 = qrmanager->ldq * qrmanager->ncols;
          nActiveConstr = qrmanager->ldq;
          if (qrmanager->mrows != 0) {
            iyend = iQR0 + qrmanager->mrows;
            for (idxRotGCol = iQR0 + 1; idxRotGCol <= iyend; idxRotGCol++) {
              qrmanager->QR->data[idxRotGCol - 1] = 0.0;
            }

            iy = (qrmanager->mrows - 1) * qrmanager->ldq + 1;
            for (iyend = 1; nActiveConstr < 0 ? iyend >= iy : iyend <= iy; iyend
                 += nActiveConstr) {
              normDelta = 0.0;
              idxRotGCol = (iyend + qrmanager->mrows) - 1;
              for (idx = iyend; idx <= idxRotGCol; idx++) {
                normDelta += workingset->ATwset->data[(nrows + idx) - iyend] *
                  qrmanager->Q->data[idx - 1];
              }

              qrmanager->QR->data[iQR0] += normDelta;
              iQR0++;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt.data[qrmanager->ncols - 1] = qrmanager->ncols;
          for (idx = qrmanager->mrows - 2; idx + 2 > qrmanager->ncols; idx--) {
            idxRotGCol = (qrmanager->ncols - 1) * qrmanager->ldq;
            iQR0 = (idx + idxRotGCol) + 1;
            temp = qrmanager->QR->data[iQR0];
            Swingup_MPC_xrotg(&qrmanager->QR->data[idx + idxRotGCol], &temp,
                              &normDelta, &s);
            qrmanager->QR->data[iQR0] = temp;
            idxRotGCol = qrmanager->ldq * idx;
            nActiveConstr = qrmanager->mrows;
            if (qrmanager->mrows >= 1) {
              iy = qrmanager->ldq + idxRotGCol;
              for (iyend = 0; iyend < nActiveConstr; iyend++) {
                iQR0 = iy + iyend;
                nrows = idxRotGCol + iyend;
                temp = qrmanager->Q->data[nrows] * normDelta + qrmanager->
                  Q->data[iQR0] * s;
                qrmanager->Q->data[iQR0] = qrmanager->Q->data[iQR0] * normDelta
                  - qrmanager->Q->data[nrows] * s;
                qrmanager->Q->data[nrows] = temp;
              }
            }
          }
          break;

         case -1:
          Swingup_MPC_deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;

         default:
          Swingup_MPC_factorQR_j(qrmanager, workingset->ATwset, nVar,
            workingset->nActiveConstr, workingset->ldA);
          nActiveConstr = qrmanager->minRowCol;
          for (iyend = 0; iyend < nActiveConstr; iyend++) {
            iQR0 = qrmanager->ldq * iyend + iyend;
            iy = qrmanager->mrows - iyend;
            for (idx = 0; idx <= iy - 2; idx++) {
              idxRotGCol = (idx + iQR0) + 1;
              qrmanager->Q->data[idxRotGCol] = qrmanager->QR->data[idxRotGCol];
            }
          }

          Swingup_MPC_xorgqr(qrmanager->mrows, qrmanager->mrows,
                             qrmanager->minRowCol, qrmanager->Q, qrmanager->ldq,
                             qrmanager->tau.data);
          break;
        }

        Swingup_MPC_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective, Swingup_MPC_strcmp(options_SolverName));
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = Swingup_MPC_xnrm2_l(nVar, solution->searchDir.data);
          guard11 = true;
        }
      } else {
        iyend = solution->searchDir.size;
        if (solution->searchDir.size - 1 >= 0) {
          memcpy(&y_data[0], &solution->searchDir.data[0], (uint32_T)
                 solution->searchDir.size * sizeof(real_T));
        }

        for (idxRotGCol = 0; idxRotGCol < nVar; idxRotGCol++) {
          y_data[idxRotGCol] = 0.0;
        }

        if (solution->searchDir.size - 1 >= 0) {
          memcpy(&solution->searchDir.data[0], &y_data[0], (uint32_T)
                 solution->searchDir.size * sizeof(real_T));
        }

        normDelta = 0.0;
        guard11 = true;
      }

      if (guard11) {
        if ((!subProblemChanged) || (normDelta < options_StepTolerance) ||
            (workingset->nActiveConstr >= nVar)) {
          nActiveConstr = qrmanager->ncols;
          if (qrmanager->ncols > 0) {
            guard1 = false;
            if (objective->objtype != 4) {
              normDelta = 100.0 * (real_T)qrmanager->mrows *
                2.2204460492503131E-16;
              updateFval = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
              if (updateFval) {
                idxRotGCol = qrmanager->ncols;
                guard2 = false;
                if (qrmanager->mrows < qrmanager->ncols) {
                  iyend = (qrmanager->ncols - 1) * qrmanager->ldq +
                    qrmanager->mrows;
                  while ((idxRotGCol > qrmanager->mrows) && (fabs(qrmanager->
                           QR->data[iyend - 1]) >= normDelta)) {
                    idxRotGCol--;
                    iyend -= qrmanager->ldq;
                  }

                  updateFval = (idxRotGCol == qrmanager->mrows);
                  if (!updateFval) {
                  } else {
                    guard2 = true;
                  }
                } else {
                  guard2 = true;
                }

                if (guard2) {
                  iyend = (idxRotGCol - 1) * qrmanager->ldq + idxRotGCol;
                  while ((idxRotGCol >= 1) && (fabs(qrmanager->QR->data[iyend -
                           1]) >= normDelta)) {
                    idxRotGCol--;
                    iyend = (iyend - qrmanager->ldq) - 1;
                  }

                  updateFval = (idxRotGCol == 0);
                }
              }

              if (!updateFval) {
                solution->state = -7;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              Swingup_MPC_xgemv_n(qrmanager->mrows, qrmanager->ncols,
                                  qrmanager->Q, qrmanager->ldq,
                                  objective->grad.data,
                                  memspace->workspace_double);
              if (qrmanager->ncols != 0) {
                for (iyend = nActiveConstr; iyend >= 1; iyend--) {
                  iQR0 = ((iyend - 1) * qrmanager->ldq + iyend) - 2;
                  memspace->workspace_double->data[iyend - 1] /= qrmanager->
                    QR->data[iQR0 + 1];
                  for (idx = 0; idx <= iyend - 2; idx++) {
                    idxRotGCol = (iyend - idx) - 2;
                    memspace->workspace_double->data[idxRotGCol] -=
                      memspace->workspace_double->data[iyend - 1] *
                      qrmanager->QR->data[iQR0 - idx];
                  }
                }
              }

              iyend = (qrmanager->ncols / 2) << 1;
              idx = iyend - 2;
              for (idxRotGCol = 0; idxRotGCol <= idx; idxRotGCol += 2) {
                tmp = _mm_loadu_pd(&memspace->workspace_double->data[idxRotGCol]);
                _mm_storeu_pd(&solution->lambda.data[idxRotGCol], _mm_mul_pd(tmp,
                  _mm_set1_pd(-1.0)));
              }

              for (idxRotGCol = iyend; idxRotGCol < nActiveConstr; idxRotGCol++)
              {
                solution->lambda.data[idxRotGCol] = -memspace->
                  workspace_double->data[idxRotGCol];
              }
            }
          }

          if ((solution->state != -7) || (workingset->nActiveConstr > nVar)) {
            iyend = 0;
            normDelta = 0.0;
            idx = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
            nrows = workingset->nActiveConstr;
            for (idxRotGCol = idx; idxRotGCol <= nrows; idxRotGCol++) {
              if (solution->lambda.data[idxRotGCol - 1] < normDelta) {
                normDelta = solution->lambda.data[idxRotGCol - 1];
                iyend = idxRotGCol;
              }
            }

            if (iyend == 0) {
              solution->state = 1;
            } else {
              activeSetChangeID = -1;
              globalActiveConstrIdx = iyend;
              subProblemChanged = true;
              Swingup_MPC_removeConstr(workingset, iyend);
              solution->lambda.data[iyend - 1] = 0.0;
            }
          } else {
            iyend = workingset->nActiveConstr;
            activeSetChangeID = 0;
            globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            Swingup_MPC_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda.data[iyend - 1] = 0.0;
          }

          updateFval = false;
        } else {
          Swingup_MPC_feasibleratiotest(solution->xstar.data,
            solution->searchDir.data, memspace->workspace_double,
            workingset->nVar, workingset->ldA, workingset->Aineq,
            workingset->bineq.data, workingset->lb.data,
            workingset->indexLB.data, workingset->sizes, workingset->isActiveIdx,
            workingset->isActiveConstr.data, workingset->nWConstr,
            objective->objtype == 5, &normDelta, &updateFval, &idxRotGCol,
            &iyend);
          if (updateFval) {
            switch (idxRotGCol) {
             case 3:
              Swingup_MPC_addAineqConstr(workingset, iyend);
              break;

             case 4:
              Swin_addBoundToActiveSetMatrix_(workingset, 4, iyend);
              break;

             default:
              Swin_addBoundToActiveSetMatrix_(workingset, 5, iyend);
              break;
            }

            activeSetChangeID = 1;
          } else {
            Swingu_checkUnboundedOrIllPosed(solution, objective);
            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if ((nVar >= 1) && (!(normDelta == 0.0))) {
            iyend = (nVar / 2) << 1;
            idx = iyend - 2;
            for (idxRotGCol = 0; idxRotGCol <= idx; idxRotGCol += 2) {
              tmp = _mm_loadu_pd(&solution->searchDir.data[idxRotGCol]);
              tmp_0 = _mm_loadu_pd(&solution->xstar.data[idxRotGCol]);
              _mm_storeu_pd(&solution->xstar.data[idxRotGCol], _mm_add_pd
                            (_mm_mul_pd(_mm_set1_pd(normDelta), tmp), tmp_0));
            }

            for (idxRotGCol = iyend; idxRotGCol < nVar; idxRotGCol++) {
              solution->xstar.data[idxRotGCol] += normDelta *
                solution->searchDir.data[idxRotGCol];
            }
          }

          Swingup_MPC_computeGrad_StoreHx(objective, H, f_data,
            solution->xstar.data);
          updateFval = true;
        }

        Swin_checkStoppingAndUpdateFval(&activeSetChangeID, f_data, solution,
          memspace, objective, workingset, qrmanager, options_ObjectiveLimit,
          runTimeOptions_MaxIterations, updateFval);
      }
    } else {
      if (!updateFval) {
        solution->fstar = Swingup_MPC_computeFval_ReuseHx(objective,
          memspace->workspace_double, f_data, solution->xstar.data);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_phaseone(const real_T H[1936], const real_T f_data[],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset,
  s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager, s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *cholmanager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective,
  somzaGboVhDG7PNQS6E98jD_Swing_T *options, const
  somzaGboVhDG7PNQS6E98jD_Swing_T *runTimeOptions)
{
  int32_T PROBTYPE_ORIG;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T mConstr;
  int32_T nVar_tmp;
  boolean_T exitg1;
  PROBTYPE_ORIG = workingset->probType;
  nVar_tmp = workingset->nVar;
  solution->xstar.data[workingset->nVar] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    mConstr = 1;
  } else {
    mConstr = 4;
  }

  Swingup_MPC_setProblemType(workingset, mConstr);
  idxStartIneq = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
  idxEndIneq = workingset->nActiveConstr;
  for (mConstr = idxStartIneq; mConstr <= idxEndIneq; mConstr++) {
    workingset->isActiveConstr.data[(workingset->isActiveIdx
      [workingset->Wid.data[mConstr - 1] - 1] + workingset->
      Wlocalidx.data[mConstr - 1]) - 2] = false;
  }

  workingset->nWConstr[2] = 0;
  workingset->nWConstr[3] = 0;
  workingset->nWConstr[4] = 0;
  workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = nVar_tmp + 1;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-6;
  options->StepTolerance = 1.4901161193847657E-10;
  solution->fstar = Swingup_MPC_computeFval(objective,
    memspace->workspace_double, H, f_data, solution->xstar.data);
  solution->state = 5;
  Swingup_MPC_iterate(H, f_data, solution, memspace, workingset, qrmanager,
                      cholmanager, objective, options->SolverName,
                      options->StepTolerance, options->ObjectiveLimit,
                      runTimeOptions->MaxIterations);
  if (workingset->isActiveConstr.data[(workingset->isActiveIdx[3] +
       workingset->sizes[3]) - 2]) {
    mConstr = workingset->sizes[0] + 41;
    exitg1 = false;
    while ((!exitg1) && (mConstr <= workingset->nActiveConstr)) {
      if ((workingset->Wid.data[mConstr - 1] == 4) &&
          (workingset->Wlocalidx.data[mConstr - 1] == workingset->sizes[3])) {
        Swingup_MPC_removeConstr(workingset, mConstr);
        exitg1 = true;
      } else {
        mConstr++;
      }
    }
  }

  mConstr = workingset->nActiveConstr;
  while ((mConstr > workingset->sizes[0] + 40) && (mConstr > nVar_tmp)) {
    Swingup_MPC_removeConstr(workingset, mConstr);
    mConstr--;
  }

  solution->maxConstr = solution->xstar.data[nVar_tmp];
  Swingup_MPC_setProblemType(workingset, PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = (rtMinusInf);
  options->StepTolerance = 1.0E-6;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_driver_e(const real_T H[1936], const real_T f_data[],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *solution, s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *workingset,
  s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *qrmanager, s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *cholmanager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *objective,
  somzaGboVhDG7PNQS6E98jD_Swing_T *options, somzaGboVhDG7PNQS6E98jD_Swing_T
  *runTimeOptions)
{
  real_T y_data[449];
  real_T maxConstr_new;
  int32_T b;
  int32_T idx;
  int32_T nVar;
  boolean_T guard1;
  solution->iterations = 0;
  runTimeOptions->RemainFeasible = true;
  nVar = workingset->nVar;
  guard1 = false;
  if (workingset->probType == 3) {
    b = (uint8_T)workingset->sizes[0];
    for (idx = 0; idx < b; idx++) {
      solution->xstar.data[workingset->indexFixed.data[idx] - 1] =
        workingset->ub.data[workingset->indexFixed.data[idx] - 1];
    }

    b = (uint16_T)workingset->sizes[3];
    for (idx = 0; idx < b; idx++) {
      if (workingset->isActiveConstr.data[(workingset->isActiveIdx[3] + idx) - 1])
      {
        solution->xstar.data[workingset->indexLB.data[idx] - 1] =
          -workingset->lb.data[workingset->indexLB.data[idx] - 1];
      }
    }

    b = (uint8_T)workingset->sizes[4];
    for (idx = 0; idx < b; idx++) {
      if (workingset->isActiveConstr.data[(workingset->isActiveIdx[4] + idx) - 1])
      {
        solution->xstar.data[workingset->indexUB.data[idx] - 1] =
          workingset->ub.data[workingset->indexUB.data[idx] - 1];
      }
    }

    Swingup_MPC_PresolveWorkingSet(solution, memspace, workingset, qrmanager);
    if (solution->state < 0) {
    } else {
      guard1 = true;
    }
  } else {
    solution->state = 82;
    guard1 = true;
  }

  if (guard1) {
    solution->iterations = 0;
    solution->maxConstr = Swing_maxConstraintViolation_l2(workingset,
      solution->xstar.data);
    if (solution->maxConstr > 1.0E-6) {
      Swingup_MPC_phaseone(H, f_data, solution, memspace, workingset, qrmanager,
                           cholmanager, objective, options, runTimeOptions);
      if (solution->state == 0) {
      } else {
        solution->maxConstr = Swing_maxConstraintViolation_l2(workingset,
          solution->xstar.data);
        if (solution->maxConstr > 1.0E-6) {
          idx = workingset->mConstrMax;
          for (nVar = 0; nVar < idx; nVar++) {
            solution->lambda.data[nVar] = 0.0;
          }

          solution->fstar = Swingup_MPC_computeFval(objective,
            memspace->workspace_double, H, f_data, solution->xstar.data);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            if (solution->searchDir.size - 1 >= 0) {
              memcpy(&y_data[0], &solution->searchDir.data[0], (uint32_T)
                     solution->searchDir.size * sizeof(real_T));
            }

            if ((uint16_T)nVar - 1 >= 0) {
              memcpy(&y_data[0], &solution->xstar.data[0], (uint16_T)nVar *
                     sizeof(real_T));
            }

            if (solution->searchDir.size - 1 >= 0) {
              memcpy(&solution->searchDir.data[0], &y_data[0], (uint32_T)
                     solution->searchDir.size * sizeof(real_T));
            }

            Swingup_MPC_PresolveWorkingSet(solution, memspace, workingset,
              qrmanager);
            maxConstr_new = Swing_maxConstraintViolation_l2(workingset,
              solution->xstar.data);
            if (maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = maxConstr_new;
              if (solution->xstar.size - 1 >= 0) {
                memcpy(&y_data[0], &solution->xstar.data[0], (uint32_T)
                       solution->xstar.size * sizeof(real_T));
              }

              if ((uint16_T)nVar - 1 >= 0) {
                memcpy(&y_data[0], &solution->searchDir.data[0], (uint16_T)nVar *
                       sizeof(real_T));
              }

              if (solution->xstar.size - 1 >= 0) {
                memcpy(&solution->xstar.data[0], &y_data[0], (uint32_T)
                       solution->xstar.size * sizeof(real_T));
              }
            }
          }

          Swingup_MPC_iterate(H, f_data, solution, memspace, workingset,
                              qrmanager, cholmanager, objective,
                              options->SolverName, options->StepTolerance,
                              options->ObjectiveLimit,
                              runTimeOptions->MaxIterations);
        }
      }
    } else {
      Swingup_MPC_iterate(H, f_data, solution, memspace, workingset, qrmanager,
                          cholmanager, objective, options->SolverName,
                          options->StepTolerance, options->ObjectiveLimit,
                          runTimeOptions->MaxIterations);
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_addAeqConstr(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *obj,
  int32_T idx_local)
{
  int32_T c;
  int32_T iAeq0;
  int32_T iAw0;
  int32_T iAw0_tmp;
  int32_T totalEq;
  totalEq = obj->nWConstr[0] + obj->nWConstr[1];
  if ((obj->nActiveConstr == totalEq) && (idx_local > obj->nWConstr[1])) {
    obj->nWConstr[1]++;
    obj->isActiveConstr.data[(obj->isActiveIdx[1] + idx_local) - 2] = true;
    obj->nActiveConstr++;
    obj->Wid.data[obj->nActiveConstr - 1] = 2;
    obj->Wlocalidx.data[obj->nActiveConstr - 1] = idx_local;
    iAeq0 = (idx_local - 1) * obj->ldA;
    iAw0 = (obj->nActiveConstr - 1) * obj->ldA;
    iAw0_tmp = (uint8_T)obj->nVar;
    for (totalEq = 0; totalEq < iAw0_tmp; totalEq++) {
      obj->ATwset->data[iAw0 + totalEq] = obj->Aeq->data[iAeq0 + totalEq];
    }

    obj->bwset.data[obj->nActiveConstr - 1] = obj->beq[idx_local - 1];
  } else {
    obj->nActiveConstr++;
    iAw0 = obj->nActiveConstr - 1;
    obj->Wid.data[obj->nActiveConstr - 1] = obj->Wid.data[totalEq];
    obj->Wlocalidx.data[iAw0] = obj->Wlocalidx.data[totalEq];
    iAw0_tmp = (uint8_T)obj->nVar;
    for (iAeq0 = 0; iAeq0 < iAw0_tmp; iAeq0++) {
      obj->ATwset->data[iAeq0 + obj->ldA * iAw0] = obj->ATwset->data[obj->ldA *
        totalEq + iAeq0];
    }

    obj->bwset.data[iAw0] = obj->bwset.data[totalEq];
    obj->nWConstr[1]++;
    obj->isActiveConstr.data[(obj->isActiveIdx[1] + idx_local) - 2] = true;
    obj->Wid.data[totalEq] = 2;
    obj->Wlocalidx.data[totalEq] = idx_local;
    iAeq0 = (idx_local - 1) * obj->ldA;
    iAw0 = obj->ldA * totalEq;
    c = (uint8_T)obj->nVar;
    for (iAw0_tmp = 0; iAw0_tmp < c; iAw0_tmp++) {
      obj->ATwset->data[iAw0 + iAw0_tmp] = obj->Aeq->data[iAeq0 + iAw0_tmp];
    }

    obj->bwset.data[totalEq] = obj->beq[idx_local - 1];
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static boolean_T Swingup_MPC_soc(const real_T Hessian[1936], const real_T
  grad_data[], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, const somzaGboVhDG7PNQS6E98jD_Swing_T *qpoptions)
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  somzaGboVhDG7PNQS6E98jD_Swing_T qpoptions_0;
  somzaGboVhDG7PNQS6E98jD_Swing_T qpoptions_1;
  real_T b_c;
  int32_T idxIneqOffset;
  int32_T idx_Aineq;
  int32_T idx_lower;
  int32_T ix;
  int32_T iy;
  int32_T mConstrMax;
  int32_T mLB;
  int32_T n;
  int32_T nVar;
  int32_T nWIneq_old;
  int32_T nWLower_old;
  int32_T nWUpper_old;
  boolean_T success;
  nWIneq_old = WorkingSet->nWConstr[2];
  nWLower_old = WorkingSet->nWConstr[3];
  nWUpper_old = WorkingSet->nWConstr[4];
  nVar = WorkingSet->nVar;
  mConstrMax = WorkingSet->mConstrMax;
  mLB = (uint8_T)WorkingSet->nVar - 1;
  for (idxIneqOffset = 0; idxIneqOffset <= mLB; idxIneqOffset++) {
    TrialState->xstarsqp[idxIneqOffset] = TrialState->xstarsqp_old[idxIneqOffset];
    TrialState->socDirection.data[idxIneqOffset] = TrialState->
      xstar.data[idxIneqOffset];
  }

  if ((uint16_T)WorkingSet->mConstrMax - 1 >= 0) {
    memcpy(&TrialState->lambdaStopTest.data[0], &TrialState->lambda.data[0],
           (uint16_T)WorkingSet->mConstrMax * sizeof(real_T));
  }

  idxIneqOffset = WorkingSet->isActiveIdx[2];
  for (mLB = 0; mLB <= 38; mLB += 2) {
    tmp_1 = _mm_loadu_pd(&TrialState->cEq[mLB]);
    _mm_storeu_pd(&WorkingSet->beq[mLB], _mm_mul_pd(tmp_1, _mm_set1_pd(-1.0)));
  }

  ix = WorkingSet->ldA;
  iy = 0;
  n = WorkingSet->ldA * 39 + 1;
  for (mLB = 1; ix < 0 ? mLB >= n : mLB <= n; mLB += ix) {
    b_c = 0.0;
    idx_lower = (mLB + WorkingSet->nVar) - 1;
    for (idx_Aineq = mLB; idx_Aineq <= idx_lower; idx_Aineq++) {
      b_c += WorkingSet->Aeq->data[idx_Aineq - 1] * TrialState->
        searchDir.data[idx_Aineq - mLB];
    }

    WorkingSet->beq[iy] += b_c;
    iy++;
  }

  for (mLB = 0; mLB < 40; mLB++) {
    WorkingSet->bwset.data[WorkingSet->sizes[0] + mLB] = WorkingSet->beq[mLB];
  }

  if (WorkingSet->sizes[2] > 0) {
    idx_Aineq = (uint8_T)WorkingSet->sizes[2];
    iy = ((uint8_T)WorkingSet->sizes[2] / 2) << 1;
    n = iy - 2;
    for (mLB = 0; mLB <= n; mLB += 2) {
      tmp_1 = _mm_loadu_pd(&TrialState->cIneq.data[mLB]);
      _mm_storeu_pd(&WorkingSet->bineq.data[mLB], _mm_mul_pd(tmp_1, _mm_set1_pd(
        -1.0)));
    }

    for (mLB = iy; mLB < idx_Aineq; mLB++) {
      WorkingSet->bineq.data[mLB] = -TrialState->cIneq.data[mLB];
    }

    ix = WorkingSet->ldA;
    iy = 0;
    n = (WorkingSet->sizes[2] - 1) * WorkingSet->ldA + 1;
    for (mLB = 1; ix < 0 ? mLB >= n : mLB <= n; mLB += ix) {
      b_c = 0.0;
      idx_lower = (mLB + WorkingSet->nVar) - 1;
      for (idx_Aineq = mLB; idx_Aineq <= idx_lower; idx_Aineq++) {
        b_c += WorkingSet->Aineq->data[idx_Aineq - 1] *
          TrialState->searchDir.data[idx_Aineq - mLB];
      }

      WorkingSet->bineq.data[iy] += b_c;
      iy++;
    }

    idx_Aineq = 1;
    idx_lower = WorkingSet->sizes[2] + 1;
    iy = (WorkingSet->sizes[2] + WorkingSet->sizes[3]) + 1;
    n = WorkingSet->nActiveConstr;
    for (mLB = idxIneqOffset; mLB <= n; mLB++) {
      switch (WorkingSet->Wid.data[mLB - 1]) {
       case 3:
        ix = idx_Aineq;
        idx_Aineq++;
        WorkingSet->bwset.data[mLB - 1] = WorkingSet->bineq.data
          [WorkingSet->Wlocalidx.data[mLB - 1] - 1];
        break;

       case 4:
        ix = idx_lower;
        idx_lower++;
        break;

       default:
        ix = iy;
        iy++;
        break;
      }

      TrialState->workingset_old.data[ix - 1] = WorkingSet->Wlocalidx.data[mLB -
        1];
    }
  }

  memcpy(&TrialState->xstar.data[0], &TrialState->xstarsqp[0], (uint8_T)
         WorkingSet->nVar * sizeof(real_T));
  qpoptions_0 = *qpoptions;
  qpoptions_1 = *qpoptions;
  Swingup_MPC_driver_e(Hessian, grad_data, TrialState, memspace, WorkingSet,
                       QRManager, CholManager, QPObjective, &qpoptions_0,
                       &qpoptions_1);
  while ((WorkingSet->mEqRemoved > 0) && (WorkingSet->indexEqRemoved
          [WorkingSet->mEqRemoved - 1] >= 1)) {
    Swingup_MPC_addAeqConstr(WorkingSet, WorkingSet->indexEqRemoved
      [WorkingSet->mEqRemoved - 1]);
    WorkingSet->mEqRemoved--;
  }

  mLB = (uint8_T)nVar;
  iy = ((uint8_T)nVar / 2) << 1;
  n = iy - 2;
  for (idxIneqOffset = 0; idxIneqOffset <= n; idxIneqOffset += 2) {
    tmp_1 = _mm_loadu_pd(&TrialState->socDirection.data[idxIneqOffset]);
    tmp = _mm_loadu_pd(&TrialState->xstar.data[idxIneqOffset]);
    tmp_0 = _mm_loadu_pd(&TrialState->socDirection.data[idxIneqOffset]);
    _mm_storeu_pd(&TrialState->socDirection.data[idxIneqOffset], _mm_sub_pd(tmp,
      tmp_0));
    _mm_storeu_pd(&TrialState->xstar.data[idxIneqOffset], tmp_1);
  }

  for (idxIneqOffset = iy; idxIneqOffset < mLB; idxIneqOffset++) {
    b_c = TrialState->socDirection.data[idxIneqOffset];
    TrialState->socDirection.data[idxIneqOffset] = TrialState->
      xstar.data[idxIneqOffset] - TrialState->socDirection.data[idxIneqOffset];
    TrialState->xstar.data[idxIneqOffset] = b_c;
  }

  success = (Swingup_MPC_xnrm2_l(nVar, TrialState->socDirection.data) <= 2.0 *
             Swingup_MPC_xnrm2_l(nVar, TrialState->xstar.data));
  idxIneqOffset = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  for (nVar = 0; nVar <= 38; nVar += 2) {
    tmp_1 = _mm_loadu_pd(&TrialState->cEq[nVar]);
    _mm_storeu_pd(&WorkingSet->beq[nVar], _mm_mul_pd(tmp_1, _mm_set1_pd(-1.0)));
  }

  for (nVar = 0; nVar < 40; nVar++) {
    WorkingSet->bwset.data[WorkingSet->sizes[0] + nVar] = WorkingSet->beq[nVar];
  }

  if (WorkingSet->sizes[2] > 0) {
    idx_Aineq = (uint8_T)WorkingSet->sizes[2];
    iy = ((uint8_T)WorkingSet->sizes[2] / 2) << 1;
    n = iy - 2;
    for (nVar = 0; nVar <= n; nVar += 2) {
      tmp_1 = _mm_loadu_pd(&TrialState->cIneq.data[nVar]);
      _mm_storeu_pd(&WorkingSet->bineq.data[nVar], _mm_mul_pd(tmp_1, _mm_set1_pd
        (-1.0)));
    }

    for (nVar = iy; nVar < idx_Aineq; nVar++) {
      WorkingSet->bineq.data[nVar] = -TrialState->cIneq.data[nVar];
    }

    if (!success) {
      idx_Aineq = (WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1]) + 1;
      idx_lower = WorkingSet->nActiveConstr;
      for (nVar = idx_Aineq; nVar <= idx_lower; nVar++) {
        WorkingSet->isActiveConstr.data[(WorkingSet->isActiveIdx
          [WorkingSet->Wid.data[nVar - 1] - 1] + WorkingSet->Wlocalidx.data[nVar
          - 1]) - 2] = false;
      }

      WorkingSet->nWConstr[2] = 0;
      WorkingSet->nWConstr[3] = 0;
      WorkingSet->nWConstr[4] = 0;
      WorkingSet->nActiveConstr = WorkingSet->nWConstr[0] + WorkingSet->
        nWConstr[1];
      for (nVar = 0; nVar < nWIneq_old; nVar++) {
        Swingup_MPC_addAineqConstr(WorkingSet, TrialState->
          workingset_old.data[nVar]);
      }

      for (nWIneq_old = 0; nWIneq_old < nWLower_old; nWIneq_old++) {
        Swin_addBoundToActiveSetMatrix_(WorkingSet, 4,
          TrialState->workingset_old.data[nWIneq_old + idxIneqOffset]);
      }

      for (nWLower_old = 0; nWLower_old < nWUpper_old; nWLower_old++) {
        Swin_addBoundToActiveSetMatrix_(WorkingSet, 5,
          TrialState->workingset_old.data[(nWLower_old + idxIneqOffset) + mLB]);
      }
    }
  }

  if (!success) {
    if ((uint16_T)mConstrMax - 1 >= 0) {
      memcpy(&TrialState->lambda.data[0], &TrialState->lambdaStopTest.data[0],
             (uint16_T)mConstrMax * sizeof(real_T));
    }
  } else {
    Swingup_MPC_sortLambdaQP(TrialState->lambda.data, WorkingSet->nActiveConstr,
      WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid.data,
      WorkingSet->Wlocalidx.data, memspace->workspace_double);
  }

  return success;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_normal(const real_T Hessian[1936], const real_T
  grad_data[], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Swing_T *MeritFunction,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, const somzaGboVhDG7PNQS6E98jD_Swing_T *qpoptions)
{
  somzaGboVhDG7PNQS6E98jD_Swing_T qpoptions_0;
  somzaGboVhDG7PNQS6E98jD_Swing_T qpoptions_1;
  real_T constrViolationEq;
  real_T constrViolationIneq;
  real_T penaltyParamTrial;
  int32_T b;
  int32_T k;
  boolean_T nonlinEqRemoved;
  qpoptions_0 = *qpoptions;
  qpoptions_1 = *qpoptions;
  Swingup_MPC_driver_e(Hessian, grad_data, TrialState, memspace, WorkingSet,
                       QRManager, CholManager, QPObjective, &qpoptions_0,
                       &qpoptions_1);
  if (TrialState->state > 0) {
    penaltyParamTrial = MeritFunction->penaltyParam;
    constrViolationEq = 0.0;
    for (k = 0; k < 40; k++) {
      constrViolationEq += fabs(TrialState->cEq[k]);
    }

    constrViolationIneq = 0.0;
    b = (uint8_T)WorkingSet->sizes[2];
    for (k = 0; k < b; k++) {
      if (TrialState->cIneq.data[k] > 0.0) {
        constrViolationIneq += TrialState->cIneq.data[k];
      }
    }

    constrViolationEq += constrViolationIneq;
    constrViolationIneq = MeritFunction->linearizedConstrViol;
    MeritFunction->linearizedConstrViol = 0.0;
    constrViolationIneq += constrViolationEq;
    if ((constrViolationIneq > 2.2204460492503131E-16) && (TrialState->fstar >
         0.0)) {
      if (TrialState->sqpFval == 0.0) {
        penaltyParamTrial = 1.0;
      } else {
        penaltyParamTrial = 1.5;
      }

      penaltyParamTrial = penaltyParamTrial * TrialState->fstar /
        constrViolationIneq;
    }

    if (penaltyParamTrial < MeritFunction->penaltyParam) {
      MeritFunction->phi = penaltyParamTrial * constrViolationEq +
        TrialState->sqpFval;
      if (((MeritFunction->initConstrViolationEq +
            MeritFunction->initConstrViolationIneq) * penaltyParamTrial +
           MeritFunction->initFval) - MeritFunction->phi > (real_T)
          MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) > TrialState->sqpIterations)
        {
          MeritFunction->threshold *= 10.0;
        }

        if (penaltyParamTrial >= 1.0E-10) {
          MeritFunction->penaltyParam = penaltyParamTrial;
        } else {
          MeritFunction->penaltyParam = 1.0E-10;
        }
      } else {
        MeritFunction->phi = MeritFunction->penaltyParam * constrViolationEq +
          TrialState->sqpFval;
      }
    } else {
      if (penaltyParamTrial >= 1.0E-10) {
        MeritFunction->penaltyParam = penaltyParamTrial;
      } else {
        MeritFunction->penaltyParam = 1.0E-10;
      }

      MeritFunction->phi = MeritFunction->penaltyParam * constrViolationEq +
        TrialState->sqpFval;
    }

    constrViolationEq = TrialState->fstar - MeritFunction->penaltyParam *
      constrViolationEq;
    if (constrViolationEq <= 0.0) {
      MeritFunction->phiPrimePlus = constrViolationEq;
    } else {
      MeritFunction->phiPrimePlus = 0.0;
    }
  }

  Swingup_MPC_sortLambdaQP(TrialState->lambda.data, WorkingSet->nActiveConstr,
    WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid.data,
    WorkingSet->Wlocalidx.data, memspace->workspace_double);
  nonlinEqRemoved = (WorkingSet->mEqRemoved > 0);
  while ((WorkingSet->mEqRemoved > 0) && (WorkingSet->indexEqRemoved
          [WorkingSet->mEqRemoved - 1] >= 1)) {
    Swingup_MPC_addAeqConstr(WorkingSet, WorkingSet->indexEqRemoved
      [WorkingSet->mEqRemoved - 1]);
    WorkingSet->mEqRemoved--;
  }

  if (nonlinEqRemoved) {
    for (k = 0; k < 40; k++) {
      WorkingSet->Wlocalidx.data[WorkingSet->sizes[0] + k] = k + 1;
    }
  }
}

static void Swingup_MPC_emxCopy_real_T(emxArray_real_T_Swingup_MPC_T **dst,
  emxArray_real_T_Swingup_MPC_T * const *src)
{
  int32_T i;
  int32_T numElDst;
  int32_T numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }

  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }

  Swingu_emxEnsureCapacity_real_T(*dst, numElDst);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

static void Swingup_MPC_emxCopy_real_T_120(emxArray_real_T_120_Swingup_M_T *dst,
  const emxArray_real_T_120_Swingup_M_T *src)
{
  int32_T i;
  int32_T numElSrc;
  numElSrc = 1;
  for (i = 0; i < 1; i++) {
    numElSrc *= src->size;
  }

  for (i = 0; i < 1; i++) {
    dst->size = src->size;
  }

  for (i = 0; i < numElSrc; i++) {
    dst->data[i] = src->data[i];
  }
}

static void Swingup_MP_emxCopyMatrix_real_T(real_T dst[40], const real_T src[40])
{
  int32_T i;
  for (i = 0; i < 40; i++) {
    dst[i] = src[i];
  }
}

static void Swingup_MPC_emxCopy_real_T_245(emxArray_real_T_245_Swingup_M_T *dst,
  const emxArray_real_T_245_Swingup_M_T *src)
{
  int32_T i;
  int32_T numElSrc;
  numElSrc = 1;
  for (i = 0; i < 1; i++) {
    numElSrc *= src->size;
  }

  for (i = 0; i < 1; i++) {
    dst->size = src->size;
  }

  for (i = 0; i < numElSrc; i++) {
    dst->data[i] = src->data[i];
  }
}

static void Swingup_MPC_emxCopy_int32_T_245(emxArray_int32_T_245_Swingup__T *dst,
  const emxArray_int32_T_245_Swingup__T *src)
{
  int32_T i;
  int32_T numElSrc;
  numElSrc = 1;
  for (i = 0; i < 1; i++) {
    numElSrc *= src->size;
  }

  for (i = 0; i < 1; i++) {
    dst->size = src->size;
  }

  for (i = 0; i < numElSrc; i++) {
    dst->data[i] = src->data[i];
  }
}

static void Swingup_M_emxCopyMatrix_int32_T(int32_T dst[40], const int32_T src
  [40])
{
  int32_T i;
  for (i = 0; i < 40; i++) {
    dst[i] = src[i];
  }
}

static void Swingup_MPC_emxCopy_real_T_449(emxArray_real_T_449_Swingup_M_T *dst,
  const emxArray_real_T_449_Swingup_M_T *src)
{
  int32_T i;
  int32_T numElSrc;
  numElSrc = 1;
  for (i = 0; i < 1; i++) {
    numElSrc *= src->size;
  }

  for (i = 0; i < 1; i++) {
    dst->size = src->size;
  }

  for (i = 0; i < numElSrc; i++) {
    dst->data[i] = src->data[i];
  }
}

static void Swingup__emxCopyMatrix_int32_T1(int32_T dst[5], const int32_T src[5])
{
  int32_T i;
  for (i = 0; i < 5; i++) {
    dst[i] = src[i];
  }
}

static void Swingup__emxCopyMatrix_int32_T2(int32_T dst[6], const int32_T src[6])
{
  int32_T i;
  for (i = 0; i < 6; i++) {
    dst[i] = src[i];
  }
}

static void Swingup_M_emxCopy_boolean_T_449(emxArray_boolean_T_449_Swingu_T *dst,
  const emxArray_boolean_T_449_Swingu_T *src)
{
  int32_T i;
  int32_T numElSrc;
  numElSrc = 1;
  for (i = 0; i < 1; i++) {
    numElSrc *= src->size;
  }

  for (i = 0; i < 1; i++) {
    dst->size = src->size;
  }

  for (i = 0; i < numElSrc; i++) {
    dst->data[i] = src->data[i];
  }
}

static void Swingup_MPC_emxCopy_int32_T_449(emxArray_int32_T_449_Swingup__T *dst,
  const emxArray_int32_T_449_Swingup__T *src)
{
  int32_T i;
  int32_T numElSrc;
  numElSrc = 1;
  for (i = 0; i < 1; i++) {
    numElSrc *= src->size;
  }

  for (i = 0; i < 1; i++) {
    dst->size = src->size;
  }

  for (i = 0; i < numElSrc; i++) {
    dst->data[i] = src->data[i];
  }
}

static void emxCopyStruct_s_pBvMsf7fBJa4zdf(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *dst,
  const s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T *src)
{
  dst->mConstr = src->mConstr;
  dst->mConstrOrig = src->mConstrOrig;
  dst->mConstrMax = src->mConstrMax;
  dst->nVar = src->nVar;
  dst->nVarOrig = src->nVarOrig;
  dst->nVarMax = src->nVarMax;
  dst->ldA = src->ldA;
  Swingup_MPC_emxCopy_real_T(&dst->Aineq, &src->Aineq);
  Swingup_MPC_emxCopy_real_T_120(&dst->bineq, &src->bineq);
  Swingup_MPC_emxCopy_real_T(&dst->Aeq, &src->Aeq);
  Swingup_MP_emxCopyMatrix_real_T(dst->beq, src->beq);
  Swingup_MPC_emxCopy_real_T_245(&dst->lb, &src->lb);
  Swingup_MPC_emxCopy_real_T_245(&dst->ub, &src->ub);
  Swingup_MPC_emxCopy_int32_T_245(&dst->indexLB, &src->indexLB);
  Swingup_MPC_emxCopy_int32_T_245(&dst->indexUB, &src->indexUB);
  Swingup_MPC_emxCopy_int32_T_245(&dst->indexFixed, &src->indexFixed);
  dst->mEqRemoved = src->mEqRemoved;
  Swingup_M_emxCopyMatrix_int32_T(dst->indexEqRemoved, src->indexEqRemoved);
  Swingup_MPC_emxCopy_real_T(&dst->ATwset, &src->ATwset);
  Swingup_MPC_emxCopy_real_T_449(&dst->bwset, &src->bwset);
  dst->nActiveConstr = src->nActiveConstr;
  Swingup_MPC_emxCopy_real_T_449(&dst->maxConstrWorkspace,
    &src->maxConstrWorkspace);
  Swingup__emxCopyMatrix_int32_T1(dst->sizes, src->sizes);
  Swingup__emxCopyMatrix_int32_T1(dst->sizesNormal, src->sizesNormal);
  Swingup__emxCopyMatrix_int32_T1(dst->sizesPhaseOne, src->sizesPhaseOne);
  Swingup__emxCopyMatrix_int32_T1(dst->sizesRegularized, src->sizesRegularized);
  Swingup__emxCopyMatrix_int32_T1(dst->sizesRegPhaseOne, src->sizesRegPhaseOne);
  Swingup__emxCopyMatrix_int32_T2(dst->isActiveIdx, src->isActiveIdx);
  Swingup__emxCopyMatrix_int32_T2(dst->isActiveIdxNormal, src->isActiveIdxNormal);
  Swingup__emxCopyMatrix_int32_T2(dst->isActiveIdxPhaseOne,
    src->isActiveIdxPhaseOne);
  Swingup__emxCopyMatrix_int32_T2(dst->isActiveIdxRegularized,
    src->isActiveIdxRegularized);
  Swingup__emxCopyMatrix_int32_T2(dst->isActiveIdxRegPhaseOne,
    src->isActiveIdxRegPhaseOne);
  Swingup_M_emxCopy_boolean_T_449(&dst->isActiveConstr, &src->isActiveConstr);
  Swingup_MPC_emxCopy_int32_T_449(&dst->Wid, &src->Wid);
  Swingup_MPC_emxCopy_int32_T_449(&dst->Wlocalidx, &src->Wlocalidx);
  Swingup__emxCopyMatrix_int32_T1(dst->nWConstr, src->nWConstr);
  dst->probType = src->probType;
  dst->SLACK0 = src->SLACK0;
}

static void emxFreeStruct_s_pBvMsf7fBJa4zdf(s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *pStruct)
{
  Swingup_MPC_emxFree_real_T(&pStruct->Aineq);
  Swingup_MPC_emxFree_real_T(&pStruct->Aeq);
  Swingup_MPC_emxFree_real_T(&pStruct->ATwset);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_relaxed(const real_T Hessian[1936], const real_T
  grad_data[], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Swing_T *MeritFunction,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, somzaGboVhDG7PNQS6E98jD_Swing_T *qpoptions)
{
  somzaGboVhDG7PNQS6E98jD_Swing_T qpoptions_0;
  somzaGboVhDG7PNQS6E98jD_Swing_T qpoptions_1;
  real_T beta;
  real_T qpfvalQuadExcess;
  real_T s;
  real_T smax;
  real_T y;
  int32_T idx_max;
  int32_T ix;
  int32_T mFiniteLBOrig;
  int32_T mLBOrig;
  int32_T nVarOrig;
  int32_T tmp;
  boolean_T b_tf;
  boolean_T tf;
  nVarOrig = WorkingSet->nVar - 1;
  beta = 0.0;
  idx_max = (uint8_T)WorkingSet->nVar;
  for (mFiniteLBOrig = 0; mFiniteLBOrig < idx_max; mFiniteLBOrig++) {
    beta += Hessian[44 * mFiniteLBOrig + mFiniteLBOrig];
  }

  beta /= (real_T)WorkingSet->nVar;
  if (TrialState->sqpIterations <= 1) {
    mLBOrig = QPObjective->nvar;
    if (QPObjective->nvar < 1) {
      idx_max = 0;
    } else {
      idx_max = 1;
      if (QPObjective->nvar > 1) {
        smax = fabs(grad_data[0]);
        for (mFiniteLBOrig = 2; mFiniteLBOrig <= mLBOrig; mFiniteLBOrig++) {
          s = fabs(grad_data[mFiniteLBOrig - 1]);
          if (s > smax) {
            idx_max = mFiniteLBOrig;
            smax = s;
          }
        }
      }
    }

    s = fabs(grad_data[idx_max - 1]);
    if ((s <= 1.0) || rtIsNaN(s)) {
      s = 1.0;
    }

    smax = 100.0 * s;
  } else {
    mLBOrig = WorkingSet->mConstr;
    if (WorkingSet->mConstr < 1) {
      idx_max = 0;
    } else {
      idx_max = 1;
      if (WorkingSet->mConstr > 1) {
        smax = fabs(TrialState->lambdasqp.data[0]);
        for (mFiniteLBOrig = 2; mFiniteLBOrig <= mLBOrig; mFiniteLBOrig++) {
          s = fabs(TrialState->lambdasqp.data[mFiniteLBOrig - 1]);
          if (s > smax) {
            idx_max = mFiniteLBOrig;
            smax = s;
          }
        }
      }
    }

    smax = fabs(TrialState->lambdasqp.data[idx_max - 1]);
  }

  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->beta = beta;
  QPObjective->rho = smax;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 4;
  emxInitStruct_s_pBvMsf7fBJa4zdf(&Swingup_MPC_B.b_WorkingSet);
  emxCopyStruct_s_pBvMsf7fBJa4zdf(&Swingup_MPC_B.b_WorkingSet, WorkingSet);
  Swingup_MPC_setProblemType(&Swingup_MPC_B.b_WorkingSet, 2);
  idx_max = Swingup_MPC_B.b_WorkingSet.sizes[2] + 1;
  mLBOrig = (Swingup_MPC_B.b_WorkingSet.sizes[3] -
             Swingup_MPC_B.b_WorkingSet.sizes[2]) - 80;
  ix = (uint16_T)Swingup_MPC_B.b_WorkingSet.sizes[2];
  for (mFiniteLBOrig = 0; mFiniteLBOrig < ix; mFiniteLBOrig++) {
    memspace->workspace_double->data[mFiniteLBOrig] =
      Swingup_MPC_B.b_WorkingSet.bineq.data[mFiniteLBOrig];
  }

  Swingup_MPC_xgemv_nbnhgmsyw(WorkingSet->nVar,
    Swingup_MPC_B.b_WorkingSet.sizes[2], Swingup_MPC_B.b_WorkingSet.Aineq,
    Swingup_MPC_B.b_WorkingSet.ldA, TrialState->xstar.data,
    memspace->workspace_double);
  ix = (uint8_T)Swingup_MPC_B.b_WorkingSet.sizes[2];
  for (mFiniteLBOrig = 0; mFiniteLBOrig < ix; mFiniteLBOrig++) {
    TrialState->xstar.data[(nVarOrig + mFiniteLBOrig) + 1] = (real_T)
      (memspace->workspace_double->data[mFiniteLBOrig] > 0.0) *
      memspace->workspace_double->data[mFiniteLBOrig];
  }

  for (mFiniteLBOrig = 0; mFiniteLBOrig < 40; mFiniteLBOrig++) {
    memspace->workspace_double->data[mFiniteLBOrig] =
      Swingup_MPC_B.b_WorkingSet.beq[mFiniteLBOrig];
  }

  Swingup_MPC_xgemv_nbnhgmsyw(WorkingSet->nVar, 40,
    Swingup_MPC_B.b_WorkingSet.Aeq, Swingup_MPC_B.b_WorkingSet.ldA,
    TrialState->xstar.data, memspace->workspace_double);
  for (mFiniteLBOrig = 0; mFiniteLBOrig < 40; mFiniteLBOrig++) {
    ix = idx_max + mFiniteLBOrig;
    if (memspace->workspace_double->data[mFiniteLBOrig] <= 0.0) {
      TrialState->xstar.data[nVarOrig + ix] = 0.0;
      TrialState->xstar.data[(nVarOrig + ix) + 40] = -memspace->
        workspace_double->data[mFiniteLBOrig];
      Swin_addBoundToActiveSetMatrix_(&Swingup_MPC_B.b_WorkingSet, 4, mLBOrig +
        ix);
      if (memspace->workspace_double->data[mFiniteLBOrig] >= -1.0E-6) {
        Swin_addBoundToActiveSetMatrix_(&Swingup_MPC_B.b_WorkingSet, 4, (mLBOrig
          + ix) + 40);
      }
    } else {
      tmp = nVarOrig + ix;
      TrialState->xstar.data[tmp] = memspace->workspace_double->
        data[mFiniteLBOrig];
      TrialState->xstar.data[tmp + 40] = 0.0;
      Swin_addBoundToActiveSetMatrix_(&Swingup_MPC_B.b_WorkingSet, 4, (mLBOrig +
        ix) + 40);
      if (memspace->workspace_double->data[mFiniteLBOrig] <= 1.0E-6) {
        Swin_addBoundToActiveSetMatrix_(&Swingup_MPC_B.b_WorkingSet, 4, mLBOrig
          + ix);
      }
    }
  }

  nVarOrig = qpoptions->MaxIterations;
  qpoptions->MaxIterations = (qpoptions->MaxIterations +
    Swingup_MPC_B.b_WorkingSet.nVar) - WorkingSet->nVar;
  qpoptions_0 = *qpoptions;
  qpoptions_1 = *qpoptions;
  Swingup_MPC_driver_e(Hessian, grad_data, TrialState, memspace,
                       &Swingup_MPC_B.b_WorkingSet, QRManager, CholManager,
                       QPObjective, &qpoptions_0, &qpoptions_1);
  qpoptions->MaxIterations = nVarOrig;
  idx_max = Swingup_MPC_B.b_WorkingSet.sizes[3] - 81;
  nVarOrig = 0;
  for (mFiniteLBOrig = 0; mFiniteLBOrig < 40; mFiniteLBOrig++) {
    mLBOrig = (Swingup_MPC_B.b_WorkingSet.isActiveIdx[3] + idx_max) +
      mFiniteLBOrig;
    tf = Swingup_MPC_B.b_WorkingSet.isActiveConstr.data[mLBOrig];
    b_tf = Swingup_MPC_B.b_WorkingSet.isActiveConstr.data[mLBOrig + 40];
    memspace->workspace_int.data[mFiniteLBOrig] = tf;
    memspace->workspace_int.data[mFiniteLBOrig + 40] = b_tf;
    nVarOrig = (nVarOrig + tf) + b_tf;
  }

  mLBOrig = (uint8_T)Swingup_MPC_B.b_WorkingSet.sizes[2];
  for (mFiniteLBOrig = 0; mFiniteLBOrig < mLBOrig; mFiniteLBOrig++) {
    tf = Swingup_MPC_B.b_WorkingSet.isActiveConstr.data
      [((Swingup_MPC_B.b_WorkingSet.isActiveIdx[3] + idx_max) -
        Swingup_MPC_B.b_WorkingSet.sizes[2]) + mFiniteLBOrig];
    memspace->workspace_int.data[mFiniteLBOrig + 80] = tf;
    nVarOrig += tf;
  }

  if (TrialState->state != -6) {
    idx_max = (Swingup_MPC_B.b_WorkingSet.nVarMax - WorkingSet->nVar) - 1;
    mLBOrig = WorkingSet->nVar;
    s = 0.0;
    qpfvalQuadExcess = 0.0;
    if (idx_max >= 1) {
      ix = WorkingSet->nVar + idx_max;
      for (mFiniteLBOrig = mLBOrig + 1; mFiniteLBOrig <= ix; mFiniteLBOrig++) {
        s += fabs(TrialState->xstar.data[mFiniteLBOrig - 1]);
      }

      idx_max = (uint8_T)idx_max;
      for (mFiniteLBOrig = 0; mFiniteLBOrig < idx_max; mFiniteLBOrig++) {
        qpfvalQuadExcess += TrialState->xstar.data[mLBOrig + mFiniteLBOrig] *
          TrialState->xstar.data[WorkingSet->nVar + mFiniteLBOrig];
      }
    }

    beta = (TrialState->fstar - smax * s) - beta / 2.0 * qpfvalQuadExcess;
    idx_max = WorkingSet->nVar + 1;
    mLBOrig = (WorkingSet->nVarMax - WorkingSet->nVar) - 1;
    smax = MeritFunction->penaltyParam;
    s = 0.0;
    for (mFiniteLBOrig = 0; mFiniteLBOrig < 40; mFiniteLBOrig++) {
      s += fabs(TrialState->cEq[mFiniteLBOrig]);
    }

    qpfvalQuadExcess = 0.0;
    ix = (uint8_T)WorkingSet->sizes[2];
    for (mFiniteLBOrig = 0; mFiniteLBOrig < ix; mFiniteLBOrig++) {
      if (TrialState->cIneq.data[mFiniteLBOrig] > 0.0) {
        qpfvalQuadExcess += TrialState->cIneq.data[mFiniteLBOrig];
      }
    }

    s += qpfvalQuadExcess;
    qpfvalQuadExcess = MeritFunction->linearizedConstrViol;
    y = 0.0;
    if (mLBOrig >= 1) {
      mLBOrig += WorkingSet->nVar;
      for (mFiniteLBOrig = idx_max; mFiniteLBOrig <= mLBOrig; mFiniteLBOrig++) {
        y += fabs(TrialState->xstar.data[mFiniteLBOrig - 1]);
      }
    }

    MeritFunction->linearizedConstrViol = y;
    qpfvalQuadExcess = (s + qpfvalQuadExcess) - y;
    if ((qpfvalQuadExcess > 2.2204460492503131E-16) && (beta > 0.0)) {
      if (TrialState->sqpFval == 0.0) {
        smax = 1.0;
      } else {
        smax = 1.5;
      }

      smax = smax * beta / qpfvalQuadExcess;
    }

    if (smax < MeritFunction->penaltyParam) {
      MeritFunction->phi = smax * s + TrialState->sqpFval;
      if (((MeritFunction->initConstrViolationEq +
            MeritFunction->initConstrViolationIneq) * smax +
           MeritFunction->initFval) - MeritFunction->phi > (real_T)
          MeritFunction->nPenaltyDecreases * MeritFunction->threshold) {
        MeritFunction->nPenaltyDecreases++;
        if ((MeritFunction->nPenaltyDecreases << 1) > TrialState->sqpIterations)
        {
          MeritFunction->threshold *= 10.0;
        }

        if (smax >= 1.0E-10) {
          MeritFunction->penaltyParam = smax;
        } else {
          MeritFunction->penaltyParam = 1.0E-10;
        }
      } else {
        MeritFunction->phi = MeritFunction->penaltyParam * s +
          TrialState->sqpFval;
      }
    } else {
      if (smax >= 1.0E-10) {
        MeritFunction->penaltyParam = smax;
      } else {
        MeritFunction->penaltyParam = 1.0E-10;
      }

      MeritFunction->phi = MeritFunction->penaltyParam * s + TrialState->sqpFval;
    }

    beta -= MeritFunction->penaltyParam * s;
    if (beta <= 0.0) {
      MeritFunction->phiPrimePlus = beta;
    } else {
      MeritFunction->phiPrimePlus = 0.0;
    }

    idx_max = Swingup_MPC_B.b_WorkingSet.isActiveIdx[1] - 1;
    for (mFiniteLBOrig = 0; mFiniteLBOrig < 40; mFiniteLBOrig++) {
      if ((memspace->workspace_int.data[mFiniteLBOrig] != 0) &&
          (memspace->workspace_int.data[mFiniteLBOrig + 40] != 0)) {
        tf = true;
      } else {
        tf = false;
      }

      mLBOrig = idx_max + mFiniteLBOrig;
      TrialState->lambda.data[mLBOrig] *= (real_T)tf;
    }

    idx_max = Swingup_MPC_B.b_WorkingSet.isActiveIdx[2];
    mLBOrig = Swingup_MPC_B.b_WorkingSet.nActiveConstr;
    for (mFiniteLBOrig = idx_max; mFiniteLBOrig <= mLBOrig; mFiniteLBOrig++) {
      if (Swingup_MPC_B.b_WorkingSet.Wid.data[mFiniteLBOrig - 1] == 3) {
        TrialState->lambda.data[mFiniteLBOrig - 1] *= (real_T)
          memspace->
          workspace_int.data[Swingup_MPC_B.b_WorkingSet.Wlocalidx.data[mFiniteLBOrig
          - 1] + 79];
      }
    }
  }

  emxInitStruct_s_pBvMsf7fBJa4zdf(&Swingup_MPC_B.c_WorkingSet);
  emxCopyStruct_s_pBvMsf7fBJa4zdf(&Swingup_MPC_B.c_WorkingSet,
    &Swingup_MPC_B.b_WorkingSet);
  mFiniteLBOrig = (Swingup_MPC_B.b_WorkingSet.sizes[3] -
                   Swingup_MPC_B.b_WorkingSet.sizes[2]) - 80;
  idx_max = Swingup_MPC_B.b_WorkingSet.nActiveConstr;
  while ((idx_max > Swingup_MPC_B.b_WorkingSet.sizes[0] + 40) && (nVarOrig > 0))
  {
    if ((Swingup_MPC_B.c_WorkingSet.Wid.data[idx_max - 1] == 4) &&
        (Swingup_MPC_B.c_WorkingSet.Wlocalidx.data[idx_max - 1] > mFiniteLBOrig))
    {
      beta = TrialState->lambda.data[Swingup_MPC_B.c_WorkingSet.nActiveConstr -
        1];
      TrialState->lambda.data[Swingup_MPC_B.c_WorkingSet.nActiveConstr - 1] =
        0.0;
      TrialState->lambda.data[idx_max - 1] = beta;
      Swingup_MPC_removeConstr(&Swingup_MPC_B.c_WorkingSet, idx_max);
      nVarOrig--;
    }

    idx_max--;
  }

  emxFreeStruct_s_pBvMsf7fBJa4zdf(&Swingup_MPC_B.b_WorkingSet);
  QPObjective->nvar = WorkingSet->nVar;
  QPObjective->hasLinear = true;
  QPObjective->objtype = 3;
  emxCopyStruct_s_pBvMsf7fBJa4zdf(WorkingSet, &Swingup_MPC_B.c_WorkingSet);
  emxFreeStruct_s_pBvMsf7fBJa4zdf(&Swingup_MPC_B.c_WorkingSet);
  Swingup_MPC_setProblemType(WorkingSet, 3);
  Swingup_MPC_sortLambdaQP(TrialState->lambda.data, WorkingSet->nActiveConstr,
    WorkingSet->sizes, WorkingSet->isActiveIdx, WorkingSet->Wid.data,
    WorkingSet->Wlocalidx.data, memspace->workspace_double);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static boolean_T Swingup_MPC_step_l(int32_T *STEP_TYPE, real_T Hessian[1936],
  const real_T lb[44], s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState,
  sG8JZ69axY52WWR6RKyApQC_Swing_T *MeritFunction,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, somzaGboVhDG7PNQS6E98jD_Swing_T *qpoptions)
{
  __m128d tmp;
  __m128d tmp_0;
  real_T y_data[449];
  real_T m_data[245];
  real_T nrmDirInf;
  real_T nrmGradInf;
  real_T u1;
  int32_T exitg1;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T loop_ub;
  int32_T nVar;
  int32_T vectorUB;
  boolean_T checkBoundViolation;
  boolean_T guard1;
  boolean_T stepSuccess;
  stepSuccess = true;
  checkBoundViolation = true;
  nVar = WorkingSet->nVar;
  if (*STEP_TYPE != 3) {
    memcpy(&TrialState->xstar.data[0], &TrialState->xstarsqp[0], (uint8_T)
           WorkingSet->nVar * sizeof(real_T));
  } else {
    if (TrialState->searchDir.size - 1 >= 0) {
      memcpy(&y_data[0], &TrialState->searchDir.data[0], (uint32_T)
             TrialState->searchDir.size * sizeof(real_T));
    }

    if ((uint16_T)WorkingSet->nVar - 1 >= 0) {
      memcpy(&y_data[0], &TrialState->xstar.data[0], (uint16_T)WorkingSet->nVar *
             sizeof(real_T));
    }

    if (TrialState->searchDir.size - 1 >= 0) {
      memcpy(&TrialState->searchDir.data[0], &y_data[0], (uint32_T)
             TrialState->searchDir.size * sizeof(real_T));
    }
  }

  do {
    exitg1 = 0;
    guard1 = false;
    switch (*STEP_TYPE) {
     case 1:
      Swingup_MPC_normal(Hessian, TrialState->grad.data, TrialState,
                         MeritFunction, memspace, WorkingSet, QRManager,
                         CholManager, QPObjective, qpoptions);
      if ((TrialState->state <= 0) && (TrialState->state != -6)) {
        *STEP_TYPE = 2;
      } else {
        if (TrialState->delta_x.size - 1 >= 0) {
          memcpy(&y_data[0], &TrialState->delta_x.data[0], (uint32_T)
                 TrialState->delta_x.size * sizeof(real_T));
        }

        if ((uint16_T)nVar - 1 >= 0) {
          memcpy(&y_data[0], &TrialState->xstar.data[0], (uint16_T)nVar * sizeof
                 (real_T));
        }

        if (TrialState->delta_x.size - 1 >= 0) {
          memcpy(&TrialState->delta_x.data[0], &y_data[0], (uint32_T)
                 TrialState->delta_x.size * sizeof(real_T));
        }

        guard1 = true;
      }
      break;

     case 2:
      idxStartIneq = (WorkingSet->nWConstr[0] + WorkingSet->nWConstr[1]) + 1;
      idxEndIneq = WorkingSet->nActiveConstr;
      for (loop_ub = idxStartIneq; loop_ub <= idxEndIneq; loop_ub++) {
        WorkingSet->isActiveConstr.data[(WorkingSet->isActiveIdx
          [WorkingSet->Wid.data[loop_ub - 1] - 1] + WorkingSet->
          Wlocalidx.data[loop_ub - 1]) - 2] = false;
      }

      WorkingSet->nWConstr[2] = 0;
      WorkingSet->nWConstr[3] = 0;
      WorkingSet->nWConstr[4] = 0;
      WorkingSet->nActiveConstr = WorkingSet->nWConstr[0] + WorkingSet->
        nWConstr[1];
      if (TrialState->xstar.size - 1 >= 0) {
        memcpy(&m_data[0], &TrialState->xstar.data[0], (uint32_T)
               TrialState->xstar.size * sizeof(real_T));
      }

      idxStartIneq = (uint16_T)WorkingSet->sizes[3];
      for (loop_ub = 0; loop_ub < idxStartIneq; loop_ub++) {
        nrmGradInf = WorkingSet->lb.data[WorkingSet->indexLB.data[loop_ub] - 1];
        if (-m_data[WorkingSet->indexLB.data[loop_ub] - 1] > nrmGradInf) {
          m_data[WorkingSet->indexLB.data[loop_ub] - 1] = -nrmGradInf + fabs
            (nrmGradInf);
        }
      }

      if (TrialState->xstar.size - 1 >= 0) {
        memcpy(&TrialState->xstar.data[0], &m_data[0], (uint32_T)
               TrialState->xstar.size * sizeof(real_T));
      }

      Swingup_MPC_relaxed(Hessian, TrialState->grad.data, TrialState,
                          MeritFunction, memspace, WorkingSet, QRManager,
                          CholManager, QPObjective, qpoptions);
      if (TrialState->delta_x.size - 1 >= 0) {
        memcpy(&y_data[0], &TrialState->delta_x.data[0], (uint32_T)
               TrialState->delta_x.size * sizeof(real_T));
      }

      if ((uint16_T)nVar - 1 >= 0) {
        memcpy(&y_data[0], &TrialState->xstar.data[0], (uint16_T)nVar * sizeof
               (real_T));
      }

      if (TrialState->delta_x.size - 1 >= 0) {
        memcpy(&TrialState->delta_x.data[0], &y_data[0], (uint32_T)
               TrialState->delta_x.size * sizeof(real_T));
      }

      guard1 = true;
      break;

     default:
      stepSuccess = Swingup_MPC_soc(Hessian, TrialState->grad.data, TrialState,
        memspace, WorkingSet, QRManager, CholManager, QPObjective, qpoptions);
      checkBoundViolation = stepSuccess;
      if (stepSuccess && (TrialState->state != -6)) {
        idxStartIneq = (uint8_T)nVar;
        idxEndIneq = ((uint8_T)nVar / 2) << 1;
        vectorUB = idxEndIneq - 2;
        for (loop_ub = 0; loop_ub <= vectorUB; loop_ub += 2) {
          tmp = _mm_loadu_pd(&TrialState->xstar.data[loop_ub]);
          tmp_0 = _mm_loadu_pd(&TrialState->socDirection.data[loop_ub]);
          _mm_storeu_pd(&TrialState->delta_x.data[loop_ub], _mm_add_pd(tmp,
            tmp_0));
        }

        for (loop_ub = idxEndIneq; loop_ub < idxStartIneq; loop_ub++) {
          TrialState->delta_x.data[loop_ub] = TrialState->xstar.data[loop_ub] +
            TrialState->socDirection.data[loop_ub];
        }
      }

      guard1 = true;
      break;
    }

    if (guard1) {
      if (TrialState->state != -6) {
        exitg1 = 1;
      } else {
        nrmGradInf = 0.0;
        nrmDirInf = 1.0;
        for (loop_ub = 0; loop_ub < 44; loop_ub++) {
          u1 = fabs(TrialState->grad.data[loop_ub]);
          if ((!(nrmGradInf >= u1)) && (!rtIsNaN(u1))) {
            nrmGradInf = u1;
          }

          u1 = fabs(TrialState->xstar.data[loop_ub]);
          if ((!(nrmDirInf >= u1)) && (!rtIsNaN(u1))) {
            nrmDirInf = u1;
          }
        }

        nrmGradInf /= nrmDirInf;
        if ((nrmGradInf <= 2.2204460492503131E-16) || rtIsNaN(nrmGradInf)) {
          nrmGradInf = 2.2204460492503131E-16;
        }

        for (loop_ub = 0; loop_ub < 44; loop_ub++) {
          idxEndIneq = 44 * loop_ub;
          for (idxStartIneq = 0; idxStartIneq < loop_ub; idxStartIneq++) {
            Hessian[idxEndIneq + idxStartIneq] = 0.0;
          }

          Hessian[loop_ub + 44 * loop_ub] = nrmGradInf;
          idxEndIneq += loop_ub;
          vectorUB = 42 - loop_ub;
          for (idxStartIneq = 0; idxStartIneq <= vectorUB; idxStartIneq++) {
            Hessian[(idxEndIneq + idxStartIneq) + 1] = 0.0;
          }
        }
      }
    }
  } while (exitg1 == 0);

  if (checkBoundViolation) {
    idxEndIneq = TrialState->delta_x.size;
    if (TrialState->delta_x.size - 1 >= 0) {
      memcpy(&m_data[0], &TrialState->delta_x.data[0], (uint32_T)
             TrialState->delta_x.size * sizeof(real_T));
    }

    loop_ub = (uint16_T)WorkingSet->sizes[3];
    for (nVar = 0; nVar < loop_ub; nVar++) {
      nrmDirInf = m_data[WorkingSet->indexLB.data[nVar] - 1];
      nrmGradInf = (TrialState->xstarsqp[WorkingSet->indexLB.data[nVar] - 1] +
                    nrmDirInf) - lb[WorkingSet->indexLB.data[nVar] - 1];
      if (nrmGradInf < 0.0) {
        m_data[WorkingSet->indexLB.data[nVar] - 1] = nrmDirInf - nrmGradInf;
        TrialState->xstar.data[WorkingSet->indexLB.data[nVar] - 1] -= nrmGradInf;
      }
    }

    TrialState->delta_x.size = idxEndIneq;
    if (idxEndIneq - 1 >= 0) {
      memcpy(&TrialState->delta_x.data[0], &m_data[0], (uint32_T)idxEndIneq *
             sizeof(real_T));
    }
  }

  return stepSuccess;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_evalObjAndConstr(int32_T obj_next_next_next_next_next_va,
  const s_GSKgPzH92oA7AAcXEvWMnG_Swin_T *obj_next_next_next_next_next_ne, const
  s_OOgWGXXQYnSElkPXvuQxeH_Swin_T *obj_next_next_next_next_next__0, const real_T
  x[44], real_T Cineq_workspace_data[], int32_T ineq0, real_T Ceq_workspace[40],
  real_T *fval, int32_T *status)
{
  __m128i tmp_0;
  real_T c[80];
  real_T c_data[80];
  real_T X[44];
  real_T b_X_tmp[44];
  real_T reshapes_f1[40];
  real_T A_1[16];
  real_T U[11];
  real_T A_1_tmp[4];
  real_T B[4];
  real_T B_tmp[4];
  real_T wtYerr[4];
  real_T A_1_tmp_tmp;
  real_T A_1_tmp_tmp_0;
  real_T U_0;
  real_T duk;
  real_T e;
  real_T fs;
  real_T ic_idx_1;
  real_T ic_idx_2;
  real_T ic_idx_3;
  real_T wtUerr;
  real_T wtUerr_tmp;
  real_T wtYerr_tmp;
  real_T wtYerr_tmp_0;
  int32_T ineqRange_data[80];
  int32_T ic[8];
  int32_T b_X_tmp_tmp;
  int32_T ineqRange_size_idx_1;
  int32_T n;
  int32_T vectorUB;
  int32_T yk;
  int8_T b_data[80];
  int8_T input_sizes_idx_0;
  int8_T sizes_idx_1;
  boolean_T icf[80];
  boolean_T tmp[40];
  boolean_T icf_0[8];
  boolean_T b_x[4];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T y;
  Swingup_MPC_znlmpc_getXUe(x, obj_next_next_next_next_next__0->runtimedata.x, X,
    U, &e);
  fs = 0.0;
  for (n = 0; n < 11; n++) {
    b_X_tmp_tmp = n << 2;
    b_X_tmp[b_X_tmp_tmp] = X[n];
    b_X_tmp[b_X_tmp_tmp + 1] = X[n + 11];
    b_X_tmp[b_X_tmp_tmp + 2] = X[n + 22];
    b_X_tmp[b_X_tmp_tmp + 3] = X[n + 33];
  }

  for (b_X_tmp_tmp = 0; b_X_tmp_tmp < 10; b_X_tmp_tmp++) {
    n = (b_X_tmp_tmp + 1) << 2;
    duk = (b_X_tmp[n] - obj_next_next_next_next_next__0->
           runtimedata.ref[b_X_tmp_tmp]) *
      obj_next_next_next_next_next__0->runtimedata.OutputWeights[b_X_tmp_tmp];
    ic_idx_1 = duk * duk;
    duk = (b_X_tmp[n + 1] - obj_next_next_next_next_next__0->
           runtimedata.ref[b_X_tmp_tmp + 10]) *
      obj_next_next_next_next_next__0->runtimedata.OutputWeights[b_X_tmp_tmp +
      10];
    ic_idx_1 += duk * duk;
    duk = (b_X_tmp[n + 2] - obj_next_next_next_next_next__0->
           runtimedata.ref[b_X_tmp_tmp + 20]) *
      obj_next_next_next_next_next__0->runtimedata.OutputWeights[b_X_tmp_tmp +
      20];
    ic_idx_1 += duk * duk;
    duk = (b_X_tmp[n + 3] - obj_next_next_next_next_next__0->
           runtimedata.ref[b_X_tmp_tmp + 30]) *
      obj_next_next_next_next_next__0->runtimedata.OutputWeights[b_X_tmp_tmp +
      30];
    fs += duk * duk + ic_idx_1;
    if (b_X_tmp_tmp + 1 == 1) {
      duk = U[b_X_tmp_tmp] - obj_next_next_next_next_next__0->runtimedata.lastMV;
    } else {
      duk = U[b_X_tmp_tmp] - U[b_X_tmp_tmp - 1];
    }

    wtUerr = 0.0 * U[b_X_tmp_tmp];
    duk *= 0.1;
    fs = (wtUerr * wtUerr + fs) + duk * duk;
  }

  *fval = 100000.0 * e * e + fs;
  if (rtIsInf(*fval) || rtIsNaN(*fval)) {
    if (rtIsNaN(*fval)) {
      *status = -3;
    } else if (*fval < 0.0) {
      *status = -1;
    } else {
      *status = -2;
    }
  } else {
    if (obj_next_next_next_next_next_va - 1 < 0) {
      n = 0;
    } else {
      n = (uint8_T)(obj_next_next_next_next_next_va - 1) + 1;
    }

    ineqRange_size_idx_1 = n;
    if (n > 0) {
      ineqRange_data[0] = 0;
      yk = 0;
      for (b_X_tmp_tmp = 2; b_X_tmp_tmp <= n; b_X_tmp_tmp++) {
        yk++;
        ineqRange_data[b_X_tmp_tmp - 1] = yk;
      }
    }

    yk = n - 1;
    b_X_tmp_tmp = (n / 4) << 2;
    vectorUB = b_X_tmp_tmp - 4;
    for (n = 0; n <= vectorUB; n += 4) {
      tmp_0 = _mm_loadu_si128((const __m128i *)&ineqRange_data[n]);
      _mm_storeu_si128((__m128i *)&ineqRange_data[n], _mm_add_epi32(tmp_0,
        _mm_set1_epi32(ineq0)));
    }

    for (n = b_X_tmp_tmp; n <= yk; n++) {
      ineqRange_data[n] += ineq0;
    }

    Swingup_MPC_znlmpc_getXUe(x, obj_next_next_next_next_next_ne->x, X, U, &e);
    for (b_X_tmp_tmp = 0; b_X_tmp_tmp < 40; b_X_tmp_tmp++) {
      reshapes_f1[b_X_tmp_tmp] = 0.0;
    }

    duk = 1.0;
    ic_idx_1 = 2.0;
    ic_idx_2 = 3.0;
    ic_idx_3 = 4.0;
    for (n = 0; n < 11; n++) {
      b_X_tmp_tmp = n << 2;
      b_X_tmp[b_X_tmp_tmp] = X[n];
      b_X_tmp[b_X_tmp_tmp + 1] = X[n + 11];
      b_X_tmp[b_X_tmp_tmp + 2] = X[n + 22];
      b_X_tmp[b_X_tmp_tmp + 3] = X[n + 33];
    }

    for (b_X_tmp_tmp = 0; b_X_tmp_tmp < 10; b_X_tmp_tmp++) {
      U_0 = U[b_X_tmp_tmp];
      fs = cos(b_X_tmp[(b_X_tmp_tmp << 2) + 3]);
      A_1[0] = 0.0005983720976 - fs * fs * 7.77845976E-5;
      A_1[4] = -0.0001161372 * fs;
      A_1[8] = 0.0;
      A_1[12] = 0.0;
      A_1[1] = -0.00011613720000000002 * fs;
      A_1[5] = 0.0001109943968;
      A_1[9] = 0.0;
      A_1[13] = 0.0;
      A_1[2] = 0.0;
      A_1[3] = 0.0;
      A_1[6] = 0.0;
      A_1[7] = 0.0;
      A_1[10] = 1.0;
      A_1[11] = 0.0;
      A_1[14] = 0.0;
      A_1[15] = 1.0;
      n = b_X_tmp_tmp << 2;
      wtUerr_tmp = b_X_tmp[n + 3];
      wtUerr = sin(wtUerr_tmp);
      wtYerr_tmp = b_X_tmp[n + 1];
      wtYerr_tmp_0 = b_X_tmp[n];
      wtYerr[0] = (wtYerr_tmp * wtYerr_tmp * (-0.0001161372 * wtUerr) -
                   0.0001555691952 * fs * wtUerr * wtYerr_tmp * wtYerr_tmp_0) -
        wtYerr_tmp_0 * 0.00021;
      wtYerr[1] = 0.024 * fs * wtUerr * 0.0032410249 * (wtYerr_tmp_0 *
        wtYerr_tmp_0) - 0.23544 * wtUerr * 0.05693;
      wtYerr[2] = wtYerr_tmp_0;
      wtYerr[3] = wtYerr_tmp;
      Swingup_MPC_mldivide_m(A_1, wtYerr);
      fs = U_0 * 0.005;
      B[0] = fs;
      B_tmp[0] = fs;
      fs = U_0 * 0.0;
      B[1] = fs;
      B_tmp[1] = fs;
      B[2] = fs;
      B_tmp[2] = fs;
      B[3] = fs;
      B_tmp[3] = fs;
      Swingup_MPC_mldivide_m(A_1, B);
      yk = (b_X_tmp_tmp + 1) << 2;
      U_0 = b_X_tmp[yk + 3];
      fs = cos(U_0);
      A_1[0] = 0.0005983720976 - fs * fs * 7.77845976E-5;
      A_1[4] = -0.0001161372 * fs;
      A_1[8] = 0.0;
      A_1[12] = 0.0;
      A_1[1] = -0.00011613720000000002 * fs;
      A_1[5] = 0.0001109943968;
      A_1[9] = 0.0;
      A_1[13] = 0.0;
      A_1[2] = 0.0;
      A_1[3] = 0.0;
      A_1[6] = 0.0;
      A_1[7] = 0.0;
      A_1[10] = 1.0;
      A_1[11] = 0.0;
      A_1[14] = 0.0;
      A_1[15] = 1.0;
      wtUerr = sin(U_0);
      A_1_tmp_tmp = b_X_tmp[yk + 1];
      A_1_tmp_tmp_0 = b_X_tmp[yk];
      A_1_tmp[0] = (A_1_tmp_tmp * A_1_tmp_tmp * (-0.0001161372 * wtUerr) -
                    0.0001555691952 * fs * wtUerr * A_1_tmp_tmp * A_1_tmp_tmp_0)
        - A_1_tmp_tmp_0 * 0.00021;
      A_1_tmp[1] = 0.024 * fs * wtUerr * 0.0032410249 * (A_1_tmp_tmp_0 *
        A_1_tmp_tmp_0) - 0.23544 * wtUerr * 0.05693;
      A_1_tmp[2] = A_1_tmp_tmp_0;
      A_1_tmp[3] = A_1_tmp_tmp;
      Swingup_MPC_mldivide_m(A_1, A_1_tmp);
      Swingup_MPC_mldivide_m(A_1, B_tmp);
      reshapes_f1[(int32_T)duk - 1] = (((wtYerr[0] + B[0]) + (A_1_tmp[0] +
        B_tmp[0])) * 0.0005 + wtYerr_tmp_0) - A_1_tmp_tmp_0;
      duk += 4.0;
      reshapes_f1[(int32_T)ic_idx_1 - 1] = (((wtYerr[1] + B[1]) + (A_1_tmp[1] +
        B_tmp[1])) * 0.0005 + wtYerr_tmp) - A_1_tmp_tmp;
      ic_idx_1 += 4.0;
      reshapes_f1[(int32_T)ic_idx_2 - 1] = (((wtYerr[2] + B[2]) + (A_1_tmp[2] +
        B_tmp[2])) * 0.0005 + b_X_tmp[n + 2]) - b_X_tmp[yk + 2];
      ic_idx_2 += 4.0;
      reshapes_f1[(int32_T)ic_idx_3 - 1] = (((wtYerr[3] + B[3]) + (A_1_tmp[3] +
        B_tmp[3])) * 0.0005 + wtUerr_tmp) - U_0;
      ic_idx_3 += 4.0;
    }

    for (n = 0; n < 40; n++) {
      tmp[n] = rtIsInf(obj_next_next_next_next_next_ne->OutputMin[n]);
    }

    Swingup_MPC_all(tmp, b_x);
    y = true;
    b_X_tmp_tmp = 0;
    exitg1 = false;
    while ((!exitg1) && (b_X_tmp_tmp < 4)) {
      if (!b_x[b_X_tmp_tmp]) {
        y = false;
        exitg1 = true;
      } else {
        b_X_tmp_tmp++;
      }
    }

    guard1 = false;
    if (y) {
      for (n = 0; n < 40; n++) {
        tmp[n] = rtIsInf(obj_next_next_next_next_next_ne->OutputMax[n]);
      }

      Swingup_MPC_all(tmp, b_x);
      b_X_tmp_tmp = 0;
      exitg1 = false;
      while ((!exitg1) && (b_X_tmp_tmp < 4)) {
        if (!b_x[b_X_tmp_tmp]) {
          y = false;
          exitg1 = true;
        } else {
          b_X_tmp_tmp++;
        }
      }

      if (y) {
        yk = 0;
        n = 0;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      for (b_X_tmp_tmp = 0; b_X_tmp_tmp < 80; b_X_tmp_tmp++) {
        c[b_X_tmp_tmp] = 0.0;
        icf[b_X_tmp_tmp] = true;
      }

      duk = 1.0;
      ic_idx_1 = 2.0;
      ic_idx_2 = 3.0;
      ic_idx_3 = 4.0;
      for (b_X_tmp_tmp = 0; b_X_tmp_tmp < 10; b_X_tmp_tmp++) {
        icf[(int32_T)duk - 1] = ((!rtIsInf
          (obj_next_next_next_next_next_ne->OutputMin[b_X_tmp_tmp])) &&
          (!rtIsNaN(obj_next_next_next_next_next_ne->OutputMin[b_X_tmp_tmp])));
        A_1_tmp_tmp_0 = obj_next_next_next_next_next_ne->OutputMin[b_X_tmp_tmp +
          10];
        icf[(int32_T)ic_idx_1 - 1] = ((!rtIsInf(A_1_tmp_tmp_0)) && (!rtIsNaN
          (A_1_tmp_tmp_0)));
        A_1_tmp_tmp = obj_next_next_next_next_next_ne->OutputMin[b_X_tmp_tmp +
          20];
        icf[(int32_T)ic_idx_2 - 1] = ((!rtIsInf(A_1_tmp_tmp)) && (!rtIsNaN
          (A_1_tmp_tmp)));
        fs = obj_next_next_next_next_next_ne->OutputMin[b_X_tmp_tmp + 30];
        icf[(int32_T)ic_idx_3 - 1] = ((!rtIsInf(fs)) && (!rtIsNaN(fs)));
        icf[(int32_T)(duk + 4.0) - 1] = ((!rtIsInf
          (obj_next_next_next_next_next_ne->OutputMax[b_X_tmp_tmp])) &&
          (!rtIsNaN(obj_next_next_next_next_next_ne->OutputMax[b_X_tmp_tmp])));
        ic[0] = (int32_T)duk - 1;
        ic[4] = (int32_T)(duk + 4.0) - 1;
        wtUerr = obj_next_next_next_next_next_ne->OutputMax[b_X_tmp_tmp + 10];
        icf[(int32_T)(ic_idx_1 + 4.0) - 1] = ((!rtIsInf(wtUerr)) && (!rtIsNaN
          (wtUerr)));
        ic[1] = (int32_T)ic_idx_1 - 1;
        ic[5] = (int32_T)(ic_idx_1 + 4.0) - 1;
        wtUerr_tmp = obj_next_next_next_next_next_ne->OutputMax[b_X_tmp_tmp + 20];
        icf[(int32_T)(ic_idx_2 + 4.0) - 1] = ((!rtIsInf(wtUerr_tmp)) &&
          (!rtIsNaN(wtUerr_tmp)));
        ic[2] = (int32_T)ic_idx_2 - 1;
        ic[6] = (int32_T)(ic_idx_2 + 4.0) - 1;
        wtYerr_tmp = obj_next_next_next_next_next_ne->OutputMax[b_X_tmp_tmp + 30];
        icf[(int32_T)(ic_idx_3 + 4.0) - 1] = ((!rtIsInf(wtYerr_tmp)) &&
          (!rtIsNaN(wtYerr_tmp)));
        ic[3] = (int32_T)ic_idx_3 - 1;
        ic[7] = (int32_T)(ic_idx_3 + 4.0) - 1;
        for (n = 0; n < 8; n++) {
          icf_0[n] = icf[ic[n]];
        }

        if (Swingup_MPC_any(icf_0)) {
          wtYerr_tmp_0 = X[b_X_tmp_tmp + 1];
          c[(int32_T)duk - 1] = (obj_next_next_next_next_next_ne->
            OutputMin[b_X_tmp_tmp] - e) - wtYerr_tmp_0;
          U_0 = X[b_X_tmp_tmp + 12];
          c[(int32_T)ic_idx_1 - 1] = (A_1_tmp_tmp_0 - e) - U_0;
          A_1_tmp_tmp_0 = X[b_X_tmp_tmp + 23];
          c[(int32_T)ic_idx_2 - 1] = (A_1_tmp_tmp - e) - A_1_tmp_tmp_0;
          A_1_tmp_tmp = X[b_X_tmp_tmp + 34];
          c[(int32_T)ic_idx_3 - 1] = (fs - e) - A_1_tmp_tmp;
          c[(int32_T)(duk + 4.0) - 1] = (wtYerr_tmp_0 -
            obj_next_next_next_next_next_ne->OutputMax[b_X_tmp_tmp]) - e;
          c[(int32_T)(ic_idx_1 + 4.0) - 1] = (U_0 - wtUerr) - e;
          c[(int32_T)(ic_idx_2 + 4.0) - 1] = (A_1_tmp_tmp_0 - wtUerr_tmp) - e;
          c[(int32_T)(ic_idx_3 + 4.0) - 1] = (A_1_tmp_tmp - wtYerr_tmp) - e;
        }

        duk += 8.0;
        ic_idx_1 += 8.0;
        ic_idx_2 += 8.0;
        ic_idx_3 += 8.0;
      }

      n = 0;
      for (b_X_tmp_tmp = 0; b_X_tmp_tmp < 80; b_X_tmp_tmp++) {
        if (icf[b_X_tmp_tmp]) {
          n++;
        }
      }

      yk = n;
      n = 0;
      for (b_X_tmp_tmp = 0; b_X_tmp_tmp < 80; b_X_tmp_tmp++) {
        if (icf[b_X_tmp_tmp]) {
          b_data[n] = (int8_T)(b_X_tmp_tmp + 1);
          n++;
        }
      }

      for (n = 0; n < yk; n++) {
        c_data[n] = c[b_data[n] - 1];
      }

      n = 1;
      if (yk - 1 >= 0) {
        memcpy(&c[0], &c_data[0], (uint32_T)yk * sizeof(real_T));
      }
    }

    sizes_idx_1 = (int8_T)((yk != 0) && (n != 0));
    if ((sizes_idx_1 == 0) || ((yk != 0) && (n != 0))) {
      input_sizes_idx_0 = (int8_T)yk;
    } else {
      input_sizes_idx_0 = 0;
    }

    yk = sizes_idx_1;
    for (n = 0; n < yk; n++) {
      if (input_sizes_idx_0 - 1 >= 0) {
        memcpy(&Swingup_MPC_B.varargin_1_data[0], &c[0], (uint32_T)
               input_sizes_idx_0 * sizeof(real_T));
      }
    }

    for (n = 0; n < ineqRange_size_idx_1; n++) {
      Cineq_workspace_data[ineqRange_data[n] - 1] =
        Swingup_MPC_B.varargin_1_data[n];
    }

    memcpy(&Ceq_workspace[0], &reshapes_f1[0], 40U * sizeof(real_T));
    *status = Swingup_MP_checkVectorNonFinite(obj_next_next_next_next_next_va,
      Cineq_workspace_data, ineq0);
    if (*status == 1) {
      *status = Swingup__checkVectorNonFinite_b(Ceq_workspace);
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup__computeLinearResiduals(const real_T x[44], int32_T nVar,
  real_T workspaceIneq_data[], const int32_T *workspaceIneq_size, int32_T
  mLinIneq, const emxArray_real_T_Swingup_MPC_T *AineqT, const real_T
  bineq_data[], int32_T ldAi)
{
  __m128d tmp;
  real_T y_data[449];
  real_T c;
  int32_T b;
  int32_T f;
  int32_T loop_ub;
  int32_T vectorUB;
  int32_T y_size_idx_0;
  if (mLinIneq > 0) {
    if (*workspaceIneq_size - 1 >= 0) {
      memcpy(&y_data[0], &workspaceIneq_data[0], (uint32_T)*workspaceIneq_size *
             sizeof(real_T));
    }

    if ((uint16_T)mLinIneq - 1 >= 0) {
      memcpy(&y_data[0], &bineq_data[0], (uint16_T)mLinIneq * sizeof(real_T));
    }

    if (*workspaceIneq_size - 1 >= 0) {
      memcpy(&workspaceIneq_data[0], &y_data[0], (uint32_T)*workspaceIneq_size *
             sizeof(real_T));
    }

    b = (uint8_T)mLinIneq;
    y_size_idx_0 = ((uint8_T)mLinIneq / 2) << 1;
    vectorUB = y_size_idx_0 - 2;
    for (loop_ub = 0; loop_ub <= vectorUB; loop_ub += 2) {
      tmp = _mm_loadu_pd(&workspaceIneq_data[loop_ub]);
      _mm_storeu_pd(&workspaceIneq_data[loop_ub], _mm_mul_pd(tmp, _mm_set1_pd
        (-1.0)));
    }

    for (loop_ub = y_size_idx_0; loop_ub < b; loop_ub++) {
      workspaceIneq_data[loop_ub] = -workspaceIneq_data[loop_ub];
    }

    y_size_idx_0 = 0;
    vectorUB = (mLinIneq - 1) * ldAi + 1;
    for (loop_ub = 1; ldAi < 0 ? loop_ub >= vectorUB : loop_ub <= vectorUB;
         loop_ub += ldAi) {
      c = 0.0;
      f = (loop_ub + nVar) - 1;
      for (b = loop_ub; b <= f; b++) {
        c += AineqT->data[b - 1] * x[b - loop_ub];
      }

      workspaceIneq_data[y_size_idx_0] += c;
      y_size_idx_0++;
    }
  }
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static real_T Swingup_MPC_computeMeritFcn(real_T obj_penaltyParam, real_T fval,
  const real_T Cineq_workspace_data[], int32_T mIneq, const real_T
  Ceq_workspace[40], boolean_T evalWellDefined)
{
  real_T Cineq_workspace;
  real_T constrViolationEq;
  real_T constrViolationIneq;
  real_T val;
  int32_T idx;
  int32_T k;
  if (evalWellDefined) {
    constrViolationEq = 0.0;
    for (k = 0; k < 40; k++) {
      constrViolationEq += fabs(Ceq_workspace[k]);
    }

    constrViolationIneq = 0.0;
    k = (uint8_T)mIneq;
    for (idx = 0; idx < k; idx++) {
      Cineq_workspace = Cineq_workspace_data[idx];
      if (Cineq_workspace > 0.0) {
        constrViolationIneq += Cineq_workspace;
      }
    }

    val = (constrViolationEq + constrViolationIneq) * obj_penaltyParam + fval;
  } else {
    val = (rtInf);
  }

  return val;
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_linesearch(boolean_T *evalWellDefined, const real_T
  bineq_data[], int32_T WorkingSet_nVar, int32_T WorkingSet_ldA, const
  emxArray_real_T_Swingup_MPC_T *WorkingSet_Aineq,
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState, real_T MeritFunction_penaltyParam,
  real_T MeritFunction_phi, real_T MeritFunction_phiPrimePlus, real_T
  MeritFunction_phiFullStep, int32_T FcnEvaluator_next_next_next_nex, const
  s_GSKgPzH92oA7AAcXEvWMnG_Swin_T *FcnEvaluator_next_next_next_n_0, const
  s_OOgWGXXQYnSElkPXvuQxeH_Swin_T *FcnEvaluator_next_next_next_n_1, boolean_T
  socTaken, real_T *alpha, int32_T *exitflag)
{
  __m128d tmp;
  __m128d tmp_0;
  real_T y_data[449];
  real_T phi_alpha;
  int32_T exitg1;
  int32_T loop_ub;
  int32_T mLinIneq;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T y_size_idx_0;
  boolean_T exitg2;
  boolean_T tooSmallX;
  mLinIneq = TrialState->mIneq - TrialState->mNonlinIneq;
  *alpha = 1.0;
  *exitflag = 1;
  phi_alpha = MeritFunction_phiFullStep;
  if (TrialState->searchDir.size - 1 >= 0) {
    memcpy(&y_data[0], &TrialState->searchDir.data[0], (uint32_T)
           TrialState->searchDir.size * sizeof(real_T));
  }

  if ((uint16_T)WorkingSet_nVar - 1 >= 0) {
    memcpy(&y_data[0], &TrialState->delta_x.data[0], (uint16_T)WorkingSet_nVar *
           sizeof(real_T));
  }

  if (TrialState->searchDir.size - 1 >= 0) {
    memcpy(&TrialState->searchDir.data[0], &y_data[0], (uint32_T)
           TrialState->searchDir.size * sizeof(real_T));
  }

  do {
    exitg1 = 0;
    if (TrialState->FunctionEvaluations < 4400) {
      if ((*evalWellDefined) && (phi_alpha <= *alpha * 0.0001 *
           MeritFunction_phiPrimePlus + MeritFunction_phi)) {
        exitg1 = 1;
      } else {
        *alpha *= 0.7;
        loop_ub = (uint8_T)WorkingSet_nVar - 1;
        scalarLB = ((uint8_T)WorkingSet_nVar / 2) << 1;
        vectorUB = scalarLB - 2;
        for (y_size_idx_0 = 0; y_size_idx_0 <= vectorUB; y_size_idx_0 += 2) {
          tmp_0 = _mm_loadu_pd(&TrialState->xstar.data[y_size_idx_0]);
          _mm_storeu_pd(&TrialState->delta_x.data[y_size_idx_0], _mm_mul_pd
                        (_mm_set1_pd(*alpha), tmp_0));
        }

        for (y_size_idx_0 = scalarLB; y_size_idx_0 <= loop_ub; y_size_idx_0++) {
          TrialState->delta_x.data[y_size_idx_0] = *alpha *
            TrialState->xstar.data[y_size_idx_0];
        }

        if (socTaken) {
          phi_alpha = *alpha * *alpha;
          if ((WorkingSet_nVar >= 1) && (!(phi_alpha == 0.0))) {
            scalarLB = (WorkingSet_nVar / 2) << 1;
            vectorUB = scalarLB - 2;
            for (y_size_idx_0 = 0; y_size_idx_0 <= vectorUB; y_size_idx_0 += 2)
            {
              tmp_0 = _mm_loadu_pd(&TrialState->socDirection.data[y_size_idx_0]);
              tmp = _mm_loadu_pd(&TrialState->delta_x.data[y_size_idx_0]);
              _mm_storeu_pd(&TrialState->delta_x.data[y_size_idx_0], _mm_add_pd
                            (_mm_mul_pd(_mm_set1_pd(phi_alpha), tmp_0), tmp));
            }

            for (y_size_idx_0 = scalarLB; y_size_idx_0 < WorkingSet_nVar;
                 y_size_idx_0++) {
              TrialState->delta_x.data[y_size_idx_0] += phi_alpha *
                TrialState->socDirection.data[y_size_idx_0];
            }
          }
        }

        tooSmallX = true;
        y_size_idx_0 = 0;
        exitg2 = false;
        while ((!exitg2) && (y_size_idx_0 <= (uint8_T)WorkingSet_nVar - 1)) {
          phi_alpha = fabs(TrialState->xstarsqp[y_size_idx_0]);
          if ((phi_alpha <= 1.0) || rtIsNaN(phi_alpha)) {
            phi_alpha = 1.0;
          }

          if (1.0E-6 * phi_alpha <= fabs(TrialState->delta_x.data[y_size_idx_0]))
          {
            tooSmallX = false;
            exitg2 = true;
          } else {
            y_size_idx_0++;
          }
        }

        if (tooSmallX) {
          *exitflag = -2;
          exitg1 = 1;
        } else {
          for (y_size_idx_0 = 0; y_size_idx_0 <= loop_ub; y_size_idx_0++) {
            TrialState->xstarsqp[y_size_idx_0] = TrialState->
              xstarsqp_old[y_size_idx_0] + TrialState->delta_x.data[y_size_idx_0];
          }

          Swingup_MPC_evalObjAndConstr(FcnEvaluator_next_next_next_nex,
            FcnEvaluator_next_next_next_n_0, FcnEvaluator_next_next_next_n_1,
            TrialState->xstarsqp, TrialState->cIneq.data, TrialState->iNonIneq0,
            TrialState->cEq, &TrialState->sqpFval, &y_size_idx_0);
          Swingup__computeLinearResiduals(TrialState->xstarsqp, WorkingSet_nVar,
            TrialState->cIneq.data, &TrialState->cIneq.size, mLinIneq,
            WorkingSet_Aineq, bineq_data, WorkingSet_ldA);
          TrialState->FunctionEvaluations++;
          *evalWellDefined = (y_size_idx_0 == 1);
          phi_alpha = Swingup_MPC_computeMeritFcn(MeritFunction_penaltyParam,
            TrialState->sqpFval, TrialState->cIneq.data, TrialState->mIneq,
            TrialState->cEq, *evalWellDefined);
        }
      }
    } else {
      *exitflag = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_driver(const real_T bineq_data[], const real_T lb[44],
  s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T *TrialState, sG8JZ69axY52WWR6RKyApQC_Swing_T
  *MeritFunction, const coder_internal_stickyStruct_9_T *FcnEvaluator,
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T *memspace, s_pBvMsf7fBJa4zdfMTVPUqH_Swin_T
  *WorkingSet, s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T *QRManager,
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T *CholManager, s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T *
  QPObjective, const int32_T *fscales_lineq_constraint_size, const int32_T
  *fscales_cineq_constraint_size, real_T Hessian[1936])
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  s7RdrPWkr8UPAUyTdDJkLaG_Swing_T Flags;
  somzaGboVhDG7PNQS6E98jD_Swing_T expl_temp;
  real_T y_data[449];
  real_T s;
  real_T smax;
  int32_T b_iy;
  int32_T b_nVar;
  int32_T c_ix;
  int32_T idx_max;
  int32_T ix;
  int32_T iy;
  int32_T mConstr_tmp;
  int32_T mFixed;
  int32_T mIneq;
  int32_T mLB;
  int32_T mLambda;
  int32_T mUB;
  int32_T qpoptions_MaxIterations;
  int32_T scalarLB;
  int32_T u1;
  boolean_T isFeasible;
  static const int8_T ab[1936] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  static const char_T x[7] = { 'f', 'm', 'i', 'n', 'c', 'o', 'n' };

  somzaGboVhDG7PNQS6E98jD_Swing_T expl_temp_0;
  int32_T b_nVar_tmp;
  int32_T mLinIneq_tmp_tmp;
  int32_T nVar_tmp_tmp;
  for (scalarLB = 0; scalarLB < 1936; scalarLB++) {
    Hessian[scalarLB] = ab[scalarLB];
  }

  nVar_tmp_tmp = WorkingSet->nVar;
  mFixed = WorkingSet->sizes[0];
  mIneq = WorkingSet->sizes[2];
  mLB = WorkingSet->sizes[3];
  mUB = WorkingSet->sizes[4];
  mConstr_tmp = (((WorkingSet->sizes[0] + WorkingSet->sizes[2]) +
                  WorkingSet->sizes[3]) + WorkingSet->sizes[4]) + 40;
  mLinIneq_tmp_tmp = WorkingSet->sizes[2] - TrialState->mNonlinIneq;
  u1 = ((WorkingSet->sizes[2] + WorkingSet->sizes[3]) + WorkingSet->sizes[4]) +
    (WorkingSet->sizes[0] << 1);
  if (WorkingSet->nVar >= u1) {
    u1 = WorkingSet->nVar;
  }

  qpoptions_MaxIterations = 10 * u1;
  TrialState->steplength = 1.0;
  Flags.fevalOK = true;
  Flags.stepAccepted = false;
  Flags.failedLineSearch = false;
  Flags.stepType = 1;
  b_nVar_tmp = (uint16_T)mConstr_tmp;
  if ((uint16_T)mConstr_tmp - 1 >= 0) {
    memcpy(&TrialState->lambdaStopTest.data[0], &TrialState->lambdasqp.data[0],
           (uint16_T)mConstr_tmp * sizeof(real_T));
  }

  Swingup_MPC_computeGradLag(TrialState->gradLag.data, WorkingSet->ldA,
    WorkingSet->nVar, TrialState->grad.data, WorkingSet->sizes[2],
    WorkingSet->Aineq, WorkingSet->Aeq, WorkingSet->indexFixed.data,
    WorkingSet->sizes[0], WorkingSet->indexLB.data, WorkingSet->sizes[3],
    WorkingSet->indexUB.data, WorkingSet->sizes[4],
    TrialState->lambdaStopTest.data);
  if (WorkingSet->nVar < 1) {
    idx_max = 0;
  } else {
    idx_max = 1;
    if (WorkingSet->nVar > 1) {
      smax = fabs(TrialState->grad.data[0]);
      for (u1 = 2; u1 <= nVar_tmp_tmp; u1++) {
        s = fabs(TrialState->grad.data[u1 - 1]);
        if (s > smax) {
          idx_max = u1;
          smax = s;
        }
      }
    }
  }

  smax = fabs(TrialState->grad.data[idx_max - 1]);
  if ((smax <= 1.0) || rtIsNaN(smax)) {
    smax = 1.0;
  }

  if (rtIsInf(smax)) {
    smax = 1.0;
  }

  MeritFunction->nlpPrimalFeasError = Swingup__computePrimalFeasError
    (TrialState->xstarsqp, WorkingSet->sizes[2] - TrialState->mNonlinIneq,
     TrialState->mNonlinIneq, TrialState->cIneq.data, TrialState->cEq,
     WorkingSet->indexLB.data, WorkingSet->sizes[3], lb,
     WorkingSet->indexUB.data, WorkingSet->sizes[4]);
  if ((MeritFunction->nlpPrimalFeasError <= 1.0) || rtIsNaN
      (MeritFunction->nlpPrimalFeasError)) {
    MeritFunction->feasRelativeFactor = 1.0;
  } else {
    MeritFunction->feasRelativeFactor = MeritFunction->nlpPrimalFeasError;
  }

  isFeasible = (MeritFunction->nlpPrimalFeasError <= 1.0E-6 *
                MeritFunction->feasRelativeFactor);
  Swingup_MP_computeDualFeasError(WorkingSet->nVar, TrialState->gradLag.data,
    &Flags.gradOK, &MeritFunction->nlpDualFeasError);
  if (!Flags.gradOK) {
    Flags.done = true;
    if (isFeasible) {
      TrialState->sqpExitFlag = 2;
    } else {
      TrialState->sqpExitFlag = -2;
    }
  } else {
    MeritFunction->nlpComplError = 0.0;
    if (MeritFunction->nlpDualFeasError >= 0.0) {
      MeritFunction->firstOrderOpt = MeritFunction->nlpDualFeasError;
    } else {
      MeritFunction->firstOrderOpt = 0.0;
    }

    if ((uint16_T)mConstr_tmp - 1 >= 0) {
      memcpy(&TrialState->lambdaStopTestPrev.data[0],
             &TrialState->lambdaStopTest.data[0], (uint16_T)mConstr_tmp * sizeof
             (real_T));
    }

    if (isFeasible && (MeritFunction->nlpDualFeasError <= 1.0E-6 * smax)) {
      Flags.done = true;
      TrialState->sqpExitFlag = 1;
    } else {
      Flags.done = false;
      if (isFeasible && (TrialState->sqpFval < -1.0E+20)) {
        Flags.done = true;
        TrialState->sqpExitFlag = -3;
      }
    }
  }

  Swingup_MPC_saveJacobian(TrialState, WorkingSet->nVar, WorkingSet->sizes[2],
    WorkingSet->Aineq, TrialState->iNonIneq0, WorkingSet->Aeq, WorkingSet->ldA);
  TrialState->sqpFval_old = TrialState->sqpFval;
  for (u1 = 0; u1 < 44; u1++) {
    TrialState->xstarsqp_old[u1] = TrialState->xstarsqp[u1];
    TrialState->grad_old.data[u1] = TrialState->grad.data[u1];
  }

  u1 = TrialState->cIneq_old.size;
  if (TrialState->cIneq_old.size - 1 >= 0) {
    memcpy(&y_data[0], &TrialState->cIneq_old.data[0], (uint32_T)
           TrialState->cIneq_old.size * sizeof(real_T));
  }

  if ((uint16_T)TrialState->mIneq - 1 >= 0) {
    memcpy(&y_data[0], &TrialState->cIneq.data[0], (uint16_T)TrialState->mIneq *
           sizeof(real_T));
  }

  if (TrialState->cIneq_old.size - 1 >= 0) {
    memcpy(&TrialState->cIneq_old.data[0], &y_data[0], (uint32_T)
           TrialState->cIneq_old.size * sizeof(real_T));
  }

  memcpy(&TrialState->cEq_old[0], &TrialState->cEq[0], 40U * sizeof(real_T));
  if (!Flags.done) {
    TrialState->sqpIterations = 1;
  }

  while (!Flags.done) {
    if ((!Flags.stepAccepted) && (!Flags.failedLineSearch)) {
      expl_temp.IterDisplayQP = false;
      expl_temp.RemainFeasible = false;
      expl_temp.ProbRelTolFactor = 1.0;
      expl_temp.ConstrRelTolFactor = 1.0;
      expl_temp.PricingTolerance = 0.0;
      expl_temp.ObjectiveLimit = (rtMinusInf);
      expl_temp.ConstraintTolerance = 1.0E-6;
      expl_temp.OptimalityTolerance = 2.2204460492503131E-14;
      expl_temp.StepTolerance = 1.0E-6;
      expl_temp.MaxIterations = qpoptions_MaxIterations;
      for (scalarLB = 0; scalarLB < 7; scalarLB++) {
        expl_temp.SolverName[scalarLB] = x[scalarLB];
      }
    }

    while ((!Flags.stepAccepted) && (!Flags.failedLineSearch)) {
      if (Flags.stepType != 3) {
        Swingu_updateWorkingSetForNewQP(TrialState->xstarsqp, WorkingSet, mIneq,
          TrialState->mNonlinIneq, TrialState->cIneq.data, TrialState->cEq, mLB,
          lb, mUB, mFixed);
      }

      expl_temp_0 = expl_temp;
      Flags.stepAccepted = Swingup_MPC_step_l(&Flags.stepType, Hessian, lb,
        TrialState, MeritFunction, memspace, WorkingSet, QRManager, CholManager,
        QPObjective, &expl_temp_0);
      if (Flags.stepAccepted) {
        b_nVar = (uint8_T)nVar_tmp_tmp;
        for (u1 = 0; u1 < b_nVar; u1++) {
          TrialState->xstarsqp[u1] += TrialState->delta_x.data[u1];
        }

        Swingup_MPC_evalObjAndConstr
          (FcnEvaluator->next.next.next.next.next.value,
           &FcnEvaluator->next.next.next.next.next.next.next.value.workspace.runtimedata,
           &FcnEvaluator->next.next.next.next.next.next.next.next.value.workspace,
           TrialState->xstarsqp, TrialState->cIneq.data, TrialState->iNonIneq0,
           TrialState->cEq, &TrialState->sqpFval, &u1);
        Flags.fevalOK = (u1 == 1);
        TrialState->FunctionEvaluations++;
        Swingup__computeLinearResiduals(TrialState->xstarsqp, nVar_tmp_tmp,
          TrialState->cIneq.data, &TrialState->cIneq.size, mLinIneq_tmp_tmp,
          WorkingSet->Aineq, bineq_data, WorkingSet->ldA);
        MeritFunction->phiFullStep = Swingup_MPC_computeMeritFcn
          (MeritFunction->penaltyParam, TrialState->sqpFval,
           TrialState->cIneq.data, mIneq, TrialState->cEq, Flags.fevalOK);
      }

      if ((Flags.stepType == 1) && Flags.stepAccepted && Flags.fevalOK &&
          (MeritFunction->phi < MeritFunction->phiFullStep) &&
          (TrialState->sqpFval < TrialState->sqpFval_old)) {
        Flags.stepType = 3;
        Flags.stepAccepted = false;
      } else {
        Swingup_MPC_linesearch(&Flags.fevalOK, bineq_data, WorkingSet->nVar,
          WorkingSet->ldA, WorkingSet->Aineq, TrialState,
          MeritFunction->penaltyParam, MeritFunction->phi,
          MeritFunction->phiPrimePlus, MeritFunction->phiFullStep,
          FcnEvaluator->next.next.next.next.next.value,
          &FcnEvaluator->next.next.next.next.next.next.next.value.workspace.runtimedata,
          &FcnEvaluator->next.next.next.next.next.next.next.next.value.workspace,
          (Flags.stepType == 3) && Flags.stepAccepted, &smax, &u1);
        TrialState->steplength = smax;
        if (u1 > 0) {
          Flags.stepAccepted = true;
        } else {
          Flags.failedLineSearch = true;
        }
      }
    }

    if (Flags.stepAccepted && (!Flags.failedLineSearch)) {
      b_nVar = (uint8_T)nVar_tmp_tmp;
      for (u1 = 0; u1 < b_nVar; u1++) {
        TrialState->xstarsqp[u1] = TrialState->xstarsqp_old[u1] +
          TrialState->delta_x.data[u1];
      }

      scalarLB = ((uint16_T)mConstr_tmp / 2) << 1;
      idx_max = scalarLB - 2;
      for (u1 = 0; u1 <= idx_max; u1 += 2) {
        tmp = _mm_loadu_pd(&TrialState->lambda.data[u1]);
        tmp_0 = _mm_loadu_pd(&TrialState->lambdasqp.data[u1]);
        tmp_1 = _mm_loadu_pd(&TrialState->lambdasqp.data[u1]);
        _mm_storeu_pd(&TrialState->lambdasqp.data[u1], _mm_add_pd(_mm_mul_pd
          (_mm_sub_pd(tmp, tmp_0), _mm_set1_pd(TrialState->steplength)), tmp_1));
      }

      for (u1 = scalarLB; u1 < b_nVar_tmp; u1++) {
        TrialState->lambdasqp.data[u1] += (TrialState->lambda.data[u1] -
          TrialState->lambdasqp.data[u1]) * TrialState->steplength;
      }

      TrialState->sqpFval_old = TrialState->sqpFval;
      for (u1 = 0; u1 < 44; u1++) {
        TrialState->xstarsqp_old[u1] = TrialState->xstarsqp[u1];
        TrialState->grad_old.data[u1] = TrialState->grad.data[u1];
      }

      u1 = TrialState->cIneq_old.size;
      if (TrialState->cIneq_old.size - 1 >= 0) {
        memcpy(&y_data[0], &TrialState->cIneq_old.data[0], (uint32_T)
               TrialState->cIneq_old.size * sizeof(real_T));
      }

      if ((uint16_T)TrialState->mIneq - 1 >= 0) {
        memcpy(&y_data[0], &TrialState->cIneq.data[0], (uint16_T)
               TrialState->mIneq * sizeof(real_T));
      }

      if (TrialState->cIneq_old.size - 1 >= 0) {
        memcpy(&TrialState->cIneq_old.data[0], &y_data[0], (uint32_T)
               TrialState->cIneq_old.size * sizeof(real_T));
      }

      memcpy(&TrialState->cEq_old[0], &TrialState->cEq[0], 40U * sizeof(real_T));
      Flags.gradOK = true;
      evalObjAndConstrAndDerivatives
        (FcnEvaluator->next.next.next.next.next.value,
         &FcnEvaluator->next.next.next.next.next.next.next.value.workspace.runtimedata,
         &FcnEvaluator->next.next.next.next.next.next.next.next.value.workspace,
         TrialState->xstarsqp, TrialState->grad.data, TrialState->cIneq.data,
         TrialState->iNonIneq0, TrialState->cEq, WorkingSet->Aineq,
         TrialState->iNonIneq0, WorkingSet->ldA, WorkingSet->Aeq,
         WorkingSet->ldA, &TrialState->sqpFval, &u1);
      TrialState->FunctionEvaluations++;
      Flags.fevalOK = (u1 == 1);
    } else {
      TrialState->sqpFval = TrialState->sqpFval_old;
      memcpy(&TrialState->xstarsqp[0], &TrialState->xstarsqp_old[0], 44U *
             sizeof(real_T));
      u1 = TrialState->cIneq.size;
      if (TrialState->cIneq.size - 1 >= 0) {
        memcpy(&y_data[0], &TrialState->cIneq.data[0], (uint32_T)
               TrialState->cIneq.size * sizeof(real_T));
      }

      if ((uint16_T)TrialState->mIneq - 1 >= 0) {
        memcpy(&y_data[0], &TrialState->cIneq_old.data[0], (uint16_T)
               TrialState->mIneq * sizeof(real_T));
      }

      if (TrialState->cIneq.size - 1 >= 0) {
        memcpy(&TrialState->cIneq.data[0], &y_data[0], (uint32_T)
               TrialState->cIneq.size * sizeof(real_T));
      }

      memcpy(&TrialState->cEq[0], &TrialState->cEq_old[0], 40U * sizeof(real_T));
    }

    Swingup_MPC_test_exit(&Flags, memspace, MeritFunction,
                          fscales_lineq_constraint_size,
                          fscales_cineq_constraint_size, WorkingSet, TrialState,
                          QRManager, lb);
    if ((!Flags.done) && Flags.stepAccepted) {
      Flags.stepAccepted = false;
      Flags.stepType = 1;
      Flags.failedLineSearch = false;
      b_nVar = (mFixed + TrialState->iNonIneq0) + 39;
      u1 = WorkingSet->ldA;
      memcpy(&TrialState->delta_gradLag.data[0], &TrialState->grad.data[0],
             (uint8_T)nVar_tmp_tmp * sizeof(real_T));
      if (nVar_tmp_tmp >= 1) {
        scalarLB = (nVar_tmp_tmp / 2) << 1;
        idx_max = scalarLB - 2;
        for (mLambda = 0; mLambda <= idx_max; mLambda += 2) {
          tmp = _mm_loadu_pd(&TrialState->delta_gradLag.data[mLambda]);
          tmp_0 = _mm_loadu_pd(&TrialState->grad_old.data[mLambda]);
          _mm_storeu_pd(&TrialState->delta_gradLag.data[mLambda], _mm_sub_pd(tmp,
            tmp_0));
        }

        for (mLambda = scalarLB; mLambda < nVar_tmp_tmp; mLambda++) {
          TrialState->delta_gradLag.data[mLambda] -= TrialState->
            grad_old.data[mLambda];
        }
      }

      ix = mFixed;
      iy = WorkingSet->ldA * 39 + 1;
      for (mLambda = 1; u1 < 0 ? mLambda >= iy : mLambda <= iy; mLambda += u1) {
        b_iy = (mLambda + nVar_tmp_tmp) - 1;
        for (idx_max = mLambda; idx_max <= b_iy; idx_max++) {
          scalarLB = idx_max - mLambda;
          TrialState->delta_gradLag.data[scalarLB] += WorkingSet->Aeq->
            data[idx_max - 1] * TrialState->lambdasqp.data[ix];
        }

        ix++;
      }

      c_ix = mFixed;
      for (mLambda = 1; u1 < 0 ? mLambda >= iy : mLambda <= iy; mLambda += u1) {
        b_iy = (mLambda + nVar_tmp_tmp) - 1;
        for (idx_max = mLambda; idx_max <= b_iy; idx_max++) {
          scalarLB = idx_max - mLambda;
          TrialState->delta_gradLag.data[scalarLB] +=
            TrialState->JacCeqTrans_old->data[idx_max - 1] *
            -TrialState->lambdasqp.data[c_ix];
        }

        c_ix++;
      }

      if (TrialState->mNonlinIneq > 0) {
        ix = (TrialState->iNonIneq0 - 1) * WorkingSet->ldA + 1;
        c_ix = b_nVar;
        iy = (TrialState->mNonlinIneq - 1) * WorkingSet->ldA + ix;
        for (mLambda = ix; u1 < 0 ? mLambda >= iy : mLambda <= iy; mLambda += u1)
        {
          b_iy = (mLambda + nVar_tmp_tmp) - 1;
          for (idx_max = mLambda; idx_max <= b_iy; idx_max++) {
            scalarLB = idx_max - mLambda;
            TrialState->delta_gradLag.data[scalarLB] += WorkingSet->Aineq->
              data[idx_max - 1] * TrialState->lambdasqp.data[c_ix];
          }

          c_ix++;
        }

        idx_max = b_nVar;
        c_ix = (TrialState->mNonlinIneq - 1) * WorkingSet->ldA + 1;
        for (b_nVar = 1; u1 < 0 ? b_nVar >= c_ix : b_nVar <= c_ix; b_nVar += u1)
        {
          b_iy = (b_nVar + nVar_tmp_tmp) - 1;
          for (mLambda = b_nVar; mLambda <= b_iy; mLambda++) {
            scalarLB = mLambda - b_nVar;
            TrialState->delta_gradLag.data[scalarLB] +=
              TrialState->JacCineqTrans_old->data[mLambda - 1] *
              -TrialState->lambdasqp.data[idx_max];
          }

          idx_max++;
        }
      }

      Swingup_MPC_saveJacobian(TrialState, nVar_tmp_tmp, mIneq,
        WorkingSet->Aineq, TrialState->iNonIneq0, WorkingSet->Aeq,
        WorkingSet->ldA);
      Swingup_MPC_BFGSUpdate(nVar_tmp_tmp, Hessian, TrialState->delta_x.data,
        TrialState->delta_gradLag.data, memspace->workspace_double);
      TrialState->sqpIterations++;
    }
  }
}

static void emxFreeStruct_s_xgaiQX2t1f8Iwfq(s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T
  *pStruct)
{
  Swingup_MPC_emxFree_real_T(&pStruct->FMat);
}

static void emxFreeStruct_s_qjgm7GzdZt1MoSN(s_qjgm7GzdZt1MoSNNUuwzWH_Swin_T
  *pStruct)
{
  Swingup_MPC_emxFree_real_T(&pStruct->QR);
  Swingup_MPC_emxFree_real_T(&pStruct->Q);
}

static void emxFreeStruct_s_j0Ykcy5K3TT7uFO(s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T
  *pStruct)
{
  Swingup_MPC_emxFree_real_T(&pStruct->workspace_double);
}

static void emxFreeStruct_s_k1Ho7Q1nYjseRM5(s_k1Ho7Q1nYjseRM5cXIwEUD_Swin_T
  *pStruct)
{
  Swingup_MPC_emxFree_real_T(&pStruct->JacCineqTrans_old);
  Swingup_MPC_emxFree_real_T(&pStruct->JacCeqTrans_old);
}

/* Function for MATLAB Function: '<S6>/NLMPC' */
static void Swingup_MPC_fmincon(const s_GSKgPzH92oA7AAcXEvWMnG_Swin_T
  *fun_workspace_runtimedata, const sXyXDxkiKhsfpX9ivkpx9WG_Swing_T
  *fun_workspace_userdata, const real_T x0[44], const real_T Aineq_data[], const
  real_T bineq_data[], const int32_T *bineq_size, const real_T lb[44], const
  s_GSKgPzH92oA7AAcXEvWMnG_Swin_T *nonlcon_workspace_runtimedata, const
  sXyXDxkiKhsfpX9ivkpx9WG_Swing_T *nonlcon_workspace_userdata, real_T x[44],
  real_T *fval, real_T *exitflag, sttYSJM5GCi2c1Eu0R50efC_Swing_T *output)
{
  __m128d tmp;
  sG8JZ69axY52WWR6RKyApQC_Swing_T MeritFunction;
  s_j0Ykcy5K3TT7uFOSX0kFSG_Swin_T memspace;
  s_x5MUnC0L5qGnqHjeyMGHGF_Swin_T QPObjective;
  s_xgaiQX2t1f8Iwfqw2xCGq_Swing_T CholManager;
  real_T y_data[449];
  real_T Cineq_data[80];
  real_T Ceq[40];
  real_T absxk;
  real_T b_c;
  real_T scale;
  real_T t;
  int32_T Cineq_size[2];
  int32_T JacCineqTrans_size[2];
  int32_T i;
  int32_T iEq0;
  int32_T k;
  int32_T loop_ub;
  int32_T mConstrMax;
  int32_T mIneq;
  int32_T mNonlinIneq;
  int32_T maxDims;
  int32_T vectorUB;
  int8_T WorkingSet_tmp[5];
  int8_T WorkingSet_tmp_0;
  Swingup_eML_blk_kernel_anonFcn2(nonlcon_workspace_runtimedata->x,
    nonlcon_workspace_runtimedata->OutputMin,
    nonlcon_workspace_runtimedata->OutputMax, x0, Cineq_data, Cineq_size, Ceq,
    Swingup_MPC_B.JacCineqTrans_data, JacCineqTrans_size,
    Swingup_MPC_B.JacCeqTrans);
  mNonlinIneq = Cineq_size[0] * Cineq_size[1];
  mIneq = *bineq_size + mNonlinIneq;
  mConstrMax = (mIneq + mIneq) + 209;
  if (mIneq + 125 >= mConstrMax) {
    maxDims = mIneq + 125;
  } else {
    maxDims = mConstrMax;
  }

  emxInitStruct_s_k1Ho7Q1nYjseRM5(&Swingup_MPC_B.TrialState);
  Swingup_MPC_factoryConstruct(mIneq + 125, mConstrMax, mIneq, mNonlinIneq,
    &Swingup_MPC_B.TrialState);
  memcpy(&Swingup_MPC_B.TrialState.xstarsqp[0], &x0[0], 44U * sizeof(real_T));
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.value = mNonlinIneq;
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.x
    [0] = nonlcon_workspace_runtimedata->x[0];
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.x
    [1] = nonlcon_workspace_runtimedata->x[1];
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.x
    [2] = nonlcon_workspace_runtimedata->x[2];
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.x
    [3] = nonlcon_workspace_runtimedata->x[3];
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.lastMV
    = nonlcon_workspace_runtimedata->lastMV;
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.ref
     [0], &nonlcon_workspace_runtimedata->ref[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.OutputWeights
     [0], &nonlcon_workspace_runtimedata->OutputWeights[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.MVWeights
     [0], &nonlcon_workspace_runtimedata->MVWeights[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.MVRateWeights
     [0], &nonlcon_workspace_runtimedata->MVRateWeights[0], 10U * sizeof(real_T));
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.ECRWeight
    = nonlcon_workspace_runtimedata->ECRWeight;
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.OutputMin
     [0], &nonlcon_workspace_runtimedata->OutputMin[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.OutputMax
     [0], &nonlcon_workspace_runtimedata->OutputMax[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.StateMin
     [0], &nonlcon_workspace_runtimedata->StateMin[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.StateMax
     [0], &nonlcon_workspace_runtimedata->StateMax[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.MVMin
     [0], &nonlcon_workspace_runtimedata->MVMin[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.MVMax
     [0], &nonlcon_workspace_runtimedata->MVMax[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.MVRateMin
     [0], &nonlcon_workspace_runtimedata->MVRateMin[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.MVRateMax
     [0], &nonlcon_workspace_runtimedata->MVRateMax[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata.MVScaledTarget
     [0], &nonlcon_workspace_runtimedata->MVScaledTarget[0], 10U * sizeof(real_T));
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.userdata
    = *nonlcon_workspace_userdata;
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.x
    [0] = fun_workspace_runtimedata->x[0];
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.x
    [1] = fun_workspace_runtimedata->x[1];
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.x
    [2] = fun_workspace_runtimedata->x[2];
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.x
    [3] = fun_workspace_runtimedata->x[3];
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.lastMV
    = fun_workspace_runtimedata->lastMV;
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.ref
     [0], &fun_workspace_runtimedata->ref[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.OutputWeights
     [0], &fun_workspace_runtimedata->OutputWeights[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.MVWeights
     [0], &fun_workspace_runtimedata->MVWeights[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.MVRateWeights
     [0], &fun_workspace_runtimedata->MVRateWeights[0], 10U * sizeof(real_T));
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.ECRWeight
    = fun_workspace_runtimedata->ECRWeight;
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.OutputMin
     [0], &fun_workspace_runtimedata->OutputMin[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.OutputMax
     [0], &fun_workspace_runtimedata->OutputMax[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.StateMin
     [0], &fun_workspace_runtimedata->StateMin[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.StateMax
     [0], &fun_workspace_runtimedata->StateMax[0], 40U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.MVMin
     [0], &fun_workspace_runtimedata->MVMin[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.MVMax
     [0], &fun_workspace_runtimedata->MVMax[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.MVRateMin
     [0], &fun_workspace_runtimedata->MVRateMin[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.MVRateMax
     [0], &fun_workspace_runtimedata->MVRateMax[0], 10U * sizeof(real_T));
  memcpy
    (&Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.runtimedata.MVScaledTarget
     [0], &fun_workspace_runtimedata->MVScaledTarget[0], 10U * sizeof(real_T));
  Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace.userdata
    = *fun_workspace_userdata;
  Swingup_M_factoryConstruct_h3jt(mIneq + 125, &QPObjective.grad.size,
    &QPObjective.Hx.size, &QPObjective.hasLinear, &QPObjective.nvar,
    &QPObjective.maxVar, &QPObjective.beta, &QPObjective.rho,
    &QPObjective.objtype, &QPObjective.prev_objtype, &QPObjective.prev_nvar,
    &QPObjective.prev_hasLinear, &QPObjective.gammaScalar);
  QPObjective.nvar = 44;
  QPObjective.hasLinear = true;
  QPObjective.objtype = 3;
  emxInitStruct_s_j0Ykcy5K3TT7uFO(&memspace);
  k = memspace.workspace_double->size[0] * memspace.workspace_double->size[1];
  memspace.workspace_double->size[0] = maxDims;
  memspace.workspace_double->size[1] = mIneq + 125;
  Swingu_emxEnsureCapacity_real_T(memspace.workspace_double, k);
  memspace.workspace_int.size = maxDims;
  memspace.workspace_sort.size = maxDims;
  emxInitStruct_s_pBvMsf7fBJa4zdf(&Swingup_MPC_B.WorkingSet);
  Swingup__factoryConstruct_h3jty(mIneq, mIneq + 125, mConstrMax,
    &Swingup_MPC_B.WorkingSet);
  k = -1;
  for (iEq0 = 0; iEq0 < 44; iEq0++) {
    b_c = lb[iEq0];
    if ((!rtIsInf(b_c)) && (!rtIsNaN(b_c))) {
      k++;
      Swingup_MPC_B.WorkingSet.indexLB.data[k] = iEq0 + 1;
    }
  }

  Swingup_MPC_B.WorkingSet.mConstrMax = mConstrMax;
  iEq0 = mIneq + k;
  Swingup_MPC_B.WorkingSet.mConstr = iEq0 + 41;
  Swingup_MPC_B.WorkingSet.mConstrOrig = iEq0 + 41;
  WorkingSet_tmp[0] = 0;
  WorkingSet_tmp[1] = 40;
  WorkingSet_tmp[2] = (int8_T)mIneq;
  WorkingSet_tmp[3] = (int8_T)(k + 1);
  WorkingSet_tmp[4] = 0;
  for (i = 0; i < 5; i++) {
    WorkingSet_tmp_0 = WorkingSet_tmp[i];
    Swingup_MPC_B.WorkingSet.sizes[i] = WorkingSet_tmp_0;
    Swingup_MPC_B.WorkingSet.sizesNormal[i] = WorkingSet_tmp_0;
  }

  Swingup_MPC_B.WorkingSet.sizesPhaseOne[0] = 0;
  Swingup_MPC_B.WorkingSet.sizesPhaseOne[1] = 40;
  Swingup_MPC_B.WorkingSet.sizesPhaseOne[2] = mIneq;
  Swingup_MPC_B.WorkingSet.sizesPhaseOne[3] = k + 2;
  Swingup_MPC_B.WorkingSet.sizesPhaseOne[4] = 0;
  Swingup_MPC_B.WorkingSet.sizesRegularized[0] = 0;
  Swingup_MPC_B.WorkingSet.sizesRegularized[1] = 40;
  Swingup_MPC_B.WorkingSet.sizesRegularized[2] = mIneq;
  Swingup_MPC_B.WorkingSet.sizesRegularized[3] = iEq0 + 81;
  Swingup_MPC_B.WorkingSet.sizesRegularized[4] = 0;
  Swingup_MPC_B.WorkingSet.sizesRegPhaseOne[0] = 0;
  Swingup_MPC_B.WorkingSet.sizesRegPhaseOne[1] = 40;
  Swingup_MPC_B.WorkingSet.sizesRegPhaseOne[2] = mIneq;
  Swingup_MPC_B.WorkingSet.sizesRegPhaseOne[3] = iEq0 + 82;
  Swingup_MPC_B.WorkingSet.sizesRegPhaseOne[4] = 0;
  Swingup_MPC_B.WorkingSet.isActiveIdxNormal[0] = 1;
  Swingup_MPC_B.WorkingSet.isActiveIdxNormal[1] = 0;
  Swingup_MPC_B.WorkingSet.isActiveIdxNormal[2] = 40;
  Swingup_MPC_B.WorkingSet.isActiveIdxNormal[3] = mIneq;
  Swingup_MPC_B.WorkingSet.isActiveIdxNormal[4] = k + 1;
  Swingup_MPC_B.WorkingSet.isActiveIdxNormal[5] = 0;
  for (i = 0; i < 6; i++) {
    Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[i] =
      Swingup_MPC_B.WorkingSet.isActiveIdxNormal[i];
  }

  for (mConstrMax = 0; mConstrMax < 5; mConstrMax++) {
    Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[mConstrMax + 1] +=
      Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[mConstrMax];
  }

  for (i = 0; i < 6; i++) {
    Swingup_MPC_B.WorkingSet.isActiveIdx[i] =
      Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[i];
  }

  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[1] = 0;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 40;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[3] = mIneq;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[4] = k + 2;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[5] = 0;
  for (mConstrMax = 0; mConstrMax < 5; mConstrMax++) {
    Swingup_MPC_B.WorkingSet.isActiveIdxNormal[mConstrMax + 1] +=
      Swingup_MPC_B.WorkingSet.isActiveIdxNormal[mConstrMax];
    Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[mConstrMax + 1] +=
      Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[mConstrMax];
  }

  for (i = 0; i < 6; i++) {
    Swingup_MPC_B.WorkingSet.isActiveIdxPhaseOne[i] =
      Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[i];
  }

  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[1] = 0;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 40;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[3] = mIneq;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[4] = iEq0 + 81;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[5] = 0;
  for (mConstrMax = 0; mConstrMax < 5; mConstrMax++) {
    Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[mConstrMax + 1] +=
      Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[mConstrMax];
  }

  for (i = 0; i < 6; i++) {
    Swingup_MPC_B.WorkingSet.isActiveIdxRegularized[i] =
      Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[i];
  }

  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[1] = 0;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 40;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[3] = mIneq;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[4] = iEq0 + 82;
  Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[5] = 0;
  for (mConstrMax = 0; mConstrMax < 5; mConstrMax++) {
    Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[mConstrMax + 1] +=
      Swingup_MPC_B.WorkingSet.isActiveIdxRegPhaseOne[mConstrMax];
  }

  if (mIneq > 0) {
    mConstrMax = *bineq_size;
    for (iEq0 = 0; iEq0 < mConstrMax; iEq0++) {
      for (i = 0; i < 44; i++) {
        Swingup_MPC_B.WorkingSet.Aineq->data[i + Swingup_MPC_B.WorkingSet.ldA *
          iEq0] = Aineq_data[*bineq_size * i + iEq0];
      }
    }
  }

  for (iEq0 = 0; iEq0 <= k; iEq0++) {
    b_c =
      Swingup_MPC_B.TrialState.xstarsqp[Swingup_MPC_B.WorkingSet.indexLB.data[iEq0]
      - 1];
    scale = lb[Swingup_MPC_B.WorkingSet.indexLB.data[iEq0] - 1];
    if ((b_c >= scale) || rtIsNaN(scale)) {
      Swingup_MPC_B.TrialState.xstarsqp[Swingup_MPC_B.WorkingSet.indexLB.data[iEq0]
        - 1] = b_c;
    } else {
      Swingup_MPC_B.TrialState.xstarsqp[Swingup_MPC_B.WorkingSet.indexLB.data[iEq0]
        - 1] = scale;
    }
  }

  evalObjAndConstrAndDerivatives(mNonlinIneq,
    &Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.value.workspace.runtimedata,
    &Swingup_MPC_B.FcnEvaluator.next.next.next.next.next.next.next.next.value.workspace,
    Swingup_MPC_B.TrialState.xstarsqp, Swingup_MPC_B.TrialState.grad.data,
    Swingup_MPC_B.TrialState.cIneq.data, Swingup_MPC_B.TrialState.iNonIneq0,
    Swingup_MPC_B.TrialState.cEq, Swingup_MPC_B.WorkingSet.Aineq,
    Swingup_MPC_B.TrialState.iNonIneq0, Swingup_MPC_B.WorkingSet.ldA,
    Swingup_MPC_B.WorkingSet.Aeq, Swingup_MPC_B.WorkingSet.ldA,
    &Swingup_MPC_B.TrialState.sqpFval, &mConstrMax);
  Swingup_MPC_B.TrialState.FunctionEvaluations = 1;
  mConstrMax = Swingup_MPC_B.WorkingSet.ldA;
  if (*bineq_size > 0) {
    i = Swingup_MPC_B.TrialState.cIneq.size;
    loop_ub = Swingup_MPC_B.TrialState.cIneq.size;
    if (loop_ub - 1 >= 0) {
      memcpy(&y_data[0], &Swingup_MPC_B.TrialState.cIneq.data[0], (uint32_T)
             loop_ub * sizeof(real_T));
    }

    iEq0 = *bineq_size - 1;
    memcpy(&y_data[0], &bineq_data[0], (uint32_T)((*bineq_size - 1) + 1) *
           sizeof(real_T));
    if (i - 1 >= 0) {
      memcpy(&Swingup_MPC_B.TrialState.cIneq.data[0], &y_data[0], (uint32_T)i *
             sizeof(real_T));
    }

    loop_ub = (*bineq_size / 2) << 1;
    vectorUB = loop_ub - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      tmp = _mm_loadu_pd(&Swingup_MPC_B.TrialState.cIneq.data[i]);
      _mm_storeu_pd(&Swingup_MPC_B.TrialState.cIneq.data[i], _mm_mul_pd(tmp,
        _mm_set1_pd(-1.0)));
    }

    for (i = loop_ub; i <= iEq0; i++) {
      Swingup_MPC_B.TrialState.cIneq.data[i] =
        -Swingup_MPC_B.TrialState.cIneq.data[i];
    }

    iEq0 = 0;
    i = (*bineq_size - 1) * Swingup_MPC_B.WorkingSet.ldA + 1;
    for (loop_ub = 1; mConstrMax < 0 ? loop_ub >= i : loop_ub <= i; loop_ub +=
         mConstrMax) {
      b_c = 0.0;
      for (vectorUB = loop_ub; vectorUB <= loop_ub + 43; vectorUB++) {
        b_c += Swingup_MPC_B.WorkingSet.Aineq->data[vectorUB - 1] *
          Swingup_MPC_B.TrialState.xstarsqp[vectorUB - loop_ub];
      }

      Swingup_MPC_B.TrialState.cIneq.data[iEq0] += b_c;
      iEq0++;
    }
  }

  for (mConstrMax = 0; mConstrMax < 40; mConstrMax++) {
    Swingup_MPC_B.WorkingSet.beq[mConstrMax] =
      -Swingup_MPC_B.TrialState.cEq[mConstrMax];
    Swingup_MPC_B.WorkingSet.bwset.data[mConstrMax] =
      Swingup_MPC_B.WorkingSet.beq[mConstrMax];
  }

  mConstrMax = 0;
  iEq0 = 0;
  for (i = 0; i < 40; i++) {
    for (loop_ub = 0; loop_ub < 44; loop_ub++) {
      Swingup_MPC_B.WorkingSet.ATwset->data[mConstrMax + loop_ub] =
        Swingup_MPC_B.WorkingSet.Aeq->data[iEq0 + loop_ub];
    }

    mConstrMax += Swingup_MPC_B.WorkingSet.ldA;
    iEq0 += Swingup_MPC_B.WorkingSet.ldA;
  }

  loop_ub = (mIneq / 2) << 1;
  vectorUB = loop_ub - 2;
  for (iEq0 = 0; iEq0 <= vectorUB; iEq0 += 2) {
    tmp = _mm_loadu_pd(&Swingup_MPC_B.TrialState.cIneq.data[iEq0]);
    _mm_storeu_pd(&Swingup_MPC_B.WorkingSet.bineq.data[iEq0], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (iEq0 = loop_ub; iEq0 < mIneq; iEq0++) {
    Swingup_MPC_B.WorkingSet.bineq.data[iEq0] =
      -Swingup_MPC_B.TrialState.cIneq.data[iEq0];
  }

  for (mConstrMax = 0; mConstrMax <= k; mConstrMax++) {
    Swingup_MPC_B.WorkingSet.lb.data[Swingup_MPC_B.WorkingSet.indexLB.data[mConstrMax]
      - 1] = -lb[Swingup_MPC_B.WorkingSet.indexLB.data[mConstrMax] - 1] +
      x0[Swingup_MPC_B.WorkingSet.indexLB.data[mConstrMax] - 1];
  }

  Swingup_MPC_initActiveSet(&Swingup_MPC_B.WorkingSet);
  MeritFunction.initFval = Swingup_MPC_B.TrialState.sqpFval;
  MeritFunction.penaltyParam = 1.0;
  MeritFunction.threshold = 0.0001;
  MeritFunction.nPenaltyDecreases = 0;
  MeritFunction.linearizedConstrViol = 0.0;
  b_c = 0.0;
  for (k = 0; k < 40; k++) {
    b_c += fabs(Swingup_MPC_B.TrialState.cEq[k]);
  }

  MeritFunction.initConstrViolationEq = b_c;
  b_c = 0.0;
  for (k = 0; k < mIneq; k++) {
    if (Swingup_MPC_B.TrialState.cIneq.data[k] > 0.0) {
      b_c += Swingup_MPC_B.TrialState.cIneq.data[k];
    }
  }

  MeritFunction.initConstrViolationIneq = b_c;
  MeritFunction.phi = 0.0;
  MeritFunction.phiPrimePlus = 0.0;
  MeritFunction.phiFullStep = 0.0;
  MeritFunction.feasRelativeFactor = 0.0;
  MeritFunction.nlpPrimalFeasError = 0.0;
  MeritFunction.nlpDualFeasError = 0.0;
  MeritFunction.nlpComplError = 0.0;
  MeritFunction.firstOrderOpt = 0.0;
  MeritFunction.hasObjective = true;
  emxInitStruct_s_qjgm7GzdZt1MoSN(&Swingup_MPC_B.QRManager);
  Swingup_MPC_factoryConstruct_h3(maxDims, maxDims, &Swingup_MPC_B.QRManager.ldq,
    Swingup_MPC_B.QRManager.QR, Swingup_MPC_B.QRManager.Q,
    Swingup_MPC_B.QRManager.jpvt.data, &Swingup_MPC_B.QRManager.jpvt.size,
    &Swingup_MPC_B.QRManager.mrows, &Swingup_MPC_B.QRManager.ncols,
    &Swingup_MPC_B.QRManager.tau.size, &Swingup_MPC_B.QRManager.minRowCol,
    &Swingup_MPC_B.QRManager.usedPivoting);
  emxInitStruct_s_xgaiQX2t1f8Iwfq(&CholManager);
  Swingup_MP_factoryConstruct_h3j(maxDims, CholManager.FMat, &CholManager.ldm,
    &CholManager.ndims, &CholManager.info, &CholManager.scaleFactor,
    &CholManager.ConvexCheck, &CholManager.regTol_, &CholManager.workspace_,
    &CholManager.workspace2_);
  Swingup_MPC_driver(bineq_data, lb, &Swingup_MPC_B.TrialState, &MeritFunction,
                     &Swingup_MPC_B.FcnEvaluator, &memspace,
                     &Swingup_MPC_B.WorkingSet, &Swingup_MPC_B.QRManager,
                     &CholManager, &QPObjective, bineq_size, &mNonlinIneq,
                     Swingup_MPC_B.unusedExpr);
  emxFreeStruct_s_xgaiQX2t1f8Iwfq(&CholManager);
  emxFreeStruct_s_qjgm7GzdZt1MoSN(&Swingup_MPC_B.QRManager);
  emxFreeStruct_s_pBvMsf7fBJa4zdf(&Swingup_MPC_B.WorkingSet);
  emxFreeStruct_s_j0Ykcy5K3TT7uFO(&memspace);
  *fval = Swingup_MPC_B.TrialState.sqpFval;
  *exitflag = Swingup_MPC_B.TrialState.sqpExitFlag;
  output->iterations = Swingup_MPC_B.TrialState.sqpIterations;
  output->funcCount = Swingup_MPC_B.TrialState.FunctionEvaluations;
  output->algorithm[0] = 's';
  output->algorithm[1] = 'q';
  output->algorithm[2] = 'p';
  output->constrviolation = MeritFunction.nlpPrimalFeasError;
  b_c = 0.0;
  scale = 3.3121686421112381E-170;
  for (mNonlinIneq = 0; mNonlinIneq < 44; mNonlinIneq++) {
    x[mNonlinIneq] = Swingup_MPC_B.TrialState.xstarsqp[mNonlinIneq];
    absxk = fabs(Swingup_MPC_B.TrialState.delta_x.data[mNonlinIneq]);
    if (absxk > scale) {
      t = scale / absxk;
      b_c = b_c * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_c += t * t;
    }
  }

  output->stepsize = scale * sqrt(b_c);
  output->lssteplength = Swingup_MPC_B.TrialState.steplength;
  emxFreeStruct_s_k1Ho7Q1nYjseRM5(&Swingup_MPC_B.TrialState);
  output->firstorderopt = MeritFunction.firstOrderOpt;
}

/* Model output function for TID0 */
void Swingup_MPC_output0(void)         /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_SmoothSignalGenerator;
  __m128d tmp;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_countstorad;
  int32_T i;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(Swingup_MPC_M)) {
    /* set solver stop time */
    if (!(Swingup_MPC_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Swingup_MPC_M->solverInfo,
                            ((Swingup_MPC_M->Timing.clockTickH0 + 1) *
        Swingup_MPC_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Swingup_MPC_M->solverInfo,
                            ((Swingup_MPC_M->Timing.clockTick0 + 1) *
        Swingup_MPC_M->Timing.stepSize0 + Swingup_MPC_M->Timing.clockTickH0 *
        Swingup_MPC_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Swingup_MPC_M)) {
    Swingup_MPC_M->Timing.t[0] = rtsiGetT(&Swingup_MPC_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Swingup_MPC_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: Swingup_MPC/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(Swingup_MPC_DW.HILReadEncoderTimebase_Task,
        1, &Swingup_MPC_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        rtb_countstorad = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
      } else {
        rtb_countstorad = Swingup_MPC_DW.HILReadEncoderTimebase_Buffer;
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: Swingup_MPC/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(Swingup_MPC_DW.HILInitialize_Card,
        &Swingup_MPC_P.HILReadEncoder_channels, 1,
        &Swingup_MPC_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
      } else {
        rtb_DiscreteTimeIntegrator = Swingup_MPC_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/counts to rad1' */
    Swingup_MPC_B.countstorad1 = Swingup_MPC_P.countstorad1_Gain *
      rtb_DiscreteTimeIntegrator;

    /* Gain: '<S4>/Gain' */
    Swingup_MPC_B.Gain = Swingup_MPC_P.Gain_Gain * Swingup_MPC_B.countstorad1;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_DiscreteTimeIntegrator = Swingup_MPC_P.Gain1_Gain *
      Swingup_MPC_P.Constant2_Value;

    /* Gain: '<Root>/counts to rad' */
    rtb_countstorad *= Swingup_MPC_P.countstorad_Gain;

    /* Gain: '<S3>/Gain' */
    Swingup_MPC_B.Gain_f[0] = Swingup_MPC_P.Gain_Gain_a *
      rtb_DiscreteTimeIntegrator;
    Swingup_MPC_B.Gain_f[1] = Swingup_MPC_P.Gain_Gain_a * rtb_countstorad;

    /* RateTransition: '<S5>/Rate Transition' */
    if (Swingup_MPC_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S5>/Rate Transition' */
      Swingup_MPC_B.RateTransition = Swingup_MPC_DW.RateTransition_Buffer0;
    }

    /* End of RateTransition: '<S5>/Rate Transition' */

    /* Abs: '<S29>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(Swingup_MPC_B.RateTransition);

    /* RelationalOperator: '<S29>/Relational Operator1' incorporates:
     *  Constant: '<S29>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      Swingup_MPC_P.StallMonitor_control_threshold);
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn1'
   */
  Swingup_MPC_B.Gain_o = (Swingup_MPC_P.TransferFcn1_C *
    Swingup_MPC_X.TransferFcn1_CSTATE + Swingup_MPC_P.TransferFcn1_D *
    Swingup_MPC_B.countstorad1) * Swingup_MPC_P.Gain_Gain_h;
  if (rtmIsMajorTimeStep(Swingup_MPC_M)) {
    /* Abs: '<S29>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(Swingup_MPC_B.Gain_o);

    /* Logic: '<S29>/Logical Operator' incorporates:
     *  Constant: '<S29>/motion threshold'
     *  RelationalOperator: '<S29>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <= Swingup_MPC_P.StallMonitor_motion_threshold));

    /* Logic: '<S29>/Logical Operator1' */
    Swingup_MPC_B.LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
    if (Swingup_MPC_B.LogicalOperator1 &&
        (Swingup_MPC_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      Swingup_MPC_DW.DiscreteTimeIntegrator_DSTATE =
        Swingup_MPC_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator = Swingup_MPC_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S29>/Relational Operator2' incorporates:
     *  Constant: '<S29>/control threshold1'
     */
    Swingup_MPC_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
      Swingup_MPC_P.StallMonitor_duration_s);

    /* Stop: '<S30>/Stop Simulation' incorporates:
     *  Constant: '<S31>/Constant'
     *  RelationalOperator: '<S31>/Compare'
     */
    if (Swingup_MPC_B.RelationalOperator2 != Swingup_MPC_P.Constant_Value_j) {
      rtmSetStopRequested(Swingup_MPC_M, 1);
    }

    /* End of Stop: '<S30>/Stop Simulation' */

    /* DataTypeConversion: '<S29>/Data Type Conversion' */
    Swingup_MPC_B.DataTypeConversion = rtb_RelationalOperator1;
  }

  /* Gain: '<Root>/Gain1' */
  Swingup_MPC_B.Gain1 = Swingup_MPC_P.Gain1_Gain_o * Swingup_MPC_B.Gain_o;
  if (rtmIsMajorTimeStep(Swingup_MPC_M)) {
    /* Sum: '<Root>/Add1' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    Swingup_MPC_B.Add1 = rtb_countstorad - Swingup_MPC_P.Constant3_Value;
  }

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  Swingup_MPC_B.VectorConcatenate[0] = Swingup_MPC_B.Gain1;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  Swingup_MPC_B.VectorConcatenate[2] = Swingup_MPC_B.countstorad1;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  Swingup_MPC_B.VectorConcatenate[3] = Swingup_MPC_B.Add1;

  /* TransferFcn: '<Root>/Transfer Fcn' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  Swingup_MPC_B.VectorConcatenate[1] = Swingup_MPC_P.TransferFcn_C *
    Swingup_MPC_X.TransferFcn_CSTATE;
  Swingup_MPC_B.VectorConcatenate[1] += Swingup_MPC_P.TransferFcn_D *
    Swingup_MPC_B.Add1;

  /* RateTransition generated from: '<S6>/NLMPC' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  if (rtmIsMajorTimeStep(Swingup_MPC_M) &&
      Swingup_MPC_M->Timing.RateInteraction.TID1_2) {
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[0] =
      Swingup_MPC_B.VectorConcatenate[0];
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[1] =
      Swingup_MPC_B.VectorConcatenate[1];
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[2] =
      Swingup_MPC_B.VectorConcatenate[2];
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[3] =
      Swingup_MPC_B.VectorConcatenate[3];
  }

  /* End of RateTransition generated from: '<S6>/NLMPC' */
  for (i = 0; i <= 8; i += 2) {
    /* Constant: '<S7>/ones' incorporates:
     *  Product: '<S7>/Product1'
     */
    tmp = _mm_loadu_pd(&Swingup_MPC_P.ones_Value[i]);

    /* Product: '<S7>/Product1' incorporates:
     *  Concatenate: '<Root>/Vector Concatenate'
     *  Constant: '<S7>/ones'
     */
    _mm_storeu_pd(&Swingup_MPC_B.Product1[i], _mm_mul_pd(tmp, _mm_set1_pd
      (Swingup_MPC_B.VectorConcatenate[0])));
    _mm_storeu_pd(&Swingup_MPC_B.Product1[i + 11], _mm_mul_pd(tmp, _mm_set1_pd
      (Swingup_MPC_B.VectorConcatenate[1])));
    _mm_storeu_pd(&Swingup_MPC_B.Product1[i + 22], _mm_mul_pd(tmp, _mm_set1_pd
      (Swingup_MPC_B.VectorConcatenate[2])));
    _mm_storeu_pd(&Swingup_MPC_B.Product1[i + 33], _mm_mul_pd(tmp, _mm_set1_pd
      (Swingup_MPC_B.VectorConcatenate[3])));
  }

  for (i = 10; i < 11; i++) {
    /* Product: '<S7>/Product1' incorporates:
     *  Concatenate: '<Root>/Vector Concatenate'
     *  Constant: '<S7>/ones'
     */
    Swingup_MPC_B.Product1[i] = Swingup_MPC_P.ones_Value[i] *
      Swingup_MPC_B.VectorConcatenate[0];
    Swingup_MPC_B.Product1[i + 11] = Swingup_MPC_P.ones_Value[i] *
      Swingup_MPC_B.VectorConcatenate[1];
    Swingup_MPC_B.Product1[i + 22] = Swingup_MPC_P.ones_Value[i] *
      Swingup_MPC_B.VectorConcatenate[2];
    Swingup_MPC_B.Product1[i + 33] = Swingup_MPC_P.ones_Value[i] *
      Swingup_MPC_B.VectorConcatenate[3];
  }

  /* RateTransition generated from: '<S7>/Product' incorporates:
   *  Constant: '<S7>/ones'
   */
  if (rtmIsMajorTimeStep(Swingup_MPC_M)) {
    if (Swingup_MPC_DW.TmpRTBAtProductInport1_semaphor == 0) {
      for (i = 0; i < 11; i++) {
        Swingup_MPC_DW.TmpRTBAtProductInport1_Buffer0[i] =
          Swingup_MPC_P.ones_Value[i];
      }
    }

    /* RateTransition generated from: '<S7>/x_Delay' incorporates:
     *  Constant: '<S7>/ones'
     *  Product: '<S7>/Product1'
     */
    if (Swingup_MPC_M->Timing.RateInteraction.TID1_2) {
      memcpy(&Swingup_MPC_DW.TmpRTBAtx_DelayInport2_Buffer[0],
             &Swingup_MPC_B.Product1[0], 44U * sizeof(real_T));
    }

    /* End of RateTransition generated from: '<S7>/x_Delay' */

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */
    /* S-Function Block: Swingup_MPC/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * Swingup_MPC_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed = (Swingup_MPC_P.SmoothSignalGenerator_Amplitude
        != Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Amp || w !=
        Swingup_MPC_DW.SmoothSignalGenerator_RWORK.W);

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
      real_T y_sin = Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos = Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_SmoothSignalGenerator = Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Amp
        * y_sin;

      /* Compute the new sin and cos values */
      Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
        Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
        Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
        Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
        Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

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
        if (y_sin == 0 || Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t ==
            0 || (y_sin < 0) !=
            (Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t < 0)) {
          if (fabs(Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Amp *
                   Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t) <
              Swingup_MPC_P.SmoothSignalGenerator_Amplitude) {
            x = asin(Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Amp *
                     Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t /
                     Swingup_MPC_P.SmoothSignalGenerator_Amplitude);
            Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(w * 0.0005);
            Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(w * 0.0005);
            Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0)) {
              Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -cos(x);
            } else {
              Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.0005;
            Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0) {
              Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
            } else {
              Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
            }

            Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(x);
            Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(x);
          }

          Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Amp =
            Swingup_MPC_P.SmoothSignalGenerator_Amplitude;
          Swingup_MPC_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }
  }

  /* End of RateTransition generated from: '<S7>/Product' */
}

/* Model update function for TID0 */
void Swingup_MPC_update0(void)         /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Swingup_MPC_M)) {
    /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
    Swingup_MPC_DW.DiscreteTimeIntegrator_DSTATE +=
      Swingup_MPC_P.DiscreteTimeIntegrator_gainval *
      Swingup_MPC_B.DataTypeConversion;
    Swingup_MPC_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      Swingup_MPC_B.LogicalOperator1;
  }

  if (rtmIsMajorTimeStep(Swingup_MPC_M)) {
    rt_ertODEUpdateContinuousStates(&Swingup_MPC_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Swingup_MPC_M->Timing.clockTick0)) {
    ++Swingup_MPC_M->Timing.clockTickH0;
  }

  Swingup_MPC_M->Timing.t[0] = rtsiGetSolverStopTime(&Swingup_MPC_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Swingup_MPC_M->Timing.clockTick1)) {
    ++Swingup_MPC_M->Timing.clockTickH1;
  }

  Swingup_MPC_M->Timing.t[1] = Swingup_MPC_M->Timing.clockTick1 *
    Swingup_MPC_M->Timing.stepSize1 + Swingup_MPC_M->Timing.clockTickH1 *
    Swingup_MPC_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Swingup_MPC_derivatives(void)
{
  XDot_Swingup_MPC_T *_rtXdot;
  _rtXdot = ((XDot_Swingup_MPC_T *) Swingup_MPC_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = Swingup_MPC_P.TransferFcn1_A *
    Swingup_MPC_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Swingup_MPC_B.countstorad1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = Swingup_MPC_P.TransferFcn_A *
    Swingup_MPC_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Swingup_MPC_B.Add1;
}

/* Model output function for TID2 */
void Swingup_MPC_output2(void)         /* Sample time: [0.001s, 0.0s] */
{
  __m128d tmp_1;
  sXyXDxkiKhsfpX9ivkpx9WG_Swing_T expl_temp;
  sXyXDxkiKhsfpX9ivkpx9WG_Swing_T expl_temp_0;
  s_GSKgPzH92oA7AAcXEvWMnG_Swin_T ConFcn_workspace_runtimedata;
  s_GSKgPzH92oA7AAcXEvWMnG_Swin_T CostFcn_workspace_runtimedata;
  sttYSJM5GCi2c1Eu0R50efC_Swing_T Out;
  real_T Au[400];
  real_T Auf_data[400];
  real_T tmp_data[240];
  real_T rtb_Selector_0[44];
  real_T tmp_0[44];
  real_T z[44];
  real_T B_data[40];
  real_T ref[40];
  real_T rtb_Selector[36];
  real_T rtb_TmpRTBAtProductInport1[11];
  real_T tmp[10];
  real_T a[3];
  real_T ExitFlag;
  real_T rtb_Saturation1;
  int32_T ic_0[2];
  int32_T Au_tmp;
  int32_T i;
  int32_T ic;
  int32_T x_tmp;
  int8_T ii_data[40];
  boolean_T x[40];
  static const real_T g[40] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.1, 0.1, 0.1, 0.1,
    0.1, 0.1, 0.1, 0.1, 0.1, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

  static real_T h[40] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static real_T j[40] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T a_0[30] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  int32_T tmp_size[2];
  boolean_T exitg1;

  /* MATLAB Function: '<S6>/NLMPC' */
  j[0U] = (rtInf);
  j[1U] = (rtInf);
  j[2U] = (rtInf);
  j[3U] = (rtInf);
  j[4U] = (rtInf);
  j[5U] = (rtInf);
  j[6U] = (rtInf);
  j[7U] = (rtInf);
  j[8U] = (rtInf);
  j[9U] = (rtInf);
  j[10U] = (rtInf);
  j[11U] = (rtInf);
  j[12U] = (rtInf);
  j[13U] = (rtInf);
  j[14U] = (rtInf);
  j[15U] = (rtInf);
  j[16U] = (rtInf);
  j[17U] = (rtInf);
  j[18U] = (rtInf);
  j[19U] = (rtInf);
  j[30U] = (rtInf);
  j[31U] = (rtInf);
  j[32U] = (rtInf);
  j[33U] = (rtInf);
  j[34U] = (rtInf);
  j[35U] = (rtInf);
  j[36U] = (rtInf);
  j[37U] = (rtInf);
  j[38U] = (rtInf);
  j[39U] = (rtInf);
  h[0U] = (rtMinusInf);
  h[1U] = (rtMinusInf);
  h[2U] = (rtMinusInf);
  h[3U] = (rtMinusInf);
  h[4U] = (rtMinusInf);
  h[5U] = (rtMinusInf);
  h[6U] = (rtMinusInf);
  h[7U] = (rtMinusInf);
  h[8U] = (rtMinusInf);
  h[9U] = (rtMinusInf);
  h[10U] = (rtMinusInf);
  h[11U] = (rtMinusInf);
  h[12U] = (rtMinusInf);
  h[13U] = (rtMinusInf);
  h[14U] = (rtMinusInf);
  h[15U] = (rtMinusInf);
  h[16U] = (rtMinusInf);
  h[17U] = (rtMinusInf);
  h[18U] = (rtMinusInf);
  h[19U] = (rtMinusInf);
  h[30U] = (rtMinusInf);
  h[31U] = (rtMinusInf);
  h[32U] = (rtMinusInf);
  h[33U] = (rtMinusInf);
  h[34U] = (rtMinusInf);
  h[35U] = (rtMinusInf);
  h[36U] = (rtMinusInf);
  h[37U] = (rtMinusInf);
  h[38U] = (rtMinusInf);
  h[39U] = (rtMinusInf);

  /* RateTransition generated from: '<S7>/Product' */
  Swingup_MPC_DW.TmpRTBAtProductInport1_semaphor = 1;
  for (i = 0; i < 11; i++) {
    rtb_TmpRTBAtProductInport1[i] =
      Swingup_MPC_DW.TmpRTBAtProductInport1_Buffer0[i];
  }

  Swingup_MPC_DW.TmpRTBAtProductInport1_semaphor = 0;

  /* End of RateTransition generated from: '<S7>/Product' */

  /* Delay: '<S7>/mv_Delay' incorporates:
   *  Delay: '<Root>/Delay'
   *  Product: '<S7>/Product'
   *  RateTransition generated from: '<S7>/Product'
   */
  if (Swingup_MPC_DW.icLoad) {
    for (i = 0; i <= 8; i += 2) {
      tmp_1 = _mm_loadu_pd(&rtb_TmpRTBAtProductInport1[i]);
      _mm_storeu_pd(&Swingup_MPC_DW.mv_Delay_DSTATE[i], _mm_mul_pd(tmp_1,
        _mm_set1_pd(Swingup_MPC_DW.Delay_DSTATE)));
    }

    for (i = 10; i < 11; i++) {
      Swingup_MPC_DW.mv_Delay_DSTATE[i] = rtb_TmpRTBAtProductInport1[i] *
        Swingup_MPC_DW.Delay_DSTATE;
    }
  }

  /* Delay: '<S7>/x_Delay' incorporates:
   *  RateTransition generated from: '<S7>/x_Delay'
   */
  if (Swingup_MPC_DW.icLoad_l) {
    memcpy(&Swingup_MPC_DW.x_Delay_DSTATE[0],
           &Swingup_MPC_DW.TmpRTBAtx_DelayInport2_Buffer[0], 44U * sizeof(real_T));
  }

  /* Selector: '<S7>/Selector' incorporates:
   *  Constant: '<S7>/Constant'
   *  Delay: '<S7>/x_Delay'
   */
  for (i = 0; i < 9; i++) {
    ic = (int32_T)Swingup_MPC_P.Constant_Value_k[i];
    rtb_Selector[i] = Swingup_MPC_DW.x_Delay_DSTATE[ic - 1];
    rtb_Selector[i + 9] = Swingup_MPC_DW.x_Delay_DSTATE[ic + 10];
    rtb_Selector[i + 18] = Swingup_MPC_DW.x_Delay_DSTATE[ic + 21];
    rtb_Selector[i + 27] = Swingup_MPC_DW.x_Delay_DSTATE[ic + 32];
  }

  /* End of Selector: '<S7>/Selector' */

  /* Delay: '<S7>/slack_delay' incorporates:
   *  Constant: '<S2>/e.init_zero'
   */
  if (Swingup_MPC_DW.icLoad_n) {
    Swingup_MPC_DW.slack_delay_DSTATE = Swingup_MPC_P.einit_zero_Value;
  }

  /* MATLAB Function: '<S6>/NLMPC' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Delay: '<Root>/Delay'
   *  Delay: '<S7>/mv_Delay'
   *  Delay: '<S7>/slack_delay'
   *  RateTransition generated from: '<S6>/NLMPC'
   *  Selector: '<S7>/Selector'
   *  Selector: '<S7>/Selector1'
   */
  /* MATLAB Function 'Nonlinear MPC Controller/MPC/NLMPC': '<S28>:1' */
  /* '<S28>:1:100' */
  ref[0] = Swingup_MPC_P.Constant_Value[0];
  ref[10] = Swingup_MPC_P.Constant_Value[1];
  ref[20] = Swingup_MPC_P.Constant_Value[2];
  ref[30] = Swingup_MPC_P.Constant_Value[3];
  for (i = 0; i < 9; i++) {
    ref[i + 1] = Swingup_MPC_P.Constant_Value[0];
    ref[i + 11] = Swingup_MPC_P.Constant_Value[1];
    ref[i + 21] = Swingup_MPC_P.Constant_Value[2];
    ref[i + 31] = Swingup_MPC_P.Constant_Value[3];
  }

  for (i = 0; i < 40; i++) {
    rtb_Saturation1 = ref[i];
    expl_temp.References[i] = rtb_Saturation1;
    CostFcn_workspace_runtimedata.ref[i] = rtb_Saturation1;
  }

  /* '<S28>:1:123' */
  /* '<S28>:1:125' */
  for (i = 0; i < 400; i++) {
    Au[i] = 0.0;
  }

  for (i = 0; i < 40; i++) {
    ref[i] = 0.0;
  }

  ic = 0;
  for (i = 0; i < 10; i++) {
    x_tmp = i << 2;
    x[x_tmp] = false;
    x[x_tmp + 1] = false;
    x_tmp = i << 2;
    x[x_tmp + 2] = true;
    x[x_tmp + 3] = true;
    Au[44 * i] = -1.0;
    x_tmp = i << 2;
    Au_tmp = 40 * i + x_tmp;
    Au[Au_tmp + 1] = 1.0;
    Au[Au_tmp + 2] = -1.0;
    Au[Au_tmp + 3] = 1.0;
    ref[x_tmp] = (rtInf);
    ref[x_tmp + 1] = (rtInf);
    ref[x_tmp + 2] = 5.0;
    ref[x_tmp + 3] = 5.0;
    if (i + 1 == 1) {
      ref[x_tmp] -= Swingup_MPC_DW.Delay_DSTATE;
      ref[x_tmp + 1] += Swingup_MPC_DW.Delay_DSTATE;
    } else {
      Au_tmp = (i - 1) * 40 + x_tmp;
      Au[Au_tmp] = 1.0;
      Au[Au_tmp + 1] = -1.0;
    }
  }

  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 40)) {
    if (x[i]) {
      ic++;
      ii_data[ic - 1] = (int8_T)(i + 1);
      if (ic >= 40) {
        exitg1 = true;
      } else {
        i++;
      }
    } else {
      i++;
    }
  }

  if (ic < 1) {
    ic = 0;
  }

  if (ic > 0) {
    Au_tmp = ic;
    for (i = 0; i < ic; i++) {
      B_data[i] = ref[ii_data[i] - 1];
    }

    x_tmp = ic * 10;
    for (i = 0; i < x_tmp; i++) {
      Auf_data[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      for (x_tmp = 0; x_tmp < ic; x_tmp++) {
        Auf_data[x_tmp + ic * i] = Au[(40 * i + ii_data[x_tmp]) - 1];
      }
    }

    ic_0[0] = ic;
    ic_0[1] = 10;
    Swingup_MPC_mtimes(Auf_data, ic_0, tmp_data, tmp_size);
    x_tmp = ic * 40;
    for (i = 0; i < x_tmp; i++) {
      Swingup_MPC_B.A_data[i] = 0.0;
    }

    x_tmp = ic * 3;
    for (i = 0; i < x_tmp; i++) {
      Swingup_MPC_B.A_data[i + ic * 40] = tmp_data[i];
    }

    for (i = 0; i < ic; i++) {
      Swingup_MPC_B.A_data[(i + ic * 40) + ic * 3] = 0.0;
    }
  } else {
    Au_tmp = 0;
  }

  /* '<S28>:1:128' */
  CostFcn_workspace_runtimedata.x[0] =
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[0];
  CostFcn_workspace_runtimedata.x[1] =
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[1];
  CostFcn_workspace_runtimedata.x[2] =
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[2];
  CostFcn_workspace_runtimedata.x[3] =
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[3];
  CostFcn_workspace_runtimedata.lastMV = Swingup_MPC_DW.Delay_DSTATE;
  memcpy(&CostFcn_workspace_runtimedata.OutputWeights[0], &g[0], 40U * sizeof
         (real_T));
  for (i = 0; i < 10; i++) {
    CostFcn_workspace_runtimedata.MVWeights[i] = 0.0;
    CostFcn_workspace_runtimedata.MVRateWeights[i] = 0.1;
  }

  CostFcn_workspace_runtimedata.ECRWeight = 100000.0;
  for (i = 0; i < 40; i++) {
    CostFcn_workspace_runtimedata.OutputMin[i] = h[i];
    CostFcn_workspace_runtimedata.OutputMax[i] = j[i];
    CostFcn_workspace_runtimedata.StateMin[i] = (rtMinusInf);
    CostFcn_workspace_runtimedata.StateMax[i] = (rtInf);
  }

  for (i = 0; i < 10; i++) {
    CostFcn_workspace_runtimedata.MVMin[i] = -5.0;
    CostFcn_workspace_runtimedata.MVMax[i] = 5.0;
    CostFcn_workspace_runtimedata.MVRateMin[i] = (rtMinusInf);
    CostFcn_workspace_runtimedata.MVRateMax[i] = (rtInf);
    CostFcn_workspace_runtimedata.MVScaledTarget[i] = 0.0;
  }

  /* '<S28>:1:129' */
  ConFcn_workspace_runtimedata.x[0] =
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[0];
  ConFcn_workspace_runtimedata.x[1] =
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[1];
  ConFcn_workspace_runtimedata.x[2] =
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[2];
  ConFcn_workspace_runtimedata.x[3] =
    Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[3];
  ConFcn_workspace_runtimedata.lastMV = Swingup_MPC_DW.Delay_DSTATE;
  memcpy(&ConFcn_workspace_runtimedata.ref[0],
         &CostFcn_workspace_runtimedata.ref[0], 40U * sizeof(real_T));
  memcpy(&ConFcn_workspace_runtimedata.OutputWeights[0], &g[0], 40U * sizeof
         (real_T));
  for (i = 0; i < 10; i++) {
    ConFcn_workspace_runtimedata.MVWeights[i] = 0.0;
    ConFcn_workspace_runtimedata.MVRateWeights[i] = 0.1;
  }

  ConFcn_workspace_runtimedata.ECRWeight = 100000.0;
  for (i = 0; i < 40; i++) {
    ConFcn_workspace_runtimedata.OutputMin[i] = h[i];
    ConFcn_workspace_runtimedata.OutputMax[i] = j[i];
    ConFcn_workspace_runtimedata.StateMin[i] = (rtMinusInf);
    ConFcn_workspace_runtimedata.StateMax[i] = (rtInf);
  }

  /* '<S28>:1:144' */
  expl_temp.PassivityUsePredictedX = true;
  expl_temp.OutputPassivityIndex = 0.1;
  expl_temp.InputPassivityIndex = 0.0;
  expl_temp.MVIndex = 1.0;
  expl_temp.NumOfInputs = 1.0;
  expl_temp.NumOfOutputs = 4.0;
  expl_temp.NumOfStates = 4.0;
  expl_temp.PredictionHorizon = 10.0;
  expl_temp.LastMV = Swingup_MPC_DW.Delay_DSTATE;
  expl_temp.CurrentStates[0] = Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[0];
  expl_temp.CurrentStates[1] = Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[1];
  expl_temp.CurrentStates[2] = Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[2];
  expl_temp.CurrentStates[3] = Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[3];
  expl_temp.Ts = 0.001;
  expl_temp_0.PassivityUsePredictedX = true;
  expl_temp_0.OutputPassivityIndex = 0.1;
  expl_temp_0.InputPassivityIndex = 0.0;
  expl_temp_0.MVIndex = 1.0;
  expl_temp_0.NumOfInputs = 1.0;
  expl_temp_0.NumOfOutputs = 4.0;
  expl_temp_0.NumOfStates = 4.0;
  expl_temp_0.PredictionHorizon = 10.0;
  for (i = 0; i < 10; i++) {
    ConFcn_workspace_runtimedata.MVMin[i] = -5.0;
    ConFcn_workspace_runtimedata.MVMax[i] = 5.0;
    ConFcn_workspace_runtimedata.MVRateMin[i] = (rtMinusInf);
    ConFcn_workspace_runtimedata.MVRateMax[i] = (rtInf);
    ConFcn_workspace_runtimedata.MVScaledTarget[i] = 0.0;
    expl_temp.MVTarget[i] = 0.0;
    expl_temp_0.MVTarget[i] = 0.0;
  }

  memcpy(&expl_temp_0.References[0], &expl_temp.References[0], 40U * sizeof
         (real_T));
  expl_temp_0.LastMV = Swingup_MPC_DW.Delay_DSTATE;
  expl_temp_0.CurrentStates[0] = Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[0];
  expl_temp_0.CurrentStates[1] = Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[1];
  expl_temp_0.CurrentStates[2] = Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[2];
  expl_temp_0.CurrentStates[3] = Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[3];
  expl_temp_0.Ts = 0.001;
  for (i = 0; i < 9; i++) {
    ic = i << 2;
    ref[ic] = rtb_Selector[i];
    ref[ic + 1] = rtb_Selector[i + 9];
    ref[ic + 2] = rtb_Selector[i + 18];
    ref[ic + 3] = rtb_Selector[i + 27];
  }

  ref[36] = rtb_Selector[8];
  ref[37] = rtb_Selector[17];
  ref[38] = rtb_Selector[26];
  ref[39] = rtb_Selector[35];
  for (i = 0; i < 9; i++) {
    tmp[i] = Swingup_MPC_DW.mv_Delay_DSTATE[(int32_T)
      Swingup_MPC_P.Constant1_Value[i] - 1];
  }

  tmp[9] = Swingup_MPC_DW.mv_Delay_DSTATE[(int32_T)
    Swingup_MPC_P.Constant1_Value[8] - 1];
  for (i = 0; i < 3; i++) {
    a[i] = 0.0;
    for (ic = 0; ic < 10; ic++) {
      a[i] += (real_T)a_0[3 * ic + i] * tmp[ic];
    }
  }

  rtb_Selector_0[40] = a[0];
  rtb_Selector_0[41] = a[1];
  rtb_Selector_0[42] = a[2];
  rtb_Selector_0[43] = Swingup_MPC_DW.slack_delay_DSTATE;
  tmp_0[40] = (rtMinusInf);
  tmp_0[41] = (rtMinusInf);
  tmp_0[42] = (rtMinusInf);
  tmp_0[43] = 0.0;
  for (i = 0; i < 40; i++) {
    rtb_Selector_0[i] = ref[i];
    tmp_0[i] = (rtMinusInf);
  }

  Swingup_MPC_fmincon(&CostFcn_workspace_runtimedata, &expl_temp, rtb_Selector_0,
                      Swingup_MPC_B.A_data, B_data, &Au_tmp, tmp_0,
                      &ConFcn_workspace_runtimedata, &expl_temp_0, z,
                      &rtb_Saturation1, &ExitFlag, &Out);

  /* '<S28>:1:144' */
  if ((ExitFlag == 0.0) && (Out.constrviolation > 1.0E-6)) {
    /* '<S28>:1:146' */
    /* '<S28>:1:147' */
    ExitFlag = -2.0;
  }

  /* '<S28>:1:150' */
  Swingup_MPC_znlmpc_getXUe(z, Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer,
    Swingup_MPC_B.xseq, rtb_TmpRTBAtProductInport1, &Swingup_MPC_B.e);
  if (ExitFlag > 0.0) {
    /* '<S28>:1:152' */
    /* '<S28>:1:153' */
    Swingup_MPC_B.mv = rtb_TmpRTBAtProductInport1[0];
  } else {
    /* '<S28>:1:155' */
    Swingup_MPC_B.mv = Swingup_MPC_DW.Delay_DSTATE;
  }

  /* '<S28>:1:158' */
  /* '<S28>:1:160' */
  /* '<S28>:1:161' */
  memcpy(&Swingup_MPC_B.mvseq[0], &rtb_TmpRTBAtProductInport1[0], 11U * sizeof
         (real_T));

  /* Saturate: '<Root>/Saturation1' */
  /* '<S28>:1:162' */
  /* '<S28>:1:163' */
  /* '<S28>:1:164' */
  /* '<S28>:1:165' */
  if (Swingup_MPC_B.mv > Swingup_MPC_P.Saturation1_UpperSat) {
    rtb_Saturation1 = Swingup_MPC_P.Saturation1_UpperSat;
  } else if (Swingup_MPC_B.mv < Swingup_MPC_P.Saturation1_LowerSat) {
    rtb_Saturation1 = Swingup_MPC_P.Saturation1_LowerSat;
  } else {
    rtb_Saturation1 = Swingup_MPC_B.mv;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Swingup_MPC/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Swingup_MPC_DW.HILInitialize_Card,
      &Swingup_MPC_P.HILWriteAnalog_channels, 1, &rtb_Saturation1);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
    }
  }

  /* RateTransition: '<S5>/Rate Transition' */
  Swingup_MPC_DW.RateTransition_Buffer0 = Swingup_MPC_B.mv;
}

/* Model update function for TID2 */
void Swingup_MPC_update2(void)         /* Sample time: [0.001s, 0.0s] */
{
  /* Update for Delay: '<Root>/Delay' */
  Swingup_MPC_DW.Delay_DSTATE = Swingup_MPC_B.mv;

  /* Update for Delay: '<S7>/mv_Delay' */
  Swingup_MPC_DW.icLoad = false;
  memcpy(&Swingup_MPC_DW.mv_Delay_DSTATE[0], &Swingup_MPC_B.mvseq[0], 11U *
         sizeof(real_T));

  /* Update for Delay: '<S7>/x_Delay' */
  Swingup_MPC_DW.icLoad_l = false;
  memcpy(&Swingup_MPC_DW.x_Delay_DSTATE[0], &Swingup_MPC_B.xseq[0], 44U * sizeof
         (real_T));

  /* Update for Delay: '<S7>/slack_delay' */
  Swingup_MPC_DW.icLoad_n = false;
  Swingup_MPC_DW.slack_delay_DSTATE = Swingup_MPC_B.e;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Swingup_MPC_M->Timing.clockTick2)) {
    ++Swingup_MPC_M->Timing.clockTickH2;
  }

  Swingup_MPC_M->Timing.t[2] = Swingup_MPC_M->Timing.clockTick2 *
    Swingup_MPC_M->Timing.stepSize2 + Swingup_MPC_M->Timing.clockTickH2 *
    Swingup_MPC_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Swingup_MPC_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Swingup_MPC_output0();
    break;

   case 2 :
    Swingup_MPC_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Swingup_MPC_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Swingup_MPC_update0();
    break;

   case 2 :
    Swingup_MPC_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Swingup_MPC_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Swingup_MPC/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0", &Swingup_MPC_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Swingup_MPC_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
      return;
    }

    if ((Swingup_MPC_P.HILInitialize_AIPStart && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Swingup_MPC_DW.HILInitialize_Card,
        &Swingup_MPC_P.HILInitialize_AIChannels, 1U,
        &Swingup_MPC_P.HILInitialize_AILow, &Swingup_MPC_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_MPC_P.HILInitialize_AOPStart && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Swingup_MPC_DW.HILInitialize_Card,
        &Swingup_MPC_P.HILInitialize_AOChannels, 1U,
        &Swingup_MPC_P.HILInitialize_AOLow, &Swingup_MPC_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_MPC_P.HILInitialize_AOStart && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Swingup_MPC_DW.HILInitialize_Card,
        &Swingup_MPC_P.HILInitialize_AOChannels, 1U,
        &Swingup_MPC_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }

    if (Swingup_MPC_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Swingup_MPC_DW.HILInitialize_Card,
         &Swingup_MPC_P.HILInitialize_AOChannels, 1U,
         &Swingup_MPC_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Swingup_MPC_DW.HILInitialize_Card, NULL,
      0U, &Swingup_MPC_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
      return;
    }

    if ((Swingup_MPC_P.HILInitialize_DOStart && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Swingup_MPC_DW.HILInitialize_Card,
        &Swingup_MPC_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Swingup_MPC_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }

    if (Swingup_MPC_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Swingup_MPC_DW.HILInitialize_Card,
         &Swingup_MPC_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &Swingup_MPC_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_MPC_P.HILInitialize_EIPStart && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_EIPEnter && is_switching)) {
      Swingup_MPC_DW.HILInitialize_QuadratureModes[0] =
        Swingup_MPC_P.HILInitialize_EIQuadrature;
      Swingup_MPC_DW.HILInitialize_QuadratureModes[1] =
        Swingup_MPC_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(Swingup_MPC_DW.HILInitialize_Card,
        Swingup_MPC_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &Swingup_MPC_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_MPC_P.HILInitialize_EIStart && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_EIEnter && is_switching)) {
      Swingup_MPC_DW.HILInitialize_InitialEICounts[0] =
        Swingup_MPC_P.HILInitialize_EIInitial;
      Swingup_MPC_DW.HILInitialize_InitialEICounts[1] =
        Swingup_MPC_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Swingup_MPC_DW.HILInitialize_Card,
        Swingup_MPC_P.HILInitialize_EIChannels, 2U,
        &Swingup_MPC_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }

    if ((Swingup_MPC_P.HILInitialize_OOStart && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Swingup_MPC_DW.HILInitialize_Card,
        Swingup_MPC_P.HILInitialize_OOChannels, 3U,
        Swingup_MPC_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }

    if (Swingup_MPC_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Swingup_MPC_DW.HILInitialize_Card,
         Swingup_MPC_P.HILInitialize_OOChannels, 3U,
         Swingup_MPC_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: Swingup_MPC/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Swingup_MPC_DW.HILInitialize_Card,
      Swingup_MPC_P.HILReadEncoderTimebase_SamplesI,
      &Swingup_MPC_P.HILReadEncoderTimebase_Channels, 1,
      &Swingup_MPC_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Swingup_MPC_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Swingup_MPC_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S5>/Rate Transition' */
  Swingup_MPC_B.RateTransition = Swingup_MPC_P.RateTransition_InitialCondition;

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */

  /* S-Function Block: Swingup_MPC/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / Swingup_MPC_P.SmoothSignalGenerator_Frequency;
    Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Amp =
      Swingup_MPC_P.SmoothSignalGenerator_Amplitude;
    Swingup_MPC_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      Swingup_MPC_P.SmoothSignalGenerator_Frequency;
    Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (Swingup_MPC_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (Swingup_MPC_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (Swingup_MPC_P.SmoothSignalGenerator_InitialPh);
    Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (Swingup_MPC_P.SmoothSignalGenerator_InitialPh);
  }

  /* InitializeConditions for RateTransition: '<S5>/Rate Transition' */
  Swingup_MPC_DW.RateTransition_Buffer0 =
    Swingup_MPC_P.RateTransition_InitialCondition;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Swingup_MPC_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  Swingup_MPC_DW.DiscreteTimeIntegrator_DSTATE =
    Swingup_MPC_P.DiscreteTimeIntegrator_IC;
  Swingup_MPC_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Swingup_MPC_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  Swingup_MPC_DW.Delay_DSTATE = Swingup_MPC_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S7>/mv_Delay' */
  Swingup_MPC_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S7>/x_Delay' */
  Swingup_MPC_DW.icLoad_l = true;

  /* InitializeConditions for Delay: '<S7>/slack_delay' */
  Swingup_MPC_DW.icLoad_n = true;
}

/* Model terminate function */
void Swingup_MPC_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Swingup_MPC/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Swingup_MPC_DW.HILInitialize_Card);
    hil_monitor_stop_all(Swingup_MPC_DW.HILInitialize_Card);
    is_switching = false;
    if ((Swingup_MPC_P.HILInitialize_AOTerminate && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Swingup_MPC_P.HILInitialize_DOTerminate && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Swingup_MPC_P.HILInitialize_OOTerminate && !is_switching) ||
        (Swingup_MPC_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Swingup_MPC_DW.HILInitialize_Card
                         , &Swingup_MPC_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Swingup_MPC_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Swingup_MPC_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Swingup_MPC_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Swingup_MPC_P.HILInitialize_DOFinal
                         , Swingup_MPC_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Swingup_MPC_DW.HILInitialize_Card,
            &Swingup_MPC_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Swingup_MPC_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Swingup_MPC_DW.HILInitialize_Card,
            &Swingup_MPC_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &Swingup_MPC_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Swingup_MPC_DW.HILInitialize_Card,
            Swingup_MPC_P.HILInitialize_OOChannels, num_final_other_outputs,
            Swingup_MPC_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Swingup_MPC_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Swingup_MPC_DW.HILInitialize_Card);
    hil_monitor_delete_all(Swingup_MPC_DW.HILInitialize_Card);
    hil_close(Swingup_MPC_DW.HILInitialize_Card);
    Swingup_MPC_DW.HILInitialize_Card = NULL;
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
  if (tid == 1)
    tid = 0;
  Swingup_MPC_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Swingup_MPC_update(tid);
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
  Swingup_MPC_initialize();
}

void MdlTerminate(void)
{
  Swingup_MPC_terminate();
}

/* Registration function */
RT_MODEL_Swingup_MPC_T *Swingup_MPC(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Swingup_MPC_M, 0,
                sizeof(RT_MODEL_Swingup_MPC_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Swingup_MPC_M->solverInfo,
                          &Swingup_MPC_M->Timing.simTimeStep);
    rtsiSetTPtr(&Swingup_MPC_M->solverInfo, &rtmGetTPtr(Swingup_MPC_M));
    rtsiSetStepSizePtr(&Swingup_MPC_M->solverInfo,
                       &Swingup_MPC_M->Timing.stepSize0);
    rtsiSetdXPtr(&Swingup_MPC_M->solverInfo, &Swingup_MPC_M->derivs);
    rtsiSetContStatesPtr(&Swingup_MPC_M->solverInfo, (real_T **)
                         &Swingup_MPC_M->contStates);
    rtsiSetNumContStatesPtr(&Swingup_MPC_M->solverInfo,
      &Swingup_MPC_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Swingup_MPC_M->solverInfo,
      &Swingup_MPC_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Swingup_MPC_M->solverInfo,
      &Swingup_MPC_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Swingup_MPC_M->solverInfo,
      &Swingup_MPC_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Swingup_MPC_M->solverInfo, (&rtmGetErrorStatus
      (Swingup_MPC_M)));
    rtsiSetRTModelPtr(&Swingup_MPC_M->solverInfo, Swingup_MPC_M);
  }

  rtsiSetSimTimeStep(&Swingup_MPC_M->solverInfo, MAJOR_TIME_STEP);
  Swingup_MPC_M->intgData.f[0] = Swingup_MPC_M->odeF[0];
  Swingup_MPC_M->contStates = ((real_T *) &Swingup_MPC_X);
  rtsiSetSolverData(&Swingup_MPC_M->solverInfo, (void *)&Swingup_MPC_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Swingup_MPC_M->solverInfo, false);
  rtsiSetSolverName(&Swingup_MPC_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Swingup_MPC_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Swingup_MPC_M points to
       static memory which is guaranteed to be non-NULL" */
    Swingup_MPC_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Swingup_MPC_M->Timing.sampleTimes = (&Swingup_MPC_M->
      Timing.sampleTimesArray[0]);
    Swingup_MPC_M->Timing.offsetTimes = (&Swingup_MPC_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    Swingup_MPC_M->Timing.sampleTimes[0] = (0.0);
    Swingup_MPC_M->Timing.sampleTimes[1] = (0.0005);
    Swingup_MPC_M->Timing.sampleTimes[2] = (0.001);

    /* task offsets */
    Swingup_MPC_M->Timing.offsetTimes[0] = (0.0);
    Swingup_MPC_M->Timing.offsetTimes[1] = (0.0);
    Swingup_MPC_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Swingup_MPC_M, &Swingup_MPC_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Swingup_MPC_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = Swingup_MPC_M->Timing.perTaskSampleHitsArray;
    Swingup_MPC_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Swingup_MPC_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Swingup_MPC_M, -1);
  Swingup_MPC_M->Timing.stepSize0 = 0.0005;
  Swingup_MPC_M->Timing.stepSize1 = 0.0005;
  Swingup_MPC_M->Timing.stepSize2 = 0.001;

  /* External mode info */
  Swingup_MPC_M->Sizes.checksums[0] = (3749285996U);
  Swingup_MPC_M->Sizes.checksums[1] = (3713643326U);
  Swingup_MPC_M->Sizes.checksums[2] = (910804090U);
  Swingup_MPC_M->Sizes.checksums[3] = (3496678677U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Swingup_MPC_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Swingup_MPC_M->extModeInfo,
      &Swingup_MPC_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Swingup_MPC_M->extModeInfo,
                        Swingup_MPC_M->Sizes.checksums);
    rteiSetTPtr(Swingup_MPC_M->extModeInfo, rtmGetTPtr(Swingup_MPC_M));
  }

  Swingup_MPC_M->solverInfoPtr = (&Swingup_MPC_M->solverInfo);
  Swingup_MPC_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&Swingup_MPC_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&Swingup_MPC_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Swingup_MPC_M->blockIO = ((void *) &Swingup_MPC_B);
  (void) memset(((void *) &Swingup_MPC_B), 0,
                sizeof(B_Swingup_MPC_T));

  {
    int32_T i;
    for (i = 0; i < 44; i++) {
      Swingup_MPC_B.Product1[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      Swingup_MPC_B.mvseq[i] = 0.0;
    }

    for (i = 0; i < 44; i++) {
      Swingup_MPC_B.xseq[i] = 0.0;
    }

    Swingup_MPC_B.countstorad1 = 0.0;
    Swingup_MPC_B.Gain = 0.0;
    Swingup_MPC_B.Gain_f[0] = 0.0;
    Swingup_MPC_B.Gain_f[1] = 0.0;
    Swingup_MPC_B.RateTransition = 0.0;
    Swingup_MPC_B.Gain_o = 0.0;
    Swingup_MPC_B.DataTypeConversion = 0.0;
    Swingup_MPC_B.Gain1 = 0.0;
    Swingup_MPC_B.Add1 = 0.0;
    Swingup_MPC_B.VectorConcatenate[0] = 0.0;
    Swingup_MPC_B.VectorConcatenate[1] = 0.0;
    Swingup_MPC_B.VectorConcatenate[2] = 0.0;
    Swingup_MPC_B.VectorConcatenate[3] = 0.0;
    Swingup_MPC_B.mv = 0.0;
    Swingup_MPC_B.e = 0.0;
  }

  /* parameters */
  Swingup_MPC_M->defaultParam = ((real_T *)&Swingup_MPC_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Swingup_MPC_X;
    Swingup_MPC_M->contStates = (x);
    (void) memset((void *)&Swingup_MPC_X, 0,
                  sizeof(X_Swingup_MPC_T));
  }

  /* states (dwork) */
  Swingup_MPC_M->dwork = ((void *) &Swingup_MPC_DW);
  (void) memset((void *)&Swingup_MPC_DW, 0,
                sizeof(DW_Swingup_MPC_T));
  Swingup_MPC_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  Swingup_MPC_DW.Delay_DSTATE = 0.0;

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      Swingup_MPC_DW.mv_Delay_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 44; i++) {
      Swingup_MPC_DW.x_Delay_DSTATE[i] = 0.0;
    }
  }

  Swingup_MPC_DW.slack_delay_DSTATE = 0.0;
  Swingup_MPC_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Swingup_MPC_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Swingup_MPC_DW.RateTransition_Buffer0 = 0.0;
  Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[0] = 0.0;
  Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[1] = 0.0;
  Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[2] = 0.0;
  Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer[3] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      Swingup_MPC_DW.TmpRTBAtProductInport1_Buffer0[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 44; i++) {
      Swingup_MPC_DW.TmpRTBAtx_DelayInport2_Buffer[i] = 0.0;
    }
  }

  Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Amp = 0.0;
  Swingup_MPC_DW.SmoothSignalGenerator_RWORK.W = 0.0;
  Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = 0.0;
  Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = 0.0;
  Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0.0;
  Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Cos_w_t = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Swingup_MPC_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Swingup_MPC_M->Sizes.numContStates = (2);/* Number of continuous states */
  Swingup_MPC_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Swingup_MPC_M->Sizes.numY = (0);     /* Number of model outputs */
  Swingup_MPC_M->Sizes.numU = (0);     /* Number of model inputs */
  Swingup_MPC_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Swingup_MPC_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Swingup_MPC_M->Sizes.numBlocks = (78);/* Number of blocks */
  Swingup_MPC_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  Swingup_MPC_M->Sizes.numBlockPrms = (169);/* Sum of parameter "widths" */
  return Swingup_MPC_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
