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

    void ConsoleLoggerCore::log(const wchar_t *message)
    {
        std::wcout << message << std::endl;
    }
}
