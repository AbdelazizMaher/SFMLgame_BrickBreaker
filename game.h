#pragma once

#include <SFML/Graphics.hpp>

#include "gameConstants.h"
#include "background.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "entityManager.h"

using namespace std::literals;

class game
{
private:
	/// \param modeWidth        Width in pixels
	/// \param modeHeight       Height in pixels
	/// \param modeBitsPerPixel Pixel depths in bits per pixel
	// VideoMode(unsigned int modeWidth, unsigned int modeHeight, unsigned int modeBitsPerPixel = 32);
	// 
	/// \param mode     Video mode to use (defines the width, height and depth of the rendering area of the window)
	/// \param title    Title of the window
	/// \param style    %Window style, a bitwise OR combination of sf::Style enumerators
	/// \param settings Additional settings for the underlying OpenGL context
	// 
	// RenderWindow(VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());
	sf::RenderWindow game_window{ {constants::window_width, constants::window_height},
		"^^^ brick breaker Game ^^^"s};


	entityManager the_manager;

	sf::Font m_verdana;
	sf::Text m_stateText, m_LivesText;

	// Enum with allowed values for the game's state
	enum class gameState : uint8_t
	{ 
		PAUSED,
		RUNNING,
		GAME_OVER,
		PLAYER_WINS
	};

	// Member to store the current state of the game
	gameState m_state{ gameState::PAUSED };

	int m_lives{ constants::player_Lives };

public:
	game();

	// Reinitialize the game
	void reset();

	// Game loop
	void run();
};

