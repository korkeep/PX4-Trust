## NUCLEO-H745ZI-Q
<img title="NUCLEO-H745ZI-Q" alt="" src="https://user-images.githubusercontent.com/20378368/119439137-b5d1d280-bd5c-11eb-9bfb-c7afef5a0ccc.png" width="500"/>  

### Pin Configureation
> <img title="pinmap" alt="" src="https://user-images.githubusercontent.com/20378368/119438106-6d191a00-bd5a-11eb-9560-6fc8365af1db.png" width="800"/>  
- On-board ST-LINK/V2-1
- Mbed-enabled
- 3 user LEDs
- Two buttons (User and Reset)
- 32.768 kHz crystal oscillator
- USB OTG FS with Micro-AB connectors
- Ethernet connector
- Board connectors:
  - USB with Micro-AB  
  - SWD  
  - Ethernet RJ45  
  - ST Zio connector including Arduino Uno V3  
  - ST morpho  
- NUCLEO virtual console
  - PD8: SERIAL_TX
  - PD9: SERIAL_RX

### RTOS porting
[**PX4-NuttX**](https://github.com/korkeep/PX4-Trust/tree/main/PX4-Trust/NUCLEO-H745ZI-Q/NuttX) Configure Steps
- **Step 1**: Configure Board  

  > ```$ tools/configure.sh nucleo-h743zi:nsh```

- **Step 2**: Build file  

  > ```$ make```

- **Step 3**: Then `nuttx`, `nuttx.bin`, `nuttx.hex`, `nuttx.manifest`, `System.map` files will be generated  

  > <img title="result" alt="" src="https://user-images.githubusercontent.com/20378368/119437274-be280e80-bd58-11eb-83ee-a4e94c531831.png" width="500"/>  

- **Step 4**: Upload `nuttx.bin`, `System.map` files to **NUCLEO-H745ZI-Q** via [ST-Link v2](https://www.st.com/en/development-tools/st-link-v2.html)  

  > <img title="upload" alt="" src="https://user-images.githubusercontent.com/20378368/119437566-5aeaac00-bd59-11eb-9d08-206af263871d.png" width="500"/>  

### Bootloader porting
[**PX4-Bootloader**](https://github.com/korkeep/PX4-Trust/tree/main/PX4-Trust/NUCLEO-H745ZI-Q/Bootloader) Configure Steps
### Application porting
[**PX4-Autopilot**](https://github.com/PX4/PX4-Autopilot) Configure Steps