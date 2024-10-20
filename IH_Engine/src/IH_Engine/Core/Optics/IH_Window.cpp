#include "IH_Window.h"
#include "SDL3/SDL.h"

void IH_Window::Init()
{
    // We initialize SDL and create a window with it.
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);

    Window = SDL_CreateWindow(
        "Vulkan Engine",
        1700,
        900,
        window_flags);
}

void IH_Window::Destroy()
{

}
