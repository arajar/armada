#include "pch.h"
#include "state_manager.h"

//////////////////////////////////////////////////////////////////////////

namespace states
{
	manager::manager()
	{
	}

	//////////////////////////////////////////////////////////////////////////

	void manager::update(uint32_t deltaTime)
	{
		if (!m_states.empty())
		{
			m_states.back()->update(deltaTime);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////

	void manager::render(core::gfx::renderer& renderer)
	{
		if (!m_states.empty())
		{
			m_states.back()->render(renderer);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	
	void manager::handleEvents(const SDL_Event& ev)
	{
		if (!m_states.empty())
		{
			m_states.back()->handleEvents(ev);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	
	state* manager::getCurrentState()
	{
		return m_states.back();
	}

	//////////////////////////////////////////////////////////////////////////

	bool manager::popState()
	{
		if (!m_states.empty())
		{
			auto lastState = m_states.back();
			lastState->suspend();
			lastState->end();
			m_states.pop_back();
		}

		return m_states.empty();
	}

	//////////////////////////////////////////////////////////////////////////

	void manager::popAllStates()
	{
		if (!m_states.empty())
		{
			auto lastState = m_states.back();
			lastState->suspend();
		}

		while (!m_states.empty())
		{
			auto lastState = m_states.back();
			lastState->end();
			m_states.pop_back();
		}
	}
}