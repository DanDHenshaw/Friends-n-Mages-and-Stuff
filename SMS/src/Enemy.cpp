#include "Enemy.h"

#include "SAT.h"

namespace Insignia
{
	Enemy::Enemy(GameDataRef data, ObjectType type)
		: _data(data)
	{
		INSTRMENTATIONTIMER();

		_type = type;
	}

	sf::Vector2f calculateSpawn(int w, int h, sf::FloatRect rect)
	{
		sf::Vector2f pos;

		int dir = rand() & 1;

		// down on x
		if(dir == 1)
		{
			pos.x = rand() % (w + 1);

			dir = rand() & 1;
			if(dir == 1)
			{
				pos.y = h + rect.height;
			}
			else
			{
				pos.y = 0 - rect.height;
			}
		}
		// across on y
		else
		{
			pos.y = rand() % (h + 1);

			dir = rand() & 1;
			if (dir == 1)
			{
				pos.x = w + rect.width;
			}
			else
			{
				pos.x = 0 - rect.height;
			}
		}

		return pos;
	}

	void Enemy::Init()
	{
		// Loads enemy texture.
		this->_data->assets.LoadTexture("Enemy", ENEMY_FILEPATH);

		// Sets enemy texture.
		const sf::Texture* tex = &this->_data->assets.GetTexture("Enemy");
		_enemy.setTexture(tex);

		// Sets enemy scale.
		//_enemy.setSize(215, 268);
		_enemy.setSize(sf::Vector2f(215 / 2, 268 / 2));

		// Sets enemy origin.
		_enemy.setOrigin(_enemy.getLocalBounds().width / 2, _enemy.getLocalBounds().height / 2);

		sf::Vector2f distance(SCREEN_WIDTH, SCREEN_HEIGHT);

		// Sets enemy position.
		_enemy.setPosition(calculateSpawn(SCREEN_WIDTH, SCREEN_HEIGHT, _enemy.getLocalBounds()));
	}

	void Enemy::HandleInput()
	{

	}

	void Enemy::Animations()
	{
		// Checks if the Anim frame time has passed.
		if (this->_clock.getElapsedTime().asSeconds() > ENEMY_WALK_ANIM_TIME)
		{
			// Checks if the animation is on the last frame.
			if (this->_walkingPos >= ENEMY_WALK.size() - 1)
			{
				// Sets the frame to 0.
				this->_walkingPos = 0;
			}

			// Increases the frame.
			this->_walkingPos++;

			// Restarts the clock.
			this->_clock.restart();
		}

		_enemy.setTextureRect(ENEMY_WALK[this->_walkingPos]);

		if(isFlipped)
		{
			_enemy.setScale(-1, 1);
		} else
		{
			_enemy.setScale(1, 1);
		}
	}

	sf::Vector2f Movement(sf::RectangleShape castleShape, sf::RectangleShape enemy, float delta)
	{
		sf::Vector2f move;

		move.x = (castleShape.getPosition().x - enemy.getPosition().x) * (MOVEMENT_SPEED * delta) * 0.25f;
		move.y = (castleShape.getPosition().y - enemy.getPosition().y) * (MOVEMENT_SPEED * delta) * 0.25f;

		return move;
	}

	void Enemy::Update(float delta)
	{
		sf::Vector2f move = Movement(castleShape, _enemy, delta);

		if(move.x > 0)
		{
			isFlipped = false;
		} else
		{
			isFlipped = true;
		}

		_enemy.move(move);
		Animations();

		SAT sat;
		if (sat.collisionSAT(_enemy, killbeamShape))
		{
			isDead = true;
		}

		if (sat.collisionSAT(_enemy, castleShape))
		{
			castleAttacked = true;
		}
	}

	void Enemy::Draw(float delta)
	{
		// Draws the enemy.
		this->_data->window.draw(this->_enemy);
	}
}
