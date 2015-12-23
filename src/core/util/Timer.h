#pragma once

namespace core
{
	namespace util
	{
		class Timer
		{
		public:
			enum class Status
			{
				STARTED,
				PAUSED,
				STOPPED,
			};

		public:
			Timer();
			virtual ~Timer();

		public:
			void Start();
			void Stop();
			void Pause();
			void Resume();

		public:
			uint32_t GetTicks() const;

			Status GetStatus() const;

		private:
			uint32_t m_startTicks;
			uint32_t m_pausedTicks;

			Status m_status;
		};
	}
}