#ifndef _HANDLE_H
#define _HANDLE_H

#define DECLARE_HANDLE(name)     \
struct name##__                  \
{                                \
	int unused;                  \
};                               \
                                 \
typedef struct name##__* name

typedef void* HANDLE;

#endif //_HANDLE_H