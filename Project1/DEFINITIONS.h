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
const vector<IntRect> PLAYER1_WALK
{
	{10, 288, 215, 268},
	{235, 288, 215, 268},
	{460, 288, 215, 268},
	{685, 288, 215, 268},
	{910, 288, 215, 268}
};
// Mage 2 sprite filepath
#define PLAYER2_FILEPATH "data/res/game/players/Mage2.png"
// Mage 2 Idle Anim
const vector<IntRect> PLAYER2_IDLE
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
const vector<IntRect> PLAYER2_WALK
{
	{10, 288, 205, 268},
	{225, 288, 205, 268},
	{439, 288, 205, 268},
	{654, 288, 205, 268},
	{869, 288, 205, 268}
};

#define PLAYER_IDLE_ANIM_TIME 0.25f
#define PLAYER_WALK_ANIM_TIME 0.1f

#define PLAYER_SIZE 0.5f
#define MOVEMENT_SPEED 1.5f
#pragma endregion

#pragma region Killbeam
#define KILLBEAM_FILEPATH "data/res/game/killbeam.png"
#pragma endregion
#pragma endregion
