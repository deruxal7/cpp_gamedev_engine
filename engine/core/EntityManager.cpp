#include "EntityManager.h"
#include <stdexcept>
#include <string>

namespace CacTus::Core {

void EntityManager::addEntity(const Entity& entity) {
    m_entities.push_back(entity);
}

void EntityManager::updateEntities() {
    //pass
}

void EntityManager::renderEntities() {
    //pass
}

const std::vector<Entity>& EntityManager::getEntities() const{
    return m_entities;
}

Entity& EntityManager::getEntity(size_t index) {
    if (index >= m_entities.size()) {
        throw std::out_of_range(std::string("EntityManager::getEntity: index out of range: ") + std::to_string(index));
    }
    return m_entities[index];
}

}