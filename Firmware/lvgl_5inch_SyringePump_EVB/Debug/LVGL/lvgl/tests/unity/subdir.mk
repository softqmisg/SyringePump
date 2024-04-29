################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/tests/unity/unity.c \
../LVGL/lvgl/tests/unity/unity_support.c 

OBJS += \
./LVGL/lvgl/tests/unity/unity.o \
./LVGL/lvgl/tests/unity/unity_support.o 

C_DEPS += \
./LVGL/lvgl/tests/unity/unity.d \
./LVGL/lvgl/tests/unity/unity_support.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/tests/unity/%.o LVGL/lvgl/tests/unity/%.su LVGL/lvgl/tests/unity/%.cyclo: ../LVGL/lvgl/tests/unity/%.c LVGL/lvgl/tests/unity/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-tests-2f-unity

clean-LVGL-2f-lvgl-2f-tests-2f-unity:
	-$(RM) ./LVGL/lvgl/tests/unity/unity.cyclo ./LVGL/lvgl/tests/unity/unity.d ./LVGL/lvgl/tests/unity/unity.o ./LVGL/lvgl/tests/unity/unity.su ./LVGL/lvgl/tests/unity/unity_support.cyclo ./LVGL/lvgl/tests/unity/unity_support.d ./LVGL/lvgl/tests/unity/unity_support.o ./LVGL/lvgl/tests/unity/unity_support.su

.PHONY: clean-LVGL-2f-lvgl-2f-tests-2f-unity

