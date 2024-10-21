#pragma once

#include "IH_Core.h"
#include "IH_Module.h"

#include <string>
#include <fmt/core.h>

class IH_Logger : public IH_Module
{
public:
    template<typename... Args>
    std::string Format(std::string LogText, Args... args) const
    {
        (([&] { LogText = ParseLog(LogText, args); }()), ...);

        return LogText;
    }

   template<typename... Args>
   void Log(std::string LogText, Args... args) const
    {
       fmt::println(Format(LogText, args...));
    }
    
private:
    std::string ParseLog(const std::string& Entry, const std::string& Value) const;
};