#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Insignia
{
	// Inherits the State class from 'State.h'
	class MenuState : public State
	{
	public:
		MenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float delta);
		void Draw(float delta);

	private:
		// Reference to GameData.
		GameDataRef _data;

		// Clock for the Splash Screen.
		sf::Clock _clock;

		// Splash screen background image.
		sf::Sprite _background;
	};
}