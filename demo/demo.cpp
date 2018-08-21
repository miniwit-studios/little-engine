// demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.hpp"

#include <iostream>
#include "windows-pa/WindowsPlatformAdapter.hpp"
#include "little-engine/SafeInit.hpp"
#include "little-engine/ConsoleLoggerCore.hpp"

using namespace LittleEngine;

int main()
{
    ConsoleLoggerCore logger;
    Platform::WindowsPlatformAdapter pa(&logger);

    {
        SafeInit paInit(pa);

        pa.pollEvents();
    }

    logger.log(""s);
    logger.log("Press any key to continue..."s);
    pa.terminal_pauseForKey();

    return 0;
}
