// Extend murshun_cigs smoke handling for the wholepack variant
if (isNil "immersion_cigs_wholepack_fnc_originalSmoke" && {!isNil "murshun_cigs_fnc_smoke"}) then {
    immersion_cigs_wholepack_fnc_originalSmoke = murshun_cigs_fnc_smoke;

    murshun_cigs_fnc_smoke = {
        params ["_unit", "_type"];

        if (_type == "wholepack") exitWith {
            private _delays = [0, 0.4, 0.8];

            {
                [_unit, _x] spawn {
                    params ["_unit", "_delay"];

                    sleep _delay;

                    for "_i" from 1 to 3 do {
                        [_unit, "wholepack"] spawn immersion_cigs_wholepack_fnc_originalSmoke;
                        sleep 0.01;
                    };
                };
            } forEach _delays;

            true
        };

        [_unit, _type] call immersion_cigs_wholepack_fnc_originalSmoke;
    };
};

if (!hasInterface) exitWith {};

immersion_cigs_wholepack_fnc_canOpenWholePack = {
    params ["_unit"];

    if (isNil "immersion_cigs_canTakeCigFromPack") exitWith {false};

    [_unit] call immersion_cigs_canTakeCigFromPack;
};

immersion_cigs_wholepack_fnc_openWholePack = {
    params ["_player"];

    if (!([_player] call immersion_cigs_wholepack_fnc_canOpenWholePack)) exitWith {};

    private _packClass = "murshun_cigs_cigpack";
    private _hasPack = magazinesAmmo _player select {(_x select 0) == _packClass};

    if (_hasPack isEqualTo []) exitWith {};

    private _newItem = "immersion_wholepack_cig0";

    if (goggles _player != "") then {
        if (hmd _player == "") then {
            _newItem = "immersion_wholepack_cig0_nv";
        };
    };

    if (!(_player canAdd _newItem)) exitWith {
        ["Not enough space to open the whole pack.", 2.5, _player] spawn ace_common_fnc_displayTextStructured;
    };

    _player removeMagazineGlobal _packClass;
    [_player, "murshun_cigs_unwrap"] call murshun_cigs_playSound;

    _player addItem _newItem;
};

private _addVanillaActions = {
    player addAction ["Open whole pack", {
        params ["_target", "_caller"];
        [_caller] spawn immersion_cigs_wholepack_fnc_openWholePack;
    }, nil, 0, false, true, "", "if (_target != player) exitWith {false}; [_target] call immersion_cigs_wholepack_fnc_canOpenWholePack", 5, false];
};

call _addVanillaActions;

player addEventHandler ["Respawn", _addVanillaActions];
