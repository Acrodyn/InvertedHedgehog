#pragma once

class IH_Application;

class IH_Engine
{
private:
    IH_Engine();

public:
    static IH_Engine* Get();

    void InjectApp(IH_Application* NewApplication);

private:
    void StartEngine();
    void ResetEngine();
    void ShutdownEngine();

private:
    static IH_Engine* EngineInstance;

    IH_Application* Application;
};