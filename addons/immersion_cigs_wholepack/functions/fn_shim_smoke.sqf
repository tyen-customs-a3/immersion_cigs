// This file installs a runtime shim for murshun_cigs_fnc_smoke so the
// wholepack type can produce denser smoke without editing murshun_cigs files.

// Save original implementation if present
if (isNil "murshun_cigs_fnc_smoke_original") then {
    if !(isNil "murshun_cigs_fnc_smoke") then {
        murshun_cigs_fnc_smoke_original = murshun_cigs_fnc_smoke;
    } else {
        // If original isn't defined yet, create a noop placeholder that does nothing
        murshun_cigs_fnc_smoke_original = { params ["_unit","_type"]; };
    };
};

// Install wrapper
murshun_cigs_fnc_smoke = {
    params ["_unit", "_type"];

    if (_type == "wholepack") then {
        // Denser smoke for whole pack: local implementation copied from original
        private _multiplier = 3;

        private _source = "logic" createVehicleLocal (getPos _unit);
        private _fog = "#particleSource" createVehicleLocal getPos _source;
        _fog setParticleParams ["\\A3\\data_f\\cl_basic",
        "",
        "Billboard",
        0.5,
        3,
        [0, 0, 0],
        [0, 0.1, -0.1],
        1,
        1.2,
        1,
        0.1,
        [0.12 * _multiplier, 0.24 * _multiplier, 0.12 * _multiplier],
        [[0.25 * _multiplier, 0.25 * _multiplier, 0.25 * _multiplier, 0.38 * _multiplier], [0, 0, 0, 0.01], [1, 1, 1, 0]],
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
    } else {
        // delegate to original
        [_unit, _type] call murshun_cigs_fnc_smoke_original;
    };
};
