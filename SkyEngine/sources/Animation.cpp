#include "Animation.h"

Animation::~Animation()
{
	m_AnimationsMap.clear();
}

void Animation::InitAnimation(int frameInRows, int frameWidth, int frameHeight)
{
	m_FrameInRows = frameInRows;
	m_FrameWidth = frameWidth;
	m_FrameHeight = frameHeight;

	m_RectSrc.w = m_FrameWidth;
	m_RectSrc.h = m_FrameHeight;
}

void Animation::AddClip(const std::string& name, int start, int count, float delay)
{
	TClip Clip;
	Clip.start = start;
	Clip.count = count;
	Clip.delay = delay;

	m_AnimationsMap.emplace(name, Clip);
}

void Animation::Stop()
{
	m_IsPlaying = false;
}

void Animation::Play(const std::string& name, bool loop)
{
	if (m_AnimationsMap.count(name) > 0)
	{
		m_CurrentClip = m_AnimationsMap[name];
	}
	m_IsLooping = loop;
	m_IsPlaying = true;


	m_RectSrc.x = (m_CurrentClip.start % m_FrameInRows) * m_FrameWidth;
	m_RectSrc.y = (m_CurrentClip.start / m_FrameInRows) * m_FrameHeight;
	m_FrameIndex = m_CurrentClip.start;
}

void Animation::Update(float dt)
{
	if (m_IsPlaying)
	{
		m_ElapsedTime += dt;
		if (m_ElapsedTime >= m_CurrentClip.delay)
		{
			m_ElapsedTime = 0;
			m_FrameIndex++;
			/*if ((m_FrameIndex - m_CurrentClip.start) > m_CurrentClip.count)
			{
				if (m_IsLooping)
				{
					m_FrameIndex = m_CurrentClip.start;
				}
				else
				{
					m_IsPlaying = false;
				}
			}*/
		}
		m_RectSrc.x = (m_FrameIndex % m_FrameInRows) * m_FrameWidth;
		m_RectSrc.y = (m_FrameIndex / m_FrameInRows) * m_FrameHeight;
	}

}