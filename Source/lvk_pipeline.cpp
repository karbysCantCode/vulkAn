#include "lvk_pipeline.hpp"

//std
#include <fstream>
#include <stdexcept>
#include <iostream>

namespace lvk {

  LvkPipeline::LvkPipeline(
        LvkDevice &device, 
        const std::string& vertFilepath, 
        const std::string& fragFilepath, 
        const PipelineConfigInfo& configInfo) :lvkDevice(device) {
    createGraphicsPipeline(vertFilepath,fragFilepath, configInfo);
  }

  std::vector<char> LvkPipeline::readFile(const std::string& filepath) {
    // open the file, reading at the very end (ate) and open as binary
    std::ifstream file{filepath, std::ios::ate | std::ios::binary}; 

    if (!file.is_open()) {
      throw std::runtime_error("failed to open file: " + filepath);
    }
    
    //get size of file from the readers current position, returns num in bytes
    size_t fileSize = static_cast<size_t>(file.tellg());
    std::vector<char> buffer(fileSize); // buffer to load the file into ram

    //return to start
    file.seekg(0);
    //read the whole file (filesize num of bytes) into the buffer
    file.read(buffer.data(), fileSize);


    file.close();
    return buffer;
  }

  void LvkPipeline::createGraphicsPipeline(
    const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) {

      auto vertCode = readFile(vertFilepath);
      auto fragCode = readFile(fragFilepath);

      std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
      std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
    }

    void LvkPipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
      VkShaderModuleCreateInfo createInfo{};
      createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
      createInfo.codeSize = code.size();
      createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

      if (vkCreateShaderModule(lvkDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
        throw std::runtime_error("failed to create shader module");
      }
    }


    PipelineConfigInfo LvkPipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
      PipelineConfigInfo configInfo{};

      return configInfo;
    }
}