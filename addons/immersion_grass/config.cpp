#include "CfgPatches.hpp"

class CfgMagazines
{
    class CA_Magazine;

    class immersion_grass_bag : CA_Magazine
    {
        author = "$STR_immersion_grass_author";
        scope = 2;
        displayName = "$STR_immersion_grass_bag";
        descriptionShort = "$STR_immersion_grass_bag_descr";
        model = "\murshun_cigs\cigpack.p3d";
        picture = "\murshun_cigs\UI\gear_cigpack_x_ca.paa";
        ammo = "";
        count = 6;
        initSpeed = 0;
        tracersEvery = 0;
        lastRoundsTracer = 0;
        mass = 1;
    };
};

class CfgGlasses
{
    class None;

    class immersion_grass_joint0 : None
    {
        scope = 2;
        displayName = "$STR_immersion_grass_joint0";
        model = "\murshun_cigs\cig0.p3d";
        picture = "\murshun_cigs\UI\gear_cig0_x_ca.paa";
        identityTypes[] = {};
        immersion_cigs_type = "joint";
        immersion_cigs_maxTime = 495; // 1.5x longer than a single cigarette
        immersion_cigs_initStateTime = 0;
        immersion_cigs_nextState = "immersion_grass_joint1";
        immersion_cigs_isCig = 1;
    };

    class immersion_grass_joint1 : immersion_grass_joint0
    {
        scope = 1;
        displayName = "Joint (Stage 1)";
        model = "\murshun_cigs\cig1.p3d";
        picture = "\murshun_cigs\UI\gear_cig1_x_ca.paa";
        immersion_cigs_initStateTime = 9;
        immersion_cigs_nextState = "immersion_grass_joint2";
    };

    class immersion_grass_joint2 : immersion_grass_joint0
    {
        scope = 1;
        displayName = "Joint (Stage 2)";
        model = "\murshun_cigs\cig2.p3d";
        picture = "\murshun_cigs\UI\gear_cig2_x_ca.paa";
        immersion_cigs_initStateTime = 99;
        immersion_cigs_nextState = "immersion_grass_joint3";
    };

    class immersion_grass_joint3 : immersion_grass_joint0
    {
        scope = 1;
        displayName = "Joint (Stage 3)";
        model = "\murshun_cigs\cig3.p3d";
        picture = "\murshun_cigs\UI\gear_cig3_x_ca.paa";
        immersion_cigs_initStateTime = 189;
        immersion_cigs_nextState = "immersion_grass_joint4";
    };

    class immersion_grass_joint4 : immersion_grass_joint0
    {
        scope = 1;
        displayName = "Joint (Stage 4)";
        model = "\murshun_cigs\cig4.p3d";
        picture = "\murshun_cigs\UI\gear_cig4_x_ca.paa";
        immersion_cigs_initStateTime = 459;
        immersion_cigs_nextState = "";
    };
};

class CfgWeapons
{
    class NVGoggles;

    class immersion_grass_joint0_nv : NVGoggles
    {
        scope = 2;
        displayName = "$STR_immersion_grass_joint0";
        model = "\murshun_cigs\cig0.p3d";
        picture = "\murshun_cigs\UI\gear_cig0_x_ca.paa";
        visionMode[] = {"Normal"};
        thermalMode[] = {0};
        modelOptics[] = {};
        opticsPPEffects[] = {};
        immersion_cigs_type = "joint";
        immersion_cigs_maxTime = 495;
        immersion_cigs_initStateTime = 0;
        immersion_cigs_nextState = "immersion_grass_joint1_nv";
        immersion_cigs_isCig = 1;
        class ItemInfo
        {
            type = 616;
            hmdType = 0;
            uniformModel = "\murshun_cigs\cig0.p3d";
            modelOff = "\murshun_cigs\cig0.p3d";
        };
    };

    class immersion_grass_joint1_nv : immersion_grass_joint0_nv
    {
        scope = 1;
        displayName = "Joint (Stage 1)";
        model = "\murshun_cigs\cig1.p3d";
        picture = "\murshun_cigs\UI\gear_cig1_x_ca.paa";
        immersion_cigs_initStateTime = 9;
        immersion_cigs_nextState = "immersion_grass_joint2_nv";
    };

    class immersion_grass_joint2_nv : immersion_grass_joint0_nv
    {
        scope = 1;
        displayName = "Joint (Stage 2)";
        model = "\murshun_cigs\cig2.p3d";
        picture = "\murshun_cigs\UI\gear_cig2_x_ca.paa";
        immersion_cigs_initStateTime = 99;
        immersion_cigs_nextState = "immersion_grass_joint3_nv";
    };

    class immersion_grass_joint3_nv : immersion_grass_joint0_nv
    {
        scope = 1;
        displayName = "Joint (Stage 3)";
        model = "\murshun_cigs\cig3.p3d";
        picture = "\murshun_cigs\UI\gear_cig3_x_ca.paa";
        immersion_cigs_initStateTime = 189;
        immersion_cigs_nextState = "immersion_grass_joint4_nv";
    };

    class immersion_grass_joint4_nv : immersion_grass_joint0_nv
    {
        scope = 1;
        displayName = "Joint (Stage 4)";
        model = "\murshun_cigs\cig4.p3d";
        picture = "\murshun_cigs\UI\gear_cig4_x_ca.paa";
        immersion_cigs_initStateTime = 459;
        immersion_cigs_nextState = "";
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
                class immersion_grass_take_joint_from_bag
                {
                    displayName = "$STR_immersion_grass_take_joint_from_bag";
                    condition = "[_player] call immersion_grass_fnc_canTakeJointFromBag";
                    statement = "[_player] spawn immersion_grass_fnc_takeJointFromBag";
                    showDisabled = 0;
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    icon = "murshun_cigs\UI\take_cig.paa";
                };
            };
        };
    };

    class WeaponHolder_Single_limited_item_F;
    class immersion_grass_bagItem : WeaponHolder_Single_limited_item_F
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_immersion_grass_bag";
        author = "$STR_immersion_grass_author";
        vehicleClass = "Magazines";
        class TransportMagazines
        {
            class immersion_grass_bag
            {
                magazine = "immersion_grass_bag";
                count = 1;
            };
        };
    };
};

class CfgFunctions
{
    class immersion_grass
    {
        class functions
        {
            file = "immersion_grass\functions";
            class postInit
            {
                postInit = 1;
            };
        };
    };
};





