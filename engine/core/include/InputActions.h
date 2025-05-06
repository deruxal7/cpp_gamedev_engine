#pragma once

#include <glm/glm.hpp>

namespace CacTus::Core {

class Entity;

class InputAction {
public:
    virtual ~InputAction() = default;
    virtual void execute(Entity& entity) = 0;
};

}