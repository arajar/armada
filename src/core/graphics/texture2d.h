#pragma once

#include <memory>
#include "SDL.h"

namespace core
{
	namespace gfx
	{
		class texture2d
		{
		public:
			using TexturePtr = std::shared_ptr<SDL_Texture>;

		public:
			texture2d() = default;
			explicit texture2d(SDL_Texture* ptr) : ptr_(ptr, SDL_DestroyTexture) {}

		public:
			operator SDL_Texture*() const
			{
				return ptr_.get();
			}

		private:
			TexturePtr ptr_;
		};
	}
}