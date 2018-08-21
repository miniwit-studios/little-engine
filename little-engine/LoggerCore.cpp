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

    Logger *LoggerCore::branch(std::string name)
    {
        return new Logger(this, name);
    }
}
