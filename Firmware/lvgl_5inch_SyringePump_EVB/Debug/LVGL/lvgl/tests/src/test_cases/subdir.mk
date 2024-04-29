################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/tests/src/test_cases/_test_template.c \
../LVGL/lvgl/tests/src/test_cases/test_arc.c \
../LVGL/lvgl/tests/src/test_cases/test_bar.c \
../LVGL/lvgl/tests/src/test_cases/test_checkbox.c \
../LVGL/lvgl/tests/src/test_cases/test_config.c \
../LVGL/lvgl/tests/src/test_cases/test_demo_stress.c \
../LVGL/lvgl/tests/src/test_cases/test_demo_widgets.c \
../LVGL/lvgl/tests/src/test_cases/test_dropdown.c \
../LVGL/lvgl/tests/src/test_cases/test_event.c \
../LVGL/lvgl/tests/src/test_cases/test_font_loader.c \
../LVGL/lvgl/tests/src/test_cases/test_fs.c \
../LVGL/lvgl/tests/src/test_cases/test_line.c \
../LVGL/lvgl/tests/src/test_cases/test_mem.c \
../LVGL/lvgl/tests/src/test_cases/test_obj_tree.c \
../LVGL/lvgl/tests/src/test_cases/test_screen_load.c \
../LVGL/lvgl/tests/src/test_cases/test_slider.c \
../LVGL/lvgl/tests/src/test_cases/test_snapshot.c \
../LVGL/lvgl/tests/src/test_cases/test_style.c \
../LVGL/lvgl/tests/src/test_cases/test_switch.c \
../LVGL/lvgl/tests/src/test_cases/test_table.c \
../LVGL/lvgl/tests/src/test_cases/test_textarea.c \
../LVGL/lvgl/tests/src/test_cases/test_tiny_ttf.c \
../LVGL/lvgl/tests/src/test_cases/test_txt.c 

OBJS += \
./LVGL/lvgl/tests/src/test_cases/_test_template.o \
./LVGL/lvgl/tests/src/test_cases/test_arc.o \
./LVGL/lvgl/tests/src/test_cases/test_bar.o \
./LVGL/lvgl/tests/src/test_cases/test_checkbox.o \
./LVGL/lvgl/tests/src/test_cases/test_config.o \
./LVGL/lvgl/tests/src/test_cases/test_demo_stress.o \
./LVGL/lvgl/tests/src/test_cases/test_demo_widgets.o \
./LVGL/lvgl/tests/src/test_cases/test_dropdown.o \
./LVGL/lvgl/tests/src/test_cases/test_event.o \
./LVGL/lvgl/tests/src/test_cases/test_font_loader.o \
./LVGL/lvgl/tests/src/test_cases/test_fs.o \
./LVGL/lvgl/tests/src/test_cases/test_line.o \
./LVGL/lvgl/tests/src/test_cases/test_mem.o \
./LVGL/lvgl/tests/src/test_cases/test_obj_tree.o \
./LVGL/lvgl/tests/src/test_cases/test_screen_load.o \
./LVGL/lvgl/tests/src/test_cases/test_slider.o \
./LVGL/lvgl/tests/src/test_cases/test_snapshot.o \
./LVGL/lvgl/tests/src/test_cases/test_style.o \
./LVGL/lvgl/tests/src/test_cases/test_switch.o \
./LVGL/lvgl/tests/src/test_cases/test_table.o \
./LVGL/lvgl/tests/src/test_cases/test_textarea.o \
./LVGL/lvgl/tests/src/test_cases/test_tiny_ttf.o \
./LVGL/lvgl/tests/src/test_cases/test_txt.o 

