#include "Sprite.h"
#include "Entity.h"

void Sprite::Draw()
{
	m_RectDst.x = m_Parent->GetPosition().X;
	m_RectDst.y = m_Parent->GetPosition().Y;

	//vérifier si le sandbox fonctionne
	m_GraphicService.DrawTexture(m_TextureID, m_RectSrc, m_RectDst, m_Angle, m_Flip, m_Color);
}

void Sprite::SetTexture(string filename)
{
	m_TextureID = Engine::Get().Graphics().LoadTexture(filename);
}

void Sprite::Rotate(double angle)
{
	m_Angle = angle;
}

void Sprite::Flip(SkyEngine::Flip flip)
{
	m_Flip = flip;
}

void Sprite::SetColor(SkyEngine::Color color)
{
	m_Color = color;
}

void Sprite::SetSrc(int w, int h)
{
	m_RectSrc.w = w;
	m_RectSrc.h = h;
	
}

void Sprite::SetDst(float w, float h)
{
	m_RectDst.w = w;
	m_RectDst.h = h;
}

RectF Sprite::GetDst()
{
	return m_RectDst;
}

void Sprite::LoadSource(RectI source)
{
	m_RectSrc = source;
}
