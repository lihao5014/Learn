.PHONY:all client server run_client run_server clean

CC := gcc
LD := gcc
AR := ar
RM := rm -f

VPATH := client server

all:client server

client:client/tcpclient.c
	$(CC) -o client/tcpclient.out $<

server:server/threadserver.c
	$(CC) -o server/threadserver.out $^ -lpthread

run_server:
	server/threadserver.out

run_client:
	client/tcpclient.out

clean:
	${RM} server/threadserver.out client/tcpclient.out
	