#pragma once

#include "Actor.h"

class Ball : public Actor
{
public:
	Vector2 velocity;
	float moveSpeed;

public:
	Ball(Game* game);

public:
	void BeginPlay() override;

	void Tick(float dt) override;
	void Render() override;

};

