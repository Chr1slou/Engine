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

void sky::Engine::Render()
{
	//SDL_Rect rect = { 0, 0, 200, 200 };
	//IGraphics render

	/*SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	m_Graphics->RenderTexture(m_Renderer, _texture, nullptr, nullptr, 0, nullptr, SDL_FLIP_NONE);
	SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);
	rect.x = static_cast<int>(_tempX);
	rect.y = static_cast<int>(_tempY);

	SDL_SetRenderDrawColor(m_Renderer, 0, 255, 0, 255);
	
	

	SDL_RenderCopyEx(m_Renderer, _texture, nullptr, nullptr, 0.0, nullptr, SDL_FLIP_NONE);
	*/
}

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



