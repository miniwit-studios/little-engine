#include "stdafx.h"
#include "PlatformAdapter.h"
#include "LoggerCore.h"
#include "Logger.h"

namespace LittleEngine::Platform
{
    PlatformAdapter::PlatformAdapter(LoggerCore *logger)
        : m_logger(logger->branch("platform-adapter"s))
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
