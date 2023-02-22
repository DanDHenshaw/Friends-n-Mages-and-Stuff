#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Insignia
{
	class LeaderboardItem
	{
	public:
		sf::RectangleShape background;
		sf::Text position, name, score;
	};

	// Inherits the State class from 'State.h'
	class LeaderboardState : public State
	{
	public:
		LeaderboardState(GameDataRef data);

		void Init() override;

		void HandleInput() override;
		void Update(float delta) override;
		void Draw(float delta) override;

	private:
		// Reference to GameData.
		GameDataRef _data;

		sf::Sprite _background;
		sf::RectangleShape _leaderboardBackground;

		sf::Sprite _menuButton;
		sf::Sprite _exitButton;

		std::vector<LeaderboardItem> items;
	};
}