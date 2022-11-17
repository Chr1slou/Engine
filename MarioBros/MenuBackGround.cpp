#include "MenuBackGround.h"

MenuBackGround::MenuBackGround()
{
}

MenuBackGround::MenuBackGround(Entity* parent)
{
	m_background_texture_id = Engine::Get().Graphics().LoadTexture("assets/title.png");
}

void MenuBackGround::Start()
{

}

void MenuBackGround::Destroy()
{
}

void MenuBackGround::Draw()
{
	m_GraphicService.DrawTexture(m_background_texture_id, Color::WHITE);
}
