#ifndef _ARRARY_H_
#define _ARRARY_H_

#include <iostream>
#include <string.h>
#include <exception>

using namespace std;

template<typename T>
class Array
{
public:	
	Array(const int size);
	Array(const T data,const int size);
	Array(const Array<T> &array);
	virtual ~Array();
	
	void fill(const T data);
	void clear();
	
	int getSize()const;
	bool reSize(const int size);
	
	T& at(const int index);
	T& operator [](const int index);
	
	int find(const T& data)const;
	bool remove(const int pos);
	bool remove(const T& data);
	
	bool change(const int index,const T& data);
	bool change(const T& src,const T& dst);
	
	void display()const;
	
	template<class Ty>
	friend istream& operator >>(istream& is,const Array<Ty> array);
	
	friend ostream& operator <<(ostream& os,const Array<T> array)
	{
		for(int i=0;i<array.size;++i){
			os<<array.pdata[i]<<" ";
		}
		return os;
	}
private:
	int size;
	T* pdata;
};

template<typename T>
Array<T>::Array(const int size)
{
	if(size <= 0){
		throw length_error("Array: size is illegle!");
	}
	
	pdata = new T[size];
	if(pdata == NULL){
		throw bad_alloc();
	}
	this->size = size;
	memset(pdata,0,sizeof(T)*size);
}

template<typename T>
Array<T>::Array(const T data,const int size)
{
	if(size <= 0){
		throw length_error("Array: size is illegle!");
	}
	
	pdata = new T[size];
	if(pdata == NULL){
		throw bad_alloc();
	}	
	this->size = size;
	
	for(int i=0;i<size;++i){
		pdata[i] = data;
	}
}

template<typename T>
Array<T>::Array(const Array<T> &array)
{
	pdata = new T[array.size];
	if(pdata == NULL){
		throw bad_alloc();
	}
	size = array.size;
	memcpy(pdata,array.pdata,sizeof(T)*size);
}

template<typename T>
Array<T>::~Array()
{
	if(pdata != NULL){
		delete [] pdata;
		pdata = NULL;
	}
}

template<typename T>
void Array<T>::fill(const T data)
{
	for(int i=0;i<size;++i){
		pdata[i] = data;
	}
}

template<typename T>
inline void Array<T>::clear()
{
	memset(pdata,0,sizeof(T)*size);
}

template<typename T>
inline int Array<T>::getSize()const
{	
	return size;
}

template<typename T>
bool Array<T>::reSize(const int size)
{
	if(size <= 0){
		cout<<"reSize: size is illegle"<<endl;
		return false;
	}
	
	if(size == this->size){
		return true;
	}
	
	T* newData = NULL;
	try{
		newData = new T[size];
	}catch(std::bad_alloc& e){
		throw e;
	}
	memset(newData,0,sizeof(T)*size);
	
	if(size >= this->size){
		memcpy(newData,pdata,sizeof(T)*this->size);
	}else{
		memcpy(newData,pdata,sizeof(T)*size);
	}
	this->size = size;
	delete [] pdata;
	pdata = newData;
	
	return true;
}

template<typename T>
inline T& Array<T>::at(const int index)
{
	if(index <=0 || index >= size){
		throw length_error("at: index is illegle!");
	}
	
	return pdata[index];
}

template<typename T>
inline T& Array<T>::operator [](const int index)
{
	if(index <=0 || index >= size){
		throw length_error("[]: index is illegle!");
	}
	
	return pdata[index];
}

template<typename T>
int Array<T>::find(const T& data)const
{
	for(int i=0;i<size;++i){
		if(pdata[i] == data){
			return i;
		}
	}
	
	return -1;
}

template<typename T>
bool Array<T>::remove(const int pos)
{
	if(pos <=0 || pos >= size){
		cout<<"remove: pos is illegle"<<endl;
		return false;
	}
	
	pdata[pos] = 0;
	return true;
}

template<typename T>
bool Array<T>::remove(const T& data)
{
	bool flag = false;
	
	for(int i=0;i<size;++i){
		if(pdata[i] == data){
			pdata[i] = 0;
			flag = true;
		}
	}
	return flag;
}

template<typename T>
bool Array<T>::change(const int index,const T& data)
{
	if(index <=0 || index >= size){
		cout<<"change: index is illegle"<<endl;
		return false;
	}
	
	pdata[index] = data;
	return true;
}

template<typename T>
bool Array<T>::change(const T& src,const T& dst)
{
	bool flag = false;
	
	for(int i=0;i<size;++i){
		if(pdata[i] == src){
			pdata[i] = dst;
			flag = true;
		}
	}
	return flag;
}

template<typename T>
void Array<T>::display()const
{
	for(int i=0;i<size;++i){
		cout<<pdata[i]<<" ";
	}
	cout<<endl;
}

template<class Ty>
istream& operator >>(istream& is,const Array<Ty> array)
{
	for(int i=0;i<array.size;++i){
		is>>array.pdata[i];
	}
	return is;
}

#endif //_ARRARY_H_