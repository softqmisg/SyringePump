################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite.c \
../LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.c \
../LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.c \
../LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.c \
../LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.c \
../LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_buf.c \
../LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_utils.c 

OBJS += \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite.o \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.o \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.o \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.o \
./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_buf.o \
./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_utils.o 

C_DEPS += \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite.d \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.d \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.d \
./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.d \
./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_buf.d \
./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/draw/nxp/vglite/%.o LVGL/lvgl/src/draw/nxp/vglite/%.su LVGL/lvgl/src/draw/nxp/vglite/%.cyclo: ../LVGL/lvgl/src/draw/nxp/vglite/%.c LVGL/lvgl/src/draw/nxp/vglite/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite:
	-$(RM) ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite.cyclo ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite.d ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite.o ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite.su ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.cyclo ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.d ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.o ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_arc.su ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.cyclo ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.d ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.o ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_blend.su ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.cyclo ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.d ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.o ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_line.su ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.cyclo ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.d ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.o ./LVGL/lvgl/src/draw/nxp/vglite/lv_draw_vglite_rect.su ./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_buf.cyclo ./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_buf.d ./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_buf.o ./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_buf.su ./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_utils.cyclo ./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_utils.d ./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_utils.o ./LVGL/lvgl/src/draw/nxp/vglite/lv_vglite_utils.su

.PHONY: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-vglite

