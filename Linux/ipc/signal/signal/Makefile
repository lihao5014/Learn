.PHONY:all clear run

CC := gcc

SOURCE := $(wildcard *.c)
TARGET := $(patsubst %.c,%.out,$(SOURCE))

all:${TARGET}

$(TARGET):${SOURCE}
	$(CC) -o $@ $<

clear:
	rm -rf *.out test.txt

run:
	./$(TARGET)