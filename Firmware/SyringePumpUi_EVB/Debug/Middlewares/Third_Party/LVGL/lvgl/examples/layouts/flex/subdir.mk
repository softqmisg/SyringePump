################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/%.o Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/%.su Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/%.c Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-layouts-2f-flex

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-layouts-2f-flex:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.d ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.o ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_1.su ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.d ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.o ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_2.su ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.d ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.o ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_3.su ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.d ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.o ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_4.su ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.d ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.o ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_5.su ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.d ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.o ./Middlewares/Third_Party/LVGL/lvgl/examples/layouts/flex/lv_example_flex_6.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-layouts-2f-flex

