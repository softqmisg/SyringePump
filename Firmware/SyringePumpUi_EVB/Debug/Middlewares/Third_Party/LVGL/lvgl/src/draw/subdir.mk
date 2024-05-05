################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_layer.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_transform.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_layer.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_transform.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_layer.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_transform.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/draw/%.o Middlewares/Third_Party/LVGL/lvgl/src/draw/%.su Middlewares/Third_Party/LVGL/lvgl/src/draw/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/src/draw/%.c Middlewares/Third_Party/LVGL/lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_arc.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_img.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_label.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_layer.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_layer.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_layer.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_layer.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_line.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_mask.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_rect.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_transform.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_transform.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_transform.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_transform.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_draw_triangle.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_buf.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_cache.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/lv_img_decoder.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw

