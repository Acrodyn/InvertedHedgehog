#include "IH_Window.h"
#include "SDL3/SDL.h"

IH_Window::IH_Window() : _event()
{
}

void IH_Window::Init(char* Name, int Width, int Height, AppRenderer Renderer)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WindowFlags windowFlags = (SDL_WindowFlags)(GetAppropriateWindowFlags(Renderer));
    _window = SDL_CreateWindow(Name, Width, Height, windowFlags);
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

Uint64 IH_Window::GetAppropriateWindowFlags(AppRenderer Renderer)
{
    switch(Renderer)
    {
    case AppRenderer::Vulkan:
        return SDL_WINDOW_VULKAN;
        break;
    }

    return 0;
}
