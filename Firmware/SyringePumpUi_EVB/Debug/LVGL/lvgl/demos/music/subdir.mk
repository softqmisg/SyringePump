################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/demos/music/lv_demo_music.c \
../LVGL/lvgl/demos/music/lv_demo_music_list.c \
../LVGL/lvgl/demos/music/lv_demo_music_main.c 

OBJS += \
./LVGL/lvgl/demos/music/lv_demo_music.o \
./LVGL/lvgl/demos/music/lv_demo_music_list.o \
./LVGL/lvgl/demos/music/lv_demo_music_main.o 

C_DEPS += \
./LVGL/lvgl/demos/music/lv_demo_music.d \
./LVGL/lvgl/demos/music/lv_demo_music_list.d \
./LVGL/lvgl/demos/music/lv_demo_music_main.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/demos/music/%.o LVGL/lvgl/demos/music/%.su LVGL/lvgl/demos/music/%.cyclo: ../LVGL/lvgl/demos/music/%.c LVGL/lvgl/demos/music/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-demos-2f-music

clean-LVGL-2f-lvgl-2f-demos-2f-music:
	-$(RM) ./LVGL/lvgl/demos/music/lv_demo_music.cyclo ./LVGL/lvgl/demos/music/lv_demo_music.d ./LVGL/lvgl/demos/music/lv_demo_music.o ./LVGL/lvgl/demos/music/lv_demo_music.su ./LVGL/lvgl/demos/music/lv_demo_music_list.cyclo ./LVGL/lvgl/demos/music/lv_demo_music_list.d ./LVGL/lvgl/demos/music/lv_demo_music_list.o ./LVGL/lvgl/demos/music/lv_demo_music_list.su ./LVGL/lvgl/demos/music/lv_demo_music_main.cyclo ./LVGL/lvgl/demos/music/lv_demo_music_main.d ./LVGL/lvgl/demos/music/lv_demo_music_main.o ./LVGL/lvgl/demos/music/lv_demo_music_main.su

.PHONY: clean-LVGL-2f-lvgl-2f-demos-2f-music

