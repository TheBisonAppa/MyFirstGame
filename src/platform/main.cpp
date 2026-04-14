#include <iostream>
#include <raylib.h>

#include "imgui.h"
#include "rlimgui.h"

#include "gameMain.h"

int main(void)
{
#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE); //No output to console when in production build
#endif
	
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1920, 1080, "BATERRIA");
	SetExitKey(KEY_NULL); // Esc no longer closes window
	SetTargetFPS(240);

#pragma region imgui configs
	rlImGuiSetup(true);

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.FontGlobalScale = 2;
#pragma endregion

	if (!initGame())
	{
		return 0;
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
#pragma region imgui docking stuff
		rlImGuiBegin();

		//docking stuff...
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);

#pragma endregion

		if (!updateGame()) 
		{
			CloseWindow();
		}

		rlImGuiEnd();

		EndDrawing();
		
	}

	CloseWindow();

	closeGame();

#pragma region imgui shutdown
	rlImGuiShutdown();
#pragma endregion

	return 0;
}