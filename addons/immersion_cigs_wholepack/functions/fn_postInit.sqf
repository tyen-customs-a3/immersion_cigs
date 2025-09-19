if (!hasInterface) exitWith {};

private _addVanillaActions_wholepack = {
    player addAction ["Open The Entire Pack", {
        params ["_target", "_caller"];
        [_caller] spawn immersion_wholepack_fnc_open_pack
    }, nil, 0, false, true, "", "if (_target != player) exitWith {false}; 'murshun_cigs_cigpack' in (magazineCargo uniformContainer player) || 'murshun_cigs_cigpack' in (magazineCargo vestContainer player)", 5, false];
};

if !(isClass (configFile >> "CfgPatches" >> "ace_interact_menu")) then {
    call _addVanillaActions_wholepack;

    player addEventHandler ["Respawn", _addVanillaActions_wholepack];
} else {
    private _actionOpen = ["immersion_wholepack_open_pack", "Open The Entire Pack", "murshun_cigs\\UI\\gear_cigpack_x_ca.paa", {
        params ["_target", "_player"];
        [_player] spawn immersion_wholepack_fnc_open_pack
    }, {
        params ["_target", "_player"];
        'murshun_cigs_cigpack' in (magazineCargo _player) || 'murshun_cigs_cigpack' in (magazineCargo _player)
    }] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 0, ["ACE_Head"], _actionOpen, true] call ace_interact_menu_fnc_addActionToClass;
};
