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
        ;% Auto data (MPC_linear_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% MPC_linear_P.StallMonitor_control_threshold
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_P.StallMonitor_duration_s
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_P.StallMonitor_motion_threshold
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% MPC_linear_P.HILReadEncoder_channels
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_P.HILWriteAnalog_channels
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% MPC_linear_P.StopwithMessage_message_icon
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 65;
            section.data(65)  = dumData; %prealloc

                    ;% MPC_linear_P.Constant1_Value
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_P.HILInitialize_OOTerminate
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_P.HILInitialize_OOExit
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% MPC_linear_P.HILInitialize_OOStart
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% MPC_linear_P.HILInitialize_OOEnter
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 4;

                    ;% MPC_linear_P.HILInitialize_AOFinal
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 5;

                    ;% MPC_linear_P.HILInitialize_OOFinal
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 6;

                    ;% MPC_linear_P.HILInitialize_AIHigh
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 9;

                    ;% MPC_linear_P.HILInitialize_AILow
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 10;

                    ;% MPC_linear_P.HILInitialize_AOHigh
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 11;

                    ;% MPC_linear_P.HILInitialize_AOLow
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 12;

                    ;% MPC_linear_P.HILInitialize_AOInitial
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 13;

                    ;% MPC_linear_P.HILInitialize_AOWatchdog
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 14;

                    ;% MPC_linear_P.HILInitialize_OOInitial
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 15;

                    ;% MPC_linear_P.HILInitialize_OOWatchdog
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 18;

                    ;% MPC_linear_P.countstorad1_Gain
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 21;

                    ;% MPC_linear_P.Gain_Gain
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 22;

                    ;% MPC_linear_P.Constant2_Value
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 23;

                    ;% MPC_linear_P.Gain1_Gain
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 24;

                    ;% MPC_linear_P.countstorad_Gain
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 25;

                    ;% MPC_linear_P.Gain_Gain_a
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 26;

                    ;% MPC_linear_P.RateTransition_InitialCondition
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 27;

                    ;% MPC_linear_P.TransferFcn1_A
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 28;

                    ;% MPC_linear_P.TransferFcn1_C
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 29;

                    ;% MPC_linear_P.TransferFcn1_D
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 30;

                    ;% MPC_linear_P.Gain_Gain_h
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 31;

                    ;% MPC_linear_P.DiscreteTimeIntegrator_gainval
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 32;

                    ;% MPC_linear_P.DiscreteTimeIntegrator_IC
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 33;

                    ;% MPC_linear_P.Gain1_Gain_o
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 34;

                    ;% MPC_linear_P.Constant3_Value
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 35;

                    ;% MPC_linear_P.TransferFcn_A
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 36;

                    ;% MPC_linear_P.TransferFcn_C
                    section.data(32).logicalSrcIdx = 37;
                    section.data(32).dtTransOffset = 37;

                    ;% MPC_linear_P.TransferFcn_D
                    section.data(33).logicalSrcIdx = 38;
                    section.data(33).dtTransOffset = 38;

                    ;% MPC_linear_P.SmoothSignalGenerator_InitialPh
                    section.data(34).logicalSrcIdx = 39;
                    section.data(34).dtTransOffset = 39;

                    ;% MPC_linear_P.SmoothSignalGenerator_Amplitude
                    section.data(35).logicalSrcIdx = 40;
                    section.data(35).dtTransOffset = 40;

                    ;% MPC_linear_P.SmoothSignalGenerator_Frequency
                    section.data(36).logicalSrcIdx = 41;
                    section.data(36).dtTransOffset = 41;

                    ;% MPC_linear_P.last_x_InitialCondition
                    section.data(37).logicalSrcIdx = 42;
                    section.data(37).dtTransOffset = 42;

                    ;% MPC_linear_P.last_mv_InitialCondition
                    section.data(38).logicalSrcIdx = 43;
                    section.data(38).dtTransOffset = 49;

                    ;% MPC_linear_P.Constant_Value
                    section.data(39).logicalSrcIdx = 44;
                    section.data(39).dtTransOffset = 50;

                    ;% MPC_linear_P.md_zero_Value
                    section.data(40).logicalSrcIdx = 45;
                    section.data(40).dtTransOffset = 54;

                    ;% MPC_linear_P.umin_zero_Value
                    section.data(41).logicalSrcIdx = 46;
                    section.data(41).dtTransOffset = 55;

                    ;% MPC_linear_P.umax_zero_Value
                    section.data(42).logicalSrcIdx = 47;
                    section.data(42).dtTransOffset = 56;

                    ;% MPC_linear_P.ymin_zero_Value
                    section.data(43).logicalSrcIdx = 48;
                    section.data(43).dtTransOffset = 57;

                    ;% MPC_linear_P.ymax_zero_Value
                    section.data(44).logicalSrcIdx = 49;
                    section.data(44).dtTransOffset = 61;

                    ;% MPC_linear_P.E_zero_Value
                    section.data(45).logicalSrcIdx = 50;
                    section.data(45).dtTransOffset = 65;

                    ;% MPC_linear_P.umin_scale4_Gain
                    section.data(46).logicalSrcIdx = 51;
                    section.data(46).dtTransOffset = 66;

                    ;% MPC_linear_P.F_zero_Value
                    section.data(47).logicalSrcIdx = 52;
                    section.data(47).dtTransOffset = 67;

                    ;% MPC_linear_P.ymin_scale1_Gain
                    section.data(48).logicalSrcIdx = 53;
                    section.data(48).dtTransOffset = 71;

                    ;% MPC_linear_P.G_zero_Value
                    section.data(49).logicalSrcIdx = 54;
                    section.data(49).dtTransOffset = 75;

                    ;% MPC_linear_P.S_zero_Value
                    section.data(50).logicalSrcIdx = 55;
                    section.data(50).dtTransOffset = 76;

                    ;% MPC_linear_P.ymin_scale2_Gain
                    section.data(51).logicalSrcIdx = 56;
                    section.data(51).dtTransOffset = 77;

                    ;% MPC_linear_P.switch_zero_Value
                    section.data(52).logicalSrcIdx = 57;
                    section.data(52).dtTransOffset = 78;

                    ;% MPC_linear_P.extmv_zero_Value
                    section.data(53).logicalSrcIdx = 58;
                    section.data(53).dtTransOffset = 79;

                    ;% MPC_linear_P.extmv_scale_Gain
                    section.data(54).logicalSrcIdx = 59;
                    section.data(54).dtTransOffset = 80;

                    ;% MPC_linear_P.mvtarget_zero_Value
                    section.data(55).logicalSrcIdx = 60;
                    section.data(55).dtTransOffset = 81;

                    ;% MPC_linear_P.extmv_scale1_Gain
                    section.data(56).logicalSrcIdx = 61;
                    section.data(56).dtTransOffset = 82;

                    ;% MPC_linear_P.ywt_zero_Value
                    section.data(57).logicalSrcIdx = 62;
                    section.data(57).dtTransOffset = 83;

                    ;% MPC_linear_P.uwt_zero_Value
                    section.data(58).logicalSrcIdx = 63;
                    section.data(58).dtTransOffset = 87;

                    ;% MPC_linear_P.duwt_zero_Value
                    section.data(59).logicalSrcIdx = 64;
                    section.data(59).dtTransOffset = 88;

                    ;% MPC_linear_P.ecrwt_zero_Value
                    section.data(60).logicalSrcIdx = 65;
                    section.data(60).dtTransOffset = 89;

                    ;% MPC_linear_P.umin_scale1_Gain
                    section.data(61).logicalSrcIdx = 66;
                    section.data(61).dtTransOffset = 90;

                    ;% MPC_linear_P.Saturation_UpperSat
                    section.data(62).logicalSrcIdx = 67;
                    section.data(62).dtTransOffset = 91;

                    ;% MPC_linear_P.Saturation_LowerSat
                    section.data(63).logicalSrcIdx = 68;
                    section.data(63).dtTransOffset = 92;

                    ;% MPC_linear_P.Saturation1_UpperSat
                    section.data(64).logicalSrcIdx = 69;
                    section.data(64).dtTransOffset = 93;

                    ;% MPC_linear_P.Saturation1_LowerSat
                    section.data(65).logicalSrcIdx = 70;
                    section.data(65).dtTransOffset = 94;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% MPC_linear_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 72;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 73;
                    section.data(3).dtTransOffset = 2;

                    ;% MPC_linear_P.HILReadEncoderTimebase_Clock
                    section.data(4).logicalSrcIdx = 74;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% MPC_linear_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 76;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 77;
                    section.data(3).dtTransOffset = 2;

                    ;% MPC_linear_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 78;
                    section.data(4).dtTransOffset = 3;

                    ;% MPC_linear_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 79;
                    section.data(5).dtTransOffset = 5;

                    ;% MPC_linear_P.HILInitialize_OOChannels
                    section.data(6).logicalSrcIdx = 80;
                    section.data(6).dtTransOffset = 6;

                    ;% MPC_linear_P.HILReadEncoderTimebase_Channels
                    section.data(7).logicalSrcIdx = 81;
                    section.data(7).dtTransOffset = 9;

                    ;% MPC_linear_P.HILReadEncoderTimebase_SamplesI
                    section.data(8).logicalSrcIdx = 82;
                    section.data(8).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 40;
            section.data(40)  = dumData; %prealloc

                    ;% MPC_linear_P.Constant_Value_j
                    section.data(1).logicalSrcIdx = 83;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_P.HILInitialize_Active
                    section.data(2).logicalSrcIdx = 84;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_P.HILInitialize_AOTerminate
                    section.data(3).logicalSrcIdx = 85;
                    section.data(3).dtTransOffset = 2;

                    ;% MPC_linear_P.HILInitialize_AOExit
                    section.data(4).logicalSrcIdx = 86;
                    section.data(4).dtTransOffset = 3;

                    ;% MPC_linear_P.HILInitialize_DOTerminate
                    section.data(5).logicalSrcIdx = 87;
                    section.data(5).dtTransOffset = 4;

                    ;% MPC_linear_P.HILInitialize_DOExit
                    section.data(6).logicalSrcIdx = 88;
                    section.data(6).dtTransOffset = 5;

                    ;% MPC_linear_P.HILInitialize_POTerminate
                    section.data(7).logicalSrcIdx = 89;
                    section.data(7).dtTransOffset = 6;

                    ;% MPC_linear_P.HILInitialize_POExit
                    section.data(8).logicalSrcIdx = 90;
                    section.data(8).dtTransOffset = 7;

                    ;% MPC_linear_P.HILInitialize_CKPStart
                    section.data(9).logicalSrcIdx = 91;
                    section.data(9).dtTransOffset = 8;

                    ;% MPC_linear_P.HILInitialize_CKPEnter
                    section.data(10).logicalSrcIdx = 92;
                    section.data(10).dtTransOffset = 9;

                    ;% MPC_linear_P.HILInitialize_CKStart
                    section.data(11).logicalSrcIdx = 93;
                    section.data(11).dtTransOffset = 10;

                    ;% MPC_linear_P.HILInitialize_CKEnter
                    section.data(12).logicalSrcIdx = 94;
                    section.data(12).dtTransOffset = 11;

                    ;% MPC_linear_P.HILInitialize_AIPStart
                    section.data(13).logicalSrcIdx = 95;
                    section.data(13).dtTransOffset = 12;

                    ;% MPC_linear_P.HILInitialize_AIPEnter
                    section.data(14).logicalSrcIdx = 96;
                    section.data(14).dtTransOffset = 13;

                    ;% MPC_linear_P.HILInitialize_AOPStart
                    section.data(15).logicalSrcIdx = 97;
                    section.data(15).dtTransOffset = 14;

                    ;% MPC_linear_P.HILInitialize_AOPEnter
                    section.data(16).logicalSrcIdx = 98;
                    section.data(16).dtTransOffset = 15;

                    ;% MPC_linear_P.HILInitialize_AOStart
                    section.data(17).logicalSrcIdx = 99;
                    section.data(17).dtTransOffset = 16;

                    ;% MPC_linear_P.HILInitialize_AOEnter
                    section.data(18).logicalSrcIdx = 100;
                    section.data(18).dtTransOffset = 17;

                    ;% MPC_linear_P.HILInitialize_AOReset
                    section.data(19).logicalSrcIdx = 101;
                    section.data(19).dtTransOffset = 18;

                    ;% MPC_linear_P.HILInitialize_DOPStart
                    section.data(20).logicalSrcIdx = 102;
                    section.data(20).dtTransOffset = 19;

                    ;% MPC_linear_P.HILInitialize_DOPEnter
                    section.data(21).logicalSrcIdx = 103;
                    section.data(21).dtTransOffset = 20;

                    ;% MPC_linear_P.HILInitialize_DOStart
                    section.data(22).logicalSrcIdx = 104;
                    section.data(22).dtTransOffset = 21;

                    ;% MPC_linear_P.HILInitialize_DOEnter
                    section.data(23).logicalSrcIdx = 105;
                    section.data(23).dtTransOffset = 22;

                    ;% MPC_linear_P.HILInitialize_DOReset
                    section.data(24).logicalSrcIdx = 106;
                    section.data(24).dtTransOffset = 23;

                    ;% MPC_linear_P.HILInitialize_EIPStart
                    section.data(25).logicalSrcIdx = 107;
                    section.data(25).dtTransOffset = 24;

                    ;% MPC_linear_P.HILInitialize_EIPEnter
                    section.data(26).logicalSrcIdx = 108;
                    section.data(26).dtTransOffset = 25;

                    ;% MPC_linear_P.HILInitialize_EIStart
                    section.data(27).logicalSrcIdx = 109;
                    section.data(27).dtTransOffset = 26;

                    ;% MPC_linear_P.HILInitialize_EIEnter
                    section.data(28).logicalSrcIdx = 110;
                    section.data(28).dtTransOffset = 27;

                    ;% MPC_linear_P.HILInitialize_POPStart
                    section.data(29).logicalSrcIdx = 111;
                    section.data(29).dtTransOffset = 28;

                    ;% MPC_linear_P.HILInitialize_POPEnter
                    section.data(30).logicalSrcIdx = 112;
                    section.data(30).dtTransOffset = 29;

                    ;% MPC_linear_P.HILInitialize_POStart
                    section.data(31).logicalSrcIdx = 113;
                    section.data(31).dtTransOffset = 30;

                    ;% MPC_linear_P.HILInitialize_POEnter
                    section.data(32).logicalSrcIdx = 114;
                    section.data(32).dtTransOffset = 31;

                    ;% MPC_linear_P.HILInitialize_POReset
                    section.data(33).logicalSrcIdx = 115;
                    section.data(33).dtTransOffset = 32;

                    ;% MPC_linear_P.HILInitialize_OOReset
                    section.data(34).logicalSrcIdx = 116;
                    section.data(34).dtTransOffset = 33;

                    ;% MPC_linear_P.HILInitialize_DOFinal
                    section.data(35).logicalSrcIdx = 117;
                    section.data(35).dtTransOffset = 34;

                    ;% MPC_linear_P.HILInitialize_DOInitial
                    section.data(36).logicalSrcIdx = 118;
                    section.data(36).dtTransOffset = 35;

                    ;% MPC_linear_P.HILReadEncoderTimebase_Active
                    section.data(37).logicalSrcIdx = 119;
                    section.data(37).dtTransOffset = 36;

                    ;% MPC_linear_P.HILReadEncoder_Active
                    section.data(38).logicalSrcIdx = 120;
                    section.data(38).dtTransOffset = 37;

                    ;% MPC_linear_P.Memory_InitialCondition
                    section.data(39).logicalSrcIdx = 121;
                    section.data(39).dtTransOffset = 38;

                    ;% MPC_linear_P.HILWriteAnalog_Active
                    section.data(40).logicalSrcIdx = 122;
                    section.data(40).dtTransOffset = 62;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% MPC_linear_P.HILReadEncoderTimebase_Overflow
                    section.data(1).logicalSrcIdx = 123;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_P.ManualSwitch_CurrentSetting
                    section.data(2).logicalSrcIdx = 124;
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
        ;% Auto data (MPC_linear_B)
        ;%
            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% MPC_linear_B.countstorad1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_B.Gain
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_B.Gain_f
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% MPC_linear_B.RateTransition
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% MPC_linear_B.Gain_o
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% MPC_linear_B.DataTypeConversion
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% MPC_linear_B.Gain1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% MPC_linear_B.Add1
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 8;

                    ;% MPC_linear_B.VectorConcatenate
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 9;

                    ;% MPC_linear_B.Saturation
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 13;

                    ;% MPC_linear_B.ManualSwitch
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 14;

                    ;% MPC_linear_B.xk1
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 15;

                    ;% MPC_linear_B.u
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 22;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% MPC_linear_B.LogicalOperator1
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_B.RelationalOperator2
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_B.iAout
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 2;

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
        ;% Auto data (MPC_linear_DW)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% MPC_linear_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_DW.last_mv_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_DW.HILInitialize_FilterFrequency
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% MPC_linear_DW.RateTransition_Buffer0
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% MPC_linear_DW.TmpRTBAtoptimizerInport3_Buffer
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% MPC_linear_DW.last_x_PreviousInput
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% MPC_linear_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% MPC_linear_DW.HILReadEncoderTimebase_Task
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% MPC_linear_DW.SmoothSignalGenerator_RWORK.Amp
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% MPC_linear_DW.HILReadEncoder_PWORK
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_DW.PendAngledeg1_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_DW.ServoAngledeg_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 2;

                    ;% MPC_linear_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 12;
                    section.data(4).dtTransOffset = 3;

                    ;% MPC_linear_DW.ToWorkspace3_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 13;
                    section.data(5).dtTransOffset = 4;

                    ;% MPC_linear_DW.ToWorkspace4_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 14;
                    section.data(6).dtTransOffset = 5;

                    ;% MPC_linear_DW.ToWorkspace_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 15;
                    section.data(7).dtTransOffset = 6;

                    ;% MPC_linear_DW.HILWriteAnalog_PWORK
                    section.data(8).logicalSrcIdx = 16;
                    section.data(8).dtTransOffset = 7;

                    ;% MPC_linear_DW.MotorVoltageV_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 17;
                    section.data(9).dtTransOffset = 8;

                    ;% MPC_linear_DW.ToWorkspace1_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 18;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% MPC_linear_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% MPC_linear_DW.HILInitialize_DOStates
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

                    ;% MPC_linear_DW.HILInitialize_QuadratureModes
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 2;

                    ;% MPC_linear_DW.HILInitialize_InitialEICounts
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 4;

                    ;% MPC_linear_DW.HILReadEncoderTimebase_Buffer
                    section.data(5).logicalSrcIdx = 23;
                    section.data(5).dtTransOffset = 6;

                    ;% MPC_linear_DW.HILReadEncoder_Buffer
                    section.data(6).logicalSrcIdx = 24;
                    section.data(6).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% MPC_linear_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% MPC_linear_DW.Memory_PreviousInput
                    section.data(1).logicalSrcIdx = 26;
                    section.data(1).dtTransOffset = 0;

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


    targMap.checksum0 = 4080176400;
    targMap.checksum1 = 273858794;
    targMap.checksum2 = 1174157115;
    targMap.checksum3 = 2427828122;

