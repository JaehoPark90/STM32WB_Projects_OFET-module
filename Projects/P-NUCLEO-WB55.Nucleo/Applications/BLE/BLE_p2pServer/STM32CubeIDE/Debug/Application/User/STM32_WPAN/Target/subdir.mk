################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Jaeho\ Park/Documents/GitHub/STM32WB_Projects_OFET-module/Projects/P-NUCLEO-WB55.Nucleo/Applications/BLE/BLE_p2pServer/STM32_WPAN/Target/hw_ipcc.c 

OBJS += \
./Application/User/STM32_WPAN/Target/hw_ipcc.o 

C_DEPS += \
./Application/User/STM32_WPAN/Target/hw_ipcc.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/STM32_WPAN/Target/hw_ipcc.o: C:/Users/Jaeho\ Park/Documents/GitHub/STM32WB_Projects_OFET-module/Projects/P-NUCLEO-WB55.Nucleo/Applications/BLE/BLE_p2pServer/STM32_WPAN/Target/hw_ipcc.c Application/User/STM32_WPAN/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_NUCLEO -DDEBUG -DSTM32WB55xx -c -I../../Core/Inc -I"C:/Users/Jaeho Park/Downloads/STM32CubeWB-master_new/STM32CubeWB-master/Drivers/CMSIS" -I../../STM32_WPAN/App -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32WBxx_HAL_Driver/Inc/Legacy -I../../../../../../../Utilities/lpm/tiny_lpm -I../../../../../../../Middlewares/ST/STM32_WPAN -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl -I../../../../../../../Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci -I../../../../../../../Middlewares/ST/STM32_WPAN/utilities -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/core -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/core/auto -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/core/template -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/svc/Inc -I../../../../../../../Middlewares/ST/STM32_WPAN/ble/svc/Src -I../../../../../../../Drivers/CMSIS/Device/ST/STM32WBxx/Include -I../../../../../../../Utilities/sequencer -I../../../../../../../Middlewares/ST/STM32_WPAN/ble -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/BSP/P-NUCLEO-WB55.Nucleo -I../../tiny_lpm -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Drivers/STM32WBxx_HAL_Driver/Inc" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Utilities/lpm/tiny_lpm" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/utilities" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/ble/core" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/ble/core/auto" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/ble/svc/Inc" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/ble/svc/Src" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Drivers/CMSIS/Device/ST/STM32WBxx/Include" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Utilities/sequencer" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Middlewares/ST/STM32_WPAN/ble" -I"C:/Users/Jaeho Park/STM32Cube/Repository/STM32Cube_FW_WB_V1.14.1/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Application/User/STM32_WPAN/Target/hw_ipcc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-STM32_WPAN-2f-Target

clean-Application-2f-User-2f-STM32_WPAN-2f-Target:
	-$(RM) ./Application/User/STM32_WPAN/Target/hw_ipcc.cyclo ./Application/User/STM32_WPAN/Target/hw_ipcc.d ./Application/User/STM32_WPAN/Target/hw_ipcc.o ./Application/User/STM32_WPAN/Target/hw_ipcc.su

.PHONY: clean-Application-2f-User-2f-STM32_WPAN-2f-Target

