################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/scroll/lv_example_scroll_1.c \
../LVGL/lvgl/examples/scroll/lv_example_scroll_2.c \
../LVGL/lvgl/examples/scroll/lv_example_scroll_3.c \
../LVGL/lvgl/examples/scroll/lv_example_scroll_4.c \
../LVGL/lvgl/examples/scroll/lv_example_scroll_5.c \
../LVGL/lvgl/examples/scroll/lv_example_scroll_6.c 

OBJS += \
./LVGL/lvgl/examples/scroll/lv_example_scroll_1.o \
./LVGL/lvgl/examples/scroll/lv_example_scroll_2.o \
./LVGL/lvgl/examples/scroll/lv_example_scroll_3.o \
./LVGL/lvgl/examples/scroll/lv_example_scroll_4.o \
./LVGL/lvgl/examples/scroll/lv_example_scroll_5.o \
./LVGL/lvgl/examples/scroll/lv_example_scroll_6.o 

C_DEPS += \
./LVGL/lvgl/examples/scroll/lv_example_scroll_1.d \
./LVGL/lvgl/examples/scroll/lv_example_scroll_2.d \
./LVGL/lvgl/examples/scroll/lv_example_scroll_3.d \
./LVGL/lvgl/examples/scroll/lv_example_scroll_4.d \
./LVGL/lvgl/examples/scroll/lv_example_scroll_5.d \
./LVGL/lvgl/examples/scroll/lv_example_scroll_6.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/scroll/%.o LVGL/lvgl/examples/scroll/%.su LVGL/lvgl/examples/scroll/%.cyclo: ../LVGL/lvgl/examples/scroll/%.c LVGL/lvgl/examples/scroll/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-scroll

clean-LVGL-2f-lvgl-2f-examples-2f-scroll:
	-$(RM) ./LVGL/lvgl/examples/scroll/lv_example_scroll_1.cyclo ./LVGL/lvgl/examples/scroll/lv_example_scroll_1.d ./LVGL/lvgl/examples/scroll/lv_example_scroll_1.o ./LVGL/lvgl/examples/scroll/lv_example_scroll_1.su ./LVGL/lvgl/examples/scroll/lv_example_scroll_2.cyclo ./LVGL/lvgl/examples/scroll/lv_example_scroll_2.d ./LVGL/lvgl/examples/scroll/lv_example_scroll_2.o ./LVGL/lvgl/examples/scroll/lv_example_scroll_2.su ./LVGL/lvgl/examples/scroll/lv_example_scroll_3.cyclo ./LVGL/lvgl/examples/scroll/lv_example_scroll_3.d ./LVGL/lvgl/examples/scroll/lv_example_scroll_3.o ./LVGL/lvgl/examples/scroll/lv_example_scroll_3.su ./LVGL/lvgl/examples/scroll/lv_example_scroll_4.cyclo ./LVGL/lvgl/examples/scroll/lv_example_scroll_4.d ./LVGL/lvgl/examples/scroll/lv_example_scroll_4.o ./LVGL/lvgl/examples/scroll/lv_example_scroll_4.su ./LVGL/lvgl/examples/scroll/lv_example_scroll_5.cyclo ./LVGL/lvgl/examples/scroll/lv_example_scroll_5.d ./LVGL/lvgl/examples/scroll/lv_example_scroll_5.o ./LVGL/lvgl/examples/scroll/lv_example_scroll_5.su ./LVGL/lvgl/examples/scroll/lv_example_scroll_6.cyclo ./LVGL/lvgl/examples/scroll/lv_example_scroll_6.d ./LVGL/lvgl/examples/scroll/lv_example_scroll_6.o ./LVGL/lvgl/examples/scroll/lv_example_scroll_6.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-scroll

