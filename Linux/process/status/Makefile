.PHONY:build clean run execute

CC := gcc

SRC := $(wildcard *.c)
TARGET := $(patsubst %.c,%.out,$(SRC))

build:${TARGET}

${TARGET}:$(SRC)
	$(CC) -o $@ $^

clean:
	rm -rf ${TARGET}

run:
	./$(TARGET)

execute:
	./$(TARGET) &
	@sleep 1s
	ps -ef | grep $(TARGET)
	@sleep 1s
	ps -ef | grep $(TARGET)