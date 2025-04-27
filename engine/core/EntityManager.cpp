#include "EntityManager.h"

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

}