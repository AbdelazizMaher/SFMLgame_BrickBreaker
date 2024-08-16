#include "ball.h"
#include "../game/gameConstants.h"

ball::ball(float x_pos, float y_pos) 
{
	/// \brief Load the texture from a file on disk
	m_texture.loadFromFile("../../resources/ball.png");
	/// \brief Change the source texture of the sprite
	m_sprite.setTexture(m_texture);
	/// \brief set the position of the object, This function completely overwrites the previous position.
	m_sprite.setPosition(x_pos, y_pos);
	m_velocity = { constants::ball_speed / 2.0f, constants::ball_speed / 2.0f };

	m_sprite.setColor(sf::Color::Red);

	m_sprite.setOrigin(getCentre());
}

void ball::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void ball::update()
{
	m_sprite.move(m_velocity);

	if (Xpos() < 0 || Xpos() > constants::window_width)
		m_velocity.x = -m_velocity.x;

	if (Ypos() < 0)
		m_velocity.y = -m_velocity.y;
	if (Ypos() > constants::window_height)
		destroyEntity();
}

void ball::moveUp() noexcept
{
	m_velocity.y = -constants::ball_speed;
}

void ball::moveLeft() noexcept
{
	m_velocity.x = -constants::ball_speed;
}

void ball::moveRight() noexcept
{
	m_velocity.x = constants::ball_speed;
}

void ball::moveDown() noexcept
{
	m_velocity.y = constants::ball_speed;
}

void ball::stopMoving() noexcept
{
	m_velocity.x = 0;
}
