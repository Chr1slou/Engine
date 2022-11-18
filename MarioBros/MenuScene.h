#pragma once
#include <Engine.h>


/// <summary>
/// scene for the menu
/// </summary>
class MenuScene :
    public sky::IScene
{
public:
    MenuScene();
    ~MenuScene();
    /// <summary>
    /// adds the entity in the scene
    /// </summary>
    virtual void Load() override;

    /// <summary>
    /// sets the name of the scene
    /// </summary>
    /// <param name="sceneName"></param>
    virtual void SetName(const std::string& sceneName) override;
};

