# BTHome water meter
An ESP-IDF project which counts pulses in ULP unit and sends data encoded in the BTHome format over BLE.

Pulses are counted in Ultra Low Power coprocessor in deep-sleep mode with consumption about 0.00016A. When counter reach 5 pulses,
it wakes up main ESP unit, add recently counted pulses to NVS memory and start broadcasting BLE signal (in BTHome standard), after that, it goes deep-sleep again.

# Instructions
1. Set up platform.io project (you can use VSCode with platform.io extension)
2. Run build and upload to your board
3. Connect GPIO 4 and GND with your pulse generator
 - port GPIO4 is set up as pull-up, so you can connect any pulse generator with high-impedance state
4. New BTHome device should appear in home-assistant automatically

# References
1. [BTHome Weather Station](https://github.com/stumpylog/bthome-weather-station)
1. [ULP Pulse Counting Example](https://github.com/espressif/esp-idf/tree/v4.3.4/examples/system/ulp)
1. [BTHome](https://bthome.io/)

# Improvements
1. Battery monitoring
1. Solve how to setup initial state
