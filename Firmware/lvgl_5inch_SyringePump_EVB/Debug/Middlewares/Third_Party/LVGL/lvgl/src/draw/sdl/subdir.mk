################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/%.o Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/%.su Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/%.c Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-sdl

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_img.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_label.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_layer.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_line.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-sdl

