#pragma once

#include <string>
#include "IH_Core.h"
#include "IH_AppData.h"

class IH_RendererInterface;

class IH_Application
{
public:
    IH_Application();
    ~IH_Application();

public:
    void IH_API Run();
    void IH_API SetAppRenderer(IH_RendererInterface* Renderer);
    void IH_API SetAppName(char* Name);
    void IH_API SetWindowDimensions(int Width, int Height);

protected:
    virtual void Init();
    virtual void Update();
    virtual void Reset();
    virtual void End();

protected:
    AppData _appData;

friend class IH_Engine;
};