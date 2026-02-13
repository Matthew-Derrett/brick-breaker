#pragma once

#include <string>
#include <raylib.h>
#include <vector>

using std::string;
using std::vector;

class Actor;

class Game
{
public:
	Game(int w, int h, string title, Color clrColor);
	~Game();

public:
	int Run();

	int GetWidth() const;
	int GetHeight() const;

private:
	int m_width;
    int m_height;
	string m_title;
	Color m_clrColor;

	vector<Actor*> m_actors;

private:
	/* The function that is called when the game is run for the first time. */
	void BeginPlay();

	/* The function that is used for any gameplay logic. Called once per frame. */
	void Tick(float dt);
	/* The function that is used to draw any object on the creen */
	void Render();

	/* The function that is called to cleanup any actors or memory in the game. */
	void EndPlay();


};

