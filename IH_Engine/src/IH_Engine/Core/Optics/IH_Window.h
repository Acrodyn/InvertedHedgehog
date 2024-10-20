#pragma once

#include "IH_Core.h"

struct SDL_Window;

class IH_Window
{
public:
	IH_Window() {};

	void Init();
	void Destroy();

private:
	SDL_Window* Window = nullptr;

};