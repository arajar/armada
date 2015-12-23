#pragma once

#include "SDL.h"
#include <memory>
#include <string>

namespace core
{
	namespace gfx
	{
		class surface
		{
		public:
			using SurfacePtr = std::unique_ptr<SDL_Surface, decltype(SDL_FreeSurface)*>;

		public:
			explicit surface(SDL_Surface* ptr) : ptr_(ptr, SDL_FreeSurface) {}

		public:
			operator SDL_Surface*() const
			{
				return ptr_.get();
			}

		private:
			SurfacePtr ptr_;
		};
	}
}