/*
 * Kalman_Filterr.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Kalman_Filterr".
 *
 * Model version              : 8.13
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Nov 15 16:04:29 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Kalman_Filterr.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Kalman_Filterr_private.h"
#include <string.h>
#include <emmintrin.h>
#include <float.h>
#include "Kalman_Filterr_dt.h"

/* Block signals (default storage) */
B_Kalman_Filterr_T Kalman_Filterr_B;

/* Continuous states */
X_Kalman_Filterr_T Kalman_Filterr_X;

/* Block states (default storage) */
DW_Kalman_Filterr_T Kalman_Filterr_DW;

/* Real-time model */
static RT_MODEL_Kalman_Filterr_T Kalman_Filterr_M_;
RT_MODEL_Kalman_Filterr_T *const Kalman_Filterr_M = &Kalman_Filterr_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Kalman_Filterr_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Kalman_Filterr_M, 2);
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
  if (Kalman_Filterr_M->Timing.TaskCounters.TID[1] == 0) {
    Kalman_Filterr_M->Timing.RateInteraction.TID1_2 =
      (Kalman_Filterr_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Kalman_Filterr_M->Timing.perTaskSampleHits[5] =
      Kalman_Filterr_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Kalman_Filterr_M->Timing.TaskCounters.TID[2])++;
  if ((Kalman_Filterr_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.02s, 0.0s] */
    Kalman_Filterr_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Kalman_Filterr_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
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

/* Model output function for TID0 */
void Kalman_Filterr_output0(void)      /* Sample time: [0.0s, 0.0s] */
{
  __m128d tmp_3;
  __m128d tmp_4;
  const real_T *tmp_5;
  real_T temp;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  int32_T i;
  int32_T i_0;
  if (rtmIsMajorTimeStep(Kalman_Filterr_M)) {
    /* set solver stop time */
    if (!(Kalman_Filterr_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Kalman_Filterr_M->solverInfo,
                            ((Kalman_Filterr_M->Timing.clockTickH0 + 1) *
        Kalman_Filterr_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Kalman_Filterr_M->solverInfo,
                            ((Kalman_Filterr_M->Timing.clockTick0 + 1) *
        Kalman_Filterr_M->Timing.stepSize0 +
        Kalman_Filterr_M->Timing.clockTickH0 *
        Kalman_Filterr_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Kalman_Filterr_M)) {
    Kalman_Filterr_M->Timing.t[0] = rtsiGetT(&Kalman_Filterr_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Kalman_Filterr_DW.MeasurementUpdate_SubsysRanBC);
  if (rtmIsMajorTimeStep(Kalman_Filterr_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S8>/HIL Read Encoder Timebase' */

    /* S-Function Block: Kalman_Filterr/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (Kalman_Filterr_DW.HILReadEncoderTimebase_Task, 1,
         &Kalman_Filterr_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        Kalman_Filterr_B.HILReadEncoderTimebase_o1 = 0;
        Kalman_Filterr_B.HILReadEncoderTimebase_o2 = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
      } else {
        Kalman_Filterr_B.HILReadEncoderTimebase_o1 =
          Kalman_Filterr_DW.HILReadEncoderTimebase_Buffer[0];
        Kalman_Filterr_B.HILReadEncoderTimebase_o2 =
          Kalman_Filterr_DW.HILReadEncoderTimebase_Buffer[1];
      }
    }
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = Kalman_Filterr_P.SignalGenerator_Frequency * Kalman_Filterr_M->
    Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    /* SignalGenerator: '<Root>/Signal Generator' */
    Kalman_Filterr_B.SignalGenerator =
      Kalman_Filterr_P.SignalGenerator_Amplitude;
  } else {
    /* SignalGenerator: '<Root>/Signal Generator' */
    Kalman_Filterr_B.SignalGenerator =
      -Kalman_Filterr_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Gain: '<Root>/Gain' */
  Kalman_Filterr_B.Gain = Kalman_Filterr_P.Gain_Gain *
    Kalman_Filterr_B.SignalGenerator;

  /* Gain: '<S1>/Gain1' */
  Kalman_Filterr_B.Gain1 = Kalman_Filterr_P.Gain1_Gain * Kalman_Filterr_B.Gain;
  if (rtmIsMajorTimeStep(Kalman_Filterr_M)) {
    /* Gain: '<S62>/Arm: counts to rad' */
    Kalman_Filterr_B.Armcountstorad = Kalman_Filterr_P.Armcountstorad_Gain *
      Kalman_Filterr_B.HILReadEncoderTimebase_o1;
  }

  /* Gain: '<S7>/Gain' */
  Kalman_Filterr_B.Gain_b[0] = Kalman_Filterr_P.Gain_Gain_a *
    Kalman_Filterr_B.Gain1;
  Kalman_Filterr_B.Gain_b[1] = Kalman_Filterr_P.Gain_Gain_a *
    Kalman_Filterr_B.Armcountstorad;
  if (rtmIsMajorTimeStep(Kalman_Filterr_M)) {
    /* Gain: '<S62>/Pendulum:  counts to rad' */
    Kalman_Filterr_B.Pendulumcountstorad =
      Kalman_Filterr_P.Pendulumcountstorad_Gain *
      Kalman_Filterr_B.HILReadEncoderTimebase_o2;

    /* Math: '<S62>/Math Function' incorporates:
     *  Constant: '<S62>/Constant1'
     */
    Kalman_Filterr_B.MathFunction = rt_modd_snf
      (Kalman_Filterr_B.Pendulumcountstorad, Kalman_Filterr_P.Constant1_Value);

    /* Bias: '<S62>/Bias' */
    Kalman_Filterr_B.Bias = Kalman_Filterr_B.MathFunction +
      Kalman_Filterr_P.Bias_Bias;

    /* Constant: '<S3>/X0' */
    Kalman_Filterr_B.X0[0] = Kalman_Filterr_P.X0_Value[0];
    Kalman_Filterr_B.X0[1] = Kalman_Filterr_P.X0_Value[1];
    Kalman_Filterr_B.X0[2] = Kalman_Filterr_P.X0_Value[2];
    Kalman_Filterr_B.X0[3] = Kalman_Filterr_P.X0_Value[3];
  }

  /* Integrator: '<S3>/MemoryX' */
  if (Kalman_Filterr_DW.MemoryX_IWORK != 0) {
    Kalman_Filterr_X.MemoryX_CSTATE[0] = Kalman_Filterr_B.X0[0];
    Kalman_Filterr_X.MemoryX_CSTATE[1] = Kalman_Filterr_B.X0[1];
    Kalman_Filterr_X.MemoryX_CSTATE[2] = Kalman_Filterr_B.X0[2];
    Kalman_Filterr_X.MemoryX_CSTATE[3] = Kalman_Filterr_B.X0[3];
  }

  /* Integrator: '<S3>/MemoryX' */
  Kalman_Filterr_B.MemoryX[0] = Kalman_Filterr_X.MemoryX_CSTATE[0];

  /* Reshape: '<S3>/Reshapexhat' */
  Kalman_Filterr_B.Reshapexhat[0] = Kalman_Filterr_B.MemoryX[0];

  /* Integrator: '<S3>/MemoryX' */
  Kalman_Filterr_B.MemoryX[1] = Kalman_Filterr_X.MemoryX_CSTATE[1];

  /* Reshape: '<S3>/Reshapexhat' */
  Kalman_Filterr_B.Reshapexhat[1] = Kalman_Filterr_B.MemoryX[1];

  /* Integrator: '<S3>/MemoryX' */
  Kalman_Filterr_B.MemoryX[2] = Kalman_Filterr_X.MemoryX_CSTATE[2];

  /* Reshape: '<S3>/Reshapexhat' */
  Kalman_Filterr_B.Reshapexhat[2] = Kalman_Filterr_B.MemoryX[2];

  /* Integrator: '<S3>/MemoryX' */
  Kalman_Filterr_B.MemoryX[3] = Kalman_Filterr_X.MemoryX_CSTATE[3];

  /* Reshape: '<S3>/Reshapexhat' */
  Kalman_Filterr_B.Reshapexhat[3] = Kalman_Filterr_B.MemoryX[3];

  /* RateTransition generated from: '<Root>/Sum3' */
  if (rtmIsMajorTimeStep(Kalman_Filterr_M)) {
    /* RandomNumber: '<S5>/White Noise' */
    Kalman_Filterr_B.WhiteNoise = Kalman_Filterr_DW.NextOutput;

    /* Gain: '<S5>/Output' */
    temp = Kalman_Filterr_P.R * Kalman_Filterr_P.Ts;
    temp = sqrt(temp);
    temp /= 0.044721359549995794;

    /* Gain: '<S5>/Output' */
    Kalman_Filterr_B.Output = temp * Kalman_Filterr_B.WhiteNoise;

    /* Gain: '<Root>/Gain1' */
    Kalman_Filterr_B.Gain1_a[0] = Kalman_Filterr_P.Gain1_Gain_j[0] *
      Kalman_Filterr_B.Output;
    Kalman_Filterr_B.Gain1_a[1] = Kalman_Filterr_P.Gain1_Gain_j[1] *
      Kalman_Filterr_B.Output;

    /* Sum: '<Root>/Sum2' */
    Kalman_Filterr_B.Sum2[0] = Kalman_Filterr_B.Armcountstorad +
      Kalman_Filterr_B.Gain1_a[0];
    Kalman_Filterr_B.Sum2[1] = Kalman_Filterr_B.Bias + Kalman_Filterr_B.Gain1_a
      [1];

    /* Gain: '<S6>/Gain' */
    Kalman_Filterr_B.Gain_i = Kalman_Filterr_P.Gain_Gain_ar *
      Kalman_Filterr_B.Bias;

    /* Abs: '<Root>/|alpha|' */
    Kalman_Filterr_B.alpha = fabs(Kalman_Filterr_B.Bias);

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    Kalman_Filterr_B.Compare = (uint8_T)(Kalman_Filterr_B.alpha <=
      Kalman_Filterr_P.EnableBalanceControl_const);
    if (Kalman_Filterr_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition generated from: '<Root>/Sum3' */
      Kalman_Filterr_B.TmpRTBAtSum3Inport2 =
        Kalman_Filterr_DW.TmpRTBAtSum3Inport2_Buffer0;
    }
  }

  /* End of RateTransition generated from: '<Root>/Sum3' */

  /* Gain: '<Root>/Convert to Vector' */
  Kalman_Filterr_B.ConverttoVector[0] = Kalman_Filterr_P.ConverttoVector_Gain[0]
    * Kalman_Filterr_B.Gain1;

  /* Sum: '<Root>/Sum' */
  Kalman_Filterr_B.Sum[0] = Kalman_Filterr_B.ConverttoVector[0] -
    Kalman_Filterr_B.Reshapexhat[0];

  /* Gain: '<Root>/u = -K*x' */
  tmp = Kalman_Filterr_P.K[0] * Kalman_Filterr_B.Sum[0];

  /* Gain: '<Root>/Convert to Vector' */
  Kalman_Filterr_B.ConverttoVector[1] = Kalman_Filterr_P.ConverttoVector_Gain[1]
    * Kalman_Filterr_B.Gain1;

  /* Sum: '<Root>/Sum' */
  Kalman_Filterr_B.Sum[1] = Kalman_Filterr_B.ConverttoVector[1] -
    Kalman_Filterr_B.Reshapexhat[1];

  /* Gain: '<Root>/u = -K*x' */
  tmp += Kalman_Filterr_P.K[1] * Kalman_Filterr_B.Sum[1];

  /* Gain: '<Root>/Convert to Vector' */
  Kalman_Filterr_B.ConverttoVector[2] = Kalman_Filterr_P.ConverttoVector_Gain[2]
    * Kalman_Filterr_B.Gain1;

  /* Sum: '<Root>/Sum' */
  Kalman_Filterr_B.Sum[2] = Kalman_Filterr_B.ConverttoVector[2] -
    Kalman_Filterr_B.Reshapexhat[2];

  /* Gain: '<Root>/u = -K*x' */
  tmp += Kalman_Filterr_P.K[2] * Kalman_Filterr_B.Sum[2];

  /* Gain: '<Root>/Convert to Vector' */
  Kalman_Filterr_B.ConverttoVector[3] = Kalman_Filterr_P.ConverttoVector_Gain[3]
    * Kalman_Filterr_B.Gain1;

  /* Sum: '<Root>/Sum' */
  Kalman_Filterr_B.Sum[3] = Kalman_Filterr_B.ConverttoVector[3] -
    Kalman_Filterr_B.Reshapexhat[3];

  /* Gain: '<Root>/u = -K*x' */
  tmp += Kalman_Filterr_P.K[3] * Kalman_Filterr_B.Sum[3];

  /* Gain: '<Root>/u = -K*x' */
  Kalman_Filterr_B.uKx = tmp;

  /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' */
  if (Kalman_Filterr_B.Compare == 0) {
    /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' incorporates:
     *  Constant: '<Root>/u = 0V'
     */
    Kalman_Filterr_B.EnableBalanceControlSwitch = Kalman_Filterr_P.u0V_Value;
  } else {
    /* Sum: '<Root>/Sum3' */
    Kalman_Filterr_B.Sum3 = Kalman_Filterr_B.uKx +
      Kalman_Filterr_B.TmpRTBAtSum3Inport2;

    /* MultiPortSwitch: '<Root>/Enable Balance Control Switch' */
    Kalman_Filterr_B.EnableBalanceControlSwitch = Kalman_Filterr_B.Sum3;
  }

  /* End of MultiPortSwitch: '<Root>/Enable Balance Control Switch' */
  if (rtmIsMajorTimeStep(Kalman_Filterr_M)) {
    /* MATLAB Function: '<S58>/SqrtUsedFcn' incorporates:
     *  Constant: '<S58>/isSqrtUsed'
     *  Constant: '<S9>/CovarianceZ'
     */
    /* MATLAB Function 'Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn': '<S59>:1' */
    if (Kalman_Filterr_P.isSqrtUsed_Value) {
      /* '<S59>:1:4' */
      /* '<S59>:1:5' */
      for (i = 0; i < 4; i++) {
        for (i_0 = 0; i_0 < 4; i_0++) {
          Kalman_Filterr_B.P[i + (i_0 << 2)] = 0.0;
          Kalman_Filterr_B.P[i + (i_0 << 2)] +=
            Kalman_Filterr_P.CovarianceZ_Value[i] *
            Kalman_Filterr_P.CovarianceZ_Value[i_0];
          Kalman_Filterr_B.P[i + (i_0 << 2)] +=
            Kalman_Filterr_P.CovarianceZ_Value[i + 4] *
            Kalman_Filterr_P.CovarianceZ_Value[i_0 + 4];
          Kalman_Filterr_B.P[i + (i_0 << 2)] +=
            Kalman_Filterr_P.CovarianceZ_Value[i + 8] *
            Kalman_Filterr_P.CovarianceZ_Value[i_0 + 8];
          Kalman_Filterr_B.P[i + (i_0 << 2)] +=
            Kalman_Filterr_P.CovarianceZ_Value[i + 12] *
            Kalman_Filterr_P.CovarianceZ_Value[i_0 + 12];
        }
      }
    } else {
      /* '<S59>:1:7' */
      memcpy(&Kalman_Filterr_B.P[0], &Kalman_Filterr_P.CovarianceZ_Value[0],
             sizeof(real_T) << 4U);
    }

    /* End of MATLAB Function: '<S58>/SqrtUsedFcn' */
  }

  /* Product: '<S29>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S3>/A'
   */
  tmp_5 = &Kalman_Filterr_P.A_Value[0];
  tmp = Kalman_Filterr_B.MemoryX[0];
  tmp_0 = Kalman_Filterr_B.MemoryX[1];
  tmp_1 = Kalman_Filterr_B.MemoryX[2];
  tmp_2 = Kalman_Filterr_B.MemoryX[3];
  for (i = 0; i <= 2; i += 2) {
    /* Product: '<S29>/A[k]*xhat[k|k-1]' */
    tmp_3 = _mm_loadu_pd(&tmp_5[i]);
    tmp_3 = _mm_mul_pd(tmp_3, _mm_set1_pd(tmp));
    tmp_3 = _mm_add_pd(tmp_3, _mm_set1_pd(0.0));
    tmp_4 = _mm_loadu_pd(&tmp_5[i + 4]);
    tmp_4 = _mm_mul_pd(tmp_4, _mm_set1_pd(tmp_0));
    tmp_3 = _mm_add_pd(tmp_4, tmp_3);

    /* Product: '<S29>/A[k]*xhat[k|k-1]' */
    tmp_4 = _mm_loadu_pd(&tmp_5[i + 8]);
    tmp_4 = _mm_mul_pd(tmp_4, _mm_set1_pd(tmp_1));
    tmp_3 = _mm_add_pd(tmp_4, tmp_3);

    /* Product: '<S29>/A[k]*xhat[k|k-1]' */
    tmp_4 = _mm_loadu_pd(&tmp_5[i + 12]);
    tmp_4 = _mm_mul_pd(tmp_4, _mm_set1_pd(tmp_2));
    tmp_3 = _mm_add_pd(tmp_4, tmp_3);

    /* Product: '<S29>/A[k]*xhat[k|k-1]' */
    _mm_storeu_pd(&Kalman_Filterr_B.Akxhatkk1[i], tmp_3);
  }

  /* Product: '<S29>/B[k]*u[k]' incorporates:
   *  Constant: '<S3>/B'
   */
  temp = Kalman_Filterr_B.uKx;
  tmp = Kalman_Filterr_P.B_Value[0];

  /* Product: '<S29>/B[k]*u[k]' */
  Kalman_Filterr_B.Bkuk[0] = tmp * temp;

  /* Product: '<S29>/B[k]*u[k]' incorporates:
   *  Constant: '<S3>/B'
   */
  tmp = Kalman_Filterr_P.B_Value[1];

  /* Product: '<S29>/B[k]*u[k]' */
  Kalman_Filterr_B.Bkuk[1] = tmp * temp;

  /* Product: '<S29>/B[k]*u[k]' incorporates:
   *  Constant: '<S3>/B'
   */
  tmp = Kalman_Filterr_P.B_Value[2];

  /* Product: '<S29>/B[k]*u[k]' */
  Kalman_Filterr_B.Bkuk[2] = tmp * temp;

  /* Product: '<S29>/B[k]*u[k]' incorporates:
   *  Constant: '<S3>/B'
   */
  tmp = Kalman_Filterr_P.B_Value[3];

  /* Product: '<S29>/B[k]*u[k]' */
  Kalman_Filterr_B.Bkuk[3] = tmp * temp;

  /* Outputs for Enabled SubSystem: '<S29>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (rtmIsMajorTimeStep(Kalman_Filterr_M) && rtsiIsModeUpdateTimeStep
      (&Kalman_Filterr_M->solverInfo)) {
    /* Constant: '<S3>/Enable' */
    if (Kalman_Filterr_P.Enable_Value) {
      if (!Kalman_Filterr_DW.MeasurementUpdate_MODE) {
        Kalman_Filterr_DW.MeasurementUpdate_MODE = true;
      }
    } else if (Kalman_Filterr_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S60>/Product3' incorporates:
       *  Outport: '<S60>/L*(y[k]-yhat[k|k-1])'
       */
      Kalman_Filterr_B.Product3[0] = Kalman_Filterr_P.Lykyhatkk1_Y0;
      Kalman_Filterr_B.Product3[1] = Kalman_Filterr_P.Lykyhatkk1_Y0;
      Kalman_Filterr_B.Product3[2] = Kalman_Filterr_P.Lykyhatkk1_Y0;
      Kalman_Filterr_B.Product3[3] = Kalman_Filterr_P.Lykyhatkk1_Y0;
      Kalman_Filterr_DW.MeasurementUpdate_MODE = false;
    }

    /* End of Constant: '<S3>/Enable' */
  }

  if (Kalman_Filterr_DW.MeasurementUpdate_MODE) {
    /* Product: '<S60>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S3>/C'
     *  Product: '<S60>/Product3'
     */
    tmp_5 = &Kalman_Filterr_P.C_Value[0];
    tmp = Kalman_Filterr_B.MemoryX[0];
    tmp_0 = Kalman_Filterr_B.MemoryX[1];
    tmp_1 = Kalman_Filterr_B.MemoryX[2];
    tmp_2 = Kalman_Filterr_B.MemoryX[3];

    /* Product: '<S60>/D[k]*u[k]' */
    temp = Kalman_Filterr_B.uKx;
    for (i = 0; i <= 0; i += 2) {
      /* Product: '<S60>/C[k]*xhat[k|k-1]' */
      tmp_3 = _mm_loadu_pd(&tmp_5[i]);
      tmp_3 = _mm_mul_pd(tmp_3, _mm_set1_pd(tmp));
      tmp_3 = _mm_add_pd(tmp_3, _mm_set1_pd(0.0));
      tmp_4 = _mm_loadu_pd(&tmp_5[i + 2]);
      tmp_4 = _mm_mul_pd(tmp_4, _mm_set1_pd(tmp_0));
      tmp_3 = _mm_add_pd(tmp_4, tmp_3);

      /* Product: '<S60>/C[k]*xhat[k|k-1]' */
      tmp_4 = _mm_loadu_pd(&tmp_5[i + 4]);
      tmp_4 = _mm_mul_pd(tmp_4, _mm_set1_pd(tmp_1));
      tmp_3 = _mm_add_pd(tmp_4, tmp_3);

      /* Product: '<S60>/C[k]*xhat[k|k-1]' */
      tmp_4 = _mm_loadu_pd(&tmp_5[i + 6]);
      tmp_4 = _mm_mul_pd(tmp_4, _mm_set1_pd(tmp_2));
      tmp_3 = _mm_add_pd(tmp_4, tmp_3);

      /* Product: '<S60>/C[k]*xhat[k|k-1]' */
      _mm_storeu_pd(&Kalman_Filterr_B.Ckxhatkk1[i], tmp_3);

      /* Constant: '<S3>/D' incorporates:
       *  Product: '<S60>/C[k]*xhat[k|k-1]'
       */
      tmp_3 = _mm_loadu_pd(&Kalman_Filterr_P.D_Value[i]);

      /* Product: '<S60>/D[k]*u[k]' */
      tmp_3 = _mm_mul_pd(tmp_3, _mm_set1_pd(temp));

      /* Product: '<S60>/D[k]*u[k]' incorporates:
       *  Product: '<S60>/C[k]*xhat[k|k-1]'
       */
      _mm_storeu_pd(&Kalman_Filterr_B.Dkuk[i], tmp_3);

      /* Sum: '<S60>/Add1' incorporates:
       *  Product: '<S60>/C[k]*xhat[k|k-1]'
       *  Product: '<S60>/D[k]*u[k]'
       */
      tmp_3 = _mm_loadu_pd(&Kalman_Filterr_B.Ckxhatkk1[i]);
      tmp_4 = _mm_loadu_pd(&Kalman_Filterr_B.Dkuk[i]);
      tmp_3 = _mm_add_pd(tmp_3, tmp_4);

      /* Sum: '<S60>/Add1' incorporates:
       *  Product: '<S60>/C[k]*xhat[k|k-1]'
       */
      _mm_storeu_pd(&Kalman_Filterr_B.yhatkk1[i], tmp_3);

      /* Sum: '<S60>/Sum' incorporates:
       *  Product: '<S60>/C[k]*xhat[k|k-1]'
       *  Sum: '<S60>/Add1'
       */
      tmp_3 = _mm_loadu_pd(&Kalman_Filterr_B.Sum2[i]);
      tmp_4 = _mm_loadu_pd(&Kalman_Filterr_B.yhatkk1[i]);
      tmp_3 = _mm_sub_pd(tmp_3, tmp_4);

      /* Sum: '<S60>/Sum' incorporates:
       *  Product: '<S60>/C[k]*xhat[k|k-1]'
       */
      _mm_storeu_pd(&Kalman_Filterr_B.Sum_j[i], tmp_3);
    }

    /* Product: '<S60>/Product3' incorporates:
     *  Constant: '<S9>/KalmanGainL'
     *  Product: '<S60>/C[k]*xhat[k|k-1]'
     *  Sum: '<S60>/Sum'
     */
    tmp_5 = &Kalman_Filterr_P.KalmanGainL_Value[0];
    tmp = Kalman_Filterr_B.Sum_j[0];
    tmp_0 = Kalman_Filterr_B.Sum_j[1];
    for (i = 0; i <= 2; i += 2) {
      /* Product: '<S60>/Product3' */
      _mm_storeu_pd(&Kalman_Filterr_B.Product3[i], _mm_set1_pd(0.0));

      /* Product: '<S60>/Product3' */
      tmp_3 = _mm_loadu_pd(&tmp_5[i]);
      tmp_3 = _mm_mul_pd(tmp_3, _mm_set1_pd(tmp));
      tmp_4 = _mm_loadu_pd(&Kalman_Filterr_B.Product3[i]);
      tmp_3 = _mm_add_pd(tmp_3, tmp_4);

      /* Product: '<S60>/Product3' */
      _mm_storeu_pd(&Kalman_Filterr_B.Product3[i], tmp_3);

      /* Product: '<S60>/Product3' */
      tmp_3 = _mm_loadu_pd(&tmp_5[i + 4]);
      tmp_3 = _mm_mul_pd(tmp_3, _mm_set1_pd(tmp_0));
      tmp_4 = _mm_loadu_pd(&Kalman_Filterr_B.Product3[i]);
      tmp_3 = _mm_add_pd(tmp_3, tmp_4);

      /* Product: '<S60>/Product3' */
      _mm_storeu_pd(&Kalman_Filterr_B.Product3[i], tmp_3);
    }

    if (rtsiIsModeUpdateTimeStep(&Kalman_Filterr_M->solverInfo)) {
      srUpdateBC(Kalman_Filterr_DW.MeasurementUpdate_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S29>/MeasurementUpdate' */

  /* Sum: '<S29>/Add' incorporates:
   *  Product: '<S29>/B[k]*u[k]'
   *  Product: '<S60>/Product3'
   */
  Kalman_Filterr_B.Add[0] = (Kalman_Filterr_B.Bkuk[0] +
    Kalman_Filterr_B.Akxhatkk1[0]) + Kalman_Filterr_B.Product3[0];
  Kalman_Filterr_B.Add[1] = (Kalman_Filterr_B.Bkuk[1] +
    Kalman_Filterr_B.Akxhatkk1[1]) + Kalman_Filterr_B.Product3[1];
  Kalman_Filterr_B.Add[2] = (Kalman_Filterr_B.Bkuk[2] +
    Kalman_Filterr_B.Akxhatkk1[2]) + Kalman_Filterr_B.Product3[2];
  Kalman_Filterr_B.Add[3] = (Kalman_Filterr_B.Bkuk[3] +
    Kalman_Filterr_B.Akxhatkk1[3]) + Kalman_Filterr_B.Product3[3];

  /* TransferFcn: '<S63>/alpha_dot' */
  Kalman_Filterr_B.alpha_dot = Kalman_Filterr_P.alpha_dot_C *
    Kalman_Filterr_X.alpha_dot_CSTATE;
  Kalman_Filterr_B.alpha_dot += Kalman_Filterr_P.alpha_dot_D *
    Kalman_Filterr_B.Bias;

  /* TransferFcn: '<S63>/theta_dot' */
  Kalman_Filterr_B.theta_dot = Kalman_Filterr_P.theta_dot_C *
    Kalman_Filterr_X.theta_dot_CSTATE;
  Kalman_Filterr_B.theta_dot += Kalman_Filterr_P.theta_dot_D *
    Kalman_Filterr_B.Armcountstorad;

  /* Gain: '<S8>/For +ve CCW' */
  Kalman_Filterr_B.ForveCCW = Kalman_Filterr_P.ForveCCW_Gain *
    Kalman_Filterr_B.EnableBalanceControlSwitch;
  if (rtmIsMajorTimeStep(Kalman_Filterr_M)) {
    /* S-Function (hil_write_analog_block): '<S8>/HIL Write Analog' */

    /* S-Function Block: Kalman_Filterr/Rotary Pendulum Interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Kalman_Filterr_DW.HILInitialize_Card,
        &Kalman_Filterr_P.HILWriteAnalog_channels, 1, &Kalman_Filterr_B.ForveCCW);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
      }
    }
  }
}

/* Model update function for TID0 */
void Kalman_Filterr_update0(void)      /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S3>/MemoryX' */
  Kalman_Filterr_DW.MemoryX_IWORK = 0;
  if (rtmIsMajorTimeStep(Kalman_Filterr_M)) {
    /* Update for RandomNumber: '<S5>/White Noise' */
    Kalman_Filterr_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Kalman_Filterr_DW.RandSeed) * Kalman_Filterr_P.WhiteNoise_StdDev +
      Kalman_Filterr_P.WhiteNoise_Mean;
  }

  if (rtmIsMajorTimeStep(Kalman_Filterr_M)) {
    rt_ertODEUpdateContinuousStates(&Kalman_Filterr_M->solverInfo);
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
  if (!(++Kalman_Filterr_M->Timing.clockTick0)) {
    ++Kalman_Filterr_M->Timing.clockTickH0;
  }

  Kalman_Filterr_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Kalman_Filterr_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Kalman_Filterr_M->Timing.clockTick1)) {
    ++Kalman_Filterr_M->Timing.clockTickH1;
  }

  Kalman_Filterr_M->Timing.t[1] = Kalman_Filterr_M->Timing.clockTick1 *
    Kalman_Filterr_M->Timing.stepSize1 + Kalman_Filterr_M->Timing.clockTickH1 *
    Kalman_Filterr_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Kalman_Filterr_derivatives(void)
{
  XDot_Kalman_Filterr_T *_rtXdot;
  _rtXdot = ((XDot_Kalman_Filterr_T *) Kalman_Filterr_M->derivs);

  /* Derivatives for Integrator: '<S3>/MemoryX' */
  _rtXdot->MemoryX_CSTATE[0] = Kalman_Filterr_B.Add[0];
  _rtXdot->MemoryX_CSTATE[1] = Kalman_Filterr_B.Add[1];
  _rtXdot->MemoryX_CSTATE[2] = Kalman_Filterr_B.Add[2];
  _rtXdot->MemoryX_CSTATE[3] = Kalman_Filterr_B.Add[3];

  /* Derivatives for TransferFcn: '<S63>/alpha_dot' */
  _rtXdot->alpha_dot_CSTATE = Kalman_Filterr_P.alpha_dot_A *
    Kalman_Filterr_X.alpha_dot_CSTATE;
  _rtXdot->alpha_dot_CSTATE += Kalman_Filterr_B.Bias;

  /* Derivatives for TransferFcn: '<S63>/theta_dot' */
  _rtXdot->theta_dot_CSTATE = Kalman_Filterr_P.theta_dot_A *
    Kalman_Filterr_X.theta_dot_CSTATE;
  _rtXdot->theta_dot_CSTATE += Kalman_Filterr_B.Armcountstorad;
}

/* Model output function for TID2 */
void Kalman_Filterr_output2(void)      /* Sample time: [0.02s, 0.0s] */
{
  real_T x;

  /* RandomNumber: '<S4>/White Noise' */
  Kalman_Filterr_B.WhiteNoise_l = Kalman_Filterr_DW.NextOutput_m;

  /* Gain: '<S4>/Output' */
  x = Kalman_Filterr_P.Q * Kalman_Filterr_P.Ts;
  x = sqrt(x);
  x /= 0.1414213562373095;

  /* Gain: '<S4>/Output' */
  Kalman_Filterr_B.Output_l = x * Kalman_Filterr_B.WhiteNoise_l;

  /* Gain: '<Root>/Gain3' */
  Kalman_Filterr_B.Gain3 = Kalman_Filterr_P.Kw * Kalman_Filterr_B.Output_l;

  /* RateTransition generated from: '<Root>/Sum3' */
  Kalman_Filterr_DW.TmpRTBAtSum3Inport2_Buffer0 = Kalman_Filterr_B.Gain3;
}

/* Model update function for TID2 */
void Kalman_Filterr_update2(void)      /* Sample time: [0.02s, 0.0s] */
{
  /* Update for RandomNumber: '<S4>/White Noise' */
  Kalman_Filterr_DW.NextOutput_m = rt_nrand_Upu32_Yd_f_pw_snf
    (&Kalman_Filterr_DW.RandSeed_a) * Kalman_Filterr_P.WhiteNoise_StdDev_g +
    Kalman_Filterr_P.WhiteNoise_Mean_b;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Kalman_Filterr_M->Timing.clockTick2)) {
    ++Kalman_Filterr_M->Timing.clockTickH2;
  }

  Kalman_Filterr_M->Timing.t[2] = Kalman_Filterr_M->Timing.clockTick2 *
    Kalman_Filterr_M->Timing.stepSize2 + Kalman_Filterr_M->Timing.clockTickH2 *
    Kalman_Filterr_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Kalman_Filterr_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Kalman_Filterr_output0();
    break;

   case 2 :
    Kalman_Filterr_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Kalman_Filterr_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Kalman_Filterr_update0();
    break;

   case 2 :
    Kalman_Filterr_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Kalman_Filterr_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Kalman_Filterr/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0",
                      &Kalman_Filterr_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Kalman_Filterr_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
      return;
    }

    if ((Kalman_Filterr_P.HILInitialize_AIPStart && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Kalman_Filterr_DW.HILInitialize_Card,
        &Kalman_Filterr_P.HILInitialize_AIChannels, 1U,
        &Kalman_Filterr_P.HILInitialize_AILow,
        &Kalman_Filterr_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Filterr_P.HILInitialize_AOPStart && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Kalman_Filterr_DW.HILInitialize_Card,
        &Kalman_Filterr_P.HILInitialize_AOChannels, 1U,
        &Kalman_Filterr_P.HILInitialize_AOLow,
        &Kalman_Filterr_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Filterr_P.HILInitialize_AOStart && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Kalman_Filterr_DW.HILInitialize_Card,
        &Kalman_Filterr_P.HILInitialize_AOChannels, 1U,
        &Kalman_Filterr_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }

    if (Kalman_Filterr_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (Kalman_Filterr_DW.HILInitialize_Card,
         &Kalman_Filterr_P.HILInitialize_AOChannels, 1U,
         &Kalman_Filterr_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(Kalman_Filterr_DW.HILInitialize_Card,
      NULL, 0U, &Kalman_Filterr_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
      return;
    }

    if ((Kalman_Filterr_P.HILInitialize_DOStart && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(Kalman_Filterr_DW.HILInitialize_Card,
        &Kalman_Filterr_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &Kalman_Filterr_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }

    if (Kalman_Filterr_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (Kalman_Filterr_DW.HILInitialize_Card,
         &Kalman_Filterr_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &Kalman_Filterr_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Filterr_P.HILInitialize_EIPStart && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_EIPEnter && is_switching)) {
      Kalman_Filterr_DW.HILInitialize_QuadratureModes[0] =
        Kalman_Filterr_P.HILInitialize_EIQuadrature;
      Kalman_Filterr_DW.HILInitialize_QuadratureModes[1] =
        Kalman_Filterr_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (Kalman_Filterr_DW.HILInitialize_Card,
         Kalman_Filterr_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &Kalman_Filterr_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Filterr_P.HILInitialize_EIStart && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_EIEnter && is_switching)) {
      Kalman_Filterr_DW.HILInitialize_InitialEICounts[0] =
        Kalman_Filterr_P.HILInitialize_EIInitial;
      Kalman_Filterr_DW.HILInitialize_InitialEICounts[1] =
        Kalman_Filterr_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(Kalman_Filterr_DW.HILInitialize_Card,
        Kalman_Filterr_P.HILInitialize_EIChannels, 2U,
        &Kalman_Filterr_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }

    if ((Kalman_Filterr_P.HILInitialize_OOStart && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(Kalman_Filterr_DW.HILInitialize_Card,
        Kalman_Filterr_P.HILInitialize_OOChannels, 3U,
        Kalman_Filterr_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }

    if (Kalman_Filterr_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (Kalman_Filterr_DW.HILInitialize_Card,
         Kalman_Filterr_P.HILInitialize_OOChannels, 3U,
         Kalman_Filterr_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S8>/HIL Read Encoder Timebase' */

  /* S-Function Block: Kalman_Filterr/Rotary Pendulum Interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Kalman_Filterr_DW.HILInitialize_Card,
      Kalman_Filterr_P.HILReadEncoderTimebase_SamplesI,
      Kalman_Filterr_P.HILReadEncoderTimebase_Channels, 2,
      &Kalman_Filterr_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (Kalman_Filterr_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (Kalman_Filterr_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
    }
  }

  /* Start for Constant: '<S3>/X0' */
  Kalman_Filterr_B.X0[0] = Kalman_Filterr_P.X0_Value[0];
  Kalman_Filterr_B.X0[1] = Kalman_Filterr_P.X0_Value[1];
  Kalman_Filterr_B.X0[2] = Kalman_Filterr_P.X0_Value[2];
  Kalman_Filterr_B.X0[3] = Kalman_Filterr_P.X0_Value[3];

  /* Start for RateTransition generated from: '<Root>/Sum3' */
  Kalman_Filterr_B.TmpRTBAtSum3Inport2 =
    Kalman_Filterr_P.TmpRTBAtSum3Inport2_InitialCond;

  /* Start for Enabled SubSystem: '<S29>/MeasurementUpdate' */
  Kalman_Filterr_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S29>/MeasurementUpdate' */
  {
    real_T tmp;
    int32_T r;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for Integrator: '<S3>/MemoryX' */
    if (rtmIsFirstInitCond(Kalman_Filterr_M)) {
      Kalman_Filterr_X.MemoryX_CSTATE[0] = 0.0;
      Kalman_Filterr_X.MemoryX_CSTATE[1] = 0.0;
      Kalman_Filterr_X.MemoryX_CSTATE[2] = 0.0;
      Kalman_Filterr_X.MemoryX_CSTATE[3] = 0.0;
    }

    Kalman_Filterr_DW.MemoryX_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S3>/MemoryX' */

    /* InitializeConditions for RandomNumber: '<S5>/White Noise' */
    tmp = floor(Kalman_Filterr_P.MeasurmentNoise_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    Kalman_Filterr_DW.RandSeed = tseed;
    Kalman_Filterr_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Kalman_Filterr_DW.RandSeed) * Kalman_Filterr_P.WhiteNoise_StdDev +
      Kalman_Filterr_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S5>/White Noise' */

    /* InitializeConditions for RateTransition generated from: '<Root>/Sum3' */
    Kalman_Filterr_DW.TmpRTBAtSum3Inport2_Buffer0 =
      Kalman_Filterr_P.TmpRTBAtSum3Inport2_InitialCond;

    /* InitializeConditions for TransferFcn: '<S63>/alpha_dot' */
    Kalman_Filterr_X.alpha_dot_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S63>/theta_dot' */
    Kalman_Filterr_X.theta_dot_CSTATE = 0.0;

    /* InitializeConditions for RandomNumber: '<S4>/White Noise' */
    tmp = floor(Kalman_Filterr_P.Loaddisturbances_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    Kalman_Filterr_DW.RandSeed_a = tseed;
    Kalman_Filterr_DW.NextOutput_m = rt_nrand_Upu32_Yd_f_pw_snf
      (&Kalman_Filterr_DW.RandSeed_a) * Kalman_Filterr_P.WhiteNoise_StdDev_g +
      Kalman_Filterr_P.WhiteNoise_Mean_b;

    /* End of InitializeConditions for RandomNumber: '<S4>/White Noise' */

    /* SystemInitialize for Enabled SubSystem: '<S29>/MeasurementUpdate' */
    /* SystemInitialize for Product: '<S60>/Product3' incorporates:
     *  Outport: '<S60>/L*(y[k]-yhat[k|k-1])'
     */
    Kalman_Filterr_B.Product3[0] = Kalman_Filterr_P.Lykyhatkk1_Y0;
    Kalman_Filterr_B.Product3[1] = Kalman_Filterr_P.Lykyhatkk1_Y0;
    Kalman_Filterr_B.Product3[2] = Kalman_Filterr_P.Lykyhatkk1_Y0;
    Kalman_Filterr_B.Product3[3] = Kalman_Filterr_P.Lykyhatkk1_Y0;

    /* End of SystemInitialize for SubSystem: '<S29>/MeasurementUpdate' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(Kalman_Filterr_M)) {
      rtmSetFirstInitCond(Kalman_Filterr_M, 0);
    }
  }
}

/* Model terminate function */
void Kalman_Filterr_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Kalman_Filterr/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(Kalman_Filterr_DW.HILInitialize_Card);
    hil_monitor_stop_all(Kalman_Filterr_DW.HILInitialize_Card);
    is_switching = false;
    if ((Kalman_Filterr_P.HILInitialize_AOTerminate && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((Kalman_Filterr_P.HILInitialize_DOTerminate && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((Kalman_Filterr_P.HILInitialize_OOTerminate && !is_switching) ||
        (Kalman_Filterr_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(Kalman_Filterr_DW.HILInitialize_Card
                         , &Kalman_Filterr_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &Kalman_Filterr_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , Kalman_Filterr_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &Kalman_Filterr_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &Kalman_Filterr_P.HILInitialize_DOFinal
                         , Kalman_Filterr_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Kalman_Filterr_DW.HILInitialize_Card,
            &Kalman_Filterr_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &Kalman_Filterr_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(Kalman_Filterr_DW.HILInitialize_Card,
            &Kalman_Filterr_P.HILInitialize_DOChannels,
            num_final_digital_outputs, (t_boolean *)
            &Kalman_Filterr_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(Kalman_Filterr_DW.HILInitialize_Card,
            Kalman_Filterr_P.HILInitialize_OOChannels, num_final_other_outputs,
            Kalman_Filterr_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Kalman_Filterr_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Kalman_Filterr_DW.HILInitialize_Card);
    hil_monitor_delete_all(Kalman_Filterr_DW.HILInitialize_Card);
    hil_close(Kalman_Filterr_DW.HILInitialize_Card);
    Kalman_Filterr_DW.HILInitialize_Card = NULL;
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
  Kalman_Filterr_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Kalman_Filterr_update(tid);
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
  Kalman_Filterr_initialize();
}

void MdlTerminate(void)
{
  Kalman_Filterr_terminate();
}

/* Registration function */
RT_MODEL_Kalman_Filterr_T *Kalman_Filterr(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Kalman_Filterr_M, 0,
                sizeof(RT_MODEL_Kalman_Filterr_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Kalman_Filterr_M->solverInfo,
                          &Kalman_Filterr_M->Timing.simTimeStep);
    rtsiSetTPtr(&Kalman_Filterr_M->solverInfo, &rtmGetTPtr(Kalman_Filterr_M));
    rtsiSetStepSizePtr(&Kalman_Filterr_M->solverInfo,
                       &Kalman_Filterr_M->Timing.stepSize0);
    rtsiSetdXPtr(&Kalman_Filterr_M->solverInfo, &Kalman_Filterr_M->derivs);
    rtsiSetContStatesPtr(&Kalman_Filterr_M->solverInfo, (real_T **)
                         &Kalman_Filterr_M->contStates);
    rtsiSetNumContStatesPtr(&Kalman_Filterr_M->solverInfo,
      &Kalman_Filterr_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Kalman_Filterr_M->solverInfo,
      &Kalman_Filterr_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Kalman_Filterr_M->solverInfo,
      &Kalman_Filterr_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Kalman_Filterr_M->solverInfo,
      &Kalman_Filterr_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Kalman_Filterr_M->solverInfo, (&rtmGetErrorStatus
      (Kalman_Filterr_M)));
    rtsiSetRTModelPtr(&Kalman_Filterr_M->solverInfo, Kalman_Filterr_M);
  }

  rtsiSetSimTimeStep(&Kalman_Filterr_M->solverInfo, MAJOR_TIME_STEP);
  Kalman_Filterr_M->intgData.f[0] = Kalman_Filterr_M->odeF[0];
  Kalman_Filterr_M->contStates = ((real_T *) &Kalman_Filterr_X);
  rtsiSetSolverData(&Kalman_Filterr_M->solverInfo, (void *)
                    &Kalman_Filterr_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Kalman_Filterr_M->solverInfo, false);
  rtsiSetSolverName(&Kalman_Filterr_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Kalman_Filterr_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Kalman_Filterr_M points to
       static memory which is guaranteed to be non-NULL" */
    Kalman_Filterr_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Kalman_Filterr_M->Timing.sampleTimes =
      (&Kalman_Filterr_M->Timing.sampleTimesArray[0]);
    Kalman_Filterr_M->Timing.offsetTimes =
      (&Kalman_Filterr_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Kalman_Filterr_M->Timing.sampleTimes[0] = (0.0);
    Kalman_Filterr_M->Timing.sampleTimes[1] = (0.002);
    Kalman_Filterr_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    Kalman_Filterr_M->Timing.offsetTimes[0] = (0.0);
    Kalman_Filterr_M->Timing.offsetTimes[1] = (0.0);
    Kalman_Filterr_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Kalman_Filterr_M, &Kalman_Filterr_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Kalman_Filterr_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Kalman_Filterr_M->Timing.perTaskSampleHitsArray;
    Kalman_Filterr_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Kalman_Filterr_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Kalman_Filterr_M, -1);
  Kalman_Filterr_M->Timing.stepSize0 = 0.002;
  Kalman_Filterr_M->Timing.stepSize1 = 0.002;
  Kalman_Filterr_M->Timing.stepSize2 = 0.02;
  rtmSetFirstInitCond(Kalman_Filterr_M, 1);

  /* External mode info */
  Kalman_Filterr_M->Sizes.checksums[0] = (236425795U);
  Kalman_Filterr_M->Sizes.checksums[1] = (1288574271U);
  Kalman_Filterr_M->Sizes.checksums[2] = (3103587852U);
  Kalman_Filterr_M->Sizes.checksums[3] = (15773901U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Kalman_Filterr_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &Kalman_Filterr_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Kalman_Filterr_M->extModeInfo,
      &Kalman_Filterr_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Kalman_Filterr_M->extModeInfo,
                        Kalman_Filterr_M->Sizes.checksums);
    rteiSetTPtr(Kalman_Filterr_M->extModeInfo, rtmGetTPtr(Kalman_Filterr_M));
  }

  Kalman_Filterr_M->solverInfoPtr = (&Kalman_Filterr_M->solverInfo);
  Kalman_Filterr_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Kalman_Filterr_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Kalman_Filterr_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Kalman_Filterr_M->blockIO = ((void *) &Kalman_Filterr_B);
  (void) memset(((void *) &Kalman_Filterr_B), 0,
                sizeof(B_Kalman_Filterr_T));

  {
    int32_T i;
    for (i = 0; i < 16; i++) {
      Kalman_Filterr_B.P[i] = 0.0;
    }

    Kalman_Filterr_B.HILReadEncoderTimebase_o1 = 0.0;
    Kalman_Filterr_B.HILReadEncoderTimebase_o2 = 0.0;
    Kalman_Filterr_B.SignalGenerator = 0.0;
    Kalman_Filterr_B.Gain = 0.0;
    Kalman_Filterr_B.Gain1 = 0.0;
    Kalman_Filterr_B.Armcountstorad = 0.0;
    Kalman_Filterr_B.Gain_b[0] = 0.0;
    Kalman_Filterr_B.Gain_b[1] = 0.0;
    Kalman_Filterr_B.Pendulumcountstorad = 0.0;
    Kalman_Filterr_B.MathFunction = 0.0;
    Kalman_Filterr_B.Bias = 0.0;
    Kalman_Filterr_B.X0[0] = 0.0;
    Kalman_Filterr_B.X0[1] = 0.0;
    Kalman_Filterr_B.X0[2] = 0.0;
    Kalman_Filterr_B.X0[3] = 0.0;
    Kalman_Filterr_B.MemoryX[0] = 0.0;
    Kalman_Filterr_B.MemoryX[1] = 0.0;
    Kalman_Filterr_B.MemoryX[2] = 0.0;
    Kalman_Filterr_B.MemoryX[3] = 0.0;
    Kalman_Filterr_B.Reshapexhat[0] = 0.0;
    Kalman_Filterr_B.Reshapexhat[1] = 0.0;
    Kalman_Filterr_B.Reshapexhat[2] = 0.0;
    Kalman_Filterr_B.Reshapexhat[3] = 0.0;
    Kalman_Filterr_B.WhiteNoise = 0.0;
    Kalman_Filterr_B.Output = 0.0;
    Kalman_Filterr_B.Gain1_a[0] = 0.0;
    Kalman_Filterr_B.Gain1_a[1] = 0.0;
    Kalman_Filterr_B.Sum2[0] = 0.0;
    Kalman_Filterr_B.Sum2[1] = 0.0;
    Kalman_Filterr_B.Gain_i = 0.0;
    Kalman_Filterr_B.alpha = 0.0;
    Kalman_Filterr_B.ConverttoVector[0] = 0.0;
    Kalman_Filterr_B.ConverttoVector[1] = 0.0;
    Kalman_Filterr_B.ConverttoVector[2] = 0.0;
    Kalman_Filterr_B.ConverttoVector[3] = 0.0;
    Kalman_Filterr_B.Sum[0] = 0.0;
    Kalman_Filterr_B.Sum[1] = 0.0;
    Kalman_Filterr_B.Sum[2] = 0.0;
    Kalman_Filterr_B.Sum[3] = 0.0;
    Kalman_Filterr_B.uKx = 0.0;
    Kalman_Filterr_B.TmpRTBAtSum3Inport2 = 0.0;
    Kalman_Filterr_B.EnableBalanceControlSwitch = 0.0;
    Kalman_Filterr_B.Akxhatkk1[0] = 0.0;
    Kalman_Filterr_B.Akxhatkk1[1] = 0.0;
    Kalman_Filterr_B.Akxhatkk1[2] = 0.0;
    Kalman_Filterr_B.Akxhatkk1[3] = 0.0;
    Kalman_Filterr_B.Bkuk[0] = 0.0;
    Kalman_Filterr_B.Bkuk[1] = 0.0;
    Kalman_Filterr_B.Bkuk[2] = 0.0;
    Kalman_Filterr_B.Bkuk[3] = 0.0;
    Kalman_Filterr_B.Add[0] = 0.0;
    Kalman_Filterr_B.Add[1] = 0.0;
    Kalman_Filterr_B.Add[2] = 0.0;
    Kalman_Filterr_B.Add[3] = 0.0;
    Kalman_Filterr_B.alpha_dot = 0.0;
    Kalman_Filterr_B.theta_dot = 0.0;
    Kalman_Filterr_B.ForveCCW = 0.0;
    Kalman_Filterr_B.WhiteNoise_l = 0.0;
    Kalman_Filterr_B.Output_l = 0.0;
    Kalman_Filterr_B.Gain3 = 0.0;
    Kalman_Filterr_B.Sum3 = 0.0;
    Kalman_Filterr_B.Ckxhatkk1[0] = 0.0;
    Kalman_Filterr_B.Ckxhatkk1[1] = 0.0;
    Kalman_Filterr_B.Dkuk[0] = 0.0;
    Kalman_Filterr_B.Dkuk[1] = 0.0;
    Kalman_Filterr_B.yhatkk1[0] = 0.0;
    Kalman_Filterr_B.yhatkk1[1] = 0.0;
    Kalman_Filterr_B.Sum_j[0] = 0.0;
    Kalman_Filterr_B.Sum_j[1] = 0.0;
    Kalman_Filterr_B.Product3[0] = 0.0;
    Kalman_Filterr_B.Product3[1] = 0.0;
    Kalman_Filterr_B.Product3[2] = 0.0;
    Kalman_Filterr_B.Product3[3] = 0.0;
  }

  /* parameters */
  Kalman_Filterr_M->defaultParam = ((real_T *)&Kalman_Filterr_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Kalman_Filterr_X;
    Kalman_Filterr_M->contStates = (x);
    (void) memset((void *)&Kalman_Filterr_X, 0,
                  sizeof(X_Kalman_Filterr_T));
  }

  /* states (dwork) */
  Kalman_Filterr_M->dwork = ((void *) &Kalman_Filterr_DW);
  (void) memset((void *)&Kalman_Filterr_DW, 0,
                sizeof(DW_Kalman_Filterr_T));
  Kalman_Filterr_DW.HILInitialize_FilterFrequency[0] = 0.0;
  Kalman_Filterr_DW.HILInitialize_FilterFrequency[1] = 0.0;
  Kalman_Filterr_DW.NextOutput = 0.0;
  Kalman_Filterr_DW.TmpRTBAtSum3Inport2_Buffer0 = 0.0;
  Kalman_Filterr_DW.NextOutput_m = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Kalman_Filterr_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Kalman_Filterr_M->Sizes.numContStates = (6);/* Number of continuous states */
  Kalman_Filterr_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Kalman_Filterr_M->Sizes.numY = (0);  /* Number of model outputs */
  Kalman_Filterr_M->Sizes.numU = (0);  /* Number of model inputs */
  Kalman_Filterr_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Kalman_Filterr_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Kalman_Filterr_M->Sizes.numBlocks = (64);/* Number of blocks */
  Kalman_Filterr_M->Sizes.numBlockIO = (41);/* Number of block outputs */
  Kalman_Filterr_M->Sizes.numBlockPrms = (176);/* Sum of parameter "widths" */
  return Kalman_Filterr_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
