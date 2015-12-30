
#include <pug/graphics/context.h>
#include <SDL.h>

namespace gfx
{
	context::context()
	: renderer_(nullptr)
	, window_(nullptr)
	{
		SDL_Init(SDL_INIT_EVERYTHING | SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_OPENGL);
	}
	
	context::~context()
	{
		SDL_Quit();
	}
	
	void context::init(const std::string& name, int x, int y, int w, int h)
		{
			window_ = new gfx::window(name, x, y, w, h, 0);
			renderer_ = window_->createRenderer();
		}
		
	void context::resize(int w, int h) const { window_->resize(w, h); }
	gfx::renderer& context::renderer() const { return *renderer_; }

}
