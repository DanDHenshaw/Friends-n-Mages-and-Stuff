#include "LeaderboardState.h"

#include <iostream>

#include "MenuState.h"

namespace Insignia
{
	LeaderboardState::LeaderboardState(GameDataRef data)
		: _data(data)
	{
		
	}

	void LeaderboardState::Init()
	{
		// Loads background texture.
		this->_data->assets.LoadTexture("Leaderboard State Background", LEADERBOARD_BACKGROUND_FILEPATH);

		// Sets background texture.
		this->_background.setTexture(this->_data->assets.GetTexture("Leaderboard State Background"));

		this->_data->assets.LoadTexture("Leaderboard Panel", LEADERBOARD_PANEL_FILEPATH);

		const sf::Texture* tex = &this->_data->assets.GetTexture("Leaderboard Panel");
		_leaderboardBackground.setTexture(tex);

		_leaderboardBackground.setSize(LEADERBOARD_PANEL_SIZE);

		_leaderboardBackground.setPosition((this->_data->window.getSize().x / 2) - (_leaderboardBackground.getGlobalBounds().width / 2), (this->_data->window.getSize().y / 2) - (_leaderboardBackground.getGlobalBounds().height / 2) - 50);

		LeaderboardItem item;
		this->_data->assets.LoadTexture("Item Background", LEADERBOARD_ITEM_FILEPATH);
		const sf::Texture* texItemBack = &this->_data->assets.GetTexture("Item Background");
		item.background.setTexture(texItemBack);
		item.background.setSize(LEADERBOARD_ITEM_SIZE);

		item.position.setFont(this->_data->assets.GetFont("FONT"));
		item.position.setColor(LEADERBOARD_ITEM_TEXT_COLOR);
		item.position.setCharacterSize(25);

		item.name.setFont(this->_data->assets.GetFont("FONT"));
		item.name.setColor(LEADERBOARD_ITEM_TEXT_COLOR);
		item.name.setCharacterSize(25);

		item.score.setFont(this->_data->assets.GetFont("FONT"));
		item.score.setColor(LEADERBOARD_ITEM_TEXT_COLOR);
		item.score.setCharacterSize(25);

		for(size_t i = 0; i < 8; i++)
		{
			item.background.setPosition((this->_data->window.getSize().x / 2) - (item.background.getGlobalBounds().width / 2), (65 * i) + 85);

			item.position.setString("");
			item.position.setPosition(item.background.getPosition().x + 5, item.background.getPosition().y + 10);

			item.name.setString("");
			item.name.setPosition(item.position.getPosition().x + 100, item.position.getPosition().y);

			item.score.setString("");
			item.score.setPosition(item.name.getPosition().x + 250, item.name.getPosition().y);

			items.push_back(item);
		}

		this->_data->leaderboard.GetResults();
		for(size_t i = 0; i < this->_data->leaderboard._results.size(); i++)
		{
			if(i < items.size())
			{
				items[i].position.setString(std::to_string(i + 1));
				items[i].name.setString(this->_data->leaderboard._results[i].name);
				std::string score = this->_data->leaderboard._results[i].score + " seconds";
				items[i].score.setString(score);
			}
		}

		// Loads play button texture.
		this->_data->assets.LoadTexture("Leaderboard State Menu Button", LEADERBOARD_MENU_BUTTON);
		// Loads menu button texture.
		this->_data->assets.LoadTexture("Leaderboard State Exit Button", LEADERBOARD_EXIT_BUTTON);

		// Sets play button texture.
		this->_menuButton.setTexture(this->_data->assets.GetTexture("Leaderboard State Menu Button"));
		// Sets menu button texture.
		this->_exitButton.setTexture(this->_data->assets.GetTexture("Leaderboard State Exit Button"));

		this->_menuButton.setPosition(_leaderboardBackground.getPosition().x, this->_data->window.getSize().y - _menuButton.getGlobalBounds().height - 20);
		this->_exitButton.setPosition(_leaderboardBackground.getLocalBounds().width - _exitButton.getGlobalBounds().width + 60, this->_data->window.getSize().y - _exitButton.getGlobalBounds().height - 20);
	}

	void LeaderboardState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_menuButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(StateRef(new MenuState(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->window.close();
			}
		}
	}

	void LeaderboardState::Update(float delta)
	{

	}

	void LeaderboardState::Draw(float delta)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(_background);
		this->_data->window.draw(_leaderboardBackground);

		this->_data->window.draw(_menuButton);
		this->_data->window.draw(_exitButton);

		for(size_t i = 0; i < items.size(); i++)
		{
			this->_data->window.draw(items[i].background);
			this->_data->window.draw(items[i].position);
			this->_data->window.draw(items[i].name);
			this->_data->window.draw(items[i].score);
		}

		this->_data->window.display();
	}
};