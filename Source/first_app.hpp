#pragma once

#include "lvk_window.hpp"
#include "lvk_pipeline.hpp"
#include "lvk_device.hpp"

namespace lvk {
class FirstApp {
    
    public:
    static constexpr int WIDTH = 800;
    static constexpr int HEIGHT = 600;

    void run();

    private:
     LvkWindow lvkWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
     LvkDevice lvkDevice{lvkWindow};
     LvkPipeline lvkPipeline{
      lvkDevice, 
      "Shaders/simple_shader.vert.spv", 
      "Shaders/simple_shader.frag.spv", 
      LvkPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
};
} // namespace lvk