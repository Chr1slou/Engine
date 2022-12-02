#include "GameScene.h"
#include "Entity.h"
#include "Square.h"
#include "Background.h"
#include "PlayerController.h"
#include "LoadScene.h"
#include "Animation.h"

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
	
	Entity* entitytemp2 = entityTemp->Instantiate("Entity2");
	entitytemp2->AddComponent<PlayerController>();
	entitytemp2->AddComponent<Animation>();
	Animation* Animator = entitytemp2->GetComponent< Animation>();
	entitytemp2->GetComponent<PlayerController>()->SetAnimator(Animator);
	Animator->SetTexture("assets/Player.png");
	Animator->SetDst(64, 64);
	/*Animator->AddFrame("0", 0, 0, 250, 120);
	Animator->AddFrame("0", 250, 0, 250, 120);
	Animator->AddFrame("0", 0, 120, 250, 120);
	Animator->AddFrame("0", 250, 120, 250, 120);*/
	Animator->InitAnimation(6, 32, 32);
	Animator->AddClip("Idle", 0, 0, 1);
	Animator->AddClip("Right", 1, 3, 0.3);
	Animator->Play("Idle", true);
	
}

void GameScene::LoadTileset(const std::string& image, int tileW, int tileH, int col, int count)
{
}

void GameScene::SetName(const std::string& sceneName)
{
	m_Name = sceneName;
}
