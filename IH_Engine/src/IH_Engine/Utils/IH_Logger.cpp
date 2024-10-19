#include "IH_Logger.h"

std::string IH_Logger::ParseLog(const std::string& Entry, const std::string& Value) const
{
    static std::string placeholder = "(x)";

    std::string result = Entry;
    size_t pos = result.find(placeholder);

    if (pos == std::string::npos)
    {
        return result;
    }

    result = result.replace(pos, placeholder.length(), Value);

    return result;
}