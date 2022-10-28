#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>

#include <Engine.h>
#include <GameScene.h>



void InitGameplay()
{
	sky::Engine::Get().World().Register("Game", new GameScene());
	sky::Engine::Get().World().Load("Game");
	
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR argv, _In_ INT argc)
{
	sky::Engine& theEngine = sky::Engine::Get();
	if (theEngine.Init("MarioBros", 800, 600))
	{
		InitGameplay();
		theEngine.Start();
	}
	return 0;
}