#include "cvector.h"
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>     //algorithm头文件中的所有算法，都不能改变容器的实际大小

#define _DEBUG_ON_
#include "common.h"

#define EPS 0.000001

using namespace std;

typedef struct CVecterInternal_
{
	vector<VectorData_t> internal_vector;
}CVecterInternal,*CVecterInternalPtr;

CVecterPtr vector_create_default()
{
	CVecterInternalPtr pvecInternal = new CVecterInternal;
	return reinterpret_cast<CVecterPtr>(pvecInternal);
}

CVecterPtr vector_create_by_size(int size,const VectorData_t data)
{
	CVecterInternalPtr pvecInternal = new CVecterInternal;
	pvecInternal->internal_vector.assign(size,data);
	return (CVecterPtr)pvecInternal;
}

CVecterPtr vector_create_by_array(const VectorData_t arr[],int len)
{
	CVecterInternalPtr pvecInternal = new CVecterInternal;
	pvecInternal->internal_vector.assign(arr,arr + len);
	return (CVecterPtr)pvecInternal;	
}

CVecterPtr vector_create_by_copy(const CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return NULL;
	}
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	CVecterInternalPtr pnewVecInternal = new CVecterInternal;
	pnewVecInternal->internal_vector = pvecInternal->internal_vector;
	return reinterpret_cast<CVecterPtr>(pnewVecInternal);
}

void vector_destroy(CVecterPtr* pvecPtr)
{
	if(pvecPtr == nullptr)
	{
		Assert_print(pvecPtr == nullptr);
		return;
	}
	
	if(*pvecPtr == nullptr)
	{
		Assert_print(*pvecPtr == nullptr);
		return;
	}
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(*pvecPtr);
	delete pvecInternal;
	*pvecPtr = nullptr;
}

void vector_assign_with_size(CVecterPtr pvec,int size,const VectorData_t data)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	pvecInternal->internal_vector.assign(size,data);
}

void vector_assign_with_array(CVecterPtr pvec,const VectorData_t arr[],int len)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	CVecterInternalPtr pvecInternal = (CVecterInternalPtr)pvec;
	pvecInternal->internal_vector.assign(arr,arr + len);	
}

bool vector_empty(const CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return true;
	}
	
	const CVecterInternalPtr pvecInternal = (const CVecterInternalPtr)pvec;
	return pvecInternal->internal_vector.empty();
}

int vector_size(const CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return -1;
	}

	const CVecterInternalPtr pvecInternal = reinterpret_cast<const CVecterInternalPtr>(pvec);
	return pvecInternal->internal_vector.size();
}

void vector_push_back(CVecterPtr pvec,const VectorData_t data)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	pvecInternal->internal_vector.push_back(data);
}

void vector_pop_back(CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	CVecterInternalPtr pvecInternal = (CVecterInternalPtr)pvec;
	pvecInternal->internal_vector.pop_back();	
}

VectorData_t* vector_front(CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return NULL;
	}
	
	CVecterInternalPtr pvecInternal = (CVecterInternalPtr)pvec;
	VectorData_t& data = pvecInternal->internal_vector.front();
	return &data;
}

VectorData_t* vector_back(CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return NULL;
	}
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	VectorData_t& data = pvecInternal->internal_vector.back();
	return &data;	
}

VectorData_t* vector_at(CVecterPtr pvec,int index)
{
	assert(pvec != nullptr);
	assert(index > 0 && index < vector_size(pvec));
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	VectorData_t& data = pvecInternal->internal_vector.at(index);
	return &data;
}

void vector_insert(CVecterPtr pvec,int pos,const VectorData_t data)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	if(pos < 0 || pos > vector_size(pvec))
	{
		Assert_print(pos < 0 || pos > vector_size(pvec));
		return;
	}
	
	CVecterInternalPtr pvecInternal = (CVecterInternalPtr)pvec;
	auto iter = pvecInternal->internal_vector.begin();
	std::advance(iter,pos);
	pvecInternal->internal_vector.insert(iter,data);
}

void vector_replace(CVecterPtr pvec,int pos,const VectorData_t data)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	if(pos < 0 || pos > vector_size(pvec))
	{
		Assert_print(pos < 0 || pos > vector_size(pvec));
		return;
	}
	
	CVecterInternalPtr pvecInternal = (CVecterInternalPtr)pvec;
	pvecInternal->internal_vector[pos] = data;
}

void vector_change(CVecterPtr pvec,const VectorData_t oldData,const VectorData_t newData)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	auto& vecRef = pvecInternal->internal_vector;
	std::replace(vecRef.begin(),vecRef.end(),oldData,newData);
}

