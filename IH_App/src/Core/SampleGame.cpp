#include "SampleGame.h"
#include "Core/IH_Engine.h"
#include "Utils/IH_Logger.h"
#include "IH_Vulkan/IH_Vulkan.h"

void SampleGame::Init()
{
	IH_Application::Init();

	SetAppName("Sample Game");
	SetWindowDimensions(900, 600);
	SetAppRenderer(new IH_Vulkan());
}

void SampleGame::Update()
{
	IH_Application::Update();

	IHE::GetLogger()->Log(CTXT("Test (x) + (x)"), CTXT("Char"), DTXT(155));
}

void SampleGame::End()
{
	IH_Application::End();
}
