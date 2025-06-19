cmake_minimum_required(VERSION 3.11.0)

project(vulkan_practice VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp")

add_executable(vulkan_practice ${SOURCE})