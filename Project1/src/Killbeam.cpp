#include "Killbeam.h"

#include <iostream>
#include <math.h>

namespace Insignia
{
	Killbeam::Killbeam(GameDataRef data, ObjectType type) : _data(data)
	{
		_type = type;
	}

	void Killbeam::Init()
	{
		this->_data->assets.LoadTexture("Killbeam", KILLBEAM_FILEPATH);
		const Texture* tex = &this->_data->assets.GetTexture("Killbeam");
		_killbeam.setTexture(tex);
		_killbeam.setTextureRect(KILLBEAM_ANIM[0]);

		_killbeam.setOrigin(_killbeam.getOrigin().x, KILLBEAM_SIZE / 2);

		_killbeam.setFillColor(Color::White);
	}

	void Killbeam::HandleInput()
	{
		
	}

	void Killbeam::Update(float delta)
	{
		// Calculates x & y of player
			// forming a right angle triangle
		float x = extraWandPos.x - wandPos.x;
		float y = extraWandPos.y - wandPos.y;

		// Pythagoras' Theorem
			// h - hypotenuse (length of long side of right angle triangle)
		float h = pow(x, 2) + pow(y, 2);
		h = sqrt(h);
		
		// Trigonometry
			// Gets the angle in rad
		float angle = y / h;
		angle = asin(angle);
			// Converts rad to deg
		angle *= (180.0 / 3.141592653589793238463);
		
		_killbeam.setPosition(wandPos.x, wandPos.y);
		_killbeam.setSize(Vector2f(h, KILLBEAM_SIZE));

		_killbeam.setOrigin(_killbeam.getOrigin().x, _killbeam.getSize().y / 2);

		_killbeam.setRotation(angle);

		if (this->_clock.getElapsedTime().asSeconds() > KILLBEAM_ANIM_TIME)
		{
			// Checks if the animation is on the last frame.
			if (this->_animPos >= KILLBEAM_ANIM.size() - 1)
			{
				// Sets the frame to 0.
				this->_animPos = 0;
			}

			// Increases the frame.
			this->_animPos++;

			// Restarts the clock.
			this->_clock.restart();
		}

		// Sets the animation frame.
		_killbeam.setTextureRect(KILLBEAM_ANIM[_animPos]);
	}

	void Killbeam::Draw(float delta)
	{
		this->_data->window.draw(_killbeam);
	}
}
