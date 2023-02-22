#pragma once
#include "Game.h"

#include "SFML/Graphics.hpp"

namespace Insignia
{
	class Textbox
	{
	public:
		Textbox(GameDataRef);

		void Init();

		void HandleInput(int charTyped);
		void Update(float delta);
		void Draw(float delta);

		int score;

	private:
		// Reference to GameData.
		GameDataRef _data;

		sf::RectangleShape background;
		sf::Text textbox;
		std::string text;

		const int ENTER_KEY = 13;
		const int DELETE_KEY = 8;

		void DeleteLastChar();
	};
};