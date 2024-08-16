#pragma once
#include "gameEntity.h"

class movingEntity :
    public gameEntity
{
protected:
    sf::Vector2f m_velocity;
public:
    virtual void moveUp() noexcept = 0;
    virtual void moveLeft() noexcept = 0;
    virtual void moveRight() noexcept = 0;
    virtual void moveDown() noexcept = 0;
    virtual void stopMoving() noexcept = 0;
};

