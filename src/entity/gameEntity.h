#pragma once

#include <SFML/Graphics.hpp>
#include "../game/gameConstants.h"

class gameEntity
{
protected:
	sf::Sprite m_sprite;

	bool m_destroyed{ false };
public:
	virtual ~gameEntity() = default;

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update() = 0;

	/// \brief Get the global bounding rectangle of the entity
	sf::FloatRect getBoundingBox() const noexcept { return m_sprite.getGlobalBounds(); }

	sf::Vector2f getCentre() const noexcept
	{
		auto [left, top, width, height] = getBoundingBox();
		return { width / 2.0f, height / 2.0f };
	}

	float Xpos() const noexcept { return m_sprite.getPosition().x; }
	float Ypos() const noexcept { return m_sprite.getPosition().y; }

	// Helper functions to get the edges of the sprite
	float leftBound() const noexcept
	{
		auto [left, top, width, height] = getBoundingBox();
		return Xpos() - width / 2.0f;
	}

	float rightBound() const noexcept
	{
		auto [left, top, width, height] = getBoundingBox();
		return Xpos() + width / 2.0f;
	}
	float topBound() const noexcept
	{
		auto [left, top, width, height] = getBoundingBox();
		return Ypos() - height / 2.0f;
	}
	float bottomBound() const noexcept
	{
		auto [left, top, width, height] = getBoundingBox();
		return Ypos() + height / 2.0f;
	}

	// Helper functions for the state of the entity
	void destroyEntity() noexcept { m_destroyed = true; }

	bool isDestroyed() const noexcept { return m_destroyed; }
};



