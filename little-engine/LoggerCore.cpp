#include "stdafx.hpp"
#include "LoggerCore.hpp"
#include "Logger.hpp"

namespace LittleEngine
{
    LoggerCore::LoggerCore()
    {
    }
    LoggerCore::~LoggerCore()
    {
    }

    Logger *LoggerCore::branch(const wchar_t *name)
    {
        return new Logger(this, name);
    }
}
