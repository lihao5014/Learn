#ifndef _C_MAP_H_
#define _C_MAP_H_

#include <stdbool.h>

typedef void* CMapPtr;

typedef const char* MapKey_t;
typedef char MapValue_t;

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*pFunction)(MapValue_t* pvalue);

CMapPtr map_create();
CMapPtr map_copy(const CMapPtr pmap);
void map_destroy(CMapPtr* ppmap);

bool map_empty(const CMapPtr pmap);
int map_size(const CMapPtr pmap);

MapValue_t* map_at(CMapPtr pmap,MapKey_t key);
bool map_find(CMapPtr pmap,MapKey_t key);

void map_insert(CMapPtr pmap,MapKey_t key,const MapValue_t value);
void map_erase(CMapPtr pmap,MapKey_t key);

void map_clear(CMapPtr pmap);

void map_foreach(CMapPtr pmap,pFunction pfun);

void map_print(const CMapPtr pmap);

#ifdef __cplusplus
}
#endif

#endif  //_C_MAP_H_