.PHONY:all clean run

CC := gcc

SOURCE := $(wildcard *.c)
TARGET := $(patsubst %.c,%.out,$(SOURCE))

all:${TARGET}

${TARGET}:$(SOURCE)
	$(CC) -o $@ $^

clean:
	rm -rf $(TARGET)

run:
	./$(TARGET) &
	@sleep 1s
	ps -ef | grep $(TARGET)
	@sleep 2s
	ps -ef | grep defunct   #查看僵尸进程
	@sleep 2s
	ps -ef | grep $(TARGET)
	@sleep 2s
	ps -ef | grep $(TARGET)