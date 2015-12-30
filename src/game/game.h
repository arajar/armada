#pragma once
#include <pug/util/timer.h>

union SDL_Event;

namespace gfx
{
	class context;
	class window;
	class renderer;
}

class game
{
public:
	static const int FPS;
	static const int SKIP_TICKS;

public:
	game();
	virtual ~game();

	game(const game&) = delete; // disallow copying
	game& operator=(const game&) = delete; // disallow copying

public:
	bool init(int argc, char* argv[]);
	void run();

public:
	virtual void handleEvents(const SDL_Event& event);
	virtual void update(uint32_t deltaTime);
	virtual void render();

private:
	bool running_;

private:
	//config::cfg* gameConfig_;

	pug::util::timer fpsTimer_;

private:
	std::shared_ptr<gfx::context> gfx_context_;
};