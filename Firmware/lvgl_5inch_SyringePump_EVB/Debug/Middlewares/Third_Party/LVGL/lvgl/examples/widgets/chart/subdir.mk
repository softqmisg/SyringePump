################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/%.o Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/%.su Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/%.c Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-chart

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-chart:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_1.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_2.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_3.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_4.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_5.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_6.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_7.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_8.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/chart/lv_example_chart_9.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-chart

