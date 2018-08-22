#pragma once
#include "little-engine/PlatformAdapter.hpp"

namespace LittleEngine::Platform
{
    class GlfwPlatformAdapterImpl;

    class WINDOWSPA_API GlfwPlatformAdapter final : public PlatformAdapter
    {
    public:
        GlfwPlatformAdapter(LoggerCore *logger);
        ~GlfwPlatformAdapter();

        virtual std::string platformName() override;

        virtual bool init() override;
        virtual void shutdown() override;

        virtual void pollEvents() override;

        virtual void terminal_pauseForKey() override;

    private:
        GlfwPlatformAdapterImpl *m_pimpl;
    };
}
