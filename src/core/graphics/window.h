#pragma once

#include <sdl.h>
#include <memory>
#include <string>

namespace core
{
	namespace gfx
	{
		class renderer;

		class window
		{
		public:
			using WindowPtr = std::unique_ptr<SDL_Window, decltype(SDL_DestroyWindow)*>;

			window() = default;
			window(const std::string& name, int x, int y, int w, int h, uint32_t flags);
			renderer* createRenderer(int idx, uint32_t flags) const;

		public:
			void resize(int w, int h) const;

		public:
			operator SDL_Window*() const
			{ return ptr_.get(); }

		private:
			WindowPtr ptr_;
		};
	}
}
