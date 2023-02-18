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

		std::cout << "x:" << _enemy.getPosition().x << " y:" << _enemy.getPosition().y << std::endl;
	}

	void Enemy::HandleInput()
	{

	}

	void Enemy::Animations()
	{

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
		_enemy.move(Movement(castleShape, _enemy, delta));

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
