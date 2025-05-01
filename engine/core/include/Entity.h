#pragma once

namespace CacTus::Core {

class Entity {
public:
    Entity(float x, float y, float width, float height);

    void setPosition(float x, float y);
    void move(float dx, float dy);

    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;

private:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
};
}