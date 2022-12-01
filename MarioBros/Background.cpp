#include "Background.h"



Background::Background()
{
}

Background::Background(Entity* parent) : Component(parent)
{
	//m_background_texture_id = Engine::Get().Graphics().LoadTexture("assets/background.png");
	/*m_GraphicService.LoadTileSet("assets/env.png", 32, 32, 16, 153);
	m_GraphicService.LoadTileMap("assets/layer1.csv", "layer1");
	m_GraphicService.LoadTileMap("assets/layer2.csv", "layer2");*/
	m_GraphicService.LoadTileSet("assets/tileset.png", 32, 32, 11, 66);
	m_GraphicService.LoadTileMap("assets/layer1.csv", "layer1");

}

void Background::Start()
{

}

void Background::Destroy()
{
}

void Background::Draw()
{
	//Engine::Get().Graphics().DrawTexture(m_background_texture_id, Color::WHITE);
	m_GraphicService.DrawTiles(32, 32);
}
