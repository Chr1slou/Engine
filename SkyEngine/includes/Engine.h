#pragma once
#include <string>
#include "RectI.h"
#include "RectF.h"
#include "Color.h"
#include "Flip.h"
#include"EKey.h"
#include <vector>
using SkyEngine::Color;


class Entity;
typedef std::vector<std::vector<int>> TTilemapLayer;

namespace sky {

	typedef struct
	{
		float X;
		float Y;
	}Vector2;


	/// <summary>
	/// input interface
	/// </summary>
	/// 
	class IInput
	{
	public:

		virtual ~IInput() = default;
		virtual bool IsKeyDown(EKey key) = 0;
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
	/// interface for updatable components
	/// </summary>
	class IUpdatable
	{
	public:
		virtual ~IUpdatable() = default;
		virtual void Update(float dt) = 0;
	};

	

	/// <summary>
	/// graphics interface
	/// </summary>
	class IGraphics
	{
	public:
		virtual ~IGraphics() = default;



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
			double angle, const SkyEngine::Flip& flip, const Color& color) = 0;
		virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0;
		virtual void DrawTexture(size_t id, const Color& color) = 0;
		virtual void GetTextureSize(size_t id, int* w, int* h) = 0;
		virtual void LoadTileSet(const std::string& image, int tileW, int tileH, int col, int count) = 0;
		virtual size_t LoadFont(const std::string& filename, int fontSize) = 0;
		virtual void DrawString(const std::string& text, size_t fontId, float x,
			float y, const Color& color) = 0;
		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0;
		virtual void RenderFrame() = 0;
		virtual void DrawTiles(int tileW, int tileH) = 0;
		virtual void LoadTileMap(const std::string& text, const std::string& layerName) = 0;
		virtual void AddLayer(const std::string& layerName, TTilemapLayer layer) = 0;
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
	/// load the entities
	/// </summary>
	class IScene {
	public:
		virtual ~IScene() = default;
		virtual void Load() = 0;
		virtual void SetName(const std::string& sceneName) = 0;
		std::string& GetName() { return m_Name; }

	protected:
		std::string m_Name;
		//TODO rajouter un name et un getname
	};

	class IWorld
	{
	public:

		virtual ~IWorld() = default;
		virtual Entity* Find(const std::string& name) = 0;
		virtual void Add(Entity* entity) = 0;
		virtual Entity* Create(std::string name) = 0;
		virtual void Draw() = 0;
		virtual void Update(float dt) = 0;
		virtual void Remove(Entity* entity) = 0;
		virtual void Load(const std::string& scene) = 0;
		virtual void Unload() = 0;
		virtual void Register(const std::string& name, IScene* scene) = 0;
		virtual void UnRegister(const std::string& name) = 0;
		virtual void ClearWorld() = 0;
	};


	
	/// <summary>
	/// class which manages the element to create the game
	/// </summary>
	class Engine final {
	public:
		static Engine& Get()
		{
			static Engine* _instance;
			if(_instance == nullptr)
			{
				_instance = new Engine();
			}
			return *_instance;
		}

		bool Init(const std::string& title, int w, int h);
		void Start();
		static void Exit();
		IInput& Input() const { return *m_Input; }
		ILogger& Logger() const { return *m_Logger; }
		IWorld& World() const { return *m_World; }
		IGraphics& Graphics() const { return *m_Graphics;}

	private:
		Engine()
		{

		}

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
		IWorld* m_World = nullptr;
	};

	/// <summary>
	/// interface for drawable components
	/// </summary>
	class IDrawable
	{
	public:
		virtual ~IDrawable() = default;
		virtual void Draw() = 0;
	protected:
		IGraphics& m_GraphicService = Engine::Get().Graphics();
	};

	

}