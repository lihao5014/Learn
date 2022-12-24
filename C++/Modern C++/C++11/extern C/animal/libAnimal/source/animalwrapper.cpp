#include "animalwrapper.h"
#include <iostream>
#include <vector>
#include <map>
#include "animal.h"

using namespace std;

/*使用STL vector容器对C++中的类class进行包装，在C++程序中定义容器存储一组对象，
 *C++程序对C语言暴露的接口函数仅传递包装后的对象在容器中的地址，即对象在容器中的索引。
 */
#ifdef _ERROR_
static vector<Animal> g_animalPool;         //定义一个全局的Animal对象池。
#else
static map<HAnimal,Animal> g_animalPool;
#endif

#ifdef _ERROR_
HAnimal animal_create(const char* name,int age)
{
	if(name == NULL || age < 0)
	{
		cout<<"animal_create warn: name is NULL or age is less than zero!"<<endl;
		return -1;
	}
	
	Animal animal(name,age);
	g_animalPool.push_back(animal);
	return g_animalPool.size() - 1;
}
#else
HAnimal animal_create(const char* name,int age)
{
	if(name == NULL || age < 0)
	{
		cout<<"animal_create warn: name is NULL or age is less than zero!"<<endl;
		return -1;
	}
	
	Animal animal(name,age);
	HAnimal hAnimal = (HAnimal)&animal;
	g_animalPool.insert(std::pair<HAnimal,Animal>(hAnimal,animal));    //使用变量的地址充当uuid。
	return hAnimal;
}
#endif

#ifdef _ERROR_
HAnimal animal_copy(const HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalPool.size())
	{
		cout<<"animal_copy warn: hAnimal is illegal!"<<endl;
		return -1;
	}
	
	const Animal& animal = g_animalPool[hAnimal];
	Animal newAnimal(animal);
	g_animalPool.push_back(newAnimal);
	return g_animalPool.size() - 1;
}
#else
HAnimal animal_copy(const HAnimal hAnimal)
{
	if(g_animalPool.count(hAnimal) < 1)
	{
		cout<<"animal_copy warn: hAnimal is illegal!"<<endl;
		return -1;
	}
	
	const Animal& animal = g_animalPool[hAnimal];
	Animal newAnimal(animal);
	HAnimal hNewAnimal = (HAnimal)&newAnimal;
	g_animalPool[hNewAnimal] = newAnimal;
	return hNewAnimal;
}
#endif

#ifdef _ERROR_
void animal_destroy(HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalPool.size())
	{
		cout<<"animal_destroy warn: hAnimal is illegal!"<<endl;
		return;
	}
	
	g_animalPool.erase(g_animalPool.begin() + hAnimal);
}
#else
void animal_destroy(HAnimal hAnimal)
{
	map<HAnimal,Animal>::iterator iter = g_animalPool.find(hAnimal);
	if(iter == g_animalPool.end())
	{
		cout<<"animal_destroy warn: hAnimal is illegal!"<<endl;
		return;
	}
	
	g_animalPool.erase(iter);
}	
#endif

#ifdef _ERROR_
void animal_setName(HAnimal hAnimal,const char* name)
{
	if(hAnimal < 0 || hAnimal >= g_animalPool.size() || name == NULL)
	{
		cout<<"animal_setName warn: hAnimal is illegal or name is NULL!"<<endl;
		return;
	}
	
	Animal& animal = g_animalPool[hAnimal];
	animal.setName(name);
}
#else
void animal_setName(HAnimal hAnimal,const char* name)
{
	if(g_animalPool.count(hAnimal) < 1 || name == NULL)
	{
		cout<<"animal_setName warn: hAnimal is illegal or name is NULL!"<<endl;
		return;
	}
	
	Animal& animal = g_animalPool[hAnimal];
	animal.setName(name);
}
#endif

#ifdef _ERROR_
const char* animal_getName(const HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalPool.size())
	{
		cout<<"animal_getName warn: hAnimal is illegal!"<<endl;
		return NULL;
	}
	
	const Animal& animal = g_animalPool[hAnimal];
	return animal.getName().c_str();
}
#else
const char* animal_getName(const HAnimal hAnimal)
{
	if(g_animalPool.count(hAnimal) < 1)
	{
		cout<<"animal_getName warn: hAnimal is illegal!"<<endl;
		return NULL;
	}
	
	const Animal& animal = g_animalPool[hAnimal];
	return animal.getName().c_str();
}
#endif

#ifdef _ERROR_
void animal_setAge(HAnimal hAnimal,int age)
{
	if(hAnimal < 0 || hAnimal >= g_animalPool.size() || age < 0)
	{
		cout<<"animal_setAge warn: hAnimal or age is illegal!"<<endl;
		return;
	}
	
	Animal& animal = g_animalPool[hAnimal];
	animal.setAge(age);
}
#else
void animal_setAge(HAnimal hAnimal,int age)
{
	if(g_animalPool.count(hAnimal) < 1 || age < 0)
	{
		cout<<"animal_setAge warn: hAnimal or age is illegal!"<<endl;
		return;
	}
	
	Animal& animal = g_animalPool[hAnimal];
	animal.setAge(age);
}
#endif

#ifdef _ERROR_
int animal_getAge(const HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalPool.size())
	{
		cout<<"animal_getAge warn: hAnimal is illegal!"<<endl;
		return -1;
	}
	
	const Animal& animal = g_animalPool[hAnimal];
	return animal.getAge();
}
#else
int animal_getAge(const HAnimal hAnimal)
{
	if(g_animalPool.count(hAnimal) < 1)
	{
		cout<<"animal_getAge warn: hAnimal is illegal!"<<endl;
		return -1;
	}
	
	const Animal& animal = g_animalPool[hAnimal];
	return animal.getAge();
}
#endif

#ifdef _ERROR_
void animal_display(const HAnimal hAnimal)
{
	if(hAnimal < 0 || hAnimal >= g_animalPool.size())
	{
		cout<<"animal_display warn: hAnimal is illegal!"<<endl;
		return;
	}
	
	const Animal& animal = g_animalPool[hAnimal];
	animal.display();
}
#else
void animal_display(const HAnimal hAnimal)
{
	if(g_animalPool.count(hAnimal) < 1)
	{
		cout<<"animal_display warn: hAnimal is illegal!"<<endl;
		return;
	}
	
	const Animal& animal = g_animalPool[hAnimal];
	animal.display();
}
#endif