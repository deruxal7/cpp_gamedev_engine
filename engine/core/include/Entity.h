#pragma once

namespace CacTus::Core {

class Entity {
public:
    Entity(float x, float y, float width, float height);
    ~Entity() = default;

    float getX() const;
    float getY() const;
    float getSpeedX() const;
    float getSpeedY() const;
    float getWidth() const;
    float getHeight() const;


    void setX(float x);
    void setY(float y);
    void setSpeedX(float speedX);
    void setSpeedY(float speedY);

private:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    float m_speedX;
    float m_speedY;
};
}