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
	Engine::Get().Graphics().FillRect(200, 200, 200, 200, Color::AQUAMARINE);
}
