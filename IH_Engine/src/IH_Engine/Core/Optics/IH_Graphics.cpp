#include "IH_Graphics.h"
#include "IH_Window.h"

void IH_Graphics::Init()
{
	Window = new IH_Window();
}

void IH_Graphics::Clear()
{
	delete Window;
}
