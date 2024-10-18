#include "IH_Logger.h"

std::string IH_Logger::ParseLog(const std::string& Entry, const std::string& Value, int Index) const
{
    std::string placeholder = "(" + std::to_string(Index) + ")";
    std::string result = Entry;

    size_t pos = result.find(placeholder);

    while (pos != std::string::npos) 
    {
        result.replace(pos, placeholder.length(), Value);
        pos = result.find(placeholder, pos + Value.length());
    }

    return result;
}
