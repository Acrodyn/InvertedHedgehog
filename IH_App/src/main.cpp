#include "Core/SampleGame.h"

int main()
{
	SampleGame Game;

	Game.SetAppName("Sample Game");
	Game.SetAppRenderer(AppRenderer::Vulkan);
	Game.SetWindowDimensions(900, 600);

	Game.Run();
}