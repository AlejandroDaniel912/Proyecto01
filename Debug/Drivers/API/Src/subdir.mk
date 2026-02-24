################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_BMP180.c \
../Drivers/API/Src/API_Delay.c \
../Drivers/API/Src/API_GPIO.c \
../Drivers/API/Src/DHT11_01.c \
../Drivers/API/Src/Driver_PWM.c \
../Drivers/API/Src/vivero_hc05.c 

OBJS += \
./Drivers/API/Src/API_BMP180.o \
./Drivers/API/Src/API_Delay.o \
./Drivers/API/Src/API_GPIO.o \
./Drivers/API/Src/DHT11_01.o \
./Drivers/API/Src/Driver_PWM.o \
./Drivers/API/Src/vivero_hc05.o 

C_DEPS += \
./Drivers/API/Src/API_BMP180.d \
./Drivers/API/Src/API_Delay.d \
./Drivers/API/Src/API_GPIO.d \
./Drivers/API/Src/DHT11_01.d \
./Drivers/API/Src/Driver_PWM.d \
./Drivers/API/Src/vivero_hc05.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ale55/STM32CubeIDE/workspace_1.18.1/Project_PruebaBMP01/Drivers/API/Inc" -I"C:/Users/ale55/STM32CubeIDE/workspace_1.18.1/Project_PruebaBMP01/Drivers/API/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_BMP180.cyclo ./Drivers/API/Src/API_BMP180.d ./Drivers/API/Src/API_BMP180.o ./Drivers/API/Src/API_BMP180.su ./Drivers/API/Src/API_Delay.cyclo ./Drivers/API/Src/API_Delay.d ./Drivers/API/Src/API_Delay.o ./Drivers/API/Src/API_Delay.su ./Drivers/API/Src/API_GPIO.cyclo ./Drivers/API/Src/API_GPIO.d ./Drivers/API/Src/API_GPIO.o ./Drivers/API/Src/API_GPIO.su ./Drivers/API/Src/DHT11_01.cyclo ./Drivers/API/Src/DHT11_01.d ./Drivers/API/Src/DHT11_01.o ./Drivers/API/Src/DHT11_01.su ./Drivers/API/Src/Driver_PWM.cyclo ./Drivers/API/Src/Driver_PWM.d ./Drivers/API/Src/Driver_PWM.o ./Drivers/API/Src/Driver_PWM.su ./Drivers/API/Src/vivero_hc05.cyclo ./Drivers/API/Src/vivero_hc05.d ./Drivers/API/Src/vivero_hc05.o ./Drivers/API/Src/vivero_hc05.su

.PHONY: clean-Drivers-2f-API-2f-Src

