#include "Core/SampleGame.h"

int main()
{
	SampleGame Game;

	Game.SetAppName("Sample Game");
	Game.SetAppRenderer(AppRenderer::Vulkan);

	Game.Run();
}