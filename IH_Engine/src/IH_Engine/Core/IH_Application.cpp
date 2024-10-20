#include "IH_Application.h"
#include "IH_Engine.h"

IH_Application::IH_Application() : _appData()
{
}

IH_Application::~IH_Application()
{
}

void IH_Application::Run()
{
	IHE_PTR->InjectApp(this);
}

void IH_Application::SetAppRenderer(AppRenderer Renderer)
{
	_appData.Renderer = Renderer;
}

void IH_Application::SetAppName(char* Name)
{
	_appData.AppName = Name;
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
