### NUCLEO-L552ZE-Q
<img title="NUCLEO-L552ZE-Q" alt="" src="https://user-images.githubusercontent.com/20378368/120424039-94996380-c3a6-11eb-83b4-0d255d1aa05a.png" width="600"/>  

### RTOS porting
[**PX4-NuttX**](https://github.com/korkeep/PX4-Trust/tree/main/PX4-Trust/NUCLEO-H745ZI-Q/NuttX) Configure Steps
- **Step 1**: Configure Board  

  > `$ tools/configure.sh nucleo-l552ze:nsh`

- **Step 2**: Change config file via menuconfig

  > `$ make menuconfig`  

  > CONFIG_STM32L5_USART3_SERIALDRIVER=y  
  > CONFIG_STM32L5_USART=y  
  > CONFIG_USART3_SERIALDRIVER=y  
  > CONFIG_USART3_RXBUFSIZE=256  
  > CONFIG_USART3_TXBUFSIZE=256  
  > CONFIG_USART3_BAUD=115200  
  > CONFIG_USART3_BITS=8  
  > CONFIG_USART3_PARITY=0  
  > CONFIG_USART3_2STOP=0  

- **Step 3**: Build file

  > `$ make oldconfig`  
  > `$ make`

- **Step 4**: Then `nuttx`, `nuttx.bin`, `nuttx.manifest`, `System.map` files will be generated  

  > <img title="RTOS-build" alt="" src="https://user-images.githubusercontent.com/20378368/120424399-3620b500-c3a7-11eb-82e6-47f1c5fac195.png" width="500"/>  

- **Step 5**: Upload `nuttx.bin` file to **NUCLEO-L552ZE-Q** via [ST-Link v2](https://www.st.com/en/development-tools/st-link-v2.html)  

  > <img title="RTOS-upload" alt="" src="https://user-images.githubusercontent.com/20378368/120424739-ee4e5d80-c3a7-11eb-87fd-0d06717de6e6.png" width="500"/>  

- **Step 6**: Connect **NUCLEO-L552ZE-Q** with USB-UART converter

  > <img title="RTOS-connect" alt="" src="https://user-images.githubusercontent.com/20378368/120426415-04a9e880-c3ab-11eb-847a-e53b7b785b86.png" width="600"/>  
    | Pin Color | NUCLEO-L552ZE-Q | USB-UART Converter |
    | --- | --- | --- |
    | Yellow | D1TX | RX |
    | Green | D0RX | TX |
    | Blue | GND | GND |

- **Step 7**: Unzip `CDM v2.12.28 WHQL Certified`

  > <img title="RTOS-connect" alt="" src="https://user-images.githubusercontent.com/20378368/120428342-70418500-c3ae-11eb-984f-33ca604e0b68.png" width="600"/> 

- **Step 8**: Install converter driver via `Deivce Manager`

  > <img title="RTOS-connect" alt="" src="https://user-images.githubusercontent.com/20378368/120428634-f8c02580-c3ae-11eb-9f04-42c2b27fd2ef.png" width="700"/> 

- **Step 9**: Result

  > <img title="RTOS-result" alt="" src="https://user-images.githubusercontent.com/20378368/120424809-0d4cef80-c3a8-11eb-94b7-432477616b26.png" width="250"/>  

### Bootloader porting
[**PX4-Bootloader**](https://github.com/korkeep/PX4-Trust/tree/main/PX4-Trust/NUCLEO-H745ZI-Q/Bootloader) Configure Steps
### Application porting
[**PX4-Autopilot**](https://github.com/PX4/PX4-Autopilot) Configure Steps
