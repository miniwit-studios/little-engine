#include "stdafx.hpp"
#include "GlfwPlatformAdapterImpl.hpp"

#include <conio.h>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

namespace LittleEngine::Platform
{
    GlfwPlatformAdapterImpl::GlfwPlatformAdapterImpl(Logger *logger)
        : m_logger(logger), m_glfwLogger(nullptr), m_inst(nullptr), m_window(nullptr)
    {
        m_glfwLogger = logger->branch("glfw"s);
    }
    GlfwPlatformAdapterImpl::~GlfwPlatformAdapterImpl()
    {
        SafeDelete(m_glfwLogger);
    }

    bool GlfwPlatformAdapterImpl::init()
    {
        m_logger->log("Initializing GlfwPlatformAdapter..."s);
        return init_glfwErrorCallback();
    }
    bool GlfwPlatformAdapterImpl::init_glfwErrorCallback()
    {
        s_glfwLogger = this->m_glfwLogger;
        void(*error_callback)(int, const char*) = [](int error, const char* description)
        {
            std::ostringstream stream;
            stream << "Error: " << description;
            GlfwPlatformAdapterImpl::s_glfwLogger->log(stream.str());
        };
        glfwSetErrorCallback(error_callback);
        m_logger->log("Configured GLFW's error callback."s);

        auto worked = init_glfw();
        if (!worked)
        {
            glfwSetErrorCallback(nullptr);
            s_glfwLogger = nullptr;
        }
        return worked;
    }
    bool GlfwPlatformAdapterImpl::init_glfw()
    {
        auto worked = (glfwInit() == GLFW_TRUE);
        if (!worked)
        {
            m_logger->log("Failed to initialize GLFW."s);
        }
        else
        {
            m_logger->log("Initialized GLFW."s);
            worked = init_vulkan();
            if (!worked)
            {
                m_logger->log("Terminating GLFW..."s);
                glfwTerminate();
            }
        }
        return worked;
    }
    bool GlfwPlatformAdapterImpl::init_vulkan()
    {
        auto worked = (glfwVulkanSupported() == GLFW_TRUE);
        if (!worked)
        {
            m_logger->log("No vulkan-enabled devices."s);
        }
        else
        {
            m_logger->log("Vulkan is supported on your platform."s);
            worked = init_vulkanInstance();
        }
        return worked;
    }
    bool GlfwPlatformAdapterImpl::init_vulkanInstance()
    {
        uint32_t extensionCount;
        const char **extensions = glfwGetRequiredInstanceExtensions(&extensionCount);
        if (extensions == nullptr)
        {
            m_logger->log("Failed to retrieve required vulkan extensions list."s);
            return false;
        }
        m_logger->log("Fetched required vulkan extensions:"s);
        for (size_t q = 0; q < extensionCount; q++)
        {
            m_logger->log("  - "s + extensions[q]);
        }

        VkInstanceCreateInfo createInfo;
        memset(&createInfo, 0, sizeof(createInfo));
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.enabledExtensionCount = extensionCount;
        createInfo.ppEnabledExtensionNames = extensions;

        auto worked = (vkCreateInstance(&createInfo, nullptr, &m_inst) == VK_SUCCESS);
        if (!worked)
        {
            m_logger->log("Failed to create vulkan instance."s);
        }
        else
        {
            m_logger->log("Created vulkan instance."s);
            worked = init_window();

            if (!worked)
            {
                m_logger->log("Destroying vulkan instance..."s);
                vkDestroyInstance(m_inst, nullptr);
            }
        }
        return worked;
    }
    bool GlfwPlatformAdapterImpl::init_window()
    {
        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        m_window = glfwCreateWindow(800, 600, "Vulkan Window", NULL, NULL);
        auto worked = (m_window != nullptr);

        if (!worked)
        {
            m_logger->log("Failed to create window."s);
        }
        else
        {
            m_logger->log("Created window."s);
        }
        return worked;
    }
    void GlfwPlatformAdapterImpl::shutdown()
    {
        m_logger->log("Shutting down GlfwPlatformAdapter..."s);

        glfwDestroyWindow(m_window);
        m_window = nullptr;

        vkDestroyInstance(m_inst, nullptr);
        m_inst = nullptr;

        glfwTerminate();

        glfwSetErrorCallback(nullptr);
        s_glfwLogger = nullptr;

        m_logger->log("GLFW terminated."s);
    }

    void GlfwPlatformAdapterImpl::pollEvents()
    {
        m_logger->log("Polling window events..."s);
        while (!glfwWindowShouldClose(m_window))
        {
            glfwPollEvents();
        }
    }

    void GlfwPlatformAdapterImpl::terminal_pauseForKey()
    {
        while (!_kbhit())
        {
            std::this_thread::sleep_for(10ms);
        }
        _getch();
    }

    Logger *GlfwPlatformAdapterImpl::s_glfwLogger = nullptr;
}
