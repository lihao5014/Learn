#ifndef _PERMISSION_H
#define _PERMISSION_H

#include <stdio.h>

#if defined _DEBUG_ | defined _TRACK_
#define DEBUG(expr) printf("%s =%d\n",#expr,(expr))
#define TRACK(expr)  \
	printf("[%s: %s %d] %s =%d\n",__FILE__,__func__,__LINE__,#expr,(expr))
#else
#define DEBUG(expr)
#define TRACK(expr)
#endif

typedef enum
{
	FALSE = 0,
	TRUE = 1
}BOOL;

typedef enum Permission
{
	NONE = 0,
	CREATE = 1,
	DELETE = CREATE * 2,
	OPEN = DELETE * 2,
	CLOSE = OPEN * 2,
	READ = CLOSE * 2,
	WRITR = READ * 2,
	SAVE = WRITR * 2,
	RENAME = SAVE * 2,
	COPY = RENAME * 2,
	PASTE = COPY * 2,
	CUT = PASTE * 2,
	
	Reader = OPEN|CLOSE|READ,
	Writer = OPEN|CLOSE|WRITR|SAVE,
	Developer = OPEN|CLOSE|READ|WRITR|SAVE|RENAME,
	MaintainUser = CREATE|DELETE|RENAME|COPY|PASTE|CUT,
	SuperUser = CREATE|DELETE|OPEN|CLOSE|READ|WRITR|SAVE|RENAME,
	AdminUser = CREATE|DELETE|OPEN|CLOSE|READ|WRITR|SAVE|RENAME|COPY|PASTE|CUT
}PermissionType;

BOOL isPermission(PermissionType power,PermissionType powerTo)
{
	return (power & powerTo) > 0;
}

void showPermission(enum Permission user)
{
	if(user & CREATE)
	{
		printf("create: %d\n",(user & CREATE) != 0);
	}
	
	if(user & DELETE)
	{
		printf("delete: %d\n",(user & DELETE) != 0);
	}
	
	if((user & OPEN) > 0)
	{
		fprintf(stdout,"open: %d\n",(user & OPEN) > 0);
	}
	
	if((user & CLOSE) > 0)
	{
		fprintf(stdout,"close: %d\n",(user & CLOSE) > 0);
	}
	
	if((user & READ) == READ)
	{
		printf("read: %d\n",(user & READ) == READ);
	}
	
	if((user & WRITR) == WRITR)
	{
		printf("write: %d\n",(user & WRITR) == WRITR);
	}
	
	if((user & SAVE) - SAVE == 0)
	{
		printf("save: %d\n",(user & SAVE) - SAVE == 0);
	}
	
	if((user & RENAME) - RENAME == 0)
	{
		printf("rename: %d\n",(user & RENAME) - RENAME == 0);
	}
	
	if((user & COPY) != 0)
	{
		printf("copy: %d\n",(user & COPY) != 0);
	}
	
	if((user & PASTE) != 0)
	{
		printf("PASTE: %d\n",(user & PASTE) != 0);
	}
	
	if((user & CUT) == CUT)
	{
		printf("cut: %d\n",(user & CUT) == CUT);
	}
}

#endif //_PERMISSION_H