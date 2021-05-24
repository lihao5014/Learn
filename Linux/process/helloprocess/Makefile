.PHONY:all clean run execute print

CC := gcc

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c,%.o,$(SRC))
TARGET := $(patsubst %.o,%.out,$(OBJ))

all:$(TARGET)

debug:
	@echo source: $(SRC)
	@echo object: ${OBJ}
	@echo target: ${TARGET}

${TARGET}:$(OBJ)
	${CC} -o $@ $^

%.o:%.c
	$(CC) -c $^ -o $@

clean:
	rm -rf ${OBJ} $(TARGET)

run:
	./$(TARGET)


execute:
	./${TARGET} &    #在终端后台运行helloprocess.out

print:
	ps -ef | grep ${TARGET}