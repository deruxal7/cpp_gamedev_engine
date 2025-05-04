#include "InputActions.h"
#include "Entity.h"

#include <iostream>

namespace CacTus::Core {

MoveLeftAction::MoveLeftAction(float speed) : m_speed(speed) {}
void MoveLeftAction::execute(Entity& entity) {
    std::cout << "Move left action!" << std::endl;
    entity.setSpeedX(-m_speed);
}

MoveRightAction::MoveRightAction(float speed) : m_speed(speed) {}
void MoveRightAction::execute(Entity& entity) {
    std::cout << "Move right action!" << std::endl;
    entity.setSpeedX(m_speed);
}

MoveUpAction::MoveUpAction(float speed) : m_speed(speed) {}
void MoveUpAction::execute(Entity& entity) {
    std::cout << "Move up action!" << std::endl;
    entity.setSpeedY(-m_speed);
}

MoveDownAction::MoveDownAction(float speed) : m_speed(speed) {}
void MoveDownAction::execute(Entity& entity) {
    std::cout << "Move down action!" << std::endl;
    entity.setSpeedY(m_speed);
}

}