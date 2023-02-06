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
		Player(GameDataRef data, ObjectType type);

		void Init() override;

		void HandleInput() override;
		void Update(float delta) override;
		void Draw(float delta) override;

	private:
		// Reference to GameData.
		GameDataRef _data;

		// Sprite for mage 1
		sf::Sprite _player;

		// Clock for the Player.
		sf::Clock _clock;

		int idlePos = 0;
		int walkingPos = 0;

		float _moveSpeed = MOVEMENT_SPEED;
		bool isWalking = false;
	};
}