################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/extra/widgets/imgbtn/lv_imgbtn.c 

OBJS += \
./LVGL/lvgl/src/extra/widgets/imgbtn/lv_imgbtn.o 

C_DEPS += \
./LVGL/lvgl/src/extra/widgets/imgbtn/lv_imgbtn.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/extra/widgets/imgbtn/%.o LVGL/lvgl/src/extra/widgets/imgbtn/%.su LVGL/lvgl/src/extra/widgets/imgbtn/%.cyclo: ../LVGL/lvgl/src/extra/widgets/imgbtn/%.c LVGL/lvgl/src/extra/widgets/imgbtn/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-imgbtn

clean-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-imgbtn:
	-$(RM) ./LVGL/lvgl/src/extra/widgets/imgbtn/lv_imgbtn.cyclo ./LVGL/lvgl/src/extra/widgets/imgbtn/lv_imgbtn.d ./LVGL/lvgl/src/extra/widgets/imgbtn/lv_imgbtn.o ./LVGL/lvgl/src/extra/widgets/imgbtn/lv_imgbtn.su

.PHONY: clean-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-imgbtn
