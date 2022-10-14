#pragma once
#include <Component.h>
#include <Engine.h>
class Square :
    public Component, sky::IDrawable
{
public:
    Square();
    ~Square() = default ;
    virtual void Draw() override;
};

