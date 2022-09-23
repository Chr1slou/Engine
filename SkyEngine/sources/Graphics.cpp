#include "Graphics.h"
#include <SDL_image.h>

struct SDL_Texture;

Graphics::Graphics()
{
}

Graphics::~Graphics()
{
}

SDL_Texture* Graphics::LoadTexture(SDL_Renderer* m_Renderer, string filename)
{
	SDL_Texture* _texture = IMG_LoadTexture(m_Renderer, filename.c_str());
	return _texture;
}

void Graphics::RenderTexture(SDL_Renderer* m_Renderer, SDL_Texture* _tex, const SDL_Rect* _src, const SDL_Rect* _dst, const double angle, const SDL_Point* center, int _flip)
{
	SDL_RenderCopyEx(m_Renderer, _tex, _src, _dst, angle, nullptr, SDL_FLIP_NONE);
}
