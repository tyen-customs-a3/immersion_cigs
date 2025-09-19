if (!hasInterface) exitWith {};

private _addVanillaActions = {
	player addAction ["Smoke a joint", {
		params ["_target", "_caller"];
		[_caller] spawn immersion_grass_fnc_start_joint_your
	}, nil, 0, false, true, "", "if (_target != player) exitWith {false}; [_this] call immersion_grass_canStartSmoking", 5, false];

	player addAction ["Stop smoking", {
		params ["_target", "_caller"];
		[_caller] spawn immersion_grass_fnc_stop_joint
	}, nil, 0, false, true, "", "if (_target != player) exitWith {false}; [_this] call immersion_grass_canStopSmoking", 5, false];

	player addAction ["Take joint from pack", {
		params ["_target", "_caller"];
		[_caller] spawn immersion_grass_fnc_take_joint_from_pack
	}, nil, 0, false, true, "", "if (_target != player) exitWith {false}; 'immersion_grass_jointpack' in (magazineCargo uniformContainer player) || 'immersion_grass_jointpack' in (magazineCargo vestContainer player)", 5, false];
};

if !(isClass (configFile >> "CfgPatches" >> "ace_interact_menu")) then {
	call _addVanillaActions;

	player addEventHandler ["Respawn", _addVanillaActions];
} else {
	private _action = ["immersion_grass_start_someones_joint", "Start someone's joint", "murshun_cigs\UI\light_cig.paa", {
		params ["_target", "_player"];
		[_target, _player] spawn immersion_grass_fnc_start_joint_their
	}, {
		params ["_target", "_player"];
		(((goggles _target) in immersion_grass_cigsArray) || ((hmd _target) in immersion_grass_cigsArray)) && !(_target getVariable ['immersion_grass_jointLitUp', false]) && (alive _target)
	}] call ace_interact_menu_fnc_createAction;

	["CAManBase", 0, ["ACE_Head"], _action, true] call ace_interact_menu_fnc_addActionToClass;
};

player addEventHandler ["Respawn", {
	player setVariable ["immersion_grass_jointLitUp", false];
}];

player addEventHandler ["InventoryClosed", {
	params ["_unit", "_container"];

	if (goggles _unit in immersion_grass_cigsArray && hmd _unit in immersion_grass_cigsArray) then {
		_unit addItem (hmd _unit);

		_unit unlinkItem (hmd _unit);
	};
}];

if (!isMultiplayer && !is3DENPreview && immersion_grass_giveItemsInSP) then {
	player addItem "immersion_grass_jointpack";
};

