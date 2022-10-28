#include "PlayerController.h"
#include "Entity.h"
#include "Square.h"





PlayerController::PlayerController()
{
}

PlayerController::PlayerController(Entity* parent) : Component(parent)
{
	
}

void PlayerController::Update(float dt)
{
	if (Engine::Get().Input().IsKeyDown(EKey::EKEY_1))
	{
		Engine::Get().World().Remove(m_Parent);
	}
	if (Engine::Get().Input().IsKeyDown(EKey::EKEY_A))
	{
		m_Parent->SetX(-200 * dt);

	}
	if (Engine::Get().Input().IsKeyDown(EKey::EKEY_D))
	{
		m_Parent->SetX(200 * dt);
	}
	if (Engine::Get().Input().IsKeyDown(EKey::EKEY_W))
	{
		m_Parent->SetY(-200 * dt);
	}
	if (Engine::Get().Input().IsKeyDown(EKey::EKEY_S))
	{
		m_Parent->SetY(200 * dt);
	}

}

void PlayerController::Start()
{
	m_player = m_Parent->GetComponent<Square>();
}

void PlayerController::Destroy()
{
	if (m_Parent != nullptr)
	{
		delete m_Parent;
	}
	if (m_player != nullptr)
	{
		delete m_player;
	}
}
