#pragma once

#include "SDL.h"

#include "window.h"
#include "renderer.h"

namespace core
{
	namespace gfx
	{
		class context : public singleton<context>
		{
		public:
			context() : context(SDL_INIT_EVERYTHING) { }
			explicit context(uint32_t flags) : renderer_(nullptr), window_(nullptr)
			{
				SDL_Init(flags);
			}

			virtual ~context()
			{
				SDL_Quit();
			}

			void init(const std::string& name, int x, int y, int w, int h, uint32_t flags)
			{
				window_ = new gfx::window(name, x, y, w, h, 0);
				renderer_ = window_->createRenderer(-1, flags);
			}

			void resize(int w, int h) const { window_->resize(w, h); }
			gfx::renderer& getRenderer() const { return *renderer_; }

		private:
			gfx::renderer* renderer_;
			gfx::window* window_;
		};
	}
}