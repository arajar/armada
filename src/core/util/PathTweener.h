#pragma once

namespace core
{
	namespace util
	{
		class PathTweener
		{
		public:
			PathTweener(const std::vector<math::vec2f>& values, uint32_t delay);
			virtual ~PathTweener();

		public:
			bool Update(uint32_t deltaTime);

		public:
			math::vec2f GetValue() const;
			uint32_t GetDelay() const;
			bool HasFinished() const;

		private:
			void Init();

		private:
			std::vector<math::vec2f> m_array;
			math::vec2f m_currentValue;
			uint32_t m_delayTime;
			uint32_t m_accumTime;
			bool m_hasFinished;

			float m_totalLength;
			core::util::Tweener<math::vec2f> m_tweener;

		private:
			struct DataValue
			{
				float delay;
				math::vec2f pos1;
				math::vec2f pos2;
				float length;
			};

			std::vector<DataValue> m_dataArray;
			int m_currentSegment;
		};
	}
}