.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
NAME2 = zad5
PIPENAME = fifa
ARG1 = dane_do_skonsumowania.txt
ARG2 = plik_docelowy_dla_danych.txt
EXEC2 = $(NAME2).x
OBJS2 = $(NAME2).o
CFLAGS = -Wall -std=c99 -pedantic -O
LFLAGS = -Wall -std=c99 -pedantic -O
CO = gcc
LD = $(CO)
%.o: %.c
	$(CO) $(CFLAGS) -c $< -o $@
$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^
.PHONY: all
all: $(EXEC1) $(EXEC2)

run5: $(EXEC2)
	./$(EXEC2) $(ARG1) $(ARG2) $(PIPENAME)
clean:
	rm *.x *.o