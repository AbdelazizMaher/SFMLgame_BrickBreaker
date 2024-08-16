#pragma once
#include "gameEntity.h"

class background :
    public gameEntity
{
private:
    inline static sf::Texture m_texture;
public:
    background(float x_pos, float y_pos);

    virtual void draw(sf::RenderWindow& window) override;
    virtual void update() override;
};

