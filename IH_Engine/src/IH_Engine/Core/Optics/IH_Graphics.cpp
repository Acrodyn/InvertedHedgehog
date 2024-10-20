#include "IH_Graphics.h"
#include "IH_Window.h"
#include "IH_AppData.h"

IH_Graphics::IH_Graphics() : _window(nullptr), _renderer(AppRenderer::Vulkan)
{
}

void IH_Graphics::Init()
{
	_window = new IH_Window();
}

void IH_Graphics::Clear()
{
	delete _window;
}

void IH_Graphics::SetRenderer(AppRenderer Renderer)
{
	_renderer = Renderer;
}
