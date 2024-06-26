#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#define PROFILER false

#define PI 3.141592653589793238463

#define FONT_FILEPATH "fonts/RiotGothic.ttf"
#define TEXT_COLOR sf::Color(117, 93, 69)

#pragma region Leaderboard
#define LEADERBOARD_NAME "highscores.db"
#pragma endregion

#pragma region RENDER WINDOW
// Game title.
#define TITLE "Friends 'n Mages and Stuff"
// Game width.
#define SCREEN_WIDTH 1280
// Game height
#define SCREEN_HEIGHT 720
// Game icon filepath
#define GAMEICON_FILEPATH "res/menu/title.png"
#pragma endregion

#pragma region SPLASH SCREEN
// Splash screen play length.
#define SPLASH_STATE_SHOW_TIME 3
// Splash screen background filepath.
#define SPLASH_SCENE_BACKGROUND_FILEPATH "res/splash/background.jpg"
#pragma endregion

#pragma region MENU SCREEN
// Menu screen background filepath.
#define MAIN_MENU_SCENE_BACKGROUND_FILEPATH "res/game/background.jpg"
// Menu screen play button filepath.
#define MAIN_MENU_SCENE_PLAY_BUTTON_FILEPATH "res/menu/playButton.png"
// Menu screen leaderboard button filepath.
#define MAIN_MENU_SCENE_LEADERBOARD_BUTTON_FILEPATH "res/menu/leaderboardButton.png"
// Menu screen exit button filepath.
#define MAIN_MENU_SCENE_EXIT_BUTTON_FILEPATH "res/menu/quitButton.png"
// Menu screen title filepath.
#define MAIN_MENU_SCENE_TITLE_FILEPATH "res/menu/title.png"
#pragma endregion

#pragma region LEADERBOARD SCREEN
#define LEADERBOARD_BACKGROUND_FILEPATH "res/game/background.jpg"

#define LEADERBOARD_PANEL_FILEPATH "res/leaderboard/leaderboardPanel.png"
#define LEADERBOARD_PANEL_SIZE sf::Vector2f(1147, 589)

#define LEADERBOARD_ITEM_FILEPATH "res/leaderboard/leaderboardPosition.png"
#define LEADERBOARD_ITEM_SIZE sf::Vector2f(1102, 46)

#define LEADERBOARD_ITEM_TEXT_COLOR sf::Color(198, 164, 127)

#define LEADERBOARD_MENU_BUTTON "res/pause/menuButton.png"
#define LEADERBOARD_EXIT_BUTTON "res/pause/quitButton.png"
#pragma endregion

#pragma region PAUSE SCREEN
// Pause screen background filepath.
#define PAUSE_SCENE_BACKGROUND_FILEPATH "res/game/background.jpg"
// Pause screen resume button filepath.
#define PAUSE_SCENE_RESUME_BUTTON_FILEPATH "res/pause/resumeButton.png"
// Pause screen menu button filepath.
#define PAUSE_SCENE_MENU_BUTTON_FILEPATH "res/pause/menuButton.png"
// Pause screen exit button filepath.
#define PAUSE_SCENE_EXIT_BUTTON_FILEPATH "res/pause/quitButton.png"
#pragma endregion

#pragma region GAME SCREEN
#define GAME_BACKGROUND_FILEPATH "res/game/background.jpg"

#define SCORE_BACKGROUND_FILEPATH "res/game/score.png"
#define SCORE_BACKGROUND_SIZE sf::Vector2f(494 / 2, 82 / 2)

#define SCORE_TEXT_SIZE 36

#define NAME_BACKGROUND "res/game/name.png"
#define NAME_BACKGROUND_SIZE sf::Vector2f(1111, 174)

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

#pragma region ENEMY
// Mage 1 sprite filepath
#define ENEMY_FILEPATH "res/game/enemy/enemy.png"

#define ENEMY_SIZE sf::Vector2f(266 / 2, 228 / 2)

// Enemy Walk Anim
const std::vector<sf::IntRect> ENEMY_WALK
{
	{10, 0, 266, 228},
	{286, 0, 266, 228},
	{561, 0, 266, 228},
	{837, 0, 266, 228},
	{1113, 0, 266, 228}
};

#define ENEMY_WALK_ANIM_TIME 0.1f

#define START_SPAWN_CLOCK 10.0f
#pragma endregion

#pragma region CASTLE
// Castle texture location
#define CASTLE_FILEPATH "res/game/castle/castle.png"

// Size of castle
#define CASTLE_SIZE sf::Vector2f(215 / 2, 268 / 2)
#pragma endregion
#pragma endregion

#pragma region PROFILER
	#if PROFILER
		#include "Profiler.h"

		#define BEGIN_SESSION(name) Profiler::BeginSession(name)
		#define INSTRMENTATIONTIMER() Profiler::InstrumentationTimer timer(__FUNCSIG__)
		#define END_SESSION() Profiler::EndSession();

		#define TITLE "Friends 'n Mages and Stuff (Profiler)"
	#else
		#define BEGIN_SESSION(name)
		#define INSTRMENTATIONTIMER()
		#define END_SESSION()
	#endif
#pragma endregion
