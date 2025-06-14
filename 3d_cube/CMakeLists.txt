cmake_minimum_required(VERSION 3.10)
project(OpenGLCube)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include GLAD, GLFW, and GLM headers
include_directories(include libs/glfw/include)

# Add GLAD source file
add_library(glad src/glad.c)
add_subdirectory(libs/glfw-3.4)

# Create executable
add_executable(OpenGLCube src/main.cpp)

target_link_libraries(OpenGLCube glad glfw ${CMAKE_DL_LIBS})
