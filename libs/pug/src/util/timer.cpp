#include <pug/util/timer.h>
#include <SDL_timer.h>

namespace pug
{
	namespace util
	{
		timer::timer()
			: startTicks_(0)
			, pausedTicks_(0)
			, status_(status::Stopped)
		{
		}

		timer::~timer()
		{
		}

		void timer::start()
		{
			status_ = status::Started;

			startTicks_ = SDL_GetTicks();
			pausedTicks_ = 0;
		}

		void timer::stop()
		{
			status_ = status::Stopped;

			startTicks_ = 0;
			pausedTicks_ = 0;
		}

		void timer::pause()
		{
			if (status_ == status::Started)
			{
				status_ = status::Paused;

				pausedTicks_ = SDL_GetTicks() - startTicks_;
				startTicks_ = 0;
			}
		}

		void timer::resume()
		{
			if (status_ == status::Paused)
			{
				status_ = status::Started;

				startTicks_ = SDL_GetTicks() - pausedTicks_;
				pausedTicks_ = 0;
			}
		}

		uint32_t timer::ticks() const
		{
			uint32_t time = 0;

			if (status_ == status::Started)
			{
				time = SDL_GetTicks() - startTicks_;
			}
			else if (status_ == status::Paused)
			{
				time = pausedTicks_;
			}

			return time;
		}

		timer::status timer::getStatus() const
		{
			return status_;
		}
	}
}
