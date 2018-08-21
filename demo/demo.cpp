// demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "windows-pa/WindowsPlatformAdapter.h"

using namespace LittleEngine::Platform;

int main()
{
    WindowsPlatformAdapter pa;

    std::cout << "Hello, World!"s << std::endl;
    std::cout << "This is a demo project using the "s << pa.platformName() << " Platform Adapter."s << std::endl;

    pa.terminal_pauseForKey();

    return 0;
}
