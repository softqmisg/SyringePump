################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.c \
../LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.c \
../LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.c \
../LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.c \
../LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.c \
../LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.c \
../LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.c \
../LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.c \
../LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.c 

OBJS += \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.o \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.o \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.o \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.o \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.o \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.o \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.o \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.o \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.o 

C_DEPS += \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.d \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.d \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.d \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.d \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.d \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.d \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.d \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.d \
./LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/widgets/chart/%.o LVGL/lvgl/examples/widgets/chart/%.su LVGL/lvgl/examples/widgets/chart/%.cyclo: ../LVGL/lvgl/examples/widgets/chart/%.c LVGL/lvgl/examples/widgets/chart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-chart

clean-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-chart:
	-$(RM) ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.cyclo ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.d ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.o ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.su ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.cyclo ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.d ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.o ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.su ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.cyclo ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.d ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.o ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.su ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.cyclo ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.d ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.o ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.su ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.cyclo ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.d ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.o ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.su ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.cyclo ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.d ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.o ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.su ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.cyclo ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.d ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.o ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.su ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.cyclo ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.d ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.o ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.su ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.cyclo ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.d ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.o ./LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-chart

