#include "Game.h"
#include "SplashState.h"

namespace Insignia
{
	Game::Game(int width, int height, std::string title)
	{
		INSTRMENTATIONTIMER();

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

		// Sets window icon
		sf::Image icon;
		icon.loadFromFile(GAMEICON_FILEPATH);
		_data->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

		_data->machine.AddState(StateRef(new SplashState(this->_data)));

		this->Run();
	}

	void Game::Run()
	{
		INSTRMENTATIONTIMER();

		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f) { frameTime = 0.25f; }

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}

}