#pragma once
#include "little-engine/PlatformAdapter.h"

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
    };
}
