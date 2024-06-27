################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/env_support/rt-thread/lv_rt_thread_port.c 

OBJS += \
./LVGL/lvgl/env_support/rt-thread/lv_rt_thread_port.o 

C_DEPS += \
./LVGL/lvgl/env_support/rt-thread/lv_rt_thread_port.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/env_support/rt-thread/%.o LVGL/lvgl/env_support/rt-thread/%.su LVGL/lvgl/env_support/rt-thread/%.cyclo: ../LVGL/lvgl/env_support/rt-thread/%.c LVGL/lvgl/env_support/rt-thread/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-env_support-2f-rt-2d-thread

clean-LVGL-2f-lvgl-2f-env_support-2f-rt-2d-thread:
	-$(RM) ./LVGL/lvgl/env_support/rt-thread/lv_rt_thread_port.cyclo ./LVGL/lvgl/env_support/rt-thread/lv_rt_thread_port.d ./LVGL/lvgl/env_support/rt-thread/lv_rt_thread_port.o ./LVGL/lvgl/env_support/rt-thread/lv_rt_thread_port.su

.PHONY: clean-LVGL-2f-lvgl-2f-env_support-2f-rt-2d-thread

