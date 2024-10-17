#include "SampleGame.h"

#include <iostream>

void SampleGame::Init()
{
	IH_Application::Init();
}

void SampleGame::Update()
{
	IH_Application::Update();

	std::cout << "test";
}

void SampleGame::End()
{
	IH_Application::End();
}
