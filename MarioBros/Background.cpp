#include "Background.h"

Background::Background()
{
}

Background::Background(Entity* parent)
{
	m_background_texture_id = Engine::Get().Graphics().LoadTexture("assets/background.png");
}

void Background::Start()
{

}

void Background::Destroy()
{
}

void Background::Draw()
{
	Engine::Get().Graphics().DrawTexture(m_background_texture_id, Color::WHITE);
}
