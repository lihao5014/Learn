# gcc�ı������̷�Ϊ4��:
# 1.Ԥ������pre-processing����ͨ��Ԥ������.c��.cppԴ�ļ�����Ԥ�������.i��.ii�ļ���
# 2.���루compile����ͨ�����뽫.i��.ii�ļ����ɱ�����.s�������ԭʼ����
# 3.��ࣨassembling����ͨ����ཫ.s�ļ����ɻ����.o������Ŀ���ļ���
# 4.�νӣ�linking����ͨ���νӽ�.o�ļ������νӺ��.exe��ִ���ļ���

all:math.i math.s math.o main.i main.s main.o main.exe

math.i:math.c
	gcc -E math.c -o ./build/math.i

math.s:math.i
	gcc -S ./build/math.i -o ./build/math.s

math.o:math.s
	gcc -c build/math.s -o build/math.o

main.i:main.c
	gcc -E main.c -o build/main.i

main.s:main.i
	gcc -S build/main.i -o build/main.s

main.o:main.s
	gcc -c build/main.s -o build/main.o

main.exe:math.o main.o
	gcc build/math.o build/main.o -o main.exe

clean:
	del /f build/math.i build/math.s build/math.o build/main.i build/main.s build/main.o main.exe

run:
	main.exe