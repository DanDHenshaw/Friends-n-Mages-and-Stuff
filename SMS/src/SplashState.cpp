#include "SplashState.h"
#include <sstream>
#include <iostream>

#include "MenuState.h"

namespace Insignia
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	// Initializes the state.
	void SplashState::Init()
	{
		INSTRMENTATIONTIMER();

		// Loads background texture.
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		// Sets background texture.
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}

	// Handles events.
	void SplashState::HandleInput()
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

	// Updates splash screen after SPLASH_STATE_SHOW_TIME.
	void SplashState::Update(float delta)
	{
		INSTRMENTATIONTIMER();

		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Swap from SplashState to MenuState.
			this->_data->machine.AddState(StateRef(new MenuState(_data)), true);
		}
	}

	// Draws splash screen.
	void SplashState::Draw(float delta)
	{
		INSTRMENTATIONTIMER();

		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		this->_data->window.display();
	}

}