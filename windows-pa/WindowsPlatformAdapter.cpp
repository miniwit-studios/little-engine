#include "stdafx.h"
#include "WindowsPlatformAdapter.h"

#include <conio.h>

namespace LittleEngine::Platform
{
    WindowsPlatformAdapter::WindowsPlatformAdapter()
    {
    }
    WindowsPlatformAdapter::~WindowsPlatformAdapter()
    {
    }

    std::string WindowsPlatformAdapter::platformName()
    {
        return "Windows"s;
    }

    void WindowsPlatformAdapter::terminal_pauseForKey()
    {
        //TODO: don't busy-wait for the key!
        while (!_kbhit()) ;
        _getch();
    }
}
