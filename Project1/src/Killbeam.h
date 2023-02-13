#pragma once

#include "GameObject.h"
#include "Game.h"

namespace Insignia
{
	// Inherits the State class from 'GameObject.h'
	class Killbeam : public GameObject
	{
	public:
		Killbeam(GameDataRef data, ObjectType type);

		void Init() override;

		void HandleInput() override;
		void Update(float delta) override;
		void Draw(float delta) override;

	private:
		// Reference to GameData.
		GameDataRef _data;

		// Sprite for killbeam
		RectangleShape _killbeam;

		// Clock for the Player.
		sf::Clock _clock;

		int _animPos = 0;
	};
}