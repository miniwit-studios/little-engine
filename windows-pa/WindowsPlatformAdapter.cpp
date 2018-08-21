#include "stdafx.hpp"
#include "vulkan.hpp"
#include "WindowsPlatformAdapter.hpp"
#include "little-engine/Logger.hpp"

#include <conio.h>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

namespace LittleEngine::Platform
{
    WindowsPlatformAdapter::WindowsPlatformAdapter(LoggerCore *logger)
        : PlatformAdapter(logger)
    {
        m_glfwLogger = this->logger().branch("glfw"s);
    }
    WindowsPlatformAdapter::~WindowsPlatformAdapter()
    {
        SafeDelete(m_glfwLogger);
    }

    std::string WindowsPlatformAdapter::platformName()
    {
        return "Windows"s;
    }

    bool WindowsPlatformAdapter::init()
    {
        logger().log("Initializing WindowsPlatformAdapter..."s);

        s_glfwLogger = this->m_glfwLogger;
        void (*error_callback)(int, const char*) = [](int error, const char* description)
        {
            std::ostringstream stream;
            stream << "Error: " << description;
            WindowsPlatformAdapter::s_glfwLogger->log(stream.str());
        };
        glfwSetErrorCallback(error_callback);
        logger().log("Configured GLFW's error callback."s);

        if (glfwInit() != GLFW_TRUE)
        {
            logger().log("Failed to initialize GLFW."s);
            return false;
        }
        logger().log("GLFW initialized."s);

        if (glfwVulkanSupported() != GLFW_TRUE)
        {
            logger().log("No vulkan-enabled devices."s);
            return false;
        }

        uint32_t count;
        const char **extensions = glfwGetRequiredInstanceExtensions(&count);

        return true;
    }
    void WindowsPlatformAdapter::shutdown()
    {
        logger().log("Shutting down WindowsPlatformAdapter..."s);
        glfwTerminate();
        glfwSetErrorCallback(nullptr);
        s_glfwLogger = nullptr;

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

    Logger *WindowsPlatformAdapter::s_glfwLogger = nullptr;
}
