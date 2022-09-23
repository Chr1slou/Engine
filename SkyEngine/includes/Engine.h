#pragma once
#include <string>

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;
struct SDL_Point;


namespace sky {
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

	class ILogger
	{
	public:

		virtual ~ILogger() = default;
		virtual void Write(std::string message) = 0;
		virtual void OpenLog() = 0;
		virtual void CloseLog() = 0;
	
	};


	class IGraphics
	{
	public:
		virtual ~IGraphics() = default;
		virtual SDL_Texture* LoadTexture(SDL_Renderer* m_Renderer, std::string filename) = 0;
		virtual void RenderTexture(SDL_Renderer* m_Renderer, SDL_Texture* _tex, const SDL_Rect* _src, const SDL_Rect* _dst, const double angle, const SDL_Point* center, int _flip) = 0;

	};

	class Engine final {
	public:
		bool Init(const std::string& title, int w, int h);
		void Start();
		IInput& Input() const { return *m_Input; }
		static void Exit();

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

	};

	

	

}