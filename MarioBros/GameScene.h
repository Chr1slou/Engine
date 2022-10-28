#pragma once
#include <Engine.h>



class GameScene :
    public sky::IScene
{
public:
    GameScene();
    ~GameScene();
    virtual void Load() override;
    void LoadTileset(const std::string& image, int tileW, int tileH, int col, int count);
    virtual void SetName(const std::string& sceneName) override;

    

};

