#include <stdio.h>
#include <string.h>
#include "sample.h"
#include "demo.h"
#include "test.h"

#define SafeDelete(ptr)          \
	do{                          \
		if(ptr != nullptr)       \
		{                        \
			delete ptr;          \
			ptr = nullptr;       \
		}                        \
	}while(0)

struct SampleMemHelper    //配合memcpy函数手动设置Sample类中，成员变量值的辅助类
{
	void *ptable;
	char *name;
};

struct DemoMemHelper     //配合memcpy函数手动设置Demo类中，成员变量值的辅助类
{
	void *ptable;
	int data;
	Sample* psample;
};

static void Sample_test();
static void Demo_test();
static void Test_test();

int main(int argc,char** argv)
{
#if _CHANGE_WAY_A
	printf("---change way a---\n");
#elif _CHANGE_WAY_B
	puts("---change way b---");
#elif _CHANGE_WAY_C
	fprintf(stdout,"---change way c---\n");
#else
	fputs("---change way d---\n",stdout);
#endif

	// Sample_test();
	// Demo_test();
	Test_test();
	
	return 0;
}

void Sample_test()
{
	Sample sample1("create sample1");
	sample1.show();
	printf("pointer size: %d\n",sizeof(char*));          //64位操作系统指针大小为8个字节，32位操作系统指针大小为32个字节
	printf("Sample type size: %d\n",sizeof(Sample));     //Sample类中只要有虚函数存在，就有一个虚函数表指针ptable需要占用一个指针大小的内存空间

#ifdef _DEEPLY_COPY_
	sample1.setName("rename sample1");     //C++中const char*指针不能为char*指针赋值，但char*指针反过来可以为const char*指针赋值
	const char* name = sample1.getName();
	printf("getName() name =%s\n",name);
	sample1.show();
#endif

	char *pstr = new char[strlen("hello world") + 1];
	strcpy(pstr,"hello world");
	sample1.setName(pstr);      //Sample类的setName方法使用的是深赋值实现的，所以传入的实参指针需要由用户手动释放内存
	printf("getName() name =%s\n",sample1.getName());
	sample1.show();

#ifdef _DEEPLY_COPY_
	if(pstr != nullptr)    //如果使用浅拷贝实现的setName方法，则Sample类会在析构函数中释放setName传入的实参指针内存。
	{                      //当用户将传入setName方法的实参指针手动释放掉以后，会造成Sample类析构时Sample::name野指针delete问题。
		delete[] pstr;
		pstr = nullptr;
	}
#endif
	
	Sample *psample = new Sample(nullptr);
	memcpy(psample,&sample1,sizeof(Sample));     //直接使用memcpy内存拷贝时，Sample类中的成员指针相当于浅赋值
	psample->show();
	
	pstr = new char[strlen("shallow copy constructor test") + 1];
	strcpy(pstr,"shallow copy constructor test");
	
	psample->setName(pstr);        //由于sample1和psample指向的对象中，name指针指向的内存是共用的，
	Sample tempSample(nullptr);    //所以当调用psample->setName将name成员指针释放掉以后，sample1中的name成员指针就变为了野指针。
	memcpy(&sample1,&tempSample,sizeof(tempSample));   //通过拷贝一个name成员指针为nullptr的Sample临时对象内存，以将sample1对象中的name野指针变为空指针
	printf("getName() name =%s\n",psample->getName());
	sample1.show();
	if(pstr != nullptr)
	{
		delete[] pstr;
		pstr = nullptr;
	}
	
	SampleMemHelper helper = {nullptr,nullptr};
	memcpy(&helper,&sample1,sizeof(Sample));      //主要为了设置SampleMemHelper::ptable指针,因为怕如果Sample类中的虚函数表指针混乱了，sample1对象析构时软件崩溃
	helper.name = new char[strlen("SampleMemHelper") + 1];
	strcpy(helper.name,"SampleMemHelper");
	memcpy(&sample1,&helper,sizeof(SampleMemHelper));     //主要为了设置Sample类中的name指针
	sample1.show();
	
	// getchar();     //延迟析构的时候软件的崩溃
}

static void Demo_test()
{
	Demo demo1(10);
	demo1.display();
	
	Sample* psample = new Sample("test Demo::psample");
	demo1.registerSample(psample);
	demo1.setData(11);
	demo1.display();

#if defined(_DEEPLY_COPY_) && !(_CHANGE_WAY_B)
	SafeDelete(psample);
#endif

#if defined(_DEEPLY_COPY_) && _CHANGE_WAY_B
	SampleMemHelper sampleHelper = {nullptr,nullptr};
	memcpy(&sampleHelper,psample,sizeof(Sample));      //主要为了设置SampleMemHelper::ptable指针,因为怕如果Sample类中的虚函数表指针混乱了，sample1对象析构时软件崩溃
	sampleHelper.name = new char[strlen("SampleMemHelper") + 1];
	strcpy(sampleHelper.name,"SampleMemHelper");
	memcpy(psample,&sampleHelper,sizeof(SampleMemHelper));     //主要为了设置Sample类中的name指针
	
	psample->show();
	SafeDelete(psample);
#endif

	Demo demo2(demo1);    //如果Demo类的拷贝构造函数是浅拷贝实现时，则拷贝构造完成以后demo1和demo2对象中的psample指针指向同一片内存区域
	demo2.setData(12);
	demo2.display();
	
	char* pname = new char[strlen("sample::name") + 1];
	strncpy(pname,"sample::name",strlen("sample::name") + 1);
	demo2.sample()->setName(pname);
	demo2.display();

#ifdef _DEEPLY_COPY_
	SafeDelete(pname);
#endif
	
#ifndef _DEEPLY_COPY_
	demo1.registerSample(nullptr);    //防止demo1和demo2对象中的psample指针指向的同一片内存区域，在Demo类析构时两次释放其内存
#endif

	demo1.setData(13);
	demo1.display();
	
#if defined(_DEEPLY_COPY_) && _CHANGE_WAY_B
	DemoMemHelper demoHelper = {nullptr,0,nullptr};
	memcpy(&demoHelper,&demo1,sizeof(Demo));
	demoHelper.psample = new Sample("DemoMemHelper");
	demoHelper.data = 14;
	memcpy(&demo1,&demoHelper,sizeof(DemoMemHelper));
#endif
	demo1.display();

	// getc(stdin);     //延迟析构的时候软件的崩溃
}

static void Test_test()
{
	Test test1(20.05);
	test1.print();
	
	Sample* psample = new Sample("test Test::addSample");
	test1.addSample(psample);
	test1.setValue(21.05);
	test1.print();

	Sample sample(*psample);
	sample.show();
	test1.sample(0)->show();
	
#ifdef _DEEPLY_COPY_
	SafeDelete(psample);
	test1.removeSample(&sample);
#else
	test1.removeSample(psample);
#endif
	test1.print();
	
	// getchar();
}

