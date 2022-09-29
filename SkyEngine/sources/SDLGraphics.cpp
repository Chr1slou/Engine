#include "SDLGraphics.h"
#include <SDL_image.h>
#include <RectF.h>
#include <Vector>
#include <SDL_ttf.h>

using std::vector;

struct SDL_Texture* g_TextureBuffer;

SDLGraphics::SDLGraphics()
	:m_Renderer(nullptr), m_Window(nullptr)
{
}

SDLGraphics::~SDLGraphics()
{
}



//SDL_Texture* SDLGraphics::LoadTextureTemp(SDL_Renderer* m_Renderer, string filename)
//{
//	
//	SDL_Texture* _texture = IMG_LoadTexture(m_Renderer, filename.c_str());
//	return _texture;
//}
//
//void SDLGraphics::RenderTexture(SDL_Renderer* m_Renderer, SDL_Texture* _tex, const SDL_Rect* _src, const SDL_Rect* _dst, const double angle, const SDL_Point* center, int _flip)
//{
//	SDL_RenderCopyEx(m_Renderer, _tex, _src, _dst, angle, nullptr, SDL_FLIP_NONE);
//}


/// <summary>
/// Init SDL, Window, font
/// </summary>
/// <param name="title"> title of the window</param>
/// <param name="w"> width of the window </param>
/// <param name="h"> heigth of the window</param>
/// <returns></returns>
bool SDLGraphics::Initialize(const std::string& title, int w, int h)
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

	//TTF_Init();
	return false;
}

/// <summary>
/// called when the game loop is over to destroy the objects
/// </summary>
void SDLGraphics::Shutdown()
{
	//TTF_Quit();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

/// <summary>
/// set the color ofter the next draws
/// </summary>
/// <param name="color"></param>
void SDLGraphics::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer, color.red, color.green, color.blue, color.alpha);
}

/// <summary>
/// apply color, alpha and set blend mode
/// </summary>
/// <param name="ID"> the id of the texture we want to configure </param>
/// <param name="color"> the color you want to apply </param>
void SDLGraphics::SetTextureMode(size_t ID, const Color& color)
{
	SDL_Texture* _texture= m_TextureMapCache[ID];
	
	SDL_SetTextureColorMod(_texture, color.red, color.green, color.blue);
	SDL_SetTextureAlphaMod(_texture, color.alpha);
	SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
}

/// <summary>
/// clear the buffer
/// </summary>
void SDLGraphics::Clear()
{
	SDL_RenderClear(m_Renderer);
}


/// <summary>
/// render the image in buffer
/// </summary>
void SDLGraphics::Present()
{
	SDL_RenderPresent(m_Renderer);
}


/// <summary>
/// draw an empty rectangle providing its position and dimensions and color
/// </summary>
/// <param name="x"> position on the x axis</param>
/// <param name="y"> position on the y axis</param>
/// <param name="w"> width of the rectangle </param>
/// <param name="h"> height of the rectangle</param>
/// <param name="color"> color of the lines of the rectangle </param>
void SDLGraphics::DrawRect(float x, float y, float w, float h, const Color& color)
{
	SetColor(color);
	SDL_Rect _Rect = { static_cast<int> (x), static_cast<int> (y), static_cast<int> (w), static_cast<int> (h)};
	
	SDL_RenderDrawRect(m_Renderer, &_Rect);
}

/// <summary>
/// draw an empty rectangle providing a rect and color
/// </summary>
/// <param name="rect"> struct of 4 floats x,y,w,h </param>
/// <param name="color">color of the lines of the rectangle</param>
void SDLGraphics::DrawRect(const RectF& rect, const Color& color)
{
	DrawRect(rect.x, rect.y, rect.w, rect.h, color);
}


/// <summary>
/// draw a filled rectangle providing providing its position and dimensions and color
/// </summary>
/// <param name="x"> position on the x axis </param>
/// <param name="y"> position on the y axis </param>
/// <param name="w"> width of the rectangle</param>
/// <param name="h"> height of the rectangle</param>
/// <param name="color"> color of the lines of the rectangle </param>
void SDLGraphics::FillRect(float x, float y, float w, float h, const Color& color)
{
	SetColor(color);
	SDL_Rect _Rect = { static_cast<int> (x), static_cast<int> (y), static_cast<int> (w), static_cast<int> (h)};

	SDL_RenderFillRect(m_Renderer, &_Rect);

}


/// <summary>
/// draw a filled rectangle providing a rect and color
/// </summary>
/// <param name="rect">  struct of 4 floats x,y,w,h </param>
/// <param name="color">color of the lines of the rectangle</param>
void SDLGraphics::FillRect(const RectF& rect, const Color& color)
{
	FillRect(rect.x, rect.y, rect.w, rect.h, color);
}


/// <summary>
/// draw a line providing its start/end positions and color
/// </summary>
/// <param name="rect">  struct of 4 floats x,y,w,h </param>
/// <param name="color">color of the lines of the rectangle</param>
void SDLGraphics::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
	SetColor(color);
	vector<int> _Vect = { static_cast<int> (x1), static_cast<int> (y1), static_cast<int> (x2), static_cast<int> (y2)};

	SDL_RenderDrawLine(m_Renderer, _Vect[0], _Vect[1], _Vect[2], _Vect[3]);
}


