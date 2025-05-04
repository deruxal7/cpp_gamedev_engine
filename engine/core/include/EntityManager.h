#pragma once

#include <vector>
#include <cstddef>

#include "Entity.h"

namespace CacTus::Core {

class EntityManager {

public:

    void addEntity(const Entity& entity);
    void updateEntities();
    void renderEntities();

    const std::vector<Entity>& getEntities() const;
    Entity& getEntity(size_t index);

private:

    std::vector<Entity> m_entities;

};

}