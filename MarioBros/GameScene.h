#pragma once
#include <Engine.h>
class GameScene :
    public sky::IScene
{
public:
    GameScene();
    ~GameScene();
    virtual void Load() override;
};

