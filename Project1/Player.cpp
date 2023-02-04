#include "Player.h"

namespace Insignia
{
	Player::Player(GameDataRef data) : _data(data)
	{

	}

	void Player::Init()
	{
		type = PLAYER;

		// Loads player1 texture.
		this->_data->assets.LoadTexture("Player1", PLAYER1_FILEPATH);
		// Loads player2 texture.
		this->_data->assets.LoadTexture("Player2", PLAYER2_FILEPATH);

		// Sets player1 texture.
		_player1.setTexture(this->_data->assets.GetTexture("Player1"));
		// Sets player2 texture.
		_player2.setTexture(this->_data->assets.GetTexture("Player2"));
	}

	void Player::HandleInput()
	{
		
	}

	void Player::Update(float delta)
	{
		if (this->_clock.getElapsedTime().asSeconds() > ANIM_FPS)
		{
			if (this->idlePos >= PLAYER1_IDLE.size() - 1)
			{
				this->idlePos = 0;
			}

			this->idlePos++;

			this->_clock.restart();
		}

		_player1.setTextureRect(PLAYER1_IDLE[this->idlePos]);
		_player2.setTextureRect(PLAYER2_IDLE[this->idlePos]);
	}

	void Player::Draw(float delta)
	{
		this->_data->window.draw(this->_player1);
		this->_data->window.draw(this->_player2);
	}
}
