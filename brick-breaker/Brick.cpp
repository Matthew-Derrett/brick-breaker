#include "Brick.h"

#include "Ball.h"
#include "Game.h"

#include <raymath.h>

Brick::Brick(Vector2 location, Vector2 size, Game* game)
	: Actor{ location, size, ColorFromHSV(GetRandomValue(0, 360), 1.f, 1.f), game }, isBroken{ false }
{

}

void Brick::Tick(float dt)
{
	if (isBroken)
	{
		return;
	}

	Ball* ball = m_game->GetBall();
	Rectangle brickRect = { location.x - size.x * 0.5f, location.y - size.y * 0.5f, size.x, size.y };
	float ballRadius = Vector2Length(ball->size);

	if (CheckCollisionCircleRec(ball->location, ballRadius, brickRect))
	{
		// We have collided with the ball

		isBroken = true;
		ball->velocity.y *= -1;
		ball->moveSpeed += 2000.f;
	}
}

void Brick::Render()
{
	if (isBroken)
	{
		return;
	}

	DrawRectanglePro({ location.x, location.y, size.x, size.y }, { size.x * 0.5f, size.y * 0.5f }, 0.f, color);
}
