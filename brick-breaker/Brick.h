#pragma once

#include "Actor.h"

class Brick : public Actor
{
public:
	bool isBroken;

public:
	Brick(Vector2 location, Vector2 size, Game* game);

public:
	void Tick(float dt) override;
	void Render() override;
};

