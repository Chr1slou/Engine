#pragma once
#include <Component.h>
#include <Engine.h>
#include "Animation.h"
using namespace sky;


/// <summary>
/// receives inputs
/// </summary>
class PlayerController :
    public Component, public IUpdatable
{
public:
    PlayerController();
    PlayerController(Entity* parent);

    /// <summary>
    /// suscribes animator
    /// </summary>
    /// <param name="animator"></param>
    void SetAnimator(Animation* animator);
    /// <summary>
    /// checks the inputs and configure the behavior
    /// </summary>
    /// <param name="dt"></param>
    virtual void Update(float dt) override;
    ~PlayerController() = default;
    virtual void Start() override;
    virtual void Destroy() override;

private:
    Component* m_Player = nullptr;
    Animation* m_Animator = nullptr;
};

