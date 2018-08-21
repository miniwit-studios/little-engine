#pragma once

namespace LittleEngine::Platform
{
    class LITTLEENGINE_API PlatformAdapter
    {
    public:
        PlatformAdapter();
        virtual ~PlatformAdapter();

        virtual std::string platformName() = 0;

        virtual void terminal_pauseForKey() = 0;
    };
}
