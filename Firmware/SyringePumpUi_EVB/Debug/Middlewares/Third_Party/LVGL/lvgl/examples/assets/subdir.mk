################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg001.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg002.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg003.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_caret_down.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_alpha16.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_argb.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_indexed16.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_rgb.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_hand.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_skew_strip.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_star.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_left.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_mid.c \
../Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_right.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg001.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg002.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg003.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_caret_down.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_alpha16.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_argb.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_indexed16.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_rgb.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_hand.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_skew_strip.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_star.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_left.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_mid.o \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_right.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg001.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg002.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg003.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_caret_down.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_alpha16.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_argb.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_indexed16.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_rgb.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_hand.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_skew_strip.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_star.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_left.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_mid.d \
./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_right.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/examples/assets/%.o Middlewares/Third_Party/LVGL/lvgl/examples/assets/%.su Middlewares/Third_Party/LVGL/lvgl/examples/assets/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/examples/assets/%.c Middlewares/Third_Party/LVGL/lvgl/examples/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-assets

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-assets:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg001.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg001.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg001.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg001.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg002.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg002.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg002.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg002.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg003.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg003.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg003.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/animimg003.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_caret_down.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_caret_down.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_caret_down.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_caret_down.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_alpha16.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_alpha16.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_alpha16.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_alpha16.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_argb.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_argb.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_argb.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_argb.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_chroma_keyed.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_indexed16.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_indexed16.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_indexed16.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_indexed16.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_rgb.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_rgb.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_rgb.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_cogwheel_rgb.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_hand.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_hand.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_hand.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_hand.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_skew_strip.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_skew_strip.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_skew_strip.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_skew_strip.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_star.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_star.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_star.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/img_star.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_left.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_left.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_left.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_left.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_mid.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_mid.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_mid.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_mid.su ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_right.cyclo ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_right.d ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_right.o ./Middlewares/Third_Party/LVGL/lvgl/examples/assets/imgbtn_right.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-examples-2f-assets

