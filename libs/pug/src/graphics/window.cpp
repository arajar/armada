#include <pug.h>
#include <pug/graphics/window.h>
#include <pug/graphics/renderer.h>

namespace gfx
{
	window::window(const std::string& name, int x, int y, int w, int h, uint32_t flags)
		: ptr_(SDL_CreateWindow(name.c_str(), x, y, w, h, flags | SDL_WINDOW_OPENGL), SDL_DestroyWindow)
	{
	}

	renderer* window::createRenderer()
	{
		return new renderer(this);
	}

	void window::resize(int w, int h) const
	{
		SDL_SetWindowSize(*this, w, h);
	}
}
