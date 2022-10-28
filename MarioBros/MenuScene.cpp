#include "MenuScene.h"
#include "Entity.h"
#include "Square.h"

MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::Load()
{
	Entity* entityTemp = sky::Engine::Get().World().Create("Square");
	entityTemp->AddComponent<Square>();
}

void MenuScene::SetName(const std::string& sceneName)
{
	m_Name = sceneName;
}
