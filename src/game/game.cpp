#include "game.h"
#include "../interaction/entitesInteraction.h"

game::game() 
{
	// Create the background object
	the_manager.create<background>(0.0f, 0.0f);
	// Create a ball object in the middle of the screen
	the_manager.create<ball>(constants::window_width / 2.0f, constants::window_height / 2.0f);
	// Create a paddle object at the bottom of the screen in the middle
	the_manager.create<paddle>(constants::window_width / 2.0f, constants::window_height - constants::paddle_height);

	for (int i = 0; i < constants::brick_columns; ++i)
	{
		for (int j = 0; j < constants::brick_rows; ++j)
		{
			float xPos = constants::brick_offset + (i + 1) * constants::brick_width;
			float yPos = (j + 1) * constants::brick_height;

			the_manager.create<brick>(xPos, yPos);
		}
	}

	// load font from file
	//m_verdana.loadFromFile("C:/Windows/fonts/Verdana.ttf");
	m_verdana.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/Verdana.ttf");

	// configure text objects
	m_stateText.setFont(m_verdana);
	m_stateText.setPosition(constants::window_width / 2.0f - 120.0f, constants::window_height / 2.0f - 100.0f);
	m_stateText.setCharacterSize(35);
	m_stateText.setFillColor(sf::Color::White);
	m_stateText.setString("PAUSED");

	m_LivesText.setFont(m_verdana);
	m_LivesText.setPosition(constants::window_width / 2.0f - 70.0f, constants::window_height / 2.0f - 50.0f);
	m_LivesText.setCharacterSize(35);
	m_LivesText.setFillColor(sf::Color::White);
	m_LivesText.setString("LIVES: " + std::to_string(m_lives));

	/// \brief Limit the framerate to a maximum fixed frequency
	game_window.setFramerateLimit(constants::window_FramerateLimit);
}

void game::reset()
{
	m_lives = constants::player_Lives;

	m_LivesText.setString("LIVES: " + std::to_string(m_lives));

	m_state = gameState::PAUSED;

	// Destroy all the entities and re-create them
	the_manager.clear();

	the_manager.create<background>(0.0f, 0.0f);
	the_manager.create<ball>(constants::window_width / 2.0f, constants::window_height / 2.0f);
	the_manager.create<paddle>(constants::window_width / 2.0f, constants::window_height - constants::paddle_height);

	for (int i = 0; i < constants::brick_columns; ++i)
	{
		for (int j = 0; j < constants::brick_rows; ++j)
		{
			float xPos = constants::brick_offset + (i + 1) * constants::brick_width;
			float yPos = (j + 1) * constants::brick_height;

			the_manager.create<brick>(xPos, yPos);
		}
	}
}

void game::run()
{
	// Game loop
	// Clear the screen
	// Check for new events
	// Calculate the updated graphics
	// Display the updated graphics

	// Was the pause key pressed in the last frame?
	bool isPausekey_active{ false };


	/// \brief Tell whether or not the window is open
	/// \return True if the window is open, false if it has been closed
	while (game_window.isOpen())
	{
		/// \brief Clear the entire target with a single color
		/// \param color Fill color to use to clear the render target
		/// \brief Utility class for manipulating RGBA colors
		game_window.clear(sf::Color::Black);

		/// \brief Defines a system event and its parameters
		sf::Event event;

		/// \brief Pop the event on top of the event queue, if any, and return it
		while (game_window.pollEvent(event))
		{
			//!< The window requested to be closed (no data)
			if (event.type == sf::Event::Closed)
				game_window.close();
		}

		/// \brief Check if a key is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			game_window.close();

		// If the user presses "P", we pause/unpause the game
		// To prevent repeated use, we ignore it if it was pressed on the last iteration
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) 
		{
			// If it was not pressed on the last iteration, toggle the status
			if (!isPausekey_active)
			{
				if (m_state == gameState::PAUSED)
					m_state = gameState::RUNNING;
				else
					m_state = gameState::PAUSED;
			}
			isPausekey_active = true;
		}
		else
			isPausekey_active = false;

		// If the user presses "R", we reset the game
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
			reset();

		if (m_state == gameState::PAUSED)
			the_manager.draw(game_window);

		if (m_state != gameState::RUNNING)
		{
			switch (m_state)
			{
			case gameState::PAUSED:
				m_stateText.setString("    PAUSED    ");
				break;
			case gameState::GAME_OVER:
				m_stateText.setString("  GAME OVER!  ");
				break;
			case gameState::PLAYER_WINS:
				m_stateText.setString(" PLAYER WINS! ");
				break;
			default:
				break;
			}

			game_window.draw(m_stateText);
			game_window.draw(m_LivesText);
		}
		else
		{
			if (the_manager.getALL<ball>().empty())
			{
				the_manager.create<ball>(constants::window_width / 2.0f, constants::window_height / 2.0f);
				--m_lives;

				m_state = gameState::PAUSED;
			}

			if (the_manager.getALL<brick>().empty())
				m_state = gameState::PLAYER_WINS;
			if (m_lives == 0)
				m_state = gameState::GAME_OVER;

			m_LivesText.setString("LIVES: " + std::to_string(m_lives));

			// Calculate the updated graphics
			the_manager.update();

			the_manager.applyToALL<ball>([this](auto& the_ball) {
				the_manager.applyToALL<paddle>([&the_ball](auto& the_paddle) {
					handleCollision(the_ball, the_paddle);
					});
				});

			// Check every brick for a collision with the ball
			the_manager.applyToALL<ball>([this](auto& the_ball) {
				the_manager.applyToALL<brick>([&the_ball](auto& the_brick) {
					handleCollision(the_ball, the_brick);
					});
				});

			the_manager.refresh();

			/// \brief Display on screen what has been rendered to the window so far
			the_manager.draw(game_window);
		}

		game_window.display();

	}
}
