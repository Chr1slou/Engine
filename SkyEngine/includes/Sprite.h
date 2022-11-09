#pragma once
#include <Component.h>
#include <Engine.h>

using namespace std;
using namespace sky;

class Sprite : public Component, public IDrawable
{
public:
	Sprite(Entity* parent) : Component(parent) {}
	virtual void Draw() override;

	void SetTexture(string filename);
	void Rotate(double angle);
	void Flip(SkyEngine::Flip flip);
	void SetColor(SkyEngine::Color color);
	void SetSrc(int w, int h);
	void SetDst(float w, float h);

	RectF GetDst();
	void LoadSource(RectI source);

protected:
	RectI m_RectSrc = { 0, 0, 0, 0 };
	size_t m_TextureID = 0;
	RectF m_RectDst = { 0.0f, 0.0f, 0.0f, 0.0f };
	double m_Angle = 0;
	SkyEngine::Flip m_Flip = { false, false };
	SkyEngine::Color m_Color = Color::WHITE;
};
