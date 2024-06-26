################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Lvgl_Ui/custom/custom.c 

OBJS += \
./Core/Src/Lvgl_Ui/custom/custom.o 

C_DEPS += \
./Core/Src/Lvgl_Ui/custom/custom.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Lvgl_Ui/custom/%.o Core/Src/Lvgl_Ui/custom/%.su Core/Src/Lvgl_Ui/custom/%.cyclo: ../Core/Src/Lvgl_Ui/custom/%.c Core/Src/Lvgl_Ui/custom/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Lvgl_Ui-2f-custom

clean-Core-2f-Src-2f-Lvgl_Ui-2f-custom:
	-$(RM) ./Core/Src/Lvgl_Ui/custom/custom.cyclo ./Core/Src/Lvgl_Ui/custom/custom.d ./Core/Src/Lvgl_Ui/custom/custom.o ./Core/Src/Lvgl_Ui/custom/custom.su

.PHONY: clean-Core-2f-Src-2f-Lvgl_Ui-2f-custom

