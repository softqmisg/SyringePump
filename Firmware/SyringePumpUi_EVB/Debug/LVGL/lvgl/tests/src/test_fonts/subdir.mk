################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/tests/src/test_fonts/font_1.c \
../LVGL/lvgl/tests/src/test_fonts/font_2.c \
../LVGL/lvgl/tests/src/test_fonts/font_3.c \
../LVGL/lvgl/tests/src/test_fonts/ubuntu_font.c 

OBJS += \
./LVGL/lvgl/tests/src/test_fonts/font_1.o \
./LVGL/lvgl/tests/src/test_fonts/font_2.o \
./LVGL/lvgl/tests/src/test_fonts/font_3.o \
./LVGL/lvgl/tests/src/test_fonts/ubuntu_font.o 

C_DEPS += \
./LVGL/lvgl/tests/src/test_fonts/font_1.d \
./LVGL/lvgl/tests/src/test_fonts/font_2.d \
./LVGL/lvgl/tests/src/test_fonts/font_3.d \
./LVGL/lvgl/tests/src/test_fonts/ubuntu_font.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/tests/src/test_fonts/%.o LVGL/lvgl/tests/src/test_fonts/%.su LVGL/lvgl/tests/src/test_fonts/%.cyclo: ../LVGL/lvgl/tests/src/test_fonts/%.c LVGL/lvgl/tests/src/test_fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-tests-2f-src-2f-test_fonts

clean-LVGL-2f-lvgl-2f-tests-2f-src-2f-test_fonts:
	-$(RM) ./LVGL/lvgl/tests/src/test_fonts/font_1.cyclo ./LVGL/lvgl/tests/src/test_fonts/font_1.d ./LVGL/lvgl/tests/src/test_fonts/font_1.o ./LVGL/lvgl/tests/src/test_fonts/font_1.su ./LVGL/lvgl/tests/src/test_fonts/font_2.cyclo ./LVGL/lvgl/tests/src/test_fonts/font_2.d ./LVGL/lvgl/tests/src/test_fonts/font_2.o ./LVGL/lvgl/tests/src/test_fonts/font_2.su ./LVGL/lvgl/tests/src/test_fonts/font_3.cyclo ./LVGL/lvgl/tests/src/test_fonts/font_3.d ./LVGL/lvgl/tests/src/test_fonts/font_3.o ./LVGL/lvgl/tests/src/test_fonts/font_3.su ./LVGL/lvgl/tests/src/test_fonts/ubuntu_font.cyclo ./LVGL/lvgl/tests/src/test_fonts/ubuntu_font.d ./LVGL/lvgl/tests/src/test_fonts/ubuntu_font.o ./LVGL/lvgl/tests/src/test_fonts/ubuntu_font.su

.PHONY: clean-LVGL-2f-lvgl-2f-tests-2f-src-2f-test_fonts

