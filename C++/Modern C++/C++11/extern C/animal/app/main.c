#include "animalwrapper.h"
#include <stdio.h>

int main(void)
{
	HAnimal hAnimal = animal_create("cat",2);
	animal_display(hAnimal);
	
	animal_setName(hAnimal,"dog");
	const char* name = animal_getName(hAnimal);
	printf("name = %s\n",name);
	
	animal_setAge(hAnimal,3);
	int age = animal_getAge(hAnimal);
	printf("age = %d\n",age);
	
	animal_display(hAnimal);
	putchar('\n');
	
	HAnimal hAnimal2 = animal_copy(hAnimal);
	animal_display(hAnimal2);
	
	animal_setName(hAnimal2,"bird");
	animal_setAge(hAnimal2,1);
	animal_display(hAnimal2);
	
	puts("");
	animal_display(hAnimal);
	
	printf("hAnimal =%d, hAnimal2 =%d\n",hAnimal,hAnimal2);
	
	/*当hAnimal句柄指向的对象在animal_destroy()函数中被销毁时，会从g_animalVec对象池中删除。
	 *由于g_animalVec是由std::vector实现的。当std::vector中删除一个元素时，向量的长度也会发生改变。
	 *所以当调用animal_destroy()函数销毁第2个句柄hAnimal2时，hAnimal2句柄索引位置已经失效了，会导致
	 *std::vector访问越界，软件崩溃。
	 */
	animal_destroy(hAnimal);
	animal_destroy(hAnimal2);
	return 0;
}