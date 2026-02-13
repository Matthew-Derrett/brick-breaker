#include "Paddle.h"

#include "Game.h"
#include "Ball.h"

#include <raymath.h>

Paddle::Paddle(Game* game)
	: Actor{ { game->GetWidth() * 0.5f, game->GetHeight() - 20.f }, { 75.f, 25.f}, WHITE, game }, m_speed{ 250.f }
{

}

void Paddle::Tick(float dt)
{
	if (IsKeyDown(KEY_D))
	{
		location.x += m_speed * dt;
	}

	if (IsKeyDown(KEY_A))
	{
		location.x -= m_speed * dt;
	}

	if (location.x < size.x * 0.5f)
	{
		location.x = size.x * 0.5f;
	}

	if (location.x > m_game->GetWidth() - size.x * 0.5f)
	{
		location.x = m_game->GetWidth() - size.x * 0.5f;
	}

	Ball* ball = m_game->GetBall();
	Vector2 ballPaddleDir = Vector2Normalize(location - ball->location);
	float ballRadius = Vector2Length(ball->size);
	Rectangle paddleRect = { location.x - size.x * 0.5f, location.y - size.y * 0.5f, size.x, size.y };

	if (CheckCollisionCircleRec(ball->location, ballRadius, paddleRect))
	{
		Vector2 newBallVelocity = Vector2Reflect(ballPaddleDir, { 0, -1 });
		ball->velocity = newBallVelocity;
	}
}


void Paddle::Render()
{
	DrawRectanglePro({ location.x, location.y, size.x, size.y}, { size.x * 0.5f, size.y * 0.5f }, 0.f, color);
}
