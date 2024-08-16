#include "paddle.h"

#include "../ball/ball.h"
#include "../game/gameConstants.h"

void paddle::processPlayerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		if (Xpos() >= 0)
			m_velocity.x = -constants::paddle_speed;
		else
			m_velocity.x = 0;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) 
	{
		if (Xpos() < constants::window_width)
			m_velocity.x = constants::paddle_speed;
		else
			m_velocity.x = 0;
	}
	else
	{
		m_velocity.x = 0;
	}		
}

paddle::paddle(float x_pos, float y_pos)
{
	/// \brief Load the texture from a file on disk
	m_texture.loadFromFile("paddle.png");
	/// \brief Change the source texture of the sprite
	m_sprite.setTexture(m_texture);
	/// \brief set the position of the object, This function completely overwrites the previous position.
	m_sprite.setPosition(x_pos, y_pos);
	m_velocity = { 0.0f, 0.0f };

	m_sprite.setOrigin(getCentre());
}

void paddle::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void paddle::update()
{
	processPlayerInput();

	m_sprite.move(m_velocity);
}

void paddle::moveUp() noexcept
{
	
}

void paddle::moveLeft() noexcept
{
	m_velocity.x = -constants::paddle_speed;
}

void paddle::moveRight() noexcept
{
	m_velocity.x = constants::paddle_speed;
}

void paddle::moveDown() noexcept
{

}

void paddle::stopMoving() noexcept
{
	m_velocity.x = 0;
}

