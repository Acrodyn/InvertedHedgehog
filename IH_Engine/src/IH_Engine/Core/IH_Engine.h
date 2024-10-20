#pragma once

#include "IH_Core.h"
#include "IH_Macros.h"
#include <vector>

#define IHE IH_Engine

struct AppData;
class IH_Module;
class IH_Application;

class IH_ENGINE_API IH_Engine
{
private:
    IH_Engine();

public:
    static IH_Engine* Get();

    void InjectApp(IH_Application* NewApplication);
    const AppData* GetAppData();

    IH_MODULE(class IH_Logger, Logger);
    IH_MODULE(class IH_Graphics, Graphics);

private:
    void Init();
    void Start();
    void Loop();
    void Reset();
    void Shutdown();

    void RegisterModule(IH_Module* Module);

private:
    IH_Application* _application;

    std::vector<IH_Module*> _modules;
};