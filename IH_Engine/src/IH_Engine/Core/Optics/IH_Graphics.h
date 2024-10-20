#pragma once

#include "IH_Module.h"

class IH_Window;
enum class AppRenderer;

class IH_Graphics : public IH_Module
{
public:
	IH_Graphics();

	void Init() override;
	void Clear() override;

	void SetRenderer(AppRenderer Renderer);
	
private:
	IH_Window* _window;
	AppRenderer _renderer;
};