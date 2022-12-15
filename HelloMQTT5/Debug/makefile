################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /Users/matteo/Library/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./json/package/package_ti.utils.json.o" \
"./HelloMQTT5.o" \
"./main.o" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-Wl,-T"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/energia/linker.cmd" \
-lmsp432r_MSP-EXP432P401R_MQTTClient \
-lmsp432r_MSP-EXP432P401R_WiFi \
-lmsp432r_MSP-EXP432P401R_core \
-l:msp432p4xx_driverlib.a \
-lstdc++ \
-lgcc \
-lm \
-lnosys \
-lc \
-Wl,--end-group \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include json/lib/ccs/m4f/subdir_vars.mk
-include json/lib/gcc/m4f/subdir_vars.mk
-include json/lib/iar/m4f/subdir_vars.mk
-include json/package/subdir_vars.mk
-include subdir_rules.mk
-include json/lib/ccs/m4f/subdir_rules.mk
-include json/lib/gcc/m4f/subdir_rules.mk
-include json/lib/iar/m4f/subdir_rules.mk
-include json/package/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
HelloMQTT5.out \

EXE_OUTPUTS__QUOTED += \
"HelloMQTT5.out" \

BIN_OUTPUTS += \
HelloMQTT5.bin \

BIN_OUTPUTS__QUOTED += \
"HelloMQTT5.bin" \


# All Target
all: $(OBJS) $(A_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "HelloMQTT5.out" secondary-outputs

dependents:
	-cd /Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_core/Debug && $(MAKE) all
	-cd /Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_WiFi/Debug && $(MAKE) all
	-cd /Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_MQTTClient/Debug && $(MAKE) all

# Tool invocations
HelloMQTT5.out: $(OBJS) $(A_SRCS) $(GEN_CMDS) /Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_core/Debug/libmsp432r_MSP-EXP432P401R_core.a /Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_WiFi/Debug/libmsp432r_MSP-EXP432P401R_WiFi.a /Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_MQTTClient/Debug/libmsp432r_MSP-EXP432P401R_MQTTClient.a
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"/Users/matteo/Library/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620/bin/arm-none-eabi-gcc-6.3.1" -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_target_name__=M4F -Dxdc_cfg__xheader__=\"configPkg/package/cfg/energia_pm4fg.h\" -DBOARD_MSP_EXP432P401R -Dxdc__nolocalstring=1 -D__MSP432P401R__ -DCORE_VERSION=5251 -DF_CPU=48000000L -DENERGIA_MSP_EXP432P401R -DENERGIA_ARCH_MSP432R -D_DEFAULT_SOURCE -DENERGIA=21 -DARDUINO=10610 -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -w -Wall -mabi=aapcs -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,-Map,"HelloMQTT5.map" -nostartfiles -Wl,--gc-sections -L"/Users/matteo/workspace_v10/HelloMQTT5/json" -L"/Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_MQTTClient/Debug" -L"/Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_WiFi/Debug" -L"/Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_core/Debug" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/kernel/tirtos/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/thumb/v7e-m/fpv4-sp/hard" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/cores/msp432r" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/energia" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/kernel" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/source" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/kernel/tirtos/builds/MSP_EXP432P401R/energia/" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/kernel/tirtos/packages" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/cores/msp432r/ti/runtime/wiring/msp432" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/cores/msp432r/ti/runtime/wiring/msp432/variants/MSP_EXP432P401R" -L"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/source/ti/devices/msp432p4xx/driverlib/gcc" -Wl,--undefined,main -Wl,--undefined,_printf_float -Wl,--undefined,_scanf_float -Os -specs=nano.specs -specs=rdimon.specs -specs=nosys.specs -Wl,--check-sections -o"HelloMQTT5.out" $(ORDERED_OBJS) $(A_SRCS)
	@echo 'Finished building target: "$@"'
	@echo ' '

HelloMQTT5.bin: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: GNU Objcopy Utility'
	"/Users/matteo/Library/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620/bin/arm-none-eabi-objcopy" -O binary $(EXE_OUTPUTS__QUOTED) "HelloMQTT5.bin"
	@echo 'Finished building secondary target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "HelloMQTT5.o" "main.o" "json/package/package_ti.utils.json.o" 
	-$(RM) "json/package/package_ti.utils.json.d" 
	-$(RM) "HelloMQTT5.d" "main.d" 
	-@echo 'Finished clean'
	-@echo ' '

secondary-outputs: $(BIN_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:
/Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_core/Debug/libmsp432r_MSP-EXP432P401R_core.a:
/Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_WiFi/Debug/libmsp432r_MSP-EXP432P401R_WiFi.a:
/Users/matteo/workspace_v10/msp432r_MSP-EXP432P401R_MQTTClient/Debug/libmsp432r_MSP-EXP432P401R_MQTTClient.a:

-include ../makefile.targets

