################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_SourceHanSerifSC_Regular_18.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_12.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_16.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_18.c 

OBJS += \
./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_SourceHanSerifSC_Regular_18.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_12.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_16.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_18.o 

C_DEPS += \
./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_SourceHanSerifSC_Regular_18.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_12.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_16.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_18.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Lvgl_Ui/generated/guider_fonts/%.o Core/Src/Lvgl_Ui/generated/guider_fonts/%.su Core/Src/Lvgl_Ui/generated/guider_fonts/%.cyclo: ../Core/Src/Lvgl_Ui/generated/guider_fonts/%.c Core/Src/Lvgl_Ui/generated/guider_fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated-2f-guider_fonts

clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated-2f-guider_fonts:
	-$(RM) ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_SourceHanSerifSC_Regular_18.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_SourceHanSerifSC_Regular_18.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_SourceHanSerifSC_Regular_18.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_SourceHanSerifSC_Regular_18.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_12.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_12.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_12.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_12.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_16.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_16.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_16.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_16.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_18.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_18.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_18.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/lv_font_montserratMedium_18.su

.PHONY: clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated-2f-guider_fonts

