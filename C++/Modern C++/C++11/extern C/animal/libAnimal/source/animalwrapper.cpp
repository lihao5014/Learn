#include "animalwrapper.h"
#include <iostream>
#include <vector>
#include <map>
#include "animal.h"

#define _ERROR_
#undef _ERROR_

using namespace std;

/*使用STL vector容器对C++中的类class进行包装，在C++程序中定义容器存储一组对象，
 *C++程序对C语言暴露的接口函数仅传递包装后的对象在容器中的地址，即对象在容器中的索引。
 */
static vector<Animal> g_animalVec;     //定义一个全局的Animal对象池。

HAnimal animal_create(const char* name,int age)
{
	if(name == NULL || age < 0)
	{
		cout<<"animal_create warn: name is NULL or age is less than zero!"<<endl;
		return -1;
	}
	
	Animal animal(name,age);
	g_animalVec.push_back(animal);
	return g_animalVec.size() - 1;
}

HAnimal animal_copy(const HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalVec.size())
	{
		cout<<"animal_copy warn: hAnimal is illegal!"<<endl;
		return -1;
	}
	
	const Animal& animal = g_animalVec[hAnimal];
	Animal newAnimal(animal);
	g_animalVec.push_back(newAnimal);
	return g_animalVec.size() - 1;
}

void animal_destroy(HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalVec.size())
	{
		cout<<"animal_destroy warn: hAnimal is illegal!"<<endl;
		return;
	}
	
	g_animalVec.erase(g_animalVec.begin() + hAnimal);
}

void animal_setName(HAnimal hAnimal,const char* name)
{
	if(hAnimal < 0 || hAnimal >= g_animalVec.size() || name == NULL)
	{
		cout<<"animal_setName warn: hAnimal is illegal or name is NULL!"<<endl;
		return;
	}
	
	Animal& animal = g_animalVec[hAnimal];
	animal.setName(name);
}

const char* animal_getName(const HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalVec.size())
	{
		cout<<"animal_getName warn: hAnimal is illegal!"<<endl;
		return NULL;
	}
	
	const Animal& animal = g_animalVec[hAnimal];
	return animal.getName().c_str();
}

void animal_setAge(HAnimal hAnimal,int age)
{
	if(hAnimal < 0 || hAnimal >= g_animalVec.size() || age < 0)
	{
		cout<<"animal_setAge warn: hAnimal or age is illegal!"<<endl;
		return;
	}
	
	Animal& animal = g_animalVec[hAnimal];
	animal.setAge(age);
}

int animal_getAge(const HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalVec.size())
	{
		cout<<"animal_getAge warn: hAnimal is illegal!"<<endl;
		return -1;
	}
	
	const Animal& animal = g_animalVec[hAnimal];
	return animal.getAge();
}

void animal_display(const HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalVec.size())
	{
		cout<<"animal_display warn: hAnimal is illegal!"<<endl;
		return;
	}
	
	const Animal& animal = g_animalVec[hAnimal];
	animal.display();
}