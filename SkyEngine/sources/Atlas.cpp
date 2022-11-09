#include "Atlas.h"

void Atlas::AddFrame(const std::string& name, int x, int y, int w, int h)
{
	RectI RectSrc = { x, y, w, h };
	if (m_SourceFrameMap.count(name) > 0)
	{
		Engine::Get().Logger().Write("Frame already in map");
		return;
	}
	m_SourceFrameMap.emplace(name, RectSrc);
}

void Atlas::SetFrame(const std::string& name)
{
	if (m_SourceFrameMap.count(name) == 0)
	{
		Engine::Get().Logger().Write("Frame not in map");
		return;
	}
	LoadSource(m_SourceFrameMap[name]);
}
