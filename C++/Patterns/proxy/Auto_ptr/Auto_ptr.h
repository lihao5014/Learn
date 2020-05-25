#ifndef _AUTO_PTR_H
#define _AUTO_PTR_H

template <typename T>
class Auto_ptr
{
public:
	explicit Auto_ptr(T *ptr = 0);
	Auto_ptr(const Auto_ptr<T>& pAuto);
	
	template <typename Y>
	Auto_ptr(const Auto_ptr<Y>& pAuto);
	~Auto_ptr();
	
	Auto_ptr<T>& operator =(const Auto_ptr<T>& pAuto);
	
	template <typename Y>
	Auto_ptr<T>& operator =(const Auto_ptr<Y>& pAuto);
	
	T& operator *()const;
	T* operator ->()const;
	T* get()const;
	void reset(T* ptr = 0);
	T* release()const;
private:
	T* ptr;
	mutable bool owns;
};

template <typename T>
Auto_ptr<T>::Auto_ptr(T *ptr):ptr(ptr),owns((bool)ptr)
{
	
}

template <typename T>
Auto_ptr<T>::Auto_ptr(const Auto_ptr<T>& pAuto):ptr(pAuto.ptr),owns(pAuto.owns)
{
	pAuto.owns = false;
}

template <typename T>
template <typename Y>
Auto_ptr<T>::Auto_ptr(const Auto_ptr<Y>& pAuto):ptr(pAuto.ptr),owns(pAuto.owns)
{
	pAuto.owns = false;
}


template <typename T>
Auto_ptr<T>::~Auto_ptr()
{
	if(owns){
		delete ptr;
		ptr = nullptr;
	}
}

template <typename T>
Auto_ptr<T>& Auto_ptr<T>::operator =(const Auto_ptr<T>& pAuto)
{
	if(&pAuto != this){
		if(owns) delete ptr;
		owns = pAuto.owns;
		ptr = pAuto.ptr;
		pAuto.owns = false;
	}
	return *this;
}

template <typename T>
template <typename Y>
Auto_ptr<T>& Auto_ptr<T>::operator =(const Auto_ptr<Y>& pAuto)
{
	if(&pAuto != this){
		if(owns) delete ptr;
		owns = pAuto.owns;
		ptr = pAuto.ptr;
		pAuto.owns = false;
	}
	return *this;	
}

template <typename T>
T& Auto_ptr<T>::operator *()const
{
	return *ptr;
}

template <typename T>
T* Auto_ptr<T>::operator ->()const
{
	return ptr;
}

template <typename T>
T* Auto_ptr<T>::get()const
{
	return ptr;
}

template <typename T>
void Auto_ptr<T>::reset(T* ptr)
{
	if(owns){
		if(this->ptr != ptr) delete ptr;
	}
	this->ptr = ptr; 
}

template <typename T>
T* Auto_ptr<T>::release()const
{
	if(owns){
		delete ptr;
		ptr = nullptr;
	}
}

#endif  //_AUTO_PTR_H