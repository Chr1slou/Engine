#pragma once
#include <vector>
#include <map>
#include <string>
#include "Engine.h"

class Entity;

using namespace sky;

class WorldService : public IWorld{
public:
	WorldService();
	~WorldService() = default;
	void Add(Entity* entity) override; 
	Entity* Find(const std::string& name) override;
	void Draw() override;
	void Update(float dt) override;
	void Remove(Entity* entity) override;
	Entity* Create(std::string name) override;
	void Load(const std::string& scene) override;
	void Unload() override;
	void Register(const std::string& name, IScene* scene) override;
	virtual void UnRegister(const std::string& name) override;
	void ClearWorld() override;
	
private:
	std::vector<Entity*> m_EntityInWorld;
	std::map<std::string, Entity*> m_EntityMap;
	std::map<std::string, IScene*> m_Scenes;
	IScene* m_CurrentScene = nullptr;

};