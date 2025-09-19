// immersion_grass preInit - register functions and globals

immersion_grass_fnc_smoke = {
	params ["_unit", "_type"];

	// reuse existing smoke particle setup from murshun_cigs
	private _multiplier = 1;

	switch (_type) do {
	case "joint": { _multiplier = 1.5 };
	default { _multiplier = 1 };
	};

	private _source = "logic" createVehicleLocal (getPos _unit);
	private _fog = "#particleSource" createVehicleLocal getPos _source;
	_fog setParticleParams ["\\A3\\data_f\\cl_basic",
	"",
	"Billboard",
	0.5,
	2,
	[0, 0, 0],
	[0, 0.1, -0.1],
	1,
	1.2,
	1,
	0.1,
	[0.1 * _multiplier, 0.2 * _multiplier, 0.1 * _multiplier],
	[[0.2 * _multiplier, 0.2 * _multiplier, 0.2 * _multiplier, 0.3 * _multiplier], [0, 0, 0, 0.01], [1, 1, 1, 0]],
	[500],
	1,
	0.04,
	"",
	"",
	_source];
	_fog setParticleRandom [2, [0, 0, 0], [0.25, 0.25, 0.25], 0, 0.5, [0, 0, 0, 0.1], 0, 0, 10];
	_fog setDropInterval 0.005;

	_source attachTo [_unit, [0, 0.06, 0], "head"];

	sleep 0.4;

	deleteVehicle _source;
};

immersion_grass_fnc_playSound = {
	params ["_unit", "_class"];

	[_unit, _class] remoteExec ["say3D"];
};

immersion_grass_removeItemFromMag = {
	params ["_player", "_mag"];
	private _matchesMags = magazinesAmmo _player select {_x select 0 == _mag};

	_player removeMagazineGlobal _mag;

	private _oldMag = _matchesMags select 0;

	if ((_oldMag select 1) > 1) then {
		_player addMagazine [_mag, (_oldMag select 1) - 1];
	} else {
		[format ["%1 is now empty.", getText (configFile >> "CfgMagazines" >> _mag >> "displayName")], 2.5, _player] spawn ace_common_fnc_displayTextStructured;
	};
};

immersion_grass_fnc_useItem = {
	params ["_unit", "_player"];

	if (!("murshun_cigs_matches" in (magazines _player)) && !("murshun_cigs_lighter" in (magazines _player))) exitWith {
		["You need matches or a lighter.", 2.5, _player] spawn ace_common_fnc_displayTextStructured;
		false
	};

	switch (true) do {
	case ("murshun_cigs_lighter" in (magazines _player)): {
			[_player, "murshun_cigs_lighter"] call immersion_grass_removeItemFromMag;

			[_unit, "murshun_cigs_lighter_01"] call immersion_grass_fnc_playSound;
		};
	case ("murshun_cigs_matches" in (magazines _player)): {
			[_player, "murshun_cigs_matches"] call immersion_grass_removeItemFromMag;

			[_unit, "murshun_cigs_matches_01"] call immersion_grass_fnc_playSound;
		};
	};

	true
};

if (isNil "immersion_grass_giveItemsInSP") then {
	immersion_grass_giveItemsInSP = true;
};

immersion_grass_cigsArray = ( ("getNumber (_x >> 'immersion_cigs_isCig') == 1" configClasses (configFile >> "CfgGlasses")) apply {configName _x} ) + (("getNumber (_x >> 'immersion_cigs_isCig') == 1" configClasses (configFile >> "CfgWeapons")) apply {configName _x});

immersion_grass_canStartSmoking = {
	params ["_unit"];
	(((goggles _unit) in immersion_grass_cigsArray) || ((hmd _unit) in immersion_grass_cigsArray)) && !(_unit getVariable ['immersion_grass_jointLitUp', false])
};

immersion_grass_canStopSmoking = {
	params ["_unit"];
	(((goggles _unit) in immersion_grass_cigsArray) || ((hmd _unit) in immersion_grass_cigsArray)) && (_unit getVariable ['immersion_grass_jointLitUp', false])
};

immersion_grass_canTakeJointFromPack = {
	params ["_unit"];

	"immersion_grass_jointpack" in (magazines _unit)
};

