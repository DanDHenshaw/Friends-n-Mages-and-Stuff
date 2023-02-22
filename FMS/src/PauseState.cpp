#include "PauseState.h"
#include <sstream>
#include <iostream>

#include "GameState.h"
#include "MenuState.h"

namespace Insignia
{
	PauseState::PauseState(GameDataRef data) : _data(data)
	{
		INSTRMENTATIONTIMER();
	}

	void PauseState::Init()
	{
		INSTRMENTATIONTIMER();

		// Loads background texture.
		this->_data->assets.LoadTexture("Pause State Background", PAUSE_SCENE_BACKGROUND_FILEPATH);
		// Loads play button texture.
		this->_data->assets.LoadTexture("Pause State Resume Button", PAUSE_SCENE_RESUME_BUTTON_FILEPATH);
		// Loads menu button texture.
		this->_data->assets.LoadTexture("Pause State Menu Button", PAUSE_SCENE_MENU_BUTTON_FILEPATH);
		// Loads exit button texture.
		this->_data->assets.LoadTexture("Pause State Exit Button", PAUSE_SCENE_EXIT_BUTTON_FILEPATH);

		// Sets background texture.
		this->_background.setTexture(this->_data->assets.GetTexture("Pause State Background"));
		// Sets play button texture.
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Pause State Resume Button"));
		// Sets menu button texture.
		this->_menuButton.setTexture(this->_data->assets.GetTexture("Pause State Menu Button"));
		// Sets exit button texture.
		this->_exitButton.setTexture(this->_data->assets.GetTexture("Pause State Exit Button"));

		this->_resumeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 4 * 1) - (this->_resumeButton.getLocalBounds().height / 2));

		this->_menuButton.setPosition((this->_data->window.getSize().x / 2) - (this->_menuButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 4 * 2) - (this->_menuButton.getLocalBounds().height / 2));

		this->_exitButton.setPosition((this->_data->window.getSize().x / 2) - (this->_exitButton.getLocalBounds().width / 2), (this->_data->window.getSize().y / 4 * 3) - (this->_exitButton.getLocalBounds().height / 2));
	}

	void PauseState::HandleInput()
	{
		INSTRMENTATIONTIMER();

		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.RemoveState();
			}

			if (this->_data->input.IsSpriteClicked(this->_menuButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.RemoveState();

				this->_data->machine.AddState(StateRef(new MenuState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->window.close();
			}
		}
	}

	void PauseState::Update(float delta)
	{

	}

	void PauseState::Draw(float delta)
	{
		INSTRMENTATIONTIMER();

		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_resumeButton);
		this->_data->window.draw(this->_menuButton);
		this->_data->window.draw(this->_exitButton);
		this->_data->window.display();
	}

}
