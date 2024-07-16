# Define compiler and linker
CC = riscv32-unknown-elf-g++
OBJCOPY = riscv32-unknown-elf-objcopy

# Compiler flags
CFLAGS = -march=rv32i -mabi=ilp32 -O0 -g -Wall

# Linker script
LINKER_SCRIPT = bram.ld

# Source files
SRCS = gpio_cores.cpp init.cpp testing_code.cpp timer_core.cpp uart_core.cpp
HEADERS = gpio_cores.h init.h io_map.h io_rw.h timer_core.h uart_core.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output files
OUTPUT = output

# Target: all (default target)
all: $(OUTPUT).hex

# Generate object files
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files using linker with correct libraries
$(OUTPUT).elf: $(OBJS) $(LINKER_SCRIPT)
	$(CC) -T $(LINKER_SCRIPT) -o $@ $(OBJS) -march=rv32i -mabi=ilp32 -lgcc -lc -lstdc++ -lm

# Generate HEX file from ELF
$(OUTPUT).hex: $(OUTPUT).elf
	$(OBJCOPY) -O ihex $(OUTPUT).elf $(OUTPUT).hex

# Clean rule
clean:
	rm -f $(OBJS) $(OUTPUT).elf $(OUTPUT).hex

# Phony targets
.PHONY: all clean

