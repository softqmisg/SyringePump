################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/draw/sw/lv_draw_sw.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_img.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_layer.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_line.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.c \
../LVGL/lvgl/src/draw/sw/lv_draw_sw_transform.c 

OBJS += \
./LVGL/lvgl/src/draw/sw/lv_draw_sw.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_img.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_layer.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_line.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.o \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_transform.o 

C_DEPS += \
./LVGL/lvgl/src/draw/sw/lv_draw_sw.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_img.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_layer.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_line.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.d \
./LVGL/lvgl/src/draw/sw/lv_draw_sw_transform.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/draw/sw/%.o LVGL/lvgl/src/draw/sw/%.su LVGL/lvgl/src/draw/sw/%.cyclo: ../LVGL/lvgl/src/draw/sw/%.c LVGL/lvgl/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-sw

clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./LVGL/lvgl/src/draw/sw/lv_draw_sw.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_arc.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_blend.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_dither.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_gradient.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_img.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_img.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_img.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_img.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_layer.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_layer.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_layer.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_layer.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_letter.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_line.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_line.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_line.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_line.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_polygon.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_rect.su ./LVGL/lvgl/src/draw/sw/lv_draw_sw_transform.cyclo ./LVGL/lvgl/src/draw/sw/lv_draw_sw_transform.d ./LVGL/lvgl/src/draw/sw/lv_draw_sw_transform.o ./LVGL/lvgl/src/draw/sw/lv_draw_sw_transform.su

.PHONY: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-sw

