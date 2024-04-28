################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/assets/animimg001.c \
../LVGL/lvgl/examples/assets/animimg002.c \
../LVGL/lvgl/examples/assets/animimg003.c \
../LVGL/lvgl/examples/assets/img_caret_down.c \
../LVGL/lvgl/examples/assets/img_cogwheel_alpha16.c \
../LVGL/lvgl/examples/assets/img_cogwheel_argb.c \
../LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.c \
../LVGL/lvgl/examples/assets/img_cogwheel_indexed16.c \
../LVGL/lvgl/examples/assets/img_cogwheel_rgb.c \
../LVGL/lvgl/examples/assets/img_hand.c \
../LVGL/lvgl/examples/assets/img_skew_strip.c \
../LVGL/lvgl/examples/assets/img_star.c \
../LVGL/lvgl/examples/assets/imgbtn_left.c \
../LVGL/lvgl/examples/assets/imgbtn_mid.c \
../LVGL/lvgl/examples/assets/imgbtn_right.c 

OBJS += \
./LVGL/lvgl/examples/assets/animimg001.o \
./LVGL/lvgl/examples/assets/animimg002.o \
./LVGL/lvgl/examples/assets/animimg003.o \
./LVGL/lvgl/examples/assets/img_caret_down.o \
./LVGL/lvgl/examples/assets/img_cogwheel_alpha16.o \
./LVGL/lvgl/examples/assets/img_cogwheel_argb.o \
./LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.o \
./LVGL/lvgl/examples/assets/img_cogwheel_indexed16.o \
./LVGL/lvgl/examples/assets/img_cogwheel_rgb.o \
./LVGL/lvgl/examples/assets/img_hand.o \
./LVGL/lvgl/examples/assets/img_skew_strip.o \
./LVGL/lvgl/examples/assets/img_star.o \
./LVGL/lvgl/examples/assets/imgbtn_left.o \
./LVGL/lvgl/examples/assets/imgbtn_mid.o \
./LVGL/lvgl/examples/assets/imgbtn_right.o 

C_DEPS += \
./LVGL/lvgl/examples/assets/animimg001.d \
./LVGL/lvgl/examples/assets/animimg002.d \
./LVGL/lvgl/examples/assets/animimg003.d \
./LVGL/lvgl/examples/assets/img_caret_down.d \
./LVGL/lvgl/examples/assets/img_cogwheel_alpha16.d \
./LVGL/lvgl/examples/assets/img_cogwheel_argb.d \
./LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.d \
./LVGL/lvgl/examples/assets/img_cogwheel_indexed16.d \
./LVGL/lvgl/examples/assets/img_cogwheel_rgb.d \
./LVGL/lvgl/examples/assets/img_hand.d \
./LVGL/lvgl/examples/assets/img_skew_strip.d \
./LVGL/lvgl/examples/assets/img_star.d \
./LVGL/lvgl/examples/assets/imgbtn_left.d \
./LVGL/lvgl/examples/assets/imgbtn_mid.d \
./LVGL/lvgl/examples/assets/imgbtn_right.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/assets/%.o LVGL/lvgl/examples/assets/%.su LVGL/lvgl/examples/assets/%.cyclo: ../LVGL/lvgl/examples/assets/%.c LVGL/lvgl/examples/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-assets

clean-LVGL-2f-lvgl-2f-examples-2f-assets:
	-$(RM) ./LVGL/lvgl/examples/assets/animimg001.cyclo ./LVGL/lvgl/examples/assets/animimg001.d ./LVGL/lvgl/examples/assets/animimg001.o ./LVGL/lvgl/examples/assets/animimg001.su ./LVGL/lvgl/examples/assets/animimg002.cyclo ./LVGL/lvgl/examples/assets/animimg002.d ./LVGL/lvgl/examples/assets/animimg002.o ./LVGL/lvgl/examples/assets/animimg002.su ./LVGL/lvgl/examples/assets/animimg003.cyclo ./LVGL/lvgl/examples/assets/animimg003.d ./LVGL/lvgl/examples/assets/animimg003.o ./LVGL/lvgl/examples/assets/animimg003.su ./LVGL/lvgl/examples/assets/img_caret_down.cyclo ./LVGL/lvgl/examples/assets/img_caret_down.d ./LVGL/lvgl/examples/assets/img_caret_down.o ./LVGL/lvgl/examples/assets/img_caret_down.su ./LVGL/lvgl/examples/assets/img_cogwheel_alpha16.cyclo ./LVGL/lvgl/examples/assets/img_cogwheel_alpha16.d ./LVGL/lvgl/examples/assets/img_cogwheel_alpha16.o ./LVGL/lvgl/examples/assets/img_cogwheel_alpha16.su ./LVGL/lvgl/examples/assets/img_cogwheel_argb.cyclo ./LVGL/lvgl/examples/assets/img_cogwheel_argb.d ./LVGL/lvgl/examples/assets/img_cogwheel_argb.o ./LVGL/lvgl/examples/assets/img_cogwheel_argb.su ./LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.cyclo ./LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.d ./LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.o ./LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.su ./LVGL/lvgl/examples/assets/img_cogwheel_indexed16.cyclo ./LVGL/lvgl/examples/assets/img_cogwheel_indexed16.d ./LVGL/lvgl/examples/assets/img_cogwheel_indexed16.o ./LVGL/lvgl/examples/assets/img_cogwheel_indexed16.su ./LVGL/lvgl/examples/assets/img_cogwheel_rgb.cyclo ./LVGL/lvgl/examples/assets/img_cogwheel_rgb.d ./LVGL/lvgl/examples/assets/img_cogwheel_rgb.o ./LVGL/lvgl/examples/assets/img_cogwheel_rgb.su ./LVGL/lvgl/examples/assets/img_hand.cyclo ./LVGL/lvgl/examples/assets/img_hand.d ./LVGL/lvgl/examples/assets/img_hand.o ./LVGL/lvgl/examples/assets/img_hand.su ./LVGL/lvgl/examples/assets/img_skew_strip.cyclo ./LVGL/lvgl/examples/assets/img_skew_strip.d ./LVGL/lvgl/examples/assets/img_skew_strip.o ./LVGL/lvgl/examples/assets/img_skew_strip.su ./LVGL/lvgl/examples/assets/img_star.cyclo ./LVGL/lvgl/examples/assets/img_star.d ./LVGL/lvgl/examples/assets/img_star.o ./LVGL/lvgl/examples/assets/img_star.su ./LVGL/lvgl/examples/assets/imgbtn_left.cyclo ./LVGL/lvgl/examples/assets/imgbtn_left.d ./LVGL/lvgl/examples/assets/imgbtn_left.o ./LVGL/lvgl/examples/assets/imgbtn_left.su ./LVGL/lvgl/examples/assets/imgbtn_mid.cyclo ./LVGL/lvgl/examples/assets/imgbtn_mid.d ./LVGL/lvgl/examples/assets/imgbtn_mid.o ./LVGL/lvgl/examples/assets/imgbtn_mid.su ./LVGL/lvgl/examples/assets/imgbtn_right.cyclo ./LVGL/lvgl/examples/assets/imgbtn_right.d ./LVGL/lvgl/examples/assets/imgbtn_right.o ./LVGL/lvgl/examples/assets/imgbtn_right.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-assets

