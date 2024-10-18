#pragma once

#include "IH_Core.h"

#include <string>
#include <iostream>

class IH_ENGINE_API IH_Logger
{
public:
	IH_Logger() {};

    template<typename... Args>
    void Log(std::string LogText, Args... args) const
    {
        int index = 0;

        (([&] { LogText = ParseLog(LogText, args, index++); }()), ...);

        std::cout << LogText << std::endl;
    }
    
private:
    std::string ParseLog(const std::string& Entry, const std::string& Value, int Index) const;
};