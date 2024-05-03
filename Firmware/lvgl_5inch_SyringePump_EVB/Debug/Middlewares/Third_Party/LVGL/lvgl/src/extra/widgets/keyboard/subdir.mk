################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/lv_keyboard.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/lv_keyboard.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/lv_keyboard.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/%.o Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/%.su Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/%.c Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-keyboard

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-keyboard:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/lv_keyboard.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/lv_keyboard.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/lv_keyboard.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/keyboard/lv_keyboard.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-keyboard
