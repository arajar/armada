#pragma once

#include <memory>
#include "SDL.h"

namespace core
{
	namespace gfx
	{
		class surface;
		class texture2d;
		struct sprite;

		// sdl wrapper class to handle all the rendering
		class renderer
		{
		public:
			using RendererPtr = std::unique_ptr<SDL_Renderer, decltype(SDL_DestroyRenderer)*>;

		public:
			renderer() = default;
			renderer(SDL_Window* win, int idx, uint32_t flags);

		public:
			texture2d createTexFromSurface(surface& surf) const;

		public:
			void clear(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) const;
			void renderCopy(texture2d& tex, SDL_Rect* src, SDL_Rect* dst, uint8_t alpha = 255) const;
			void present() const;

		public:
			void renderSprite(sprite sprite, SDL_Rect* dst) const;

		public:
			operator SDL_Renderer*() const
			{
				return ptr_.get();
			}

		private:
			RendererPtr ptr_;
		};
	}

}