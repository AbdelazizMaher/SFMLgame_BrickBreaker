#include "brick.h"

brick::brick(float x_pos, float y_pos)
{
	/// \brief Load the texture from a file on disk
	m_texture.loadFromFile("brick01.png");
	/// \brief Change the source texture of the sprite
	m_sprite.setTexture(m_texture);
	/// \brief set the position of the object, This function completely overwrites the previous position.
	m_sprite.setPosition(x_pos, y_pos);

	m_red = colorDist(mt);
	m_green = colorDist(mt);
	m_blue = colorDist(mt);

	m_sprite.setColor(sf::Color{ m_red, m_green, m_blue, 255 });

	m_sprite.setOrigin(getCentre());
}

void brick::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void brick::update()
{
	//if (m_strength == 1)
	//	m_sprite.setColor(sf::Color{ 0, 255, 0, 80 });
	//else if (m_strength == 2)
	//	m_sprite.setColor(sf::Color{ 0, 255, 0, 170 });
	//else if (m_strength == 3)
	//	m_sprite.setColor(sf::Color{ 0, 255, 0, 255 });


	if (m_strength == 1)
		m_sprite.setColor(sf::Color{ m_red, m_green, m_blue, 80});
	else if (m_strength == 2)
		m_sprite.setColor(sf::Color{ m_red, m_green, m_blue, 170 });
	else if (m_strength == 3)
		m_sprite.setColor(sf::Color{ m_red, m_green, m_blue, 255 });
}

void brick::setStrength(int strength) noexcept
{
	m_strength = strength;
}

void brick::weaken() noexcept
{
	--m_strength;
}

bool brick::isTooWeak() const noexcept
{
	return m_strength == 0;
}
