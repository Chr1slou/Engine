#pragma once
#include "Sprite.h"
#include <map>

typedef map<string, RectI> FrameMap;


class Atlas : public Sprite
{
public:
	Atlas(Entity* parent) : Sprite(parent) {}
	void AddFrame(const std::string& name, int x, int y, int w, int h);
	void SetFrame(const std::string& name);
protected:
	FrameMap m_SourceFrameMap;
};