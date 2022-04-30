#ifndef _UTIL_H
#define _UTIL_H

#include <vector>
#include <string>

std::vector<int> twice(const std::vector<int>& vec);
std::vector<int> square(const std::vector<int>& vec);

int summate(const std::vector<int>& vec);
int product(const std::vector<int>& vec);
std::string concat(const std::vector<std::string>& vec);

#endif  //_UTIL_H