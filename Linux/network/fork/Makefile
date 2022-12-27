.PHONY:all client server run_client run_server clean

CC := gcc
LD := gcc
AR := ar
RM := rm -f

VPATH := client server

all:client server

client:client/tcpclient.c
	$(CC) -o client/tcpclient.out $<

server:server/processserver.c
	$(CC) -o server/processserver.out $^

run_server:
	server/processserver.out

run_client:
	client/tcpclient.out

clean:
	${RM} server/processserver.out client/tcpclient.out
	