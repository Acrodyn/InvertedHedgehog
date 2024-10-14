#ifdef _WIN32
    #ifdef IH_ENGINE_EXPORTS
        #define IH_ENGINE_API __declspec(dllexport)
    #else
        #define IH_ENGINE_API __declspec(dllimport)
    #endif
#else
    #define IH_ENGINE_API
#endif

int GetBla()
{
    return 3;
}