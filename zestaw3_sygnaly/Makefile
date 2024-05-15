.SUFFIXES: .c .cpp .o .x .h
DIR = $(notdir $(CURDIR))
SYSNAME = $(shell uname -s)
NAME1 = zadA
NAME2 = zadB
NAME3 = zadC
EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
OBJS1 = $(NAME1).o
OBJS2 = $(NAME2).o
OBJS3 = $(NAME3).o
CFLAGS = -Wall -std=c99 -pedantic -O
LFLAGS = -Wall -std=c99 -pedantic -O
MODE_ARG ?= 2
SIG_ARG ?= 3
CO = gcc
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $< -o $@

$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC3): $(OBJS3)
	$(LD) -o $@ $(LFLAGS) $^	

.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)

run1: $(EXEC1)
	./$(EXEC1) $(MODE_ARG) $(SIG_ARG)

run2: $(EXEC2) $(EXEC1)
	./$(EXEC2) $(MODE_ARG) $(SIG_ARG)
run3: $(EXEC3)
	./$(EXEC3) $(MODE_ARG) $(SIG_ARG)

clean:
	rm *.x *.o