#pragma once

#include <raylib.h>
#include <vector>

class Game;

class Actor
{
public:
	Vector2 location;
	Vector2 size;
	Color color;

public:
	Actor(Vector2 position, Vector2 size, Color color, Game* game);
	~Actor();

public:
	virtual void BeginPlay();

	virtual void Tick(float dt);
	virtual void Render();

	virtual void EndPlay();

protected:
	Game* m_game;

};

