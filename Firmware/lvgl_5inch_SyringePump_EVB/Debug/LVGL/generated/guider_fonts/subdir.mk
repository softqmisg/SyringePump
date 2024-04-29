################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/generated/guider_fonts/lv_font_montserratMedium_12.c \
../LVGL/generated/guider_fonts/lv_font_montserratMedium_16.c 

OBJS += \
./LVGL/generated/guider_fonts/lv_font_montserratMedium_12.o \
./LVGL/generated/guider_fonts/lv_font_montserratMedium_16.o 

C_DEPS += \
./LVGL/generated/guider_fonts/lv_font_montserratMedium_12.d \
./LVGL/generated/guider_fonts/lv_font_montserratMedium_16.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/generated/guider_fonts/%.o LVGL/generated/guider_fonts/%.su LVGL/generated/guider_fonts/%.cyclo: ../LVGL/generated/guider_fonts/%.c LVGL/generated/guider_fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/generated" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-generated-2f-guider_fonts

clean-LVGL-2f-generated-2f-guider_fonts:
	-$(RM) ./LVGL/generated/guider_fonts/lv_font_montserratMedium_12.cyclo ./LVGL/generated/guider_fonts/lv_font_montserratMedium_12.d ./LVGL/generated/guider_fonts/lv_font_montserratMedium_12.o ./LVGL/generated/guider_fonts/lv_font_montserratMedium_12.su ./LVGL/generated/guider_fonts/lv_font_montserratMedium_16.cyclo ./LVGL/generated/guider_fonts/lv_font_montserratMedium_16.d ./LVGL/generated/guider_fonts/lv_font_montserratMedium_16.o ./LVGL/generated/guider_fonts/lv_font_montserratMedium_16.su

.PHONY: clean-LVGL-2f-generated-2f-guider_fonts

