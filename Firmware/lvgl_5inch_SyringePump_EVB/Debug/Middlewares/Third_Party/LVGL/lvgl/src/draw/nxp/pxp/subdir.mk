################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.c \
../Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.o \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.d \
./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/%.o Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/%.su Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/%.c Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_draw_pxp_blend.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp.su ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.d ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.o ./Middlewares/Third_Party/LVGL/lvgl/src/draw/nxp/pxp/lv_gpu_nxp_pxp_osa.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

