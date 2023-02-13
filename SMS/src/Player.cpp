#include "Player.h"

namespace Insignia
{
	Player::Player(GameDataRef data, ObjectType type)
		: _data(data)
	{
		_type = type;
	}

	void Player::Init()
	{
		switch (_type)
		{
		case GameObject::PLAYER1:
			// Loads player1 texture.
			this->_data->assets.LoadTexture("Player1", PLAYER1_FILEPATH);

			// Sets player1 texture.
			_player.setTexture(this->_data->assets.GetTexture("Player1"));

			// Sets player1 scale.
			_player.setScale(PLAYER_SIZE, PLAYER_SIZE);

			// Sets player1 origin.
			_player.setOrigin(_player.getScale().x / 2, _player.getScale().y / 2);

			// Sets player1 position.
			_player.setPosition(100, _data->window.getSize().y / 4);

			// Sets wandOffset to Player1's offset.
			_wandOffset = PLAYER1_WAND_OFFSET;
			// The offset by default is full size and unscaled so need to be multiplied by the player scale.
			_wandOffset *= PLAYER_SIZE;
			// Wand position is the player position + offset.
			wandPos = sf::Vector2f(_player.getPosition().x + _wandOffset.x, _player.getPosition().y + _wandOffset.y);
			break;
		case GameObject::PLAYER2:
			// Loads player2 texture.
			this->_data->assets.LoadTexture("Player2", PLAYER2_FILEPATH);

			// Sets player2 texture.
			_player.setTexture(this->_data->assets.GetTexture("Player2"));

			// Sets player2 scale and flips the x.
			_player.setScale(PLAYER_SIZE * -1, PLAYER_SIZE);

			// Sets player2 origin.
			_player.setOrigin(_player.getScale().x / 2, _player.getScale().y / 2);

			// Sets player2 position.
			_player.setPosition(_data->window.getSize().x - 100, _data->window.getSize().y / 2);

			// Sets wandOffset to Player2's offset.
			_wandOffset = PLAYER2_WAND_OFFSET;
			// The offset by default is full size and unscaled so need to be multiplied by the player scale
			_wandOffset *= PLAYER_SIZE;
			// Wand position is the player position.x - offset.x & position.y + offset.y.
			wandPos = sf::Vector2f(_player.getPosition().x - _wandOffset.x, _player.getPosition().y + _wandOffset.y);
			break;
		default:
			break;
		}
	}

	void Player::HandleInput()
	{
		sf::Vector2f movement(0.0f, 0.0f);

		switch (_type)
		{
		case GameObject::PLAYER1:
			movement = this->_data->input.Movement(sf::Keyboard::Key::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, _moveSpeed, _isWalking);

			// Checks if player1 is in the middle of the screen and stops them crossing.
			if(_player.getPosition().x + _player.getGlobalBounds().width >= this->_data->window.getSize().x / 2)
			{
				// Moves the player slightly back.
					// without this the player will get stuck in the middle of the screen.
				movement.x -= this->_moveSpeed;
			}

			// Checks if player1 is trying to walk of the edge of the screen on the x-axis.
			if(_player.getPosition().x <= 0)
			{
				// Moves the player slightly forward.
				movement.x += this->_moveSpeed;
			}
			break;
		case GameObject::PLAYER2:
			movement = this->_data->input.Movement(sf::Keyboard::Key::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, _moveSpeed, _isWalking);

			// Checks if player2 is in the middle of the screen and stops them crossing.
			if (_player.getPosition().x - _player.getGlobalBounds().width <= this->_data->window.getSize().x / 2)
			{
				// Moves the player slightly back.
				movement.x += this->_moveSpeed;
			}

			// Checks if player2 is trying to walk of the edge of the screen on the x-axis.
			if (_player.getPosition().x >= this->_data->window.getSize().x)
			{
				// Moves the player slightly forward.
				movement.x -= this->_moveSpeed;
			}
			break;
		default:
			break;
		}

		// Checks if the players are trying to walk off the top of the screen.
		if(_player.getPosition().y <= 0) movement.y += this->_moveSpeed;

		// Checks if the players are trying to walk off the bottom of the screen.
		if (_player.getPosition().y + _player.getGlobalBounds().height >= this->_data->window.getSize().y) movement.y -= this->_moveSpeed;

		// Makes the player move.
		_player.move(movement);
	}

	void Player::Animations()
	{
		// Checks if the player is walking.
		if (this->_isWalking)
		{
			// Checks if the Anim frame time has passed.
			if (this->_clock.getElapsedTime().asSeconds() > PLAYER_WALK_ANIM_TIME)
			{
				// Checks if the animation is on the last frame.
				if (this->_walkingPos >= PLAYER1_WALK.size() - 1)
				{
					// Sets the frame to 0.
					this->_walkingPos = 0;
				}

				// Increases the frame.
				this->_walkingPos++;

				// Restarts the clock.
				this->_clock.restart();
			}
		}
		// Checks if the player isn't walking.
		else
		{
			// Checks if the Anim frame time has passed.
			if (this->_clock.getElapsedTime().asSeconds() > PLAYER_IDLE_ANIM_TIME)
			{
				// Checks if the animation is on the last frame.
				if (this->_idlePos >= PLAYER1_IDLE.size() - 1)
				{
					// Sets the frame to 0.
					this->_idlePos = 0;
				}

				// Increases the frame.
				this->_idlePos++;

				// Restarts the clock.
				this->_clock.restart();
			}
		}

		// If the player is walking
		if (_isWalking)
		{
			switch (_type)
			{
			// Checks if its player1
			case GameObject::PLAYER1:
				// Animates the player
				_player.setTextureRect(PLAYER1_WALK[this->_walkingPos]);
				break;
			// Checks if its player2
			case GameObject::PLAYER2:
				// Animates the player
				_player.setTextureRect(PLAYER2_WALK[this->_walkingPos]);
				break;
			default:
				break;
			}
		}
		// If the player isn't walking
		else
		{
			switch (_type)
			{
			// Checks if its player1
			case GameObject::PLAYER1:
				// Animates the player
				_player.setTextureRect(PLAYER1_IDLE[this->_idlePos]);
				break;
			// Checks if its player2
			case GameObject::PLAYER2:
				// Animates the player
				_player.setTextureRect(PLAYER2_IDLE[this->_idlePos]);
				break;
			default:
				break;
			}
		}
	}

	void Player::Update(float delta)
	{
		// Calls the animation function
		this->Animations();

		// Wand Positioning
		switch (_type)
		{
		// Checks if player1
		case GameObject::PLAYER1:
			// Wand position is the player position + offset.
			wandPos = sf::Vector2f(_player.getPosition().x + _wandOffset.x, _player.getPosition().y + _wandOffset.y);
			break;
		// Checks if player2
		case GameObject::PLAYER2:
			// Wand position is the player position.x - offset.x & position.y + offset.y.
			wandPos = sf::Vector2f(_player.getPosition().x - _wandOffset.x, _player.getPosition().y + _wandOffset.y);
			break;
		default:
			break;
		}
	}

	void Player::Draw(float delta)
	{
		// Draws the player.
		this->_data->window.draw(this->_player);
	}
}
