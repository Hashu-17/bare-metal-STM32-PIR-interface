# Makefile - Bare-metal build for STM32L433RCT6

# Toolchain
CC      = arm-none-eabi-gcc
LD      = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE    = arm-none-eabi-size

# MCU and CPU flags
MCU     = cortex-m4
CFLAGS  = -Wall -Wextra -mcpu=$(MCU) -mthumb -O0 -g -nostdlib -nostartfiles
LDFLAGS = -T linker.ld

# Source and object files
SRCS = main.c gpio.c uart.c delay.c startup.s
OBJS = $(SRCS:.c=.o)
OBJS := $(OBJS:.s=.o)

# Output file
TARGET = firmware

all: $(TARGET).elf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	$(OBJCOPY) -O ihex $@ $(TARGET).hex
	$(OBJCOPY) -O binary $@ $(TARGET).bin
	$(OBJDUMP) -D $@ > $(TARGET).lst
	$(SIZE) $@

clean:
	rm -f *.o *.elf *.hex *.bin *.lst

flash: $(TARGET).bin
	st-flash write $(TARGET).bin 0x08000000

.PHONY: all clean flash
