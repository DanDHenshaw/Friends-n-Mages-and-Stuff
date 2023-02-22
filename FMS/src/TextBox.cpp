#include "TextBox.h"

#include "LeaderboardState.h"

namespace Insignia
{
	Textbox::Textbox(GameDataRef data)
		: _data(data)
	{
		
	}

	void Textbox::Init()
	{
		this->_data->assets.LoadTexture("NAME BACKGROUND", NAME_BACKGROUND);
		const sf::Texture* tex = &this->_data->assets.GetTexture("NAME BACKGROUND");
		background.setTexture(tex);
		background.setSize(NAME_BACKGROUND_SIZE);
		background.setPosition((this->_data->window.getSize().x / 2) - (background.getGlobalBounds().width / 2), (this->_data->window.getSize().y / 2) - (background.getGlobalBounds().height / 2));

		textbox.setFont(this->_data->assets.GetFont("FONT"));
		textbox.setCharacterSize(SCORE_TEXT_SIZE);
		textbox.setColor(TEXT_COLOR);
		textbox.setPosition(background.getPosition().x + 10, background.getPosition().y + 80);
	}

	void Textbox::HandleInput(int charTyped)
	{
		if (charTyped < 128)
		{
			if(isdigit(charTyped) || isalpha(charTyped) || charTyped == DELETE_KEY || charTyped == ENTER_KEY)
			{
				if (charTyped != ENTER_KEY && charTyped != DELETE_KEY)
				{
					text += static_cast<char>(charTyped);
					text.length() - 1;
				}
				else if (charTyped == DELETE_KEY)
				{
					if (text.length() > 0)
					{
						DeleteLastChar();
					}
				}
				else if (charTyped == ENTER_KEY)
				{
					this->_data->name = text;

					this->_data->leaderboard.SaveScore(this->_data->name, score);

					// change to leaderboard
					this->_data->machine.AddState(StateRef(new LeaderboardState(_data)), true);
				}

				textbox.setString(text);
				textbox.setPosition(background.getPosition().x + 10, background.getPosition().y + 80);
			}
		}
	}

	void Textbox::Draw(float delta)
	{
		this->_data->window.draw(background);
		this->_data->window.draw(textbox);
	}

	void Textbox::DeleteLastChar()
	{
		std::string t = text;
		std::string newT = "";

		for(int i=0; i < t.length() - 1; i++)
		{
			newT += t[i];
		}

		text = newT;

		textbox.setString(text);
	} 

};