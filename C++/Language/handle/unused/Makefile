all: libperson.a person.exe

libperson.a:
	gcc -c source/person.c -o ./lib/person.o -I ./include
	ar rcs -o ./lib/libperson.a ./lib/person.o

person.exe:
	gcc -o bin/person.exe ./test/main.c ./lib/libperson.a -I include

clean:
	del bin\person.exe lib\libperson.a .\lib\person.o

.PHONY: all