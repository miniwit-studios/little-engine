#include "stdafx.hpp"
#include "ConsoleLoggerCore.hpp"

#include <iostream>

namespace LittleEngine
{
    ConsoleLoggerCore::ConsoleLoggerCore()
        : LoggerCore()
    {
    }
    ConsoleLoggerCore::~ConsoleLoggerCore()
    {
    }

    void ConsoleLoggerCore::log(std::string message)
    {
        std::cout << message << std::endl;
    }
}
