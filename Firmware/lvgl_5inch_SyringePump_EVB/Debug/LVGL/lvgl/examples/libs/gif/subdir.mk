################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/libs/gif/img_bulb_gif.c \
../LVGL/lvgl/examples/libs/gif/lv_example_gif_1.c 

OBJS += \
./LVGL/lvgl/examples/libs/gif/img_bulb_gif.o \
./LVGL/lvgl/examples/libs/gif/lv_example_gif_1.o 

C_DEPS += \
./LVGL/lvgl/examples/libs/gif/img_bulb_gif.d \
./LVGL/lvgl/examples/libs/gif/lv_example_gif_1.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/libs/gif/%.o LVGL/lvgl/examples/libs/gif/%.su LVGL/lvgl/examples/libs/gif/%.cyclo: ../LVGL/lvgl/examples/libs/gif/%.c LVGL/lvgl/examples/libs/gif/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-libs-2f-gif

clean-LVGL-2f-lvgl-2f-examples-2f-libs-2f-gif:
	-$(RM) ./LVGL/lvgl/examples/libs/gif/img_bulb_gif.cyclo ./LVGL/lvgl/examples/libs/gif/img_bulb_gif.d ./LVGL/lvgl/examples/libs/gif/img_bulb_gif.o ./LVGL/lvgl/examples/libs/gif/img_bulb_gif.su ./LVGL/lvgl/examples/libs/gif/lv_example_gif_1.cyclo ./LVGL/lvgl/examples/libs/gif/lv_example_gif_1.d ./LVGL/lvgl/examples/libs/gif/lv_example_gif_1.o ./LVGL/lvgl/examples/libs/gif/lv_example_gif_1.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-libs-2f-gif

