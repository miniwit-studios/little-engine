#pragma once
#include "little-engine/PlatformAdapter.hpp"

namespace LittleEngine::Platform
{
    class WindowsPlatformAdapterImpl;

    class WINDOWSPA_API WindowsPlatformAdapter final : public PlatformAdapter
    {
    public:
        WindowsPlatformAdapter(LoggerCore *logger);
        ~WindowsPlatformAdapter();

        virtual std::string platformName() override;

        virtual bool init() override;
        virtual void shutdown() override;

        virtual void pollEvents() override;

        virtual void terminal_pauseForKey() override;

    private:
        WindowsPlatformAdapterImpl *m_pimpl;
    };
}
