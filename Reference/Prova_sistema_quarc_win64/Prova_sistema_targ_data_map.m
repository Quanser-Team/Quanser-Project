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
        ;% Auto data (Prova_sistema_P)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Prova_sistema_P.K
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_P.StallMonitor_control_threshold
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 4;

                    ;% Prova_sistema_P.StallMonitor_duration_s
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 5;

                    ;% Prova_sistema_P.StallMonitor_motion_threshold
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Prova_sistema_P.HILReadEncoder_channels
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_P.HILWriteAnalog_channels
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Prova_sistema_P.StopwithMessage_message_icon
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 32;
            section.data(32)  = dumData; %prealloc

                    ;% Prova_sistema_P.HILInitialize_OOTerminate
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_P.HILInitialize_OOExit
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

                    ;% Prova_sistema_P.HILInitialize_OOStart
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 2;

                    ;% Prova_sistema_P.HILInitialize_OOEnter
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 3;

                    ;% Prova_sistema_P.HILInitialize_AOFinal
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 4;

                    ;% Prova_sistema_P.HILInitialize_OOFinal
                    section.data(6).logicalSrcIdx = 12;
                    section.data(6).dtTransOffset = 5;

                    ;% Prova_sistema_P.HILInitialize_AIHigh
                    section.data(7).logicalSrcIdx = 13;
                    section.data(7).dtTransOffset = 8;

                    ;% Prova_sistema_P.HILInitialize_AILow
                    section.data(8).logicalSrcIdx = 14;
                    section.data(8).dtTransOffset = 9;

                    ;% Prova_sistema_P.HILInitialize_AOHigh
                    section.data(9).logicalSrcIdx = 15;
                    section.data(9).dtTransOffset = 10;

                    ;% Prova_sistema_P.HILInitialize_AOLow
                    section.data(10).logicalSrcIdx = 16;
                    section.data(10).dtTransOffset = 11;

                    ;% Prova_sistema_P.HILInitialize_AOInitial
                    section.data(11).logicalSrcIdx = 17;
                    section.data(11).dtTransOffset = 12;

                    ;% Prova_sistema_P.HILInitialize_AOWatchdog
                    section.data(12).logicalSrcIdx = 18;
                    section.data(12).dtTransOffset = 13;

                    ;% Prova_sistema_P.HILInitialize_OOInitial
                    section.data(13).logicalSrcIdx = 19;
                    section.data(13).dtTransOffset = 14;

                    ;% Prova_sistema_P.HILInitialize_OOWatchdog
                    section.data(14).logicalSrcIdx = 20;
                    section.data(14).dtTransOffset = 17;

                    ;% Prova_sistema_P.countstorad1_Gain
                    section.data(15).logicalSrcIdx = 21;
                    section.data(15).dtTransOffset = 20;

                    ;% Prova_sistema_P.countstorad_Gain
                    section.data(16).logicalSrcIdx = 22;
                    section.data(16).dtTransOffset = 21;

                    ;% Prova_sistema_P.ServoVelocity_A
                    section.data(17).logicalSrcIdx = 23;
                    section.data(17).dtTransOffset = 22;

                    ;% Prova_sistema_P.ServoVelocity_C
                    section.data(18).logicalSrcIdx = 24;
                    section.data(18).dtTransOffset = 23;

                    ;% Prova_sistema_P.ServoVelocity_D
                    section.data(19).logicalSrcIdx = 25;
                    section.data(19).dtTransOffset = 24;

                    ;% Prova_sistema_P.ServoVelocity1_A
                    section.data(20).logicalSrcIdx = 26;
                    section.data(20).dtTransOffset = 25;

                    ;% Prova_sistema_P.ServoVelocity1_C
                    section.data(21).logicalSrcIdx = 27;
                    section.data(21).dtTransOffset = 26;

                    ;% Prova_sistema_P.ServoVelocity1_D
                    section.data(22).logicalSrcIdx = 28;
                    section.data(22).dtTransOffset = 27;

                    ;% Prova_sistema_P.Gain_Gain
                    section.data(23).logicalSrcIdx = 29;
                    section.data(23).dtTransOffset = 28;

                    ;% Prova_sistema_P._Gain
                    section.data(24).logicalSrcIdx = 30;
                    section.data(24).dtTransOffset = 29;

                    ;% Prova_sistema_P.DiscreteTimeIntegrator_gainval
                    section.data(25).logicalSrcIdx = 31;
                    section.data(25).dtTransOffset = 30;

                    ;% Prova_sistema_P.DiscreteTimeIntegrator_IC
                    section.data(26).logicalSrcIdx = 32;
                    section.data(26).dtTransOffset = 31;

                    ;% Prova_sistema_P.SmoothSignalGenerator_InitialPh
                    section.data(27).logicalSrcIdx = 33;
                    section.data(27).dtTransOffset = 32;

                    ;% Prova_sistema_P.SmoothSignalGenerator_Amplitude
                    section.data(28).logicalSrcIdx = 34;
                    section.data(28).dtTransOffset = 33;

                    ;% Prova_sistema_P.SmoothSignalGenerator_Frequency
                    section.data(29).logicalSrcIdx = 35;
                    section.data(29).dtTransOffset = 34;

                    ;% Prova_sistema_P.Amplitudedeg_Gain
                    section.data(30).logicalSrcIdx = 36;
                    section.data(30).dtTransOffset = 35;

                    ;% Prova_sistema_P.Gain1_Gain
                    section.data(31).logicalSrcIdx = 37;
                    section.data(31).dtTransOffset = 36;

                    ;% Prova_sistema_P.Gain_Gain_a
                    section.data(32).logicalSrcIdx = 38;
                    section.data(32).dtTransOffset = 37;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Prova_sistema_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 40;
                    section.data(2).dtTransOffset = 1;

                    ;% Prova_sistema_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 41;
                    section.data(3).dtTransOffset = 2;

                    ;% Prova_sistema_P.HILReadEncoderTimebase_Clock
                    section.data(4).logicalSrcIdx = 42;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Prova_sistema_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 44;
                    section.data(2).dtTransOffset = 1;

                    ;% Prova_sistema_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 45;
                    section.data(3).dtTransOffset = 2;

                    ;% Prova_sistema_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 46;
                    section.data(4).dtTransOffset = 3;

                    ;% Prova_sistema_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 47;
                    section.data(5).dtTransOffset = 5;

                    ;% Prova_sistema_P.HILInitialize_OOChannels
                    section.data(6).logicalSrcIdx = 48;
                    section.data(6).dtTransOffset = 6;

                    ;% Prova_sistema_P.HILReadEncoderTimebase_Channels
                    section.data(7).logicalSrcIdx = 49;
                    section.data(7).dtTransOffset = 9;

                    ;% Prova_sistema_P.HILReadEncoderTimebase_SamplesI
                    section.data(8).logicalSrcIdx = 50;
                    section.data(8).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 39;
            section.data(39)  = dumData; %prealloc

                    ;% Prova_sistema_P.Constant_Value
                    section.data(1).logicalSrcIdx = 51;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_P.HILInitialize_Active
                    section.data(2).logicalSrcIdx = 52;
                    section.data(2).dtTransOffset = 1;

                    ;% Prova_sistema_P.HILInitialize_AOTerminate
                    section.data(3).logicalSrcIdx = 53;
                    section.data(3).dtTransOffset = 2;

                    ;% Prova_sistema_P.HILInitialize_AOExit
                    section.data(4).logicalSrcIdx = 54;
                    section.data(4).dtTransOffset = 3;

                    ;% Prova_sistema_P.HILInitialize_DOTerminate
                    section.data(5).logicalSrcIdx = 55;
                    section.data(5).dtTransOffset = 4;

                    ;% Prova_sistema_P.HILInitialize_DOExit
                    section.data(6).logicalSrcIdx = 56;
                    section.data(6).dtTransOffset = 5;

                    ;% Prova_sistema_P.HILInitialize_POTerminate
                    section.data(7).logicalSrcIdx = 57;
                    section.data(7).dtTransOffset = 6;

                    ;% Prova_sistema_P.HILInitialize_POExit
                    section.data(8).logicalSrcIdx = 58;
                    section.data(8).dtTransOffset = 7;

                    ;% Prova_sistema_P.HILInitialize_CKPStart
                    section.data(9).logicalSrcIdx = 59;
                    section.data(9).dtTransOffset = 8;

                    ;% Prova_sistema_P.HILInitialize_CKPEnter
                    section.data(10).logicalSrcIdx = 60;
                    section.data(10).dtTransOffset = 9;

                    ;% Prova_sistema_P.HILInitialize_CKStart
                    section.data(11).logicalSrcIdx = 61;
                    section.data(11).dtTransOffset = 10;

                    ;% Prova_sistema_P.HILInitialize_CKEnter
                    section.data(12).logicalSrcIdx = 62;
                    section.data(12).dtTransOffset = 11;

                    ;% Prova_sistema_P.HILInitialize_AIPStart
                    section.data(13).logicalSrcIdx = 63;
                    section.data(13).dtTransOffset = 12;

                    ;% Prova_sistema_P.HILInitialize_AIPEnter
                    section.data(14).logicalSrcIdx = 64;
                    section.data(14).dtTransOffset = 13;

                    ;% Prova_sistema_P.HILInitialize_AOPStart
                    section.data(15).logicalSrcIdx = 65;
                    section.data(15).dtTransOffset = 14;

                    ;% Prova_sistema_P.HILInitialize_AOPEnter
                    section.data(16).logicalSrcIdx = 66;
                    section.data(16).dtTransOffset = 15;

                    ;% Prova_sistema_P.HILInitialize_AOStart
                    section.data(17).logicalSrcIdx = 67;
                    section.data(17).dtTransOffset = 16;

                    ;% Prova_sistema_P.HILInitialize_AOEnter
                    section.data(18).logicalSrcIdx = 68;
                    section.data(18).dtTransOffset = 17;

                    ;% Prova_sistema_P.HILInitialize_AOReset
                    section.data(19).logicalSrcIdx = 69;
                    section.data(19).dtTransOffset = 18;

                    ;% Prova_sistema_P.HILInitialize_DOPStart
                    section.data(20).logicalSrcIdx = 70;
                    section.data(20).dtTransOffset = 19;

                    ;% Prova_sistema_P.HILInitialize_DOPEnter
                    section.data(21).logicalSrcIdx = 71;
                    section.data(21).dtTransOffset = 20;

                    ;% Prova_sistema_P.HILInitialize_DOStart
                    section.data(22).logicalSrcIdx = 72;
                    section.data(22).dtTransOffset = 21;

                    ;% Prova_sistema_P.HILInitialize_DOEnter
                    section.data(23).logicalSrcIdx = 73;
                    section.data(23).dtTransOffset = 22;

                    ;% Prova_sistema_P.HILInitialize_DOReset
                    section.data(24).logicalSrcIdx = 74;
                    section.data(24).dtTransOffset = 23;

                    ;% Prova_sistema_P.HILInitialize_EIPStart
                    section.data(25).logicalSrcIdx = 75;
                    section.data(25).dtTransOffset = 24;

                    ;% Prova_sistema_P.HILInitialize_EIPEnter
                    section.data(26).logicalSrcIdx = 76;
                    section.data(26).dtTransOffset = 25;

                    ;% Prova_sistema_P.HILInitialize_EIStart
                    section.data(27).logicalSrcIdx = 77;
                    section.data(27).dtTransOffset = 26;

                    ;% Prova_sistema_P.HILInitialize_EIEnter
                    section.data(28).logicalSrcIdx = 78;
                    section.data(28).dtTransOffset = 27;

                    ;% Prova_sistema_P.HILInitialize_POPStart
                    section.data(29).logicalSrcIdx = 79;
                    section.data(29).dtTransOffset = 28;

                    ;% Prova_sistema_P.HILInitialize_POPEnter
                    section.data(30).logicalSrcIdx = 80;
                    section.data(30).dtTransOffset = 29;

                    ;% Prova_sistema_P.HILInitialize_POStart
                    section.data(31).logicalSrcIdx = 81;
                    section.data(31).dtTransOffset = 30;

                    ;% Prova_sistema_P.HILInitialize_POEnter
                    section.data(32).logicalSrcIdx = 82;
                    section.data(32).dtTransOffset = 31;

                    ;% Prova_sistema_P.HILInitialize_POReset
                    section.data(33).logicalSrcIdx = 83;
                    section.data(33).dtTransOffset = 32;

                    ;% Prova_sistema_P.HILInitialize_OOReset
                    section.data(34).logicalSrcIdx = 84;
                    section.data(34).dtTransOffset = 33;

                    ;% Prova_sistema_P.HILInitialize_DOFinal
                    section.data(35).logicalSrcIdx = 85;
                    section.data(35).dtTransOffset = 34;

                    ;% Prova_sistema_P.HILInitialize_DOInitial
                    section.data(36).logicalSrcIdx = 86;
                    section.data(36).dtTransOffset = 35;

                    ;% Prova_sistema_P.HILReadEncoderTimebase_Active
                    section.data(37).logicalSrcIdx = 87;
                    section.data(37).dtTransOffset = 36;

                    ;% Prova_sistema_P.HILReadEncoder_Active
                    section.data(38).logicalSrcIdx = 88;
                    section.data(38).dtTransOffset = 37;

                    ;% Prova_sistema_P.HILWriteAnalog_Active
                    section.data(39).logicalSrcIdx = 89;
                    section.data(39).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Prova_sistema_P.HILReadEncoderTimebase_Overflow
                    section.data(1).logicalSrcIdx = 90;
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
        ;% Auto data (Prova_sistema_B)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% Prova_sistema_B.countstorad1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_B.Gain7
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Prova_sistema_B.countstorad
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Prova_sistema_B.Sum
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Prova_sistema_B.Gain
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% Prova_sistema_B.u
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% Prova_sistema_B.DataTypeConversion
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% Prova_sistema_B.Gain_f
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Prova_sistema_B.LogicalOperator1
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_B.RelationalOperator2
                    section.data(2).logicalSrcIdx = 9;
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
        nTotSects     = 7;
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
        ;% Auto data (Prova_sistema_DW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Prova_sistema_DW.DiscreteTimeIntegrator_DSTATE
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_DW.HILInitialize_FilterFrequency
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Prova_sistema_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Prova_sistema_DW.HILReadEncoderTimebase_Task
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Prova_sistema_DW.SmoothSignalGenerator_RWORK.Amp
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Prova_sistema_DW.HILReadEncoder_PWORK
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_DW.HILWriteAnalog_PWORK
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% Prova_sistema_DW.PendAngledeg1_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% Prova_sistema_DW.Scope1_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% Prova_sistema_DW.thetadeg_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Prova_sistema_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% Prova_sistema_DW.HILInitialize_DOStates
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% Prova_sistema_DW.HILInitialize_QuadratureModes
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% Prova_sistema_DW.HILInitialize_InitialEICounts
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 4;

                    ;% Prova_sistema_DW.HILReadEncoderTimebase_Buffer
                    section.data(5).logicalSrcIdx = 14;
                    section.data(5).dtTransOffset = 6;

                    ;% Prova_sistema_DW.HILReadEncoder_Buffer
                    section.data(6).logicalSrcIdx = 15;
                    section.data(6).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Prova_sistema_DW.DiscreteTimeIntegrator_PrevRese
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
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


    targMap.checksum0 = 4040441263;
    targMap.checksum1 = 1032777953;
    targMap.checksum2 = 398153021;
    targMap.checksum3 = 3020918946;

