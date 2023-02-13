#pragma once

#include "GameObject.h"
#include "Game.h"

namespace Insignia
{
	// Inherits the State class from 'GameObject.h'
	class Enemy : public GameObject
	{
	public:
		Enemy(GameDataRef data, ObjectType type);

		void Init() override;

		void HandleInput() override;
		void Update(float delta) override;
		void Draw(float delta) override;

	private:
		// Reference to GameData.
		GameDataRef _data;

		// Sprite for enemy
		sf::Sprite _enemy;

		// Clock for the Enemy.
		sf::Clock _clock;

		void Animations();
		int _idlePos = 0;
		int _walkingPos = 0;
		Vector2f _wandOffset;

		float _moveSpeed = MOVEMENT_SPEED;
		bool _isWalking = false;
	};
}