/// <summary>
/// load new texture
/// put in in a map
/// return id of existing texture in cache
/// </summary>
/// <param name="filename"> path of the texture</param>
/// <returns></returns>
size_t SDLGraphics::LoadTexture(const std::string& filename)
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


/// <summary>
/// draw part of the texture in a rect, in the buffer
/// </summary>
/// <param name="id"> id of the texture in the cache </param>
/// <param name="src"> struct of 4 ints defining the part of the texture to draw</param>
/// <param name="dst"> struct of 4 floats defining where to draw the texture </param>
/// <param name="angle"> rotation of the texture in degrees </param>
/// <param name="flip"> struct of 2 bools h (horizontal), v (vertical) to set the sdl_Flip of the texture </param>
/// <param name="color"> color parameters to apply on the texture </param>
void SDLGraphics::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
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
	SetTextureMode(id, color);
	SDL_RenderCopyEx(m_Renderer, _texture, &_src, &_dst, angle, nullptr, _flip);
}


/// <summary>
/// draw the entire texture in a rect, no flip, in the buffer
/// </summary>
/// <param name="id"> id of the texture in the cache </param>
/// <param name="dst"> struct of 4 floats defining where to draw the texture </param>
///  <param name="color"> color parameters to apply on the texture </param>
void SDLGraphics::DrawTexture(size_t id, const RectF& dst, const Color& color)
{

	SDL_Rect _dst = { static_cast<int> (dst.x), static_cast<int> (dst.y), static_cast<int> (dst.w), static_cast<int> (dst.h) };
	SDL_Texture* _texture = m_TextureMapCache[id];

	SetTextureMode(id, color);
	SDL_RenderCopyEx(m_Renderer, _texture, nullptr, &_dst, 0.0, nullptr, SDL_FLIP_NONE);

}


/// <summary>
/// draw the entire texture in the whole window, no flip, in the buffer
/// </summary>
/// <param name="id"></param>
/// <param name="color"></param>
void SDLGraphics::DrawTexture(size_t id, const Color& color)
{
	SetTextureMode(id, color);
	SDL_RenderCopyEx(m_Renderer, m_TextureMapCache[id], nullptr, nullptr, 0.0, nullptr, SDL_FLIP_NONE);
}


/// <summary>
/// put the size of the picture in pointers
/// </summary>
/// <param name="id"> id of the texture in the cache </param>
/// <param name="w"> pointer where to store the width of the texture </param>
/// <param name="h"> pointer where to store the height of the texture</param>
void SDLGraphics::GetTextureSize(size_t id, int* w, int* h)
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


/// <summary>
/// load new font
/// put in in a map
/// returns id of existing font in cache
/// </summary>
/// <param name="filename"></param>
/// <param name="fontSize"></param>
/// <returns></returns>
size_t SDLGraphics::LoadFont(const std::string& filename, int fontSize)
{

	//const size_t _fontId = std::hash<std::string>()(filename);
	//if (m_TextureMapCache.count(_fontId) != 0)
	//{
	//	return _fontId;
	//}
	//TTF_Font* _font = TTF_OpenFont(filename.c_str(), fontSize);
	//if (_font != nullptr)
	//{
	//	m_FontMapCache[_fontId] = _font;
	//	return _fontId;
	//}
	return -1;
}


/// <summary>
/// render a string on screen
/// </summary>
/// <param name="text"> text to draw </param>
/// <param name="fontId"> id of the font in cache </param>
/// <param name="x"> position on x axis </param>
/// <param name="y">position on y axis </param>
/// <param name="color"> color of the font </param>
void SDLGraphics::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
	/*if (m_FontMapCache.count(fontId) > 0)
	{
		TTF_Font* _font = m_FontMapCache[fontId];
		const SDL_Color _color = {static_cast<Uint8>(color.red), static_cast<Uint8>(color.green),static_cast<Uint8>(color.blue),static_cast<Uint8>(color.alpha)};

		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), static_cast<SDL_Color>(_color));
		SDL_Rect _dst = { static_cast<int> (x), static_cast<int> (y), static_cast<int> (_surface->w), static_cast<int> (_surface->h) };
		g_TextureBuffer = SDL_CreateTextureFromSurface(m_Renderer, _surface);
		SDL_RenderCopy(m_Renderer, g_TextureBuffer, nullptr, &_dst);
		SDL_FreeSurface(_surface);
	}*/

}


/// <summary>
/// put the size of the text in pointers
/// </summary>
/// <param name="text"> the text to display </param>
/// <param name="fontId"> id of the font in the cache</param>
/// <param name="w">pointer where to store the width of the text </param>
/// <param name="h">pointer where to store the height of the text </param>
void SDLGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
	/*if (m_FontMapCache.count(fontId) > 0)
	{
		TTF_Font* _font = m_FontMapCache[fontId];
		TTF_SizeText(_font, text.c_str(), w, h);
		
	}
	else
	{
		*w = 0;
		*h = 0;
	}*/
}
