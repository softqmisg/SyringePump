################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Lvgl_Ui/myInputDevice.c 

OBJS += \
./Core/Src/Lvgl_Ui/myInputDevice.o 

C_DEPS += \
./Core/Src/Lvgl_Ui/myInputDevice.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Lvgl_Ui/%.o Core/Src/Lvgl_Ui/%.su Core/Src/Lvgl_Ui/%.cyclo: ../Core/Src/Lvgl_Ui/%.c Core/Src/Lvgl_Ui/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Lvgl_Ui

clean-Core-2f-Src-2f-Lvgl_Ui:
	-$(RM) ./Core/Src/Lvgl_Ui/myInputDevice.cyclo ./Core/Src/Lvgl_Ui/myInputDevice.d ./Core/Src/Lvgl_Ui/myInputDevice.o ./Core/Src/Lvgl_Ui/myInputDevice.su

.PHONY: clean-Core-2f-Src-2f-Lvgl_Ui

