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
		//this->_data->assets.LoadTexture("Killbeam", KILLBEAM_FILEPATH);
		//_killBeam.setTexture(this->_data->assets.GetTexture("Killbeam"));

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
		_killbeam.setSize(Vector2f(h, 5));
		_killbeam.setRotation(angle);
	}

	void Killbeam::Draw(float delta)
	{
		this->_data->window.draw(_killbeam);
	}
}
