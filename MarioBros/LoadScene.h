#pragma once
#include <Component.h>
#include "Engine.h"

using namespace sky;
class LoadScene :
    public Component, public IUpdatable
{
public:
    LoadScene();
    LoadScene(Entity* parent);
    virtual void Update(float dt) override;
    ~LoadScene() = default;
    virtual void Start() override;
    virtual void Destroy() override;

private:
    Component* m_player = nullptr;
};

