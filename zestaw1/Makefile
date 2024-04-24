CFLAGS=-Wall

SOURCES=$(wildcard *.c)

EXECUTABLES=$(SOURCES:.c=.x)

all: $(EXECUTABLES)

%.x: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)