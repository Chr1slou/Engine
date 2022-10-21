#pragma once
#include <Component.h>
#include <Engine.h>

using namespace sky;

class Square :
    public Component,  public IDrawable
{
public:
    Square();
    Square(Entity* parent);

    ~Square() = default ;
    virtual void Start() override;
    virtual void Destroy() override;
    virtual void Draw() override;
};

