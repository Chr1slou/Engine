#include "SdlInput.h"
#include <SDL.h>


SdlInput::SdlInput()
{
}

void SdlInput::Update()
{
	SDL_Event _event;
	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:
			sky::Engine::Exit();
			break;

		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent _buttonDown = _event.button;
			m_MouseStates[_buttonDown.button] = true;
			/*SDL_Log("Button down : %d)", _buttonDown.button);
			SDL_Log("at (%d, %d)", _buttonDown.x, _buttonDown.y);*/
			break;
		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent _buttonUp = _event.button;
			m_MouseStates[_buttonUp.button] = true;
			/*SDL_Log("Button up : %d", _buttonUp.button);
			SDL_Log("at (%d, %d)", _buttonUp.x, _buttonUp.y);*/
			break;

		case SDL_MOUSEMOTION:
			SDL_MouseMotionEvent _motion = _event.motion;
			m_MouseX = _motion.x;
			m_MouseY = _motion.y;
			break;
		case SDL_KEYDOWN:
			m_KeyStates = SDL_GetKeyboardState(nullptr);
			break;
		case SDL_KEYUP:
			m_KeyStates = SDL_GetKeyboardState(nullptr);
			break;



		}
	}
}


/// <summary>
/// checks if the keyboard key is down
/// </summary>
/// <param name="keycode"> id of the key </param>
/// <returns> true if down </returns>
bool SdlInput::IsKeyDown(int keycode)
{
	if (m_KeyStates != nullptr)
	{
		return m_KeyStates[keycode] == 1;
	}
	return false;
}

/// <summary>
/// checks if the mouse button is down
/// </summary>
/// <param name="button"> id of the button </param>
/// <returns> true if down </returns>
bool SdlInput::IsButtonDown(int button)
{
	if (m_MouseStates != nullptr)
	{
		return m_MouseStates[button] == 1;
	}
	return false;
}

/// <summary>
/// put the mouse position in pointers
/// </summary>
/// <param name="x"> position on the x axis </param>
/// <param name="y"> position on the y axis </param>
void SdlInput::GetMousePosition(int* x, int* y)
{
	*x = m_MouseX;
	*y = m_MouseY;
}
