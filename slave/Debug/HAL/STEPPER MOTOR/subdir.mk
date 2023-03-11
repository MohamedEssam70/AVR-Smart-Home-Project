################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/STEPPER\ MOTOR/STEPPER_prg.c 

OBJS += \
./HAL/STEPPER\ MOTOR/STEPPER_prg.o 

C_DEPS += \
./HAL/STEPPER\ MOTOR/STEPPER_prg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/STEPPER\ MOTOR/STEPPER_prg.o: ../HAL/STEPPER\ MOTOR/STEPPER_prg.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"HAL/STEPPER MOTOR/STEPPER_prg.d" -MT"HAL/STEPPER\ MOTOR/STEPPER_prg.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


