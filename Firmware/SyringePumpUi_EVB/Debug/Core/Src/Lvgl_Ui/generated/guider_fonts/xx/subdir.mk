################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Acme_Regular_30.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_20.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_30.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_12.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_13.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_15.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_16.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_20.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_14.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_15.c \
../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_20.c 

OBJS += \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Acme_Regular_30.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_20.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_30.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_12.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_13.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_15.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_16.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_20.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_14.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_15.o \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_20.o 

C_DEPS += \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Acme_Regular_30.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_20.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_30.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_12.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_13.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_15.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_16.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_20.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_14.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_15.d \
./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_20.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Lvgl_Ui/generated/guider_fonts/xx/%.o Core/Src/Lvgl_Ui/generated/guider_fonts/xx/%.su Core/Src/Lvgl_Ui/generated/guider_fonts/xx/%.cyclo: ../Core/Src/Lvgl_Ui/generated/guider_fonts/xx/%.c Core/Src/Lvgl_Ui/generated/guider_fonts/xx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated-2f-guider_fonts-2f-xx

clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated-2f-guider_fonts-2f-xx:
	-$(RM) ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Acme_Regular_30.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Acme_Regular_30.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Acme_Regular_30.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Acme_Regular_30.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_20.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_20.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_20.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_20.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_30.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_30.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_30.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_Alatsi_Regular_30.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_12.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_12.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_12.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_12.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_13.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_13.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_13.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_13.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_15.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_15.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_15.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_15.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_16.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_16.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_16.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_16.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_20.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_20.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_20.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_arial_20.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_14.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_14.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_14.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_14.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_15.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_15.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_15.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_15.su ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_20.cyclo ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_20.d ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_20.o ./Core/Src/Lvgl_Ui/generated/guider_fonts/xx/lv_font_montserratMedium_20.su

.PHONY: clean-Core-2f-Src-2f-Lvgl_Ui-2f-generated-2f-guider_fonts-2f-xx

