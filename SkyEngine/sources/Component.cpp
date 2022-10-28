#include<Component.h>

Component::Component()
{
}

Component::Component(Entity* parent)
{
	m_Parent = parent;
}

void Component::Start()
{
}

void Component::Destroy()
{
	if (m_Parent != nullptr)
	{
		delete m_Parent;
	}
}
