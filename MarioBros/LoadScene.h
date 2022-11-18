#pragma once
#include <Component.h>
#include "Engine.h"



using namespace sky;
/// <summary>
/// handles the scene management
/// </summary>
class LoadScene :
    public Component, public IUpdatable
{
public:
    /// <summary>
    /// unloads current scene and load new scene
    /// </summary>
    LoadScene();
    LoadScene(Entity* parent);
    virtual void Update(float dt) override;
    ~LoadScene() = default;
    virtual void Start() override;
    virtual void Destroy() override;

private:
    Component* m_player = nullptr;
};

