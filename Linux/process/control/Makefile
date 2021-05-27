.PHONY:build clean run execute debug 

CC := gcc

SRC := $(wildcard *.c)
OBJ := ${patsubst %.c,%.o,${SRC}}
TARGET := $(patsubst %.o,%.out,$(OBJ))

build:${TARGET}

${TARGET}:$(OBJ)
	$(CC) -o $@ $^

$(OBJ):$(SRC)
	$(CC) -o $@ -c $< #-D_CHANGE_WAY_

clean:
	rm -rf $(OBJ) ${TARGET}

run:
	./${TARGET}

execute:
	./$(TARGET) &
	@sleep 1s
	ps -ef | grep ${TARGET}
	@sleep 3s
	ps -ef | grep ${TARGET}
	@sleep 3s
	ps -ef | grep ${TARGET}

debug:
	@echo source: $(SRC)
	@echo object: $(OBJ)
	@echo target: $(TARGET)