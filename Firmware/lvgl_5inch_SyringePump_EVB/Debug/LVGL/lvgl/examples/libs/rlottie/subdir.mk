################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_1.c \
../LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_2.c \
../LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.c 

OBJS += \
./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_1.o \
./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_2.o \
./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.o 

C_DEPS += \
./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_1.d \
./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_2.d \
./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/libs/rlottie/%.o LVGL/lvgl/examples/libs/rlottie/%.su LVGL/lvgl/examples/libs/rlottie/%.cyclo: ../LVGL/lvgl/examples/libs/rlottie/%.c LVGL/lvgl/examples/libs/rlottie/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-libs-2f-rlottie

clean-LVGL-2f-lvgl-2f-examples-2f-libs-2f-rlottie:
	-$(RM) ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_1.cyclo ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_1.d ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_1.o ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_1.su ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_2.cyclo ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_2.d ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_2.o ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_2.su ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.cyclo ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.d ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.o ./LVGL/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-libs-2f-rlottie

