    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (Kalman_Upward_P)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Kalman_Upward_P.K_pp
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_P.ts
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 4;

                    ;% Kalman_Upward_P.StallMonitor_control_threshold
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 5;

                    ;% Kalman_Upward_P.StallMonitor_duration_s
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% Kalman_Upward_P.StallMonitor_motion_threshold
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Kalman_Upward_P.HILReadEncoder_channels
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_P.HILWriteAnalog_channels
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Upward_P.StopwithMessage_message_icon
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 54;
            section.data(54)  = dumData; %prealloc

                    ;% Kalman_Upward_P.Lykyhatkk1_Y0
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_P.deltax_Y0
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Upward_P.HILInitialize_OOTerminate
                    section.data(3).logicalSrcIdx = 10;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Upward_P.HILInitialize_OOExit
                    section.data(4).logicalSrcIdx = 11;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Upward_P.HILInitialize_OOStart
                    section.data(5).logicalSrcIdx = 12;
                    section.data(5).dtTransOffset = 4;

                    ;% Kalman_Upward_P.HILInitialize_OOEnter
                    section.data(6).logicalSrcIdx = 13;
                    section.data(6).dtTransOffset = 5;

                    ;% Kalman_Upward_P.HILInitialize_AOFinal
                    section.data(7).logicalSrcIdx = 14;
                    section.data(7).dtTransOffset = 6;

                    ;% Kalman_Upward_P.HILInitialize_OOFinal
                    section.data(8).logicalSrcIdx = 15;
                    section.data(8).dtTransOffset = 7;

                    ;% Kalman_Upward_P.HILInitialize_AIHigh
                    section.data(9).logicalSrcIdx = 16;
                    section.data(9).dtTransOffset = 10;

                    ;% Kalman_Upward_P.HILInitialize_AILow
                    section.data(10).logicalSrcIdx = 17;
                    section.data(10).dtTransOffset = 11;

                    ;% Kalman_Upward_P.HILInitialize_AOHigh
                    section.data(11).logicalSrcIdx = 18;
                    section.data(11).dtTransOffset = 12;

                    ;% Kalman_Upward_P.HILInitialize_AOLow
                    section.data(12).logicalSrcIdx = 19;
                    section.data(12).dtTransOffset = 13;

                    ;% Kalman_Upward_P.HILInitialize_AOInitial
                    section.data(13).logicalSrcIdx = 20;
                    section.data(13).dtTransOffset = 14;

                    ;% Kalman_Upward_P.HILInitialize_AOWatchdog
                    section.data(14).logicalSrcIdx = 21;
                    section.data(14).dtTransOffset = 15;

                    ;% Kalman_Upward_P.HILInitialize_OOInitial
                    section.data(15).logicalSrcIdx = 22;
                    section.data(15).dtTransOffset = 16;

                    ;% Kalman_Upward_P.HILInitialize_OOWatchdog
                    section.data(16).logicalSrcIdx = 23;
                    section.data(16).dtTransOffset = 19;

                    ;% Kalman_Upward_P.countstorad1_Gain
                    section.data(17).logicalSrcIdx = 24;
                    section.data(17).dtTransOffset = 22;

                    ;% Kalman_Upward_P.TransferFcn1_A
                    section.data(18).logicalSrcIdx = 25;
                    section.data(18).dtTransOffset = 23;

                    ;% Kalman_Upward_P.TransferFcn1_C
                    section.data(19).logicalSrcIdx = 26;
                    section.data(19).dtTransOffset = 24;

                    ;% Kalman_Upward_P.TransferFcn1_D
                    section.data(20).logicalSrcIdx = 27;
                    section.data(20).dtTransOffset = 25;

                    ;% Kalman_Upward_P.Gain_Gain
                    section.data(21).logicalSrcIdx = 28;
                    section.data(21).dtTransOffset = 26;

                    ;% Kalman_Upward_P.Gain1_Gain
                    section.data(22).logicalSrcIdx = 29;
                    section.data(22).dtTransOffset = 27;

                    ;% Kalman_Upward_P.Constant3_Value
                    section.data(23).logicalSrcIdx = 30;
                    section.data(23).dtTransOffset = 28;

                    ;% Kalman_Upward_P.countstorad_Gain
                    section.data(24).logicalSrcIdx = 31;
                    section.data(24).dtTransOffset = 29;

                    ;% Kalman_Upward_P.TransferFcn_A
                    section.data(25).logicalSrcIdx = 32;
                    section.data(25).dtTransOffset = 30;

                    ;% Kalman_Upward_P.TransferFcn_C
                    section.data(26).logicalSrcIdx = 33;
                    section.data(26).dtTransOffset = 31;

                    ;% Kalman_Upward_P.TransferFcn_D
                    section.data(27).logicalSrcIdx = 34;
                    section.data(27).dtTransOffset = 32;

                    ;% Kalman_Upward_P.KalmanGainM_Value
                    section.data(28).logicalSrcIdx = 35;
                    section.data(28).dtTransOffset = 33;

                    ;% Kalman_Upward_P.C_Value
                    section.data(29).logicalSrcIdx = 36;
                    section.data(29).dtTransOffset = 42;

                    ;% Kalman_Upward_P.X0_Value
                    section.data(30).logicalSrcIdx = 37;
                    section.data(30).dtTransOffset = 51;

                    ;% Kalman_Upward_P.Constant2_Value
                    section.data(31).logicalSrcIdx = 38;
                    section.data(31).dtTransOffset = 54;

                    ;% Kalman_Upward_P.Gain1_Gain_a
                    section.data(32).logicalSrcIdx = 39;
                    section.data(32).dtTransOffset = 55;

                    ;% Kalman_Upward_P.Saturation_UpperSat
                    section.data(33).logicalSrcIdx = 40;
                    section.data(33).dtTransOffset = 56;

                    ;% Kalman_Upward_P.Saturation_LowerSat
                    section.data(34).logicalSrcIdx = 41;
                    section.data(34).dtTransOffset = 57;

                    ;% Kalman_Upward_P.Constant1_Value
                    section.data(35).logicalSrcIdx = 42;
                    section.data(35).dtTransOffset = 58;

                    ;% Kalman_Upward_P.Switch_Threshold
                    section.data(36).logicalSrcIdx = 43;
                    section.data(36).dtTransOffset = 59;

                    ;% Kalman_Upward_P.Step_Time
                    section.data(37).logicalSrcIdx = 44;
                    section.data(37).dtTransOffset = 60;

                    ;% Kalman_Upward_P.Step_Y0
                    section.data(38).logicalSrcIdx = 45;
                    section.data(38).dtTransOffset = 61;

                    ;% Kalman_Upward_P.Step_YFinal
                    section.data(39).logicalSrcIdx = 46;
                    section.data(39).dtTransOffset = 62;

                    ;% Kalman_Upward_P.Step1_Time
                    section.data(40).logicalSrcIdx = 47;
                    section.data(40).dtTransOffset = 63;

                    ;% Kalman_Upward_P.Step1_Y0
                    section.data(41).logicalSrcIdx = 48;
                    section.data(41).dtTransOffset = 64;

                    ;% Kalman_Upward_P.Step1_YFinal
                    section.data(42).logicalSrcIdx = 49;
                    section.data(42).dtTransOffset = 65;

                    ;% Kalman_Upward_P.Saturation1_UpperSat
                    section.data(43).logicalSrcIdx = 50;
                    section.data(43).dtTransOffset = 66;

                    ;% Kalman_Upward_P.Saturation1_LowerSat
                    section.data(44).logicalSrcIdx = 51;
                    section.data(44).dtTransOffset = 67;

                    ;% Kalman_Upward_P.DiscreteTimeIntegrator_gainval
                    section.data(45).logicalSrcIdx = 52;
                    section.data(45).dtTransOffset = 68;

                    ;% Kalman_Upward_P.DiscreteTimeIntegrator_IC
                    section.data(46).logicalSrcIdx = 53;
                    section.data(46).dtTransOffset = 69;

                    ;% Kalman_Upward_P.A_Value
                    section.data(47).logicalSrcIdx = 54;
                    section.data(47).dtTransOffset = 70;

                    ;% Kalman_Upward_P.B_Value
                    section.data(48).logicalSrcIdx = 55;
                    section.data(48).dtTransOffset = 79;

                    ;% Kalman_Upward_P.CovarianceZ_Value
                    section.data(49).logicalSrcIdx = 56;
                    section.data(49).dtTransOffset = 82;

                    ;% Kalman_Upward_P.KalmanGainL_Value
                    section.data(50).logicalSrcIdx = 57;
                    section.data(50).dtTransOffset = 91;

                    ;% Kalman_Upward_P.D_Value
                    section.data(51).logicalSrcIdx = 58;
                    section.data(51).dtTransOffset = 100;

                    ;% Kalman_Upward_P.SmoothSignalGenerator_InitialPh
                    section.data(52).logicalSrcIdx = 59;
                    section.data(52).dtTransOffset = 103;

                    ;% Kalman_Upward_P.SmoothSignalGenerator_Amplitude
                    section.data(53).logicalSrcIdx = 60;
                    section.data(53).dtTransOffset = 104;

                    ;% Kalman_Upward_P.SmoothSignalGenerator_Frequency
                    section.data(54).logicalSrcIdx = 61;
                    section.data(54).dtTransOffset = 105;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Kalman_Upward_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 62;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 63;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Upward_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 64;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Upward_P.HILReadEncoderTimebase_Clock
                    section.data(4).logicalSrcIdx = 65;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Kalman_Upward_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 66;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 67;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Upward_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 68;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Upward_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 69;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Upward_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 70;
                    section.data(5).dtTransOffset = 5;

                    ;% Kalman_Upward_P.HILInitialize_OOChannels
                    section.data(6).logicalSrcIdx = 71;
                    section.data(6).dtTransOffset = 6;

                    ;% Kalman_Upward_P.HILReadEncoderTimebase_Channels
                    section.data(7).logicalSrcIdx = 72;
                    section.data(7).dtTransOffset = 9;

                    ;% Kalman_Upward_P.HILReadEncoderTimebase_SamplesI
                    section.data(8).logicalSrcIdx = 73;
                    section.data(8).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 41;
            section.data(41)  = dumData; %prealloc

                    ;% Kalman_Upward_P.Constant_Value
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_P.HILInitialize_Active
                    section.data(2).logicalSrcIdx = 75;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Upward_P.HILInitialize_AOTerminate
                    section.data(3).logicalSrcIdx = 76;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Upward_P.HILInitialize_AOExit
                    section.data(4).logicalSrcIdx = 77;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Upward_P.HILInitialize_DOTerminate
                    section.data(5).logicalSrcIdx = 78;
                    section.data(5).dtTransOffset = 4;

                    ;% Kalman_Upward_P.HILInitialize_DOExit
                    section.data(6).logicalSrcIdx = 79;
                    section.data(6).dtTransOffset = 5;

                    ;% Kalman_Upward_P.HILInitialize_POTerminate
                    section.data(7).logicalSrcIdx = 80;
                    section.data(7).dtTransOffset = 6;

                    ;% Kalman_Upward_P.HILInitialize_POExit
                    section.data(8).logicalSrcIdx = 81;
                    section.data(8).dtTransOffset = 7;

                    ;% Kalman_Upward_P.HILInitialize_CKPStart
                    section.data(9).logicalSrcIdx = 82;
                    section.data(9).dtTransOffset = 8;

                    ;% Kalman_Upward_P.HILInitialize_CKPEnter
                    section.data(10).logicalSrcIdx = 83;
                    section.data(10).dtTransOffset = 9;

                    ;% Kalman_Upward_P.HILInitialize_CKStart
                    section.data(11).logicalSrcIdx = 84;
                    section.data(11).dtTransOffset = 10;

                    ;% Kalman_Upward_P.HILInitialize_CKEnter
                    section.data(12).logicalSrcIdx = 85;
                    section.data(12).dtTransOffset = 11;

                    ;% Kalman_Upward_P.HILInitialize_AIPStart
                    section.data(13).logicalSrcIdx = 86;
                    section.data(13).dtTransOffset = 12;

                    ;% Kalman_Upward_P.HILInitialize_AIPEnter
                    section.data(14).logicalSrcIdx = 87;
                    section.data(14).dtTransOffset = 13;

                    ;% Kalman_Upward_P.HILInitialize_AOPStart
                    section.data(15).logicalSrcIdx = 88;
                    section.data(15).dtTransOffset = 14;

                    ;% Kalman_Upward_P.HILInitialize_AOPEnter
                    section.data(16).logicalSrcIdx = 89;
                    section.data(16).dtTransOffset = 15;

                    ;% Kalman_Upward_P.HILInitialize_AOStart
                    section.data(17).logicalSrcIdx = 90;
                    section.data(17).dtTransOffset = 16;

                    ;% Kalman_Upward_P.HILInitialize_AOEnter
                    section.data(18).logicalSrcIdx = 91;
                    section.data(18).dtTransOffset = 17;

                    ;% Kalman_Upward_P.HILInitialize_AOReset
                    section.data(19).logicalSrcIdx = 92;
                    section.data(19).dtTransOffset = 18;

                    ;% Kalman_Upward_P.HILInitialize_DOPStart
                    section.data(20).logicalSrcIdx = 93;
                    section.data(20).dtTransOffset = 19;

                    ;% Kalman_Upward_P.HILInitialize_DOPEnter
                    section.data(21).logicalSrcIdx = 94;
                    section.data(21).dtTransOffset = 20;

                    ;% Kalman_Upward_P.HILInitialize_DOStart
                    section.data(22).logicalSrcIdx = 95;
                    section.data(22).dtTransOffset = 21;

                    ;% Kalman_Upward_P.HILInitialize_DOEnter
                    section.data(23).logicalSrcIdx = 96;
                    section.data(23).dtTransOffset = 22;

                    ;% Kalman_Upward_P.HILInitialize_DOReset
                    section.data(24).logicalSrcIdx = 97;
                    section.data(24).dtTransOffset = 23;

                    ;% Kalman_Upward_P.HILInitialize_EIPStart
                    section.data(25).logicalSrcIdx = 98;
                    section.data(25).dtTransOffset = 24;

                    ;% Kalman_Upward_P.HILInitialize_EIPEnter
                    section.data(26).logicalSrcIdx = 99;
                    section.data(26).dtTransOffset = 25;

                    ;% Kalman_Upward_P.HILInitialize_EIStart
                    section.data(27).logicalSrcIdx = 100;
                    section.data(27).dtTransOffset = 26;

                    ;% Kalman_Upward_P.HILInitialize_EIEnter
                    section.data(28).logicalSrcIdx = 101;
                    section.data(28).dtTransOffset = 27;

                    ;% Kalman_Upward_P.HILInitialize_POPStart
                    section.data(29).logicalSrcIdx = 102;
                    section.data(29).dtTransOffset = 28;

                    ;% Kalman_Upward_P.HILInitialize_POPEnter
                    section.data(30).logicalSrcIdx = 103;
                    section.data(30).dtTransOffset = 29;

                    ;% Kalman_Upward_P.HILInitialize_POStart
                    section.data(31).logicalSrcIdx = 104;
                    section.data(31).dtTransOffset = 30;

                    ;% Kalman_Upward_P.HILInitialize_POEnter
                    section.data(32).logicalSrcIdx = 105;
                    section.data(32).dtTransOffset = 31;

                    ;% Kalman_Upward_P.HILInitialize_POReset
                    section.data(33).logicalSrcIdx = 106;
                    section.data(33).dtTransOffset = 32;

                    ;% Kalman_Upward_P.HILInitialize_OOReset
                    section.data(34).logicalSrcIdx = 107;
                    section.data(34).dtTransOffset = 33;

                    ;% Kalman_Upward_P.HILInitialize_DOFinal
                    section.data(35).logicalSrcIdx = 108;
                    section.data(35).dtTransOffset = 34;

                    ;% Kalman_Upward_P.HILInitialize_DOInitial
                    section.data(36).logicalSrcIdx = 109;
                    section.data(36).dtTransOffset = 35;

                    ;% Kalman_Upward_P.HILReadEncoderTimebase_Active
                    section.data(37).logicalSrcIdx = 110;
                    section.data(37).dtTransOffset = 36;

                    ;% Kalman_Upward_P.HILReadEncoder_Active
                    section.data(38).logicalSrcIdx = 111;
                    section.data(38).dtTransOffset = 37;

                    ;% Kalman_Upward_P.Enable_Value
                    section.data(39).logicalSrcIdx = 112;
                    section.data(39).dtTransOffset = 38;

                    ;% Kalman_Upward_P.HILWriteAnalog_Active
                    section.data(40).logicalSrcIdx = 113;
                    section.data(40).dtTransOffset = 39;

                    ;% Kalman_Upward_P.isSqrtUsed_Value
                    section.data(41).logicalSrcIdx = 114;
                    section.data(41).dtTransOffset = 40;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Kalman_Upward_P.HILReadEncoderTimebase_Overflow
                    section.data(1).logicalSrcIdx = 115;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_P.ManualSwitch_CurrentSetting
                    section.data(2).logicalSrcIdx = 116;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (Kalman_Upward_B)
        ;%
            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% Kalman_Upward_B.countstorad1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_B.Gain
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Upward_B.Gain1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Upward_B.countstorad
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Upward_B.Sum
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Kalman_Upward_B.Quantizer
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% Kalman_Upward_B.Add
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% Kalman_Upward_B.Gain1_d
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 12;

                    ;% Kalman_Upward_B.Add_e
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 13;

                    ;% Kalman_Upward_B.Saturation
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 14;

                    ;% Kalman_Upward_B.Switch
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 15;

                    ;% Kalman_Upward_B.Saturation1
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 16;

                    ;% Kalman_Upward_B.DataTypeConversion
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 17;

                    ;% Kalman_Upward_B.Quantizer1
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 18;

                    ;% Kalman_Upward_B.Add_j
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 19;

                    ;% Kalman_Upward_B.y
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 22;

                    ;% Kalman_Upward_B.Product2
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 23;

                    ;% Kalman_Upward_B.Product3
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 26;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Kalman_Upward_B.LogicalOperator1
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_B.RelationalOperator2
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 2;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (Kalman_Upward_DW)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Kalman_Upward_DW.MemoryX_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% Kalman_Upward_DW.HILInitialize_FilterFrequency
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Upward_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Upward_DW.HILReadEncoderTimebase_Task
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Upward_DW.SmoothSignalGenerator_RWORK.Amp
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% Kalman_Upward_DW.HILReadEncoder_PWORK
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_DW.HILWriteAnalog_PWORK
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Upward_DW.MotorVoltageV_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Upward_DW.Motorangledeg_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Upward_DW.Pendulumangledeg_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 4;

                    ;% Kalman_Upward_DW.Scope_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 5;

                    ;% Kalman_Upward_DW.ToWorkspace_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 6;

                    ;% Kalman_Upward_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 7;

                    ;% Kalman_Upward_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 8;

                    ;% Kalman_Upward_DW.ToWorkspace3_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 9;

                    ;% Kalman_Upward_DW.ToWorkspace4_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 10;

                    ;% Kalman_Upward_DW.ToWorkspace5_PWORK.LoggedData
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Kalman_Upward_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_DW.HILInitialize_DOStates
                    section.data(2).logicalSrcIdx = 19;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Upward_DW.HILInitialize_QuadratureModes
                    section.data(3).logicalSrcIdx = 20;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Upward_DW.HILInitialize_InitialEICounts
                    section.data(4).logicalSrcIdx = 21;
                    section.data(4).dtTransOffset = 4;

                    ;% Kalman_Upward_DW.HILReadEncoderTimebase_Buffer
                    section.data(5).logicalSrcIdx = 22;
                    section.data(5).dtTransOffset = 6;

                    ;% Kalman_Upward_DW.HILReadEncoder_Buffer
                    section.data(6).logicalSrcIdx = 23;
                    section.data(6).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Kalman_Upward_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_DW.EnabledSubsystem_SubsysRanBC
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Upward_DW.MeasurementUpdate_SubsysRanBC
                    section.data(3).logicalSrcIdx = 26;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Kalman_Upward_DW.icLoad
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Upward_DW.EnabledSubsystem_MODE
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Upward_DW.MeasurementUpdate_MODE
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3416835456;
    targMap.checksum1 = 1048431882;
    targMap.checksum2 = 2374279873;
    targMap.checksum3 = 1756012103;

