#include "IH_Graphics.h"
#include "IH_Window.h"
#include "IH_AppData.h"
#include "IH_Engine.h"

IH_Graphics::IH_Graphics() : _window(nullptr), _renderer(AppRenderer::Vulkan)
{
}

void IH_Graphics::Init(const AppData* AppData)
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

void IH_Graphics::Clear()
{
	_window->Destroy();
	delete _window;
	_window = nullptr;
}

bool IH_Graphics::CanUpdate()
{
	return !_window->IsWindowClosed();
}

void IH_Graphics::Render()
{
	_window->Update();
}

void IH_Graphics::SetRenderer(AppRenderer Renderer)
{
	_renderer = Renderer;
}
