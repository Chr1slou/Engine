#pragma once
#include <Engine.h>
class MenuScene :
    public sky::IScene
{
public:
    MenuScene();
    ~MenuScene();
    virtual void Load() override;
    virtual void SetName(const std::string& sceneName) override;
};

