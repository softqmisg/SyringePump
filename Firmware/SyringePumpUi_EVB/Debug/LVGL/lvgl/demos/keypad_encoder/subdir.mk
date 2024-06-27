################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.c 

OBJS += \
./LVGL/lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.o 

C_DEPS += \
./LVGL/lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/demos/keypad_encoder/%.o LVGL/lvgl/demos/keypad_encoder/%.su LVGL/lvgl/demos/keypad_encoder/%.cyclo: ../LVGL/lvgl/demos/keypad_encoder/%.c LVGL/lvgl/demos/keypad_encoder/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-demos-2f-keypad_encoder

clean-LVGL-2f-lvgl-2f-demos-2f-keypad_encoder:
	-$(RM) ./LVGL/lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.cyclo ./LVGL/lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.d ./LVGL/lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.o ./LVGL/lvgl/demos/keypad_encoder/lv_demo_keypad_encoder.su

.PHONY: clean-LVGL-2f-lvgl-2f-demos-2f-keypad_encoder

