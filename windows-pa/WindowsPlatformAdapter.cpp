#include "stdafx.hpp"
#include "WindowsPlatformAdapter.hpp"
#include "little-engine/Logger.hpp"

#include <conio.h>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

//#define GLFW_INCLUDE_VULKAN
#include "middleware/glfw/glfw3.h"

namespace LittleEngine::Platform
{
    WindowsPlatformAdapter::WindowsPlatformAdapter(LoggerCore *logger)
        : PlatformAdapter(logger)
    {
    }
    WindowsPlatformAdapter::~WindowsPlatformAdapter()
    {
    }

    std::string WindowsPlatformAdapter::platformName()
    {
        return "Windows"s;
    }

    bool WindowsPlatformAdapter::init()
    {
        logger().log("Initializing WindowsPlatformAdapter..."s);
        if (glfwInit() != GLFW_TRUE) return false;
        logger().log("GLFW initialized."s);

        return true;
    }
    void WindowsPlatformAdapter::shutdown()
    {
        logger().log("Shutting down WindowsPlatformAdapter..."s);
        glfwTerminate();
        logger().log("GLFW terminated."s);
    }

    void WindowsPlatformAdapter::terminal_pauseForKey()
    {
        //TODO: don't busy-wait for the key!
        while (!_kbhit())
        {
            std::this_thread::sleep_for(10ms);
        }
        _getch();
    }
}
