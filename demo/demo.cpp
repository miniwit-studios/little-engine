// demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "windows-pa/WindowsPlatformAdapter.h"
#include "little-engine/SafeInit.h"
#include "little-engine/ConsoleLoggerCore.h"

using namespace LittleEngine;

int main()
{
    ConsoleLoggerCore logger;

    Platform::WindowsPlatformAdapter pa(&logger);
    SafeInit paInit(pa);

    std::cout << "Hello, World!"s << std::endl;
    std::cout << "This is a demo project using the "s << pa.platformName() << " Platform Adapter."s << std::endl;

    pa.terminal_pauseForKey();

    return 0;
}
