#ifndef _VARIABLE_H
#define _VARIABLE_H

#include <array>
#include <string>

#define _DUMMY_
// #undef _DUMMY_

typedef enum Attribute_t
{
	VAR_NAME,
	INIT_VALUE,
	DATA_TYPE,
	IO_TYPE,
	UNIT_INDEX,
	TOP_LIMIT,
	BOTTOM_LIMIT,
	TOP_VIEW,
	BOTTOM_VIEW,
	ATTRIBUTE_COUNT
}Attribute_t;

extern std::array<std::string,ATTRIBUTE_COUNT> variable;

extern void initVariable();

#endif //_VARIABLE_H