#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/tirtos_msp43x_2_16_00_08/packages;C:/ti/tirtos_msp43x_2_16_00_08/products/bios_6_45_01_29/packages;C:/ti/tirtos_msp43x_2_16_00_08/products/tidrivers_msp43x_2_16_00_08/packages;C:/ti/tirtos_msp43x_2_16_00_08/products/uia_2_00_05_50/packages;C:/ti/msp/MSPWare_3_10_00_75/driverlib/packages;C:/ti/msp/MSPWare_3_10_00_75/driverlib;C:/ti/ccsv6/ccs_base;C:/Users/braly/workspace_v6_1/ChallengeAssignmentThree/.config
override XDCROOT = C:/ti/xdctools_3_31_01_33_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/tirtos_msp43x_2_16_00_08/packages;C:/ti/tirtos_msp43x_2_16_00_08/products/bios_6_45_01_29/packages;C:/ti/tirtos_msp43x_2_16_00_08/products/tidrivers_msp43x_2_16_00_08/packages;C:/ti/tirtos_msp43x_2_16_00_08/products/uia_2_00_05_50/packages;C:/ti/msp/MSPWare_3_10_00_75/driverlib/packages;C:/ti/msp/MSPWare_3_10_00_75/driverlib;C:/ti/ccsv6/ccs_base;C:/Users/braly/workspace_v6_1/ChallengeAssignmentThree/.config;C:/ti/xdctools_3_31_01_33_core/packages;..
HOSTOS = Windows
endif
