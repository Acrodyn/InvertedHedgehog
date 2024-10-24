#pragma once

#include "IH_Engine/Core/IH_Core.h"
#include "IH_Engine/Core/IH_AppData.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_events.h"

#include "IH_RendererInterface.h"

struct SDL_Window;

class IH_Window
{
public:
	IH_Window();

	void Init(char* Name, int Width, int Height, IH_RendererInterface* Renderer);
	void InjectRenderer(IH_RendererInterface* Renderer);
	void Update();
	void Destroy();

	bool IsWindowClosed();
	bool IsWindowMinimized();
	bool IsWindowMaximzed();

	SDL_Window* GetWindowObject() { return _window; };

private:
	IH_RendererInterface* _renderer = nullptr;
	SDL_Window* _window = nullptr;
	SDL_Event _event;
};