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
	Animator->SetTexture("assets/helicoanim.png");
	Animator->SetDst(250, 120);
	/*Animator->AddFrame("0", 0, 0, 250, 120);
	Animator->AddFrame("0", 250, 0, 250, 120);
	Animator->AddFrame("0", 0, 120, 250, 120);
	Animator->AddFrame("0", 250, 120, 250, 120);*/
	Animator->InitAnimation(2, 250, 120);
	Animator->AddClip("right", 0, 4, 4);

	
}

void GameScene::LoadTileset(const std::string& image, int tileW, int tileH, int col, int count)
{
}

void GameScene::SetName(const std::string& sceneName)
{
	m_Name = sceneName;
}
