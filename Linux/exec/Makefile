.PHONY:all clean run

CC := gcc

all:exec.out welcome.out

exec.out:exec.c
	$(CC) -o $@ $^

welcome.out:welcome.c
	$(CC) -o $@ $<

clean:
	rm -rf *.out

run:
	./exec.out &
	ps -ef | grep -E "welcome.out|exec.out"
	@sleep 2s
	ps -ef | grep -E "welcome.out|exec.out"
	@sleep 2s
	ps -ef | grep -E "welcome.out|exec.out"