#pragma once
class Entity;

class Component
{
public:
	virtual ~Component() = default;
	Component();
	Component(Entity* parent);
	virtual void Start();
	virtual void Destroy();
protected:
	Entity* m_Parent = nullptr;
};
