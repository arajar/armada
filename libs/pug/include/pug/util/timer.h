#pragma once
#include <cstdint>

namespace pug
{
	namespace util
	{
		class timer
		{
		public:
			enum class status
			{
				Started,
				Paused,
				Stopped,
			};

		public:
			timer();
			virtual ~timer();

		public:
			void start();
			void stop();
			void pause();
			void resume();

		public:
			uint32_t ticks() const;

			status getStatus() const;

		private:
			uint32_t startTicks_;
			uint32_t pausedTicks_;

			status status_;
		};
	}
}
