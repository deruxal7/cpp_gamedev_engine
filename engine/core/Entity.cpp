#include "Entity.h"

namespace CacTus::Core {

Entity::Entity(float x, float y, float width, float height, float max_speed)
    : m_x(x), m_y(y), m_width(width), m_height(height), m_max_speed(max_speed), m_velocity(0.0f, 0.0f) {
}

float Entity::getX() const{
    return m_x;
}

float Entity::getY() const{
    return m_y;
}

float Entity::getWidth() const{
    return m_width;
}

float Entity::getHeight() const{
    return m_height;
}

float Entity::getMaxSpeed() const{
    return m_max_speed;
}

void Entity::setX(float x) {
    m_x = x;
}

void Entity::setY(float y) {
    m_y = y;
}

void Entity::setMaxSpeed(float speed) {
    m_max_speed = speed;
}

glm::vec2 Entity::getVelocity() const {
    return m_velocity;
}

void Entity::setVelocity(glm::vec2 velocity) {
    m_velocity = velocity;
}

}