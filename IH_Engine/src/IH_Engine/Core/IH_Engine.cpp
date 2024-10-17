#include "IH_Engine.h"
#include "IH_Application.h"

IH_Engine* IH_Engine::EngineInstance = nullptr;
const IH_Engine* IH_Engine::Get() { return EngineInstance; }

IH_Engine::IH_Engine() : Application(nullptr)
{

}

void IH_Engine::StartEngine(IH_Application* NewApplication)
{
	EngineInstance = this;
	Application = NewApplication;

	Application->Init();

	Application->Update();

	Application->End();


}
