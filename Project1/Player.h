#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"

namespace Insignia
{
	// Inherits the State class from 'GameObject.h'
	class Player : public GameObject
	{
	public:
		Player(GameDataRef data);

		void Init() override;

		void HandleInput() override;
		void Update(float delta) override;
		void Draw(float delta) override;

	private:
		// Reference to GameData.
		GameDataRef _data;

		// Sprite for mage 1
		sf::Sprite _player1;
		// Sprite for mage 2
		sf::Sprite _player2;
		// Sprite for magic kill beam
		sf::Sprite _magicBeam;

		// Clock for the Player.
		sf::Clock _clock;

		int idlePos = 0;
	};
}