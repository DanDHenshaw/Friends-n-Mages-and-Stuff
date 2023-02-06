#include "MenuState.h"
#include <sstream>
#include <iostream>

#include "GameState.h"

namespace Insignia
{
	MenuState::MenuState(GameDataRef data) : _data(data)
	{

	}

	void MenuState::Init()
	{
		/* UNCOMMENT WHEN ART IS ADDED
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
			_background.setTexture(this->_data->assets.GetTexture("Menu State Background"));
			// Sets play button texture.
			_playButton.setTexture(this->_data->assets.GetTexture("Menu State Play Button"));
			// Sets leaderboard button texture.
			_leaderboardButton.setTexture(this->_data->assets.GetTexture("Menu State Leaderboard Button"));
			// Sets exit button texture.
			_exitButton.setTexture(this->_data->assets.GetTexture("Menu State Exit Button"));
			// Sets title texture.
			_title.setTexture(this->_data->assets.GetTexture("Menu State Title"));
		*/
	}

	void MenuState::HandleInput()
	{
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
				//this->_data->machine.AddState(StateRef(new LeaderboardState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->window.close();
			}
		}
	}

	void MenuState::Update(float delta)
	{
		// Testing
		this->_data->machine.AddState(StateRef(new GameState(_data)), true);
	}

	void MenuState::Draw(float delta)
	{
		this->_data->window.clear(sf::Color::Red);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_leaderboardButton);
		this->_data->window.draw(this->_exitButton);
		this->_data->window.draw(this->_title);
		this->_data->window.display();
	}

}