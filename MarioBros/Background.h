#pragma once
#include <Component.h>
#include "Engine.h"

using namespace sky;

class Background :
    public Component, public IDrawable
{
public:
    Background();
    Background(Entity* parent);

    ~Background() = default;
    virtual void Start() override;
    virtual void Destroy() override;
    virtual void Draw() override;
private:
    
};

