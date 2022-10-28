#include "Square.h"
#include "Entity.h"
#include "color.h"


Square::Square(): Square(nullptr)
{
}

Square::Square(Entity* parent) : Component(parent)
{
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
}
