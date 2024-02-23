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
        ;% Auto data (Swingup_MPC_P)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Swingup_MPC_P.StallMonitor_control_threshold
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_P.StallMonitor_duration_s
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_P.StallMonitor_motion_threshold
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Swingup_MPC_P.HILReadEncoder_channels
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_P.HILWriteAnalog_channels
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Swingup_MPC_P.StopwithMessage_message_icon
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 59;
            section.data(59)  = dumData; %prealloc

                    ;% Swingup_MPC_P.HILInitialize_OOTerminate
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_P.HILInitialize_OOExit
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_P.HILInitialize_OOStart
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% Swingup_MPC_P.HILInitialize_OOEnter
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% Swingup_MPC_P.HILInitialize_AOFinal
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 4;

                    ;% Swingup_MPC_P.HILInitialize_OOFinal
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 5;

                    ;% Swingup_MPC_P.HILInitialize_AIHigh
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 8;

                    ;% Swingup_MPC_P.HILInitialize_AILow
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 9;

                    ;% Swingup_MPC_P.HILInitialize_AOHigh
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 10;

                    ;% Swingup_MPC_P.HILInitialize_AOLow
                    section.data(10).logicalSrcIdx = 15;
                    section.data(10).dtTransOffset = 11;

                    ;% Swingup_MPC_P.HILInitialize_AOInitial
                    section.data(11).logicalSrcIdx = 16;
                    section.data(11).dtTransOffset = 12;

                    ;% Swingup_MPC_P.HILInitialize_AOWatchdog
                    section.data(12).logicalSrcIdx = 17;
                    section.data(12).dtTransOffset = 13;

                    ;% Swingup_MPC_P.HILInitialize_OOInitial
                    section.data(13).logicalSrcIdx = 18;
                    section.data(13).dtTransOffset = 14;

                    ;% Swingup_MPC_P.HILInitialize_OOWatchdog
                    section.data(14).logicalSrcIdx = 19;
                    section.data(14).dtTransOffset = 17;

                    ;% Swingup_MPC_P.countstorad1_Gain
                    section.data(15).logicalSrcIdx = 20;
                    section.data(15).dtTransOffset = 20;

                    ;% Swingup_MPC_P.Gain_Gain
                    section.data(16).logicalSrcIdx = 21;
                    section.data(16).dtTransOffset = 21;

                    ;% Swingup_MPC_P.Constant2_Value
                    section.data(17).logicalSrcIdx = 22;
                    section.data(17).dtTransOffset = 22;

                    ;% Swingup_MPC_P.Gain1_Gain
                    section.data(18).logicalSrcIdx = 23;
                    section.data(18).dtTransOffset = 23;

                    ;% Swingup_MPC_P.countstorad_Gain
                    section.data(19).logicalSrcIdx = 24;
                    section.data(19).dtTransOffset = 24;

                    ;% Swingup_MPC_P.Gain_Gain_a
                    section.data(20).logicalSrcIdx = 25;
                    section.data(20).dtTransOffset = 25;

                    ;% Swingup_MPC_P.RateTransition_InitialCondition
                    section.data(21).logicalSrcIdx = 26;
                    section.data(21).dtTransOffset = 26;

                    ;% Swingup_MPC_P.TransferFcn1_A
                    section.data(22).logicalSrcIdx = 27;
                    section.data(22).dtTransOffset = 27;

                    ;% Swingup_MPC_P.TransferFcn1_C
                    section.data(23).logicalSrcIdx = 28;
                    section.data(23).dtTransOffset = 28;

                    ;% Swingup_MPC_P.TransferFcn1_D
                    section.data(24).logicalSrcIdx = 29;
                    section.data(24).dtTransOffset = 29;

                    ;% Swingup_MPC_P.Gain_Gain_h
                    section.data(25).logicalSrcIdx = 30;
                    section.data(25).dtTransOffset = 30;

                    ;% Swingup_MPC_P.DiscreteTimeIntegrator_gainval
                    section.data(26).logicalSrcIdx = 31;
                    section.data(26).dtTransOffset = 31;

                    ;% Swingup_MPC_P.DiscreteTimeIntegrator_IC
                    section.data(27).logicalSrcIdx = 32;
                    section.data(27).dtTransOffset = 32;

                    ;% Swingup_MPC_P.Gain1_Gain_o
                    section.data(28).logicalSrcIdx = 33;
                    section.data(28).dtTransOffset = 33;

                    ;% Swingup_MPC_P.Constant3_Value
                    section.data(29).logicalSrcIdx = 34;
                    section.data(29).dtTransOffset = 34;

                    ;% Swingup_MPC_P.TransferFcn_A
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 35;

                    ;% Swingup_MPC_P.TransferFcn_C
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 36;

                    ;% Swingup_MPC_P.TransferFcn_D
                    section.data(32).logicalSrcIdx = 37;
                    section.data(32).dtTransOffset = 37;

                    ;% Swingup_MPC_P.ones_Value
                    section.data(33).logicalSrcIdx = 38;
                    section.data(33).dtTransOffset = 38;

                    ;% Swingup_MPC_P.SmoothSignalGenerator_InitialPh
                    section.data(34).logicalSrcIdx = 39;
                    section.data(34).dtTransOffset = 59;

                    ;% Swingup_MPC_P.SmoothSignalGenerator_Amplitude
                    section.data(35).logicalSrcIdx = 40;
                    section.data(35).dtTransOffset = 60;

                    ;% Swingup_MPC_P.SmoothSignalGenerator_Frequency
                    section.data(36).logicalSrcIdx = 41;
                    section.data(36).dtTransOffset = 61;

                    ;% Swingup_MPC_P.Constant_Value
                    section.data(37).logicalSrcIdx = 42;
                    section.data(37).dtTransOffset = 62;

                    ;% Swingup_MPC_P.Delay_InitialCondition
                    section.data(38).logicalSrcIdx = 43;
                    section.data(38).dtTransOffset = 66;

                    ;% Swingup_MPC_P.md_zero_Value
                    section.data(39).logicalSrcIdx = 44;
                    section.data(39).dtTransOffset = 67;

                    ;% Swingup_MPC_P.mvtarget_zero_Value
                    section.data(40).logicalSrcIdx = 45;
                    section.data(40).dtTransOffset = 68;

                    ;% Swingup_MPC_P.mvmin_zero_Value
                    section.data(41).logicalSrcIdx = 46;
                    section.data(41).dtTransOffset = 69;

                    ;% Swingup_MPC_P.mvmax_zero_Value
                    section.data(42).logicalSrcIdx = 47;
                    section.data(42).dtTransOffset = 70;

                    ;% Swingup_MPC_P.ymin_zero_Value
                    section.data(43).logicalSrcIdx = 48;
                    section.data(43).dtTransOffset = 71;

                    ;% Swingup_MPC_P.ymax_zero_Value
                    section.data(44).logicalSrcIdx = 49;
                    section.data(44).dtTransOffset = 75;

                    ;% Swingup_MPC_P.dmvmin_zero_Value
                    section.data(45).logicalSrcIdx = 50;
                    section.data(45).dtTransOffset = 79;

                    ;% Swingup_MPC_P.dmvmax_zero_Value
                    section.data(46).logicalSrcIdx = 51;
                    section.data(46).dtTransOffset = 80;

                    ;% Swingup_MPC_P.xmin_zero_Value
                    section.data(47).logicalSrcIdx = 52;
                    section.data(47).dtTransOffset = 81;

                    ;% Swingup_MPC_P.xmax_zero_Value
                    section.data(48).logicalSrcIdx = 53;
                    section.data(48).dtTransOffset = 85;

                    ;% Swingup_MPC_P.ywt_zero_Value
                    section.data(49).logicalSrcIdx = 54;
                    section.data(49).dtTransOffset = 89;

                    ;% Swingup_MPC_P.mvwt_zero_Value
                    section.data(50).logicalSrcIdx = 55;
                    section.data(50).dtTransOffset = 93;

                    ;% Swingup_MPC_P.dmvwt_zero_Value
                    section.data(51).logicalSrcIdx = 56;
                    section.data(51).dtTransOffset = 94;

                    ;% Swingup_MPC_P.ecrwt_zero_Value
                    section.data(52).logicalSrcIdx = 57;
                    section.data(52).dtTransOffset = 95;

                    ;% Swingup_MPC_P.params_zero_Value
                    section.data(53).logicalSrcIdx = 58;
                    section.data(53).dtTransOffset = 96;

                    ;% Swingup_MPC_P.Constant1_Value
                    section.data(54).logicalSrcIdx = 59;
                    section.data(54).dtTransOffset = 97;

                    ;% Swingup_MPC_P.Constant_Value_k
                    section.data(55).logicalSrcIdx = 60;
                    section.data(55).dtTransOffset = 116;

                    ;% Swingup_MPC_P.einit_zero_Value
                    section.data(56).logicalSrcIdx = 61;
                    section.data(56).dtTransOffset = 135;

                    ;% Swingup_MPC_P.Gain2_Gain
                    section.data(57).logicalSrcIdx = 62;
                    section.data(57).dtTransOffset = 136;

                    ;% Swingup_MPC_P.Saturation1_UpperSat
                    section.data(58).logicalSrcIdx = 63;
                    section.data(58).dtTransOffset = 137;

                    ;% Swingup_MPC_P.Saturation1_LowerSat
                    section.data(59).logicalSrcIdx = 64;
                    section.data(59).dtTransOffset = 138;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Swingup_MPC_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 65;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 66;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 67;
                    section.data(3).dtTransOffset = 2;

                    ;% Swingup_MPC_P.HILReadEncoderTimebase_Clock
                    section.data(4).logicalSrcIdx = 68;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Swingup_MPC_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 70;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 71;
                    section.data(3).dtTransOffset = 2;

                    ;% Swingup_MPC_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 72;
                    section.data(4).dtTransOffset = 3;

                    ;% Swingup_MPC_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 73;
                    section.data(5).dtTransOffset = 5;

                    ;% Swingup_MPC_P.HILInitialize_OOChannels
                    section.data(6).logicalSrcIdx = 74;
                    section.data(6).dtTransOffset = 6;

                    ;% Swingup_MPC_P.HILReadEncoderTimebase_Channels
                    section.data(7).logicalSrcIdx = 75;
                    section.data(7).dtTransOffset = 9;

                    ;% Swingup_MPC_P.HILReadEncoderTimebase_SamplesI
                    section.data(8).logicalSrcIdx = 76;
                    section.data(8).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 39;
            section.data(39)  = dumData; %prealloc

                    ;% Swingup_MPC_P.Constant_Value_j
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_P.HILInitialize_Active
                    section.data(2).logicalSrcIdx = 78;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_P.HILInitialize_AOTerminate
                    section.data(3).logicalSrcIdx = 79;
                    section.data(3).dtTransOffset = 2;

                    ;% Swingup_MPC_P.HILInitialize_AOExit
                    section.data(4).logicalSrcIdx = 80;
                    section.data(4).dtTransOffset = 3;

                    ;% Swingup_MPC_P.HILInitialize_DOTerminate
                    section.data(5).logicalSrcIdx = 81;
                    section.data(5).dtTransOffset = 4;

                    ;% Swingup_MPC_P.HILInitialize_DOExit
                    section.data(6).logicalSrcIdx = 82;
                    section.data(6).dtTransOffset = 5;

                    ;% Swingup_MPC_P.HILInitialize_POTerminate
                    section.data(7).logicalSrcIdx = 83;
                    section.data(7).dtTransOffset = 6;

                    ;% Swingup_MPC_P.HILInitialize_POExit
                    section.data(8).logicalSrcIdx = 84;
                    section.data(8).dtTransOffset = 7;

                    ;% Swingup_MPC_P.HILInitialize_CKPStart
                    section.data(9).logicalSrcIdx = 85;
                    section.data(9).dtTransOffset = 8;

                    ;% Swingup_MPC_P.HILInitialize_CKPEnter
                    section.data(10).logicalSrcIdx = 86;
                    section.data(10).dtTransOffset = 9;

                    ;% Swingup_MPC_P.HILInitialize_CKStart
                    section.data(11).logicalSrcIdx = 87;
                    section.data(11).dtTransOffset = 10;

                    ;% Swingup_MPC_P.HILInitialize_CKEnter
                    section.data(12).logicalSrcIdx = 88;
                    section.data(12).dtTransOffset = 11;

                    ;% Swingup_MPC_P.HILInitialize_AIPStart
                    section.data(13).logicalSrcIdx = 89;
                    section.data(13).dtTransOffset = 12;

                    ;% Swingup_MPC_P.HILInitialize_AIPEnter
                    section.data(14).logicalSrcIdx = 90;
                    section.data(14).dtTransOffset = 13;

                    ;% Swingup_MPC_P.HILInitialize_AOPStart
                    section.data(15).logicalSrcIdx = 91;
                    section.data(15).dtTransOffset = 14;

                    ;% Swingup_MPC_P.HILInitialize_AOPEnter
                    section.data(16).logicalSrcIdx = 92;
                    section.data(16).dtTransOffset = 15;

                    ;% Swingup_MPC_P.HILInitialize_AOStart
                    section.data(17).logicalSrcIdx = 93;
                    section.data(17).dtTransOffset = 16;

                    ;% Swingup_MPC_P.HILInitialize_AOEnter
                    section.data(18).logicalSrcIdx = 94;
                    section.data(18).dtTransOffset = 17;

                    ;% Swingup_MPC_P.HILInitialize_AOReset
                    section.data(19).logicalSrcIdx = 95;
                    section.data(19).dtTransOffset = 18;

                    ;% Swingup_MPC_P.HILInitialize_DOPStart
                    section.data(20).logicalSrcIdx = 96;
                    section.data(20).dtTransOffset = 19;

                    ;% Swingup_MPC_P.HILInitialize_DOPEnter
                    section.data(21).logicalSrcIdx = 97;
                    section.data(21).dtTransOffset = 20;

                    ;% Swingup_MPC_P.HILInitialize_DOStart
                    section.data(22).logicalSrcIdx = 98;
                    section.data(22).dtTransOffset = 21;

                    ;% Swingup_MPC_P.HILInitialize_DOEnter
                    section.data(23).logicalSrcIdx = 99;
                    section.data(23).dtTransOffset = 22;

                    ;% Swingup_MPC_P.HILInitialize_DOReset
                    section.data(24).logicalSrcIdx = 100;
                    section.data(24).dtTransOffset = 23;

                    ;% Swingup_MPC_P.HILInitialize_EIPStart
                    section.data(25).logicalSrcIdx = 101;
                    section.data(25).dtTransOffset = 24;

                    ;% Swingup_MPC_P.HILInitialize_EIPEnter
                    section.data(26).logicalSrcIdx = 102;
                    section.data(26).dtTransOffset = 25;

                    ;% Swingup_MPC_P.HILInitialize_EIStart
                    section.data(27).logicalSrcIdx = 103;
                    section.data(27).dtTransOffset = 26;

                    ;% Swingup_MPC_P.HILInitialize_EIEnter
                    section.data(28).logicalSrcIdx = 104;
                    section.data(28).dtTransOffset = 27;

                    ;% Swingup_MPC_P.HILInitialize_POPStart
                    section.data(29).logicalSrcIdx = 105;
                    section.data(29).dtTransOffset = 28;

                    ;% Swingup_MPC_P.HILInitialize_POPEnter
                    section.data(30).logicalSrcIdx = 106;
                    section.data(30).dtTransOffset = 29;

                    ;% Swingup_MPC_P.HILInitialize_POStart
                    section.data(31).logicalSrcIdx = 107;
                    section.data(31).dtTransOffset = 30;

                    ;% Swingup_MPC_P.HILInitialize_POEnter
                    section.data(32).logicalSrcIdx = 108;
                    section.data(32).dtTransOffset = 31;

                    ;% Swingup_MPC_P.HILInitialize_POReset
                    section.data(33).logicalSrcIdx = 109;
                    section.data(33).dtTransOffset = 32;

                    ;% Swingup_MPC_P.HILInitialize_OOReset
                    section.data(34).logicalSrcIdx = 110;
                    section.data(34).dtTransOffset = 33;

                    ;% Swingup_MPC_P.HILInitialize_DOFinal
                    section.data(35).logicalSrcIdx = 111;
                    section.data(35).dtTransOffset = 34;

                    ;% Swingup_MPC_P.HILInitialize_DOInitial
                    section.data(36).logicalSrcIdx = 112;
                    section.data(36).dtTransOffset = 35;

                    ;% Swingup_MPC_P.HILReadEncoderTimebase_Active
                    section.data(37).logicalSrcIdx = 113;
                    section.data(37).dtTransOffset = 36;

                    ;% Swingup_MPC_P.HILReadEncoder_Active
                    section.data(38).logicalSrcIdx = 114;
                    section.data(38).dtTransOffset = 37;

                    ;% Swingup_MPC_P.HILWriteAnalog_Active
                    section.data(39).logicalSrcIdx = 115;
                    section.data(39).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Swingup_MPC_P.HILReadEncoderTimebase_Overflow
                    section.data(1).logicalSrcIdx = 116;
                    section.data(1).dtTransOffset = 0;

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
        ;% Auto data (Swingup_MPC_B)
        ;%
            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% Swingup_MPC_B.countstorad1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_B.Gain
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_B.Gain_f
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Swingup_MPC_B.RateTransition
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% Swingup_MPC_B.Gain_o
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% Swingup_MPC_B.DataTypeConversion
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% Swingup_MPC_B.Gain1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% Swingup_MPC_B.Add1
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 8;

                    ;% Swingup_MPC_B.VectorConcatenate
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 9;

                    ;% Swingup_MPC_B.Product1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 13;

                    ;% Swingup_MPC_B.Gain2
                    section.data(11).logicalSrcIdx = 12;
                    section.data(11).dtTransOffset = 97;

                    ;% Swingup_MPC_B.mv
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 98;

                    ;% Swingup_MPC_B.mvseq
                    section.data(13).logicalSrcIdx = 14;
                    section.data(13).dtTransOffset = 99;

                    ;% Swingup_MPC_B.xseq
                    section.data(14).logicalSrcIdx = 15;
                    section.data(14).dtTransOffset = 120;

                    ;% Swingup_MPC_B.e
                    section.data(15).logicalSrcIdx = 16;
                    section.data(15).dtTransOffset = 204;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Swingup_MPC_B.LogicalOperator1
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_B.RelationalOperator2
                    section.data(2).logicalSrcIdx = 18;
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
        ;% Auto data (Swingup_MPC_DW)
        ;%
            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% Swingup_MPC_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_DW.Delay_DSTATE
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_DW.mv_Delay_DSTATE
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Swingup_MPC_DW.x_Delay_DSTATE
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 23;

                    ;% Swingup_MPC_DW.slack_delay_DSTATE
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 107;

                    ;% Swingup_MPC_DW.HILInitialize_FilterFrequency
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 108;

                    ;% Swingup_MPC_DW.RateTransition_Buffer0
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 110;

                    ;% Swingup_MPC_DW.TmpRTBAtNLMPCInport1_Buffer
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 111;

                    ;% Swingup_MPC_DW.TmpRTBAtProductInport1_Buffer0
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 115;

                    ;% Swingup_MPC_DW.TmpRTBAtx_DelayInport2_Buffer
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 136;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Swingup_MPC_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Swingup_MPC_DW.HILReadEncoderTimebase_Task
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Swingup_MPC_DW.SmoothSignalGenerator_RWORK.Amp
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Swingup_MPC_DW.HILReadEncoder_PWORK
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_DW.PendAngledeg1_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_DW.ServoAngledeg_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 2;

                    ;% Swingup_MPC_DW.ToWorkspace2_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 16;
                    section.data(4).dtTransOffset = 3;

                    ;% Swingup_MPC_DW.ToWorkspace3_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 17;
                    section.data(5).dtTransOffset = 4;

                    ;% Swingup_MPC_DW.ToWorkspace4_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 18;
                    section.data(6).dtTransOffset = 5;

                    ;% Swingup_MPC_DW.HILWriteAnalog_PWORK
                    section.data(7).logicalSrcIdx = 19;
                    section.data(7).dtTransOffset = 6;

                    ;% Swingup_MPC_DW.MotorVoltageV_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 20;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Swingup_MPC_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_DW.HILInitialize_DOStates
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_DW.HILInitialize_QuadratureModes
                    section.data(3).logicalSrcIdx = 23;
                    section.data(3).dtTransOffset = 2;

                    ;% Swingup_MPC_DW.HILInitialize_InitialEICounts
                    section.data(4).logicalSrcIdx = 24;
                    section.data(4).dtTransOffset = 4;

                    ;% Swingup_MPC_DW.HILReadEncoderTimebase_Buffer
                    section.data(5).logicalSrcIdx = 25;
                    section.data(5).dtTransOffset = 6;

                    ;% Swingup_MPC_DW.HILReadEncoder_Buffer
                    section.data(6).logicalSrcIdx = 26;
                    section.data(6).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Swingup_MPC_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_DW.TmpRTBAtProductInport1_semaphor
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Swingup_MPC_DW.icLoad
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

                    ;% Swingup_MPC_DW.icLoad_l
                    section.data(2).logicalSrcIdx = 30;
                    section.data(2).dtTransOffset = 1;

                    ;% Swingup_MPC_DW.icLoad_n
                    section.data(3).logicalSrcIdx = 31;
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


    targMap.checksum0 = 2741594534;
    targMap.checksum1 = 3964561287;
    targMap.checksum2 = 3980242749;
    targMap.checksum3 = 3046116706;

