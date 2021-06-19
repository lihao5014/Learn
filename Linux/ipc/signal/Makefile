.PHONY:all clear

CC := gcc

TARGET1 := signal.out
TARGET2 := sigaction.out

all:${TARGET1} ${TARGET2}

$(TARGET1):signal.c
	$(CC) -o $@ $<

${TARGET2}:sigaction.c
	$(CC) -o $@ $<

clear:
	rm -rf *.out test.txt