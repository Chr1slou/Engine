#include "GameScene.h"
#include "Entity.h"
#include "Square.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Load()
{
	Entity* entityTemp = sky::Engine::Get().World().Create("Entity1");
	entityTemp->AddComponent<Square>(new Square());
}
