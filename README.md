# PX4-Trust
The **PX4-Trust** project proposes an architecture that can protect core-assets of the drone system, such as private key, user data, and security functions, by utilizing the ARM Trusted Firmware-M function. 🚁🔐  

## PX4
**PX4 Autopilot** is an open-source autopilot system for Unmanned Aerial Vehicle. **PX4 Autopilot** guarantees scalability so that the PX4 ecosystem can be maintained by providing a standard for drone hardware and software.  
- [PX4 Github](https://github.com/PX4/PX4-Autopilot)
- [PX4 Autopilot](https://docs.px4.io/master/en/)
- [QGroundControl](http://qgroundcontrol.com/)
- [MAVLink Protocol](https://mavlink.io/en/)

## ARM PSA(Platform Security Architecture)
**ARM PSA** was introduced to protect key assets of the system such as private keys, user data, and security functions from unauthorized external access. **ARM PSA** is a mechanism that guarantees the separation of the execution environment by dividing memory, peripheral devices, and functions into secure and non-secure areas. ARMv8-M is a processor model that can utilize **ARM PSA** function based on ARM Cortex-M series(M23, M33, M35P, M55). ARMv8-M provides secure functions such as TEE(Trusted Execution Environment), Secure Key Storage, Secure Firmware Update, and Crypto Accelerator.
- [PSA Technology](https://www.arm.com/why-arm/technologies/trustzone-for-cortex-m)
- [ARMv8-M FreeRTOS Demo](https://www.freertos.org/RTOS-Cortex-M23-NuMaker-PFM-M2351-Keil.html#SourceCodeOrg)

## Architecture
<img title="Architecture" alt="PX4-Trust" src="https://github.com/korkeep/PX4-Trust/blob/main/Architecture/PX4-Trust.png" width="1000"/>

### Secure State
**Secure State** is a TEE that can protect from unauthorized external access by using the ARM PSA technique. Components of **Secure State** include Trusted Firmware, Input Validation System, PSA Services, and PSA Development API.
- **Trusted Firmware**: Trusted Firmware provides a software package to build a TEE. Trusted Firmware is the basis for utilizing the ARM PSA function.
- **PSA Services**: PSA Services are security function that can be applied to the drone system. Functions provided by PSA Services include Key Management, Cryptography, Secure Boot, Secure Storage, Secure Firmware Update, and Attestation.
- **Input Validation System**: Logs are monitored to validate inputs. It notifies the user when the log is different from the normal case.
- **PSA Development API**: PSA Development API allows applications in the Non-Secure State to access assets in the Secure State.

### Non-Secure State
**Non-Secure State** is a REE(Rich Execution Environment) in which drone applications, middleware, operating systems, and drivers operate. Components of **Non-Secure State** include Drivers, RTOS, Middleware, and Flight Control.  
- **Drivers**: A driver provides software interface to hardware devices. There are IMU, RC, GPS, Telemetry Radio, Distance and Barometer drivers representatively.
- **RTOS**: An operating system focused on real-time application management. NuttX does this role in PX4.
- **Middleware**: Software that acts as a request broker between RTOS and Flight Control. uORB does this role in PX4.
- **Flight Control**: It shows the main modules that control drone flight and the flow of data processed by the drone system. First, a command from the user is received from the Commander, and data is transferred in the order of Estimator, Navigator, and Controller.

### Trusted Hardware
**Trusted Hardware** is a hardware module necessary to utilize the security functions provided by Secure State. Components of **Trusted Hardware** include High-Entropy RNG, Crypto Accelerator, and OTP Memory.
- **High-Entropy RNG**: High-Entropy RNG(Random Number Generator) generates random numbers with high entropy as hardware. Random numbers are used in the encryption process and have higher reliability than PRNG(Pseudo RNG).
- **Crypto Accelerator**: Crypto Accelerator is hardware that performs key generation, encryption, and decryption, and supports various encryption algorithms such as AES, ECDSA, RSA, and SHA. Crypto Accelerator can encrypt and store data in Secure Flash for data confidentiality.
- **OTP Memory**: OTP(One Time Programmable) memory is non-volatile and cannot be rewritten. Provisioned Data was provided when manufacturing SoC devices, Device Unique Key is used in the encryption process.


## References
- [PX4 NuttX Github](https://github.com/PX4/NuttX)
- [PX4 Bootloader Github](https://github.com/PX4/PX4-Bootloader)
- [NuttX Porting Guide](https://cwiki.apache.org/confluence/display/NUTTX/Porting+Guide)
- [Bootloader Porting Guide](https://docs.px4.io/master/en/software_update/stm32_bootloader.html)
- [Flight Controller Porting Guide](https://hamishwillee.gitbooks.io/havdevguide/content/en/hardware/porting_guide_nuttx.html)
- [STM32-Trust](https://www.st.com/content/st_com/en/ecosystems/stm32trust.html)
- [STM32CubeL5 Examples](https://github.com/STMicroelectronics/STM32CubeL5)
- [M2351BSP Examples](https://github.com/OpenNuvoton/M2351BSP)
