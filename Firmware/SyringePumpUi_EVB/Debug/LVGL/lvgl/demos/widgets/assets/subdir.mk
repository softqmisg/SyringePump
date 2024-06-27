################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/demos/widgets/assets/img_clothes.c \
../LVGL/lvgl/demos/widgets/assets/img_demo_widgets_avatar.c \
../LVGL/lvgl/demos/widgets/assets/img_lvgl_logo.c 

OBJS += \
./LVGL/lvgl/demos/widgets/assets/img_clothes.o \
./LVGL/lvgl/demos/widgets/assets/img_demo_widgets_avatar.o \
./LVGL/lvgl/demos/widgets/assets/img_lvgl_logo.o 

C_DEPS += \
./LVGL/lvgl/demos/widgets/assets/img_clothes.d \
./LVGL/lvgl/demos/widgets/assets/img_demo_widgets_avatar.d \
./LVGL/lvgl/demos/widgets/assets/img_lvgl_logo.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/demos/widgets/assets/%.o LVGL/lvgl/demos/widgets/assets/%.su LVGL/lvgl/demos/widgets/assets/%.cyclo: ../LVGL/lvgl/demos/widgets/assets/%.c LVGL/lvgl/demos/widgets/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Pump_inc" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Designs/Javad_works/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-demos-2f-widgets-2f-assets

clean-LVGL-2f-lvgl-2f-demos-2f-widgets-2f-assets:
	-$(RM) ./LVGL/lvgl/demos/widgets/assets/img_clothes.cyclo ./LVGL/lvgl/demos/widgets/assets/img_clothes.d ./LVGL/lvgl/demos/widgets/assets/img_clothes.o ./LVGL/lvgl/demos/widgets/assets/img_clothes.su ./LVGL/lvgl/demos/widgets/assets/img_demo_widgets_avatar.cyclo ./LVGL/lvgl/demos/widgets/assets/img_demo_widgets_avatar.d ./LVGL/lvgl/demos/widgets/assets/img_demo_widgets_avatar.o ./LVGL/lvgl/demos/widgets/assets/img_demo_widgets_avatar.su ./LVGL/lvgl/demos/widgets/assets/img_lvgl_logo.cyclo ./LVGL/lvgl/demos/widgets/assets/img_lvgl_logo.d ./LVGL/lvgl/demos/widgets/assets/img_lvgl_logo.o ./LVGL/lvgl/demos/widgets/assets/img_lvgl_logo.su

.PHONY: clean-LVGL-2f-lvgl-2f-demos-2f-widgets-2f-assets

