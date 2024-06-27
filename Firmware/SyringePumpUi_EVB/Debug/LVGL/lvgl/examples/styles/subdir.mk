################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/styles/lv_example_style_1.c \
../LVGL/lvgl/examples/styles/lv_example_style_10.c \
../LVGL/lvgl/examples/styles/lv_example_style_11.c \
../LVGL/lvgl/examples/styles/lv_example_style_12.c \
../LVGL/lvgl/examples/styles/lv_example_style_13.c \
../LVGL/lvgl/examples/styles/lv_example_style_14.c \
../LVGL/lvgl/examples/styles/lv_example_style_15.c \
../LVGL/lvgl/examples/styles/lv_example_style_2.c \
../LVGL/lvgl/examples/styles/lv_example_style_3.c \
../LVGL/lvgl/examples/styles/lv_example_style_4.c \
../LVGL/lvgl/examples/styles/lv_example_style_5.c \
../LVGL/lvgl/examples/styles/lv_example_style_6.c \
../LVGL/lvgl/examples/styles/lv_example_style_7.c \
../LVGL/lvgl/examples/styles/lv_example_style_8.c \
../LVGL/lvgl/examples/styles/lv_example_style_9.c 

OBJS += \
./LVGL/lvgl/examples/styles/lv_example_style_1.o \
./LVGL/lvgl/examples/styles/lv_example_style_10.o \
./LVGL/lvgl/examples/styles/lv_example_style_11.o \
./LVGL/lvgl/examples/styles/lv_example_style_12.o \
./LVGL/lvgl/examples/styles/lv_example_style_13.o \
./LVGL/lvgl/examples/styles/lv_example_style_14.o \
./LVGL/lvgl/examples/styles/lv_example_style_15.o \
./LVGL/lvgl/examples/styles/lv_example_style_2.o \
./LVGL/lvgl/examples/styles/lv_example_style_3.o \
./LVGL/lvgl/examples/styles/lv_example_style_4.o \
./LVGL/lvgl/examples/styles/lv_example_style_5.o \
./LVGL/lvgl/examples/styles/lv_example_style_6.o \
./LVGL/lvgl/examples/styles/lv_example_style_7.o \
./LVGL/lvgl/examples/styles/lv_example_style_8.o \
./LVGL/lvgl/examples/styles/lv_example_style_9.o 

C_DEPS += \
./LVGL/lvgl/examples/styles/lv_example_style_1.d \
./LVGL/lvgl/examples/styles/lv_example_style_10.d \
./LVGL/lvgl/examples/styles/lv_example_style_11.d \
./LVGL/lvgl/examples/styles/lv_example_style_12.d \
./LVGL/lvgl/examples/styles/lv_example_style_13.d \
./LVGL/lvgl/examples/styles/lv_example_style_14.d \
./LVGL/lvgl/examples/styles/lv_example_style_15.d \
./LVGL/lvgl/examples/styles/lv_example_style_2.d \
./LVGL/lvgl/examples/styles/lv_example_style_3.d \
./LVGL/lvgl/examples/styles/lv_example_style_4.d \
./LVGL/lvgl/examples/styles/lv_example_style_5.d \
./LVGL/lvgl/examples/styles/lv_example_style_6.d \
./LVGL/lvgl/examples/styles/lv_example_style_7.d \
./LVGL/lvgl/examples/styles/lv_example_style_8.d \
./LVGL/lvgl/examples/styles/lv_example_style_9.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/styles/%.o LVGL/lvgl/examples/styles/%.su LVGL/lvgl/examples/styles/%.cyclo: ../LVGL/lvgl/examples/styles/%.c LVGL/lvgl/examples/styles/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-styles

clean-LVGL-2f-lvgl-2f-examples-2f-styles:
	-$(RM) ./LVGL/lvgl/examples/styles/lv_example_style_1.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_1.d ./LVGL/lvgl/examples/styles/lv_example_style_1.o ./LVGL/lvgl/examples/styles/lv_example_style_1.su ./LVGL/lvgl/examples/styles/lv_example_style_10.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_10.d ./LVGL/lvgl/examples/styles/lv_example_style_10.o ./LVGL/lvgl/examples/styles/lv_example_style_10.su ./LVGL/lvgl/examples/styles/lv_example_style_11.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_11.d ./LVGL/lvgl/examples/styles/lv_example_style_11.o ./LVGL/lvgl/examples/styles/lv_example_style_11.su ./LVGL/lvgl/examples/styles/lv_example_style_12.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_12.d ./LVGL/lvgl/examples/styles/lv_example_style_12.o ./LVGL/lvgl/examples/styles/lv_example_style_12.su ./LVGL/lvgl/examples/styles/lv_example_style_13.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_13.d ./LVGL/lvgl/examples/styles/lv_example_style_13.o ./LVGL/lvgl/examples/styles/lv_example_style_13.su ./LVGL/lvgl/examples/styles/lv_example_style_14.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_14.d ./LVGL/lvgl/examples/styles/lv_example_style_14.o ./LVGL/lvgl/examples/styles/lv_example_style_14.su ./LVGL/lvgl/examples/styles/lv_example_style_15.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_15.d ./LVGL/lvgl/examples/styles/lv_example_style_15.o ./LVGL/lvgl/examples/styles/lv_example_style_15.su ./LVGL/lvgl/examples/styles/lv_example_style_2.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_2.d ./LVGL/lvgl/examples/styles/lv_example_style_2.o ./LVGL/lvgl/examples/styles/lv_example_style_2.su ./LVGL/lvgl/examples/styles/lv_example_style_3.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_3.d ./LVGL/lvgl/examples/styles/lv_example_style_3.o ./LVGL/lvgl/examples/styles/lv_example_style_3.su ./LVGL/lvgl/examples/styles/lv_example_style_4.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_4.d ./LVGL/lvgl/examples/styles/lv_example_style_4.o ./LVGL/lvgl/examples/styles/lv_example_style_4.su ./LVGL/lvgl/examples/styles/lv_example_style_5.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_5.d ./LVGL/lvgl/examples/styles/lv_example_style_5.o ./LVGL/lvgl/examples/styles/lv_example_style_5.su ./LVGL/lvgl/examples/styles/lv_example_style_6.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_6.d ./LVGL/lvgl/examples/styles/lv_example_style_6.o ./LVGL/lvgl/examples/styles/lv_example_style_6.su ./LVGL/lvgl/examples/styles/lv_example_style_7.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_7.d ./LVGL/lvgl/examples/styles/lv_example_style_7.o ./LVGL/lvgl/examples/styles/lv_example_style_7.su ./LVGL/lvgl/examples/styles/lv_example_style_8.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_8.d ./LVGL/lvgl/examples/styles/lv_example_style_8.o ./LVGL/lvgl/examples/styles/lv_example_style_8.su ./LVGL/lvgl/examples/styles/lv_example_style_9.cyclo ./LVGL/lvgl/examples/styles/lv_example_style_9.d ./LVGL/lvgl/examples/styles/lv_example_style_9.o ./LVGL/lvgl/examples/styles/lv_example_style_9.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-styles

