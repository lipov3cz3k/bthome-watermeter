#include "bthome/advertisement.h"
#include "esp_bt.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "esp_gap_ble_api.h"
#include "esp_gatt_defs.h"
#include "esp_gattc_api.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include <cstdint>
#include <cstring>

// Store the packet ID and persist it across sleep
static RTC_DATA_ATTR uint8_t packetId{0};

static bthome::AdvertisementWithId advertisement(std::string("BTWatermater"), packetId);

static esp_ble_adv_params_t ble_adv_params = {
    .adv_int_min = 0x20,
    .adv_int_max = 0x40,
    .adv_type = ADV_TYPE_NONCONN_IND,
    .own_addr_type = BLE_ADDR_TYPE_PUBLIC,
    .peer_addr_type = BLE_ADDR_TYPE_PUBLIC,
    .channel_map = ADV_CHNL_ALL,
    .adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};

static uint8_t advertData[64];

void ble_init(void)
{
    ESP_LOGI("ble", "Starting BLE init");
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_bt_controller_mem_release(ESP_BT_MODE_CLASSIC_BT));

    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_bt_controller_init(&bt_cfg));

    ESP_ERROR_CHECK(esp_bt_controller_enable(ESP_BT_MODE_BLE));

    ESP_ERROR_CHECK(esp_bluedroid_init());
    ESP_ERROR_CHECK(esp_bluedroid_enable());
    ESP_LOGI("ble", "BLE init completed");
}

void ble_deinit(void)
{
    ESP_ERROR_CHECK(esp_bluedroid_disable());
    ESP_ERROR_CHECK(esp_bluedroid_deinit());
    ESP_ERROR_CHECK(esp_bt_controller_disable());
    ESP_ERROR_CHECK(esp_bt_controller_deinit());
}

uint8_t build_data_advert(uint8_t data[], uint32_t pulse_count)
{
    packetId++;
    bthome::Measurement pc_measurement(bthome::constants::ObjectId::COUNT_LARGE, static_cast<uint64_t>(pulse_count));

    advertisement.addMeasurement(pc_measurement);

    memcpy(&data[0], advertisement.getPayload(), advertisement.getPayloadSize());
    return advertisement.getPayloadSize();
}

void ble_advert(uint32_t pulseCount)
{
    // Encode sensor data
    uint8_t const dataLength = build_data_advert(&advertData[0], pulseCount);

    ESP_LOGI("ble", "Advert size: %i bytes", dataLength);

    // Configure advertising data
    ESP_ERROR_CHECK(esp_ble_gap_config_adv_data_raw(&advertData[0], dataLength));

    // Begin advertising
    ESP_ERROR_CHECK(esp_ble_gap_start_advertising(&ble_adv_params));

    // Wait 1500ms for a few advertisement to go out
    // The minimum time is 1s, the maximum time is 1.28s, so waiting
    // 320ms beyond that
    float delay_s = 15 / portTICK_PERIOD_MS;
    ESP_LOGI("ble", "Waiting %f for advertisements to go out", delay_s);
    sleep(delay_s);

    // Stop advertising data
    ESP_ERROR_CHECK(esp_ble_gap_stop_advertising());

    ESP_LOGI("ble", "Goodbye!");
}
