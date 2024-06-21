################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_18x64.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_38x64.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_56x251.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_67x79.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_18x64.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_67x79.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_100x100.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_alpha_100x100.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_lirana_logo_454x340.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_100x100.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_alpha_100x100.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/_syringe2_512_alpha_464x100.c \
../Core/Src/Lvgl_Ui/generated/images/xxx/batterybg_64.c 

OBJS += \
./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_18x64.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_38x64.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_56x251.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_67x79.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_18x64.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_67x79.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_100x100.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_alpha_100x100.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_lirana_logo_454x340.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_100x100.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_alpha_100x100.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe2_512_alpha_464x100.o \
./Core/Src/Lvgl_Ui/generated/images/xxx/batterybg_64.o 

C_DEPS += \
./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_18x64.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_38x64.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_56x251.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_67x79.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_18x64.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_67x79.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_100x100.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_alpha_100x100.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_lirana_logo_454x340.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_100x100.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_alpha_100x100.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe2_512_alpha_464x100.d \
./Core/Src/Lvgl_Ui/generated/images/xxx/batterybg_64.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Lvgl_Ui/generated/images/xxx/%.o Core/Src/Lvgl_Ui/generated/images/xxx/%.su Core/Src/Lvgl_Ui/generated/images/xxx/%.cyclo: ../Core/Src/Lvgl_Ui/generated/images/xxx/%.c Core/Src/Lvgl_Ui/generated/images/xxx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated-2f-images-2f-xxx

clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated-2f-images-2f-xxx:
	-$(RM) ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_18x64.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_18x64.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_18x64.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_18x64.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_38x64.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_38x64.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_38x64.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_38x64.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_56x251.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_56x251.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_56x251.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_56x251.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_67x79.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_67x79.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_67x79.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_battery_64_67x79.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_18x64.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_18x64.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_18x64.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_18x64.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_67x79.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_67x79.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_67x79.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_batterybg_64_67x79.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_100x100.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_100x100.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_100x100.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_100x100.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_alpha_100x100.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_alpha_100x100.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_alpha_100x100.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_droplet_64_alpha_100x100.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_lirana_logo_454x340.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_lirana_logo_454x340.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_lirana_logo_454x340.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_lirana_logo_454x340.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_100x100.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_100x100.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_100x100.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_100x100.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_alpha_100x100.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_alpha_100x100.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_alpha_100x100.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe1_128_alpha_100x100.su ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe2_512_alpha_464x100.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe2_512_alpha_464x100.d ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe2_512_alpha_464x100.o ./Core/Src/Lvgl_Ui/generated/images/xxx/_syringe2_512_alpha_464x100.su ./Core/Src/Lvgl_Ui/generated/images/xxx/batterybg_64.cyclo ./Core/Src/Lvgl_Ui/generated/images/xxx/batterybg_64.d ./Core/Src/Lvgl_Ui/generated/images/xxx/batterybg_64.o ./Core/Src/Lvgl_Ui/generated/images/xxx/batterybg_64.su

.PHONY: clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated-2f-images-2f-xxx

