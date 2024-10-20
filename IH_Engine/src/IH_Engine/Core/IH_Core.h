#pragma once

#ifdef _WIN32
    #ifdef IH_ENGINE_EXPORTS
        #define IH_API __declspec(dllexport)
    #else
        #define IH_API __declspec(dllimport)
    #endif
#else
    #define IH_API
#endif