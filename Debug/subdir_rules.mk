################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
MSP_EXP432P401R.obj: ../MSP_EXP432P401R.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/ccsv6/ccs_base/arm/include" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/LcdDriver" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/GrLib/grlib" --include_path="C:/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="MSP_EXP432P401R.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

adc14.obj: ../adc14.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/ccsv6/ccs_base/arm/include" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/LcdDriver" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/GrLib/grlib" --include_path="C:/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="adc14.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

button.obj: ../button.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/ccsv6/ccs_base/arm/include" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/LcdDriver" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/GrLib/grlib" --include_path="C:/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="button.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

clock.obj: ../clock.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/ccsv6/ccs_base/arm/include" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/LcdDriver" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/GrLib/grlib" --include_path="C:/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="clock.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

empty.obj: ../empty.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/ccsv6/ccs_base/arm/include" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/LcdDriver" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/GrLib/grlib" --include_path="C:/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="empty.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: ../empty.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_31_01_33_core/xs" --xdcpath="C:/ti/tirtos_msp43x_2_16_00_08/packages;C:/ti/tirtos_msp43x_2_16_00_08/products/bios_6_45_01_29/packages;C:/ti/tirtos_msp43x_2_16_00_08/products/tidrivers_msp43x_2_16_00_08/packages;C:/ti/tirtos_msp43x_2_16_00_08/products/uia_2_00_05_50/packages;C:/ti/msp/MSPWare_3_10_00_75/driverlib/packages;C:/ti/msp/MSPWare_3_10_00_75/driverlib;C:/ti/ccsv6/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.msp432:MSP432P401R -r release -c "C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5" --compileOptions "-mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path=\"C:/ti/ccsv6/ccs_base/arm/include\" --include_path=\"C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/LcdDriver\" --include_path=\"C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/GrLib/grlib\" --include_path=\"C:/ti/ccsv6/ccs_base/arm/include/CMSIS\" --include_path=\"C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3\" --include_path=\"C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS\" --include_path=\"C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc\" --include_path=\"C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx\" --include_path=\"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include\" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on  " "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd

gfx.obj: ../gfx.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/ccsv6/ccs_base/arm/include" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/LcdDriver" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/GrLib/grlib" --include_path="C:/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="gfx.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uartTransmission.obj: ../uartTransmission.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/ccsv6/ccs_base/arm/include" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/LcdDriver" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3/GrLib/grlib" --include_path="C:/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignment3" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="uartTransmission.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


