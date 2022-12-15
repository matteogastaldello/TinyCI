################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
build-683118577:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-683118577-inproc

build-683118577-inproc: ../HelloMQTT5.ino
	@echo 'Building file: "$<"'
	@echo 'Invoking: Resource Custom Build Step'
	
	@echo 'Finished building: "$<"'
	@echo ' '

HelloMQTT5.cpp: build-683118577 ../HelloMQTT5.ino
main.cpp: build-683118577

%.o: ./%.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/Users/matteo/Library/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620/bin/arm-none-eabi-gcc-6.3.1" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_target_name__=M4F -Dxdc_cfg__xheader__=\"configPkg/package/cfg/energia_pm4fg.h\" -DBOARD_MSP_EXP432P401R -Dxdc__nolocalstring=1 -D__MSP432P401R__ -DCORE_VERSION=5251 -DF_CPU=48000000L -DENERGIA_MSP_EXP432P401R -DENERGIA_ARCH_MSP432R -D_DEFAULT_SOURCE -DENERGIA=21 -DARDUINO=10610 -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/cores/msp432r/ti/runtime/wiring/" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/cores/msp432r/ti/runtime/wiring/msp432" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/kernel/tirtos/packages/ti/sysbios/posix" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/kernel/tirtos/packages" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/source" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/energia" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/source/ti/devices/msp432p4xx/driverlib" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/source/ti/devices/msp432p4xx/inc" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/source/ti/devices/msp432p4xx/" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/system/source/third_party/CMSIS/Include" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/cores/msp432r" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/variants/MSP_EXP432P401R" -I"/Users/matteo/workspace_v10/HelloMQTT5" -I"/Users/matteo/Library/Energia15/packages/energia/hardware/msp432r/5.25.1/libraries/WiFi" -I"/Applications/Energia.app/Contents/Java/libraries/MQTTClient" -I"/Users/matteo/Library/Energia15/packages/energia/tools/arm-none-eabi-gcc/6.3.1-20170620/arm-none-eabi/include" -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -w -Wall -mabi=aapcs -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  -fno-rtti -fno-threadsafe-statics -fno-exceptions $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

