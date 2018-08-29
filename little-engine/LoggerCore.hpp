#pragma once

namespace LittleEngine
{
    class Logger;

    class LITTLEENGINE_API LoggerCore
    {
    public:
        LoggerCore();
        virtual ~LoggerCore();

        virtual Logger *branch(const wchar_t *name);

        virtual void log(const wchar_t *message) = 0;
    };
}
