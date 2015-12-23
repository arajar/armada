#include "pch.h"
#include "PathTweener.h"

namespace core
{
	namespace util
	{
		PathTweener::PathTweener(const std::vector<math::vec2f>& values, uint32_t delay)
			: m_array(values)
			, m_delayTime(delay)
			, m_totalLength(0)
			, m_currentSegment(0)
		{
			Init();
		}

		PathTweener::~PathTweener()
		{

		}

		bool PathTweener::Update(uint32_t deltaTime)
		{
			m_tweener.Update(deltaTime);

			if (m_tweener.HasFinished())
			{
				if (m_currentSegment + 1 < m_dataArray.size())
				{
					m_currentSegment++;
					auto pos2 = m_dataArray[m_currentSegment].pos2;
					int delay = static_cast<int>(m_dataArray[m_currentSegment].delay);

					m_tweener.SetTargetValue(pos2);
					m_tweener.SetDelay(delay);
				}
			}

			return true;
		}

		math::vec2f PathTweener::GetValue() const
		{
			return m_tweener.GetValue();
		}

		uint32_t PathTweener::GetDelay() const
		{
			return m_delayTime;
		}

		bool PathTweener::HasFinished() const
		{
			return m_hasFinished;
		}

		void PathTweener::Init()
		{
			if (m_array.empty())
			{
				return;
			}

			// Get the total length of the array
			for (size_t i = 0; i < m_array.size() - 1; i++)
			{
				DataValue dataVal;

				dataVal.pos1 = m_array[i];
				dataVal.pos2 = m_array[i + 1];

				auto val = dataVal.pos1 - dataVal.pos2;

				dataVal.length = sqrtf(static_cast<float>(val.x * val.x + val.y * val.y));

				m_totalLength += abs(dataVal.length);

				m_dataArray.push_back(dataVal);
			}

			float prevDelay = 0.f;
			for (auto& val : m_dataArray)
			{
				float lengthForThisSegment = val.length / m_totalLength;
				val.delay = prevDelay + (static_cast<float>(m_delayTime) - prevDelay) * lengthForThisSegment;
				//prevDelay += val.delay;
			}

			auto pos1 = m_dataArray.front().pos1;
			auto pos2 = m_dataArray.front().pos2;
			int delay = static_cast<int>(m_dataArray.front().delay);

			m_tweener.SetEaseFunction([](float val) { return val; });

			m_tweener.Reset(pos1, pos2);
			m_tweener.SetDelay(delay);
		}
	}
}