#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

namespace Insignia
{
	// Inherits the State class from 'State.h'
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init() override;

		void HandleInput() override;
		void Update(float delta) override;
		void Draw(float delta) override;

	private:
		// Reference to GameData.
		GameDataRef _data;

		// Clock for the Splash Screen.
		sf::Clock _clock;

		// Splash screen background image.
		sf::Sprite _background;
	};
}