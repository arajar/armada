#include "pch.h"

// Hack so SDL 2.0.3 compiles without problems in Visual Studio 2015
extern "C" { FILE __iob_func[3] = { *stdin, *stdout, *stderr }; }

int main(int argc, char* argv[])
{
	return 0;
}
