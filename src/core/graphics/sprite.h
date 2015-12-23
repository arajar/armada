#pragma once
#include "texture2d.h"

namespace core
{
	namespace gfx
	{
		struct sprite
		{
			sprite() = default;
			sprite(gfx::texture2d tex, SDL_Rect pos):tex_(tex), pos_(pos) {}

			gfx::texture2d tex_;
			SDL_Rect pos_;
		};
	}
}
