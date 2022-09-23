#include "SDLGraphics.h"
#include <SDL_image.h>



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

bool Graphics::Initialize(const std::string& title, int w, int h)
{
	return false;
}

void Graphics::Shutdown()
{
}

void Graphics::SetColor(const Color& color)
{
}

void Graphics::Clear()
{
}

void Graphics::Present()
{
}

void Graphics::DrawRect(float x, float y, float w, float h, const Color& color)
{
}

void Graphics::DrawRect(const RectF& rect, const Color& color)
{
}

void Graphics::FillRect(float x, float y, float w, float h, const Color& color)
{
}

void Graphics::FillRect(const RectF& rect, const Color& color)
{
}

void Graphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
}

size_t Graphics::LoadTexture(const std::string& filename)
{
	return size_t();
}

void Graphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
}

void Graphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
}

void Graphics::DrawTexture(size_t id, const Color& color)
{
}

void Graphics::GetTextureSize(size_t id, int* w, int* h)
{
}

size_t Graphics::LoadFont(const std::string& filename, int fontSize)
{
	return size_t();
}

void Graphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
}

void Graphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
}
