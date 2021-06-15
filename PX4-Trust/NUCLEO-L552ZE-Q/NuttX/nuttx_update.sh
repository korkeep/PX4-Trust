#!/bin/bash - 
echo "Nuttx Update Started"
# Absolute path to this script
SCRIPT=$(readlink -f $0)
# Absolute path this script
SCRIPTPATH=`dirname $SCRIPT`
PATH="/C/Program Files/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/":$PATH
stm32programmercli="STM32_Programmer_CLI"
connect_no_reset="-c port=SWD mode=UR"
connect="-c port=SWD mode=UR --hardRst"

slot1=0x08000000
image_number=1

# Sungsu Added
if [ $image_number == 1 ]; then
echo "Write NuttX"
#$stm32programmercli $connect -d $SCRIPTPATH/nuttx.bin $slot1 -v
$stm32programmercli $connect -d $SCRIPTPATH/nuttx.bin $slot1 -v
ret=$?
# if [ $ret != 0 ]; then
#   if [ "$1" != "AUTO" ]; then read -p "SBSFU_UPDATE script failed, press a key" -n1 -s; fi
#   exit 1
# fi
echo "NuttX Written"
fi