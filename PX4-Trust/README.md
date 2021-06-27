## NUCLEO-L552ZE-Q
<img title="NUCLEO-L552ZE-Q" alt="" src="https://user-images.githubusercontent.com/20378368/120424039-94996380-c3a6-11eb-83b4-0d255d1aa05a.png" width="600"/>  

### RTOS porting
[**PX4-NuttX**](https://github.com/korkeep/PX4-Trust/tree/main/PX4-Trust/NuttX) Configure Steps
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

- **Step 5**: Delete existing firmware via `nuttx_delete.sh`

  > <img title="RTOS-delete" alt="" src="https://user-images.githubusercontent.com/20378368/121977377-d4a61080-cdc0-11eb-94b5-883948d8ac76.png" width="500"/>  

- **Step 6**: Flash `nuttx.bin` file to **NUCLEO-L552ZE-Q** via `nuttx_upload.sh`  

  > <img title="RTOS-upload" alt="" src="https://user-images.githubusercontent.com/20378368/121977436-fef7ce00-cdc0-11eb-9737-e5b1647eb50e.png" width="500"/>  

- **Step 7**: Connect **NUCLEO-L552ZE-Q** with USB-UART converter

  > <img title="RTOS-connect" alt="" src="https://user-images.githubusercontent.com/20378368/120426415-04a9e880-c3ab-11eb-847a-e53b7b785b86.png" width="600"/>  
    | Pin Color | NUCLEO-L552ZE-Q | USB-UART Converter |
    | --- | --- | --- |
    | Yellow | D1TX | RX |
    | Green | D0RX | TX |
    | Blue | GND | GND |

- **Step 8**: Unzip `USB-UART-converter.zip`

  > <img title="RTOS-connect" alt="" src="https://user-images.githubusercontent.com/20378368/120428342-70418500-c3ae-11eb-984f-33ca604e0b68.png" width="600"/> 

- **Step 9**: Install converter driver via `Deivce Manager`

  > <img title="RTOS-connect" alt="" src="https://user-images.githubusercontent.com/20378368/120428634-f8c02580-c3ae-11eb-9f04-42c2b27fd2ef.png" width="700"/> 

- **Step 10**: Result

  > <img title="RTOS-result" alt="" src="https://user-images.githubusercontent.com/20378368/120424809-0d4cef80-c3a8-11eb-94b7-432477616b26.png" width="250"/>  

### Application porting
[**PX4-Autopilot**](https://github.com/PX4/PX4-Autopilot) Configure Steps
