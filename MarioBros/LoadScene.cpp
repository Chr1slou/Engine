#include "LoadScene.h"
#include "MenuScene.h"

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
		sky::Engine::Get().World().Register("Menu", new MenuScene());
		sky::Engine::Get().World().Load("Menu");
	}
}

void LoadScene::Start()
{
}

void LoadScene::Destroy()
{
}
