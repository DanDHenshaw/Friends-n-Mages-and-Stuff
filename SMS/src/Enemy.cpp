#include "Enemy.h"

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
