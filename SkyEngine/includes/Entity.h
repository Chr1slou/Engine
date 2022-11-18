#pragma once
#include <string>
#include <vector>
#include "Engine.h"
#include "Component.h"
#include <map>
#include <typeinfo>

using namespace sky;

/// <summary>
/// object that constains component in the game
/// </summary>
class  Entity final {
public:
	Entity(const std::string& name) : m_Name(name) {}
	virtual ~Entity() = default;
	/// <summary>
	/// init the components
	/// </summary>
	virtual void Start();

	/// <summary>
	/// calls update on the updatable components
	/// </summary>
	/// <param name="dt"> deltatime in seconds</param>
	virtual void Update(float dt);

	/// <summary>
	/// calls draw on the drawable components
	/// </summary>

	virtual void Draw();
	virtual void Destroy();
	/// <summary>
	/// creates a new entity
	/// </summary>
	/// <param name="name">name of the entity</param>
	/// <returns>an entity</returns>
	virtual Entity* Instantiate(const std::string& name);
	
	/// <summary>
	/// adds a component on the entity
	/// </summary>
	/// <typeparam name="T">type of the component</typeparam>
	/// <returns>the component created</returns>
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

	/// <summary>
	/// returns a component from the specified type
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
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

	/// <summary>
	/// return the position of the entity
	/// </summary>
	/// <returns></returns>
	Vector2 GetPosition() { return m_Position;}

	/// <summary>
	/// set the position of the entity on the x axis
	/// </summary>
	/// <param name="X"></param>
	void SetX(float X);

	/// <summary>
/// set the position of the entity on the y axis
/// </summary>
/// <param name="Y"></param>
	void SetY(float Y);

	/// <summary>
	/// returns the name of the entity
	/// </summary>
	/// <returns>string</returns>
	std::string& GetName() { return m_Name;}
protected:
	Vector2 m_Position = { 0.0f, 0.0f };
	float m_Angle = 0.0f;
	Vector2 m_Scale{ 1.0f,1.0f};
	std::string m_Name;
	std::vector<IUpdatable*> m_Updatable;
	std::vector<IDrawable*> m_Drawable;
	std::map<const type_info*, Component*> m_componentByType;
	
};

