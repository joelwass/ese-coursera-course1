#******************************************************************************
# Copyright (C) 
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
#
#*****************************************************************************

# Add your Source files to this variable
PLATFORM = HOST
SOURCES =
INCLUDES =

ifeq ($(PLATFORM),HOST)
SOURCES_HOST = ./src/memory.c ./src/main.c ./src/course1.c ./src/data.c ./src/stats.c
INCLUDES = -I./include/CMSIS \
			 		 -I./include/common
else
INCLUDES = -I./include/msp432 \
			     -I./include/common
SOURCES_MSP432 = main.c \
								 memory.c \
								 interrupts_msp432p401r_gcc.c \
								 startup_msp432p401r_gcc.c \
								 system_msp432p401r.c \
								 ./src/course1.c
endif

