################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.c \
../LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.c \
../LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.c \
../LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.c \
../LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.c \
../LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.c 

OBJS += \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.o \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.o \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.o \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.o \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.o \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.o 

C_DEPS += \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.d \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.d \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.d \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.d \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.d \
./LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/widgets/bar/%.o LVGL/lvgl/examples/widgets/bar/%.su LVGL/lvgl/examples/widgets/bar/%.cyclo: ../LVGL/lvgl/examples/widgets/bar/%.c LVGL/lvgl/examples/widgets/bar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-bar

clean-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-bar:
	-$(RM) ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.cyclo ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.d ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.o ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.su ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.cyclo ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.d ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.o ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.su ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.cyclo ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.d ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.o ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.su ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.cyclo ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.d ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.o ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.su ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.cyclo ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.d ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.o ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.su ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.cyclo ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.d ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.o ./LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-bar

