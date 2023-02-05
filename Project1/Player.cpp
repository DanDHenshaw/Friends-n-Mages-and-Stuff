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

		// Sets player1 origin to centre.
		_player1.setOrigin(_player1.getScale().x / 2, _player1.getScale().y / 2);
		// Sets player2 origin to centre.
		_player2.setOrigin(_player2.getScale().x / 2, _player2.getScale().y / 2);


		// Positions player1 into the centre of the screen.
		_player1.setPosition(100, SCREEN_HEIGHT / 4);
		// Positions player2 into the centre of the screen.
		_player2.setPosition(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 4);

		// Flips player2 to face to opposite direction.
		_player2.setScale(_player2.getScale().x * -1, _player2.getScale().y);
	}

	void Player::HandleInput()
	{
		_player1.move(Movement(Keyboard::Key::W, Keyboard::S, Keyboard::A, Keyboard::D));
		_player2.move(Movement(Keyboard::Up, Keyboard::Down, Keyboard::Left, Keyboard::Right));
	}

	void Player::Update(float delta)
	{
		if(this->isWalking)
		{
			if(this->_clock.getElapsedTime().asSeconds() > PLAYER_WALK_ANIM_TIME)
			{
				if (this->walkingPos >= PLAYER1_WALK.size() - 1)
				{
					this->walkingPos = 0;
				}

				this->walkingPos++;

				this->_clock.restart();
			}
		}
		else
		{
			if (this->_clock.getElapsedTime().asSeconds() > PLAYER_IDLE_ANIM_TIME)
			{
				if (this->idlePos >= PLAYER1_IDLE.size() - 1)
				{
					this->idlePos = 0;
				}

				this->idlePos++;

				this->_clock.restart();
			}
		}

		if (isWalking)
		{
			_player1.setTextureRect(PLAYER1_WALK[this->walkingPos]);
			_player2.setTextureRect(PLAYER2_WALK[this->walkingPos]);
		}
		else
		{
			_player1.setTextureRect(PLAYER1_IDLE[this->idlePos]);
			_player2.setTextureRect(PLAYER2_IDLE[this->idlePos]);
		}
	}

	void Player::Draw(float delta)
	{
		this->_data->window.draw(this->_player1);
		this->_data->window.draw(this->_player2);
	}

	Vector2f Player::Movement(Keyboard::Key Up, Keyboard::Key Down, Keyboard::Key Left, Keyboard::Key Right)
	{
		Vector2f move(0.0f, 0.0f);

		if(Keyboard::isKeyPressed(Up))
		{
			move.y = this->_moveSpeed * -1.0f;
		}

		if (Keyboard::isKeyPressed(Down))
		{
			move.y = this->_moveSpeed;
		}

		if (Keyboard::isKeyPressed(Left))
		{
			move.x = this->_moveSpeed * -1.0f;
		}

		if (Keyboard::isKeyPressed(Right))
		{
			move.x = this->_moveSpeed;
		}
		
		return move;
	}

}
