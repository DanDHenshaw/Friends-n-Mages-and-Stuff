#include "Enemy.h"

#include <iostream>

namespace Insignia
{
	Enemy::Enemy(GameDataRef data, ObjectType type)
		: _data(data)
	{
		INSTRMENTATIONTIMER();

		_type = type;
	}

	void Enemy::Init()
	{
		// Loads enemy texture.
		this->_data->assets.LoadTexture("Enemy", ENEMY_FILEPATH);

		// Sets enemy texture.
		_enemy.setTexture(this->_data->assets.GetTexture("Enemy"));

		// Sets enemy scale.
		_enemy.setScale(ENEMY_SIZE, ENEMY_SIZE);

		// Sets enemy origin.
		_enemy.setOrigin(_enemy.getLocalBounds().width / 2, _enemy.getLocalBounds().height / 2);

		int rangex = SCREEN_WIDTH - 0 + 1;
		int rangey = SCREEN_HEIGHT - 0 + 1;

		// Sets enemy position.
		_enemy.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	}

	void Enemy::HandleInput()
	{

	}

	void Enemy::Animations()
	{

	}


	void Enemy::Update(float delta)
	{

	}

	void Enemy::Draw(float delta)
	{
		// Draws the enemy.
		this->_data->window.draw(this->_enemy);
	}
}
