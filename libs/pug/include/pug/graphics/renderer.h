#pragma once

#include "window.h"

typedef void *SDL_GLContext;

namespace gfx
{
	class renderer
	{
	public:
		renderer() = default;
		explicit renderer(gfx::window* win);

		~renderer();

	public:
		void clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) const;
		void present() const;

	public:
		operator SDL_GLContext() const
		{
			return ctx_;
		}

	private:
		SDL_GLContext ctx_;
		gfx::window* win_;
	};
}
