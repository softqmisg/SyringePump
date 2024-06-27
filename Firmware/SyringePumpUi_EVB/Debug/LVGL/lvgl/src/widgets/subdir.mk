################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/widgets/lv_arc.c \
../LVGL/lvgl/src/widgets/lv_bar.c \
../LVGL/lvgl/src/widgets/lv_btn.c \
../LVGL/lvgl/src/widgets/lv_btnmatrix.c \
../LVGL/lvgl/src/widgets/lv_canvas.c \
../LVGL/lvgl/src/widgets/lv_checkbox.c \
../LVGL/lvgl/src/widgets/lv_dropdown.c \
../LVGL/lvgl/src/widgets/lv_img.c \
../LVGL/lvgl/src/widgets/lv_label.c \
../LVGL/lvgl/src/widgets/lv_line.c \
../LVGL/lvgl/src/widgets/lv_objx_templ.c \
../LVGL/lvgl/src/widgets/lv_roller.c \
../LVGL/lvgl/src/widgets/lv_slider.c \
../LVGL/lvgl/src/widgets/lv_switch.c \
../LVGL/lvgl/src/widgets/lv_table.c \
../LVGL/lvgl/src/widgets/lv_textarea.c 

OBJS += \
./LVGL/lvgl/src/widgets/lv_arc.o \
./LVGL/lvgl/src/widgets/lv_bar.o \
./LVGL/lvgl/src/widgets/lv_btn.o \
./LVGL/lvgl/src/widgets/lv_btnmatrix.o \
./LVGL/lvgl/src/widgets/lv_canvas.o \
./LVGL/lvgl/src/widgets/lv_checkbox.o \
./LVGL/lvgl/src/widgets/lv_dropdown.o \
./LVGL/lvgl/src/widgets/lv_img.o \
./LVGL/lvgl/src/widgets/lv_label.o \
./LVGL/lvgl/src/widgets/lv_line.o \
./LVGL/lvgl/src/widgets/lv_objx_templ.o \
./LVGL/lvgl/src/widgets/lv_roller.o \
./LVGL/lvgl/src/widgets/lv_slider.o \
./LVGL/lvgl/src/widgets/lv_switch.o \
./LVGL/lvgl/src/widgets/lv_table.o \
./LVGL/lvgl/src/widgets/lv_textarea.o 

C_DEPS += \
./LVGL/lvgl/src/widgets/lv_arc.d \
./LVGL/lvgl/src/widgets/lv_bar.d \
./LVGL/lvgl/src/widgets/lv_btn.d \
./LVGL/lvgl/src/widgets/lv_btnmatrix.d \
./LVGL/lvgl/src/widgets/lv_canvas.d \
./LVGL/lvgl/src/widgets/lv_checkbox.d \
./LVGL/lvgl/src/widgets/lv_dropdown.d \
./LVGL/lvgl/src/widgets/lv_img.d \
./LVGL/lvgl/src/widgets/lv_label.d \
./LVGL/lvgl/src/widgets/lv_line.d \
./LVGL/lvgl/src/widgets/lv_objx_templ.d \
./LVGL/lvgl/src/widgets/lv_roller.d \
./LVGL/lvgl/src/widgets/lv_slider.d \
./LVGL/lvgl/src/widgets/lv_switch.d \
./LVGL/lvgl/src/widgets/lv_table.d \
./LVGL/lvgl/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/widgets/%.o LVGL/lvgl/src/widgets/%.su LVGL/lvgl/src/widgets/%.cyclo: ../LVGL/lvgl/src/widgets/%.c LVGL/lvgl/src/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-src-2f-widgets

