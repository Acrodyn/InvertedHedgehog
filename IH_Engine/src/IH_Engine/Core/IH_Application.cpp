#include "IH_Application.h"
#include "IH_Engine.h"

IH_Application::IH_Application() : AppName(nullptr)
{
}

IH_Application::~IH_Application()
{
}

void IH_Application::Run()
{
	IH_Engine::Get()->InjectApp(this);
}

void IH_Application::SetAppRenderer(AppRenderer Renderer)
{

}

void IH_Application::SetAppName(char* Name)
{
	AppName = Name;
}

void IH_Application::Init()
{

}

void IH_Application::Update()
{

}

void IH_Application::Reset()
{

}

void IH_Application::End()
{

}
