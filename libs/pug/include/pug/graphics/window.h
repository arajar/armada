#pragma once

#include <memory>
#include <string>
#include <functional>

struct SDL_Window;

namespace gfx
{
	class renderer;

	class window
	{
	public:
		using WindowPtr = std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>;

		window() = default;
		window(const std::string& name, int x, int y, int w, int h, uint32_t flags);
		renderer* createRenderer();

	public:
		void resize(int w, int h) const;

	public:
		operator SDL_Window*() const
		{
			return ptr_.get();
		}

	private:
		WindowPtr ptr_;
	};
}