clean-LVGL-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./LVGL/lvgl/src/widgets/lv_arc.cyclo ./LVGL/lvgl/src/widgets/lv_arc.d ./LVGL/lvgl/src/widgets/lv_arc.o ./LVGL/lvgl/src/widgets/lv_arc.su ./LVGL/lvgl/src/widgets/lv_bar.cyclo ./LVGL/lvgl/src/widgets/lv_bar.d ./LVGL/lvgl/src/widgets/lv_bar.o ./LVGL/lvgl/src/widgets/lv_bar.su ./LVGL/lvgl/src/widgets/lv_btn.cyclo ./LVGL/lvgl/src/widgets/lv_btn.d ./LVGL/lvgl/src/widgets/lv_btn.o ./LVGL/lvgl/src/widgets/lv_btn.su ./LVGL/lvgl/src/widgets/lv_btnmatrix.cyclo ./LVGL/lvgl/src/widgets/lv_btnmatrix.d ./LVGL/lvgl/src/widgets/lv_btnmatrix.o ./LVGL/lvgl/src/widgets/lv_btnmatrix.su ./LVGL/lvgl/src/widgets/lv_canvas.cyclo ./LVGL/lvgl/src/widgets/lv_canvas.d ./LVGL/lvgl/src/widgets/lv_canvas.o ./LVGL/lvgl/src/widgets/lv_canvas.su ./LVGL/lvgl/src/widgets/lv_checkbox.cyclo ./LVGL/lvgl/src/widgets/lv_checkbox.d ./LVGL/lvgl/src/widgets/lv_checkbox.o ./LVGL/lvgl/src/widgets/lv_checkbox.su ./LVGL/lvgl/src/widgets/lv_dropdown.cyclo ./LVGL/lvgl/src/widgets/lv_dropdown.d ./LVGL/lvgl/src/widgets/lv_dropdown.o ./LVGL/lvgl/src/widgets/lv_dropdown.su ./LVGL/lvgl/src/widgets/lv_img.cyclo ./LVGL/lvgl/src/widgets/lv_img.d ./LVGL/lvgl/src/widgets/lv_img.o ./LVGL/lvgl/src/widgets/lv_img.su ./LVGL/lvgl/src/widgets/lv_label.cyclo ./LVGL/lvgl/src/widgets/lv_label.d ./LVGL/lvgl/src/widgets/lv_label.o ./LVGL/lvgl/src/widgets/lv_label.su ./LVGL/lvgl/src/widgets/lv_line.cyclo ./LVGL/lvgl/src/widgets/lv_line.d ./LVGL/lvgl/src/widgets/lv_line.o ./LVGL/lvgl/src/widgets/lv_line.su ./LVGL/lvgl/src/widgets/lv_objx_templ.cyclo ./LVGL/lvgl/src/widgets/lv_objx_templ.d ./LVGL/lvgl/src/widgets/lv_objx_templ.o ./LVGL/lvgl/src/widgets/lv_objx_templ.su ./LVGL/lvgl/src/widgets/lv_roller.cyclo ./LVGL/lvgl/src/widgets/lv_roller.d ./LVGL/lvgl/src/widgets/lv_roller.o ./LVGL/lvgl/src/widgets/lv_roller.su ./LVGL/lvgl/src/widgets/lv_slider.cyclo ./LVGL/lvgl/src/widgets/lv_slider.d ./LVGL/lvgl/src/widgets/lv_slider.o ./LVGL/lvgl/src/widgets/lv_slider.su ./LVGL/lvgl/src/widgets/lv_switch.cyclo ./LVGL/lvgl/src/widgets/lv_switch.d ./LVGL/lvgl/src/widgets/lv_switch.o ./LVGL/lvgl/src/widgets/lv_switch.su ./LVGL/lvgl/src/widgets/lv_table.cyclo ./LVGL/lvgl/src/widgets/lv_table.d ./LVGL/lvgl/src/widgets/lv_table.o ./LVGL/lvgl/src/widgets/lv_table.su ./LVGL/lvgl/src/widgets/lv_textarea.cyclo ./LVGL/lvgl/src/widgets/lv_textarea.d ./LVGL/lvgl/src/widgets/lv_textarea.o ./LVGL/lvgl/src/widgets/lv_textarea.su

.PHONY: clean-LVGL-2f-lvgl-2f-src-2f-widgets

