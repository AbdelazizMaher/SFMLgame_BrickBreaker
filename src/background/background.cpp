#include "background.h"

background::background(float x_pos, float y_pos)
{
	/// \brief Load the texture from a file on disk
	m_texture.loadFromFile("../../resources/background.jpg");
	/// \brief Change the source texture of the sprite
	m_sprite.setTexture(m_texture);
	/// \brief set the position of the object, This function completely overwrites the previous position.
	m_sprite.setPosition(x_pos, y_pos);
}

void background::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void background::update()
{
}
