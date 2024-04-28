################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/extra/widgets/led/lv_led.c 

OBJS += \
./LVGL/lvgl/src/extra/widgets/led/lv_led.o 

C_DEPS += \
./LVGL/lvgl/src/extra/widgets/led/lv_led.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/extra/widgets/led/%.o LVGL/lvgl/src/extra/widgets/led/%.su LVGL/lvgl/src/extra/widgets/led/%.cyclo: ../LVGL/lvgl/src/extra/widgets/led/%.c LVGL/lvgl/src/extra/widgets/led/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-led

clean-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-led:
	-$(RM) ./LVGL/lvgl/src/extra/widgets/led/lv_led.cyclo ./LVGL/lvgl/src/extra/widgets/led/lv_led.d ./LVGL/lvgl/src/extra/widgets/led/lv_led.o ./LVGL/lvgl/src/extra/widgets/led/lv_led.su

.PHONY: clean-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-led

