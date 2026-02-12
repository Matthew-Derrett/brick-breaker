#include <cstdlib>
#include <iostream>

#include <raylib.h>

int main(int argC, char* argV[])
{
	InitWindow(1080, 720, "Brick Breaker");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawCircle(540, 360, 50.f, RED);

		EndDrawing();
	}

	CloseWindow();

	return EXIT_SUCCESS;
}