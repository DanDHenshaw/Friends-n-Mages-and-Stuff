#include "Player.h"

namespace Insignia
{
	Player::Player(GameDataRef data, ObjectType type) : _data(data)
	{
		_type = type;
	}

	void Player::Init()
	{
		switch (_type)
		{
		case GameObject::PLAYER1:
			this->_data->assets.LoadTexture("Player1", PLAYER1_FILEPATH);

			_player.setTexture(this->_data->assets.GetTexture("Player1"));

			_player.setScale(PLAYER_SIZE, PLAYER_SIZE);

			_player.setOrigin(_player.getScale().x / 2, _player.getScale().y / 2);

			_player.setPosition(100, SCREEN_HEIGHT / 4);
			break;
		case GameObject::PLAYER2:
			this->_data->assets.LoadTexture("Player2", PLAYER2_FILEPATH);

			_player.setTexture(this->_data->assets.GetTexture("Player2"));

			_player.setScale(PLAYER_SIZE, PLAYER_SIZE);

			_player.setOrigin(_player.getScale().x / 2, _player.getScale().y / 2);
		
			_player.setScale(_player.getScale().x * -1, _player.getScale().y);

			_player.setPosition(SCREEN_WIDTH - 100, SCREEN_HEIGHT / 4);
			break;
		default:
			break;
		}
	}

	void Player::HandleInput()
	{
		switch (_type)
		{
		case GameObject::PLAYER1:
			_player.move(this->_data->input.Movement(Keyboard::Key::W, Keyboard::S, Keyboard::A, Keyboard::D, _moveSpeed, isWalking));
			break;
		case GameObject::PLAYER2:
			_player.move(this->_data->input.Movement(Keyboard::Key::Up, Keyboard::Down, Keyboard::Left, Keyboard::Right, _moveSpeed, isWalking));
			break;
		default:
			break;
		}
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
			switch (_type)
			{
			case GameObject::PLAYER1:
				_player.setTextureRect(PLAYER1_WALK[this->walkingPos]);
				break;
			case GameObject::PLAYER2:
				_player.setTextureRect(PLAYER2_WALK[this->walkingPos]);
				break;
			default:
				break;
			}
		}
		else
		{
			switch (_type)
			{
			case GameObject::PLAYER1:
				_player.setTextureRect(PLAYER1_IDLE[this->idlePos]);
				break;
			case GameObject::PLAYER2:
				_player.setTextureRect(PLAYER2_IDLE[this->idlePos]);
				break;
			default:
				break;
			}
		}
	}

	void Player::Draw(float delta)
	{
		this->_data->window.draw(this->_player);
	}
}
