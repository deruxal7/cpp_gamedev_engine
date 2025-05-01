#pragma once

namespace CacTus::Core {

class InputActions {

public: 
    virtual ~InputActions() = default;

    virtual void execute() = 0;

};

class MoveLeftAction : public InputActions {

public:
    MoveLeftAction() = default;
    void execute() override;

};

class MoveRightAction : public InputActions {

public: 
    MoveRightAction() = default;
    void execute() override;

};

class MoveUpAction : public InputActions {

public:
    MoveUpAction() = default;
    void execute() override;

};

class MoveDownAction : public InputActions {

public:
    MoveDownAction() = default;
    void execute() override;

};

}