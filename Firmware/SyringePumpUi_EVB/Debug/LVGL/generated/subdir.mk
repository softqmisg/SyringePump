################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/generated/events_init.c \
../LVGL/generated/gui_guider.c \
../LVGL/generated/setup_scr_InitScreen.c \
../LVGL/generated/setup_scr_MainScreen.c \
../LVGL/generated/setup_scr_SettingScreen.c \
../LVGL/generated/widgets_init.c 

OBJS += \
./LVGL/generated/events_init.o \
./LVGL/generated/gui_guider.o \
./LVGL/generated/setup_scr_InitScreen.o \
./LVGL/generated/setup_scr_MainScreen.o \
./LVGL/generated/setup_scr_SettingScreen.o \
./LVGL/generated/widgets_init.o 

C_DEPS += \
./LVGL/generated/events_init.d \
./LVGL/generated/gui_guider.d \
./LVGL/generated/setup_scr_InitScreen.d \
./LVGL/generated/setup_scr_MainScreen.d \
./LVGL/generated/setup_scr_SettingScreen.d \
./LVGL/generated/widgets_init.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/generated/%.o LVGL/generated/%.su LVGL/generated/%.cyclo: ../LVGL/generated/%.c LVGL/generated/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/generated" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-generated

clean-LVGL-2f-generated:
	-$(RM) ./LVGL/generated/events_init.cyclo ./LVGL/generated/events_init.d ./LVGL/generated/events_init.o ./LVGL/generated/events_init.su ./LVGL/generated/gui_guider.cyclo ./LVGL/generated/gui_guider.d ./LVGL/generated/gui_guider.o ./LVGL/generated/gui_guider.su ./LVGL/generated/setup_scr_InitScreen.cyclo ./LVGL/generated/setup_scr_InitScreen.d ./LVGL/generated/setup_scr_InitScreen.o ./LVGL/generated/setup_scr_InitScreen.su ./LVGL/generated/setup_scr_MainScreen.cyclo ./LVGL/generated/setup_scr_MainScreen.d ./LVGL/generated/setup_scr_MainScreen.o ./LVGL/generated/setup_scr_MainScreen.su ./LVGL/generated/setup_scr_SettingScreen.cyclo ./LVGL/generated/setup_scr_SettingScreen.d ./LVGL/generated/setup_scr_SettingScreen.o ./LVGL/generated/setup_scr_SettingScreen.su ./LVGL/generated/widgets_init.cyclo ./LVGL/generated/widgets_init.d ./LVGL/generated/widgets_init.o ./LVGL/generated/widgets_init.su

.PHONY: clean-LVGL-2f-generated

