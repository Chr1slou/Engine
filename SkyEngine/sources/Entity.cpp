#include <Entity.h>



void Entity::Start()
{
	for(auto cmp : m_componentByType)
	{
		cmp.second->Start();
	}
}

void Entity::Update(float dt)
{
	for (auto cmp : m_Updatable)
	{
		cmp->Update(dt);
	}
}

void Entity::Draw()
{
	for (auto cmp : m_Drawable)
	{
		cmp->Draw();
	}
}

void Entity::Destroy()
{
	for (auto cmp : m_componentByType)
	{
		delete cmp.second;
	}
}

Entity* Entity::Instantiate(const std::string& name)
{
	return Engine::Get().World().Create(name);
}

void Entity::SetX(float X)
{
	m_Position.X += X;
}

void Entity::SetY(float Y)
{
	m_Position.Y += Y;
}




