#pragma once
#include <Engine.h>
#include "vld.h"
#include <iostream>

using namespace std;
struct SDL_Texture;

class Graphics final : public sky::IGraphics
{
public:

	Graphics();
	virtual ~Graphics();
	virtual SDL_Texture* LoadTexture(SDL_Renderer* m_Renderer, string filename) override;
	virtual void RenderTexture(SDL_Renderer* m_Renderer, SDL_Texture* _tex, const SDL_Rect* _src, const SDL_Rect* _dst, const double angle, const SDL_Point* center, int _flip) override;
};
