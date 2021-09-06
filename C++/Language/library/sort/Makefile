.PHONY:all clean run

all:libmysort.dll main.exe

libmysort.dll:mysort.c
	gcc -fPIC -shared $^ -o $@

main.exe:main.c
	gcc $< -o $@ libmysort.dll

clean:
	del /f mysort.dll main.exe

run:
	main.exe