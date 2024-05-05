################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.c \
../Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.o \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.d \
./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/core/%.o Middlewares/Third_Party/LVGL/lvgl/src/core/%.su Middlewares/Third_Party/LVGL/lvgl/src/core/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/src/core/%.c Middlewares/Third_Party/LVGL/lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-core

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-core:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_disp.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_event.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_group.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_indev_scroll.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_class.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_draw.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_pos.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_scroll.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_style_gen.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_obj_tree.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_refr.su ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.d ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.o ./Middlewares/Third_Party/LVGL/lvgl/src/core/lv_theme.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-core

