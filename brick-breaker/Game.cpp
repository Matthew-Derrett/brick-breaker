#include "Game.h"

#include "Actor.h"
#include "Paddle.h"
#include "brick.h"
#include "Ball.h"

#include <cstdlib>
#include <ctime>

Game::Game(int w, int h, string title, Color clrColor)
	: m_width{ w }, m_height{ h }, m_title{ title }, m_clrColor{ clrColor }, m_ball{ nullptr }
{
	int brickXCount = 7;
	int brickYCount = 6;
	float padding = 2.5f;

	Vector2 brickSize = { (w * .9f) / brickXCount - padding, (h * .4f) / brickYCount - padding };
	for (int x = 0; x < brickXCount; ++x)
	{
		for (int y = 0; y < brickYCount; ++y)
		{
			Vector2 brickPos =
			{
				x * (brickSize.x + padding) + brickSize.x / 2 + w * .05f,
				y * (brickSize.y + padding) + brickSize.y / 2 + h * .05f
			};

			m_actors.emplace_back(new Brick{ brickPos, brickSize, this });
		}
	}

	m_ball = new Ball{ this };
	m_actors.emplace_back(m_ball);

	m_actors.emplace_back(new Paddle{ this });
}

Game::~Game()
{
	for (Actor* actor : m_actors)
	{
		delete actor;
	}

	m_actors.clear();
}

int Game::Run()
{
	InitWindow(m_width, m_height, m_title.c_str());

	// Test if the window did open succesfully
	if (!IsWindowReady())
	{
		// It didn't, so return failure
		return EXIT_FAILURE;
	}

	BeginPlay();

	while (!WindowShouldClose())
	{
		// Run the gameplay loop logic with the deltatime calcualted by raylib
		Tick(GetFrameTime());

		BeginDrawing();
		ClearBackground(m_clrColor);

		// Draw the gameplay elements to the screen
		Render();

		EndDrawing();

	}

	EndPlay();

	CloseWindow();

	return EXIT_SUCCESS;
}

int Game::GetWidth() const
{
	return m_width;
}

int Game::GetHeight() const
{
	return m_height;
}

Ball* Game::GetBall()
{
	return m_ball;
}

void Game::BeginPlay()
{
	SetRandomSeed(time(nullptr));
	for (Actor* actor : m_actors)
	{
		actor->BeginPlay();
	}
}

void Game::Tick(float dt)
{
	for (Actor* actor : m_actors)
	{
		actor->Tick(dt);
	}
}

void Game::Render()
{
	for (Actor* actor : m_actors)
	{
		actor->Render();
	}
}

void Game::EndPlay()
{
	for (Actor* actor : m_actors)
	{
		actor->EndPlay();
	}
}
