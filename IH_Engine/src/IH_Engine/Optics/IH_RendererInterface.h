#pragma once

#include "IH_Engine/Core/IH_AppData.h"

class IH_Window;

class IH_RendererInterface 
{
public:
	virtual void Init(IH_Window* Window) = 0;
	virtual AppRenderer GetRendererType() = 0;

};