C_DEPS += \
./LVGL/lvgl/tests/src/test_cases/_test_template.d \
./LVGL/lvgl/tests/src/test_cases/test_arc.d \
./LVGL/lvgl/tests/src/test_cases/test_bar.d \
./LVGL/lvgl/tests/src/test_cases/test_checkbox.d \
./LVGL/lvgl/tests/src/test_cases/test_config.d \
./LVGL/lvgl/tests/src/test_cases/test_demo_stress.d \
./LVGL/lvgl/tests/src/test_cases/test_demo_widgets.d \
./LVGL/lvgl/tests/src/test_cases/test_dropdown.d \
./LVGL/lvgl/tests/src/test_cases/test_event.d \
./LVGL/lvgl/tests/src/test_cases/test_font_loader.d \
./LVGL/lvgl/tests/src/test_cases/test_fs.d \
./LVGL/lvgl/tests/src/test_cases/test_line.d \
./LVGL/lvgl/tests/src/test_cases/test_mem.d \
./LVGL/lvgl/tests/src/test_cases/test_obj_tree.d \
./LVGL/lvgl/tests/src/test_cases/test_screen_load.d \
./LVGL/lvgl/tests/src/test_cases/test_slider.d \
./LVGL/lvgl/tests/src/test_cases/test_snapshot.d \
./LVGL/lvgl/tests/src/test_cases/test_style.d \
./LVGL/lvgl/tests/src/test_cases/test_switch.d \
./LVGL/lvgl/tests/src/test_cases/test_table.d \
./LVGL/lvgl/tests/src/test_cases/test_textarea.d \
./LVGL/lvgl/tests/src/test_cases/test_tiny_ttf.d \
./LVGL/lvgl/tests/src/test_cases/test_txt.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/tests/src/test_cases/%.o LVGL/lvgl/tests/src/test_cases/%.su LVGL/lvgl/tests/src/test_cases/%.cyclo: ../LVGL/lvgl/tests/src/test_cases/%.c LVGL/lvgl/tests/src/test_cases/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-tests-2f-src-2f-test_cases

