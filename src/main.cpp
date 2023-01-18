#include "esp_log.h"
#include "esp_sleep.h"
#include <stdio.h>

#include "bluetooth.h"
#include "ulp.h"

// app_main must link to C code
#ifdef __cplusplus
extern "C"
{
#endif
    void app_main(void);

#ifdef __cplusplus
}
#endif

void app_main(void)
{
    ESP_LOGI("main", "Starting up");
    ble_init();
    esp_sleep_wakeup_cause_t cause = esp_sleep_get_wakeup_cause();
    if (cause != ESP_SLEEP_WAKEUP_ULP)
    {
        ESP_LOGI("main", "Not ULP wakeup, initializing ULP");
        init_ulp_program();
    }
    else
    {
        ESP_LOGI("main", "ULP wakeup, saving pulse count");
        update_pulse_count();
    }

    ESP_LOGI("main", "Entering deep sleep\n\n");
    ble_deinit();
    ESP_ERROR_CHECK(esp_sleep_enable_ulp_wakeup());
    esp_deep_sleep_start();
}
