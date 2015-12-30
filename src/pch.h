#pragma once

struct version
{
	static int major;
	static int minor;
	static int build;
};

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

#include <pug.h>
