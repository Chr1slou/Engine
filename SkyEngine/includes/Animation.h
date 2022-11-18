#pragma once
#include "Atlas.h"
#include <Engine.h>

using namespace sky;



/// <summary>
/// creates an animation
/// </summary>
class Animation : public Atlas, public IUpdatable
{
public:
	Animation(Entity* parent) : Atlas(parent) {}
	virtual ~Animation();
	/// <summary>
	/// set the parameters of the frames
	/// </summary>
	/// <param name="frameInRows"></param>
	/// <param name="frameWidth"></param>
	/// <param name="frameHeight"></param>
	virtual void InitAnimation(int frameInRows, int frameWidth, int frameHeight);

	/// <summary>
	/// creates a clips
	/// </summary>
	/// <param name="name"> name of the clip</param>
	/// <param name="start"> index of first frame</param>
	/// <param name="count"> number of frame</param>
	/// <param name="delay"> time between frames</param>
	virtual void AddClip(const std::string& name, int start, int count, float delay);
	/// <summary>
	/// stop the animation
	/// </summary>
	virtual void Stop();

	/// <summary>
	/// start the animation
	/// </summary>
	/// <param name="name"> name of the anim</param>
	/// <param name="loop"> set loop</param>
	virtual void Play(const std::string& name, bool loop);

	/// <summary>
	/// changes sources of the frame from the texture
	/// </summary>
	/// <param name="dt"></param>
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