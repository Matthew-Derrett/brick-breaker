#include "Ball.h"

#include "Game.h"

#include <raymath.h>

Ball::Ball(Game* game)
	: Actor{ { game->GetWidth() * 0.5f, game->GetHeight() * 0.5f }, { 5.f, 5.f }, WHITE, game },
	velocity{ 0.5f, 0.5 }, moveSpeed{ 250.f }
{

}

void Ball::BeginPlay()
{
	float dir = GetRandomValue(-9, 9) * 0.1f;
	velocity.x = dir;

	velocity = Vector2Normalize(velocity);
}

void Ball::Tick(float dt)
{
	location += velocity * moveSpeed * dt;

	float radius = Vector2Length(size) * 1.f;

	if (location.x > m_game->GetWidth() - radius ||
		location.x < radius)
	{
		velocity.x *= -1;
	}

	if (location.y < radius)
	{
		velocity.y *= -1;
	}

	if (location.y > m_game->GetHeight() - radius)
	{
		location = { m_game->GetHeight() * 0.5f, m_game->GetHeight() * 0.5f };
	}

}

void Ball::Render()
{
	DrawCircleV(location, Vector2Length(size), color);
}
