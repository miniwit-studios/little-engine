#pragma once

namespace LittleEngine
{
    class Logger;
    class LoggerCore;
}

namespace LittleEngine::Platform
{
    class LITTLEENGINE_API PlatformAdapter
    {
    public:
        PlatformAdapter(LoggerCore *logger);
        virtual ~PlatformAdapter();

        virtual std::string platformName() = 0;

        virtual bool init() = 0;
        virtual void shutdown() = 0;

        virtual void terminal_pauseForKey() = 0;

        Logger &logger();

    private:
        Logger *m_logger;
    };
}
