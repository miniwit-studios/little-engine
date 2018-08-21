#pragma once

namespace LittleEngine
{
    class Logger;

    class LITTLEENGINE_API LoggerCore
    {
    public:
        LoggerCore();
        virtual ~LoggerCore();

        virtual Logger *branch(std::string name);

        virtual void log(std::string message) = 0;
    };
}
