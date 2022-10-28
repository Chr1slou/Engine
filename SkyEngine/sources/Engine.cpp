#include <Engine.h>
#include <SDL.h>
#include<time.h>
#include <windows.h>
#include <SdlInput.h>

#if _DEBUG
#include <ConsoleLogger.h>
#else
#include <FileLogger.h>
#endif

#include "SDLGraphics.h"
#include "SDLAudio.h"
#include "WorldService.h"
#include "vld.h"




static unsigned char const* _keys = nullptr;
static float _tempX = 400;
static float _tempY = 230;
static bool isRunning = false;

//assets IDs
size_t background_texture_id = 0;
size_t mario_image_id = 0;
size_t background_music_id = 0;
size_t sample_sound_id = 0;
size_t font_id = 0;


/// <summary>
/// init the services
/// </summary>
/// <param name="title"> string</param>
/// <param name="w"></param>
/// <param name="h"></param>
/// <returns></returns>
bool sky::Engine::Init(const std::string& title, int w, int h)
{
#if _DEBUG
	m_Logger = new ConsoleLogger();
#else
	m_Logger = new FileLogger();
#endif

	m_Logger->Write("Wooowww");
	

	m_Input = new SdlInput();
	m_Graphics = new SDLGraphics();
	m_Audio = new SDLAudio();
	m_Graphics->Initialize(title, w, h);
	m_World = new WorldService();
	return true;
}


/// <summary>
///  game loop
/// </summary>
void sky::Engine::Start()
{
	const char* file = "assets/title.png";
	//Load assets
	background_texture_id = m_Graphics->LoadTexture("assets/background.png");
	mario_image_id = m_Graphics->LoadTexture("assets/mario.png");

	font_id = m_Graphics->LoadFont("./assets/mario.ttf",100);
	sample_sound_id = m_Audio->LoadSound("assets/sounds/jump.wav");
	background_music_id = m_Audio->LoadMusic("assets/track1.wav");
	m_Audio->PlayMusic(background_music_id);
	m_Audio->PlaySFX(sample_sound_id, 3);
	
	isRunning = true;
	clock_t _lastTime = clock();
	float MS_PER_FRAME = 1000 / 60;

	//game loop
	while (isRunning)
	{
		const clock_t _start = clock();
		float _dt = (_start - _lastTime) * 0.001f;
		
		ProcessInput();
		
		Update(_dt);
		Render();
		

		//Sleep to cap the fps
		float sleepDuration = _start + MS_PER_FRAME - clock();
		if (sleepDuration >= 0)
		{
			Sleep(static_cast<DWORD>(sleepDuration));
		}
		
			
		_lastTime = _start;
	}
	
	Shutdown();
}

//closes the game
void sky::Engine::Exit()
{
	isRunning = false;
}

/// <summary>
/// manage the inputs
/// </summary>
void sky::Engine::ProcessInput()
{
	m_Input -> Update();
}

void sky::Engine::Update(float dt)
{
	m_World->Update(dt);
		
		if (m_Input->IsKeyDown(EKey::EKEY_1))
		{
			
		}

#if _DEBUG
		if (m_Input->IsKeyDown(EKey::EKEY_ESCAPE))
		{
			isRunning = false;
		}
#endif
	
}

/// <summary>
/// display images in the window
/// </summary>
void sky::Engine::Render()
{
	m_Graphics->SetColor(Color::BLACK);
	//clear the buffer
	m_Graphics->Clear();

	//draw in buffer
	/*m_Graphics->DrawTexture(background_texture_id, Color::WHITE);
	m_Graphics->DrawTexture(mario_image_id, {_tempX, _tempY, 64, 70 }, Color::WHITE);

	m_Graphics->FillRect({ 100, 100, 100, 100 }, Color::BLUEVIOLET);
	m_Graphics->DrawString("Labo 4", font_id, 20.0f, 20.0f, Color::RED);
*/
	m_World->Draw();
	//render buffer
	m_Graphics->Present();
}


/// <summary>
/// free allocated memory
/// </summary>
void sky::Engine::Shutdown()
{
	if (m_World != nullptr)
	{
		m_World->Unload();
		m_World->ClearWorld();
		delete m_World;
	}
	m_Graphics->Shutdown();
	if (m_Audio != nullptr)
	{
		delete m_Audio;
	}
	if (m_Graphics != nullptr)
	{
		delete m_Graphics;
	}
	if (m_Input != nullptr)
	{
		delete m_Input;
	}
	if (m_Logger != nullptr)
	{
		m_Logger->CloseLog();
		delete m_Logger;
	}
	Engine* ptr = &Engine::Get();
	delete ptr;
	
}



