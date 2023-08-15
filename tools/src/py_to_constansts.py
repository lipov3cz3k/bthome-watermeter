from bthome_ble.const import MEAS_TYPES, SensorLibrary
from sensor_state_data.description import (
    BaseSensorDescription,
    BaseBinarySensorDescription,
)
from bthome_ble.event import EventDeviceKeys

name_map = {
    0x02: "TEMPERATURE_PRECISE__CELSIUS",
    0x03: "HUMIDITY_PRECISE__PERCENTAGE",
    0x09: "COUNT_SMALL__NONE",
    0x0A: "ENERGY_MEDIUM__ENERGY_KILO_WATT_HOUR",
    0x0C: "VOLTAGE_PRECISE__ELECTRIC_POTENTIAL_VOLT",
    0x2E: "HUMIDITY_COARSE__PERCENTAGE",
    0x14: "MOISTURE_PRECISE__PERCENTAGE",
    0x2F: "MOISTURE_COARSE__PERCENTAGE",
    0x3D: "COUNT_MEDIUM__NONE",
    0x3E: "COUNT_LARGE__NONE",
    0x45: "TEMPERATURE_COARSE__CELSIUS",
    0x47: "VOLUME_COARSE__VOLUME_LITERS",
    0x4A: "VOLTAGE_COARSE__ELECTRIC_POTENTIAL_VOLT",
    0x4B: "GAS_MEDIUM__VOLUME_CUBIC_METERS",
    0x4C: "GAS_LARGE__VOLUME_CUBIC_METERS",
    0x4D: "ENERGY_LARGE__ENERGY_KILO_WATT_HOUR",
    0x4E: "VOLUME_PRECISE__VOLUME_LITERS",
}


def _get_constant_name(value):
    if isinstance(value, BaseBinarySensorDescription):
        return value.device_class.name
    if isinstance(value, EventDeviceKeys):
        return value.name
    if isinstance(value, BaseSensorDescription):
        for n, v in SensorLibrary.__dict__.items():
            if v == value:
                return n
    return "UNKNOWN VALUE"


def _load_constants():
    const = {}
    for object_id, meas_type in MEAS_TYPES.items():
        if object_id in name_map:
            name = name_map[object_id]
        else:
            name = _get_constant_name(meas_type.meas_format)
        const[object_id] = {
            "name": name,
            "factor": int(1 / (meas_type.factor or 1)),
            "length": meas_type.data_length or 1,
        }
    # get max object id
    const[max(const.keys()) + 1] = {"name": "LAST_DEFINED_ID"}
    const[256] = {"name": "MAX_OBJECT_ID"}
    return const


def get_enum(constants):
    enum = ["enum ObjectId {"]
    for object_id, v in constants.items():
        enum.append(f"{v['name']} = 0x{object_id:0>2X},")
    enum.append("};")
    return "\n".join(enum)


def get_info_lookup(constants):
    lookup = ["const BTHomeDataTypeInfo InfoLookup[ObjectId::MAX_OBJECT_ID] = {"]
    for object_id in range(list(constants.keys())[-2]):
        constant = constants.get(object_id)
        if constant:
            lookup.append(f"// {constant['name']} ")
            lookup.append(f"{{.factor = {constant['factor']}, .length = {constant['length']}}},")
        else:
            lookup.append(f"{{}}, // empty 0x{object_id:0>2X}")
    lookup.append("};")
    return "\n".join(lookup)


constants = _load_constants()
print(get_enum(constants))
