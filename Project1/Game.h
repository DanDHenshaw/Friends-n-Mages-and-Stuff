#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "DEFINITIONS.h"

namespace Insignia
{
	/*
	 Reference to all the games data.
		- machine is a reference to the StateMachine.
		- window is a reference to the RenderWindow.
		- assets is a reference to the AssetManager.
		- input is a reference to the InputManager.
	 */
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		/*
		 Game constructor.
			- width is the width of the screen.
			- height is the height of the screen.
			- title is the title of the screen.
		 */
		Game(int width, int height, std::string title);

	private:
		// DeltaTime - 60FPS.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		// Reference to GameData.
		GameDataRef _data = std::make_shared<GameData>();

		// Runs the game.
		void Run();
	};
}
