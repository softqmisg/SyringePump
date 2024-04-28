################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/libs/png/img_wink_png.c \
../LVGL/lvgl/examples/libs/png/lv_example_png_1.c 

OBJS += \
./LVGL/lvgl/examples/libs/png/img_wink_png.o \
./LVGL/lvgl/examples/libs/png/lv_example_png_1.o 

C_DEPS += \
./LVGL/lvgl/examples/libs/png/img_wink_png.d \
./LVGL/lvgl/examples/libs/png/lv_example_png_1.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/libs/png/%.o LVGL/lvgl/examples/libs/png/%.su LVGL/lvgl/examples/libs/png/%.cyclo: ../LVGL/lvgl/examples/libs/png/%.c LVGL/lvgl/examples/libs/png/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-libs-2f-png

clean-LVGL-2f-lvgl-2f-examples-2f-libs-2f-png:
	-$(RM) ./LVGL/lvgl/examples/libs/png/img_wink_png.cyclo ./LVGL/lvgl/examples/libs/png/img_wink_png.d ./LVGL/lvgl/examples/libs/png/img_wink_png.o ./LVGL/lvgl/examples/libs/png/img_wink_png.su ./LVGL/lvgl/examples/libs/png/lv_example_png_1.cyclo ./LVGL/lvgl/examples/libs/png/lv_example_png_1.d ./LVGL/lvgl/examples/libs/png/lv_example_png_1.o ./LVGL/lvgl/examples/libs/png/lv_example_png_1.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-libs-2f-png

