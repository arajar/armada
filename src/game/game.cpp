#include "pch.h"
#include "game.h"
#include <pug/graphics/context.h>
#include <SDL.h>
#include <pug/states/state_manager.h>

const int game::FPS = 30;
const int game::SKIP_TICKS = 1000 / game::FPS;

game::game()
	: running_(true)
	, gfx_ctx_(nullptr)
{
}

game::~game()
{
	if (gfx_ctx_)
	{
		gfx_ctx_ = nullptr;
	}
}

bool game::init(int argc, char* argv[])
{
	gfx_ctx_ = std::make_shared<gfx::context>();
	gfx_ctx_->init("pug", 100, 100, 300, 300);

	return true;
}

void game::run()
{
	// simple game loop
	running_ = true;
	while (running_)
	{
		// check for events while the game is running
		fpsTimer_.start();
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running_ = false;
			}

			//handleEvents(event);
		}

		// fixed framerate for simplicity - the game always runs at 30 fps
		update(game::SKIP_TICKS);
		render();

		if (fpsTimer_.ticks() < 1000.0 / game::FPS)
		{
			SDL_Delay((1000 / game::FPS) - fpsTimer_.ticks());
		}
	}
}

void game::handleEvents(const SDL_Event& event)
{
	// forward the events to the current gamestate
	states::manager::get_instance()->handleEvents(event);
}

void game::update(uint32_t deltaTime)
{
	// update the current gamestate
	states::manager::get_instance()->update(deltaTime);
}

void game::render()
{
	// render the current gamestate
	gfx_ctx_->renderer().clear(123, 11, 234);

	states::manager::get_instance()->render();

	gfx_ctx_->renderer().present();
}
