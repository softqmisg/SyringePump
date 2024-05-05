################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.c \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.c \
../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.c 

OBJS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.o \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.o \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.o 

C_DEPS += \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.d \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.d \
./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/%.o Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/%.su Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/%.cyclo: ../Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/%.c Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Utilities" -I"E:/Designs/EWB-STM32-NANO-FULL-STM32H743IIT6-V4.0/Myexample/lvgl_5inch_800x480/Middlewares/Third_Party/LVGL" -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-calendar

clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-calendar:
	-$(RM) ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar.su ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.su ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.cyclo ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.d ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.o ./Middlewares/Third_Party/LVGL/lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-LVGL-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-calendar

