#pragma once
#include "little-engine/PlatformAdapter.h"

namespace LittleEngine::Platform
{
    class WINDOWSPA_API WindowsPlatformAdapter final : public PlatformAdapter
    {
    public:
        WindowsPlatformAdapter();
        ~WindowsPlatformAdapter();

        virtual std::string platformName() override;

        virtual void terminal_pauseForKey() override;
    };
}
