#pragma once
#include "LoggerCore.hpp"

namespace LittleEngine
{
    class LITTLEENGINE_API ConsoleLoggerCore : public LoggerCore
    {
    public:
        ConsoleLoggerCore();
        ~ConsoleLoggerCore();

        virtual void log(const wchar_t *message) override;
    };
}