int vector_find(const CVecterPtr pvec,const VectorData_t data)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return -1;
	}
	
	const CVecterInternalPtr pvecInternal = reinterpret_cast<const CVecterInternalPtr>(pvec);
	const auto& vecRef = pvecInternal->internal_vector;
	auto iter = std::find(vecRef.begin(),vecRef.end(),data);
	if(iter == vecRef.end())
	{
		return -1;
	}
	
	return std::distance(vecRef.begin(),iter);	
}

void vector_clear(CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}

	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	pvecInternal->internal_vector.clear();	
}

void vector_erase(CVecterPtr pvec,int pos)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}

	if(pos < 0 || pos >= vector_size(pvec))
	{
		Assert_print(pos < 0 || pos >= vector_size(pvec));
		return;
	}

	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	vector<VectorData_t>::iterator iter = pvecInternal->internal_vector.begin();
	std::advance(iter,pos);
	pvecInternal->internal_vector.erase(iter);	
}

void vector_remove(CVecterPtr pvec,const VectorData_t data)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	auto& vecRef = pvecInternal->internal_vector;
	
	/*std::remove()并不改变容器的大小，只是用后面的值覆盖掉需要remove的值。algorithm头文件中的所有算法，
	 *都不能改变容器的实际大小。要改变容器真正的大小，还得使用容器自己提供的成员函数。因为所有的algorithm
	 *算法也都可以应用于原始数组，而原始数组的大小是不能被改变的。
	 */
	vector<VectorData_t>::iterator iter = std::remove(vecRef.begin(),vecRef.end(),data);
	pvecInternal->internal_vector.erase(iter,vecRef.end());      //需要使用容器的成员函数，才能真正改变容器的大小。
}

void vector_remove_if(CVecterPtr pvec,UnaryPred pred)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}

	if(pred == nullptr)
	{
		Assert_print(pred == nullptr);
		return;
	}

	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	auto& vecRef = pvecInternal->internal_vector;
	auto iter = std::remove_if(vecRef.begin(),vecRef.end(),pred);
	pvecInternal->internal_vector.erase(iter,vecRef.end());
}

void vector_sort_default(CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	vector<VectorData_t>& vecRef = pvecInternal->internal_vector;
	std::sort(vecRef.begin(),vecRef.end());	
}

void vector_sort(CVecterPtr pvec,CompareFunc comp)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}

	if(comp == nullptr)
	{
		Assert_print(comp == nullptr);
		return;
	}

	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	vector<VectorData_t>& vecRef = pvecInternal->internal_vector;
	std::sort(vecRef.begin(),vecRef.end(),comp);	
}

void vector_reverse(CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}

	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	vector<VectorData_t>& vecRef = pvecInternal->internal_vector;
	std::reverse(vecRef.begin(),vecRef.end());	
}

bool vector_all(const CVecterPtr pvec,const UnaryPred pred)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return false;
	}

	if(pred == nullptr)
	{
		Assert_print(pred == nullptr);
		return false;
	}
	
	const CVecterInternalPtr pvecInternal = reinterpret_cast<const CVecterInternalPtr>(pvec);
	const auto& vecRef = pvecInternal->internal_vector;
	return std::all_of(vecRef.begin(),vecRef.end(),pred);
}

bool vector_any(const CVecterPtr pvec,const UnaryPred pred)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return false;
	}

	if(pred == nullptr)
	{
		Assert_print(pred == nullptr);
		return false;
	}
	
	const CVecterInternalPtr pvecInternal = reinterpret_cast<const CVecterInternalPtr>(pvec);
	const auto& vecRef = pvecInternal->internal_vector;
	return std::any_of(vecRef.begin(),vecRef.end(),pred);	
}

void vector_foreach(CVecterPtr pvec,pCallBack pfun)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}

	if(pfun == nullptr)
	{
		Assert_print(pfun == nullptr);
		return;
	}
	
	CVecterInternalPtr pvecInternal = reinterpret_cast<CVecterInternalPtr>(pvec);
	vector<VectorData_t>& vecRef = pvecInternal->internal_vector;
	for(VectorData_t& data : vecRef)
	{
		pfun(&data);
	}
}

void vector_print(const CVecterPtr pvec)
{
	if(pvec == nullptr)
	{
		Assert_print(pvec == nullptr);
		return;
	}
	
	struct 
	{
		void operator ()(const VectorData_t& data)
		{
			std::cout<<data<<" ";
		}
	}printObj;
	
	const CVecterInternalPtr pvecInternal = reinterpret_cast<const CVecterInternalPtr>(pvec);
	const vector<VectorData_t>& vecRef = pvecInternal->internal_vector;
	std::for_each(vecRef.begin(),vecRef.end(),printObj);
	cout<<"\n";
}