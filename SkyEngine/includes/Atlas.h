#pragma once
#include "Sprite.h"
#include <map>

typedef map<string, RectI> FrameMap;

/// <summary>
/// keeps frames in a map
/// </summary>
class Atlas : public Sprite
{
public:
	Atlas(Entity* parent) : Sprite(parent) {}
	/// <summary>
	/// adds frame in m_SourceFrameMap
	/// </summary>
	/// <param name="name">the key of the frame in the map</param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="w"></param>
	/// <param name="h"></param>
	void AddFrame(const std::string& name, int x, int y, int w, int h);
	/// <summary>
	/// load the frame from the map at the key [name]
	/// </summary>
	/// <param name="name"></param>
	void SetFrame(const std::string& name);
protected:
	FrameMap m_SourceFrameMap;
};