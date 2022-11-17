#pragma once
#include <Component.h>
#include <Engine.h>
#include "Animation.h"

using namespace sky;

class MenuController :
    public Component, public IUpdatable
{
public:
    MenuController();
    MenuController(Entity* parent);
    void SetAnimator(Animation* animator);
    virtual void Update(float dt) override;
    ~MenuController() = default;
    virtual void Start() override;
    virtual void Destroy() override;

private:
    Component* m_Player = nullptr;
   
};


