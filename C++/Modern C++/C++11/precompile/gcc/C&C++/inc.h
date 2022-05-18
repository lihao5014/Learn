/*1.如何使用gch文件:
 *如果同一个目录下有inc.h和inc.h.gch两个文件，那么gcc会自动使用inc.h.gch文件，即使后来修改了inc.h文件。
 *如果不重新编译更新inc.h.gch的话，对于inc.h的更改没有效果的。所以.h头文件更改后要及时编译更新.gch文件。
 *如果程序简单的话，可以每次编译的时候都删除相关的.gch文件。
 */

#ifndef _INC_H_
#define _INC_H_

#include "person.h"
#include "matrix.h"

#endif  //_INC_H_