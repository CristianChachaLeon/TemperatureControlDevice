# Makefile
#
#
#
#
#
#
# Autor: Cristian Chacha Leon
#
#----------------------------------------------------------

# Project name
PROJECT = Demo
MCU = atmega328p
PROGRAMMER = arduino
# Directories
BUILD_DIR := ./build
BIN_DIR := $(BUILD_DIR)/bin
OBJ_DIR := $(BUILD_DIR)/obj

# Output files
HEXFILE := $(BIN_DIR)/$(PROJECT).hex
ELFFILE := $(BIN_DIR)/$(PROJECT).elf

# Source files
SRC = main.c
OBJ =$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DEP := $(OBJ:.o=.d)
# Serial port
PORT = COM3

# Compiler tools
CC := avr-gcc
OBJCOPY := avr-objcopy
AVRDUDE := avrdude

# Preprocesor Flags
CPPFLAGs = -DF_CPU=16000000 -D__AVR_ATmega328P__

# Compiler Flags
CFLAGs = -Os -Wall -Wextra -MMD

# Linker flags
LDFLAGs = -mmcu=$(MCU)

# Hex file flags
OBJCOPYFLAGS = -j .text -j .data -O ihex

# Flashig flags
DUDEFLAGS =-v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b 115200 -U 


.PHONY:all clean flash

all: $(HEXFILE)

clean:
	-rm -fr $(BUILD_DIR)

flash: $(HEXFILE)
	$(AVRDUDE) $(DUDEFLAGS) flash:w:$<:i

$(HEXFILE): $(ELFFILE)
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(ELFFILE): $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $^ $(LDFLAGs) -o $@

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGs) $(CPPFLAGs) $< -c -o $@

-include $(DEP)