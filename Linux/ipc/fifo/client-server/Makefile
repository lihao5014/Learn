.PHONY:build copy create clean

build:fifo_read.out fifo_write.out

fifo_read.out:fifo_read.c
	gcc -o $@ $<

fifo_write.out:fifo_write.c
	gcc -o $@ $<

copy:
	cp ~/Share/Learn/Linux/ipc/fifo/client-server/* ~/Study/Linux/fifo/client-server

create:
	mkfifo -m 666 testfifo

clean:
	rm -rf *.out testfifo count_fifo.p