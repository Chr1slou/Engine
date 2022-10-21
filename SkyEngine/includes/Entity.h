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
	virtual Entity* Instantiate(const std::string& name);
	

	template<typename T>
	T* AddComponent()
	{
		T* cmp = new T(this);
		const type_info* type = &typeid(*cmp);
		if (m_componentByType.count(type) == 0)
		{

			m_componentByType.emplace(type, cmp);

			auto comp = dynamic_cast<IDrawable*>(cmp);
		
			if (comp != nullptr)
			{
				m_Drawable.push_back(comp);
			}
		
			auto cm = dynamic_cast<IUpdatable*>(cmp);
		
			if (cm != nullptr)
			{
				m_Updatable.push_back(cm);
			}
			return cmp;
		}
		return nullptr;
	}
	template <typename T>
	T* GetComponent()
	{
		const type_info* type = &typeid(T);
		if (m_componentByType.count(type) > 0)
		{
			return static_cast<T*>(m_componentByType[type]);
		}

		return nullptr;
	}


	std::string& GetName() { return m_Name; }
protected:
	std::string m_Name;
	std::vector<IUpdatable*> m_Updatable;
	std::vector<IDrawable*> m_Drawable;
	std::map<const type_info*, Component*> m_componentByType;
};

