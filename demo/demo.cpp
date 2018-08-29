// demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.hpp"

#include <iostream>
#include "glfw-pa/GlfwPlatformAdapter.hpp"
#include "little-engine/SafeInit.hpp"
#include "little-engine/ConsoleLoggerCore.hpp"

using namespace LittleEngine;

int main()
{
    ConsoleLoggerCore logger;
    Platform::GlfwPlatformAdapter pa(&logger);

    {
        SafeInit paInit(pa);

        pa.pollEvents();
    }

    logger.log(L"");
    logger.log(L"Press any key to continue...");
    pa.terminal_pauseForKey();

    return 0;
}
