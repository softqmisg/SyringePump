################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Lvgl_Ui/generated/events_init.c \
../Core/Src/Lvgl_Ui/generated/gui_guider.c \
../Core/Src/Lvgl_Ui/generated/setup_scr_MainScreen.c \
../Core/Src/Lvgl_Ui/generated/widgets_init.c 

OBJS += \
./Core/Src/Lvgl_Ui/generated/events_init.o \
./Core/Src/Lvgl_Ui/generated/gui_guider.o \
./Core/Src/Lvgl_Ui/generated/setup_scr_MainScreen.o \
./Core/Src/Lvgl_Ui/generated/widgets_init.o 

C_DEPS += \
./Core/Src/Lvgl_Ui/generated/events_init.d \
./Core/Src/Lvgl_Ui/generated/gui_guider.d \
./Core/Src/Lvgl_Ui/generated/setup_scr_MainScreen.d \
./Core/Src/Lvgl_Ui/generated/widgets_init.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Lvgl_Ui/generated/%.o Core/Src/Lvgl_Ui/generated/%.su Core/Src/Lvgl_Ui/generated/%.cyclo: ../Core/Src/Lvgl_Ui/generated/%.c Core/Src/Lvgl_Ui/generated/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated

clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated:
	-$(RM) ./Core/Src/Lvgl_Ui/generated/events_init.cyclo ./Core/Src/Lvgl_Ui/generated/events_init.d ./Core/Src/Lvgl_Ui/generated/events_init.o ./Core/Src/Lvgl_Ui/generated/events_init.su ./Core/Src/Lvgl_Ui/generated/gui_guider.cyclo ./Core/Src/Lvgl_Ui/generated/gui_guider.d ./Core/Src/Lvgl_Ui/generated/gui_guider.o ./Core/Src/Lvgl_Ui/generated/gui_guider.su ./Core/Src/Lvgl_Ui/generated/setup_scr_MainScreen.cyclo ./Core/Src/Lvgl_Ui/generated/setup_scr_MainScreen.d ./Core/Src/Lvgl_Ui/generated/setup_scr_MainScreen.o ./Core/Src/Lvgl_Ui/generated/setup_scr_MainScreen.su ./Core/Src/Lvgl_Ui/generated/widgets_init.cyclo ./Core/Src/Lvgl_Ui/generated/widgets_init.d ./Core/Src/Lvgl_Ui/generated/widgets_init.o ./Core/Src/Lvgl_Ui/generated/widgets_init.su

.PHONY: clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated

