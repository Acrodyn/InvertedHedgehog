#pragma once

#include "IH_Core.h"
#include "IH_Macros.h"

class IH_Application;

class IH_ENGINE_API IH_Engine
{
private:
    IH_Engine();

public:
    static IH_Engine* Get();

    void InjectApp(IH_Application* NewApplication);

    IH_MODULE(class IH_Logger, Logger);

private:
    void StartEngine();
    void ResetEngine();
    void ShutdownEngine();

private:
    IH_Application* Application;
};