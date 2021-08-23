################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../ADC.c \
../ADC_Cfg.c \
../Heater_Controller.c \
../Timer_2.c \
../PWM.c \
../Display_Manager.c \
../KEYPAD.c \
../KEYPAD_Cfg.c \
../LCD.c \
../DIO.c \
../LCD_Cfg.c \
../main.c \
../SPI.c \
../SPI_Cfg.c \
../TC72.c \
../Temp_Manager.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ADC.o \
ADC_Cfg.o \
Heater_Controller.o \
Timer_2.o \
PWM.o \
Display_Manager.o \
KEYPAD.o \
KEYPAD_Cfg.o \
LCD.o \
DIO.o \
LCD_Cfg.o \
main.o \
SPI.o \
SPI_Cfg.o \
TC72.o \
Temp_Manager.o


OBJS_AS_ARGS +=  \
ADC.o \
ADC_Cfg.o \
Heater_Controller.o \
Timer_2.o \
PWM.o \
Display_Manager.o \
KEYPAD.o \
KEYPAD_Cfg.o \
LCD.o \
DIO.o \
LCD_Cfg.o \
main.o \
SPI.o \
SPI_Cfg.o \
TC72.o \
Temp_Manager.o


C_DEPS +=  \
ADC.d \
ADC_Cfg.d \
Heater_Controller.d \
Timer_2.d \
PWM.d \
Display_Manager.d \
KEYPAD.d \
KEYPAD_Cfg.d \
LCD.d \
DIO.d \
LCD_Cfg.d \
main.d \
SPI.d \
SPI_Cfg.d \
TC72.d \
Temp_Manager.d


C_DEPS_AS_ARGS +=  \
ADC.d \
ADC_Cfg.d \
Heater_Controller.d \
Timer_2.d \
PWM.d \
Display_Manager.d \
KEYPAD.d \
KEYPAD_Cfg.d \
LCD.d \
DIO.d \
LCD_Cfg.d \
main.d \
SPI.d \
SPI_Cfg.d \
TC72.d \
Temp_Manager.d


OUTPUT_FILE_PATH +=GccApplication1.elf

OUTPUT_FILE_PATH_AS_ARGS +=GccApplication1.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

# AVR32/GNU C Compiler

































./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)E:\Atmel Studio\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -funsigned-char -funsigned-bitfields -O1 -fpack-struct -fshort-enums -g2 -Wall -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"  -mmcu=atmega32   -o"$@" "$<" 
	@echo Finished building: $<



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : (AVR_8_bit_GNU_Toolchain_3.4.1_830) 4.6.2
	$(QUOTE)E:\Atmel Studio\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="GccApplication1.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group  -mmcu=atmega32  
	@echo Finished building target: $@
	"E:\Atmel Studio\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "GccApplication1.elf" "GccApplication1.hex"
	"E:\Atmel Studio\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "GccApplication1.elf" "GccApplication1.eep" || exit 0
	"E:\Atmel Studio\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objdump.exe" -h -S "GccApplication1.elf" > "GccApplication1.lss"
	"E:\Atmel Studio\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "GccApplication1.elf" "GccApplication1.srec"
	"E:\Atmel Studio\extensions\Atmel\AVRGCC\3.4.1.95\AVRToolchain\bin\avr-size.exe" "GccApplication1.elf"
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS)$(C_DEPS_AS_ARGS) $(EXECUTABLES) 
	rm -rf "GccApplication1.elf" "GccApplication1.a" "GccApplication1.hex" "GccApplication1.lss" "GccApplication1.eep" "GccApplication1.map" "GccApplication1.srec"
	