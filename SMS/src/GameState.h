#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

#include "GameObject.h"
#include "Player.h"
#include "Killbeam.h"

namespace Insignia
{
	// Inherits the State class from 'State.h'
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init() override;

		void HandleInput() override;
		void Update(float delta) override;
		void Draw(float delta) override;

	private:
		// Reference to GameData.
		GameDataRef _data;

		// Vector of all gameobjects
		vector<std::shared_ptr<GameObject>> entities;

		sf::Vector2f wand1Pos;
		sf::Vector2f wand2Pos;
	};
}