#include "Castle.h"

namespace Insignia
{
	Castle::Castle(GameDataRef data, ObjectType type)
		: _data(data)
	{
		INSTRMENTATIONTIMER();
		_type = type;
	}

	void Castle::Init()
	{
		// Loads castle texture.
		this->_data->assets.LoadTexture("Castle", CASTLE_FILEPATH);

		// Sets castle texture.
		const sf::Texture* tex = &this->_data->assets.GetTexture("Castle");
		_castle.setTexture(tex);

		_castle.setSize(CASTLE_SIZE);

		// Sets castle origin.
		_castle.setOrigin(_castle.getLocalBounds().width / 2, _castle.getLocalBounds().height / 2);

		// Sets position to centre of screen.
		_castle.setPosition(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / 2);
	}

	void Castle::HandleInput()
	{

	}

	void Castle::Update(float delta)
	{
		castleShape = _castle;
	}

	void Castle::Draw(float delta)
	{
		this->_data->window.draw(_castle);
	}
}
