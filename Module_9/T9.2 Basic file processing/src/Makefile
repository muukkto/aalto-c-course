CXX = g++
CC = gcc
CFLAGS = -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -lm
EXECNAME = main

C_FILES = filebasics.c main.c
COBJECTS = $(C_FILES:.c=.o)

ifeq ($(OS),Windows_NT)
	RM=del /f /q
	EXECUTABLE = $(EXECNAME).exe
else
	RM=rm -f
	EXECUTABLE = $(EXECNAME)
endif

.PHONY: all

all: main run

main: $(COBJECTS)
	@echo "Linking for executable" $(EXECUTABLE)
	$(CC) $(COBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

$(COBJECTS): %.o:%.c
	@echo "Compiling" $(C_FILES)
	$(CC) $(CFLAGS) $< -o $@
clean:
	@echo "Cleaning" $(C_FILES)
	$(RM) *.o $(EXECUTABLE) $(EXECNAME).exe

run:
	@echo "Running \"$(EXECUTABLE)\""
	@./$(EXECUTABLE)

