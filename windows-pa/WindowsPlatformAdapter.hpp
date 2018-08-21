#pragma once
#include "little-engine/PlatformAdapter.hpp"

namespace LittleEngine::Platform
{
    class WINDOWSPA_API WindowsPlatformAdapter final : public PlatformAdapter
    {
    public:
        WindowsPlatformAdapter(LoggerCore *logger);
        ~WindowsPlatformAdapter();

        virtual std::string platformName() override;

        virtual bool init() override;
        virtual void shutdown() override;

        virtual void terminal_pauseForKey() override;

    private:
        Logger *m_glfwLogger;
        static Logger *s_glfwLogger;
    };
}
