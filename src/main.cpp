#include "pch.h"
#include "game/game.h"

int main(int argc, char* argv[])
{
	game g;
	if (g.init(argc, argv))
	{
		g.run();
	}

	return 0;
}
