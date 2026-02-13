#include "Brick.h"

Brick::Brick(Vector2 location, Vector2 size, Game* game)
	: Actor{ location, size, ColorFromHSV(GetRandomValue(0, 360), 1.f, 1.f), game }, isBroken{ false }
{

}

void Brick::Tick(float dt)
{

}

void Brick::Render()
{
	if (isBroken)
	{
		return;
	}

	DrawRectanglePro({ location.x, location.y, size.x, size.y }, { size.x * 0.5f, size.y * 0.5f }, 0.f, color);
}
