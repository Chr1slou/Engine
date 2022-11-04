#include "Square.h"
#include "Entity.h"
#include "color.h"


Square::Square(): Square(nullptr)
{
}

Square::Square(Entity* parent) : Component(parent)
{
	//Engine::Get().Graphics().LoadTileSet("assets/env.png", 32, 32, 16, 153);
}

void Square::Start()
{
}

void Square::Destroy()
{
}

void Square::Draw()
{
	Engine::Get().Graphics().FillRect(m_Parent->GetPosition().X, m_Parent->GetPosition().Y, 200, 200, Color::AQUAMARINE);
	//Engine::Get().Graphics().RenderFrame();
}
