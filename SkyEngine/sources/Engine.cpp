#include <Engine.h>
#include <SDL.h>
#include<time.h>
#include <windows.h>

static SDL_Window* _window = nullptr;
static SDL_Renderer* _renderer = nullptr;
static SDL_Rect rect = { 0 };
static unsigned char const* _keys = nullptr;
static float _tempX = 0;
static float _tempY = 0;

bool sky::Engine::Init(const std::string& title, int w, int h)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log(SDL_GetError());
		return false;
	}
	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	uint32_t flags = SDL_WINDOW_TOOLTIP | SDL_WINDOW_RESIZABLE;

	_window = SDL_CreateWindow(title.c_str(), _x, _y, w, h, flags);

	if(!_window)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	flags = SDL_RENDERER_ACCELERATED;

	_renderer = SDL_CreateRenderer(_window, -1, flags);
	if (!_renderer)
	{
		SDL_Log(SDL_GetError());
		return false;
	}
	return true;
}

void sky::Engine::Start()
{
	rect.x = 0;
	rect.y = 0;
	rect.w = 100;
	rect.h = 100;
	m_IsRunning = true;
	clock_t _lastTime = clock();
	float MS_PER_FRAME = 1000 / 60;
	while (m_IsRunning) 
	{
		const clock_t _start = clock();
		float _dt = (_start - _lastTime) * 0.001f;
		
		ProcessInput();
		
		Update(_dt);
		Render();
		if(m_IsRunning)
			Sleep(_start + MS_PER_FRAME - clock());
		_lastTime = _start;
	}
	
	Shutdown();
}

void sky::Engine::Exit()
{
	m_IsRunning = false;
}

void sky::Engine::ProcessInput()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
			case SDL_QUIT:
				Exit();

			case SDL_MOUSEBUTTONDOWN:
				SDL_MouseButtonEvent _buttonDown = _event.button;
				SDL_Log("Button down : %d)", _buttonDown.button);
				SDL_Log("at (%d, %d)", _buttonDown.x, _buttonDown.y);
				break;
			case SDL_MOUSEBUTTONUP:
				SDL_MouseButtonEvent _buttonUp = _event.button;
				SDL_Log("Button up : %d", _buttonUp.button);
				SDL_Log("at (%d, %d)", _buttonUp.x, _buttonUp.y);
				break;
			case SDL_KEYDOWN :
				_keys = SDL_GetKeyboardState(nullptr);
				break;
			case SDL_KEYUP:
				_keys = SDL_GetKeyboardState(nullptr);
				break;
			
			
		}
	}
}

void sky::Engine::Update(float dt)
{
	if (_keys != nullptr)
	{
		if (_keys[SDL_SCANCODE_W])
		{
			_tempY -= 200 * dt ;
		}
		if (_keys[SDL_SCANCODE_S])
		{
			_tempY += 200 * dt;
		}
		if (_keys[SDL_SCANCODE_A])
		{
			_tempX-= 200 * dt;
		}
		if (_keys[SDL_SCANCODE_D])
		{
			_tempX += 200 * dt;
		}
	}
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
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
