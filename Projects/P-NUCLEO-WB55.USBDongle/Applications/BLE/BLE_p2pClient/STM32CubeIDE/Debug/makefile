################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utilities/subdir.mk
-include Middlewares/STM32_WPAN/utilities/subdir.mk
-include Middlewares/STM32_WPAN/interface/patterns/ble_thread/vcp/subdir.mk
-include Middlewares/STM32_WPAN/interface/patterns/ble_thread/tl/subdir.mk
-include Middlewares/STM32_WPAN/interface/patterns/ble_thread/shci/subdir.mk
-include Middlewares/STM32_WPAN/ble/core/subdir.mk
-include Middlewares/STM32_WPAN/ble/blesvc/subdir.mk
-include Middlewares/STM32_USB_Device_Library/subdir.mk
-include Drivers/STM32WBxx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/P-NUCLEO-WB55.USBDongle/subdir.mk
-include Application/Startup/subdir.mk
-include Application/STM32_WPAN/target/subdir.mk
-include Application/STM32_WPAN/app/subdir.mk
-include Application/Core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := BLE_p2pClient
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
BLE_p2pClient.elf \

MAP_FILES += \
BLE_p2pClient.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
BLE_p2pClient.list \

OBJCOPY_HEX += \
BLE_p2pClient.hex \


# All Target
all: main-build

# Main-build Target
main-build: BLE_p2pClient.elf secondary-outputs

# Tool invocations
BLE_p2pClient.elf BLE_p2pClient.map: $(OBJS) $(USER_OBJS) C:\Users\Jaeho\ Park\Downloads\STM32CubeWB-master_new\STM32CubeWB-master\Projects\P-NUCLEO-WB55.USBDongle\Applications\BLE\BLE_p2pClient\STM32CubeIDE\STM32WB55CGUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "BLE_p2pClient.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Jaeho Park\Downloads\STM32CubeWB-master_new\STM32CubeWB-master\Projects\P-NUCLEO-WB55.USBDongle\Applications\BLE\BLE_p2pClient\STM32CubeIDE\STM32WB55CGUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="BLE_p2pClient.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

BLE_p2pClient.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "BLE_p2pClient.list"
	@echo 'Finished building: $@'
	@echo ' '

BLE_p2pClient.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "BLE_p2pClient.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) BLE_p2pClient.elf BLE_p2pClient.hex BLE_p2pClient.list BLE_p2pClient.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
