#include "IH_Engine.h"
#include "IH_Application.h"
#include "Utils/IH_Logger.h"

IH_Engine* IH_Engine::Get() 
{
	IH_Engine* EngineInstance = new IH_Engine();

	return EngineInstance; 
}

IH_Engine::IH_Engine() : Application(nullptr)
{
	LoggerModule = new IH_Logger();
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
