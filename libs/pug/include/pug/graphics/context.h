#pragma once

#include "window.h"
#include "renderer.h"

namespace gfx
{
	class context
	{
	public:
		explicit context();

		virtual ~context();

		void init(const std::string& name, int x, int y, int w, int h);
		void resize(int w, int h) const;
		gfx::renderer& renderer() const;

	private:
		gfx::renderer* renderer_;
		gfx::window* window_;
	};
}
