# Makefile for compiling a C project with multiple source files

# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -g -Wall

# Target executable name
TARGET = justonebit

# Source files
SRCS = justonebit.c  # Add other source files

# Object files (replace .c from SRCS with .o)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule for linking the final executable
# Depends on the object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for compiling source files into object files
# Generic rule for all source files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean target for removing compiled files, cross-platform
clean:
ifeq ($(OS),Windows_NT)
	@if exist "$(TARGET).exe" del /Q "$(TARGET).exe"
	@if exist "$(OBJS)" del /Q "$(OBJS)"
else
	@if [ -f $(TARGET) ]; then rm -f $(TARGET); fi
	@if [ -f $(TARGET).exe ]; then rm -f $(TARGET).exe; fi
	@if [ -f $(OBJS) ]; then rm -f $(OBJS); fi
endif

# Phony targets
.PHONY: all clean