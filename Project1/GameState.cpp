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
		// Creates and Adds player pointer to a vector of entities
		Player* player = new Player(_data);
		this->entities.push_back(player);

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