#include "LoadScene.h"

#include <GameScene.h>

LoadScene::LoadScene()
{
}

LoadScene::LoadScene(Entity* parent)
{
}

void LoadScene::Update(float dt)
{
	if (Engine::Get().Input().IsKeyDown(EKey::EKEY_2))
	{
		
		sky::Engine::Get().World().Unload();
		sky::Engine::Get().World().Load("Game");
		sky::Engine::Get().World().UnRegister("Menu");





	}
}

void LoadScene::Start()
{
}

void LoadScene::Destroy()
{
}
