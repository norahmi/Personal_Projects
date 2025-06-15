cmake_minimum_required(VERSION 3.10)
project(OpenGLCube)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GLFW
add_subdirectory(libs/glfw-3.4)
include_directories(libs/glfw-3.4/include)

# Add GLAD
include_directories(include)
add_library(glad src/glad.c)

# Optional: add GLM if used
include_directories(libs/glm)

# Main executable
add_executable(OpenGLCube src/main.cpp)

# Link everything together
target_link_libraries(OpenGLCube glad glfw ${CMAKE_DL_LIBS})
