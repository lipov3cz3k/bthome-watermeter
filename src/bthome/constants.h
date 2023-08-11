/**
 * This file is shamlessly copied from the following repository:
 * https://github.com/stumpylog/bthome-weather-station/blob/main/components/bthome/
 * MLP2.0 License applies.
 */

#ifndef BT_HOME_CONSTANTS_H_
#define BT_HOME_CONSTANTS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <cstdint>

    namespace bthome
    {

        namespace constants
        {

            constexpr uint16_t SERVICE_UUID{0xFCD2};
            constexpr uint8_t BLE_ADVERT_MAX_LEN{31};
            constexpr uint8_t MEASUREMENT_MAX_LEN{8};
            constexpr uint8_t NONCE_LEN{12};
            constexpr uint8_t BIND_KEY_LEN{12};
            constexpr uint8_t BTHOME_V2{2};

            enum ObjectId
            {
                PACKET_ID__NONE = 0x00,
                BATTERY__PERCENTAGE = 0x01,
                TEMPERATURE_PRECISE__CELSIUS = 0x02,
                HUMIDITY_PRECISE__PERCENTAGE = 0x03,
                PRESSURE__MBAR = 0x04,
                LIGHT__LIGHT_LUX = 0x05,
                MASS__MASS_KILOGRAMS = 0x06,
                MASS__MASS_POUNDS = 0x07,
                DEW_POINT__TEMP_CELSIUS = 0x08,
                COUNT_SMALL__NONE = 0x09,
                ENERGY_MEDIUM__ENERGY_KILO_WATT_HOUR = 0x0A,
                POWER__POWER_WATT = 0x0B,
                VOLTAGE_PRECISE__ELECTRIC_POTENTIAL_VOLT = 0x0C,
                PM25__CONCENTRATION_MICROGRAMS_PER_CUBIC_METER = 0x0D,
                PM10__CONCENTRATION_MICROGRAMS_PER_CUBIC_METER = 0x0E,
                GENERIC = 0x0F,
                POWER = 0x10,
                OPENING = 0x11,
                CO2__CONCENTRATION_PARTS_PER_MILLION = 0x12,
                VOLATILE_ORGANIC_COMPOUNDS__CONCENTRATION_MICROGRAMS_PER_CUBIC_METER = 0x13,
                MOISTURE_PRECISE__PERCENTAGE = 0x14,
                BATTERY = 0x15,
                BATTERY_CHARGING = 0x16,
                CO = 0x17,
                COLD = 0x18,
                CONNECTIVITY = 0x19,
                DOOR = 0x1A,
                GARAGE_DOOR = 0x1B,
                GAS = 0x1C,
                HEAT = 0x1D,
                LIGHT = 0x1E,
                LOCK = 0x1F,
                MOISTURE = 0x20,
                MOTION = 0x21,
                MOVING = 0x22,
                OCCUPANCY = 0x23,
                PLUG = 0x24,
                PRESENCE = 0x25,
                PROBLEM = 0x26,
                RUNNING = 0x27,
                SAFETY = 0x28,
                SMOKE = 0x29,
                SOUND = 0x2A,
                TAMPER = 0x2B,
                VIBRATION = 0x2C,
                WINDOW = 0x2D,
                HUMIDITY_COARSE__PERCENTAGE = 0x2E,
                MOISTURE_COARSE__PERCENTAGE = 0x2F,
                BUTTON = 0x3A,
                DIMMER = 0x3C,
                COUNT_MEDIUM__NONE = 0x3D,
                COUNT_LARGE__NONE = 0x3E,
                ROTATION__DEGREE = 0x3F,
                DISTANCE__LENGTH_MILLIMETERS = 0x40,
                DISTANCE__LENGTH_METERS = 0x41,
                DURATION__TIME_SECONDS = 0x42,
                CURRENT__ELECTRIC_CURRENT_AMPERE = 0x43,
                SPEED__SPEED_METERS_PER_SECOND = 0x44,
                TEMPERATURE_COARSE__CELSIUS = 0x45,
                UV_INDEX__NONE = 0x46,
                VOLUME_COARSE__VOLUME_LITERS = 0x47,
                VOLUME__VOLUME_MILLILITERS = 0x48,
                VOLUME_FLOW_RATE__VOLUME_FLOW_RATE_CUBIC_METERS_PER_HOUR = 0x49,
                VOLTAGE_COARSE__ELECTRIC_POTENTIAL_VOLT = 0x4A,
                GAS_MEDIUM__VOLUME_CUBIC_METERS = 0x4B,
                GAS_LARGE__VOLUME_CUBIC_METERS = 0x4C,
                ENERGY_LARGE__ENERGY_KILO_WATT_HOUR = 0x4D,
                VOLUME_PRECISE__VOLUME_LITERS = 0x4E,
                WATER__VOLUME_LITERS = 0x4F,
                TIMESTAMP__NONE = 0x50,
                ACCELERATION__ACCELERATION_METERS_PER_SQUARE_SECOND = 0x51,
                GYROSCOPE__GYROSCOPE_DEGREES_PER_SECOND = 0x52,
                LAST_DEFINED_ID = 0x53,
                MAX_OBJECT_ID = 0x100,
            };

            typedef struct
            {
                // The scaling factor for encoding
                uint16_t factor;
                // The length in bytes
                uint8_t length;
            } BTHomeDataTypeInfo;

            extern const BTHomeDataTypeInfo InfoLookup[ObjectId::MAX_OBJECT_ID];

            enum BTHOME_DEVICE_INFO_SHIFTS
            {
                ENCRYPTED = 0,
                TRIGGER_BASED = 2,
                VERSION = 5
            };

            enum BLE_ADVERT_DATA_TYPE
            {
                TYPE = 0x1,
                COMPLETE_NAME = 0x9,
                SERVICE_DATA = 0x16
            };

            enum BLE_FLAGS_DATA_TYPE
            {
                GENERAL_DISCOVERY = (0x01 << 1),
                BREDR_NOT_SUPPORTED = (0x01 << 2),
            };

        }; // namespace constants

    }; // namespace bthome

#ifdef __cplusplus
}
#endif

#endif