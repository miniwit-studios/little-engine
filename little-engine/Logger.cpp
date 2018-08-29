#include "stdafx.hpp"
#include "Logger.hpp"
#include "LoggerCore.hpp"
#include <sstream>

namespace LittleEngine
{
    Logger::Logger(LoggerCore *core, const wchar_t *name, bool copyName)
        : LoggerCore(), m_core(core)
    {
        if (copyName)
        {
            auto nameLength = lstrlen(name);
            auto nameBuff = new wchar_t[nameLength + 1];
            lstrcpy(nameBuff, name);
            nameBuff[nameLength] = 0;
            m_name = nameBuff;
        }
        else
        {
            m_name = name;
        }
    }
    Logger::~Logger()
    {
        SafeDelete(m_name);
    }

    const wchar_t *Logger::name() const
    {
        return this->m_name;
    }

    Logger *Logger::branch(const wchar_t *name)
    {
        const size_t myNameLen = lstrlen(m_name);
        const size_t newNameLen = lstrlen(name);
        const size_t len = myNameLen + newNameLen + 2;
        wchar_t *buff = new wchar_t[len];

        lstrcpy(buff, m_name);
        buff[myNameLen] = L':';
        lstrcpy(buff + myNameLen + 1, name);
        buff[len - 1] = 0;
        return new Logger(m_core, buff, false);
    }

    void Logger::log(const wchar_t *message)
    {
        std::wostringstream stream;
        stream << L"[" << m_name << L"] " << message;
        m_core->log(stream.str().c_str());
    }
}
