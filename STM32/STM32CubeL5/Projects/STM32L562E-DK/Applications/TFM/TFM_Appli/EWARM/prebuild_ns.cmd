iccarm.exe --cpu=Cortex-M33 -DBL2 -DTFM_PSA_API -I%1\..\..\Linker  %1\stm32l562xx_flash_ns.icf  --silent --preprocess=ns %1\stm32l562xx_flash_ns.icf.i > %1\output.txt 2>&1