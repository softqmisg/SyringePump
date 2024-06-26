################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.c \
../LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_littlefs.c \
../LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_posix.c \
../LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_rawfs.c \
../LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.c \
../LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_win32.c 

OBJS += \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.o \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_littlefs.o \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_posix.o \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_rawfs.o \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.o \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_win32.o 

C_DEPS += \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.d \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_littlefs.d \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_posix.d \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_rawfs.d \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.d \
./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_win32.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/lvgl/src/extra/libs/fsdrv/%.o LVGL/lvgl/src/extra/libs/fsdrv/%.su LVGL/lvgl/src/extra/libs/fsdrv/%.cyclo: ../LVGL/lvgl/src/extra/libs/fsdrv/%.c LVGL/lvgl/src/extra/libs/fsdrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL/lvgl" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/LVGL" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Inc/Lvgl_Ui" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/custom" -I"E:/Workspace/SyringePump/Firmware/SyringePumpUi_EVB/Core/Src/Lvgl_Ui/generated" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LVGL-2f-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv

clean-LVGL-2f-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv:
	-$(RM) ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.cyclo ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.d ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.o ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_fatfs.su ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_littlefs.cyclo ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_littlefs.d ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_littlefs.o ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_littlefs.su ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_posix.cyclo ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_posix.d ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_posix.o ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_posix.su ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_rawfs.cyclo ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_rawfs.d ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_rawfs.o ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_rawfs.su ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.cyclo ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.d ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.o ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_stdio.su ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_win32.cyclo ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_win32.d ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_win32.o ./LVGL/lvgl/src/extra/libs/fsdrv/lv_fs_win32.su

.PHONY: clean-LVGL-2f-lvgl-2f-src-2f-extra-2f-libs-2f-fsdrv

