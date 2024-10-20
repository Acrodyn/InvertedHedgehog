#include "IH_Engine.h"
#include "IH_Application.h"
#include "Utils/IH_Logger.h"
#include "Optics/IH_Graphics.h"

IH_Engine* IH_Engine::Get() 
{
	static IH_Engine* EngineInstance = new IH_Engine();

	return EngineInstance; 
}

IH_Engine::IH_Engine() : _application(nullptr)
{
	// modules
	REGISTER_MODULE(IH_Logger, Logger);
	REGISTER_MODULE(IH_Graphics, Graphics);
}

void IH_Engine::InjectApp(IH_Application* NewApplication)
{
	if (_application)
	{
		_application->End();
		_application = nullptr;
	}

	_application = NewApplication;
	Start();
}

const AppData* IH_Engine::GetAppData()
{
	IH_PTR_CHECK_RETURN(_application, nullptr);
	return &_application->_appData;
}

void IH_Engine::Init()
{
	IH_PTR_CHECK_VOID(_application);
	_application->Init();

	for (IH_Module* Module : _modules)
	{
		Module->Init(GetAppData());
	}
}

void IH_Engine::Start()
{
	IH_PTR_CHECK_VOID(_application);

	Init();
	Loop();
	Shutdown();
}

void IH_Engine::Loop()
{
	while (ShouldLoop())
	{
		_application->Update();
		GraphicsModule->Render();
	}
}

void IH_Engine::Reset()
{
	if (_application)
	{
		_application->Reset();
	}
}

void IH_Engine::Shutdown()
{
	if (_application)
	{
		_application->End();
	}

	for (IH_Module* Module : _modules)
	{
		Module->Clear();
		delete Module;
	}

	_modules.clear();
}

bool IH_Engine::ShouldLoop()
{
	return GraphicsModule->CanUpdate();
}

void IH_Engine::RegisterModule(IH_Module* Module)
{
	_modules.push_back(Module);
}
