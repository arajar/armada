#include "pch.h"
#include "window.h"
#include "renderer.h"

namespace core
{
	namespace gfx
	{
		window::window(const std::string& name, int x, int y, int w, int h, uint32_t flags)
			: ptr_(SDL_CreateWindow(name.c_str(), x, y, w, h, flags), SDL_DestroyWindow)
		{
		}

		renderer* window::createRenderer(int idx, uint32_t flags) const
		{
			return new renderer { *this, idx, flags };
		}

		void window::resize(int w, int h) const
		{
			SDL_SetWindowSize(*this, w, h);
		}
	}
}