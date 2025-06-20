#pragma once

#include "lvk_device.hpp"

//std
#include <string>
#include <vector>

namespace lvk {

  struct PipelineConfigInfo {};

  class LvkPipeline {
    public:
      LvkPipeline(
        LvkDevice &device, 
        const std::string& vertFilepath, 
        const std::string& fragFilepath, 
        const PipelineConfigInfo& configInfo);
      ~LvkPipeline() {}

      LvkPipeline(const LvkPipeline&) = delete;
      void operator=(const LvkPipeline&) = delete;

      static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);


    private:
      static std::vector<char> readFile(const std::string& filepath);

      void createGraphicsPipeline(
        const std::string& vertFilepath, 
        const std::string& fragFilepath,
        const PipelineConfigInfo& configInfo);

      void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

      LvkDevice& lvkDevice;
      VkPipeline graphicsPipeline;
      VkShaderModule vertShaderModule;
      VkShaderModule fragShaderModule;
  };
}