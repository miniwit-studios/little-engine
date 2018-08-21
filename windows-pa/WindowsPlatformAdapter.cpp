#include "stdafx.hpp"
#include "WindowsPlatformAdapter.hpp"
#include "WindowsPlatformAdapterImpl.hpp"

namespace LittleEngine::Platform
{
    WindowsPlatformAdapter::WindowsPlatformAdapter(LoggerCore *logger)
        : PlatformAdapter(logger), m_pimpl(new WindowsPlatformAdapterImpl(&this->logger()))
    {
    }
    WindowsPlatformAdapter::~WindowsPlatformAdapter()
    {
        SafeDelete(m_pimpl);
    }

    std::string WindowsPlatformAdapter::platformName()
    {
        return "Windows"s;
    }

    bool WindowsPlatformAdapter::init()
    {
        return m_pimpl->init();
    }
    void WindowsPlatformAdapter::shutdown()
    {
        m_pimpl->shutdown();
    }

    void WindowsPlatformAdapter::pollEvents()
    {
        m_pimpl->pollEvents();
    }

    void WindowsPlatformAdapter::terminal_pauseForKey()
    {
        m_pimpl->terminal_pauseForKey();
    }
}
