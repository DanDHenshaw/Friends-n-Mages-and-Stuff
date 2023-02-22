#include "AssetManager.h"
#include "DEFINITIONS.h"

namespace Insignia
{
	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		INSTRMENTATIONTIMER();

		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name)
	{
		INSTRMENTATIONTIMER();

		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		INSTRMENTATIONTIMER();

		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetManager::GetFont(std::string name)
	{
		INSTRMENTATIONTIMER();

		return this->_fonts.at(name);
	}
}
