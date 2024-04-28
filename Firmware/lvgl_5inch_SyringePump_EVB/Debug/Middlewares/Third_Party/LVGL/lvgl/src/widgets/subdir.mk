################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.c \
../Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.o \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.d \
./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/widgets/%.o Middlewares/Third_Party/LVGL/lvgl/src/widgets/%.su Middlewares/Third_Party/LVGL/lvgl/src/widgets/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/src/widgets/%.c Middlewares/Third_Party/LVGL/lvgl/src/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-widgets

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_arc.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_bar.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btn.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_btnmatrix.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_canvas.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_checkbox.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_dropdown.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_img.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_label.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_line.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_objx_templ.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_roller.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_slider.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_switch.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_table.su ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.d ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.o ./Middlewares/Third_Party/LVGL/lvgl/src/widgets/lv_textarea.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-widgets

