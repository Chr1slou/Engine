#pragma once
class Entity;

class Component
{
public:
	virtual ~Component() = default;
	Component();
	/// <summary>
	/// set the entity parent
	/// </summary>
	/// <param name="parent">the entity that creates the component</param>
	Component(Entity* parent);
	/// <summary>
	/// init of the component
	/// </summary>
	virtual void Start();
	/// <summary>
	/// behavior on destroy
	/// </summary>
	virtual void Destroy();
protected:
	Entity* m_Parent = nullptr;
};
