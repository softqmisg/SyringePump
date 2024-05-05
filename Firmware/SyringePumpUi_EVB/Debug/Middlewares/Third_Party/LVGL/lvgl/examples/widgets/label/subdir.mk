################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_1.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_2.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_3.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_4.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_5.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_1.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_2.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_3.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_4.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_5.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_1.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_2.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_3.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_4.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_5.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/%.o Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/%.su Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/%.c Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-label

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-label:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_1.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_1.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_1.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_1.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_2.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_2.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_2.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_2.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_3.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_3.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_3.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_3.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_4.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_4.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_4.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_4.su ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_5.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_5.d ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_5.o ./Middlewares/Third_Party/LVGL/lvgl/examples/widgets/label/lv_example_label_5.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-widgets-2f-label

