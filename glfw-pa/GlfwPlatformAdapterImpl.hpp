#pragma once
#include "vulkan.hpp"
#include "little-engine/Logger.hpp"

namespace LittleEngine::Platform
{
    class GlfwPlatformAdapterImpl
    {
    public:
        GlfwPlatformAdapterImpl(Logger *logger);
        ~GlfwPlatformAdapterImpl();

        bool init();
        void shutdown();

        void pollEvents();

        void terminal_pauseForKey();

    private:
        Logger *m_logger, *m_glfwLogger;
        static Logger *s_glfwLogger;

        VkInstance m_inst;
        GLFWwindow *m_window;

        bool init_glfwErrorCallback();
        bool init_glfw();
        bool init_vulkan();
        bool init_vulkanInstance();
        bool init_window();
    };
}
