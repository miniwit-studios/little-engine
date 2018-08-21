#include "stdafx.h"
#include "ConsoleLoggerCore.h"

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
