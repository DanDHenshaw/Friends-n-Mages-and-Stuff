#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

#pragma region RENDER WINDOW
// Game title.
#define TITLE "TITLE"
// Game width.
#define SCREEN_WIDTH 1280
// Game height
#define SCREEN_HEIGHT 720
#pragma endregion

#pragma region SPLASH SCREEN
// Splash screen play length.
#define SPLASH_STATE_SHOW_TIME 3
// Splash screen background filepath.
#define SPLASH_SCENE_BACKGROUND_FILEPATH "data/res/splash/background.jpg"
#pragma endregion

#pragma region MENU SCREEN
// Menu screen background filepath.
#define MAIN_MENU_SCENE_BACKGROUND_FILEPATH "data/res/menu/background.jpg"
// Menu screen play button filepath.
#define MAIN_MENU_SCENE_PLAY_BUTTON_FILEPATH "data/res/menu/playButton.png"
// Menu screen leaderboard button filepath.
#define MAIN_MENU_SCENE_LEADERBOARD_BUTTON_FILEPATH "data/res/menu/leaderboardButton.png"
// Menu screen exit button filepath.
#define MAIN_MENU_SCENE_EXIT_BUTTON_FILEPATH "data/res/menu/exitButton.png"
// Menu screen title filepath.
#define MAIN_MENU_SCENE_TITLE_FILEPATH "data/res/menu/title.png"
#pragma endregion

#pragma region GAME
#pragma region PLAYERS
// Mage 1 sprite filepath
#define PLAYER1_FILEPATH "data/res/game/players/Mage1.png"
// Mage 1 Idle Anim
const vector<IntRect> PLAYER1_IDLE
{
	{-3, 4, 188, 228},
	{184, 4, 188, 228},
	{371, 4, 188, 228},
	{559, 4, 188, 228},
	{747, 4, 188, 228},
	{934, 4, 188, 228},
	{1112, 4, 188, 228},
	{1306, 4, 188, 228}
};
// Mage 1 Walk Anim
const vector<IntRect> PLAYER1_WALK
{
	{-3, 238, 188, 228},
	{187, 238, 188, 228},
	{374, 238, 188, 228},
	{560, 238, 188, 228},
	{747, 238, 188, 228}
};
// Mage 2 sprite filepath
#define PLAYER2_FILEPATH "data/res/game/players/Mage2.png"
// Mage 2 Idle Anim
const vector<IntRect> PLAYER2_IDLE
{
	{12, 14, 175, 238},
	{199, 14, 175, 238},
	{385, 14, 175, 238},
	{576, 14, 175, 238},
	{761, 14, 175, 238},
	{945, 14, 175, 238},
	{1133, 14, 175, 238},
	{1320, 14, 175, 238},
};
// Mage 2 Walk Anim
const vector<IntRect> PLAYER2_WALK
{
	{12, 258, 175, 238},
	{202, 258, 175, 238},
	{389, 258, 175, 238},
	{576, 258, 175, 238},
	{759, 258, 175, 238}
};

#define ANIM_FPS 0.125f
#pragma endregion
#pragma endregion
