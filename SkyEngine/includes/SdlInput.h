#pragma once
#include <Engine.h>

/// <summary>
/// input manager
/// </summary>
class SdlInput final : public sky::IInput {
public:
	SdlInput();
	virtual ~SdlInput() = default;
	virtual void Update() override;
	virtual bool IsKeyDown(int keycode) override;
	virtual bool IsButtonDown(int button) override;
	virtual void GetMousePosition(int* x, int* y) override;
private:
	unsigned char const* m_KeyStates = nullptr;
	int m_MouseX = 0;
	int m_MouseY = 0;
	bool m_MouseStates[3]{ false, false, false };
	
};