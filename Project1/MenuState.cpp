#include "MenuState.h"
#include <sstream>
#include <iostream>

namespace Insignia
{
	MenuState::MenuState(GameDataRef data) : _data(data)
	{

	}

	void MenuState::Init()
	{
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}

	void MenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->_data->window.close();
				break;
			}
		}
	}

	void MenuState::Update(float delta)
	{
		
	}

	void MenuState::Draw(float delta)
	{
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		this->_data->window.display();
	}

}