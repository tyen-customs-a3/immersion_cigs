#include "CfgPatches.hpp"

class CfgGlasses
{
    class None;

    class immersion_wholepack_cig0 : None
    {
        scope = 2;
        displayName = "Cigarettes (The Whole Pack)";
        model = "immersion_cigs_wholepack\cigs0.p3d";
        picture = "\murshun_cigs\UI\gear_cigpack_x_ca.paa";
        immersion_cigs_type = "wholepack";
        immersion_cigs_maxTime = 495; // 1.5x longer burn than a single cigarette
        immersion_cigs_initStateTime = 0;
        immersion_cigs_nextState = "immersion_wholepack_cig1";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig1 : immersion_wholepack_cig0
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 1)";
        model = "immersion_cigs_wholepack\cigs1.p3d";
        picture = "\murshun_cigs\UI\gear_cig1_x_ca.paa";
        immersion_cigs_initStateTime = 9;
        immersion_cigs_nextState = "immersion_wholepack_cig2";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig2 : immersion_wholepack_cig0
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 2)";
        model = "immersion_cigs_wholepack\cigs2.p3d";
        picture = "\murshun_cigs\UI\gear_cig2_x_ca.paa";
        immersion_cigs_initStateTime = 99;
        immersion_cigs_nextState = "immersion_wholepack_cig3";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig3 : immersion_wholepack_cig0
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 3)";
        model = "immersion_cigs_wholepack\cigs3.p3d";
        picture = "\murshun_cigs\UI\gear_cig3_x_ca.paa";
        immersion_cigs_initStateTime = 189;
        immersion_cigs_nextState = "immersion_wholepack_cig4";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig4 : immersion_wholepack_cig0
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 4)";
        model = "immersion_cigs_wholepack\cigs4.p3d";
        picture = "\murshun_cigs\UI\gear_cig4_x_ca.paa";
        immersion_cigs_initStateTime = 459;
        immersion_cigs_nextState = "";
        immersion_cigs_isCig = 1;
    };
};

class CfgWeapons
{
    class NVGoggles;

    class immersion_wholepack_cig0_nv : NVGoggles
    {
        scope = 2;
        displayName = "Cigarettes (The Whole Pack) (NVG Slot)";
        model = "immersion_cigs_wholepack\cigs0.p3d";
        picture = "\murshun_cigs\UI\gear_cigpack_x_ca.paa";
        visionMode[] = {"Normal"};
        thermalMode[] = {0};
        modelOptics[] = {};
        opticsPPEffects[] = {};
        immersion_cigs_type = "wholepack";
        immersion_cigs_maxTime = 495;
        immersion_cigs_initStateTime = 0;
        immersion_cigs_nextState = "immersion_wholepack_cig1_nv";
        immersion_cigs_isCig = 1;
        class ItemInfo
        {
            type = 616;
            hmdType = 0;
            uniformModel = "immersion_cigs_wholepack\cigs0.p3d";
            modelOff = "immersion_cigs_wholepack\cigs0.p3d";
        };
    };

    class immersion_wholepack_cig1_nv : immersion_wholepack_cig0_nv
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 1) (NVG Slot)";
        model = "immersion_cigs_wholepack\cigs1.p3d";
        picture = "\murshun_cigs\UI\gear_cig1_x_ca.paa";
        immersion_cigs_initStateTime = 9;
        immersion_cigs_nextState = "immersion_wholepack_cig2_nv";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig2_nv : immersion_wholepack_cig0_nv
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 2) (NVG Slot)";
        model = "immersion_cigs_wholepack\cigs2.p3d";
        picture = "\murshun_cigs\UI\gear_cig2_x_ca.paa";
        immersion_cigs_initStateTime = 99;
        immersion_cigs_nextState = "immersion_wholepack_cig3_nv";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig3_nv : immersion_wholepack_cig0_nv
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 3) (NVG Slot)";
        model = "immersion_cigs_wholepack\cigs3.p3d";
        picture = "\murshun_cigs\UI\gear_cig3_x_ca.paa";
        immersion_cigs_initStateTime = 189;
        immersion_cigs_nextState = "immersion_wholepack_cig4_nv";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig4_nv : immersion_wholepack_cig0_nv
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 4) (NVG Slot)";
        model = "immersion_cigs_wholepack\cigs4.p3d";
        picture = "\murshun_cigs\UI\gear_cig4_x_ca.paa";
        immersion_cigs_initStateTime = 459;
        immersion_cigs_nextState = "";
        immersion_cigs_isCig = 1;
    };
};
class CfgVehicles
{
    class Man;
    class CAManBase : Man
    {
        class ACE_SelfActions
        {
            class ACE_Equipment
            {
                class immersion_cigs_open_wholepack
                {
                    displayName = "Open whole pack";
                    condition = "[_player] call immersion_cigs_wholepack_fnc_canOpenWholePack";
                    statement = "[_player] spawn immersion_cigs_wholepack_fnc_openWholePack";
                    showDisabled = 0;
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    icon = "murshun_cigs\UI\take_cig.paa";
                };
            };
        };
    };
};
class CfgFunctions
{
    class immersion_cigs_wholepack
    {
        class functions
        {
            file = "immersion_cigs_wholepack\functions";
            class postInit
            {
                postInit = 1;
                recompile = 1;
            };
        };
    };
};










