#pragma once
#include <string>
#include <vector>
#include "Engine.h"
#include "Component.h"
#include <map>
#include <typeinfo>

using namespace sky;


class  Entity final {
public:
	Entity(const std::string& name) : m_Name(name) {}
	virtual ~Entity() = default;
	virtual void Start();
	virtual void Update(float dt);
	virtual void Draw();
	virtual void Destroy();

	template<typename T>
	inline T AddComponent(T* cmp)
	{
		const type_info* type = &typeid(*cmp);
		m_componentByType.emplace(type, cmp);

		IDrawable* comp = dynamic_cast<IDrawable*>(cmp);
		
		if (comp != nullptr)
		{
			m_Drawable.push_back(comp);
		}
		
		IUpdatable* cm = dynamic_cast<IUpdatable*>(cmp);
		
		if (cm != nullptr)
		{
			m_Updatable.push_back(cm);
		}
		
		
	}
	std::string& GetName() { return m_Name; }
private:
	std::string m_Name;
	std::vector<IUpdatable*> m_Updatable;
	std::vector<IDrawable*> m_Drawable;
	std::map< type_info*, Component*> m_componentByType;
};