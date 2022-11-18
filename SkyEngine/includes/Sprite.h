#pragma once
#include <Component.h>
#include <Engine.h>

using namespace std;
using namespace sky;


/// <summary>
/// drawable class to draw a texture or a part of a texture
/// </summary>
class Sprite : public Component, public IDrawable
{
public:
	Sprite(Entity* parent) : Component(parent) {}
	/// <summary>
	/// draws the set texture
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// loads the texture from assets folder
	/// </summary>
	/// <param name="filename"></param>
	void SetTexture(string filename);

	/// <summary>
	/// sets the rotation of the image
	/// </summary>
	/// <param name="angle"> in degrees</param>
	void Rotate(double angle);

	/// <summary>
	/// flips the image from a flip struct
	/// </summary>
	/// <param name="flip"> struct {bool horizontal flip, bool vertical flip}</param>
	void Flip(SkyEngine::Flip flip);

	/// <summary>
	/// flips giving 2 bools
	/// </summary>
	/// <param name="h">horizontal</param>
	/// <param name="v">vertical</param>
	void SetFlip(bool h, bool v);

	/// <summary>
	/// sets the color
	/// </summary>
	/// <param name="color"></param>
	void SetColor(SkyEngine::Color color);

	/// <summary>
	/// set the source rect of the image
	/// </summary>
	/// <param name="w"></param>
	/// <param name="h"></param>
	void SetSrc(int w, int h);

	/// <summary>
	/// set the destination of the image in pixels
	/// </summary>
	/// <param name="w">width on screen</param>
	/// <param name="h">height on screen</param>
	void SetDst(float w, float h);

	/// <summary>
	/// returns the dimensions of the sprite on screen
	/// </summary>
	/// <returns>RectF</returns>
	RectF GetDst();
	/// <summary>
	/// sets sources from a RectI
	/// </summary>
	/// <param name="source">RectI</param>
	void LoadSource(RectI source);

protected:
	RectI m_RectSrc = { 0, 0, 0, 0 };
	size_t m_TextureID = 0;
	RectF m_RectDst = { 0.0f, 0.0f, 0.0f, 0.0f };
	double m_Angle = 0;
	SkyEngine::Flip m_Flip = { false, false };
	SkyEngine::Color m_Color = Color::WHITE;
};
