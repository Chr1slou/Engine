#pragma once
#include <string>
#include "RectI.h"
#include "RectF.h"
#include "Color.h"
#include "Flip.h"
using SkyEngine::Color;

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;
struct SDL_Point;


namespace sky {

	/// <summary>
	/// input interface
	/// </summary>
	class IInput
	{
	public:

		virtual ~IInput() = default;
		virtual bool IsKeyDown(int key) = 0;
		virtual bool IsButtonDown(int button) = 0;
		virtual void GetMousePosition(int* x, int* y) = 0;

	protected:
		friend class Engine;
		virtual void Update() = 0;
	};
	/// <summary>
	/// logger interface
	/// </summary>
	class ILogger
	{
	public:

		virtual ~ILogger() = default;
		virtual void Write(std::string message) = 0;
		virtual void OpenLog() = 0;
		virtual void CloseLog() = 0;
	
	};

	/// <summary>
	/// graphics interface
	/// </summary>
	class IGraphics
	{
	public:
		virtual ~IGraphics() = default;
		//virtual SDL_Texture* LoadTextureTemp(SDL_Renderer* m_Renderer, std::string filename) = 0;
		//virtual void RenderTexture(SDL_Renderer* m_Renderer, SDL_Texture* _tex, const SDL_Rect* _src, const SDL_Rect* _dst, const double angle, const SDL_Point* center, int _flip) = 0;



		virtual bool Initialize(const std::string& title, int w, int h) = 0;
		virtual void Shutdown() = 0;
		virtual void SetColor(const Color& color) = 0;
		virtual void SetTextureMode(size_t ID, const Color& color) = 0;
		virtual void Clear() = 0;
		virtual void Present() = 0;
		virtual void DrawRect(float x, float y, float w, float h, const Color& color) = 0;
		virtual void DrawRect(const RectF& rect, const Color& color) = 0;
		virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0;
		virtual void FillRect(const RectF& rect, const Color& color) = 0;
		virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0;
		virtual size_t LoadTexture(const std::string& filename) = 0;
		virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst,
			double angle, const Flip& flip, const Color& color) = 0;
		virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0;
		virtual void DrawTexture(size_t id, const Color& color) = 0;
		virtual void GetTextureSize(size_t id, int* w, int* h) = 0;
		virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
		virtual void DrawString(const std::string& text, size_t fontId, float x,
			float y, const Color& color) = 0;
		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
	};

	/// <summary>
	/// audio interface
	/// </summary>
	class IAudio
	{
	public:

		virtual ~IAudio() = default;
		virtual size_t LoadMusic(const std::string& filename) = 0;
		virtual size_t LoadSound(const std::string& filename) = 0;
		virtual void PlayMusic(size_t id) = 0;
		virtual void PlayMusic(size_t id, int loop) = 0;
		virtual void PlaySFX(size_t id) = 0;
		virtual void PlaySFX(size_t id, int loop) = 0;
		virtual void PauseMusic() = 0;
		virtual void StopMusic() = 0;
		virtual void ResumeMusic() = 0;
		virtual void SetVolume(int volume) = 0;
		virtual void SetVolume(size_t soundId, int volume) = 0;

	};
	
	/// <summary>
	/// class which manages the element to create the game
	/// </summary>
	class Engine final {
	public:
		static Engine& Get()
		{
			static Engine _instance;
			return _instance;
		}

		bool Init(const std::string& title, int w, int h);
		void Start();
		static void Exit();
		IInput& Input() const { return *m_Input; }
		ILogger& Logger() const { return *m_Logger; }

	private:
		void ProcessInput();
		void Update(float dt);
		void Render();
		void Shutdown();
	private:
		bool m_IsRunning = false;
		bool m_IsInit = false;

		IInput* m_Input = nullptr;
		ILogger* m_Logger = nullptr;
		IGraphics* m_Graphics = nullptr;
		IAudio* m_Audio = nullptr;
	};

	

	

}