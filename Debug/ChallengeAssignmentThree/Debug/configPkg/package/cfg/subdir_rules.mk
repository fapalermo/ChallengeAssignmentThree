################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
ChallengeAssignmentThree/Debug/configPkg/package/cfg/empty_pem4f.obj: ../ChallengeAssignmentThree/Debug/configPkg/package/cfg/empty_pem4f.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/ccsv6/ccs_base/arm/include" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignmentThree/LcdDriver" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignmentThree/GrLib/fonts}" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignmentThree/GrLib/grlib" --include_path="C:/ti/ccsv6/ccs_base/arm/include/CMSIS" --include_path="C:/ccsv6_workshop/msp432/workspace/ChallengeAssignmentThree" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc/CMSIS" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/inc" --include_path="C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="ChallengeAssignmentThree/Debug/configPkg/package/cfg/empty_pem4f.pp" --obj_directory="ChallengeAssignmentThree/Debug/configPkg/package/cfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


