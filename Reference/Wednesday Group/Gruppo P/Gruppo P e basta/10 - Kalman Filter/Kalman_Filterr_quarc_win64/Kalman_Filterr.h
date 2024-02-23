/*
 * Kalman_Filterr.h
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

#ifndef RTW_HEADER_Kalman_Filterr_h_
#define RTW_HEADER_Kalman_Filterr_h_
#ifndef Kalman_Filterr_COMMON_INCLUDES_
#define Kalman_Filterr_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                                 /* Kalman_Filterr_COMMON_INCLUDES_ */

#include "Kalman_Filterr_types.h"
#include "rt_defines.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTimerIndices
#define rtmGetMdlRefGlobalTimerIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalTimerIndices
#define rtmSetMdlRefGlobalTimerIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ()
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ()
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Kalman_Filterr_rtModel         RT_MODEL_Kalman_Filterr_T

/* Block signals (default storage) */
typedef struct {
  real_T HILReadEncoderTimebase_o1;    /* '<S8>/HIL Read Encoder Timebase' */
  real_T HILReadEncoderTimebase_o2;    /* '<S8>/HIL Read Encoder Timebase' */
  real_T SignalGenerator;              /* '<Root>/Signal Generator' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T Armcountstorad;               /* '<S62>/Arm: counts to rad' */
  real_T Gain_b[2];                    /* '<S7>/Gain' */
  real_T Pendulumcountstorad;          /* '<S62>/Pendulum:  counts to rad' */
  real_T MathFunction;                 /* '<S62>/Math Function' */
  real_T Bias;                         /* '<S62>/Bias' */
  real_T X0[4];                        /* '<S3>/X0' */
  real_T MemoryX[4];                   /* '<S3>/MemoryX' */
  real_T Reshapexhat[4];               /* '<S3>/Reshapexhat' */
  real_T WhiteNoise;                   /* '<S5>/White Noise' */
  real_T Output;                       /* '<S5>/Output' */
  real_T Gain1_a[2];                   /* '<Root>/Gain1' */
  real_T Sum2[2];                      /* '<Root>/Sum2' */
  real_T Gain_i;                       /* '<S6>/Gain' */
  real_T alpha;                        /* '<Root>/|alpha|' */
  real_T ConverttoVector[4];           /* '<Root>/Convert to Vector' */
  real_T Sum[4];                       /* '<Root>/Sum' */
  real_T uKx;                          /* '<Root>/u = -K*x' */
  real_T TmpRTBAtSum3Inport2;          /* '<Root>/Gain3' */
  real_T EnableBalanceControlSwitch;/* '<Root>/Enable Balance Control Switch' */
  real_T Akxhatkk1[4];                 /* '<S29>/A[k]*xhat[k|k-1]' */
  real_T Bkuk[4];                      /* '<S29>/B[k]*u[k]' */
  real_T Add[4];                       /* '<S29>/Add' */
  real_T alpha_dot;                    /* '<S63>/alpha_dot' */
  real_T theta_dot;                    /* '<S63>/theta_dot' */
  real_T ForveCCW;                     /* '<S8>/For +ve CCW' */
  real_T WhiteNoise_l;                 /* '<S4>/White Noise' */
  real_T Output_l;                     /* '<S4>/Output' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T Ckxhatkk1[2];                 /* '<S60>/C[k]*xhat[k|k-1]' */
  real_T Dkuk[2];                      /* '<S60>/D[k]*u[k]' */
  real_T yhatkk1[2];                   /* '<S60>/Add1' */
  real_T Sum_j[2];                     /* '<S60>/Sum' */
  real_T Product3[4];                  /* '<S60>/Product3' */
  real_T P[16];                        /* '<S58>/SqrtUsedFcn' */
  uint8_T Compare;                     /* '<S2>/Compare' */
} B_Kalman_Filterr_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_FilterFrequency[2];/* '<Root>/HIL Initialize' */
  real_T NextOutput;                   /* '<S5>/White Noise' */
  real_T TmpRTBAtSum3Inport2_Buffer0;  /* synthesized block */
  real_T NextOutput_m;                 /* '<S4>/White Noise' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  t_task HILReadEncoderTimebase_Task;  /* '<S8>/HIL Read Encoder Timebase' */
  struct {
    void *LoggedData;
  } Thetadeg_PWORK;                    /* '<Root>/ Theta (deg)' */

  struct {
    void *LoggedData;
  } Alfa_PWORK;                        /* '<Root>/Alfa' */

  struct {
    void *LoggedData;
  } Alfadeg_PWORK;                     /* '<Root>/Alfa (deg)' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Theta_PWORK;                       /* '<Root>/Theta' */

  struct {
    void *LoggedData;
  } VmV_PWORK;                         /* '<Root>/Vm (V)' */

  void *HILWriteAnalog_PWORK;          /* '<S8>/HIL Write Analog' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  int32_T HILInitialize_ClockModes;    /* '<Root>/HIL Initialize' */
  int32_T HILInitialize_DOStates;      /* '<Root>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[2];/* '<Root>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[2];/* '<Root>/HIL Initialize' */
  int32_T HILReadEncoderTimebase_Buffer[2];/* '<S8>/HIL Read Encoder Timebase' */
  uint32_T RandSeed;                   /* '<S5>/White Noise' */
  uint32_T RandSeed_a;                 /* '<S4>/White Noise' */
  int_T MemoryX_IWORK;                 /* '<S3>/MemoryX' */
  int8_T MeasurementUpdate_SubsysRanBC;/* '<S29>/MeasurementUpdate' */
  boolean_T MeasurementUpdate_MODE;    /* '<S29>/MeasurementUpdate' */
} DW_Kalman_Filterr_T;

