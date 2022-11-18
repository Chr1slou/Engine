#pragma once
#include <vector>
#include <map>
#include <string>
#include "Engine.h"

class Entity;

using namespace sky;
/// <summary>
/// manages scenes and creates entities
/// </summary>
class WorldService : public IWorld{
public:
	WorldService();
	virtual ~WorldService();
	/// <summary>
	/// Add the entity in m_EntityInWorld and m_EntityMap 
	/// </summary>
	/// <param name="entity"> entity to add in world</param>
	virtual void Add(Entity* entity) override; 

	/// <summary>
	/// Find an Entity from its name
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	virtual Entity* Find(const std::string& name) override;

	/// <summary>
	/// calls the draw of the entities in m_EntityInWorld
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// calls the update of the entities in m_EntityInWorld
	/// </summary>
	virtual void Update(float dt) override;

	/// <summary>
	/// removes the entity in m_EntityInWorld and m_EntityMap 
	/// </summary>
	/// <param name="entity"> entity to add in world</param>
	virtual void Remove(Entity* entity) override;

	/// <summary>
	/// creates an Entity, sets its name and add it in m_EntityInWorld and m_EntityMap
	/// </summary>
	/// <param name="name">name of the entity and key in map</param>
	/// <returns> a new entity</returns>
	virtual Entity* Create(std::string name) override;

	/// <summary>
	/// unloads previous scene and load the scene from its name
	/// </summary>
	/// <param name="scene"></param>
	virtual void Load(const std::string& scene) override;

	/// <summary>
	/// Clears all entity from the current scenes and from
	/// m_EntityInWorld and m_EntityMap
	/// </summary>
	virtual void Unload() override;

	/// <summary>
	/// adds scene in the map m_Scenes
	/// </summary>
	/// <param name="name"> key value of the scene</param>
	/// <param name="scene"> scene to create</param>
	virtual void Register(const std::string& name, IScene* scene) override;

	/// <summary>
	/// erase scene in the map m_Scenes
	/// </summary>
	/// <param name="name"></param>
	virtual virtual void UnRegister(const std::string& name) override;

	/// <summary>
	/// Clear the world from all scene and entities
	/// called on destroy
	/// </summary>
	virtual void ClearWorld() override;
	
private:
	std::vector<Entity*> m_EntityInWorld;
	std::map<std::string, Entity*> m_EntityMap;
	std::map<std::string, IScene*> m_Scenes;
	IScene* m_CurrentScene = nullptr;

};