clean-LVGL-2f-lvgl-2f-tests-2f-src-2f-test_cases:
	-$(RM) ./LVGL/lvgl/tests/src/test_cases/_test_template.cyclo ./LVGL/lvgl/tests/src/test_cases/_test_template.d ./LVGL/lvgl/tests/src/test_cases/_test_template.o ./LVGL/lvgl/tests/src/test_cases/_test_template.su ./LVGL/lvgl/tests/src/test_cases/test_arc.cyclo ./LVGL/lvgl/tests/src/test_cases/test_arc.d ./LVGL/lvgl/tests/src/test_cases/test_arc.o ./LVGL/lvgl/tests/src/test_cases/test_arc.su ./LVGL/lvgl/tests/src/test_cases/test_bar.cyclo ./LVGL/lvgl/tests/src/test_cases/test_bar.d ./LVGL/lvgl/tests/src/test_cases/test_bar.o ./LVGL/lvgl/tests/src/test_cases/test_bar.su ./LVGL/lvgl/tests/src/test_cases/test_checkbox.cyclo ./LVGL/lvgl/tests/src/test_cases/test_checkbox.d ./LVGL/lvgl/tests/src/test_cases/test_checkbox.o ./LVGL/lvgl/tests/src/test_cases/test_checkbox.su ./LVGL/lvgl/tests/src/test_cases/test_config.cyclo ./LVGL/lvgl/tests/src/test_cases/test_config.d ./LVGL/lvgl/tests/src/test_cases/test_config.o ./LVGL/lvgl/tests/src/test_cases/test_config.su ./LVGL/lvgl/tests/src/test_cases/test_demo_stress.cyclo ./LVGL/lvgl/tests/src/test_cases/test_demo_stress.d ./LVGL/lvgl/tests/src/test_cases/test_demo_stress.o ./LVGL/lvgl/tests/src/test_cases/test_demo_stress.su ./LVGL/lvgl/tests/src/test_cases/test_demo_widgets.cyclo ./LVGL/lvgl/tests/src/test_cases/test_demo_widgets.d ./LVGL/lvgl/tests/src/test_cases/test_demo_widgets.o ./LVGL/lvgl/tests/src/test_cases/test_demo_widgets.su ./LVGL/lvgl/tests/src/test_cases/test_dropdown.cyclo ./LVGL/lvgl/tests/src/test_cases/test_dropdown.d ./LVGL/lvgl/tests/src/test_cases/test_dropdown.o ./LVGL/lvgl/tests/src/test_cases/test_dropdown.su ./LVGL/lvgl/tests/src/test_cases/test_event.cyclo ./LVGL/lvgl/tests/src/test_cases/test_event.d ./LVGL/lvgl/tests/src/test_cases/test_event.o ./LVGL/lvgl/tests/src/test_cases/test_event.su ./LVGL/lvgl/tests/src/test_cases/test_font_loader.cyclo ./LVGL/lvgl/tests/src/test_cases/test_font_loader.d ./LVGL/lvgl/tests/src/test_cases/test_font_loader.o ./LVGL/lvgl/tests/src/test_cases/test_font_loader.su ./LVGL/lvgl/tests/src/test_cases/test_fs.cyclo ./LVGL/lvgl/tests/src/test_cases/test_fs.d ./LVGL/lvgl/tests/src/test_cases/test_fs.o ./LVGL/lvgl/tests/src/test_cases/test_fs.su ./LVGL/lvgl/tests/src/test_cases/test_line.cyclo ./LVGL/lvgl/tests/src/test_cases/test_line.d ./LVGL/lvgl/tests/src/test_cases/test_line.o ./LVGL/lvgl/tests/src/test_cases/test_line.su ./LVGL/lvgl/tests/src/test_cases/test_mem.cyclo ./LVGL/lvgl/tests/src/test_cases/test_mem.d ./LVGL/lvgl/tests/src/test_cases/test_mem.o ./LVGL/lvgl/tests/src/test_cases/test_mem.su ./LVGL/lvgl/tests/src/test_cases/test_obj_tree.cyclo ./LVGL/lvgl/tests/src/test_cases/test_obj_tree.d ./LVGL/lvgl/tests/src/test_cases/test_obj_tree.o ./LVGL/lvgl/tests/src/test_cases/test_obj_tree.su ./LVGL/lvgl/tests/src/test_cases/test_screen_load.cyclo ./LVGL/lvgl/tests/src/test_cases/test_screen_load.d ./LVGL/lvgl/tests/src/test_cases/test_screen_load.o ./LVGL/lvgl/tests/src/test_cases/test_screen_load.su ./LVGL/lvgl/tests/src/test_cases/test_slider.cyclo ./LVGL/lvgl/tests/src/test_cases/test_slider.d ./LVGL/lvgl/tests/src/test_cases/test_slider.o ./LVGL/lvgl/tests/src/test_cases/test_slider.su ./LVGL/lvgl/tests/src/test_cases/test_snapshot.cyclo ./LVGL/lvgl/tests/src/test_cases/test_snapshot.d ./LVGL/lvgl/tests/src/test_cases/test_snapshot.o ./LVGL/lvgl/tests/src/test_cases/test_snapshot.su ./LVGL/lvgl/tests/src/test_cases/test_style.cyclo ./LVGL/lvgl/tests/src/test_cases/test_style.d ./LVGL/lvgl/tests/src/test_cases/test_style.o ./LVGL/lvgl/tests/src/test_cases/test_style.su ./LVGL/lvgl/tests/src/test_cases/test_switch.cyclo ./LVGL/lvgl/tests/src/test_cases/test_switch.d ./LVGL/lvgl/tests/src/test_cases/test_switch.o ./LVGL/lvgl/tests/src/test_cases/test_switch.su ./LVGL/lvgl/tests/src/test_cases/test_table.cyclo ./LVGL/lvgl/tests/src/test_cases/test_table.d ./LVGL/lvgl/tests/src/test_cases/test_table.o ./LVGL/lvgl/tests/src/test_cases/test_table.su ./LVGL/lvgl/tests/src/test_cases/test_textarea.cyclo ./LVGL/lvgl/tests/src/test_cases/test_textarea.d ./LVGL/lvgl/tests/src/test_cases/test_textarea.o ./LVGL/lvgl/tests/src/test_cases/test_textarea.su ./LVGL/lvgl/tests/src/test_cases/test_tiny_ttf.cyclo ./LVGL/lvgl/tests/src/test_cases/test_tiny_ttf.d ./LVGL/lvgl/tests/src/test_cases/test_tiny_ttf.o ./LVGL/lvgl/tests/src/test_cases/test_tiny_ttf.su ./LVGL/lvgl/tests/src/test_cases/test_txt.cyclo ./LVGL/lvgl/tests/src/test_cases/test_txt.d ./LVGL/lvgl/tests/src/test_cases/test_txt.o ./LVGL/lvgl/tests/src/test_cases/test_txt.su

.PHONY: clean-LVGL-2f-lvgl-2f-tests-2f-src-2f-test_cases

