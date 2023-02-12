#pragma once

#include <SFML/Graphics.hpp>

namespace Insignia
{
	class GameObject
	{
	public:
		// Type
		enum ObjectType { PLAYER1, PLAYER2, KILLBEAM, ENEMY };
		ObjectType _type;

		sf::Vector2f wandPos;
		sf::Vector2f extraWandPos;

		/*
		Initialises the state.
		*/
		virtual void Init() = 0;

		/*
		Handles the user input while in this state.
		*/
		virtual void HandleInput() = 0;
		/*
		Updates the state every frame.
			- delta is the DeltaTime
		*/
		virtual void Update(float delta) = 0;
		/*
		 Draws the state every frame.
			- delta is the DeltaTime
		 */
		virtual void Draw(float delta) = 0;
	};
}
