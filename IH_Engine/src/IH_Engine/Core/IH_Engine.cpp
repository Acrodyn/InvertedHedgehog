#include "IH_Engine.h"
#include "IH_Application.h"

IH_Engine* IH_Engine::EngineInstance = nullptr;

IH_Engine* IH_Engine::Get() 
{
	if (!EngineInstance)
	{
		EngineInstance = new IH_Engine();
	}

	return EngineInstance; 
}

IH_Engine::IH_Engine() : Application(nullptr)
{

}

void IH_Engine::InjectApp(IH_Application* NewApplication)
{
	if (Application)
	{
		ResetEngine();
		Application = nullptr;
	}

	Application = NewApplication;
	StartEngine();
}

void IH_Engine::StartEngine()
{
	Application->Init();

	Application->Update();

	Application->End();
}

void IH_Engine::ResetEngine()
{

}

void IH_Engine::ShutdownEngine()
{

}
