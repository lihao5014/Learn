.PHONY:all clean run

CC := gcc

TARGET := fileinfo.out
SOURCE := $(wildcard *.c)
OBJECT := $(patsubst %.c,%.o,${SOURCE})

#Makefile中可以使用$()或${}获取变量的值
all:$(TARGET)

debug:
	echo source: $(SOURCE)
	@echo object: ${OBJECT}

$(TARGET):${OBJECT}
	$(CC) -o $@ $<

$(OBJECT):${SOURCE}
	$(CC) -c $^ -o $@

clean:
	rm -rf $(TARGET) ${OBJECT}

run:
	./$(TARGET)