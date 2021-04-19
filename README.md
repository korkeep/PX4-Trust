# PX4-TrustZone
The PX4-TrustZone project proposes an architecture that can protect core-assets of the drone system, such as private key, user data, and security functions, by utilizing the ARM TrustZone function. 🚁🔐  

## PX4
<img title="Architecture" alt="PX4" src="https://github.com/korkeep/PX4-TrustZone/raw/main/Architecture/PX4.png" width="500"/>  

PX4 Autopilot is an open-source autopilot system for Unmanned Aerial Vehicle. PX4 Autopilot guarantees scalability so that the PX4 ecosystem can be maintained by providing a standard for drone hardware and software.  
- [PX4 Github](https://github.com/PX4/PX4-Autopilot)
- [PX4 Autopilot](https://docs.px4.io/master/en/)
- [QGroundControl](http://qgroundcontrol.com/)
- [MAVLink Protocol](https://mavlink.io/en/)

## ARM TrustZone
ARM TrustZone was introduced to protect key assets of the system such as private keys, user data, and security functions from unauthorized external access. ARM TrustZone is a mechanism that guarantees the separation of the execution environment by dividing memory, peripheral devices, and functions into secure and non-secure areas. ARMv8-M is a processor model that can utilize ARM TrustZone function based on ARM Cortex-M series(M23, M33, M35P, M55). ARMv8-M provides secure functions such as TEE(Trusted Execution Environment), Secure Key Storage, Secure Firmware Update, and Crypto Accelerator.
- [TrustZone Technology](https://www.arm.com/why-arm/technologies/trustzone-for-cortex-m)
- [ARMv8-M FreeRTOS Demo](https://www.freertos.org/RTOS-Cortex-M23-NuMaker-PFM-M2351-Keil.html#SourceCodeOrg)

## Architecture
<img title="Architecture" alt="PX4-TrustZone" src="https://github.com/korkeep/PX4-TrustZone/raw/main/Architecture/PX4-TrustZone.PNG" width="800"/>

### Secure State
Secure State is a TEE that can protect from unauthorized external access by using the ARM TrustZone technique. Components of Secure State include TF-M Core, S-Driver, Flight Control IDS, PSA Services, and PSA Development API.

### Non-Secure State
Non-Secure State is a REE(Rich Execution Environment) in which drone applications, middleware, operating systems, and drivers operate. Components of Non-Secure State include NS-Driver, RTOS, Middleware, and Flight Control.  

### High-Entropy RNG
High-Entropy RNG(Random Number Generator) generates random numbers with high entropy as hardware. Random numbers are used in the encryption process and have higher reliability than PRNG(Pseudo RNG).  

### Crypto Accelerator
Crypto Accelerator is hardware that performs key generation, encryption, and decryption, and supports various encryption algorithms such as AES, ECDSA, RSA, and SHA. Crypto Accelerator can encrypt and store data in Secure Flash for data confidentiality.  

### OTP Memory
OTP(One Time Programmable) memory is non-volatile and cannot be rewritten. Provisioned Data was provided when manufacturing SoC devices, Device Unique Key is used in the encryption process.  

## References
- [NuttX Github](https://github.com/PX4/NuttX)
- [NuttX Porting Guide](https://cwiki.apache.org/confluence/display/NUTTX/Porting+Guide)
- [M2351BSP Examples](https://github.com/OpenNuvoton/M2351BSP)
- [STM32 Bootloader](https://docs.px4.io/master/en/software_update/stm32_bootloader.html)
- [STM32Trust](https://www.st.com/content/st_com/en/ecosystems/stm32trust.html)
- [STM32CubeL5 Examples](https://github.com/STMicroelectronics/STM32CubeL5)
