################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/lv_bmp.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/lv_bmp.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/lv_bmp.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/%.o Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/%.su Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/%.c Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-libs-2f-bmp

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-libs-2f-bmp:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/lv_bmp.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/lv_bmp.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/lv_bmp.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/libs/bmp/lv_bmp.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-libs-2f-bmp

