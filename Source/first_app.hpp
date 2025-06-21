#pragma once

#include "lvk_window.hpp"
#include "lvk_pipeline.hpp"
#include "lvk_device.hpp"
#include "lvk_swap_chain.hpp"

// std
#include <memory>
#include <vector>

namespace lvk {
class FirstApp {
    
    public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    FirstApp();
    ~FirstApp();
     
    FirstApp(const FirstApp &) = delete;
    FirstApp &operator=(const FirstApp &) = delete;
    void run();

    private:
    void createPipelineLayout();
    void createPipeline();
    void createCommandBuffers();
    void drawFrame();
     LvkWindow lvkWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
     LvkDevice lvkDevice{lvkWindow};
     LvkSwapChain lvkSwapChain{lvkDevice, lvkWindow.getExtent()};
     std::unique_ptr<LvkPipeline> lvkPipeline;
     VkPipelineLayout pipelineLayout;
     std::vector<VkCommandBuffer> commandBuffers;
};
} // namespace lvk