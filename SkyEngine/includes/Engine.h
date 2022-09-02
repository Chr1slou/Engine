#pragma once
#include <string>


namespace sky {
	class Engine final {
	public:
		bool Init(const std::string& title, int w, int h);
		void Start();
		void Exit();

	private:
		void ProcessInput();
		void Update(float dt);
		void Render();
		void Shutdown();

	private:
		bool m_IsRunning = false;
		bool m_IsInit = false;
		
		
	};
}