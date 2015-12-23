#pragma once

// Useful macros for development, will show a TODO message when compiling
#define STRING2(x) #x
#define STRING(x) STRING2(x)
#define TODO(msg) __pragma( message (__FILE__ "[" STRING(__LINE__) "] --- TODO: " msg ))

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <map>
#include <ctime>
#include <functional>

#include "sdl.h"

//#include "loguru.hpp"

#include "core/resources/contentManager.h"
#include "core/resources/iresource.h"

#include "core/util/timer.h"
#include "core/util/tweener.h"
#include "core/util/singleton.h"
