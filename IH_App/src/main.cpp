#include "Core/SampleGame.h"

int main()
{
	SampleGame Game;

	Game.SetAppName("Sample Game");
	Game.SetWindowDimensions(900, 600);
	Game.SetAppRenderer(AppRenderer::Vulkan);

	Game.Run();
}