#include "IH_Application.h"
#include "IH_Engine.h"

IH_Application::IH_Application()
{
}

IH_Application::~IH_Application()
{
}

void IH_Application::Run()
{
	IH_Engine Engine;
	Engine.StartEngine(this);
}

void IH_Application::SetAppRenderer(AppRenderer Renderer)
{

}

void IH_Application::SetAppName(const std::string& Name)
{
	AppName = Name;
}

void IH_Application::Init()
{

}

void IH_Application::Update()
{

}

void IH_Application::End()
{

}
