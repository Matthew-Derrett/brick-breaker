#include "Actor.h"

Actor::Actor(Vector2 location, Vector2 size, Color color, Game* game)
	: location{ location }, size{ size }, color{ color }, m_game{ game }
{

}

Actor:: ~Actor()
{
	m_game = nullptr;
}

void Actor::BeginPlay()
{

}

void Actor::Tick(float dt)
{

}

void Actor::Render()
{

}

void Actor::EndPlay()
{

}