#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlimgui.h>

int main()
{
	
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1920, 1080, "BATERRIA");

	rlImGuiSetup(true);


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
	
		rlImGuiBegin();

		DrawRectangle(75, 75, 100, 100, { 0,255,0,255 });
		DrawRectangle(50, 50, 100, 100, { 255,0,0,255 });
		
		DrawText("Congrats! You Created The Window For BATERRIA!!", 960, 540, 20, RED);

		rlImGuiEnd();

		EndDrawing();
		
	}

	rlImGuiShutdown();


	CloseWindow();
	return 0;
}