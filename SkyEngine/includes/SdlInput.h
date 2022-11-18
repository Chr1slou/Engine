#pragma once
#include <Engine.h>
#include <EKey.h>

/// <summary>
/// input manager
/// </summary>
class SdlInput final : public sky::IInput {
public:
	SdlInput();
	virtual ~SdlInput() = default;
	virtual void Update() override;
	/// <summary>
/// checks if the keyboard key is down
/// </summary>
/// <param name="keycode"> id of the key </param>
/// <returns> true if down </returns>
	virtual bool IsKeyDown(sky::EKey keycode) override;
	/// <summary>
/// checks if the mouse button is down
/// </summary>
/// <param name="button"> id of the button </param>
/// <returns> true if down </returns>
	virtual bool IsButtonDown(int button) override;

	/// <summary>
/// put the mouse position in pointers
/// </summary>
/// <param name="x"> position on the x axis </param>
/// <param name="y"> position on the y axis </param>
	virtual void GetMousePosition(int* x, int* y) override;
private:
	unsigned char const* m_KeyStates = nullptr;
	int m_MouseX = 0;
	int m_MouseY = 0;
	bool m_MouseStates[3]{ false, false, false };
	
};