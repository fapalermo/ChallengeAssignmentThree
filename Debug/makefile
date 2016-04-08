################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5

GEN_OPTS__FLAG := --cmd_file="configPkg/compiler.opt"
GEN_CMDS__FLAG := -l"configPkg/linker.cmd"

ORDERED_OBJS += \
"./MSP_EXP432P401R.obj" \
"./clock.obj" \
"./empty.obj" \
"./gfx.obj" \
"./uartTransmission.obj" \
"./LcdDriver/Crystalfontz128x128_ST7735.obj" \
"./LcdDriver/HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.obj" \
"./GrLib/grlib/button.obj" \
"./GrLib/grlib/checkbox.obj" \
"./GrLib/grlib/circle.obj" \
"./GrLib/grlib/context.obj" \
"./GrLib/grlib/display.obj" \
"./GrLib/grlib/image.obj" \
"./GrLib/grlib/imageButton.obj" \
"./GrLib/grlib/line.obj" \
"./GrLib/grlib/radioButton.obj" \
"./GrLib/grlib/rectangle.obj" \
"./GrLib/grlib/string.obj" \
"./GrLib/fonts/fontfixed6x8.obj" \
"../MSP_EXP432P401R.cmd" \
$(GEN_CMDS__FLAG) \
-l"C:/ti/tirtos_msp43x_2_16_00_08/products/msp432_driverlib_3_10_00_09/driverlib/MSP432P4xx/ccs/msp432p4xx_driverlib.lib" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include LcdDriver/subdir_vars.mk
-include GrLib/grlib/subdir_vars.mk
-include GrLib/fonts/subdir_vars.mk
-include subdir_rules.mk
-include LcdDriver/subdir_rules.mk
-include GrLib/grlib/subdir_rules.mk
-include GrLib/fonts/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
ChallengeAssignment3.out \

EXE_OUTPUTS__QUOTED += \
"ChallengeAssignment3.out" \

BIN_OUTPUTS += \
ChallengeAssignment3.hex \

BIN_OUTPUTS__QUOTED += \
"ChallengeAssignment3.hex" \


# All Target
all: ChallengeAssignment3.out

# Tool invocations
ChallengeAssignment3.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP432 Linker'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --advice:power_severity=suppress --advice:power=all -g --gcc --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE --diag_wrap=off --diag_warning=225 --diag_warning=255 --display_error_number --gen_func_subsections=on -z -m"ChallengeAssignment3.map" --heap_size=1024 --stack_size=512 -i"C:/ti/ccsv6/ccs_base/arm/include" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/lib" -i"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/include" --reread_libs --display_error_number --diag_wrap=off --warn_sections --xml_link_info="ChallengeAssignment3_linkInfo.xml" --rom_model -o "ChallengeAssignment3.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

ChallengeAssignment3.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP432 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.5/bin/armhex"  -o "ChallengeAssignment3.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_OPTS__QUOTED)$(GEN_CMDS__QUOTED)
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-$(RM) "MSP_EXP432P401R.pp" "clock.pp" "empty.pp" "gfx.pp" "uartTransmission.pp" "LcdDriver\Crystalfontz128x128_ST7735.pp" "LcdDriver\HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.pp" "GrLib\grlib\button.pp" "GrLib\grlib\checkbox.pp" "GrLib\grlib\circle.pp" "GrLib\grlib\context.pp" "GrLib\grlib\display.pp" "GrLib\grlib\image.pp" "GrLib\grlib\imageButton.pp" "GrLib\grlib\line.pp" "GrLib\grlib\radioButton.pp" "GrLib\grlib\rectangle.pp" "GrLib\grlib\string.pp" "GrLib\fonts\fontfixed6x8.pp" 
	-$(RM) "MSP_EXP432P401R.obj" "clock.obj" "empty.obj" "gfx.obj" "uartTransmission.obj" "LcdDriver\Crystalfontz128x128_ST7735.obj" "LcdDriver\HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.obj" "GrLib\grlib\button.obj" "GrLib\grlib\checkbox.obj" "GrLib\grlib\circle.obj" "GrLib\grlib\context.obj" "GrLib\grlib\display.obj" "GrLib\grlib\image.obj" "GrLib\grlib\imageButton.obj" "GrLib\grlib\line.obj" "GrLib\grlib\radioButton.obj" "GrLib\grlib\rectangle.obj" "GrLib\grlib\string.obj" "GrLib\fonts\fontfixed6x8.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

