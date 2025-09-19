#include "CfgPatches.hpp"

class CfgGlasses
{
    class None;

    class immersion_wholepack_cig0 : None
    {
        scope = 2;
        displayName = "Cigarettes (The Whole Pack)";
        model = "\murshun_cigs\cigs0.p3d";
        picture = "\murshun_cigs\UI\gear_cigpack_x_ca.paa";
        immersion_cigs_type = "wholepack";
        immersion_cigs_maxTime = 1320; // longer burn overall
        immersion_cigs_initStateTime = 0;
        immersion_cigs_nextState = "immersion_wholepack_cig1";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig1 : immersion_wholepack_cig0
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 1)";
        model = "\murshun_cigs\cigs1.p3d";
        picture = "\murshun_cigs\UI\gear_cig1_x_ca.paa";
        immersion_cigs_initStateTime = 12;
        immersion_cigs_nextState = "immersion_wholepack_cig2";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig2 : immersion_wholepack_cig0
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 2)";
        model = "\murshun_cigs\cigs2.p3d";
        picture = "\murshun_cigs\UI\gear_cig2_x_ca.paa";
        immersion_cigs_initStateTime = 132;
        immersion_cigs_nextState = "immersion_wholepack_cig3";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig3 : immersion_wholepack_cig0
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 3)";
        model = "\murshun_cigs\cigs3.p3d";
        picture = "\murshun_cigs\UI\gear_cig3_x_ca.paa";
        immersion_cigs_initStateTime = 252;
        immersion_cigs_nextState = "immersion_wholepack_cig4";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig4 : immersion_wholepack_cig0
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 4)";
        model = "\murshun_cigs\cigs4.p3d";
        picture = "\murshun_cigs\UI\gear_cig4_x_ca.paa";
        immersion_cigs_initStateTime = 612;
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
        model = "\murshun_cigs\cigs0.p3d";
        picture = "\murshun_cigs\UI\gear_cigpack_x_ca.paa";
        visionMode[] = {"Normal"};
        thermalMode[] = {0};
        modelOptics[] = {};
        opticsPPEffects[] = {};
        immersion_cigs_type = "wholepack";
        immersion_cigs_maxTime = 1320;
        immersion_cigs_initStateTime = 0;
        immersion_cigs_nextState = "immersion_wholepack_cig1_nv";
        immersion_cigs_isCig = 1;
        class ItemInfo
        {
            type = 616;
            hmdType = 0;
            uniformModel = "\murshun_cigs\cigs0.p3d";
            modelOff = "\murshun_cigs\cigs0.p3d";
        };
    };

    class immersion_wholepack_cig1_nv : immersion_wholepack_cig0_nv
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 1) (NVG Slot)";
        model = "\murshun_cigs\cigs1.p3d";
        picture = "\murshun_cigs\UI\gear_cig1_x_ca.paa";
        immersion_cigs_initStateTime = 12;
        immersion_cigs_nextState = "immersion_wholepack_cig2_nv";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig2_nv : immersion_wholepack_cig0_nv
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 2) (NVG Slot)";
        model = "\murshun_cigs\cigs2.p3d";
        picture = "\murshun_cigs\UI\gear_cig2_x_ca.paa";
        immersion_cigs_initStateTime = 132;
        immersion_cigs_nextState = "immersion_wholepack_cig3_nv";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig3_nv : immersion_wholepack_cig0_nv
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 3) (NVG Slot)";
        model = "\murshun_cigs\cigs3.p3d";
        picture = "\murshun_cigs\UI\gear_cig3_x_ca.paa";
        immersion_cigs_initStateTime = 252;
        immersion_cigs_nextState = "immersion_wholepack_cig4_nv";
        immersion_cigs_isCig = 1;
    };

    class immersion_wholepack_cig4_nv : immersion_wholepack_cig0_nv
    {
        scope = 1;
        displayName = "Cigarettes (The Whole Pack) (Stage 4) (NVG Slot)";
        model = "\murshun_cigs\cigs4.p3d";
        picture = "\murshun_cigs\UI\gear_cig4_x_ca.paa";
        immersion_cigs_initStateTime = 612;
        immersion_cigs_nextState = "";
        immersion_cigs_isCig = 1;
    };
};
