#include "IH_Optics.h"
#include "IH_Window.h"
#include "IH_AppData.h"
#include "IH_Engine.h"

IH_Optics::IH_Optics() : _window(nullptr), _renderer(AppRenderer::Vulkan)
{
}

void IH_Optics::Init(const AppData* AppData)
{
	if (_window)
	{
		Clear();
	}

	_window = new IH_Window();
	_window->Init(AppData->AppName, 
		AppData->Optics.WindowWidth,
		AppData->Optics.WindowHeight,
		AppData->Optics.Renderer);
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

void IH_Optics::SetRenderer(AppRenderer Renderer)
{
	_renderer = Renderer;
}
