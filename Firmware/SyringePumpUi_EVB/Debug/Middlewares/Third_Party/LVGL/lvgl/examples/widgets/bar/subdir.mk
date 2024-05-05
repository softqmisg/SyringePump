################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/%.o Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/%.su Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/%.c Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-bar

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-bar:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_1.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_2.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_3.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_4.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_5.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/bar/lv_example_bar_6.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-bar

