################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci/shci.c 

OBJS += \
./Middlewares/STM32_WPAN/interface/patterns/ble_thread/shci/shci.o 

C_DEPS += \
./Middlewares/STM32_WPAN/interface/patterns/ble_thread/shci/shci.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STM32_WPAN/interface/patterns/ble_thread/shci/shci.o: C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci/shci.c Middlewares/STM32_WPAN/interface/patterns/ble_thread/shci/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_USB_DONGLE -DCORE_CM4 -DDEBUG -DSTM32WB55xx -c -I../../Core/Inc -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../../../../../../../Utilities/sequencer -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/vcp -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../../STM32_WPAN/App -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/core -I../../../../../../../Middlewares/ST/STM32_WPAN -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/core/template -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/core/auto -I../../../../../../../Drivers/BSP/P-NUCLEO-WB55.USBDongle -I../../../../../../../Middlewares/ST/STM32_WPAN/utilities -I../../../../../../../Middlewares/ST/STM32_WPAN/ble -I../../../../../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/STM32_WPAN/interface/patterns/ble_thread/shci/shci.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-STM32_WPAN-2f-interface-2f-patterns-2f-ble_thread-2f-shci

clean-Middlewares-2f-STM32_WPAN-2f-interface-2f-patterns-2f-ble_thread-2f-shci:
	-$(RM) ./Middlewares/STM32_WPAN/interface/patterns/ble_thread/shci/shci.d ./Middlewares/STM32_WPAN/interface/patterns/ble_thread/shci/shci.o ./Middlewares/STM32_WPAN/interface/patterns/ble_thread/shci/shci.su

.PHONY: clean-Middlewares-2f-STM32_WPAN-2f-interface-2f-patterns-2f-ble_thread-2f-shci

