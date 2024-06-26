#pragma once

namespace Insignia
{
	class State
	{
	public:
		/*
		 Initialises the state.
		 */
		virtual void Init() = 0;

		/*
		 Handles the user input while in this state.
		 */
		virtual void HandleInput() = 0;
		/*
		 Updates the state every frame.
			- delta is the DeltaTime
		 */
		virtual void Update(float delta) = 0;
		/*
		 Draws the state every frame.
			- delta is the DeltaTime
		 */
		virtual void Draw(float delta) = 0;

		/*
		 Pauses the state.
		 */
		virtual void Pause() {}
		/*
		 Resumes the state.
		 */
		virtual void Resume() {}
	};
}