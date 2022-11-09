#pragma once
#include "Sprite.h"
#include <map>

class Atlas : public Sprite
{
public:
	Atlas(Entity* parent) : Sprite(parent) {}
	void AddFrame(const std::string& name, int x, int y, int w, int h);
	void SetFrame(const std::string& name);
private:
	map<string, RectI> m_SourceFrameMap;
};