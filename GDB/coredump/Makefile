.PHONY:release debug clean run gdb

CC := gcc
GDB := gdb

SOURCE := $(wildcard *.c)
TARGET := $(patsubst %.c,%.out,${SOURCE})

release:$(TARGET)

$(TARGET):${SOURCE}
	$(CC) -o $@ $<

debug:FORCE
	$(CC) -g -o $(TARGET) ${SOURCE}

FORCE:       #FORCE是一个强制目标
	
clean:
	rm -rf *.out core gdb.txt

run:
	./$(TARGET)

gdb:
	$(GDB) -g ./$(TARGET)