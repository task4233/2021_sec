#ifndef ___ERROR_HPP
#define ___ERROR_HPP

#include <stdio.h>
#include <time.h>

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "macro.hpp"

void push_error_log(const char *comment, const char *file, const char *func,
                    const int line);

#endif
