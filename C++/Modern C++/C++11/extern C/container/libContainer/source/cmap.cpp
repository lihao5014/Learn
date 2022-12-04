#include "cmap.h"
#include <iostream>
#include <map>
#include <algorithm>

#define _DEBUG_ON_
#include "common.h"

using namespace std;

typedef struct CMapPrivate_t
{
	map<MapKey_t,MapValue_t> private_map;
}CMapPrivate,*CMapPrivatePtr;

CMapPtr map_create()
{
	CMapPrivatePtr mapPtr = new CMapPrivate;
	return reinterpret_cast<CMapPtr>(mapPtr);
}

CMapPtr map_copy(const CMapPtr pmap)
{
	if(pmap == NULL)
	{
		return NULL;
	}
	
	CMapPrivatePtr mapPtr = reinterpret_cast<CMapPrivatePtr>(pmap);
	CMapPrivatePtr newMapPtr = new CMapPrivate{mapPtr->private_map};
	return (CMapPtr)newMapPtr;
}

void map_destroy(CMapPtr* ppmap)
{
	if(*ppmap != NULL)
	{
		free(*ppmap);
		*ppmap = NULL;
	}
}

bool map_empty(const CMapPtr pmap)
{
	if(pmap == NULL)
	{
		Assert_print(pmap == NULL);
		return true;
	}

	CMapPrivatePtr mapPtr = (CMapPrivatePtr)pmap;
	return mapPtr->private_map.empty();
}

int map_size(const CMapPtr pmap)
{
	if(pmap == NULL)
	{
		Assert_print(pmap == NULL);
		return -1;
	}
	
	CMapPrivatePtr mapPtr = (CMapPrivatePtr)pmap;
	return mapPtr->private_map.size();	
}

MapValue_t* map_at(CMapPtr pmap,MapKey_t key)
{
	if(pmap == NULL)
	{
		Assert_print(pmap == NULL);
		return NULL;
	}
	
	CMapPrivatePtr mapPtr = reinterpret_cast<CMapPrivatePtr>(pmap);
	MapValue_t& value = mapPtr->private_map.at(key);
	return &value;
}

bool map_find(CMapPtr pmap,MapKey_t key)
{
	if(pmap == NULL)
	{
		Assert_print(pmap == NULL);
		return false;
	}
	
	CMapPrivatePtr mapPtr = reinterpret_cast<CMapPrivatePtr>(pmap);
	return mapPtr->private_map.count(key) > 0;
}

void map_insert(CMapPtr pmap,MapKey_t key,const MapValue_t value)
{
	if(pmap == NULL)
	{
		Assert_print(pmap == NULL);
		return;
	}
	
	CMapPrivatePtr mapPtr = (CMapPrivatePtr)pmap;
	mapPtr->private_map.insert(pair<MapKey_t,MapValue_t>(key,value));
}

void map_erase(CMapPtr pmap,MapKey_t key)
{
	if(pmap == NULL)
	{
		Assert_print(pmap == NULL);
		return;
	}

	CMapPrivatePtr mapPtr = (CMapPrivatePtr)pmap;
	mapPtr->private_map.erase(key);
}

void map_clear(CMapPtr pmap)
{
	if(pmap == NULL)
	{
		Assert_print(pmap == NULL);
		return;
	}

	CMapPrivatePtr mapPtr = (CMapPrivatePtr)pmap;
	mapPtr->private_map.clear();	
}

void map_foreach(CMapPtr pmap,pFunction pfun)
{
	if(pmap == NULL || pfun == NULL)
	{
		Assert_print(pmap == NULL || pfun == NULL);
		return;
	}

	CMapPrivatePtr mapPtr = reinterpret_cast<CMapPrivatePtr>(pmap);
	auto& mapRef = mapPtr->private_map;
	map<MapKey_t,MapValue_t>::iterator iter = mapRef.begin();
	for(;iter != mapRef.end();++iter)
	{
		MapValue_t* pvalue = &iter->second;
		pfun(pvalue);
	}
}

void map_print(const CMapPtr pmap)
{
	if(pmap == NULL)
	{
		Assert_print(pmap == NULL);
		return;
	}
	
	CMapPrivatePtr mapPtr = reinterpret_cast<CMapPrivatePtr>(pmap);
	auto& mapRef = mapPtr->private_map;
	for_each(mapRef.begin(),mapRef.end(),
		[](const auto& tempPair){
			cout<<tempPair.first<<" : "<<tempPair.second<<endl;
		}
	);
}