#Makefile�е�αĿ�겢���ᴴ��Ŀ���ļ���ֻ����ȥִ�����Ŀ����������
#αĿ��Ĵ��ڿ��԰��������ҵ����ִ�С�

#ʹ��αĿ���ԭ��
#	1.�������ǵ�Makefile�ж����ִֻ�������Ŀ��͹���Ŀ¼��ʵ�ʳ������ֳ�ͻ��
#	2.���ִ��makeʱ��Ч�ʣ��ر��Ƕ���һ����Ĺ�����˵����߱���Ч��Ҳ������������ġ�

CC := gcc
CINCLUDE := -I include

vpath main.o build
vpath vector.o build
vpath libvector.a lib
VPATH := include source

main.exe:main.o libvector.a
	$(CC) -o bin/$@ $^ $(CINCLUDE)

main.o:main.c
	$(CC) -c $< -o build/$@ $(CINCLUDE)

libvector.a:vector.o
	ar rcs -o lib/$@ build/$<

vector.o:vector.c
	$(CC) -c $< -o build/$@ $(CINCLUDE)

#�����е�del����Ǵ���cleanĿ���ļ����������ִ��ɾ�����񡣵�����Ŀ¼�²�����clean������ļ�ʱ��
#��shell������make clean�������del /f build\*.o lib\*.a bin\*.exe���ǻᱻִ�У���Ҳ�����������Ľ����
clean:
	del /f build\*.o lib\*.a bin\*.exe

#����������������ȥ�����ļ�������ͨ��make������ȷָ������ִ��һ���ض������
run:
	bin/main.exe

.PHONY:clean run


	