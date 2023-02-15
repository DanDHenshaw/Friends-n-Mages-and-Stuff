#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "..\..\profiler-v0.1.2-x86\include\Profiler.h"

#pragma region PROFILER
	#define PROFILER false

	#if PROFILER
		#define BEGINSESSION(name) Profiler::BeginSession(name)
		#define INSTRMENTATIONTIMER() Profiler::InstrumentationTimer timer(__FUNCSIG__)
		#define ENDSESSION() Profiler::EndSession();
	#else
		#define BEGINSESSION(name)
		#define INSTRMENTATIONTIMER()
		#define ENDSESSION()
	#endif
#pragma endregion


#pragma region RENDER WINDOW
// Game title.
#define TITLE "Friends 'n Mages and Stuff"
// Game width.
#define SCREEN_WIDTH 1280
// Game height
#define SCREEN_HEIGHT 720
#pragma endregion

#pragma region SPLASH SCREEN
// Splash screen play length.
#define SPLASH_STATE_SHOW_TIME 3
// Splash screen background filepath.
#define SPLASH_SCENE_BACKGROUND_FILEPATH "res/splash/background.jpg"
#pragma endregion

#pragma region MENU SCREEN
// Menu screen background filepath.
#define MAIN_MENU_SCENE_BACKGROUND_FILEPATH "res/menu/background.jpg"
// Menu screen play button filepath.
#define MAIN_MENU_SCENE_PLAY_BUTTON_FILEPATH "res/menu/playButton.png"
// Menu screen leaderboard button filepath.
#define MAIN_MENU_SCENE_LEADERBOARD_BUTTON_FILEPATH "res/menu/leaderboardButton.png"
// Menu screen exit button filepath.
#define MAIN_MENU_SCENE_EXIT_BUTTON_FILEPATH "res/menu/exitButton.png"
// Menu screen title filepath.
#define MAIN_MENU_SCENE_TITLE_FILEPATH "res/menu/title.png"
#pragma endregion

#pragma region GAME
#pragma region PLAYERS
// Mage 1 sprite filepath
#define PLAYER1_FILEPATH "res/game/players/Mage1.png"
// Mage 1 Idle Anim
const std::vector<sf::IntRect> PLAYER1_IDLE
{
	{10, 10, 215, 268},
	{235, 10, 215, 268},
	{460, 10, 215, 268},
	{685, 10, 215, 268},
	{910, 10, 215, 268},
	{1135, 10, 215, 268},
	{1361, 10, 215, 268},
	{1586, 10, 215, 268}
};
// Mage 1 Walk Anim
const std::vector<sf::IntRect> PLAYER1_WALK
{
	{10, 288, 215, 268},
	{235, 288, 215, 268},
	{460, 288, 215, 268},
	{685, 288, 215, 268},
	{910, 288, 215, 268}
};
// Mage 1 Wand Position
const sf::Vector2f PLAYER1_WAND_OFFSET(185.0f, 134.0f);
// Mage 2 sprite filepath
#define PLAYER2_FILEPATH "res/game/players/Mage2.png"
// Mage 2 Idle Anim
const std::vector<sf::IntRect> PLAYER2_IDLE
{
	{10, 10, 205, 268},
	{225, 10, 205, 268},
	{439, 10, 205, 268},
	{654, 10, 205, 268},
	{869, 10, 205, 268},
	{1083, 10, 205, 268},
	{1298, 10, 205, 268},
	{1512, 10, 205, 268}
};
// Mage 2 Walk Anim
const std::vector<sf::IntRect> PLAYER2_WALK
{
	{10, 288, 205, 268},
	{225, 288, 205, 268},
	{439, 288, 205, 268},
	{654, 288, 205, 268},
	{869, 288, 205, 268}
};
// Mage 2 Wand Position
const sf::Vector2f PLAYER2_WAND_OFFSET(182.0f, 142.0f);

#define PLAYER_IDLE_ANIM_TIME 0.25f
#define PLAYER_WALK_ANIM_TIME 0.1f

#define PLAYER_SIZE 0.5f
#define MOVEMENT_SPEED 1.5f
#pragma endregion

#pragma region Killbeam
#define KILLBEAM_FILEPATH "res/game/killbeam.png"

#define KILLBEAM_SIZE 50

// Killbeam Animation
const std::vector<sf::IntRect> KILLBEAM_ANIM
{
	{45, 0, 422, 132},
	{45, 127, 422, 132},
	{45, 255, 422, 132},
	{45, 382, 422, 132},
	{45, 511, 422, 132},
	{45, 639, 422, 132},
	{45, 765, 422, 132},
	{45, 894, 422, 132},
	{45, 1025, 422, 132},
	{45, 1153, 422, 132},
	{45, 1281, 422, 132}
};

#define KILLBEAM_ANIM_TIME 0.1f
#pragma endregion
#pragma endregion
