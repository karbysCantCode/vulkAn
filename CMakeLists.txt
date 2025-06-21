cmake_minimum_required(VERSION 3.12.0)
project(vulkan_practice VERSION 0.1.0 LANGUAGES C CXX)


set(BUILD_MODE "DEBUG") # either "DEBUG" or "RELEASE"


file(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp") #add cpp files to a variable that'll compile to exe
add_executable(vulkan_practice ${SOURCE})# yup


target_include_directories(vulkan_practice PRIVATE #include headers
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glfw/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glm"
    "$ENV{VULKAN_SDK}/Include"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source"
)


add_subdirectory(Vendor/glfw) #compile glfw to lib
target_link_libraries(vulkan_practice PRIVATE #link glfw and vulkan lib
    glfw
    "$ENV{VULKAN_SDK}/Lib/vulkan-1.lib"
)


target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC VK_SDK_PATH="$ENV{VULKAN_SDK}")

if(BUILD_MODE STREQUAL "RELEASE")
  target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC SHADER_PATH="./Shaders/")
else()
  target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC SHADER_PATH="${CMAKE_CURRENT_SOURCE_DIR}/Shaders/")
endif()


#attach the cmake script that compiles the shaders to execute at build time
add_custom_target(compile_shaders ALL
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/CMakeShaderCompiler.txt)
#pretty much calling the "function" above!
add_dependencies(vulkan_practice compile_shaders)





#copy shaders folder to build folder
add_custom_target(copy_shaders ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/Shaders"
            "${CMAKE_BINARY_DIR}/Shaders"
)
#pretty much calling the "function" above!
add_dependencies(vulkan_practice copy_shaders)