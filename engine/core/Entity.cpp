#include "Entity.h"

namespace CacTus::Core {

Entity::Entity(float x, float y, float width, float height)
    : m_x(x), m_y(y), m_width(width), m_height(height) {}

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

float Entity::getSpeedX() const{
    return m_speedX;
}

float Entity::getSpeedY() const{
    return m_speedY;
}

void Entity::setX(float x) {
    m_x = x;
}

void Entity::setY(float y) {
    m_y = y;
}

void Entity::setSpeedX(float speedX) {
    m_speedX = speedX;
}

void Entity::setSpeedY(float speedY) {
    m_speedY = speedY;
}

}