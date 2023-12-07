################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Drivers/BSP/P-NUCLEO-WB55.USBDongle/stm32wbxx_usb_dongle.c 

OBJS += \
./Drivers/BSP/P-NUCLEO-WB55.USBDongle/stm32wbxx_usb_dongle.o 

C_DEPS += \
./Drivers/BSP/P-NUCLEO-WB55.USBDongle/stm32wbxx_usb_dongle.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/P-NUCLEO-WB55.USBDongle/stm32wbxx_usb_dongle.o: C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Drivers/BSP/P-NUCLEO-WB55.USBDongle/stm32wbxx_usb_dongle.c Drivers/BSP/P-NUCLEO-WB55.USBDongle/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_USB_DONGLE -DCORE_CM4 -DDEBUG -DSTM32WB55xx -c -I../../Core/Inc -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../../../../../../../Utilities/sequencer -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/vcp -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../../STM32_WPAN/App -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/core -I../../../../../../../Middlewares/ST/STM32_WPAN -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/core/template -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/core/auto -I../../../../../../../Drivers/BSP/P-NUCLEO-WB55.USBDongle -I../../../../../../../Middlewares/ST/STM32_WPAN/utilities -I../../../../../../../Middlewares/ST/STM32_WPAN/ble -I../../../../../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/P-NUCLEO-WB55.USBDongle/stm32wbxx_usb_dongle.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-P-2d-NUCLEO-2d-WB55-2e-USBDongle

clean-Drivers-2f-BSP-2f-P-2d-NUCLEO-2d-WB55-2e-USBDongle:
	-$(RM) ./Drivers/BSP/P-NUCLEO-WB55.USBDongle/stm32wbxx_usb_dongle.d ./Drivers/BSP/P-NUCLEO-WB55.USBDongle/stm32wbxx_usb_dongle.o ./Drivers/BSP/P-NUCLEO-WB55.USBDongle/stm32wbxx_usb_dongle.su

.PHONY: clean-Drivers-2f-BSP-2f-P-2d-NUCLEO-2d-WB55-2e-USBDongle

