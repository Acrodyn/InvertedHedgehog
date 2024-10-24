#include "IH_Window.h"
#include "SDL3/SDL.h"
#include "IH_Macros.h"

IH_Window::IH_Window() : _event()
{

}

void IH_Window::Init(char* Name, int Width, int Height, IH_RendererInterface* Renderer)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WindowFlags windowFlags = (SDL_WindowFlags)(Renderer->GetWindowFlags());
    _window = SDL_CreateWindow(Name, Width, Height, windowFlags);

    InjectRenderer(Renderer);
}

void IH_Window::InjectRenderer(IH_RendererInterface* Renderer)
{
    _renderer = Renderer;
    _renderer->Init(this);
}

void IH_Window::Update()
{
    if (SDL_PollEvent(&_event) == 0)
    {
        _event.type = SDL_EVENT_FIRST;
    }
}

void IH_Window::Destroy()
{
    _renderer->Clear();
    delete _renderer;
    SDL_DestroyWindow(_window);
}

bool IH_Window::IsWindowClosed()
{
    if (_event.type != SDL_EVENT_FIRST)
    {
        if (_event.type == SDL_EVENT_QUIT)
        {
            return true;
        }
    }

    return false;
}

bool IH_Window::IsWindowMinimized()
{
    return _event.type == SDL_EVENT_WINDOW_MINIMIZED;
}

bool IH_Window::IsWindowMaximzed()
{
    return _event.type == SDL_EVENT_WINDOW_MAXIMIZED;
}
