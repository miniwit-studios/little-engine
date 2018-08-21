#pragma once
#include "LoggerCore.h"

namespace LittleEngine
{
    class LITTLEENGINE_API Logger final : public LoggerCore
    {
    public:
        Logger(LoggerCore *core, std::string name);
        ~Logger();

        std::string name();

        virtual Logger *branch(std::string name) override;

        void log(std::string message);

    private:
        LoggerCore *m_core;
        std::string m_name;
    };
}
