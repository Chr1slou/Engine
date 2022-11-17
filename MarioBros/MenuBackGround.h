#pragma once
#include <Component.h>
#include "Engine.h"

using namespace sky;

class MenuBackGround :
    public Component, public IDrawable
{
public:
    MenuBackGround();
    MenuBackGround(Entity* parent);

    ~MenuBackGround() = default;
    virtual void Start() override;
    virtual void Destroy() override;
    virtual void Draw() override;
private:
    size_t m_background_texture_id;
};

