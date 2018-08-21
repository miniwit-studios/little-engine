#include "stdafx.hpp"
#include "Logger.hpp"
#include "LoggerCore.hpp"

namespace LittleEngine
{
    Logger::Logger(LoggerCore *core, std::string name)
        : LoggerCore(), m_core(core), m_name(name)
    {
    }
    Logger::~Logger()
    {
    }

    std::string Logger::name()
    {
        return this->m_name;
    }

    Logger *Logger::branch(std::string name)
    {
        return new Logger(m_core, m_name + name);
    }

    void Logger::log(std::string message)
    {
        m_core->log("["s + m_name + "] "s + message);
    }
}
