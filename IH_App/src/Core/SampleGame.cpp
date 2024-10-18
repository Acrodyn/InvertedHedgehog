#include "SampleGame.h"
#include "Core/IH_Engine.h"
#include "Utils/IH_Logger.h"

#include <iostream>

void SampleGame::Init()
{
	IH_Application::Init();
}

void SampleGame::Update()
{
	IH_Application::Update();

	IH_Engine::GetLogger()->Log(CTXT("Test (0) + (1)"), CTXT("Char"), DTXT(123));
}

void SampleGame::End()
{
	IH_Application::End();
}
