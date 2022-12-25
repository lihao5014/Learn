.PHONY:all client server run_client run_server clean

CC := gcc
LD := gcc
AR := ar
RM := rm -f

VPATH := client server

all:client server

client:client/tcpclient.c
	$(CC) -o client/tcpclient.out $<

server:server/tcpserver.c
	$(CC) -o server/tcpserver.out $^

run_server:
	server/tcpserver.out

run_client:
	client/tcpclient.out

clean:
	${RM} server/tcpserver.out client/tcpclient.out
	