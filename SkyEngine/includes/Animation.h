#pragma once
#include "Atlas.h"
#include <Engine.h>

using namespace sky;




class Animation : public Atlas, public IUpdatable
{
public:
	Animation(Entity* parent) : Atlas(parent) {}
	virtual ~Animation();
	void InitAnimation(int frameInRows, int frameWidth, int frameHeight);
	void AddClip(const std::string& name, int start, int count, float delay);
	void Stop();
	void Play(const std::string& name, bool loop);
	virtual void Update(float dt) override;
private:
	 struct TClip{
		int start = 0;
		int count = 0;
		float delay = 0.0f;
	 };
	typedef map<string, TClip> TClipsMap;
	TClipsMap m_AnimationsMap;
	TClip m_CurrentClip;
	float m_ElapsedTime = 0.0f;
	bool m_IsPlaying = false;;
	bool m_IsLooping = false;
	int m_FrameInRows = 0;
	int m_FrameWidth = 0;
	int m_FrameHeight = 0;
	int m_FrameIndex = 0;

	
};