#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Insignia
{
	// Inherits the State class from 'State.h'
	class PauseState : public State
	{
	public:
		PauseState(GameDataRef data);

		void Init() override;

		void HandleInput() override;
		void Update(float delta) override;
		void Draw(float delta) override;

	private:
		// Reference to GameData.
		GameDataRef _data;

		// Splash screen background image.
		sf::Sprite _background;

		// Play button sprite.
		sf::Sprite _resumeButton;

		// Menu button sprite.
		sf::Sprite _menuButton;

		// Close button sprite.
		sf::Sprite _exitButton;
	};
}