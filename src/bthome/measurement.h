/**
 * This file is shamlessly copied from the following repository:
 * https://github.com/stumpylog/bthome-weather-station/blob/main/components/bthome/
 * MLP2.0 License applies.
 */

#ifndef BT_HOME_SENSOR_H_
#define BT_HOME_SENSOR_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "constants.h"

#include <cstdint>

    namespace bthome
    {
        class Measurement
        {
        public:
            Measurement(enum constants::ObjectId const objectId, float const data);
            Measurement(enum constants::ObjectId const objectId, uint64_t const data);
            ~Measurement();
            const uint8_t *getPayload(void) const;
            uint32_t getPayloadSize(void) const;

        protected:
            void packData(void);

            enum constants::ObjectId m_objectId;
            uint64_t m_scaledData;
            uint32_t m_payloadIdx;
            uint8_t m_payload[constants::MEASUREMENT_MAX_LEN]{0};
        };

    }; // namespace bthome

#ifdef __cplusplus
}
#endif

#endif
