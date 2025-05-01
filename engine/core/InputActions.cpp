#include <InputActions.h>
#include <iostream>

namespace CacTus::Core {

void MoveLeftAction::execute() {
    std::cout << "Move left action!" << std::endl;
}

void MoveRightAction::execute() {
    std::cout << "Move right action!" << std::endl;
}

void MoveUpAction::execute() {
    std::cout << "Move up action!" << std::endl;
}

void MoveDownAction::execute() {
    std::cout << "Move down action!" << std::endl;
}

}