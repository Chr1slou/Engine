#include <Engine.h>
#include <SDL.h>
#include<time.h>
#include <windows.h>
#include <SdlInput.h>
#include <ConsoleLogger.h>
#include <FileLogger.h>
#include "SDLGraphics.h"
#include <SDL_image.h>
#include "vld.h"




static SDL_Texture* _texture = nullptr;
static SDL_Rect rect = { 0 };
static unsigned char const* _keys = nullptr;
static float _tempX = 0;
static float _tempY = 0;
static bool isRunning = false;


/// <summary>
/// init the services
/// </summary>
/// <param name="title"></param>
/// <param name="w"></param>
/// <param name="h"></param>
/// <returns></returns>
bool sky::Engine::Init(const std::string& title, int w, int h)
{
#if _DEBUG
		m_Logger = new ConsoleLogger();
		m_Logger->Write("Wooowww");
#else
	m_Logger = new FileLogger();
#endif
	

	m_Input = new SdlInput();
	m_Graphics = new Graphics();
	m_Graphics->Initialize(title, w, h);
	
	return true;
}


/// <summary>
///  game loop
/// </summary>
void sky::Engine::Start()
{
	const char* file = "assets/title.png";
	//Load texture
	//_texture = m_Graphics->LoadTexture("assets/title.png");
	//_texture = IMG_LoadTexture(_renderer,"assets/title.png");
	//cube dimensions
	rect.x = 0;
	rect.y = 0;
	rect.w = 100;
	rect.h = 100;
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
	
		if (m_Input->IsKeyDown(SDL_SCANCODE_W))
		{
			_tempY -= 200 * dt ;
			
		}
		if (m_Input->IsKeyDown(SDL_SCANCODE_S))
		{
			_tempY += 200 * dt;
		}
		if (m_Input->IsKeyDown(SDL_SCANCODE_A))
		{
			_tempX-= 200 * dt;
		}
		if (m_Input->IsKeyDown(SDL_SCANCODE_D))
		{
			_tempX += 200 * dt;
		}

#if _DEBUG
		if (m_Input->IsKeyDown(SDL_SCANCODE_ESCAPE))
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
	//TODO demo
}


/// <summary>
/// free allocated memory
/// </summary>
void sky::Engine::Shutdown()
{
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
	
}



