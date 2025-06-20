#include "first_app.hpp"

namespace lvk{

void FirstApp::run() {
    while (!lvkWindow.shouldClose()) {
        glfwPollEvents();
    }
}
} // namespace vk
