#pragma once

#include <glm/glm.hpp>

namespace CacTus::Core {

class Entity {
public:
    Entity(float x, float y, float width, float height, float max_speed);
    ~Entity() = default;

    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;

    float getMaxSpeed() const;

    void setX(float x);
    void setY(float y);
    void setMaxSpeed(float speed);

    glm::vec2 getVelocity() const;
    void setVelocity(glm::vec2 velocity);

private:
    float m_x;
    float m_y;
    float m_width;
    float m_height;

    float m_max_speed;
    
    glm::vec2 m_velocity;
};
}