/* Continuous states (default storage) */
typedef struct {
  real_T MemoryX_CSTATE[4];            /* '<S3>/MemoryX' */
  real_T alpha_dot_CSTATE;             /* '<S63>/alpha_dot' */
  real_T theta_dot_CSTATE;             /* '<S63>/theta_dot' */
} X_Kalman_Filterr_T;

/* State derivatives (default storage) */
typedef struct {
  real_T MemoryX_CSTATE[4];            /* '<S3>/MemoryX' */
  real_T alpha_dot_CSTATE;             /* '<S63>/alpha_dot' */
  real_T theta_dot_CSTATE;             /* '<S63>/theta_dot' */
} XDot_Kalman_Filterr_T;

/* State disabled  */
typedef struct {
  boolean_T MemoryX_CSTATE[4];         /* '<S3>/MemoryX' */
  boolean_T alpha_dot_CSTATE;          /* '<S63>/alpha_dot' */
  boolean_T theta_dot_CSTATE;          /* '<S63>/theta_dot' */
} XDis_Kalman_Filterr_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Kalman_Filterr_B
#define BlockIO                        B_Kalman_Filterr_T
#define rtX                            Kalman_Filterr_X
#define ContinuousStates               X_Kalman_Filterr_T
#define rtXdot                         Kalman_Filterr_XDot
#define StateDerivatives               XDot_Kalman_Filterr_T
#define tXdis                          Kalman_Filterr_XDis
#define StateDisabled                  XDis_Kalman_Filterr_T
#define rtP                            Kalman_Filterr_P
#define Parameters                     P_Kalman_Filterr_T
#define rtDWork                        Kalman_Filterr_DW
#define D_Work                         DW_Kalman_Filterr_T

