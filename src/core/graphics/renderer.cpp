#include "pch.h"
#include "renderer.h"
#include "texture2d.h"
#include "sprite.h"
#include "surface.h"

namespace core
{
	namespace gfx
	{
		renderer::renderer(SDL_Window* win, int idx, uint32_t flags)
			: ptr_(SDL_CreateRenderer(win, idx, flags), SDL_DestroyRenderer)
		{
		}

		texture2d renderer::createTexFromSurface(surface& surf) const
		{
			auto tex = SDL_CreateTextureFromSurface(*this, surf);
			return texture2d(tex);
		}

		void renderer::clear(uint8_t r, uint8_t g, uint8_t b) const
		{
			SDL_SetRenderDrawColor(*this, r, g, b, 255);
			SDL_RenderClear(*this);
		}

		void renderer::renderCopy(texture2d& tex, SDL_Rect* src, SDL_Rect* dst, uint8_t alpha) const
		{
			SDL_SetTextureAlphaMod(tex, alpha);
			SDL_RenderCopy(*this, tex, src, dst);
		}

		void renderer::present() const
		{
			SDL_RenderPresent(*this);
		}

		void renderer::renderSprite(sprite sprite, SDL_Rect* dst) const
		{
			renderCopy(sprite.tex_, &sprite.pos_, dst);
		}
	}
}