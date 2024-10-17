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
    void SetAppName(const std::string& Name);

protected:
    virtual void Init();
    virtual void Update();
    virtual void End();

private:
    std::string AppName;

friend class IH_Engine;
};