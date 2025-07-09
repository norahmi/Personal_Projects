cmake_minimum_required(VERSION 3.10)
project(OpenGLBasic)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add GLFW
add_subdirectory(libs/glfw-3.4)
include_directories(libs/glfw-3.4/include)

add_subdirectory(libs/stb_image)
include_directories(libs/stb_image)

# Add GLAD
include_directories(include)
add_library(glad src/glad.c)

# Optional: add GLM if used
include_directories(include/glm)

add_executable(OpenGLBasic 
    src/main.cpp
    src/Shader.cpp
    src/shapes_utils/ShapeType.cpp
    libs/stb_image/stb_image.cpp
)

# Link everything together
target_link_libraries(OpenGLBasic glad glfw stb_image ${CMAKE_DL_LIBS})
