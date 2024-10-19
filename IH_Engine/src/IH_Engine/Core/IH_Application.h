#pragma once

#include <string>
#include "IH_Core.h"
#include "IH_AppData.h"

class IH_ENGINE_API IH_Application
{
public:
    IH_Application();
    ~IH_Application();

public:
    void Run();
    void SetAppRenderer(AppRenderer Renderer);
    void SetAppName(char* Name);

protected:
    virtual void Init();
    virtual void Update();
    virtual void Reset();
    virtual void End();

private:
   char* AppName;

friend class IH_Engine;
};