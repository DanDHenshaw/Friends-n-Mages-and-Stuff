#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace Insignia
{
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		/*
		Loads a texture into a map.
			- name is used as a key for loading the texture again.
			- fileName is the path of the texture file.
		 */
		void LoadTexture(std::string name, std::string fileName);
		/*
		Returns a texture from a map.
			- name is the key in which the texture is saved in the map.
		 */
		sf::Texture& GetTexture(std::string name);

		/*
		Loads a font into a map.
			- name is used as a key for loading the font again.
			- fileName is the path of the font file.
		 */
		void LoadFont(std::string name, std::string fileName);
		/*
		Returns a font from a map.
			- name is the key in which the font is saved in the map.
		 */
		sf::Font& GetFont(std::string name);

	private:
		// Map of all loaded textures.
		std::map<std::string, sf::Texture> _textures;
		// Map of all loaded fonts.
		std::map<std::string, sf::Font> _fonts;
	};
}