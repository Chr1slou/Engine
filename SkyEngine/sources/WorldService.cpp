#include <WorldService.h>
#include <Entity.h>

WorldService::WorldService()
{
}

void WorldService::Add(Entity* entity)
{
	m_EntityInWorld.emplace_back(entity);
	m_EntityMap.emplace(entity->GetName(), entity);
}

Entity* WorldService::Find(const std::string& name)
{
	if (m_EntityMap.count(name) > 0) {
		return m_EntityMap[name];
	}
	return nullptr;
}

void WorldService::Remove(Entity* entity)
{
	for (auto it = m_EntityMap.begin(); it != m_EntityMap.end(); ++it) {
		if ((*it).second->GetName() == entity->GetName()) {
			m_EntityMap.erase(it--);
		}
	}
	for (auto it = m_EntityInWorld.begin(); it != m_EntityInWorld.end(); ++it) {
		if ((*it)->GetName() == entity->GetName()) {
			m_EntityInWorld.erase(it--);
		}
	}
}

Entity* WorldService::Create(std::string name)
{
	Entity* _e = new Entity(name);
	Add(_e);
	return _e;
}

void WorldService::Load(const std::string& scene)
{
	if (m_Scenes.count(scene) > 0) {
		Unload();
		m_CurrentScene = m_Scenes[scene];
		m_CurrentScene->Load();
	}
}

void WorldService::Unload()
{
	if (m_CurrentScene != nullptr) {
		for (auto entity : m_EntityInWorld) {
			entity->Destroy();
			delete entity;
		}
		m_EntityInWorld.clear();
		m_EntityMap.clear();
	}

}

void WorldService::Register(const std::string& name, IScene* scene)
{
	if (m_Scenes.count(name) == 0) {
		m_Scenes[name] = scene;
	}
}
