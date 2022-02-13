#******************************************************************************
# Copyright (C) 2017 by Joel Wass 
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Make file for assessment 2
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      main.i, main.asm, main.o, compile-all, build, clean      
#
# Platform Overrides:
#      overrides for platform, linker_file, CFLAGS, CPPFLAGS, CC, LD, and LDFLAGS
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
BASENAME = c1m2
TARGET = $(BASENAME).out

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds

ifeq ($(PLATFORM),MSP432)
SRCS = $(SOURCES_MSP432)
OBJS = $(SRCS:.c=.o)
CC = arm-none-eabi-gcc
PRINT_SIZE = arm-none-eabi-size $(TARGET)
LD = arm-none-eabi-ld
LDFLAGS = -Wl -T $(LINKER_FILE)
CFLAGS = -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs -Wall -Werror -g -O0 -std=c99
CPPFLAGS = $(INCLUDES) -D$(PLATFORM)
else
SRCS = $(SOURCES_HOST)
OBJS = $(SRCS:.c=.o)
CC = gcc
PRINT_SIZE = size $(TARGET)
LD = ld
LDFLAGS = -Wl
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = $(INCLUDES) -D$(PLATFORM)
endif

#Pre-processing Stage
%.i : %.c
	$(CC) -E $(CFLAGS) $(CPPFLAGS) $< -o $*.i
	$(CC) -MM $(CFLAGS) $(CPPFLAGS) $< -o $*.d
#Compiler-proper Stage
%.asm : %.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $< -o $*.asm
	$(CC) -MM $(CFLAGS) $(CPPFLAGS) $< -o $*.d
#Assembler Stage
%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $*.o
	$(CC) -MM $(CFLAGS) $(CPPFLAGS) $< -o $*.d
#Linker and Locator Stage
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@ && $(PRINT_SIZE)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET)

.PHONY: compile-all
compile-all: $(SRCS:.c=.o)

.PHONY: clean
clean:
	rm -f $(SRCS:.c=.o) $(SRCS:.c=.d) $(SRCS:.c=.i) $(SRCS:.c=.asm) $(TARGET).out $(TARGET).map
