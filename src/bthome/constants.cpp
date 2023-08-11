/**
 * This file is shamlessly copied from the following repository:
 * https://github.com/stumpylog/bthome-weather-station/blob/main/components/bthome/
 * MLP2.0 License applies.
 */

#include "constants.h"

namespace bthome
{

    namespace constants
    {

        const BTHomeDataTypeInfo InfoLookup[ObjectId::MAX_OBJECT_ID] = {
            // PACKET_ID__NONE
            {.factor = 1, .length = 1},
            // BATTERY__PERCENTAGE
            {.factor = 1, .length = 1},
            // TEMPERATURE_PRECISE__CELSIUS
            {.factor = 100, .length = 2},
            // HUMIDITY_PRECISE__PERCENTAGE
            {.factor = 100, .length = 2},
            // PRESSURE__MBAR
            {.factor = 100, .length = 3},
            // LIGHT__LIGHT_LUX
            {.factor = 100, .length = 3},
            // MASS__MASS_KILOGRAMS
            {.factor = 100, .length = 2},
            // MASS__MASS_POUNDS
            {.factor = 100, .length = 2},
            // DEW_POINT__TEMP_CELSIUS
            {.factor = 100, .length = 2},
            // COUNT_SMALL__NONE
            {.factor = 1, .length = 1},
            // ENERGY_MEDIUM__ENERGY_KILO_WATT_HOUR
            {.factor = 1000, .length = 3},
            // POWER__POWER_WATT
            {.factor = 100, .length = 3},
            // VOLTAGE_PRECISE__ELECTRIC_POTENTIAL_VOLT
            {.factor = 1000, .length = 2},
            // PM25__CONCENTRATION_MICROGRAMS_PER_CUBIC_METER
            {.factor = 1, .length = 2},
            // PM10__CONCENTRATION_MICROGRAMS_PER_CUBIC_METER
            {.factor = 1, .length = 2},
            // GENERIC
            {.factor = 1, .length = 1},
            // POWER
            {.factor = 1, .length = 1},
            // OPENING
            {.factor = 1, .length = 1},
            // CO2__CONCENTRATION_PARTS_PER_MILLION
            {.factor = 1, .length = 2},
            // VOLATILE_ORGANIC_COMPOUNDS__CONCENTRATION_MICROGRAMS_PER_CUBIC_METER
            {.factor = 1, .length = 2},
            // MOISTURE_PRECISE__PERCENTAGE
            {.factor = 100, .length = 2},
            // BATTERY
            {.factor = 1, .length = 1},
            // BATTERY_CHARGING
            {.factor = 1, .length = 1},
            // CO
            {.factor = 1, .length = 1},
            // COLD
            {.factor = 1, .length = 1},
            // CONNECTIVITY
            {.factor = 1, .length = 1},
            // DOOR
            {.factor = 1, .length = 1},
            // GARAGE_DOOR
            {.factor = 1, .length = 1},
            // GAS
            {.factor = 1, .length = 1},
            // HEAT
            {.factor = 1, .length = 1},
            // LIGHT
            {.factor = 1, .length = 1},
            // LOCK
            {.factor = 1, .length = 1},
            // MOISTURE
            {.factor = 1, .length = 1},
            // MOTION
            {.factor = 1, .length = 1},
            // MOVING
            {.factor = 1, .length = 1},
            // OCCUPANCY
            {.factor = 1, .length = 1},
            // PLUG
            {.factor = 1, .length = 1},
            // PRESENCE
            {.factor = 1, .length = 1},
            // PROBLEM
            {.factor = 1, .length = 1},
            // RUNNING
            {.factor = 1, .length = 1},
            // SAFETY
            {.factor = 1, .length = 1},
            // SMOKE
            {.factor = 1, .length = 1},
            // SOUND
            {.factor = 1, .length = 1},
            // TAMPER
            {.factor = 1, .length = 1},
            // VIBRATION
            {.factor = 1, .length = 1},
            // WINDOW
            {.factor = 1, .length = 1},
            // HUMIDITY_COARSE__PERCENTAGE
            {.factor = 1, .length = 1},
            // MOISTURE_COARSE__PERCENTAGE
            {.factor = 1, .length = 1},
            {}, // empty 0x30
            {}, // empty 0x31
            {}, // empty 0x32
            {}, // empty 0x33
            {}, // empty 0x34
            {}, // empty 0x35
            {}, // empty 0x36
            {}, // empty 0x37
            {}, // empty 0x38
            {}, // empty 0x39
            // BUTTON
            {.factor = 1, .length = 1},
            {}, // empty 0x3B
            // DIMMER
            {.factor = 1, .length = 2},
            // COUNT_MEDIUM__NONE
            {.factor = 1, .length = 2},
            // COUNT_LARGE__NONE
            {.factor = 1, .length = 4},
            // ROTATION__DEGREE
            {.factor = 10, .length = 2},
            // DISTANCE__LENGTH_MILLIMETERS
            {.factor = 1, .length = 2},
            // DISTANCE__LENGTH_METERS
            {.factor = 10, .length = 2},
            // DURATION__TIME_SECONDS
            {.factor = 1000, .length = 3},
            // CURRENT__ELECTRIC_CURRENT_AMPERE
            {.factor = 1000, .length = 2},
            // SPEED__SPEED_METERS_PER_SECOND
            {.factor = 100, .length = 2},
            // TEMPERATURE_COARSE__CELSIUS
            {.factor = 10, .length = 2},
            // UV_INDEX__NONE
            {.factor = 10, .length = 1},
            // VOLUME_COARSE__VOLUME_LITERS
            {.factor = 10, .length = 2},
            // VOLUME__VOLUME_MILLILITERS
            {.factor = 1, .length = 2},
            // VOLUME_FLOW_RATE__VOLUME_FLOW_RATE_CUBIC_METERS_PER_HOUR
            {.factor = 1000, .length = 2},
            // VOLTAGE_COARSE__ELECTRIC_POTENTIAL_VOLT
            {.factor = 10, .length = 2},
            // GAS_MEDIUM__VOLUME_CUBIC_METERS
            {.factor = 1000, .length = 3},
            // GAS_LARGE__VOLUME_CUBIC_METERS
            {.factor = 1000, .length = 4},
            // ENERGY_LARGE__ENERGY_KILO_WATT_HOUR
            {.factor = 1000, .length = 4},
            // VOLUME_PRECISE__VOLUME_LITERS
            {.factor = 1000, .length = 4},
            // WATER__VOLUME_LITERS
            {.factor = 1000, .length = 4},
            // TIMESTAMP__NONE
            {.factor = 1, .length = 4},
            // ACCELERATION__ACCELERATION_METERS_PER_SQUARE_SECOND
            {.factor = 1000, .length = 2},
            // GYROSCOPE__GYROSCOPE_DEGREES_PER_SECOND
            {.factor = 1000, .length = 2},
        };

    };
}; // namespace bthome
