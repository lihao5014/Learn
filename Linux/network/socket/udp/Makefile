.PHONY:all client server run_client run_server clean

CC := gcc
LD := gcc
AR := ar
RM := rm -f

VPATH := client server

all:client server

client:client/udpclient.c
	$(CC) -o client/udpclient.out $<

server:server/udpserver.c
	$(CC) -o server/udpserver.out $^

run_server:
	server/udpserver.out

run_client:
	client/udpclient.out

clean:
	${RM} server/udpserver.out client/udpclient.out
	