/* Parameters (default storage) */
struct P_Kalman_Filterr_T_ {
  real_T K[4];                         /* Variable: K
                                        * Referenced by: '<Root>/u = -K*x'
                                        */
  real_T Kw;                           /* Variable: Kw
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Q;                            /* Variable: Q
                                        * Referenced by: '<S4>/Output'
                                        */
  real_T R;                            /* Variable: R
                                        * Referenced by: '<S5>/Output'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<S4>/Output'
                                        *   '<S5>/Output'
                                        */
  real_T EnableBalanceControl_const;
                                   /* Mask Parameter: EnableBalanceControl_const
                                    * Referenced by: '<S2>/Constant'
                                    */
  real_T MeasurmentNoise_seed;         /* Mask Parameter: MeasurmentNoise_seed
                                        * Referenced by: '<S5>/White Noise'
                                        */
  real_T Loaddisturbances_seed;        /* Mask Parameter: Loaddisturbances_seed
                                        * Referenced by: '<S4>/White Noise'
                                        */
  uint32_T HILWriteAnalog_channels;   /* Mask Parameter: HILWriteAnalog_channels
                                       * Referenced by: '<S8>/HIL Write Analog'
                                       */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S60>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T HILInitialize_OOTerminate;/* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  real_T HILInitialize_OOExit;    /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<Root>/HIL Initialize'
                                   */
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;    /* Expression: set_other_outputs_at_switch_in
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOFinal[3];     /* Expression: final_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh;         /* Expression: analog_output_maximums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow;          /* Expression: analog_output_minimums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial;      /* Expression: initial_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_AOWatchdog;     /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOInitial[3];   /* Expression: initial_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_OOWatchdog[3];  /* Expression: watchdog_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T SignalGenerator_Amplitude;    /* Expression: 1
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  real_T SignalGenerator_Frequency;    /* Expression: 0.125
                                        * Referenced by: '<Root>/Signal Generator'
                                        */
  real_T Gain_Gain;                    /* Expression: 0
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Armcountstorad_Gain;          /* Expression: -2*pi/512/4
                                        * Referenced by: '<S62>/Arm: counts to rad'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 180/pi
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Pendulumcountstorad_Gain;     /* Expression: 2*pi/512/4
                                        * Referenced by: '<S62>/Pendulum:  counts to rad'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S62>/Constant1'
                                        */
  real_T Bias_Bias;                    /* Expression: -pi
                                        * Referenced by: '<S62>/Bias'
                                        */
  real_T X0_Value[4];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S3>/X0'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S5>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S5>/White Noise'
                                        */
  real_T Gain1_Gain_j[2];              /* Expression: [Ktheta; Kalfa]
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain_ar;                 /* Expression: 180/pi
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T u0V_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/u = 0V'
                                        */
  real_T ConverttoVector_Gain[4];      /* Expression: [1 0 0 0]
                                        * Referenced by: '<Root>/Convert to Vector'
                                        */
  real_T TmpRTBAtSum3Inport2_InitialCond;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T A_Value[16];                  /* Expression: pInitialization.A
                                        * Referenced by: '<S3>/A'
                                        */
  real_T B_Value[4];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S3>/B'
                                        */
  real_T C_Value[8];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S3>/C'
                                        */
  real_T CovarianceZ_Value[16];        /* Expression: pInitialization.Z
                                        * Referenced by: '<S9>/CovarianceZ'
                                        */
  real_T KalmanGainL_Value[8];         /* Expression: pInitialization.L
                                        * Referenced by: '<S9>/KalmanGainL'
                                        */
  real_T D_Value[2];                   /* Expression: pInitialization.D
                                        * Referenced by: '<S3>/D'
                                        */
  real_T alpha_dot_A;                  /* Computed Parameter: alpha_dot_A
                                        * Referenced by: '<S63>/alpha_dot'
                                        */
  real_T alpha_dot_C;                  /* Computed Parameter: alpha_dot_C
                                        * Referenced by: '<S63>/alpha_dot'
                                        */
  real_T alpha_dot_D;                  /* Computed Parameter: alpha_dot_D
                                        * Referenced by: '<S63>/alpha_dot'
                                        */
  real_T theta_dot_A;                  /* Computed Parameter: theta_dot_A
                                        * Referenced by: '<S63>/theta_dot'
                                        */
  real_T theta_dot_C;                  /* Computed Parameter: theta_dot_C
                                        * Referenced by: '<S63>/theta_dot'
                                        */
  real_T theta_dot_D;                  /* Computed Parameter: theta_dot_D
                                        * Referenced by: '<S63>/theta_dot'
                                        */
  real_T ForveCCW_Gain;                /* Expression: -1
                                        * Referenced by: '<S8>/For +ve CCW'
                                        */
  real_T WhiteNoise_Mean_b;            /* Expression: 0
                                        * Referenced by: '<S4>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_g;         /* Computed Parameter: WhiteNoise_StdDev_g
                                       * Referenced by: '<S4>/White Noise'
                                       */
  int32_T HILInitialize_CKChannels;
                                 /* Computed Parameter: HILInitialize_CKChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  int32_T HILInitialize_DOWatchdog;
                                 /* Computed Parameter: HILInitialize_DOWatchdog
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  int32_T HILInitialize_EIInitial;/* Computed Parameter: HILInitialize_EIInitial
                                   * Referenced by: '<Root>/HIL Initialize'
                                   */
  int32_T HILReadEncoderTimebase_Clock;
                             /* Computed Parameter: HILReadEncoderTimebase_Clock
                              * Referenced by: '<S8>/HIL Read Encoder Timebase'
                              */
  uint32_T HILInitialize_AIChannels;
                                 /* Computed Parameter: HILInitialize_AIChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILInitialize_AOChannels;
                                 /* Computed Parameter: HILInitialize_AOChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILInitialize_DOChannels;
                                 /* Computed Parameter: HILInitialize_DOChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIChannels[2];
                                 /* Computed Parameter: HILInitialize_EIChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILInitialize_EIQuadrature;
                               /* Computed Parameter: HILInitialize_EIQuadrature
                                * Referenced by: '<Root>/HIL Initialize'
                                */
  uint32_T HILInitialize_OOChannels[3];
                                 /* Computed Parameter: HILInitialize_OOChannels
                                  * Referenced by: '<Root>/HIL Initialize'
                                  */
  uint32_T HILReadEncoderTimebase_Channels[2];
                          /* Computed Parameter: HILReadEncoderTimebase_Channels
                           * Referenced by: '<S8>/HIL Read Encoder Timebase'
                           */
  uint32_T HILReadEncoderTimebase_SamplesI;
                          /* Computed Parameter: HILReadEncoderTimebase_SamplesI
                           * Referenced by: '<S8>/HIL Read Encoder Timebase'
                           */
  boolean_T HILInitialize_Active;    /* Computed Parameter: HILInitialize_Active
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_AOTerminate;
                                /* Computed Parameter: HILInitialize_AOTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_AOExit;    /* Computed Parameter: HILInitialize_AOExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOTerminate;
                                /* Computed Parameter: HILInitialize_DOTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_DOExit;    /* Computed Parameter: HILInitialize_DOExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_POTerminate;
                                /* Computed Parameter: HILInitialize_POTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_POExit;    /* Computed Parameter: HILInitialize_POExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_CKPStart;/* Computed Parameter: HILInitialize_CKPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKPEnter;/* Computed Parameter: HILInitialize_CKPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_CKStart;  /* Computed Parameter: HILInitialize_CKStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_CKEnter;  /* Computed Parameter: HILInitialize_CKEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AIPStart;/* Computed Parameter: HILInitialize_AIPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AIPEnter;/* Computed Parameter: HILInitialize_AIPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPStart;/* Computed Parameter: HILInitialize_AOPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOPEnter;/* Computed Parameter: HILInitialize_AOPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_AOStart;  /* Computed Parameter: HILInitialize_AOStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOEnter;  /* Computed Parameter: HILInitialize_AOEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_AOReset;  /* Computed Parameter: HILInitialize_AOReset
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOPStart;/* Computed Parameter: HILInitialize_DOPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOPEnter;/* Computed Parameter: HILInitialize_DOPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_DOStart;  /* Computed Parameter: HILInitialize_DOStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOEnter;  /* Computed Parameter: HILInitialize_DOEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOReset;  /* Computed Parameter: HILInitialize_DOReset
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIPStart;/* Computed Parameter: HILInitialize_EIPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIPEnter;/* Computed Parameter: HILInitialize_EIPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_EIStart;  /* Computed Parameter: HILInitialize_EIStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_EIEnter;  /* Computed Parameter: HILInitialize_EIEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POPStart;/* Computed Parameter: HILInitialize_POPStart
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POPEnter;/* Computed Parameter: HILInitialize_POPEnter
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  boolean_T HILInitialize_POStart;  /* Computed Parameter: HILInitialize_POStart
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POEnter;  /* Computed Parameter: HILInitialize_POEnter
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_POReset;  /* Computed Parameter: HILInitialize_POReset
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_OOReset;  /* Computed Parameter: HILInitialize_OOReset
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOFinal;  /* Computed Parameter: HILInitialize_DOFinal
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T HILInitialize_DOInitial;
                                  /* Computed Parameter: HILInitialize_DOInitial
                                   * Referenced by: '<Root>/HIL Initialize'
                                   */
  boolean_T HILReadEncoderTimebase_Active;
                            /* Computed Parameter: HILReadEncoderTimebase_Active
                             * Referenced by: '<S8>/HIL Read Encoder Timebase'
                             */
  boolean_T isSqrtUsed_Value;          /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S58>/isSqrtUsed'
                                        */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S3>/Enable'
                                        */
  boolean_T HILWriteAnalog_Active;  /* Computed Parameter: HILWriteAnalog_Active
                                     * Referenced by: '<S8>/HIL Write Analog'
                                     */
  uint8_T HILReadEncoderTimebase_Overflow;
                          /* Computed Parameter: HILReadEncoderTimebase_Overflow
                           * Referenced by: '<S8>/HIL Read Encoder Timebase'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Kalman_Filterr_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][6];
  ODE1_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Kalman_Filterr_T Kalman_Filterr_P;

/* Block signals (default storage) */
extern B_Kalman_Filterr_T Kalman_Filterr_B;

/* Continuous states (default storage) */
extern X_Kalman_Filterr_T Kalman_Filterr_X;

/* Block states (default storage) */
extern DW_Kalman_Filterr_T Kalman_Filterr_DW;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* Model entry point functions */
extern void Kalman_Filterr_initialize(void);
extern void Kalman_Filterr_output0(void);
extern void Kalman_Filterr_update0(void);
extern void Kalman_Filterr_output2(void);
extern void Kalman_Filterr_update2(void);
extern void Kalman_Filterr_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Kalman_Filterr_rtModel *Kalman_Filterr(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Kalman_Filterr_T *const Kalman_Filterr_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Conversion' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Conversion' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/KalmanGainM' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Conversion' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/G' : Unused code path elimination
 * Block '<S3>/H' : Unused code path elimination
 * Block '<S3>/N' : Unused code path elimination
 * Block '<S3>/P0' : Unused code path elimination
 * Block '<S3>/Q' : Unused code path elimination
 * Block '<S3>/R' : Unused code path elimination
 * Block '<S50>/CheckSignalProperties' : Unused code path elimination
 * Block '<S51>/CheckSignalProperties' : Unused code path elimination
 * Block '<S52>/Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Reshape' : Reshape block reduction
 * Block '<S3>/ReshapeX0' : Reshape block reduction
 * Block '<S3>/Reshapeu' : Reshape block reduction
 * Block '<S3>/Reshapey' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Kalman_Filterr'
 * '<S1>'   : 'Kalman_Filterr/Degrees to Radians'
 * '<S2>'   : 'Kalman_Filterr/Enable Balance Control'
 * '<S3>'   : 'Kalman_Filterr/Kalman Filter'
 * '<S4>'   : 'Kalman_Filterr/Load disturbances'
 * '<S5>'   : 'Kalman_Filterr/Measurment Noise '
 * '<S6>'   : 'Kalman_Filterr/Radians to Degrees'
 * '<S7>'   : 'Kalman_Filterr/Radians to Degrees1'
 * '<S8>'   : 'Kalman_Filterr/Rotary Pendulum Interface'
 * '<S9>'   : 'Kalman_Filterr/Kalman Filter/CalculatePL'
 * '<S10>'  : 'Kalman_Filterr/Kalman Filter/CalculateYhat'
 * '<S11>'  : 'Kalman_Filterr/Kalman Filter/CovarianceOutputConfigurator'
 * '<S12>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionA'
 * '<S13>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionB'
 * '<S14>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionC'
 * '<S15>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionD'
 * '<S16>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionEnable'
 * '<S17>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionG'
 * '<S18>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionH'
 * '<S19>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionN'
 * '<S20>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionP'
 * '<S21>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionP0'
 * '<S22>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionQ'
 * '<S23>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionR'
 * '<S24>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionReset'
 * '<S25>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionX'
 * '<S26>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionX0'
 * '<S27>'  : 'Kalman_Filterr/Kalman Filter/DataTypeConversionu'
 * '<S28>'  : 'Kalman_Filterr/Kalman Filter/MemoryP'
 * '<S29>'  : 'Kalman_Filterr/Kalman Filter/Observer'
 * '<S30>'  : 'Kalman_Filterr/Kalman Filter/ReducedQRN'
 * '<S31>'  : 'Kalman_Filterr/Kalman Filter/Reset'
 * '<S32>'  : 'Kalman_Filterr/Kalman Filter/Reshapeyhat'
 * '<S33>'  : 'Kalman_Filterr/Kalman Filter/ScalarExpansionP0'
 * '<S34>'  : 'Kalman_Filterr/Kalman Filter/ScalarExpansionQ'
 * '<S35>'  : 'Kalman_Filterr/Kalman Filter/ScalarExpansionR'
 * '<S36>'  : 'Kalman_Filterr/Kalman Filter/UseCurrentEstimator'
 * '<S37>'  : 'Kalman_Filterr/Kalman Filter/checkA'
 * '<S38>'  : 'Kalman_Filterr/Kalman Filter/checkB'
 * '<S39>'  : 'Kalman_Filterr/Kalman Filter/checkC'
 * '<S40>'  : 'Kalman_Filterr/Kalman Filter/checkD'
 * '<S41>'  : 'Kalman_Filterr/Kalman Filter/checkEnable'
 * '<S42>'  : 'Kalman_Filterr/Kalman Filter/checkG'
 * '<S43>'  : 'Kalman_Filterr/Kalman Filter/checkH'
 * '<S44>'  : 'Kalman_Filterr/Kalman Filter/checkN'
 * '<S45>'  : 'Kalman_Filterr/Kalman Filter/checkP0'
 * '<S46>'  : 'Kalman_Filterr/Kalman Filter/checkQ'
 * '<S47>'  : 'Kalman_Filterr/Kalman Filter/checkR'
 * '<S48>'  : 'Kalman_Filterr/Kalman Filter/checkReset'
 * '<S49>'  : 'Kalman_Filterr/Kalman Filter/checkX0'
 * '<S50>'  : 'Kalman_Filterr/Kalman Filter/checku'
 * '<S51>'  : 'Kalman_Filterr/Kalman Filter/checky'
 * '<S52>'  : 'Kalman_Filterr/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S53>'  : 'Kalman_Filterr/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S54>'  : 'Kalman_Filterr/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S55>'  : 'Kalman_Filterr/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S56>'  : 'Kalman_Filterr/Kalman Filter/CalculatePL/Ground'
 * '<S57>'  : 'Kalman_Filterr/Kalman Filter/CalculateYhat/Ground'
 * '<S58>'  : 'Kalman_Filterr/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S59>'  : 'Kalman_Filterr/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S60>'  : 'Kalman_Filterr/Kalman Filter/Observer/MeasurementUpdate'
 * '<S61>'  : 'Kalman_Filterr/Kalman Filter/ReducedQRN/Ground'
 * '<S62>'  : 'Kalman_Filterr/Rotary Pendulum Interface/Counts to Angles'
 * '<S63>'  : 'Kalman_Filterr/Rotary Pendulum Interface/State X'
 */
#endif                                 /* RTW_HEADER_Kalman_Filterr_h_ */
