#include "InputManager.h"

namespace Insignia
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}

		return false;
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}

	sf::Vector2f InputManager::Movement(sf::Keyboard::Key Up, sf::Keyboard::Key Down, sf::Keyboard::Key Left, sf::Keyboard::Key Right, float moveSpeed, bool& isWalking)
	{
		sf::Vector2f move(0.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(Up))
		{
			move.y += moveSpeed * -1.0f;
		}

		if (sf::Keyboard::isKeyPressed(Down))
		{
			move.y += moveSpeed;
		}

		if (sf::Keyboard::isKeyPressed(Left))
		{
			move.x += moveSpeed * -1.0f;
		}

		if (sf::Keyboard::isKeyPressed(Right))
		{
			move.x += moveSpeed;
		}

		if (move.x == 0.0f && move.y == 0.0f)
		{
			isWalking = false;
		}
		else
		{
			isWalking = true;
		}

		return move;
	}
}