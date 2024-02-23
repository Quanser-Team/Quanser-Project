/*
 * MPC_linear.c
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

#include "MPC_linear.h"
#include "rtwtypes.h"
#include <math.h>
#include <emmintrin.h>
#include "MPC_linear_private.h"
#include "rt_nonfinite.h"
#include <string.h>
#include "MPC_linear_dt.h"

/* Named constants for MATLAB Function: '<S26>/optimizer' */
#define MPC_linear_degrees             (3)

/* Block signals (default storage) */
B_MPC_linear_T MPC_linear_B;

/* Continuous states */
X_MPC_linear_T MPC_linear_X;

/* Block states (default storage) */
DW_MPC_linear_T MPC_linear_DW;

/* Real-time model */
static RT_MODEL_MPC_linear_T MPC_linear_M_;
RT_MODEL_MPC_linear_T *const MPC_linear_M = &MPC_linear_M_;

/* Forward declaration for local functions */
static real_T MPC_linear_norm(const real_T x[3]);
static real_T MPC_linear_maximum(const real_T x[3]);
static real_T MPC_linear_xnrm2(int32_T n, const real_T x[9], int32_T ix0);
static void MPC_linear_xgemv(int32_T b_m, int32_T n, const real_T b_A[9],
  int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3]);
static void MPC_linear_xgerc(int32_T b_m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[3], real_T b_A[9], int32_T ia0);
static real_T MPC_linear_KWIKfactor(const real_T b_Ac[72], const int32_T iC[24],
  int32_T nA, const real_T b_Linv[9], real_T RLinv[9], real_T D[9], real_T b_H[9],
  int32_T n);
static void MPC_linear_DropConstraint(int32_T kDrop, boolean_T iA[24], int32_T
  *nA, int32_T iC[24]);
static void MPC_linear_qpkwik(const real_T b_Linv[9], const real_T b_Hinv[9],
  const real_T f[3], const real_T b_Ac[72], const real_T b[24], boolean_T iA[24],
  int32_T maxiter, real_T FeasTol, real_T x[3], real_T lambda[24], int32_T
  *status);
static void rate_monotonic_scheduler(void);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(MPC_linear_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(MPC_linear_M, 2);
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
  if (MPC_linear_M->Timing.TaskCounters.TID[1] == 0) {
    MPC_linear_M->Timing.RateInteraction.TID1_2 =
      (MPC_linear_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    MPC_linear_M->Timing.perTaskSampleHits[5] =
      MPC_linear_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (MPC_linear_M->Timing.TaskCounters.TID[2])++;
  if ((MPC_linear_M->Timing.TaskCounters.TID[2]) > 199) {/* Sample time: [0.1s, 0.0s] */
    MPC_linear_M->Timing.TaskCounters.TID[2] = 0;
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
  MPC_linear_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S26>/optimizer' */
static real_T MPC_linear_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S26>/optimizer' */
static real_T MPC_linear_maximum(const real_T x[3])
{
  real_T ex;
  real_T tmp;
  int32_T idx;
  int32_T k;
  boolean_T exitg1;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 4; k++) {
      tmp = x[k - 1];
      if (ex < tmp) {
        ex = tmp;
      }
    }
  }

  return ex;
}

/* Function for MATLAB Function: '<S26>/optimizer' */
static real_T MPC_linear_xnrm2(int32_T n, const real_T x[9], int32_T ix0)
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
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
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

/* Function for MATLAB Function: '<S26>/optimizer' */
static void MPC_linear_xgemv(int32_T b_m, int32_T n, const real_T b_A[9],
  int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3])
{
  real_T c;
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T iyend;
  if ((b_m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0;
    }

    b = (n - 1) * 3 + ia0;
    for (b_iy = ia0; b_iy <= b; b_iy += 3) {
      c = 0.0;
      d = (b_iy + b_m) - 1;
      for (iyend = b_iy; iyend <= d; iyend++) {
        c += x[((ix0 + iyend) - b_iy) - 1] * b_A[iyend - 1];
      }

      iyend = div_nde_s32_floor(b_iy - ia0, 3);
      y[iyend] += c;
    }
  }
}

/* Function for MATLAB Function: '<S26>/optimizer' */
static void MPC_linear_xgerc(int32_T b_m, int32_T n, real_T alpha1, int32_T ix0,
  const real_T y[3], real_T b_A[9], int32_T ia0)
{
  real_T temp;
  int32_T b;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  if (!(alpha1 == 0.0)) {
    jA = ia0;
    for (j = 0; j < n; j++) {
      temp = y[j];
      if (temp != 0.0) {
        temp *= alpha1;
        b = b_m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          b_A[ijA - 1] += b_A[((ix0 + ijA) - jA) - 1] * temp;
        }
      }

      jA += 3;
    }
  }
}

