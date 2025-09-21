if (!hasInterface) exitWith {};

immersion_grass_fnc_canTakeJointFromBag = {
    params ["_unit"];

    "immersion_grass_bag" in (magazines _unit);
};

immersion_grass_fnc_takeJointFromBag = {
    params ["_player"];

    if (!([_player] call immersion_grass_fnc_canTakeJointFromBag)) exitWith {false};

    private _newItem = "immersion_grass_joint0";

    if (goggles _player != "") then {
        if (hmd _player == "") then {
            _newItem = "immersion_grass_joint0_nv";
        };
    };

    if (!(_player canAdd _newItem)) exitWith {
        ["Not enough space to stash a joint.", 2.5, _player] spawn ace_common_fnc_displayTextStructured;
        false
    };

    [_player, "immersion_grass_bag"] call murshun_cigs_removeItemFromMag;
    [_player, "murshun_cigs_unwrap"] call murshun_cigs_playSound;

    _player addItem _newItem;
    true
};

immersion_grass_fnc_addVanillaActions = {
    player addAction [localize "STR_immersion_grass_take_joint_from_bag", {
        params ["_target", "_caller"];
        [_caller] spawn immersion_grass_fnc_takeJointFromBag;
    }, nil, 0, false, true, "", "if (_target != player) exitWith {false}; [_target] call immersion_grass_fnc_canTakeJointFromBag", 5, false];
};

call immersion_grass_fnc_addVanillaActions;

player addEventHandler ["Respawn", immersion_grass_fnc_addVanillaActions];

