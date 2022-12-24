#ifndef _ANIMAL_WRAPPER_H_
#define _ANIMAL_WRAPPER_H_

#include <stdint.h>

#define _ERROR_
#undef _ERROR_

//32位系统中指针的大小是4个字节，但在64位系统中指针的大小为8个字节。
#ifdef _ERROR_
#define DECLARE_HANDLE(name)  \
	typedef int32_t H##name;
#else
#define DECLARE_HANDLE(name)  \
	typedef int64_t H##name;	
#endif

/*使用整数作为句柄，在C++程序暴露给C语言的接口函数之间进行传递。可以减少C++封装
 *Animal类给C语言使用时的Animal结构体定义。
 */
DECLARE_HANDLE(Animal)

#ifdef __cplusplus
extern "C" {
#endif

//使用整数作为句柄，类型于Linux的文件描述符fp。
HAnimal animal_create(const char* name,int age);
HAnimal animal_copy(const HAnimal hAnimal);
void animal_destroy(HAnimal hAnimal);

void animal_setName(HAnimal hAnimal,const char* name);
const char* animal_getName(const HAnimal hAnimal);

void animal_setAge(HAnimal hAnimal,int age);
int animal_getAge(const HAnimal hAnimal);

void animal_display(const HAnimal hAnimal);

#ifdef __cplusplus
}
#endif

#endif //_ANIMAL_WRAPPER_H_