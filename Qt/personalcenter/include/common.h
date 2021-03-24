#ifndef _COMMON_H
#define _COMMON_H

#include <QString>

#ifdef _TRANSLATE_
#define TR(str) QString::fromLocal8Bit(str)
#else
#define TR(str) str
#endif

#endif //_COMMON_H