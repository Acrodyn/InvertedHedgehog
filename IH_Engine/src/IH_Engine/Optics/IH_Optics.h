#pragma once

#include "IH_Module.h"
#include "IH_AppData.h"

class IH_Window;
enum class AppRenderer;

class IH_Optics : public IH_Module
{
public:
	IH_Optics();

	void Init(const AppData* AppData) override;
	void Clear() override;

	bool CanUpdate();
	void Render();

	void IH_API SetRenderer(AppRenderer Renderer);
	
private:
	IH_Window* _window;
	AppRenderer _renderer;
};