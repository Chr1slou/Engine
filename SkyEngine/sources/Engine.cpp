#include <Engine.h>
#include <SDL.h>
#include<time.h>
#include <windows.h>
#include <SdlInput.h>
#include <ConsoleLogger.h>
#include <FileLogger.h>


static SDL_Window* _window = nullptr;
static SDL_Renderer* _renderer = nullptr;
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
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		m_Logger->Write( SDL_GetError());
		return false;
	}
	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	uint32_t flags = SDL_WINDOW_TOOLTIP | SDL_WINDOW_RESIZABLE;

	_window = SDL_CreateWindow(title.c_str(), _x, _y, w, h, flags);

	if(!_window)
	{
		m_Logger->Write(SDL_GetError());
		return false;
	}

	flags = SDL_RENDERER_ACCELERATED;

	_renderer = SDL_CreateRenderer(_window, -1, flags);
	if (!_renderer)
	{
		m_Logger->Write(SDL_GetError());
		return false;
	}

	m_Input = new SdlInput();


	
	return true;
}

void sky::Engine::Start()
{

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
			Sleep(sleepDuration);
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
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	rect.x = _tempX;
	rect.y = _tempY;

	SDL_RenderFillRect(_renderer, &rect);
	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(_renderer, 0, 300, 800, 300);
	SDL_RenderPresent(_renderer);
}

void sky::Engine::Shutdown()
{
	if (m_Input != nullptr)
	{
		delete m_Input;
	}
	if (m_Logger != nullptr)
	{
		m_Logger->CloseLog();
		delete m_Logger;
	}
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
