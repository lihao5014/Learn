.PHONY:all clean run

all:helloworld.exe

helloworld.exe:helloworld.c
	gcc -o $@ $<

clean:
	del /f *.exe

run:
	helloworld.exe
