#pragma once

class IH_Application;

class IH_Engine
{
public:
    IH_Engine();

    static const IH_Engine* Get();

    void StartEngine(IH_Application* NewApplication);

private:
    static IH_Engine* EngineInstance;

    IH_Application* Application;
};