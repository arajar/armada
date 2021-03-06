#include "pch.h"
#include "game.h"
#include <pug/graphics/context.h>
#include <SDL.h>
#include <pug/states/state_manager.h>

const int game::FPS = 30;
const int game::SKIP_TICKS = 1000 / game::FPS;

game::game()
	: running_(true)
	, gfx_context_(nullptr)
{
}

game::~game()
{
	if (gfx_context_)
	{
		gfx_context_ = nullptr;
	}
}

bool game::init(int argc, char* argv[])
{
	gfx_context_ = std::make_shared<gfx::context>();
	gfx_context_->init(util::format("armada - {0}.{1}.{2}", version::major, version::minor, version::build)
		, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480);

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
	gfx_context_->renderer().clear(64, 64, 64);

	states::manager::get_instance()->render();

	gfx_context_->renderer().present();
}
