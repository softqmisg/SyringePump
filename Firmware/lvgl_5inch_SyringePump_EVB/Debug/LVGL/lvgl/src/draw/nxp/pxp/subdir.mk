################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.c \
../LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.c \
../LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.c \
../LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.c 

OBJS += \
./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.o \
./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.o \
./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.o \
./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.o 

C_DEPS += \
./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.d \
./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.d \
./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.d \
./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/draw/nxp/pxp/%.o LVGL/lvgl/src/draw/nxp/pxp/%.su LVGL/lvgl/src/draw/nxp/pxp/%.cyclo: ../LVGL/lvgl/src/draw/nxp/pxp/%.c LVGL/lvgl/src/draw/nxp/pxp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp:
	-$(RM) ./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.cyclo ./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.d ./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.o ./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.su ./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.cyclo ./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.d ./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.o ./LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.su ./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.cyclo ./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.d ./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.o ./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.su ./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.cyclo ./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.d ./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.o ./LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.su

.PHONY: clean-LVGL-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

