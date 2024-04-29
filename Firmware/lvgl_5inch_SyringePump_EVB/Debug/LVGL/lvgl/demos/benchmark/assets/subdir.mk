################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.c \
../LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.c \
../LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.c \
../LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.c \
../LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.c \
../LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.c \
../LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.c \
../LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.c \
../LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.c 

OBJS += \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.o \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.o \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.o \
./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.o \
./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.o \
./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.o 

C_DEPS += \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.d \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.d \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d \
./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.d \
./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.d \
./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.d \
./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/demos/benchmark/assets/%.o LVGL/lvgl/demos/benchmark/assets/%.su LVGL/lvgl/demos/benchmark/assets/%.cyclo: ../LVGL/lvgl/demos/benchmark/assets/%.c LVGL/lvgl/demos/benchmark/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/lvgl_5inch_SyringePump_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-demos-2f-benchmark-2f-assets

clean-LVGL-2f-lvgl-2f-demos-2f-benchmark-2f-assets:
	-$(RM) ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.cyclo ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.d ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.o ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.su ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.cyclo ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.su ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.cyclo ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.d ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.o ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.su ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.cyclo ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.su ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.cyclo ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.su ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.cyclo ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.d ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.o ./LVGL/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb565a8.su ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.cyclo ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.d ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.o ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.su ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.cyclo ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.d ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.o ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.su ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.cyclo ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.d ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.o ./LVGL/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.su

.PHONY: clean-LVGL-2f-lvgl-2f-demos-2f-benchmark-2f-assets

