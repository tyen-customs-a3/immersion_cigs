immersion_wholepack_fnc_open_pack = {
    params ["_player"];

    // Require that player has a cigpack
    if not ("murshun_cigs_cigpack" in (magazines _player)) exitWith {
        if !(isClass (configFile >> "CfgPatches" >> "ace_common")) then {
            hintSilent localize "STR_murshun_cigs_no_matches_or_lighter";
        } else {
            [localize "STR_murshun_cigs_no_matches_or_lighter", 2.5, _player] spawn ace_common_fnc_displayTextStructured;
        };
        false
    };

    // remove one pack and add the whole pack 'item' (as glasses slot item)
    [_player, "murshun_cigs_cigpack"] call murshun_cigs_removeItemFromMag;

    // add the whole pack item as goggles (so it's discovered like other cigs)
    if (goggles _player == "") then {
        _player addItem "immersion_wholepack_cig0";
    } else {
        if (hmd _player == "") then {
            _player addItem "immersion_wholepack_cig0_nv";
        } else {
            _player addItem "immersion_wholepack_cig0";
        };
    };

    // play unwrap sound (reuse existing sound)
    [_player, "murshun_cigs_unwrap"] call murshun_cigs_playSound;
};
