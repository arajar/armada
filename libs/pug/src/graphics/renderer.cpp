#include <GL/glew.h>
#include <SDL.h>
#include <pug/graphics/renderer.h>

namespace gfx
{
	renderer::renderer(gfx::window* win)
		: ctx_(SDL_GL_CreateContext(*win))
		, win_(win)
	{
	}

	renderer::~renderer()
	{
		SDL_GL_DeleteContext(ctx_);
	}

	void renderer::clear(uint8_t r, uint8_t g, uint8_t b) const
	{
		glClearColor(r / 255.f, g / 255.f, b / 255.f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void renderer::present() const
	{
		SDL_GL_SwapWindow(*win_);
	}
}