/* Function for MATLAB Function: '<S26>/optimizer' */
static real_T MPC_linear_KWIKfactor(const real_T b_Ac[72], const int32_T iC[24],
  int32_T nA, const real_T b_Linv[9], real_T RLinv[9], real_T D[9], real_T b_H[9],
  int32_T n)
{
  __m128d tmp;
  real_T Q[9];
  real_T R[9];
  real_T TL[9];
  real_T b_A[9];
  real_T tau[3];
  real_T work[3];
  real_T Status;
  real_T atmp;
  real_T beta1;
  int32_T b_coltop;
  int32_T b_lastv;
  int32_T coltop;
  int32_T coltop_tmp;
  int32_T exitg1;
  int32_T ii;
  int32_T k_i;
  int32_T knt;
  int32_T vectorUB;
  boolean_T exitg2;
  Status = 1.0;
  for (b_coltop = 0; b_coltop < 9; b_coltop++) {
    RLinv[b_coltop] = 0.0;
  }

  for (k_i = 0; k_i < nA; k_i++) {
    ii = iC[k_i];
    for (b_coltop = 0; b_coltop < 3; b_coltop++) {
      knt = 3 * k_i + b_coltop;
      RLinv[knt] = 0.0;
      RLinv[knt] += b_Ac[ii - 1] * b_Linv[b_coltop];
      RLinv[knt] += b_Linv[b_coltop + 3] * b_Ac[ii + 23];
      RLinv[knt] += b_Linv[b_coltop + 6] * b_Ac[ii + 47];
    }
  }

  memcpy(&b_A[0], &RLinv[0], 9U * sizeof(real_T));
  tau[0] = 0.0;
  work[0] = 0.0;
  tau[1] = 0.0;
  work[1] = 0.0;
  tau[2] = 0.0;
  work[2] = 0.0;
  for (k_i = 0; k_i < 3; k_i++) {
    ii = k_i * 3 + k_i;
    if (k_i + 1 < 3) {
      atmp = b_A[ii];
      b_lastv = ii + 2;
      tau[k_i] = 0.0;
      beta1 = MPC_linear_xnrm2(2 - k_i, b_A, ii + 2);
      if (beta1 != 0.0) {
        beta1 = rt_hypotd_snf(b_A[ii], beta1);
        if (b_A[ii] >= 0.0) {
          beta1 = -beta1;
        }

        if (fabs(beta1) < 1.0020841800044864E-292) {
          knt = 0;
          do {
            knt++;
            coltop_tmp = (ii - k_i) + 3;
            coltop = (((((coltop_tmp - ii) - 1) / 2) << 1) + ii) + 2;
            vectorUB = coltop - 2;
            for (b_coltop = b_lastv; b_coltop <= vectorUB; b_coltop += 2) {
              tmp = _mm_loadu_pd(&b_A[b_coltop - 1]);
              _mm_storeu_pd(&b_A[b_coltop - 1], _mm_mul_pd(tmp, _mm_set1_pd
                (9.9792015476736E+291)));
            }

            for (b_coltop = coltop; b_coltop <= coltop_tmp; b_coltop++) {
              b_A[b_coltop - 1] *= 9.9792015476736E+291;
            }

            beta1 *= 9.9792015476736E+291;
            atmp *= 9.9792015476736E+291;
          } while ((fabs(beta1) < 1.0020841800044864E-292) && (knt < 20));

          beta1 = rt_hypotd_snf(atmp, MPC_linear_xnrm2(2 - k_i, b_A, ii + 2));
          if (atmp >= 0.0) {
            beta1 = -beta1;
          }

          tau[k_i] = (beta1 - atmp) / beta1;
          atmp = 1.0 / (atmp - beta1);
          coltop = (((((coltop_tmp - ii) - 1) / 2) << 1) + ii) + 2;
          vectorUB = coltop - 2;
          for (b_coltop = b_lastv; b_coltop <= vectorUB; b_coltop += 2) {
            tmp = _mm_loadu_pd(&b_A[b_coltop - 1]);
            _mm_storeu_pd(&b_A[b_coltop - 1], _mm_mul_pd(tmp, _mm_set1_pd(atmp)));
          }

          for (b_coltop = coltop; b_coltop <= coltop_tmp; b_coltop++) {
            b_A[b_coltop - 1] *= atmp;
          }

          for (b_lastv = 0; b_lastv < knt; b_lastv++) {
            beta1 *= 1.0020841800044864E-292;
          }

          atmp = beta1;
        } else {
          tau[k_i] = (beta1 - b_A[ii]) / beta1;
          atmp = 1.0 / (b_A[ii] - beta1);
          b_coltop = (ii - k_i) + 3;
          coltop = (((((b_coltop - ii) - 1) / 2) << 1) + ii) + 2;
          vectorUB = coltop - 2;
          for (knt = b_lastv; knt <= vectorUB; knt += 2) {
            tmp = _mm_loadu_pd(&b_A[knt - 1]);
            _mm_storeu_pd(&b_A[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(atmp)));
          }

          for (knt = coltop; knt <= b_coltop; knt++) {
            b_A[knt - 1] *= atmp;
          }

          atmp = beta1;
        }
      }

      b_A[ii] = atmp;
      beta1 = b_A[ii];
      b_A[ii] = 1.0;
      if (tau[k_i] != 0.0) {
        b_lastv = 3 - k_i;
        knt = (ii - k_i) + 2;
        while ((b_lastv > 0) && (b_A[knt] == 0.0)) {
          b_lastv--;
          knt--;
        }

        knt = 2 - k_i;
        exitg2 = false;
        while ((!exitg2) && (knt > 0)) {
          b_coltop = ((knt - 1) * 3 + ii) + 3;
          coltop = b_coltop;
          do {
            exitg1 = 0;
            if (coltop + 1 <= b_coltop + b_lastv) {
              if (b_A[coltop] != 0.0) {
                exitg1 = 1;
              } else {
                coltop++;
              }
            } else {
              knt--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        b_lastv = 0;
        knt = 0;
      }

      if (b_lastv > 0) {
        MPC_linear_xgemv(b_lastv, knt, b_A, ii + 4, b_A, ii + 1, work);
        MPC_linear_xgerc(b_lastv, knt, -tau[k_i], ii + 1, work, b_A, ii + 4);
      }

      b_A[ii] = beta1;
    } else {
      tau[2] = 0.0;
    }
  }

  for (k_i = 0; k_i < 3; k_i++) {
    for (ii = 0; ii <= k_i; ii++) {
      R[ii + 3 * k_i] = b_A[3 * k_i + ii];
    }

    for (ii = k_i + 2; ii < 4; ii++) {
      R[(ii + 3 * k_i) - 1] = 0.0;
    }

    work[k_i] = 0.0;
  }

  for (k_i = 2; k_i >= 0; k_i--) {
    b_lastv = (k_i * 3 + k_i) + 4;
    if (k_i + 1 < 3) {
      b_A[b_lastv - 4] = 1.0;
      if (tau[k_i] != 0.0) {
        knt = 3 - k_i;
        b_coltop = b_lastv - k_i;
        while ((knt > 0) && (b_A[b_coltop - 2] == 0.0)) {
          knt--;
          b_coltop--;
        }

        b_coltop = 2 - k_i;
        exitg2 = false;
        while ((!exitg2) && (b_coltop > 0)) {
          coltop = (b_coltop - 1) * 3 + b_lastv;
          ii = coltop;
          do {
            exitg1 = 0;
            if (ii <= (coltop + knt) - 1) {
              if (b_A[ii - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ii++;
              }
            } else {
              b_coltop--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        knt = 0;
        b_coltop = 0;
      }

      if (knt > 0) {
        MPC_linear_xgemv(knt, b_coltop, b_A, b_lastv, b_A, b_lastv - 3, work);
        MPC_linear_xgerc(knt, b_coltop, -tau[k_i], b_lastv - 3, work, b_A,
                         b_lastv);
      }

      b_coltop = (b_lastv - k_i) - 1;
      coltop = (((((b_coltop - b_lastv) + 3) / 2) << 1) + b_lastv) - 2;
      vectorUB = coltop - 2;
      for (knt = b_lastv - 2; knt <= vectorUB; knt += 2) {
        tmp = _mm_loadu_pd(&b_A[knt - 1]);
        _mm_storeu_pd(&b_A[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(-tau[k_i])));
      }

      for (knt = coltop; knt <= b_coltop; knt++) {
        b_A[knt - 1] *= -tau[k_i];
      }
    }

    b_A[b_lastv - 4] = 1.0 - tau[k_i];
    for (knt = 0; knt < k_i; knt++) {
      b_A[(b_lastv - knt) - 5] = 0.0;
    }
  }

  for (k_i = 0; k_i < 3; k_i++) {
    Q[3 * k_i] = b_A[3 * k_i];
    ii = 3 * k_i + 1;
    Q[ii] = b_A[ii];
    ii = 3 * k_i + 2;
    Q[ii] = b_A[ii];
  }

  k_i = 0;
  do {
    exitg1 = 0;
    if (k_i <= nA - 1) {
      if (fabs(R[3 * k_i + k_i]) < 1.0E-12) {
        Status = -2.0;
        exitg1 = 1;
      } else {
        k_i++;
      }
    } else {
      for (k_i = 0; k_i < n; k_i++) {
        for (ii = 0; ii < n; ii++) {
          TL[k_i + 3 * ii] = (b_Linv[3 * k_i + 1] * Q[3 * ii + 1] + b_Linv[3 *
                              k_i] * Q[3 * ii]) + b_Linv[3 * k_i + 2] * Q[3 * ii
            + 2];
        }
      }

      for (b_coltop = 0; b_coltop < 9; b_coltop++) {
        RLinv[b_coltop] = 0.0;
      }

      for (k_i = nA; k_i >= 1; k_i--) {
        b_coltop = (k_i - 1) * 3;
        knt = (k_i + b_coltop) - 1;
        RLinv[knt] = 1.0;
        for (ii = k_i; ii <= nA; ii++) {
          b_lastv = ((ii - 1) * 3 + k_i) - 1;
          RLinv[b_lastv] /= R[knt];
        }

        if (k_i > 1) {
          for (ii = 0; ii <= k_i - 2; ii++) {
            for (b_lastv = k_i; b_lastv <= nA; b_lastv++) {
              knt = (b_lastv - 1) * 3 + ii;
              RLinv[knt] -= RLinv[((b_lastv - 1) * 3 + k_i) - 1] * R[b_coltop +
                ii];
            }
          }
        }
      }

      for (k_i = 0; k_i < n; k_i++) {
        for (ii = k_i + 1; ii <= n; ii++) {
          b_coltop = (ii - 1) * 3 + k_i;
          b_H[b_coltop] = 0.0;
          for (b_lastv = nA + 1; b_lastv <= n; b_lastv++) {
            knt = (b_lastv - 1) * 3;
            b_H[b_coltop] -= TL[(knt + ii) - 1] * TL[knt + k_i];
          }

          b_H[(ii + 3 * k_i) - 1] = b_H[b_coltop];
        }
      }

      for (k_i = 0; k_i < nA; k_i++) {
        for (ii = 0; ii < n; ii++) {
          b_coltop = 3 * k_i + ii;
          D[b_coltop] = 0.0;
          for (b_lastv = k_i + 1; b_lastv <= nA; b_lastv++) {
            D[b_coltop] += TL[(b_lastv - 1) * 3 + ii] * RLinv[(b_lastv - 1) * 3
              + k_i];
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

/* Function for MATLAB Function: '<S26>/optimizer' */
static void MPC_linear_DropConstraint(int32_T kDrop, boolean_T iA[24], int32_T
  *nA, int32_T iC[24])
{
  int32_T i;
  if (kDrop > 0) {
    iA[iC[kDrop - 1] - 1] = false;
    if (kDrop < *nA) {
      for (i = kDrop; i < *nA; i++) {
        iC[i - 1] = iC[i];
      }
    }

    iC[*nA - 1] = 0;
    (*nA)--;
  }
}

/* Function for MATLAB Function: '<S26>/optimizer' */
static void MPC_linear_qpkwik(const real_T b_Linv[9], const real_T b_Hinv[9],
  const real_T f[3], const real_T b_Ac[72], const real_T b[24], boolean_T iA[24],
  int32_T maxiter, real_T FeasTol, real_T x[3], real_T lambda[24], int32_T
  *status)
{
  __m128d tmp_0;
  __m128d tmp_1;
  __m128d tmp_2;
  real_T cTol[24];
  real_T D[9];
  real_T RLinv[9];
  real_T U[9];
  real_T b_H[9];
  real_T Opt[6];
  real_T Rhs[6];
  real_T r[3];
  real_T z[3];
  real_T Xnorm0;
  real_T cMin;
  real_T cVal;
  real_T cVal_tmp;
  real_T rMin;
  real_T t;
  int32_T iC[24];
  int32_T U_tmp;
  int32_T b_exponent;
  int32_T exitg1;
  int32_T exitg3;
  int32_T exponent;
  int32_T i;
  int32_T iC_0;
  int32_T iSave;
  int32_T nA;
  int32_T tmp;
  boolean_T ColdReset;
  boolean_T DualFeasible;
  boolean_T cTolComputed;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1;
  boolean_T guard2;
  x[0] = 0.0;
  x[1] = 0.0;
  x[2] = 0.0;
  *status = 1;
  r[0] = 0.0;
  r[1] = 0.0;
  r[2] = 0.0;
  rMin = 0.0;
  cTolComputed = false;
  for (i = 0; i < 24; i++) {
    lambda[i] = 0.0;
    cTol[i] = 1.0;
    iC[i] = 0;
  }

  nA = 0;
  for (tmp = 0; tmp < 24; tmp++) {
    if (iA[tmp]) {
      nA++;
      iC[nA - 1] = tmp + 1;
    }
  }

  guard1 = false;
  if (nA > 0) {
    for (i = 0; i < 6; i++) {
      Opt[i] = 0.0;
    }

    Rhs[0] = f[0];
    Rhs[3] = 0.0;
    Rhs[1] = f[1];
    Rhs[4] = 0.0;
    Rhs[2] = f[2];
    Rhs[5] = 0.0;
    DualFeasible = false;
    tmp = (int32_T)rt_roundd_snf(0.3 * (real_T)nA);
    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && (*status <= maxiter)) {
        Xnorm0 = MPC_linear_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D, b_H,
          MPC_linear_degrees);
        if (Xnorm0 < 0.0) {
          if (ColdReset) {
            *status = -2;
            exitg3 = 2;
          } else {
            nA = 0;
            memset(&iC[0], 0, 24U * sizeof(int32_T));
            for (i = 0; i < 24; i++) {
              iA[i] = false;
            }

            ColdReset = true;
          }
        } else {
          for (i = 0; i < nA; i++) {
            Rhs[i + 3] = b[iC[i] - 1];
            for (iSave = i + 1; iSave <= nA; iSave++) {
              U[(iSave + 3 * i) - 1] = 0.0;
              for (iC_0 = 0; iC_0 < nA; iC_0++) {
                U_tmp = (3 * i + iSave) - 1;
                U[U_tmp] += RLinv[(3 * iC_0 + iSave) - 1] * RLinv[3 * iC_0 + i];
              }

              U[i + 3 * (iSave - 1)] = U[(3 * i + iSave) - 1];
            }
          }

          for (i = 0; i < 3; i++) {
            Opt[i] = (b_H[i + 3] * Rhs[1] + b_H[i] * Rhs[0]) + b_H[i + 6] * Rhs
              [2];
            for (iSave = 0; iSave < nA; iSave++) {
              Opt[i] += D[3 * iSave + i] * Rhs[iSave + 3];
            }
          }

          for (i = 0; i < nA; i++) {
            Opt[i + 3] = (D[3 * i + 1] * Rhs[1] + D[3 * i] * Rhs[0]) + D[3 * i +
              2] * Rhs[2];
            for (iSave = 0; iSave < nA; iSave++) {
              Opt[i + 3] += U[3 * iSave + i] * Rhs[iSave + 3];
            }
          }

          Xnorm0 = -1.0E-12;
          i = -1;
          for (iSave = 0; iSave < nA; iSave++) {
            cMin = Opt[iSave + 3];
            lambda[iC[iSave] - 1] = cMin;
            if ((cMin < Xnorm0) && (iSave + 1 <= nA)) {
              i = iSave;
              Xnorm0 = Opt[iSave + 3];
            }
          }

          if (i + 1 <= 0) {
            DualFeasible = true;
            x[0] = Opt[0];
            x[1] = Opt[1];
            x[2] = Opt[2];
          } else {
            (*status)++;
            if (tmp <= 5) {
              iC_0 = 5;
            } else {
              iC_0 = tmp;
            }

            if (*status > iC_0) {
              nA = 0;
              memset(&iC[0], 0, 24U * sizeof(int32_T));
              for (i = 0; i < 24; i++) {
                iA[i] = false;
              }

              ColdReset = true;
            } else {
              lambda[iC[i] - 1] = 0.0;
              MPC_linear_DropConstraint(i + 1, iA, &nA, iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          for (i = 0; i < 24; i++) {
            lambda[i] = 0.0;
          }

          for (tmp = 0; tmp <= 0; tmp += 2) {
            tmp_2 = _mm_set1_pd(-1.0);
            _mm_storeu_pd(&x[tmp], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_mul_pd
              (_mm_loadu_pd(&b_Hinv[tmp + 3]), tmp_2), _mm_set1_pd(f[1])),
              _mm_mul_pd(_mm_mul_pd(_mm_loadu_pd(&b_Hinv[tmp]), tmp_2),
                         _mm_set1_pd(f[0]))), _mm_mul_pd(_mm_mul_pd(_mm_loadu_pd
              (&b_Hinv[tmp + 6]), tmp_2), _mm_set1_pd(f[2]))));
          }

          for (tmp = 2; tmp < 3; tmp++) {
            x[tmp] = (-b_Hinv[tmp + 3] * f[1] + -b_Hinv[tmp] * f[0]) +
              -b_Hinv[tmp + 6] * f[2];
          }
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    for (tmp = 0; tmp <= 0; tmp += 2) {
      tmp_2 = _mm_set1_pd(-1.0);
      _mm_storeu_pd(&x[tmp], _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_mul_pd
        (_mm_loadu_pd(&b_Hinv[tmp + 3]), tmp_2), _mm_set1_pd(f[1])), _mm_mul_pd
        (_mm_mul_pd(_mm_loadu_pd(&b_Hinv[tmp]), tmp_2), _mm_set1_pd(f[0]))),
        _mm_mul_pd(_mm_mul_pd(_mm_loadu_pd(&b_Hinv[tmp + 6]), tmp_2),
                   _mm_set1_pd(f[2]))));
    }

    for (tmp = 2; tmp < 3; tmp++) {
      x[tmp] = (-b_Hinv[tmp + 3] * f[1] + -b_Hinv[tmp] * f[0]) + -b_Hinv[tmp + 6]
        * f[2];
    }

    guard1 = true;
  }

  if (guard1) {
    Xnorm0 = MPC_linear_norm(x);
    exitg2 = false;
    while ((!exitg2) && (*status <= maxiter)) {
      cMin = -FeasTol;
      tmp = -1;
      for (i = 0; i < 24; i++) {
        t = cTol[i];
        if (!cTolComputed) {
          z[0] = fabs(b_Ac[i] * x[0]);
          z[1] = fabs(b_Ac[i + 24] * x[1]);
          z[2] = fabs(b_Ac[i + 48] * x[2]);
          cVal = MPC_linear_maximum(z);
          if ((!(t >= cVal)) && (!rtIsNaN(cVal))) {
            t = cVal;
          }
        }

        if (!iA[i]) {
          cVal = (((b_Ac[i + 24] * x[1] + b_Ac[i] * x[0]) + b_Ac[i + 48] * x[2])
                  - b[i]) / t;
          if (cVal < cMin) {
            cMin = cVal;
            tmp = i;
          }
        }

        cTol[i] = t;
      }

      cTolComputed = true;
      if (tmp + 1 <= 0) {
        exitg2 = true;
      } else if (*status == maxiter) {
        *status = 0;
        exitg2 = true;
      } else {
        do {
          exitg1 = 0;
          if ((tmp + 1 > 0) && (*status <= maxiter)) {
            guard2 = false;
            if (nA == 0) {
              for (iC_0 = 0; iC_0 <= 0; iC_0 += 2) {
                _mm_storeu_pd(&z[iC_0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
                  (&b_Hinv[iC_0 + 6]), _mm_set1_pd(b_Ac[tmp + 48])), _mm_add_pd
                  (_mm_mul_pd(_mm_loadu_pd(&b_Hinv[iC_0 + 3]), _mm_set1_pd
                              (b_Ac[tmp + 24])), _mm_add_pd(_mm_mul_pd
                  (_mm_loadu_pd(&b_Hinv[iC_0]), _mm_set1_pd(b_Ac[tmp])),
                  _mm_set1_pd(0.0)))));
              }

              for (iC_0 = 2; iC_0 < 3; iC_0++) {
                z[iC_0] = (b_Hinv[iC_0 + 3] * b_Ac[tmp + 24] + b_Hinv[iC_0] *
                           b_Ac[tmp]) + b_Hinv[iC_0 + 6] * b_Ac[tmp + 48];
              }

              guard2 = true;
            } else {
              cMin = MPC_linear_KWIKfactor(b_Ac, iC, nA, b_Linv, RLinv, D, b_H,
                MPC_linear_degrees);
              if (cMin <= 0.0) {
                *status = -2;
                exitg1 = 1;
              } else {
                for (iC_0 = 0; iC_0 <= 6; iC_0 += 2) {
                  tmp_2 = _mm_loadu_pd(&b_H[iC_0]);
                  _mm_storeu_pd(&U[iC_0], _mm_mul_pd(tmp_2, _mm_set1_pd(-1.0)));
                }

                for (iC_0 = 8; iC_0 < 9; iC_0++) {
                  U[iC_0] = -b_H[iC_0];
                }

                for (iC_0 = 0; iC_0 <= 0; iC_0 += 2) {
                  tmp_2 = _mm_loadu_pd(&U[iC_0]);
                  tmp_0 = _mm_loadu_pd(&U[iC_0 + 3]);
                  tmp_1 = _mm_loadu_pd(&U[iC_0 + 6]);
                  _mm_storeu_pd(&z[iC_0], _mm_add_pd(_mm_mul_pd(tmp_1,
                    _mm_set1_pd(b_Ac[tmp + 48])), _mm_add_pd(_mm_mul_pd(tmp_0,
                    _mm_set1_pd(b_Ac[tmp + 24])), _mm_add_pd(_mm_mul_pd(tmp_2,
                    _mm_set1_pd(b_Ac[tmp])), _mm_set1_pd(0.0)))));
                }

                for (iC_0 = 2; iC_0 < 3; iC_0++) {
                  z[iC_0] = (U[iC_0 + 3] * b_Ac[tmp + 24] + U[iC_0] * b_Ac[tmp])
                    + U[iC_0 + 6] * b_Ac[tmp + 48];
                }

                for (i = 0; i < nA; i++) {
                  r[i] = (D[3 * i + 1] * b_Ac[tmp + 24] + D[3 * i] * b_Ac[tmp])
                    + D[3 * i + 2] * b_Ac[tmp + 48];
                }

                guard2 = true;
              }
            }

            if (guard2) {
              i = 0;
              cMin = 0.0;
              DualFeasible = true;
              ColdReset = true;
              if (nA > 0) {
                iSave = 0;
                exitg4 = false;
                while ((!exitg4) && (iSave <= nA - 1)) {
                  if (r[iSave] >= 1.0E-12) {
                    ColdReset = false;
                    exitg4 = true;
                  } else {
                    iSave++;
                  }
                }
              }

              if ((nA != 0) && (!ColdReset)) {
                for (iSave = 0; iSave < nA; iSave++) {
                  cVal = r[iSave];
                  if (cVal > 1.0E-12) {
                    cVal = lambda[iC[iSave] - 1] / cVal;
                    if ((i == 0) || (cVal < rMin)) {
                      rMin = cVal;
                      i = iSave + 1;
                    }
                  }
                }

                if (i > 0) {
                  cMin = rMin;
                  DualFeasible = false;
                }
              }

              t = b_Ac[tmp + 24];
              cVal_tmp = b_Ac[tmp + 48];
              cVal = (t * z[1] + z[0] * b_Ac[tmp]) + cVal_tmp * z[2];
              if (cVal <= 0.0) {
                cVal = 0.0;
                ColdReset = true;
              } else {
                cVal = (b[tmp] - ((t * x[1] + b_Ac[tmp] * x[0]) + cVal_tmp * x[2]))
                  / cVal;
                ColdReset = false;
              }

              if (DualFeasible && ColdReset) {
                *status = -1;
                exitg1 = 1;
              } else {
                if (ColdReset) {
                  t = cMin;
                } else if (DualFeasible) {
                  t = cVal;
                } else if (cMin < cVal) {
                  t = cMin;
                } else {
                  t = cVal;
                }

                for (iSave = 0; iSave < nA; iSave++) {
                  iC_0 = iC[iSave];
                  lambda[iC_0 - 1] -= t * r[iSave];
                  if ((iC_0 <= 24) && (lambda[iC_0 - 1] < 0.0)) {
                    lambda[iC_0 - 1] = 0.0;
                  }
                }

                lambda[tmp] += t;
                frexp(1.0, &exponent);
                if (fabs(t - cMin) < 2.2204460492503131E-16) {
                  MPC_linear_DropConstraint(i, iA, &nA, iC);
                }

                if (!ColdReset) {
                  x[0] += t * z[0];
                  x[1] += t * z[1];
                  x[2] += t * z[2];
                  frexp(1.0, &b_exponent);
                  if (fabs(t - cVal) < 2.2204460492503131E-16) {
                    if (nA == MPC_linear_degrees) {
                      *status = -1;
                      exitg1 = 1;
                    } else {
                      nA++;
                      iC[nA - 1] = tmp + 1;
                      i = nA - 1;
                      exitg4 = false;
                      while ((!exitg4) && (i + 1 > 1)) {
                        iC_0 = iC[i - 1];
                        if (iC[i] > iC_0) {
                          exitg4 = true;
                        } else {
                          iSave = iC[i];
                          iC[i] = iC_0;
                          iC[i - 1] = iSave;
                          i--;
                        }
                      }

                      iA[tmp] = true;
                      tmp = -1;
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                } else {
                  (*status)++;
                }
              }
            }
          } else {
            cMin = MPC_linear_norm(x);
            if (fabs(cMin - Xnorm0) > 0.001) {
              Xnorm0 = cMin;
              for (tmp = 0; tmp < 24; tmp++) {
                cMin = fabs(b[tmp]);
                if (cMin >= 1.0) {
                  cTol[tmp] = cMin;
                } else {
                  cTol[tmp] = 1.0;
                }
              }

              cTolComputed = false;
            }

            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }
  }
}

/* Model output function for TID0 */
void MPC_linear_output0(void)          /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_SmoothSignalGenerator;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_countstorad;
  boolean_T rtb_RelationalOperator1;
  if (rtmIsMajorTimeStep(MPC_linear_M)) {
    /* set solver stop time */
    if (!(MPC_linear_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&MPC_linear_M->solverInfo,
                            ((MPC_linear_M->Timing.clockTickH0 + 1) *
        MPC_linear_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&MPC_linear_M->solverInfo,
                            ((MPC_linear_M->Timing.clockTick0 + 1) *
        MPC_linear_M->Timing.stepSize0 + MPC_linear_M->Timing.clockTickH0 *
        MPC_linear_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(MPC_linear_M)) {
    MPC_linear_M->Timing.t[0] = rtsiGetT(&MPC_linear_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(MPC_linear_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

    /* S-Function Block: MPC_linear/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(MPC_linear_DW.HILReadEncoderTimebase_Task,
        1, &MPC_linear_DW.HILReadEncoderTimebase_Buffer);
      if (result < 0) {
        rtb_countstorad = 0;
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
      } else {
        rtb_countstorad = MPC_linear_DW.HILReadEncoderTimebase_Buffer;
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: MPC_linear/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(MPC_linear_DW.HILInitialize_Card,
        &MPC_linear_P.HILReadEncoder_channels, 1,
        &MPC_linear_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
      } else {
        rtb_DiscreteTimeIntegrator = MPC_linear_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/counts to rad1' */
    MPC_linear_B.countstorad1 = MPC_linear_P.countstorad1_Gain *
      rtb_DiscreteTimeIntegrator;

    /* Gain: '<S4>/Gain' */
    MPC_linear_B.Gain = MPC_linear_P.Gain_Gain * MPC_linear_B.countstorad1;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_DiscreteTimeIntegrator = MPC_linear_P.Gain1_Gain *
      MPC_linear_P.Constant2_Value;

    /* Gain: '<Root>/counts to rad' */
    rtb_countstorad *= MPC_linear_P.countstorad_Gain;

    /* Gain: '<S3>/Gain' */
    MPC_linear_B.Gain_f[0] = MPC_linear_P.Gain_Gain_a *
      rtb_DiscreteTimeIntegrator;
    MPC_linear_B.Gain_f[1] = MPC_linear_P.Gain_Gain_a * rtb_countstorad;

    /* RateTransition: '<S5>/Rate Transition' */
    if (MPC_linear_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S5>/Rate Transition' */
      MPC_linear_B.RateTransition = MPC_linear_DW.RateTransition_Buffer0;
    }

    /* End of RateTransition: '<S5>/Rate Transition' */

    /* Abs: '<S28>/Abs' */
    rtb_DiscreteTimeIntegrator = fabs(MPC_linear_B.RateTransition);

    /* RelationalOperator: '<S28>/Relational Operator1' incorporates:
     *  Constant: '<S28>/control threshold'
     */
    rtb_RelationalOperator1 = (rtb_DiscreteTimeIntegrator >=
      MPC_linear_P.StallMonitor_control_threshold);
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  TransferFcn: '<Root>/Transfer Fcn1'
   */
  MPC_linear_B.Gain_o = (MPC_linear_P.TransferFcn1_C *
    MPC_linear_X.TransferFcn1_CSTATE + MPC_linear_P.TransferFcn1_D *
    MPC_linear_B.countstorad1) * MPC_linear_P.Gain_Gain_h;
  if (rtmIsMajorTimeStep(MPC_linear_M)) {
    /* Abs: '<S28>/Abs1' */
    rtb_DiscreteTimeIntegrator = fabs(MPC_linear_B.Gain_o);

    /* Logic: '<S28>/Logical Operator' incorporates:
     *  Constant: '<S28>/motion threshold'
     *  RelationalOperator: '<S28>/Relational Operator'
     */
    rtb_RelationalOperator1 = (rtb_RelationalOperator1 &&
      (rtb_DiscreteTimeIntegrator <= MPC_linear_P.StallMonitor_motion_threshold));

    /* Logic: '<S28>/Logical Operator1' */
    MPC_linear_B.LogicalOperator1 = !rtb_RelationalOperator1;

    /* DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
    if (MPC_linear_B.LogicalOperator1 &&
        (MPC_linear_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      MPC_linear_DW.DiscreteTimeIntegrator_DSTATE =
        MPC_linear_P.DiscreteTimeIntegrator_IC;
    }

    rtb_DiscreteTimeIntegrator = MPC_linear_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */

    /* RelationalOperator: '<S28>/Relational Operator2' incorporates:
     *  Constant: '<S28>/control threshold1'
     */
    MPC_linear_B.RelationalOperator2 = (rtb_DiscreteTimeIntegrator >=
      MPC_linear_P.StallMonitor_duration_s);

    /* Stop: '<S29>/Stop Simulation' incorporates:
     *  Constant: '<S30>/Constant'
     *  RelationalOperator: '<S30>/Compare'
     */
    if (MPC_linear_B.RelationalOperator2 != MPC_linear_P.Constant_Value_j) {
      rtmSetStopRequested(MPC_linear_M, 1);
    }

    /* End of Stop: '<S29>/Stop Simulation' */

    /* DataTypeConversion: '<S28>/Data Type Conversion' */
    MPC_linear_B.DataTypeConversion = rtb_RelationalOperator1;
  }

  /* Gain: '<Root>/Gain1' */
  MPC_linear_B.Gain1 = MPC_linear_P.Gain1_Gain_o * MPC_linear_B.Gain_o;
  if (rtmIsMajorTimeStep(MPC_linear_M)) {
    /* Sum: '<Root>/Add1' incorporates:
     *  Constant: '<Root>/Constant3'
     */
    MPC_linear_B.Add1 = rtb_countstorad - MPC_linear_P.Constant3_Value;
  }

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  MPC_linear_B.VectorConcatenate[0] = MPC_linear_B.Gain1;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  MPC_linear_B.VectorConcatenate[2] = MPC_linear_B.countstorad1;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  MPC_linear_B.VectorConcatenate[3] = MPC_linear_B.Add1;

  /* TransferFcn: '<Root>/Transfer Fcn' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  MPC_linear_B.VectorConcatenate[1] = MPC_linear_P.TransferFcn_C *
    MPC_linear_X.TransferFcn_CSTATE;
  MPC_linear_B.VectorConcatenate[1] += MPC_linear_P.TransferFcn_D *
    MPC_linear_B.Add1;

  /* RateTransition generated from: '<S26>/optimizer' incorporates:
   *  Concatenate: '<Root>/Vector Concatenate'
   */
  if (rtmIsMajorTimeStep(MPC_linear_M)) {
    if (MPC_linear_M->Timing.RateInteraction.TID1_2) {
      MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer[0] =
        MPC_linear_B.VectorConcatenate[0];
      MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer[1] =
        MPC_linear_B.VectorConcatenate[1];
      MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer[2] =
        MPC_linear_B.VectorConcatenate[2];
      MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer[3] =
        MPC_linear_B.VectorConcatenate[3];
    }

    /* S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' incorporates:
     *  Concatenate: '<Root>/Vector Concatenate'
     */
    /* S-Function Block: MPC_linear/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI * MPC_linear_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed = (MPC_linear_P.SmoothSignalGenerator_Amplitude
        != MPC_linear_DW.SmoothSignalGenerator_RWORK.Amp || w !=
        MPC_linear_DW.SmoothSignalGenerator_RWORK.W);

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
      real_T y_sin = MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos = MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_SmoothSignalGenerator = MPC_linear_DW.SmoothSignalGenerator_RWORK.Amp *
        y_sin;

      /* Compute the new sin and cos values */
      MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
        MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
        MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
        MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
        MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

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
        if (y_sin == 0 || MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t == 0
            || (y_sin < 0) != (MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t
             < 0)) {
          if (fabs(MPC_linear_DW.SmoothSignalGenerator_RWORK.Amp *
                   MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t) <
              MPC_linear_P.SmoothSignalGenerator_Amplitude) {
            x = asin(MPC_linear_DW.SmoothSignalGenerator_RWORK.Amp *
                     MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t /
                     MPC_linear_P.SmoothSignalGenerator_Amplitude);
            MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(w * 0.0005);
            MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(w * 0.0005);
            MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0)) {
              MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -cos(x);
            } else {
              MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos(x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.0005;
            MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0) {
              MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
            } else {
              MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
            }

            MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin(x);
            MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos(x);
          }

          MPC_linear_DW.SmoothSignalGenerator_RWORK.Amp =
            MPC_linear_P.SmoothSignalGenerator_Amplitude;
          MPC_linear_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }
  }

  /* End of RateTransition generated from: '<S26>/optimizer' */
}

/* Model update function for TID0 */
void MPC_linear_update0(void)          /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(MPC_linear_M)) {
    /* Update for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
    MPC_linear_DW.DiscreteTimeIntegrator_DSTATE +=
      MPC_linear_P.DiscreteTimeIntegrator_gainval *
      MPC_linear_B.DataTypeConversion;
    MPC_linear_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
      MPC_linear_B.LogicalOperator1;
  }

  if (rtmIsMajorTimeStep(MPC_linear_M)) {
    rt_ertODEUpdateContinuousStates(&MPC_linear_M->solverInfo);
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
  if (!(++MPC_linear_M->Timing.clockTick0)) {
    ++MPC_linear_M->Timing.clockTickH0;
  }

  MPC_linear_M->Timing.t[0] = rtsiGetSolverStopTime(&MPC_linear_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++MPC_linear_M->Timing.clockTick1)) {
    ++MPC_linear_M->Timing.clockTickH1;
  }

  MPC_linear_M->Timing.t[1] = MPC_linear_M->Timing.clockTick1 *
    MPC_linear_M->Timing.stepSize1 + MPC_linear_M->Timing.clockTickH1 *
    MPC_linear_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void MPC_linear_derivatives(void)
{
  XDot_MPC_linear_T *_rtXdot;
  _rtXdot = ((XDot_MPC_linear_T *) MPC_linear_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = MPC_linear_P.TransferFcn1_A *
    MPC_linear_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += MPC_linear_B.countstorad1;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = MPC_linear_P.TransferFcn_A *
    MPC_linear_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += MPC_linear_B.Add1;
}

/* Model output function for TID2 */
void MPC_linear_output2(void)          /* Sample time: [0.1s, 0.0s] */
{
  real_T rseq[40];
  real_T a__1[24];
  real_T xk[7];
  real_T y_innov[4];
  real_T f[3];
  real_T zopt[3];
  int32_T i;
  static const real_T b_a[28] = { 0.55364876083545256, 0.16982498363623472,
    0.049360614550879589, 0.023613113750614402, -0.0042446960489002112,
    0.02036185336069022, -0.024892503306887328, 0.14444632951120931,
    0.54247591213637958, -0.007525357226001836, 0.0039074425250199378,
    0.0023346518668445693, 0.00048615081813792674, 0.0627538788156651,
    0.1382578834875407, -0.0086779610462331368, 0.153324872570126,
    -0.00032783979438314262, -0.0004667457802919842, -0.088897268936660764,
    0.0011526038202309653, 0.019551138438429455, 0.010815589847226493,
    -0.00079458557467502588, 0.0050559489665551027, 0.094752055762807388,
    -0.00018272073671534524, -0.0045734954553618267 };

  __m128d tmp;
  real_T b_Mlim[24];
  real_T rtb_xest[7];
  real_T b_Kx;
  real_T rtb_Saturation1;
  int32_T rseq_tmp;
  static const int8_T a[28] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0 };

  static const real_T b_a_0[28] = { 0.55364876083545256, 0.16982498363623472,
    0.049360614550879589, 0.023613113750614402, -0.0042446960489002112,
    0.02036185336069022, -0.024892503306887328, 0.14444632951120931,
    0.54247591213637958, -0.007525357226001836, 0.0039074425250199378,
    0.0023346518668445693, 0.00048615081813792674, 0.0627538788156651,
    0.1382578834875407, -0.0086779610462331368, 0.153324872570126,
    -0.00032783979438314262, -0.0004667457802919842, -0.088897268936660764,
    0.0011526038202309653, 0.019551138438429455, 0.010815589847226493,
    -0.00079458557467502588, 0.0050559489665551027, 0.094752055762807388,
    -0.00018272073671534524, -0.0045734954553618267 };

  static const real_T b_Kx_0[14] = { -0.43353495296096439, 0.42432017729568156,
    0.0, -38.737776806029764, 62.066115058633628, 0.0, 0.0, -0.30318889873327143,
    -2.5451930255733974, 0.0, -15.259166177908821, 64.88332369257347, 0.0, 0.0 };

  static const real_T b_Linv[9] = { 0.37040768832246485, -0.36632795202464646,
    0.0, 0.0, 0.52381855705412506, 0.0, 0.0, 0.0, 0.003162277660168379 };

  static const real_T b_Hinv[9] = { 0.271398024002964, -0.19188937923814306, 0.0,
    -0.19188937923814306, 0.27438588071426567, 0.0, 0.0, 0.0,
    9.9999999999999974E-6 };

  static const real_T b_Ac[72] = { -0.059338062663880885, -0.2150831393598403,
    -0.43513127274730012, -0.71760922163648022, -1.0863005356756639,
    -1.5515219960945101, -2.0905066303266291, -2.6736437353103781,
    -3.2998302855502892, -3.9925014882579548, 0.059338062663880885,
    0.2150831393598403, 0.43513127274730012, 0.71760922163648022,
    1.0863005356756639, 1.5515219960945101, 2.0905066303266291,
    2.6736437353103781, 3.2998302855502892, 3.9925014882579548, -1.0, -1.0, 1.0,
    1.0, -0.0, -0.059338062663880885, -0.2150831393598403, -0.43513127274730012,
    -0.71760922163648022, -1.0863005356756639, -1.5515219960945101,
    -2.0905066303266291, -2.6736437353103781, -3.2998302855502892, 0.0,
    0.059338062663880885, 0.2150831393598403, 0.43513127274730012,
    0.71760922163648022, 1.0863005356756639, 1.5515219960945101,
    2.0905066303266291, 2.6736437353103781, 3.2998302855502892, -0.0, -1.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T b_Kr[80] = { -0.0, -0.0, -0.0, -5.5877653444788562, -0.0,
    -0.0, -0.0, -14.170800598642847, -0.0, 0.0, -0.0, -13.382139321811023, -0.0,
    0.0, -0.0, -3.9241987560223222, -0.0, 0.0, -0.0, 1.6557681011010781, -0.0,
    -0.0, -0.0, -3.6743925736204934, -0.0, -0.0, -0.0, -11.947481645080604, -0.0,
    0.0, -0.0, -11.368701664651129, -0.0, 0.0, -0.0, -2.4836118893672818, -0.0,
    0.0, -0.0, 2.817208633939841, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -5.5877653444788562, -0.0, -0.0, -0.0, -14.170800598642847, -0.0, 0.0, -0.0,
    -13.382139321811023, -0.0, 0.0, -0.0, -3.9241987560223222, -0.0, 0.0, -0.0,
    1.6557681011010781, -0.0, -0.0, -0.0, -3.6743925736204934, -0.0, -0.0, -0.0,
    -11.947481645080604, -0.0, 0.0, -0.0, -11.368701664651129, -0.0, 0.0, -0.0,
    -2.4836118893672818 };

  static const real_T b_Mlim_0[24] = { 1.5707963267949, 1.5707963267949,
    1.5707963267949, 1.5707963267949, 1.5707963267949, 1.5707963267949,
    1.5707963267949, 1.5707963267949, 1.5707963267949, 1.5707963267949,
    1.5707963267949, 1.5707963267949, 1.5707963267949, 1.5707963267949,
    1.5707963267949, 1.5707963267949, 1.5707963267949, 1.5707963267949,
    1.5707963267949, 1.5707963267949, 5.0, 5.0, 5.0, 5.0 };

  static const real_T d_a[24] = { -0.059338062663880885, -0.2150831393598403,
    -0.43513127274730012, -0.71760922163648022, -1.0863005356756639,
    -1.5515219960945101, -2.0905066303266291, -2.6736437353103781,
    -3.2998302855502892, -3.9925014882579548, 0.059338062663880885,
    0.2150831393598403, 0.43513127274730012, 0.71760922163648022,
    1.0863005356756639, 1.5515219960945101, 2.0905066303266291,
    2.6736437353103781, 3.2998302855502892, 3.9925014882579548, -1.0, -1.0, 1.0,
    1.0 };

  static const real_T c_a[168] = { -0.096470465224239577, -0.18720646772122587,
    -0.27411760866069967, -0.35731531180046322, -0.43538488879704729,
    -0.50771267893270555, -0.57565290271623748, -0.64096685806501508,
    -0.70372015492095474, -0.762518824975738, 0.096470465224239577,
    0.18720646772122587, 0.27411760866069967, 0.35731531180046322,
    0.43538488879704729, 0.50771267893270555, 0.57565290271623748,
    0.64096685806501508, 0.70372015492095474, 0.762518824975738, 0.0, 0.0, 0.0,
    0.0, 0.0053373172685339957, 0.032847235883783951, 0.072507762774562112,
    0.096368730775331507, 0.097134020587878928, 0.097779583812503693,
    0.11967129170699933, 0.1535201254199946, 0.17274424401834271,
    0.17015004754221055, -0.0053373172685339957, -0.032847235883783951,
    -0.072507762774562112, -0.096368730775331507, -0.097134020587878928,
    -0.097779583812503693, -0.11967129170699933, -0.1535201254199946,
    -0.17274424401834271, -0.17015004754221055, 0.0, 0.0, 0.0, 0.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.14979233420208898,
    0.37987946313465737, 0.3587376638162294, 0.10519677461372356,
    -0.044386503990608173, 0.098500170720531077, 0.32027851084003411,
    0.30476304107471286, 0.066578676666867231, -0.075521470784218447,
    -0.14979233420208898, -0.37987946313465737, -0.3587376638162294,
    -0.10519677461372356, 0.044386503990608173, -0.098500170720531077,
    -0.32027851084003411, -0.30476304107471286, -0.066578676666867231,
    0.075521470784218447, 0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0,
    -0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const real_T f_a[7] = { 1.1387228932221694, 0.95105253143780089,
    0.059338062663880885, 0.05587765344478856, 0.0, 0.0, 0.0 };

  static const real_T g_a[28] = { 0.43042352339714957, -0.25713733707431763,
    0.09832789483522543, 0.01845655714589596, -0.0042446960489002155,
    0.020361853360690171, -0.024892503306887317, 0.043171660755959192,
    0.1152814111881828, 0.0029287763916857994, 0.041828139435682504,
    0.0023346518668445164, 0.00048615081813796918, 0.06275387881566509,
    0.13103326411378141, -0.0066621026646139381, 0.16675809983048054,
    -0.0012199000502317349, -0.00046674578029197607, -0.0888972689366608,
    0.0011526038202309557, 0.0037112295582929821, -0.05744438188383983,
    0.000276453214375876, 0.002346418909703918, 0.09475205576280743,
    -0.00018272073671534683, -0.0045734954553618545 };

  static const real_T e_a[49] = { 0.93226671260993754, -0.056570316464476973,
    0.096470465224239577, -0.0033237034066722231, 0.0, 0.0, 0.0,
    -0.1502901721601955, 0.31265304148056616, -0.0053373172685339957,
    0.07572234835240825, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    -2.5495053899075359, -11.811807289061544, -0.14979233420208898,
    0.31495951474616957, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  /* MATLAB Function: '<S26>/optimizer' incorporates:
   *  Constant: '<Root>/Constant'
   *  Memory: '<S6>/last_x'
   *  RateTransition generated from: '<S26>/optimizer'
   */
  /* MATLAB Function 'MPC Controller/MPC/optimizer/optimizer': '<S27>:1' */
  /* '<S27>:1:128' */
  /* '<S27>:1:153' */
  /* '<S27>:1:155' */
  /* '<S27>:1:157' */
  /* '<S27>:1:218' */
  /* '<S27>:1:219' */
  /* '<S27>:1:223' */
  /* '<S27>:1:216' */
  /* '<S27>:1:242' */
  /* '<S27>:1:24' */
  /* '<S27>:1:253' */
  /* '<S27>:1:26' */
  /* '<S27>:1:253' */
  /* '<S27>:1:28' */
  /* '<S27>:1:253' */
  /* '<S27>:1:30' */
  /* '<S27>:1:253' */
  /* '<S27>:1:128' */
  for (i = 0; i < 10; i++) {
    rseq_tmp = i << 2;
    rseq[rseq_tmp] = MPC_linear_P.Constant_Value[0];
    rseq[rseq_tmp + 1] = MPC_linear_P.Constant_Value[1];
    rseq[rseq_tmp + 2] = MPC_linear_P.Constant_Value[2];
    rseq[rseq_tmp + 3] = MPC_linear_P.Constant_Value[3];
  }

  /* '<S27>:1:133' */
  /* '<S27>:1:143' */
  /* '<S27>:1:150' */
  /* '<S27>:1:153' */
  for (i = 0; i < 7; i++) {
    xk[i] = MPC_linear_DW.last_x_PreviousInput[i];
  }

  /* '<S27>:1:155' */
  /* '<S27>:1:156' */
  for (rseq_tmp = 0; rseq_tmp < 4; rseq_tmp++) {
    b_Kx = 0.0;
    for (i = 0; i < 7; i++) {
      b_Kx += (real_T)a[(i << 2) + rseq_tmp] * xk[i];
    }

    y_innov[rseq_tmp] = MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer[rseq_tmp]
      - b_Kx;
  }

  /* '<S27>:1:157' */
  for (rseq_tmp = 0; rseq_tmp <= 4; rseq_tmp += 2) {
    /* MATLAB Function: '<S26>/optimizer' */
    tmp = _mm_loadu_pd(&xk[rseq_tmp]);
    _mm_storeu_pd(&rtb_xest[rseq_tmp], _mm_add_pd(_mm_add_pd(_mm_add_pd
      (_mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a[rseq_tmp + 7]), _mm_set1_pd
      (y_innov[1])), _mm_mul_pd(_mm_loadu_pd(&b_a[rseq_tmp]), _mm_set1_pd
      (y_innov[0]))), _mm_mul_pd(_mm_loadu_pd(&b_a[rseq_tmp + 14]), _mm_set1_pd
      (y_innov[2]))), _mm_mul_pd(_mm_loadu_pd(&b_a[rseq_tmp + 21]), _mm_set1_pd
      (y_innov[3]))), tmp));
  }

  /* MATLAB Function: '<S26>/optimizer' incorporates:
   *  Memory: '<S6>/Memory'
   *  UnitDelay: '<S6>/last_mv'
   */
  for (rseq_tmp = 6; rseq_tmp < 7; rseq_tmp++) {
    rtb_xest[rseq_tmp] = (((b_a_0[rseq_tmp + 7] * y_innov[1] + b_a_0[rseq_tmp] *
      y_innov[0]) + b_a_0[rseq_tmp + 14] * y_innov[2]) + b_a_0[rseq_tmp + 21] *
                          y_innov[3]) + xk[rseq_tmp];
  }

  /* '<S27>:1:216' */
  f[0] = 0.0;
  f[1] = 0.0;
  f[2] = 0.0;
  for (i = 0; i < 2; i++) {
    b_Kx = 0.0;
    for (rseq_tmp = 0; rseq_tmp < 7; rseq_tmp++) {
      b_Kx += b_Kx_0[7 * i + rseq_tmp] * rtb_xest[rseq_tmp];
    }

    rtb_Saturation1 = 0.0;
    for (rseq_tmp = 0; rseq_tmp < 40; rseq_tmp++) {
      rtb_Saturation1 += b_Kr[40 * i + rseq_tmp] * rseq[rseq_tmp];
    }

    f[i] = (-2.1913602854603083 * (real_T)i + 7.2885311634981553) *
      MPC_linear_DW.last_mv_DSTATE + (b_Kx + rtb_Saturation1);
  }

  for (i = 0; i < 24; i++) {
    MPC_linear_B.iAout[i] = MPC_linear_DW.Memory_PreviousInput[i];
    b_Kx = 0.0;
    for (rseq_tmp = 0; rseq_tmp < 7; rseq_tmp++) {
      b_Kx += c_a[24 * rseq_tmp + i] * rtb_xest[rseq_tmp];
    }

    b_Mlim[i] = -((b_Mlim_0[i] + b_Kx) + d_a[i] * MPC_linear_DW.last_mv_DSTATE);
  }

  MPC_linear_qpkwik(b_Linv, b_Hinv, f, b_Ac, b_Mlim, MPC_linear_B.iAout, 120,
                    1.0E-6, zopt, a__1, &i);
  if ((i < 0) || (i == 0)) {
    zopt[0] = 0.0;
  }

  rtb_Saturation1 = MPC_linear_DW.last_mv_DSTATE + zopt[0];

  /* '<S27>:1:216' */
  MPC_linear_B.u = rtb_Saturation1;

  /* '<S27>:1:216' */
  /* '<S27>:1:234' */
  /* '<S27>:1:235' */
  /* '<S27>:1:242' */
  /* '<S27>:1:244' */
  for (rseq_tmp = 0; rseq_tmp < 7; rseq_tmp++) {
    b_Kx = 0.0;
    for (i = 0; i < 7; i++) {
      b_Kx += e_a[7 * i + rseq_tmp] * xk[i];
    }

    MPC_linear_B.xk1[rseq_tmp] = (((g_a[rseq_tmp + 7] * y_innov[1] +
      g_a[rseq_tmp] * y_innov[0]) + g_a[rseq_tmp + 14] * y_innov[2]) +
      g_a[rseq_tmp + 21] * y_innov[3]) + (f_a[rseq_tmp] * rtb_Saturation1 + b_Kx);
  }

  /* Gain: '<S6>/umin_scale1' */
  /* '<S27>:1:247' */
  rtb_Saturation1 = MPC_linear_P.umin_scale1_Gain * MPC_linear_B.u;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation1 > MPC_linear_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    MPC_linear_B.Saturation = MPC_linear_P.Saturation_UpperSat;
  } else if (rtb_Saturation1 < MPC_linear_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    MPC_linear_B.Saturation = MPC_linear_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    MPC_linear_B.Saturation = rtb_Saturation1;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (MPC_linear_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' */
    MPC_linear_B.ManualSwitch = MPC_linear_B.Saturation;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    MPC_linear_B.ManualSwitch = MPC_linear_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Saturate: '<Root>/Saturation1' */
  if (MPC_linear_B.ManualSwitch > MPC_linear_P.Saturation1_UpperSat) {
    rtb_Saturation1 = MPC_linear_P.Saturation1_UpperSat;
  } else if (MPC_linear_B.ManualSwitch < MPC_linear_P.Saturation1_LowerSat) {
    rtb_Saturation1 = MPC_linear_P.Saturation1_LowerSat;
  } else {
    rtb_Saturation1 = MPC_linear_B.ManualSwitch;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: MPC_linear/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(MPC_linear_DW.HILInitialize_Card,
      &MPC_linear_P.HILWriteAnalog_channels, 1, &rtb_Saturation1);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
    }
  }

  /* RateTransition: '<S5>/Rate Transition' */
  MPC_linear_DW.RateTransition_Buffer0 = MPC_linear_B.ManualSwitch;
}

/* Model update function for TID2 */
void MPC_linear_update2(void)          /* Sample time: [0.1s, 0.0s] */
{
  int32_T i;

  /* Update for Memory: '<S6>/last_x' */
  for (i = 0; i < 7; i++) {
    MPC_linear_DW.last_x_PreviousInput[i] = MPC_linear_B.xk1[i];
  }

  /* End of Update for Memory: '<S6>/last_x' */

  /* Update for UnitDelay: '<S6>/last_mv' */
  MPC_linear_DW.last_mv_DSTATE = MPC_linear_B.u;

  /* Update for Memory: '<S6>/Memory' */
  for (i = 0; i < 24; i++) {
    MPC_linear_DW.Memory_PreviousInput[i] = MPC_linear_B.iAout[i];
  }

  /* End of Update for Memory: '<S6>/Memory' */

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++MPC_linear_M->Timing.clockTick2)) {
    ++MPC_linear_M->Timing.clockTickH2;
  }

  MPC_linear_M->Timing.t[2] = MPC_linear_M->Timing.clockTick2 *
    MPC_linear_M->Timing.stepSize2 + MPC_linear_M->Timing.clockTickH2 *
    MPC_linear_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void MPC_linear_output(int_T tid)
{
  switch (tid) {
   case 0 :
    MPC_linear_output0();
    break;

   case 2 :
    MPC_linear_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void MPC_linear_update(int_T tid)
{
  switch (tid) {
   case 0 :
    MPC_linear_update0();
    break;

   case 2 :
    MPC_linear_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void MPC_linear_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: MPC_linear/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo2_usb", "0", &MPC_linear_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(MPC_linear_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
      return;
    }

    if ((MPC_linear_P.HILInitialize_AIPStart && !is_switching) ||
        (MPC_linear_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(MPC_linear_DW.HILInitialize_Card,
        &MPC_linear_P.HILInitialize_AIChannels, 1U,
        &MPC_linear_P.HILInitialize_AILow, &MPC_linear_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }

    if ((MPC_linear_P.HILInitialize_AOPStart && !is_switching) ||
        (MPC_linear_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(MPC_linear_DW.HILInitialize_Card,
        &MPC_linear_P.HILInitialize_AOChannels, 1U,
        &MPC_linear_P.HILInitialize_AOLow, &MPC_linear_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }

    if ((MPC_linear_P.HILInitialize_AOStart && !is_switching) ||
        (MPC_linear_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(MPC_linear_DW.HILInitialize_Card,
        &MPC_linear_P.HILInitialize_AOChannels, 1U,
        &MPC_linear_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }

    if (MPC_linear_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (MPC_linear_DW.HILInitialize_Card,
         &MPC_linear_P.HILInitialize_AOChannels, 1U,
         &MPC_linear_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(MPC_linear_DW.HILInitialize_Card, NULL,
      0U, &MPC_linear_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
      return;
    }

    if ((MPC_linear_P.HILInitialize_DOStart && !is_switching) ||
        (MPC_linear_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(MPC_linear_DW.HILInitialize_Card,
        &MPC_linear_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &MPC_linear_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }

    if (MPC_linear_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (MPC_linear_DW.HILInitialize_Card,
         &MPC_linear_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &MPC_linear_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }

    if ((MPC_linear_P.HILInitialize_EIPStart && !is_switching) ||
        (MPC_linear_P.HILInitialize_EIPEnter && is_switching)) {
      MPC_linear_DW.HILInitialize_QuadratureModes[0] =
        MPC_linear_P.HILInitialize_EIQuadrature;
      MPC_linear_DW.HILInitialize_QuadratureModes[1] =
        MPC_linear_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(MPC_linear_DW.HILInitialize_Card,
        MPC_linear_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &MPC_linear_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }

    if ((MPC_linear_P.HILInitialize_EIStart && !is_switching) ||
        (MPC_linear_P.HILInitialize_EIEnter && is_switching)) {
      MPC_linear_DW.HILInitialize_InitialEICounts[0] =
        MPC_linear_P.HILInitialize_EIInitial;
      MPC_linear_DW.HILInitialize_InitialEICounts[1] =
        MPC_linear_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(MPC_linear_DW.HILInitialize_Card,
        MPC_linear_P.HILInitialize_EIChannels, 2U,
        &MPC_linear_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }

    if ((MPC_linear_P.HILInitialize_OOStart && !is_switching) ||
        (MPC_linear_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(MPC_linear_DW.HILInitialize_Card,
        MPC_linear_P.HILInitialize_OOChannels, 3U,
        MPC_linear_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }

    if (MPC_linear_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (MPC_linear_DW.HILInitialize_Card, MPC_linear_P.HILInitialize_OOChannels,
         3U, MPC_linear_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<Root>/HIL Read Encoder Timebase' */

  /* S-Function Block: MPC_linear/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(MPC_linear_DW.HILInitialize_Card,
      MPC_linear_P.HILReadEncoderTimebase_SamplesI,
      &MPC_linear_P.HILReadEncoderTimebase_Channels, 1,
      &MPC_linear_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (MPC_linear_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (MPC_linear_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S5>/Rate Transition' */
  MPC_linear_B.RateTransition = MPC_linear_P.RateTransition_InitialCondition;

  /* Start for S-Function (smooth_signal_generator_block): '<Root>/Smooth Signal Generator' */

  /* S-Function Block: MPC_linear/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / MPC_linear_P.SmoothSignalGenerator_Frequency;
    MPC_linear_DW.SmoothSignalGenerator_RWORK.Amp =
      MPC_linear_P.SmoothSignalGenerator_Amplitude;
    MPC_linear_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      MPC_linear_P.SmoothSignalGenerator_Frequency;
    MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (MPC_linear_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (MPC_linear_DW.SmoothSignalGenerator_RWORK.W * 0.0005);
    MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (MPC_linear_P.SmoothSignalGenerator_InitialPh);
    MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (MPC_linear_P.SmoothSignalGenerator_InitialPh);
  }

  {
    int32_T i;

    /* InitializeConditions for RateTransition: '<S5>/Rate Transition' */
    MPC_linear_DW.RateTransition_Buffer0 =
      MPC_linear_P.RateTransition_InitialCondition;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
    MPC_linear_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S28>/Discrete-Time Integrator' */
    MPC_linear_DW.DiscreteTimeIntegrator_DSTATE =
      MPC_linear_P.DiscreteTimeIntegrator_IC;
    MPC_linear_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
    MPC_linear_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Memory: '<S6>/last_x' */
    for (i = 0; i < 7; i++) {
      MPC_linear_DW.last_x_PreviousInput[i] =
        MPC_linear_P.last_x_InitialCondition[i];
    }

    /* End of InitializeConditions for Memory: '<S6>/last_x' */

    /* InitializeConditions for UnitDelay: '<S6>/last_mv' */
    MPC_linear_DW.last_mv_DSTATE = MPC_linear_P.last_mv_InitialCondition;

    /* InitializeConditions for Memory: '<S6>/Memory' */
    for (i = 0; i < 24; i++) {
      MPC_linear_DW.Memory_PreviousInput[i] =
        MPC_linear_P.Memory_InitialCondition[i];
    }

    /* End of InitializeConditions for Memory: '<S6>/Memory' */
  }
}

/* Model terminate function */
void MPC_linear_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: MPC_linear/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(MPC_linear_DW.HILInitialize_Card);
    hil_monitor_stop_all(MPC_linear_DW.HILInitialize_Card);
    is_switching = false;
    if ((MPC_linear_P.HILInitialize_AOTerminate && !is_switching) ||
        (MPC_linear_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((MPC_linear_P.HILInitialize_DOTerminate && !is_switching) ||
        (MPC_linear_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((MPC_linear_P.HILInitialize_OOTerminate && !is_switching) ||
        (MPC_linear_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(MPC_linear_DW.HILInitialize_Card
                         , &MPC_linear_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &MPC_linear_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , MPC_linear_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &MPC_linear_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &MPC_linear_P.HILInitialize_DOFinal
                         , MPC_linear_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(MPC_linear_DW.HILInitialize_Card,
            &MPC_linear_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &MPC_linear_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(MPC_linear_DW.HILInitialize_Card,
            &MPC_linear_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &MPC_linear_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(MPC_linear_DW.HILInitialize_Card,
            MPC_linear_P.HILInitialize_OOChannels, num_final_other_outputs,
            MPC_linear_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(MPC_linear_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(MPC_linear_DW.HILInitialize_Card);
    hil_monitor_delete_all(MPC_linear_DW.HILInitialize_Card);
    hil_close(MPC_linear_DW.HILInitialize_Card);
    MPC_linear_DW.HILInitialize_Card = NULL;
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
  MPC_linear_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  MPC_linear_update(tid);
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
  MPC_linear_initialize();
}

void MdlTerminate(void)
{
  MPC_linear_terminate();
}

/* Registration function */
RT_MODEL_MPC_linear_T *MPC_linear(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MPC_linear_M, 0,
                sizeof(RT_MODEL_MPC_linear_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MPC_linear_M->solverInfo,
                          &MPC_linear_M->Timing.simTimeStep);
    rtsiSetTPtr(&MPC_linear_M->solverInfo, &rtmGetTPtr(MPC_linear_M));
    rtsiSetStepSizePtr(&MPC_linear_M->solverInfo,
                       &MPC_linear_M->Timing.stepSize0);
    rtsiSetdXPtr(&MPC_linear_M->solverInfo, &MPC_linear_M->derivs);
    rtsiSetContStatesPtr(&MPC_linear_M->solverInfo, (real_T **)
                         &MPC_linear_M->contStates);
    rtsiSetNumContStatesPtr(&MPC_linear_M->solverInfo,
      &MPC_linear_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&MPC_linear_M->solverInfo,
      &MPC_linear_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&MPC_linear_M->solverInfo,
      &MPC_linear_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&MPC_linear_M->solverInfo,
      &MPC_linear_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&MPC_linear_M->solverInfo, (&rtmGetErrorStatus
      (MPC_linear_M)));
    rtsiSetRTModelPtr(&MPC_linear_M->solverInfo, MPC_linear_M);
  }

  rtsiSetSimTimeStep(&MPC_linear_M->solverInfo, MAJOR_TIME_STEP);
  MPC_linear_M->intgData.f[0] = MPC_linear_M->odeF[0];
  MPC_linear_M->contStates = ((real_T *) &MPC_linear_X);
  rtsiSetSolverData(&MPC_linear_M->solverInfo, (void *)&MPC_linear_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&MPC_linear_M->solverInfo, false);
  rtsiSetSolverName(&MPC_linear_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = MPC_linear_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "MPC_linear_M points to
       static memory which is guaranteed to be non-NULL" */
    MPC_linear_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    MPC_linear_M->Timing.sampleTimes = (&MPC_linear_M->Timing.sampleTimesArray[0]);
    MPC_linear_M->Timing.offsetTimes = (&MPC_linear_M->Timing.offsetTimesArray[0]);

    /* task periods */
    MPC_linear_M->Timing.sampleTimes[0] = (0.0);
    MPC_linear_M->Timing.sampleTimes[1] = (0.0005);
    MPC_linear_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    MPC_linear_M->Timing.offsetTimes[0] = (0.0);
    MPC_linear_M->Timing.offsetTimes[1] = (0.0);
    MPC_linear_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(MPC_linear_M, &MPC_linear_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = MPC_linear_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = MPC_linear_M->Timing.perTaskSampleHitsArray;
    MPC_linear_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    MPC_linear_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(MPC_linear_M, -1);
  MPC_linear_M->Timing.stepSize0 = 0.0005;
  MPC_linear_M->Timing.stepSize1 = 0.0005;
  MPC_linear_M->Timing.stepSize2 = 0.1;

  /* External mode info */
  MPC_linear_M->Sizes.checksums[0] = (4080176400U);
  MPC_linear_M->Sizes.checksums[1] = (273858794U);
  MPC_linear_M->Sizes.checksums[2] = (1174157115U);
  MPC_linear_M->Sizes.checksums[3] = (2427828122U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    MPC_linear_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MPC_linear_M->extModeInfo,
      &MPC_linear_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MPC_linear_M->extModeInfo, MPC_linear_M->Sizes.checksums);
    rteiSetTPtr(MPC_linear_M->extModeInfo, rtmGetTPtr(MPC_linear_M));
  }

  MPC_linear_M->solverInfoPtr = (&MPC_linear_M->solverInfo);
  MPC_linear_M->Timing.stepSize = (0.0005);
  rtsiSetFixedStepSize(&MPC_linear_M->solverInfo, 0.0005);
  rtsiSetSolverMode(&MPC_linear_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  MPC_linear_M->blockIO = ((void *) &MPC_linear_B);
  (void) memset(((void *) &MPC_linear_B), 0,
                sizeof(B_MPC_linear_T));

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      MPC_linear_B.xk1[i] = 0.0;
    }

    MPC_linear_B.countstorad1 = 0.0;
    MPC_linear_B.Gain = 0.0;
    MPC_linear_B.Gain_f[0] = 0.0;
    MPC_linear_B.Gain_f[1] = 0.0;
    MPC_linear_B.RateTransition = 0.0;
    MPC_linear_B.Gain_o = 0.0;
    MPC_linear_B.DataTypeConversion = 0.0;
    MPC_linear_B.Gain1 = 0.0;
    MPC_linear_B.Add1 = 0.0;
    MPC_linear_B.VectorConcatenate[0] = 0.0;
    MPC_linear_B.VectorConcatenate[1] = 0.0;
    MPC_linear_B.VectorConcatenate[2] = 0.0;
    MPC_linear_B.VectorConcatenate[3] = 0.0;
    MPC_linear_B.Saturation = 0.0;
    MPC_linear_B.ManualSwitch = 0.0;
    MPC_linear_B.u = 0.0;
  }

  /* parameters */
  MPC_linear_M->defaultParam = ((real_T *)&MPC_linear_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &MPC_linear_X;
    MPC_linear_M->contStates = (x);
    (void) memset((void *)&MPC_linear_X, 0,
                  sizeof(X_MPC_linear_T));
  }

  /* states (dwork) */
  MPC_linear_M->dwork = ((void *) &MPC_linear_DW);
  (void) memset((void *)&MPC_linear_DW, 0,
                sizeof(DW_MPC_linear_T));
  MPC_linear_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  MPC_linear_DW.last_mv_DSTATE = 0.0;
  MPC_linear_DW.HILInitialize_FilterFrequency[0] = 0.0;
  MPC_linear_DW.HILInitialize_FilterFrequency[1] = 0.0;
  MPC_linear_DW.RateTransition_Buffer0 = 0.0;
  MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer[0] = 0.0;
  MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer[1] = 0.0;
  MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer[2] = 0.0;
  MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer[3] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      MPC_linear_DW.last_x_PreviousInput[i] = 0.0;
    }
  }

  MPC_linear_DW.SmoothSignalGenerator_RWORK.Amp = 0.0;
  MPC_linear_DW.SmoothSignalGenerator_RWORK.W = 0.0;
  MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = 0.0;
  MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = 0.0;
  MPC_linear_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0.0;
  MPC_linear_DW.SmoothSignalGenerator_RWORK.Cos_w_t = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    MPC_linear_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 24;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  MPC_linear_M->Sizes.numContStates = (2);/* Number of continuous states */
  MPC_linear_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  MPC_linear_M->Sizes.numY = (0);      /* Number of model outputs */
  MPC_linear_M->Sizes.numU = (0);      /* Number of model inputs */
  MPC_linear_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  MPC_linear_M->Sizes.numSampTimes = (3);/* Number of sample times */
  MPC_linear_M->Sizes.numBlocks = (83);/* Number of blocks */
  MPC_linear_M->Sizes.numBlockIO = (16);/* Number of block outputs */
  MPC_linear_M->Sizes.numBlockPrms = (181);/* Sum of parameter "widths" */
  return MPC_linear_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
