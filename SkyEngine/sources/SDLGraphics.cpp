#include "SDLGraphics.h"
#include <SDL_image.h>
#include <RectF.h>
#include <Vector>

using std::vector;


Graphics::Graphics()
	:m_Renderer(nullptr)
{
}

Graphics::~Graphics()
{
}



SDL_Texture* Graphics::LoadTextureTemp(SDL_Renderer* m_Renderer, string filename)
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
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		sky::Engine::Get().Logger().Write(SDL_GetError());
		return false;
	}
	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;
	uint32_t flags = SDL_WINDOW_TOOLTIP | SDL_WINDOW_RESIZABLE;

	m_Window = SDL_CreateWindow(title.c_str(), _x, _y, w, h, flags);

	if (!m_Window)
	{
		sky::Engine::Get().Logger().Write(SDL_GetError());
		return false;
	}

	flags = SDL_RENDERER_ACCELERATED;

	m_Renderer = SDL_CreateRenderer(m_Window, -1, flags);
	if (!m_Renderer)
	{
		sky::Engine::Get().Logger().Write(SDL_GetError());
		return false;
	}
	return false;
}

void Graphics::Shutdown()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

void Graphics::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer, color.red, color.green, color.blue, color.alpha);

}

void Graphics::SetTextureMode(size_t ID, const Color& color)
{
	SDL_Texture* _texture= m_TextureMapCache[ID];
	
	SDL_SetTextureColorMod(_texture, color.red, color.green, color.blue);
	SDL_SetTextureAlphaMod(_texture, color.alpha);
	SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
}

void Graphics::Clear()
{
	SDL_RenderClear(m_Renderer);
}

void Graphics::Present()
{
	SDL_RenderPresent(m_Renderer);
}

void Graphics::DrawRect(float x, float y, float w, float h, const Color& color)
{
	SetColor(color);
	SDL_Rect _Rect = { static_cast<int> (x), static_cast<int> (y), static_cast<int> (w), static_cast<int> (h)};
	
	SDL_RenderDrawRect(m_Renderer, &_Rect);
}

void Graphics::DrawRect(const RectF& rect, const Color& color)
{
	DrawRect(rect.x, rect.y, rect.w, rect.h, color);
}

void Graphics::FillRect(float x, float y, float w, float h, const Color& color)
{
	SetColor(color);
	SDL_Rect _Rect = { static_cast<int> (x), static_cast<int> (y), static_cast<int> (w), static_cast<int> (h)};

	SDL_RenderFillRect(m_Renderer, &_Rect);

}

void Graphics::FillRect(const RectF& rect, const Color& color)
{
	FillRect(rect.x, rect.y, rect.w, rect.h, color);
}

void Graphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
	SetColor(color);
	vector<int> _Vect = { static_cast<int> (x1), static_cast<int> (y1), static_cast<int> (x2), static_cast<int> (y2)};

	SDL_RenderDrawLine(m_Renderer, _Vect[0], _Vect[1], _Vect[2], _Vect[3]);
}

size_t Graphics::LoadTexture(const std::string& filename)
{
	const size_t _textureId = std::hash<std::string>()(filename);
	if (m_TextureMapCache.count(_textureId) != 0)
	{
		return _textureId;
	}
	SDL_Texture* _texture = IMG_LoadTexture(m_Renderer, filename.c_str());
	if (_texture != nullptr)
	{
		m_TextureMapCache[_textureId] = _texture;
		return _textureId;
	}
	return -1;
}

void Graphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
	SDL_Rect _src = { src.x, src.y, src.w, src.h};
	SDL_Rect _dst = { static_cast<int> (dst.x), static_cast<int> (dst.y), static_cast<int> (dst.w), static_cast<int> (dst.h) };

	SDL_Texture* _texture = m_TextureMapCache[id];

	SDL_RendererFlip _flip = SDL_FLIP_NONE;
	if (flip.h == true && flip.v == false)
	{
		_flip = SDL_FLIP_HORIZONTAL;
	}
	else if (flip.h == false && flip.v == true)
	{
		_flip = SDL_FLIP_VERTICAL;
	}
	else if (flip.h == true && flip.v == true)
	{
		_flip = static_cast<SDL_RendererFlip> (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
	}
	
	SDL_RenderCopyEx(m_Renderer, _texture, &_src, &_dst, angle, nullptr, _flip);
}

void Graphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
}

void Graphics::DrawTexture(size_t id, const Color& color)
{
}

void Graphics::GetTextureSize(size_t id, int* w, int* h)
{
	if (m_TextureMapCache.count(id) > 0)
	{
		SDL_Texture* _tex = m_TextureMapCache[id];
		SDL_QueryTexture(_tex, nullptr, nullptr, w, h);
	}
	else
	{
		*w = 0;
		*h = 0;
	}

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
