################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Feedbacker/Feedbacker.cpp 

OBJS += \
./Feedbacker/Feedbacker.o 

CPP_DEPS += \
./Feedbacker/Feedbacker.d 


# Each subdirectory must supply rules for building sources it contributes
Feedbacker/%.o: ../Feedbacker/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoCore" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoCore/variants/standard" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/BufferedInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/BufferedOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/ByteArrayInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/ByteArrayOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/Closeable" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/DataInput" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/DataInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/DataOutput" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/DataOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/ExternalEepromInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/ExternalEepromOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/FilterInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/FilterOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/GprsInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/GprsOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/HardwareSerialInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/HardwareSerialOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/InputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/InternalEepromInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/InternalEepromOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/OutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/PgmspaceInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/PgmspaceSeekableInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/RandomAccess" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/RandomAccessByteArray" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/RandomAccessExternalEeprom" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/RandomAccessResource" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/RegisterBasedWiredDeviceInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/ResourceInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/ResourceOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/ResourceSeekableInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoSecretPatternLock" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoSecretPatternLock/Feedbacker" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoSecretPatternLock/KnockLock" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoSecretPatternLock/LedFeedbacker" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/Seekable" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/SeekableInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/SeekableOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/SerialInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/SerialOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/SoftwareSerialInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/SoftwareSerialOutputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/WireInputStream" -I"/work/opensource/personal/microcontroller/arduino/ArduinoLibraries/ArduinoIO/WireOutputStream" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


