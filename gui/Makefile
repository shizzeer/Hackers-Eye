CC = gcc
CFLAGS = `pkg-config --libs --cflags gtk+-2.0`

SRCS = $(wildcard *.c)
PROGRAMS = $(patsubst %.c,%.o,$(SRCS))

all: $(PROGRAMS) 

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
