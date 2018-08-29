#include "stdafx.hpp"
#include "GlfwPlatformAdapterImpl.hpp"

#include <conio.h>
#include <chrono>
#include <thread>
#include <sstream>

using namespace std::chrono_literals;

namespace LittleEngine::Platform
{
    GlfwPlatformAdapterImpl::GlfwPlatformAdapterImpl(Logger *logger)
        : m_logger(logger), m_glfwLogger(nullptr), m_inst(nullptr), m_window(nullptr)
    {
        m_glfwLogger = logger->branch(L"glfw");
    }
    GlfwPlatformAdapterImpl::~GlfwPlatformAdapterImpl()
    {
        SafeDelete(m_glfwLogger);
    }

    bool GlfwPlatformAdapterImpl::init()
    {
        m_logger->log(L"Initializing GlfwPlatformAdapter...");
        return init_glfwErrorCallback();
    }
    bool GlfwPlatformAdapterImpl::init_glfwErrorCallback()
    {
        s_glfwLogger = this->m_glfwLogger;
        void(*error_callback)(int, const char*) = [](int error, const char* description)
        {
            error;
            std::wstringstream stream;
            stream << L"Error: " << description;
            GlfwPlatformAdapterImpl::s_glfwLogger->log(stream.str().c_str());
        };
        glfwSetErrorCallback(error_callback);
        m_logger->log(L"Configured GLFW's error callback.");

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
            m_logger->log(L"Failed to initialize GLFW.");
        }
        else
        {
            m_logger->log(L"Initialized GLFW.");
            worked = init_vulkan();
            if (!worked)
            {
                m_logger->log(L"Terminating GLFW...");
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
            m_logger->log(L"No vulkan-enabled devices.");
        }
        else
        {
            m_logger->log(L"Vulkan is supported on your platform.");
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
            m_logger->log(L"Failed to retrieve required vulkan extensions list.");
            return false;
        }
        m_logger->log(L"Fetched required vulkan extensions:");
        for (size_t q = 0; q < extensionCount; q++)
        {
            std::wostringstream stream;
            stream << L"  - " << extensions[q];
            m_logger->log(stream.str().c_str());
        }

        VkInstanceCreateInfo createInfo;
        memset(&createInfo, 0, sizeof(createInfo));
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.enabledExtensionCount = extensionCount;
        createInfo.ppEnabledExtensionNames = extensions;

        auto worked = (vkCreateInstance(&createInfo, nullptr, &m_inst) == VK_SUCCESS);
        if (!worked)
        {
            m_logger->log(L"Failed to create vulkan instance.");
        }
        else
        {
            m_logger->log(L"Created vulkan instance.");
            worked = init_window();

            if (!worked)
            {
                m_logger->log(L"Destroying vulkan instance...");
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
            m_logger->log(L"Failed to create window.");
        }
        else
        {
            m_logger->log(L"Created window.");
        }
        return worked;
    }
    void GlfwPlatformAdapterImpl::shutdown()
    {
        m_logger->log(L"Shutting down GlfwPlatformAdapter...");

        glfwDestroyWindow(m_window);
        m_window = nullptr;

        vkDestroyInstance(m_inst, nullptr);
        m_inst = nullptr;

        glfwTerminate();

        glfwSetErrorCallback(nullptr);
        s_glfwLogger = nullptr;

        m_logger->log(L"GLFW terminated.");
    }

    void GlfwPlatformAdapterImpl::pollEvents()
    {
        m_logger->log(L"Polling window events...");
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
