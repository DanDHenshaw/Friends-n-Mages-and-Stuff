#include "MenuState.h"
#include <sstream>
#include <iostream>

#include "GameState.h"
#include "LeaderboardState.h"

namespace Insignia
{
	MenuState::MenuState(GameDataRef data) : _data(data)
	{
		INSTRMENTATIONTIMER();
	}

	void MenuState::Init()
	{
		INSTRMENTATIONTIMER();

		// Loads background texture.
		this->_data->assets.LoadTexture("Menu State Background", MAIN_MENU_SCENE_BACKGROUND_FILEPATH);
		// Loads play button texture.
		this->_data->assets.LoadTexture("Menu State Play Button", MAIN_MENU_SCENE_PLAY_BUTTON_FILEPATH);
		// Loads leaderboard button texture.
		this->_data->assets.LoadTexture("Menu State Leaderboard Button", MAIN_MENU_SCENE_LEADERBOARD_BUTTON_FILEPATH);
		// Loads exit button texture.
		this->_data->assets.LoadTexture("Menu State Exit Button", MAIN_MENU_SCENE_EXIT_BUTTON_FILEPATH);
		// Loads title texture.
		this->_data->assets.LoadTexture("Menu State Title", MAIN_MENU_SCENE_TITLE_FILEPATH);

		// Sets background texture.
		this->_background.setTexture(this->_data->assets.GetTexture("Menu State Background"));
		// Sets play button texture.
		this->_playButton.setTexture(this->_data->assets.GetTexture("Menu State Play Button"));
		// Sets leaderboard button texture.
		this->_leaderboardButton.setTexture(this->_data->assets.GetTexture("Menu State Leaderboard Button"));
		// Sets exit button texture.
		this->_exitButton.setTexture(this->_data->assets.GetTexture("Menu State Exit Button"));
		// Sets title texture.
		this->_title.setTexture(this->_data->assets.GetTexture("Menu State Title"));

		// Sets title position.
		this->_title.setPosition((this->_data->window.getSize().x / 2) - (this->_title.getLocalBounds().width / 2), this->_title.getPosition().y);
		// Sets play button position.
		this->_playButton.setPosition((this->_data->window.getSize().x / 2) - (this->_playButton.getLocalBounds().width / 2), this->_title.getGlobalBounds().height + this->_title.getPosition().y + 25);
		// Sets leaderboard button position.
		this->_leaderboardButton.setPosition((this->_data->window.getSize().x / 2) - (this->_leaderboardButton.getLocalBounds().width / 2), this->_playButton.getGlobalBounds().height + this->_playButton.getPosition().y + 25);
		// Sets exit button position.
		this->_exitButton.setPosition((this->_data->window.getSize().x / 2) - (this->_exitButton.getLocalBounds().width / 2), this->_leaderboardButton.getGlobalBounds().height + this->_leaderboardButton.getPosition().y + 25);
	}

	void MenuState::HandleInput()
	{
		INSTRMENTATIONTIMER();

		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if(sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_leaderboardButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new LeaderboardState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->window.close();
			}
		}
	}

	void MenuState::Update(float delta)
	{
		
	}

	void MenuState::Draw(float delta)
	{
		INSTRMENTATIONTIMER();

		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_leaderboardButton);
		this->_data->window.draw(this->_exitButton);
		this->_data->window.draw(this->_title);
		this->_data->window.display();
	}

}