################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Pump_src/Drug.c \
../Core/Src/Pump_src/InfusionMode.c \
../Core/Src/Pump_src/MachineState.c \
../Core/Src/Pump_src/Syringe.c 

OBJS += \
./Core/Src/Pump_src/Drug.o \
./Core/Src/Pump_src/InfusionMode.o \
./Core/Src/Pump_src/MachineState.o \
./Core/Src/Pump_src/Syringe.o 

C_DEPS += \
./Core/Src/Pump_src/Drug.d \
./Core/Src/Pump_src/InfusionMode.d \
./Core/Src/Pump_src/MachineState.d \
./Core/Src/Pump_src/Syringe.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Pump_src/%.o Core/Src/Pump_src/%.su Core/Src/Pump_src/%.cyclo: ../Core/Src/Pump_src/%.c Core/Src/Pump_src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Pump_src

clean-Core-2f-Src-2f-Pump_src:
	-$(RM) ./Core/Src/Pump_src/Drug.cyclo ./Core/Src/Pump_src/Drug.d ./Core/Src/Pump_src/Drug.o ./Core/Src/Pump_src/Drug.su ./Core/Src/Pump_src/InfusionMode.cyclo ./Core/Src/Pump_src/InfusionMode.d ./Core/Src/Pump_src/InfusionMode.o ./Core/Src/Pump_src/InfusionMode.su ./Core/Src/Pump_src/MachineState.cyclo ./Core/Src/Pump_src/MachineState.d ./Core/Src/Pump_src/MachineState.o ./Core/Src/Pump_src/MachineState.su ./Core/Src/Pump_src/Syringe.cyclo ./Core/Src/Pump_src/Syringe.d ./Core/Src/Pump_src/Syringe.o ./Core/Src/Pump_src/Syringe.su

.PHONY: clean-Core-2f-Src-2f-Pump_src

