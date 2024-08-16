#pragma once

#include <random>
#include "../entity/gameEntity.h"

class brick :
    public gameEntity
{
private:
    inline static sf::Texture m_texture;

    inline static std::mt19937 mt;
    inline static std::uniform_int_distribution<> colorDist{ 100, 255 };

    sf::Uint8 m_red, m_green, m_blue;

    // How many times the brick can be hit before destroying it
    int m_strength{ constants::brick_strength };
public:
    brick(float x_pos, float y_pos);

    virtual void draw(sf::RenderWindow& window) override;
    virtual void update() override;

    void setStrength(int strength) noexcept;
    void weaken() noexcept;
    bool isTooWeak() const noexcept;
};

