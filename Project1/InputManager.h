#pragma once

#include <SFML/Graphics.hpp>

namespace Insignia
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		/*
		Detects mouse click on a sprite object.
			- object is the object the user has pressed.
			- button is the mouse button the user needs to click.
			- window is the RenderWindow the user needs to click on.
		 */
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

		/*
		 Returns the users mouse position.
			- window is the RenderWindow to get the mouse position from.
		 */
		sf::Vector2i GetMousePosition(sf::RenderWindow& window);

		/*
		 Returns the users movement value
			- UP, DOWN, LEFT, RIGHT : is the Keyboard key to press to go in a certain direction.
			- moveSpeed is used for the players movement speed.
			- isWalking is the bool for if the player walking.
		*/
		sf::Vector2f Movement(sf::Keyboard::Key Up, sf::Keyboard::Key Down, sf::Keyboard::Key Left, sf::Keyboard::Key Right, float moveSpeed, bool& isWalking);
	};
}
