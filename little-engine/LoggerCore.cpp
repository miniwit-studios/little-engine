#include "stdafx.h"
#include "LoggerCore.h"
#include "Logger.h"

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
