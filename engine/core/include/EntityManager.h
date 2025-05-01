#pragma once

#include <vector>
#include "Entity.h"

namespace CacTus::Core {

class EntityManager {

public:

    void addEntity(const Entity& entity);
    void updateEntities();
    void renderEntities();

    const std::vector<Entity>& getEntities() const;

private:

    std::vector<Entity> m_entities;

};

}