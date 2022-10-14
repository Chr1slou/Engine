#pragma once
#include <Engine.h>
class MenuScene :
    public sky::IScene
{
public:
    MenuScene();
    ~MenuScene();
    virtual void Load() override;
};

