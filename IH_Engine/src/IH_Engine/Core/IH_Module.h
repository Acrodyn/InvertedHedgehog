#pragma once

#include "IH_Core.h"

struct AppData;

class IH_Module
{
public:
	virtual void Init(const AppData* AppData) {};
	virtual void Clear() {};
};