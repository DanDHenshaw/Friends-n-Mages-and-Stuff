#include "StateMachine.h"

#include "DEFINITIONS.h"

namespace Insignia
{
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		INSTRMENTATIONTIMER();

		this->_isAdding = true;
		this->_isReplacing = true;

		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		INSTRMENTATIONTIMER();

		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		INSTRMENTATIONTIMER();

		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();

			if (!this->_states.empty())
			{
				this->_states.top()->Resume();
			}

			this->_isRemoving = false;
		}

		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause();
				}
			}

			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			this->_isAdding = false;
		}
	}

	StateRef& StateMachine::GetActiveState()
	{
		INSTRMENTATIONTIMER();

		return this->_states.top();
	}

}
