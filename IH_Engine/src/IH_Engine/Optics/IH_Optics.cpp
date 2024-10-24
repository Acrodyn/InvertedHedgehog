#include "IH_Optics.h"
#include "IH_Window.h"
#include "IH_AppData.h"
#include "IH_Engine.h"

IH_Optics::IH_Optics() : _window(nullptr)
{
}

void IH_Optics::Init(const AppData* AppData)
{
	if (_window)
	{
		Clear();
	}

	_window = new IH_Window();
}

void IH_Optics::Clear()
{
	_window->Destroy();
	delete _window;
	_window = nullptr;
}

bool IH_Optics::CanUpdate()
{
	return !_window->IsWindowClosed();
}

void IH_Optics::Render()
{
	_window->Update();
}

void IH_API IH_Optics::InjectRenderer(IH_RendererInterface* Renderer)
{
	IH_PTR_CHECK_VOID(_window);

	// if already initialized, inject renderer without init
	// _window->InjectRenderer(Renderer);

	const AppData* appData = IHE_PTR->GetAppData();

	_window->Init(appData->AppName,
		appData->Optics.WindowWidth,
		appData->Optics.WindowHeight,
		Renderer);
}
