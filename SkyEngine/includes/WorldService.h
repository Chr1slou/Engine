#pragma once
#include <vector>
#include <map>
#include <string>
#include "Engine.h"
class Entity;

class WorldService : public sky::IWorld{
public:
	WorldService();
	~WorldService() = default;
	void Add(Entity* entity) override; 
	Entity* Find(const std::string& name);
	void Remove(Entity* entity);
	
private:
	std::vector<Entity*> m_EntityInWorld;
	std::map<std::string, Entity*> m_EntityMap;
};