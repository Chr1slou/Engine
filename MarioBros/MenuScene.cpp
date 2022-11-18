#include "MenuScene.h"
#include "Entity.h"
#include "MenuBackGround.h"
#include "LoadScene.h"

MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{

}

void MenuScene::Load()
{
	Entity* entityTemp = sky::Engine::Get().World().Create("MenuBackGround");
	entityTemp->AddComponent<LoadScene>();
	entityTemp->AddComponent<MenuBackGround>();
}

void MenuScene::SetName(const std::string& sceneName)
{
	m_Name = sceneName;
}
