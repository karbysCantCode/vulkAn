#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace vk {
    
    class VkWindow {
        
        private:
        GLFWwindow *window;
    };
}