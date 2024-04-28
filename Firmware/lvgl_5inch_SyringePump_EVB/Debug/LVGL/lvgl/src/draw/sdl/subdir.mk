################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/draw/sdl/%.o LVGL/lvgl/src/draw/sdl/%.su LVGL/lvgl/src/draw/sdl/%.cyclo: ../LVGL/lvgl/src/draw/sdl/%.c LVGL/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-sdl

clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.cyclo ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-sdl

