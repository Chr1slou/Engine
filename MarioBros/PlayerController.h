#pragma once
#include <Component.h>
#include <Engine.h>
#include "Animation.h"
using namespace sky;

class PlayerController :
    public Component, public IUpdatable
{
public:
    PlayerController();
    PlayerController(Entity* parent);
    void SetAnimator(Animation* animator);
    virtual void Update(float dt) override;
    ~PlayerController() = default;
    virtual void Start() override;
    virtual void Destroy() override;

private:
    Component* m_Player = nullptr;
    Animation* m_Animator = nullptr;
};

