################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.c \
../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.c \
../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.c \
../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.c \
../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.c \
../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.c \
../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.c \
../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.c \
../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.o \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.o \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.o \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.o \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.o \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.d \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.d \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.d \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.d \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.d \
./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/%.o Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/%.su Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/%.c Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-demos-2f-benchmark-2f-assets

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-demos-2f-benchmark-2f-assets:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.cyclo ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.d ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.o ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.su ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.cyclo ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.su ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.cyclo ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.d ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.o ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.su ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.cyclo ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.su ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.cyclo ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.su ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.cyclo ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.d ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.o ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.su ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.cyclo ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.d ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.o ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.su ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.cyclo ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.d ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.o ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.su ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.cyclo ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.d ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.o ./Middlewares/Third_Party/LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-demos-2f-benchmark-2f-assets

