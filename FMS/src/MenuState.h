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
		sf::Sprite _playButton;

		// Leaderboard button sprite
		sf::Sprite _leaderboardButton;

		// Close button sprite.
		sf::Sprite _exitButton;

		// Game title sprite.
		sf::Sprite _title;
	};
}