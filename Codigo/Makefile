#Main application file name

MAIN_APP = main

#Main hex file path in windows format 
MAIN_HEX_PATH =$(MAIN_APP).hex

# Compiler and other Section CC = avr-gcc

OBJCOPY = avr-objcopy

AVRDUDE := avrdude 

#Options for avr-gcc 
CFLAGS = -g -Os -o

#Linking options for avr-gcc 

LFLAGS = -Os -mmcu=atmega328p -o

#Options for HEX file generation 
HFLAGS = -j .text -j .data -O ihex

#Options for avrdude to burn the hex file

#MMCU model here according to avrdude options
PORT =/dev/ttyACM0

DUDEFLAGS = -v

DUDEFLAGS += -p atmega328p

DUDEFLAGS += -c arduino

DUDEFLAGS += -P $(PORT)

DUDEFLAGS += -b 115200

DUDEFLAGS += -U

CC=avr-gcc

# Sources files needed for building the application

SRC = $(MAIN_APP).c

SRC +=

# The headers files needed for building the application

INCLUDE = -I.

#INCLUDE +=

# commands Section Burn :
CPPFLAGs = -DF_CPU=16000000
#Build:$(AVRDUDE) $(DUDEFLAGS)
.PHONY:flash
flash:
	$(AVRDUDE) $(DUDEFLAGS) flash:w:$(MAIN_HEX_PATH):i


.PHONY:build
build : $(MAIN_APP).elf
	$(OBJCOPY) $(HFLAGS) $< $(MAIN_APP).hex


$(MAIN_APP).elf: $(MAIN_APP).o

	$(CC) $(SRC) $(INCLUDE) $(LFLAGS) $@

$(MAIN_APP).o:$(SRC)

	$(CC) $^ $(INCLUDE) $(CFLAGS) $@

.PHONY:clean
clean:
	-rm $(MAIN_HEX_PATH) 
	-rm $(MAIN_APP).elf
	-rm $(MAIN_APP).o