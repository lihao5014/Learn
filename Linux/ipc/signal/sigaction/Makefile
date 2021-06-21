.PHONY:all clean run

CC := gcc

SOURCE := $(wildcard *.c)
TARGET := $(patsubst %.c,%.out,$(SOURCE))

all:${TARGET}

$(TARGET):${SOURCE}
	$(CC) -o $@ $<

clean:
	rm -rf *.out

run:
	./$(TARGET)