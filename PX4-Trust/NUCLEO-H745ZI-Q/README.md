## NUCLEO-H745ZI-Q
### RTOS porting
[**PX4-NuttX**](https://github.com/korkeep/PX4-Trust/tree/main/PX4-Trust/NUCLEO-H745ZI-Q/NuttX) Configure Steps
- **Step 1**: Configure Board
> ```$ tools/configure.sh nucleo-h743zi:nsh```
- **Step 2**: Build file
> ```$ make```
- **Step 3**: Then `nuttx`, `nuttx.bin`, `nuttx.hex`, `nuttx.manifest`, `System.map` files will be generated
> ![result](https://user-images.githubusercontent.com/20378368/119437274-be280e80-bd58-11eb-83ee-a4e94c531831.png)
- **Step 4**: Upload `nuttx.bin`, `System.map` files to **NUCLEO-H745ZI-Q** via [ST-Link v2](https://www.st.com/en/development-tools/st-link-v2.html)
> ![upload](https://user-images.githubusercontent.com/20378368/119437566-5aeaac00-bd59-11eb-9d08-206af263871d.png)
### Bootloader porting
[**PX4-Bootloader**](https://github.com/korkeep/PX4-Trust/tree/main/PX4-Trust/NUCLEO-H745ZI-Q/Bootloader) Configure Steps
### Application porting
[**PX4-Autopilot**](https://github.com/PX4/PX4-Autopilot) Configure Steps