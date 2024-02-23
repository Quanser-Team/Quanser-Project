/*
 * MPC_linear_private.h
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

#ifndef RTW_HEADER_MPC_linear_private_h_
#define RTW_HEADER_MPC_linear_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "MPC_linear_types.h"
#include "MPC_linear.h"
#ifndef HALF_PI
#define HALF_PI                        1.5707963267948966192313216916398
#endif

#ifndef ONE_PI
#define ONE_PI                         3.1415926535897932384626433832795
#endif

#ifndef TWO_PI
#define TWO_PI                         6.2831853071795864769252867665590
#endif

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);

/* private model entry point functions */
extern void MPC_linear_derivatives(void);

#endif                                 /* RTW_HEADER_MPC_linear_private_h_ */
