#pragma once
#include "movingEntity.h"

class ball :
    public movingEntity
{
private:
    inline static sf::Texture m_texture;
public:
    ball(float x_pos, float y_pos);

    virtual void draw(sf::RenderWindow& window) override;
    virtual void update() override;

    void moveUp() noexcept override;
    void moveLeft() noexcept override;
    void moveRight() noexcept override;
    void moveDown() noexcept override;
    void stopMoving() noexcept override;
};

