#include "GameScene.h"
#include "Entity.h"
#include "Square.h"
#include "Background.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Load()
{
	Entity* entityTemp = sky::Engine::Get().World().Create("Entity1");
	entityTemp->AddComponent<Background>();
	Entity* entitytemp2 = entityTemp->Instantiate("Entity2");
	entitytemp2->AddComponent<Square>();
}

void GameScene::LoadTileset(const std::string& image, int tileW, int tileH, int col, int count)
{
}
