#pragma once

#include <Color.h>
#include <iostream>
#include <map>
#include <Engine.h>
using namespace SkyEngine;
using namespace std;

struct SDL_Texture;
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Window;
typedef struct _TTF_Font TTF_Font;

/// <summary>
/// service provider for the window, textures and font rendering
/// </summary>
class SDLGraphics final : public sky::IGraphics
{
public:

	SDLGraphics();
	virtual ~SDLGraphics();
	//virtual SDL_Texture* LoadTextureTemp(SDL_Renderer* m_Renderer, string filename) override;
	//virtual void RenderTexture(SDL_Renderer* m_Renderer, SDL_Texture* _tex, const SDL_Rect* _src, const SDL_Rect* _dst, const double angle, const SDL_Point* center, int _flip) override;
	

	virtual bool Initialize(const std::string& title, int w, int h) override;
	virtual void Shutdown() override;
	virtual void SetColor(const Color& color) override;
	virtual void SetTextureMode(size_t ID, const Color& color) override;
	virtual void Clear() override;
	virtual void Present() override;
	virtual void DrawRect(float x, float y, float w, float h, const Color& color) override;
	virtual void DrawRect(const RectF& rect, const Color& color) override;
	virtual void FillRect(float x, float y, float w, float h, const Color& color) override;
	virtual void FillRect(const RectF& rect, const Color& color) override;
	virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) override;
	virtual size_t LoadTexture(const std::string& filename) override;
	virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst,
		double angle, const Flip& flip, const Color& color) override;
	virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) override;
	virtual void DrawTexture(size_t id, const Color& color) override;
	virtual void GetTextureSize(size_t id, int* w, int* h) override;
	virtual size_t LoadFont(const std::string& filename, int fontSize) override;
	virtual void LoadTileSet(const std::string& image, int tileW, int tileH, int col, int count);
	virtual void DrawString(const std::string& text, size_t fontId, float x,
		float y, const Color& color) override;
	virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) override;

private:
	SDL_Renderer* m_Renderer = nullptr;
	SDL_Window* m_Window = nullptr;

	map<size_t, SDL_Texture*> m_TextureMapCache;
	map<size_t, TTF_Font*> m_FontMapCache;
};
