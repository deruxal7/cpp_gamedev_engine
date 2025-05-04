#pragma once

namespace CacTus::Core {

class Entity;

class InputActions {

public: 
    virtual ~InputActions() = default;

    virtual void execute(Entity& entity) = 0;

};

class MoveLeftAction : public InputActions {

public:
    MoveLeftAction(float speed);
    void execute(Entity& entity) override;

private:
    float m_speed;
};

class MoveRightAction : public InputActions {

public: 
    MoveRightAction(float speed);
    void execute(Entity& entity) override;

private:
    float m_speed;

};

class MoveUpAction : public InputActions {

public:
    MoveUpAction(float speed);
    void execute(Entity& entity) override;

private:
    float m_speed;
};

class MoveDownAction : public InputActions {

public:
    MoveDownAction(float speed);
    void execute(Entity& entity) override;

private:
    float m_speed;
};

}