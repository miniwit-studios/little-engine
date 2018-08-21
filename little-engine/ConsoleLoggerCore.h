#pragma once
#include "LoggerCore.h"

namespace LittleEngine
{
    class LITTLEENGINE_API ConsoleLoggerCore : public LoggerCore
    {
    public:
        ConsoleLoggerCore();
        ~ConsoleLoggerCore();

        virtual void log(std::string message) override;
    };
}
