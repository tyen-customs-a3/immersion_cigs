#include "CfgPatches.hpp"

class CfgVehicles
{
	class Man;
	class CAManBase : Man
	{
		class ACE_SelfActions
		{
			class ACE_Equipment
			{
				class immersion_grass_start_joint
				{
					displayName = "$STR_immersion_grass_start_joint";
					condition = "[_player] call immersion_grass_canStartSmoking";
					statement = "[_player] spawn immersion_grass_fnc_start_joint_your";
					showDisabled = 0;
					exceptions[] = {"isNotInside", "isNotSitting"};
					icon = "murshun_cigs\UI\light_cig.paa";
				};

				class immersion_grass_stop_joint
				{
					displayName = "$STR_immersion_grass_stop_joint";
					condition = "[_player] call immersion_grass_canStopSmoking";
					statement = "[_player] spawn immersion_grass_fnc_stop_joint";
					showDisabled = 0;
					exceptions[] = {"isNotInside", "isNotSitting"};
					icon = "murshun_cigs\UI\light_cig.paa";
				};

				class immersion_grass_take_joint_from_pack
				{
					displayName = "$STR_immersion_grass_take_joint_from_pack";
					condition = "[_player] call immersion_grass_canTakeJointFromPack";
					statement = "[_player] spawn immersion_grass_fnc_take_joint_from_pack";
					showDisabled = 0;
					exceptions[] = {"isNotInside", "isNotSitting"};
					icon = "murshun_cigs\UI\take_cig.paa";
				};
			};
		};
	};

	class WeaponHolder_Single_limited_item_F;

	class immersion_grass_jointpackItem : WeaponHolder_Single_limited_item_F
	{
		scope = 2;
		scopeCurator = 2;
		displayName = "$STR_immersion_grass_jointpack";
		author = "$STR_immersion_grass_author";
		vehicleClass = "Magazines";
		class TransportMagazines
		{
			class immersion_grass_jointpack
			{
				magazine = "immersion_grass_jointpack";
				count = 1;
			};
		};
	};
};

class CfgMagazines
{
	class CA_Magazine;

	class immersion_grass_jointpack : CA_Magazine
	{
		author = "$STR_immersion_grass_author";
		scope = 2;
		displayName = "$STR_immersion_grass_jointpack";
		descriptionShort = "$STR_immersion_grass_jointpack_descr";
		model = "\murshun_cigs\cigpack.p3d";
		picture = "\murshun_cigs\UI\gear_cigpack_x_ca";
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
		author = "$STR_immersion_grass_author";
		mass = 0.03;
		displayName = "$STR_immersion_grass_joint0";
		model = "\murshun_cigs\cig0.p3d"; // placeholder model
		picture = "\murshun_cigs\UI\gear_cig0_x_ca";
		identityTypes[] = {};
		immersion_cigs_type = "joint";
		immersion_cigs_maxTime = 420;
		immersion_cigs_initStateTime = 0;
		immersion_cigs_nextState = "immersion_grass_joint1";
		immersion_cigs_isCig = 1;
	};

	class immersion_grass_joint1 : immersion_grass_joint0
	{
		scope = 1;
		displayName = "Joint (Stage 1)";
		model = "\murshun_cigs\cig1.p3d";
		picture = "\murshun_cigs\UI\gear_cig1_x_ca";
		immersion_cigs_initStateTime = 8;
		immersion_cigs_nextState = "immersion_grass_joint2";
		immersion_cigs_isCig = 1;
	};

	class immersion_grass_joint2 : immersion_grass_joint0
	{
		scope = 1;
		displayName = "Joint (Stage 2)";
		model = "\murshun_cigs\cig2.p3d";
		picture = "\murshun_cigs\UI\gear_cig2_x_ca";
		immersion_cigs_initStateTime = 90;
		immersion_cigs_nextState = "immersion_grass_joint3";
		immersion_cigs_isCig = 1;
	};

	class immersion_grass_joint3 : immersion_grass_joint0
	{
		scope = 1;
		displayName = "Joint (Stage 3)";
		model = "\murshun_cigs\cig3.p3d";
		picture = "\murshun_cigs\UI\gear_cig3_x_ca";
		immersion_cigs_initStateTime = 180;
		immersion_cigs_nextState = "immersion_grass_joint4";
		immersion_cigs_isCig = 1;
	};

	class immersion_grass_joint4 : immersion_grass_joint0
	{
		scope = 1;
		displayName = "Joint (Stage 4)";
		model = "\murshun_cigs\cig4.p3d";
		picture = "\murshun_cigs\UI\gear_cig4_x_ca";
		immersion_cigs_initStateTime = 360;
		immersion_cigs_nextState = "";
		immersion_cigs_isCig = 1;
	};
};

class CfgSounds
{
	sounds[] = {};
	class immersion_grass_unwrap
	{
		sound[] = {"\murshun_cigs\murshun_cigs_unwrap.ogg", 2, 1, 15};
		titles[] = {};
	};
};

class CfgFunctions
{
	class immersion_grass
	{
		class functions
		{
			file = "immersion_grass\functions";
			class preInit
			{
				preInit = 1;
				recompile = 1;
			};
			class postInit
			{
				postInit = 1;
				recompile = 1;
			};
		};
	};
};
