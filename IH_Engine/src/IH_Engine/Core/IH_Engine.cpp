#include "IH_Engine.h"
#include "IH_Application.h"
#include "Utils/IH_Logger.h"
#include "Optics/IH_Graphics.h"

IH_Engine* IH_Engine::Get() 
{
	IH_Engine* EngineInstance = new IH_Engine();

	return EngineInstance; 
}

IH_Engine::IH_Engine() : Application(nullptr)
{
	// modules
	REGISTER_MODULE(IH_Logger, Logger);
	REGISTER_MODULE(IH_Graphics, Graphics);
}

void IH_Engine::InjectApp(IH_Application* NewApplication)
{
	if (Application)
	{
		Application->End();
		Application = nullptr;
	}

	Application = NewApplication;
	Start();
}

void IH_Engine::Init()
{
	IH_PTR_CHECK_VOID(Application);
	Application->Init();
}

void IH_Engine::Start()
{
	IH_PTR_CHECK_VOID(Application);

	Init();
	Loop();
	Shutdown();
}

void IH_Engine::Loop()
{
	Application->Update();
}

void IH_Engine::Reset()
{
	if (Application)
	{
		Application->Reset();
	}
}

void IH_Engine::Shutdown()
{
	if (Application)
	{
		Application->End();
	}

	for (IH_Module* Module : Modules)
	{
		Module->Clear();
		delete Module;
	}

	Modules.clear();
}

void IH_Engine::RegisterModule(IH_Module* Module)
{
	Modules.push_back(Module);
}
