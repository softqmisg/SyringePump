################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.c \
../LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.c \
../LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.c \
../LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.c \
../LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.c \
../LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.c 

OBJS += \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.o \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.o \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.o \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.o \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.o \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.o 

C_DEPS += \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.d \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.d \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.d \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.d \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.d \
./LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/layouts/flex/%.o LVGL/lvgl/examples/layouts/flex/%.su LVGL/lvgl/examples/layouts/flex/%.cyclo: ../LVGL/lvgl/examples/layouts/flex/%.c LVGL/lvgl/examples/layouts/flex/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-layouts-2f-flex

clean-LVGL-2f-lvgl-2f-examples-2f-layouts-2f-flex:
	-$(RM) ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.cyclo ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.d ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.o ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.su ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.cyclo ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.d ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.o ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.su ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.cyclo ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.d ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.o ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.su ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.cyclo ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.d ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.o ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.su ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.cyclo ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.d ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.o ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.su ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.cyclo ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.d ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.o ./LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-layouts-2f-flex

