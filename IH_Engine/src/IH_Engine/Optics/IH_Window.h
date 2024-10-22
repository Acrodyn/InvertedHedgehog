#pragma once

#include "IH_Core.h"
#include "IH_AppData.h"
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_events.h"

struct SDL_Window;
class IH_Vulkan;

class IH_Window
{
public:
	IH_Window();

	void Init(char* Name, int Width, int Height, AppRenderer RendererType);
	void Update();
	void Destroy();

	bool IsWindowClosed();
	bool IsWindowMinimized();
	bool IsWindowMaximzed();

private:
	Uint64 GetAppropriateWindowFlags(AppRenderer RendererType);

private:
	IH_Vulkan* _renderer = nullptr;
	SDL_Window* _window = nullptr;
	SDL_Event _event;
};