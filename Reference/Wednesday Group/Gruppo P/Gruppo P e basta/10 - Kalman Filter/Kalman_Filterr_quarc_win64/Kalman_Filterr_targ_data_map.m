    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
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
        ;% Auto data (Kalman_Filterr_P)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Kalman_Filterr_P.K
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_P.Kw
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 4;

                    ;% Kalman_Filterr_P.Q
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 5;

                    ;% Kalman_Filterr_P.R
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% Kalman_Filterr_P.Ts
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% Kalman_Filterr_P.EnableBalanceControl_const
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% Kalman_Filterr_P.MeasurmentNoise_seed
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% Kalman_Filterr_P.Loaddisturbances_seed
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Filterr_P.HILWriteAnalog_channels
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 47;
            section.data(47)  = dumData; %prealloc

                    ;% Kalman_Filterr_P.Lykyhatkk1_Y0
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_P.HILInitialize_OOTerminate
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Filterr_P.HILInitialize_OOExit
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Filterr_P.HILInitialize_OOStart
                    section.data(4).logicalSrcIdx = 12;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Filterr_P.HILInitialize_OOEnter
                    section.data(5).logicalSrcIdx = 13;
                    section.data(5).dtTransOffset = 4;

                    ;% Kalman_Filterr_P.HILInitialize_AOFinal
                    section.data(6).logicalSrcIdx = 14;
                    section.data(6).dtTransOffset = 5;

                    ;% Kalman_Filterr_P.HILInitialize_OOFinal
                    section.data(7).logicalSrcIdx = 15;
                    section.data(7).dtTransOffset = 6;

                    ;% Kalman_Filterr_P.HILInitialize_AIHigh
                    section.data(8).logicalSrcIdx = 16;
                    section.data(8).dtTransOffset = 9;

                    ;% Kalman_Filterr_P.HILInitialize_AILow
                    section.data(9).logicalSrcIdx = 17;
                    section.data(9).dtTransOffset = 10;

                    ;% Kalman_Filterr_P.HILInitialize_AOHigh
                    section.data(10).logicalSrcIdx = 18;
                    section.data(10).dtTransOffset = 11;

                    ;% Kalman_Filterr_P.HILInitialize_AOLow
                    section.data(11).logicalSrcIdx = 19;
                    section.data(11).dtTransOffset = 12;

                    ;% Kalman_Filterr_P.HILInitialize_AOInitial
                    section.data(12).logicalSrcIdx = 20;
                    section.data(12).dtTransOffset = 13;

                    ;% Kalman_Filterr_P.HILInitialize_AOWatchdog
                    section.data(13).logicalSrcIdx = 21;
                    section.data(13).dtTransOffset = 14;

                    ;% Kalman_Filterr_P.HILInitialize_OOInitial
                    section.data(14).logicalSrcIdx = 22;
                    section.data(14).dtTransOffset = 15;

                    ;% Kalman_Filterr_P.HILInitialize_OOWatchdog
                    section.data(15).logicalSrcIdx = 23;
                    section.data(15).dtTransOffset = 18;

                    ;% Kalman_Filterr_P.SignalGenerator_Amplitude
                    section.data(16).logicalSrcIdx = 24;
                    section.data(16).dtTransOffset = 21;

                    ;% Kalman_Filterr_P.SignalGenerator_Frequency
                    section.data(17).logicalSrcIdx = 25;
                    section.data(17).dtTransOffset = 22;

                    ;% Kalman_Filterr_P.Gain_Gain
                    section.data(18).logicalSrcIdx = 26;
                    section.data(18).dtTransOffset = 23;

                    ;% Kalman_Filterr_P.Gain1_Gain
                    section.data(19).logicalSrcIdx = 27;
                    section.data(19).dtTransOffset = 24;

                    ;% Kalman_Filterr_P.Armcountstorad_Gain
                    section.data(20).logicalSrcIdx = 28;
                    section.data(20).dtTransOffset = 25;

                    ;% Kalman_Filterr_P.Gain_Gain_a
                    section.data(21).logicalSrcIdx = 29;
                    section.data(21).dtTransOffset = 26;

                    ;% Kalman_Filterr_P.Pendulumcountstorad_Gain
                    section.data(22).logicalSrcIdx = 30;
                    section.data(22).dtTransOffset = 27;

                    ;% Kalman_Filterr_P.Constant1_Value
                    section.data(23).logicalSrcIdx = 31;
                    section.data(23).dtTransOffset = 28;

                    ;% Kalman_Filterr_P.Bias_Bias
                    section.data(24).logicalSrcIdx = 32;
                    section.data(24).dtTransOffset = 29;

                    ;% Kalman_Filterr_P.X0_Value
                    section.data(25).logicalSrcIdx = 33;
                    section.data(25).dtTransOffset = 30;

                    ;% Kalman_Filterr_P.WhiteNoise_Mean
                    section.data(26).logicalSrcIdx = 34;
                    section.data(26).dtTransOffset = 34;

                    ;% Kalman_Filterr_P.WhiteNoise_StdDev
                    section.data(27).logicalSrcIdx = 35;
                    section.data(27).dtTransOffset = 35;

                    ;% Kalman_Filterr_P.Gain1_Gain_j
                    section.data(28).logicalSrcIdx = 36;
                    section.data(28).dtTransOffset = 36;

                    ;% Kalman_Filterr_P.Gain_Gain_ar
                    section.data(29).logicalSrcIdx = 37;
                    section.data(29).dtTransOffset = 38;

                    ;% Kalman_Filterr_P.u0V_Value
                    section.data(30).logicalSrcIdx = 38;
                    section.data(30).dtTransOffset = 39;

                    ;% Kalman_Filterr_P.ConverttoVector_Gain
                    section.data(31).logicalSrcIdx = 39;
                    section.data(31).dtTransOffset = 40;

                    ;% Kalman_Filterr_P.TmpRTBAtSum3Inport2_InitialCond
                    section.data(32).logicalSrcIdx = 40;
                    section.data(32).dtTransOffset = 44;

                    ;% Kalman_Filterr_P.A_Value
                    section.data(33).logicalSrcIdx = 41;
                    section.data(33).dtTransOffset = 45;

                    ;% Kalman_Filterr_P.B_Value
                    section.data(34).logicalSrcIdx = 42;
                    section.data(34).dtTransOffset = 61;

                    ;% Kalman_Filterr_P.C_Value
                    section.data(35).logicalSrcIdx = 43;
                    section.data(35).dtTransOffset = 65;

                    ;% Kalman_Filterr_P.CovarianceZ_Value
                    section.data(36).logicalSrcIdx = 44;
                    section.data(36).dtTransOffset = 73;

                    ;% Kalman_Filterr_P.KalmanGainL_Value
                    section.data(37).logicalSrcIdx = 45;
                    section.data(37).dtTransOffset = 89;

                    ;% Kalman_Filterr_P.D_Value
                    section.data(38).logicalSrcIdx = 46;
                    section.data(38).dtTransOffset = 97;

                    ;% Kalman_Filterr_P.alpha_dot_A
                    section.data(39).logicalSrcIdx = 47;
                    section.data(39).dtTransOffset = 99;

                    ;% Kalman_Filterr_P.alpha_dot_C
                    section.data(40).logicalSrcIdx = 48;
                    section.data(40).dtTransOffset = 100;

                    ;% Kalman_Filterr_P.alpha_dot_D
                    section.data(41).logicalSrcIdx = 49;
                    section.data(41).dtTransOffset = 101;

                    ;% Kalman_Filterr_P.theta_dot_A
                    section.data(42).logicalSrcIdx = 50;
                    section.data(42).dtTransOffset = 102;

                    ;% Kalman_Filterr_P.theta_dot_C
                    section.data(43).logicalSrcIdx = 51;
                    section.data(43).dtTransOffset = 103;

                    ;% Kalman_Filterr_P.theta_dot_D
                    section.data(44).logicalSrcIdx = 52;
                    section.data(44).dtTransOffset = 104;

                    ;% Kalman_Filterr_P.ForveCCW_Gain
                    section.data(45).logicalSrcIdx = 53;
                    section.data(45).dtTransOffset = 105;

                    ;% Kalman_Filterr_P.WhiteNoise_Mean_b
                    section.data(46).logicalSrcIdx = 54;
                    section.data(46).dtTransOffset = 106;

                    ;% Kalman_Filterr_P.WhiteNoise_StdDev_g
                    section.data(47).logicalSrcIdx = 55;
                    section.data(47).dtTransOffset = 107;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Kalman_Filterr_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 56;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 57;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Filterr_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 58;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Filterr_P.HILReadEncoderTimebase_Clock
                    section.data(4).logicalSrcIdx = 59;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Kalman_Filterr_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 60;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 61;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Filterr_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 62;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Filterr_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 63;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Filterr_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 64;
                    section.data(5).dtTransOffset = 5;

                    ;% Kalman_Filterr_P.HILInitialize_OOChannels
                    section.data(6).logicalSrcIdx = 65;
                    section.data(6).dtTransOffset = 6;

                    ;% Kalman_Filterr_P.HILReadEncoderTimebase_Channels
                    section.data(7).logicalSrcIdx = 66;
                    section.data(7).dtTransOffset = 9;

                    ;% Kalman_Filterr_P.HILReadEncoderTimebase_SamplesI
                    section.data(8).logicalSrcIdx = 67;
                    section.data(8).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 39;
            section.data(39)  = dumData; %prealloc

                    ;% Kalman_Filterr_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 68;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 69;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Filterr_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 70;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Filterr_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 71;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Filterr_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 72;
                    section.data(5).dtTransOffset = 4;

                    ;% Kalman_Filterr_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 73;
                    section.data(6).dtTransOffset = 5;

                    ;% Kalman_Filterr_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 74;
                    section.data(7).dtTransOffset = 6;

                    ;% Kalman_Filterr_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 75;
                    section.data(8).dtTransOffset = 7;

                    ;% Kalman_Filterr_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 76;
                    section.data(9).dtTransOffset = 8;

                    ;% Kalman_Filterr_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 77;
                    section.data(10).dtTransOffset = 9;

                    ;% Kalman_Filterr_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 78;
                    section.data(11).dtTransOffset = 10;

                    ;% Kalman_Filterr_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 79;
                    section.data(12).dtTransOffset = 11;

                    ;% Kalman_Filterr_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 80;
                    section.data(13).dtTransOffset = 12;

                    ;% Kalman_Filterr_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 81;
                    section.data(14).dtTransOffset = 13;

                    ;% Kalman_Filterr_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 82;
                    section.data(15).dtTransOffset = 14;

                    ;% Kalman_Filterr_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 83;
                    section.data(16).dtTransOffset = 15;

                    ;% Kalman_Filterr_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 84;
                    section.data(17).dtTransOffset = 16;

                    ;% Kalman_Filterr_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 85;
                    section.data(18).dtTransOffset = 17;

                    ;% Kalman_Filterr_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 86;
                    section.data(19).dtTransOffset = 18;

                    ;% Kalman_Filterr_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 87;
                    section.data(20).dtTransOffset = 19;

                    ;% Kalman_Filterr_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 88;
                    section.data(21).dtTransOffset = 20;

                    ;% Kalman_Filterr_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 89;
                    section.data(22).dtTransOffset = 21;

                    ;% Kalman_Filterr_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 90;
                    section.data(23).dtTransOffset = 22;

                    ;% Kalman_Filterr_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 91;
                    section.data(24).dtTransOffset = 23;

                    ;% Kalman_Filterr_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 92;
                    section.data(25).dtTransOffset = 24;

                    ;% Kalman_Filterr_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 93;
                    section.data(26).dtTransOffset = 25;

                    ;% Kalman_Filterr_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 94;
                    section.data(27).dtTransOffset = 26;

                    ;% Kalman_Filterr_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 95;
                    section.data(28).dtTransOffset = 27;

                    ;% Kalman_Filterr_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 96;
                    section.data(29).dtTransOffset = 28;

                    ;% Kalman_Filterr_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 97;
                    section.data(30).dtTransOffset = 29;

                    ;% Kalman_Filterr_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 98;
                    section.data(31).dtTransOffset = 30;

                    ;% Kalman_Filterr_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 99;
                    section.data(32).dtTransOffset = 31;

                    ;% Kalman_Filterr_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 100;
                    section.data(33).dtTransOffset = 32;

                    ;% Kalman_Filterr_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 101;
                    section.data(34).dtTransOffset = 33;

                    ;% Kalman_Filterr_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 102;
                    section.data(35).dtTransOffset = 34;

                    ;% Kalman_Filterr_P.HILReadEncoderTimebase_Active
                    section.data(36).logicalSrcIdx = 103;
                    section.data(36).dtTransOffset = 35;

                    ;% Kalman_Filterr_P.isSqrtUsed_Value
                    section.data(37).logicalSrcIdx = 104;
                    section.data(37).dtTransOffset = 36;

                    ;% Kalman_Filterr_P.Enable_Value
                    section.data(38).logicalSrcIdx = 105;
                    section.data(38).dtTransOffset = 37;

                    ;% Kalman_Filterr_P.HILWriteAnalog_Active
                    section.data(39).logicalSrcIdx = 106;
                    section.data(39).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Filterr_P.HILReadEncoderTimebase_Overflow
                    section.data(1).logicalSrcIdx = 107;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
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
        ;% Auto data (Kalman_Filterr_B)
        ;%
            section.nData     = 40;
            section.data(40)  = dumData; %prealloc

                    ;% Kalman_Filterr_B.HILReadEncoderTimebase_o1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_B.HILReadEncoderTimebase_o2
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Filterr_B.SignalGenerator
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Filterr_B.Gain
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Filterr_B.Gain1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Kalman_Filterr_B.Armcountstorad
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% Kalman_Filterr_B.Gain_b
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% Kalman_Filterr_B.Pendulumcountstorad
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 8;

                    ;% Kalman_Filterr_B.MathFunction
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 9;

                    ;% Kalman_Filterr_B.Bias
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 10;

                    ;% Kalman_Filterr_B.X0
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 11;

                    ;% Kalman_Filterr_B.MemoryX
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 15;

                    ;% Kalman_Filterr_B.Reshapexhat
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 19;

                    ;% Kalman_Filterr_B.WhiteNoise
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 23;

                    ;% Kalman_Filterr_B.Output
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 24;

                    ;% Kalman_Filterr_B.Gain1_a
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 25;

                    ;% Kalman_Filterr_B.Sum2
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 27;

                    ;% Kalman_Filterr_B.Gain_i
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 29;

                    ;% Kalman_Filterr_B.alpha
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 30;

                    ;% Kalman_Filterr_B.ConverttoVector
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 31;

                    ;% Kalman_Filterr_B.Sum
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 35;

                    ;% Kalman_Filterr_B.uKx
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 39;

                    ;% Kalman_Filterr_B.TmpRTBAtSum3Inport2
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 40;

                    ;% Kalman_Filterr_B.EnableBalanceControlSwitch
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 41;

                    ;% Kalman_Filterr_B.Akxhatkk1
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 42;

                    ;% Kalman_Filterr_B.Bkuk
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 46;

                    ;% Kalman_Filterr_B.Add
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 50;

                    ;% Kalman_Filterr_B.alpha_dot
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 54;

                    ;% Kalman_Filterr_B.theta_dot
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 55;

                    ;% Kalman_Filterr_B.ForveCCW
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 56;

                    ;% Kalman_Filterr_B.WhiteNoise_l
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 57;

                    ;% Kalman_Filterr_B.Output_l
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 58;

                    ;% Kalman_Filterr_B.Gain3
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 59;

                    ;% Kalman_Filterr_B.Sum3
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 60;

                    ;% Kalman_Filterr_B.Ckxhatkk1
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 61;

                    ;% Kalman_Filterr_B.Dkuk
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 63;

                    ;% Kalman_Filterr_B.yhatkk1
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 65;

                    ;% Kalman_Filterr_B.Sum_j
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 67;

                    ;% Kalman_Filterr_B.Product3
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 69;

                    ;% Kalman_Filterr_B.P
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 73;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Filterr_B.Compare
                    section.data(1).logicalSrcIdx = 40;
                    section.data(1).dtTransOffset = 0;

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
        nTotSects     = 9;
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
        ;% Auto data (Kalman_Filterr_DW)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Kalman_Filterr_DW.HILInitialize_FilterFrequency
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_DW.NextOutput
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% Kalman_Filterr_DW.TmpRTBAtSum3Inport2_Buffer0
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% Kalman_Filterr_DW.NextOutput_m
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Filterr_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Filterr_DW.HILReadEncoderTimebase_Task
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% Kalman_Filterr_DW.Thetadeg_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_DW.Alfa_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Filterr_DW.Alfadeg_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Filterr_DW.Scope_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% Kalman_Filterr_DW.Scope2_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 4;

                    ;% Kalman_Filterr_DW.Theta_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 5;

                    ;% Kalman_Filterr_DW.VmV_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 6;

                    ;% Kalman_Filterr_DW.HILWriteAnalog_PWORK
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 7;

                    ;% Kalman_Filterr_DW.Scope3_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Kalman_Filterr_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_DW.HILInitialize_DOStates
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% Kalman_Filterr_DW.HILInitialize_QuadratureModes
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

                    ;% Kalman_Filterr_DW.HILInitialize_InitialEICounts
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 4;

                    ;% Kalman_Filterr_DW.HILReadEncoderTimebase_Buffer
                    section.data(5).logicalSrcIdx = 19;
                    section.data(5).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Kalman_Filterr_DW.RandSeed
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% Kalman_Filterr_DW.RandSeed_a
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Filterr_DW.MemoryX_IWORK
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Filterr_DW.MeasurementUpdate_SubsysRanBC
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Kalman_Filterr_DW.MeasurementUpdate_MODE
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
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


    targMap.checksum0 = 236425795;
    targMap.checksum1 = 1288574271;
    targMap.checksum2 = 3103587852;
    targMap.checksum3 = 15773901;

