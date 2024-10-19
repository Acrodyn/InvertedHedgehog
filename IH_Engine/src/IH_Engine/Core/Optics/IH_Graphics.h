#pragma once

#include "IH_Module.h"

class IH_Window;

class IH_Graphics : public IH_Module
{
public:
	void Init() override;
	void Clear() override;
	
private:
	IH_Window* Window;
};