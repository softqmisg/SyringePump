################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_1.c \
../LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_2.c 

OBJS += \
./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_1.o \
./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_2.o 

C_DEPS += \
./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_1.d \
./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_2.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/others/ime/%.o LVGL/lvgl/examples/others/ime/%.su LVGL/lvgl/examples/others/ime/%.cyclo: ../LVGL/lvgl/examples/others/ime/%.c LVGL/lvgl/examples/others/ime/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-others-2f-ime

clean-LVGL-2f-lvgl-2f-examples-2f-others-2f-ime:
	-$(RM) ./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_1.cyclo ./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_1.d ./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_1.o ./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_1.su ./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_2.cyclo ./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_2.d ./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_2.o ./LVGL/lvgl/examples/others/ime/lv_example_ime_pinyin_2.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-others-2f-ime

