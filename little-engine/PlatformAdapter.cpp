#include "stdafx.hpp"
#include "PlatformAdapter.hpp"
#include "LoggerCore.hpp"
#include "Logger.hpp"

namespace LittleEngine::Platform
{
    PlatformAdapter::PlatformAdapter(LoggerCore *logger)
        : m_logger(logger->branch(L"platform-adapter"))
    {
    }
    PlatformAdapter::~PlatformAdapter()
    {
        delete m_logger;
    }

    Logger &PlatformAdapter::logger()
    {
        return *m_logger;
    }
}
