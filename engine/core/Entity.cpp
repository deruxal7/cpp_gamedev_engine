#include "Entity.h"

namespace CacTus::Core {

Entity::Entity(float x, float y, float width, float height)
    : m_x(x), m_y(y), m_width(width), m_height(height) {}

void Entity::setPosition(float x, float y) {
    m_x = x;
    m_y = y;
}

void Entity::move(float dx, float dy) {
    m_x += dx;
    m_y += dy;
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


}