################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.c \
../LVGL/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.c 

OBJS += \
./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.o \
./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.o 

C_DEPS += \
./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.d \
./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/draw/renesas/%.o LVGL/lvgl/src/draw/renesas/%.su LVGL/lvgl/src/draw/renesas/%.cyclo: ../LVGL/lvgl/src/draw/renesas/%.c LVGL/lvgl/src/draw/renesas/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-renesas

clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-renesas:
	-$(RM) ./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.cyclo ./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.d ./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.o ./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_draw_label.su ./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.cyclo ./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.d ./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.o ./LVGL/lvgl/src/draw/renesas/lv_gpu_d2_ra6m3.su

.PHONY: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-renesas
