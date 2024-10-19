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

	IHE::GetLogger()->Log(CTXT("Test (x) + (x)"), CTXT("Char"), DTXT(155));
}

void SampleGame::End()
{
	IH_Application::End();
}
