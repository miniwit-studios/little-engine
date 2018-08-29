#include "stdafx.hpp"
#include "GlfwPlatformAdapter.hpp"
#include "GlfwPlatformAdapterImpl.hpp"

namespace LittleEngine::Platform
{
    GlfwPlatformAdapter::GlfwPlatformAdapter(LoggerCore *logger)
        : PlatformAdapter(logger), m_pimpl(new GlfwPlatformAdapterImpl(&this->logger()))
    {
    }
    GlfwPlatformAdapter::~GlfwPlatformAdapter()
    {
        SafeDelete(m_pimpl);
    }

    const wchar_t *GlfwPlatformAdapter::platformName()
    {
        return L"Windows";
    }

    bool GlfwPlatformAdapter::init()
    {
        return m_pimpl->init();
    }
    void GlfwPlatformAdapter::shutdown()
    {
        m_pimpl->shutdown();
    }

    void GlfwPlatformAdapter::pollEvents()
    {
        m_pimpl->pollEvents();
    }

    void GlfwPlatformAdapter::terminal_pauseForKey()
    {
        m_pimpl->terminal_pauseForKey();
    }
}
