#include "GameScene.h"
#include "Entity.h"
#include "Square.h"
#include "Background.h"
#include "PlayerController.h"
#include "LoadScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	sky::Engine::Get().World().Unload();
}

void GameScene::Load()
{
	Entity* entityTemp = sky::Engine::Get().World().Create("Entity1");
	entityTemp->AddComponent<Background>();
	entityTemp->AddComponent<LoadScene>();

	Entity* entitytemp2 = entityTemp->Instantiate("Entity2");
	entitytemp2->AddComponent<Square>();
	entitytemp2->AddComponent<PlayerController>();
}

void GameScene::LoadTileset(const std::string& image, int tileW, int tileH, int col, int count)
{
}

void GameScene::SetName(const std::string& sceneName)
{
	m_Name = sceneName;
}
