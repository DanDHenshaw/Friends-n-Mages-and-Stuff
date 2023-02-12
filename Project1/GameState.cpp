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

		Killbeam* killbeam = new Killbeam(_data, GameObject::KILLBEAM);
		this->entities.push_back(killbeam);

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

			switch (entity->_type)
			{
			case entity->PLAYER1:
				wand1Pos = entity->wandPos;
				break;
			case entity->PLAYER2:
				wand2Pos = entity->wandPos;
				break;
			case entity->KILLBEAM:
				entity->wandPos = wand1Pos;
				entity->extraWandPos = wand2Pos;
				break;
			}
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