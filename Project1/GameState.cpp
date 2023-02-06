#include "GameState.h"
#include <sstream>
#include <iostream>

namespace Insignia
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
		
	}

	void GameState::Init()
	{
		// Creates and Adds player1 pointer to a vector of entities
		Player* player1 = new Player(_data, GameObject::PLAYER1);
		this->entities.push_back(player1);

		// Creates and Adds player2 pointer to a vector of entities
		Player* player2 = new Player(_data, GameObject::PLAYER2);
		this->entities.push_back(player2);

		for (auto & entity : this->entities)
		{
			entity->Init();
		}
	}

	void GameState::HandleInput()
	{
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
		for (auto& entity : this->entities)
		{
			entity->HandleInput();
			entity->Update(delta);
		}
	}

	void GameState::Draw(float delta)
	{
		this->_data->window.clear(sf::Color::Red);

		for (auto& entity : this->entities)
		{
			entity->Draw(delta);
		}

		this->_data->window.display();
	}

}