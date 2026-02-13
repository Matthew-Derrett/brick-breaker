#pragma once
#include "Actor.h"

class Paddle : public Actor
{
public:
	Paddle(Game* game);

public:
	void Tick(float dt) override;
	void Render() override;

private:
	float m_speed;

};

