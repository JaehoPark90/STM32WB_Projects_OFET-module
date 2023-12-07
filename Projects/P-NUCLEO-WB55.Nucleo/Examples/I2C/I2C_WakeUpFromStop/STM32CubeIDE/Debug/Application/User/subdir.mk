################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Projects/P-NUCLEO-WB55.Nucleo/Examples/I2C/I2C_WakeUpFromStop/Src/main.c \
C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Projects/P-NUCLEO-WB55.Nucleo/Examples/I2C/I2C_WakeUpFromStop/Src/stm32wbxx_hal_msp.c \
C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Projects/P-NUCLEO-WB55.Nucleo/Examples/I2C/I2C_WakeUpFromStop/Src/stm32wbxx_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c 

OBJS += \
./Application/User/main.o \
./Application/User/stm32wbxx_hal_msp.o \
./Application/User/stm32wbxx_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/stm32wbxx_hal_msp.d \
./Application/User/stm32wbxx_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Projects/P-NUCLEO-WB55.Nucleo/Examples/I2C/I2C_WakeUpFromStop/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32WB55xx -c -I../../Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/P-NUCLEO-WB55.Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32wbxx_hal_msp.o: C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Projects/P-NUCLEO-WB55.Nucleo/Examples/I2C/I2C_WakeUpFromStop/Src/stm32wbxx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32WB55xx -c -I../../Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/P-NUCLEO-WB55.Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32wbxx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32wbxx_it.o: C:/Users/Jaeho\ Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Projects/P-NUCLEO-WB55.Nucleo/Examples/I2C/I2C_WakeUpFromStop/Src/stm32wbxx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32WB55xx -c -I../../Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/P-NUCLEO-WB55.Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Application/User/stm32wbxx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o Application/User/%.su: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32WB55xx -c -I../../Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/P-NUCLEO-WB55.Nucleo -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/stm32wbxx_hal_msp.d ./Application/User/stm32wbxx_hal_msp.o ./Application/User/stm32wbxx_hal_msp.su ./Application/User/stm32wbxx_it.d ./Application/User/stm32wbxx_it.o ./Application/User/stm32wbxx_it.su ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su

.PHONY: clean-Application-2f-User

