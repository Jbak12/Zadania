.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
NAME1 = zad4
ARG1 = dane_do_skonsumowania.txt
ARG2 = plik_docelowy_dla_danych.txt
EXEC1 = $(NAME1).x
OBJS1 = $(NAME1).o
CFLAGS = -Wall -std=c99 -pedantic -O
LFLAGS = -Wall -std=c99 -pedantic -O
CO = gcc
LD = $(CO)
%.o: %.c
	$(CO) $(CFLAGS) -c $< -o $@
$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
.PHONY: all
all: $(EXEC1)

run: $(EXEC1)
	./$(EXEC1) $(ARG1) $(ARG2)
clean:
	rm *.x *.o