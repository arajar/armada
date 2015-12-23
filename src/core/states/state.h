#pragma once

namespace states
{
	// simple state class
	class state
	{
	public:
		state() {}

		virtual ~state() {}

		virtual void start() = 0;
		virtual void resume() = 0;
		virtual void suspend() = 0;
		virtual void end() = 0;

	public:
		virtual void handleEvents(const SDL_Event& ev) { }
		virtual void update(uint32_t deltaTime) { }
		virtual void render(core::gfx::renderer& renderer) { }
	};
}