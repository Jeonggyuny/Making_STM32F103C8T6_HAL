MCPU = cortex-m3

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OC = arm-none-eabi-objcopy
SZ = arm-none-eabi-size

LINKER_SCRIPT = mySTM32F103C8T6.ld

TARGET = build/main.axf
TARGET_BIN = build/main.bin

ASM_SRCS = $(wildcard boot/*.s)
ASM_OBJS = $(patsubst boot/%.s, build/%.os, $(ASM_SRCS))

VPATH = boot			\
	hal/STM32F103C8T6	\
	lib

C_SRCS  = $(notdir $(wildcard boot/*.c))
C_SRCS += $(notdir $(wildcard hal/STM32F103C8T6/*.c))
C_SRCS += $(notdir $(wildcard lib/*.c))
C_OBJS  = $(patsubst %.c, build/%.o, $(C_SRCS))

INC_DIRS = -I include		\
	   -I hal		\
	   -I hal/STM32F103C8T6	\
	   -I lib

CFLAGS = -mthumb -c -g -std=c11

.PHONY: all clean flash debug gdb

all: $(TARGET_BIN)

$(TARGET_BIN): $(TARGET)
	$(OC) -O binary $< $@

$(TARGET): $(ASM_OBJS) $(C_OBJS)
	$(LD) -T $(LINKER_SCRIPT) -o $@ $^
	$(SZ) $@

build/%.os: %.s
	mkdir -p $(shell dirname $@)
	$(CC) -mcpu=$(MCPU) $(INC_DIRS) $(CFLAGS) -o $@ $<

build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -mcpu=$(MCPU) $(INC_DIRS) $(CFLAGS) -o $@ $<

clean:
	@rm -rf build

flash:
	sudo st-flash --reset write $(TARGET_BIN) 0x08000000

debug:
	sudo st-util

gdb:
	gdb-multiarch
