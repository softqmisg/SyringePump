################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/examples/porting/lv_port_disp_template.c \
../LVGL/lvgl/examples/porting/lv_port_fs_template.c \
../LVGL/lvgl/examples/porting/lv_port_indev_template.c 

OBJS += \
./LVGL/lvgl/examples/porting/lv_port_disp_template.o \
./LVGL/lvgl/examples/porting/lv_port_fs_template.o \
./LVGL/lvgl/examples/porting/lv_port_indev_template.o 

C_DEPS += \
./LVGL/lvgl/examples/porting/lv_port_disp_template.d \
./LVGL/lvgl/examples/porting/lv_port_fs_template.d \
./LVGL/lvgl/examples/porting/lv_port_indev_template.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/examples/porting/%.o LVGL/lvgl/examples/porting/%.su LVGL/lvgl/examples/porting/%.cyclo: ../LVGL/lvgl/examples/porting/%.c LVGL/lvgl/examples/porting/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-examples-2f-porting

clean-LVGL-2f-lvgl-2f-examples-2f-porting:
	-$(RM) ./LVGL/lvgl/examples/porting/lv_port_disp_template.cyclo ./LVGL/lvgl/examples/porting/lv_port_disp_template.d ./LVGL/lvgl/examples/porting/lv_port_disp_template.o ./LVGL/lvgl/examples/porting/lv_port_disp_template.su ./LVGL/lvgl/examples/porting/lv_port_fs_template.cyclo ./LVGL/lvgl/examples/porting/lv_port_fs_template.d ./LVGL/lvgl/examples/porting/lv_port_fs_template.o ./LVGL/lvgl/examples/porting/lv_port_fs_template.su ./LVGL/lvgl/examples/porting/lv_port_indev_template.cyclo ./LVGL/lvgl/examples/porting/lv_port_indev_template.d ./LVGL/lvgl/examples/porting/lv_port_indev_template.o ./LVGL/lvgl/examples/porting/lv_port_indev_template.su

.PHONY: clean-LVGL-2f-lvgl-2f-examples-2f-porting

