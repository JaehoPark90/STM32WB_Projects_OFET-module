################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Drivers/BSP/P-NUCLEO-WB55.Nucleo/stm32wbxx_nucleo.c 

OBJS += \
./Drivers/BSP/P-NUCLEO-WB55.Nucleo/stm32wbxx_nucleo.o 

C_DEPS += \
./Drivers/BSP/P-NUCLEO-WB55.Nucleo/stm32wbxx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/P-NUCLEO-WB55.Nucleo/stm32wbxx_nucleo.o: C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Drivers/BSP/P-NUCLEO-WB55.Nucleo/stm32wbxx_nucleo.c Drivers/BSP/P-NUCLEO-WB55.Nucleo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32WB55xx -c -I../../Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/P-NUCLEO-WB55.Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/P-NUCLEO-WB55.Nucleo/stm32wbxx_nucleo.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-P-2d-NUCLEO-2d-WB55-2e-Nucleo

clean-Drivers-2f-BSP-2f-P-2d-NUCLEO-2d-WB55-2e-Nucleo:
	-$(RM) ./Drivers/BSP/P-NUCLEO-WB55.Nucleo/stm32wbxx_nucleo.d ./Drivers/BSP/P-NUCLEO-WB55.Nucleo/stm32wbxx_nucleo.o ./Drivers/BSP/P-NUCLEO-WB55.Nucleo/stm32wbxx_nucleo.su

.PHONY: clean-Drivers-2f-BSP-2f-P-2d-NUCLEO-2d-WB55-2e-Nucleo

