#pragma once
#include <Component.h>
#include <Engine.h>
using namespace sky;

class PlayerController :
    public Component, public IUpdatable
{
public:
    PlayerController();
    PlayerController(Entity* parent);
    virtual void Update(float dt) override;
    ~PlayerController() = default;
    virtual void Start() override;
    virtual void Destroy() override;

private:
    Component* m_player = nullptr;
};

