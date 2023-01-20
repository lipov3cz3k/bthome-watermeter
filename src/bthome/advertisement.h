/**
 * This file is shamlessly copied from the following repository:
 * https://github.com/stumpylog/bthome-weather-station/blob/main/components/bthome/
 * MLP2.0 License applies.
 */

#ifndef _BTHOME_ADVERTISEMENT_H_
#define _BTHOME_ADVERTISEMENT_H_

#include "constants.h"
#include "measurement.h"

#include <cstdint>
#include <string>

namespace bthome
{

  class Advertisement
  {
  public:
    Advertisement(void);
    Advertisement(std::string const &name);
    ~Advertisement();

    bool addMeasurement(Measurement const &measurement);

    const uint8_t *getPayload(void) const;
    uint32_t getPayloadSize(void) const;
    void reset(void);

  private:
    void writeHeader(void);
    void writeUuid(void);
    void writeDeviceInfo(void);
    void writeByte(uint8_t const data);

    // Where in the data buffer does the next data byte go
    uint8_t m_dataIdx;
    // The actual data
    uint8_t m_data[constants::BLE_ADVERT_MAX_LEN];

    // Where in the data is the service data size located
    // The size must be updated with every new sensor data inserted
    uint8_t m_serviceDataSizeIdx;
    // Index where data writing start, following header, UUID
    uint8_t m_dataStartIdx;
    // The UUID for the service data (unencrypted or not)
    uint16_t m_serviceUuid;
  };

  class AdvertisementWithId : public Advertisement
  {
  public:
    AdvertisementWithId(uint8_t const packetId);
    AdvertisementWithId(std::string const &name, uint8_t const packetId);
  };

  /*class EncryptedAdvertisement : public Advertisement
  {
    public:
      EncryptedAdvertisement(uint32_t const countId, uint8_t const bindKey[]);
      EncryptedAdvertisement(std::string const& name, uint32_t const countId, uint8_t const bindKey[]);
    private:
      void buildNonce(void);
      void encryptData(void);
      uint8_t nonce[constants::NONCE_LEN];
      uint8_t bindKey[constants::BIND_KEY_LEN];
  };*/

}; // namespace bthome

#endif
