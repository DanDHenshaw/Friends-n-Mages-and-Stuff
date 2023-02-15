#include "GameState.h"
#include <sstream>
#include <iostream>

namespace Insignia
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
		INSTRMENTATIONTIMER();
	}

	void GameState::Init()
	{
		INSTRMENTATIONTIMER();

		// // Creates and Adds the killbeam pointer to a vector of entities.
		std::shared_ptr<Killbeam> killbeam(new Killbeam(_data, GameObject::KILLBEAM));
		this->entities.push_back(killbeam);

		// Creates and Adds player1 pointer to a vector of entities.
		std::shared_ptr<Player> player1(new Player(_data, GameObject::PLAYER1));
		this->entities.push_back(player1);

		// Creates and Adds player2 pointer to a vector of entities.
		std::shared_ptr<Player> player2(new Player(_data, GameObject::PLAYER2));
		this->entities.push_back(player2);

		// Initialises all entities.
		for (auto & entity : this->entities)
		{
			entity->Init();
		}
	}

	void GameState::HandleInput()
	{
		INSTRMENTATIONTIMER();

		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void GameState::Update(float delta)
	{
		INSTRMENTATIONTIMER();

		// Loops through all entities.
		for (auto& entity : this->entities)
		{
			// Handles all entity input.
			entity->HandleInput();
			// Handles all entity updates.
			entity->Update(delta);

			switch (entity->_type)
			{
			// Checks if player1.
			case GameObject::PLAYER1:
				// Sets wand1Pos to player1 wandPos (includes offset).
				wand1Pos = entity->wandPos;
				break;
			// Checks if player2.
			case GameObject::PLAYER2:
				// Sets wand2Pos to player2 wandPos (includes offset).
				wand2Pos = entity->wandPos;
				break;
			// Checks if Killbeam.
			case GameObject::KILLBEAM:
				// Sets wandPos to the wand1Pos.
				entity->wandPos = wand1Pos;
				// Sets extraWandPos to the wand2Pos.
				entity->extraWandPos = wand2Pos;
				break;
			default:
				break;
			}
		}
	}

	void GameState::Draw(float delta)
	{
		INSTRMENTATIONTIMER();

		this->_data->window.clear(sf::Color::Red);

		// Draws all entities.
		for (auto& entity : this->entities)
		{
			entity->Draw(delta);
		}

		this->_data->window.display();
	}

}