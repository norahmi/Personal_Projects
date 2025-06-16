#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "ShapeType.h"

#include <iostream>
#include <cmath>

// Resize callback
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// Set close window to true if pressed 'esc'
void processInput(GLFWwindow* window);
// Create and compiler vertex shader object.
unsigned int createVertexShader();
// Create and compiler fragment shader object.
unsigned int createFragmentShader();
// Create and activate shader program object.
unsigned int activateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
// Prepare buffers for triangle.
void triangleSetup(unsigned int *VAO, unsigned int *VBO);
// Prepare buffers for rectangle.
void rectangleSetup(unsigned int *VAO, unsigned int *VBO, unsigned int *EBO);
// Set uniform dynamically for color.
void setUniformColor(int shaderProgram);
/**
 * @brief Set uniform dynamically for position.
 *        Moves to the right with packman effect.
 */
void setUniformPosition (int shaderProgram, int *counter, float *offset);


// Vertex Shader. 3D Vector that gets transformed into 4D Vector. 
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 vertexColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   vertexColor = aColor;\n"
    "}\0";

// Fragment Shader. 4D vector for color. RGBA where "A" is for alpha (opacity).
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 vertexColor;\n"
    "uniform vec4 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(vertexColor, 1.0);\n"
    "}\0";




int main() {
// ---------------------------GENERAL SET UP-----------------------------------------------
    glfwInit();
    // Means we are using GLFW 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Uses Core profile.

    // Create Window.
    GLFWwindow* window = glfwCreateWindow(800, 600, "Triangle", nullptr, nullptr);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    // Initialize GLAD (manages function pointers for OpenGL).
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "GLAD failed!\n";
        return -1;
    }
    
// ---------------------------SHADERS SET UP-----------------------------------------------

    // unsigned int vertexShader = createVertexShader();
    // unsigned int fragmentShader = createFragmentShader();
    // unsigned int shaderProgram = activateShaderProgram(vertexShader, fragmentShader);

    // Use Costume shader class instead.
    Shader myshader("../shaders/basic-vertex.vs", "../shaders/basic-fragment.fs");

// ---------------------------BUFFERS SET UP-----------------------------------------------
    unsigned int VBO,VAO,EBO;
    triangleSetup(&VAO, &VBO);
    // rectangleSetup(&VAO, &VBO, &EBO);

    // Position attribute.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbinds the VBO
    glBindVertexArray(0); // Unbinds the VAO

    // To view Unfilled shapes
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    
// ---------------------------RENDER LOOP--------------------------------------------------
    int counter = 0;
    float offset = 0;
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Sets the new color with which the buffer will be filled. 
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        // Clears the color buffer.
        glClear(GL_COLOR_BUFFER_BIT);

        // glUseProgram(shaderProgram);
        myshader.use();
        
        setUniformPosition(myshader.ID, &counter, &offset);
        setUniformColor(myshader.ID);
        
        glBindVertexArray(VAO);

        // Draws a triangle.
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // Draws a rectangle.
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        // Swaps buffer once back buffer ready to be rendered. 
        glfwSwapBuffers(window);
        // Checks for any even triggered and calls call back functions.
        glfwPollEvents(); 
    }

// ---------------------------CLEAN UP & TERMINATION---------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    // glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

unsigned int createVertexShader() {
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER); // -> type of shader we are creating (Vertex, Fragment or Geometry)
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // -> attach shader source code.
    glCompileShader(vertexShader);

    // Check compilation status.
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return vertexShader;
}

unsigned int createFragmentShader() {
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Check compilation status.
    int  success;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return fragmentShader;
}

unsigned int activateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int  success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER PROGRAM::LINKAGE FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}


void triangleSetup(unsigned int *VAO, unsigned int *VBO) {
    // Only Positions.
    // std::vector<float> triangle2D = getShapeVertices(ShapeType::Triangle); 

    // Positions and Colors.
    std::vector<float> triangle2D = getShapeVertices(ShapeType::ColoredTriangle);

    // Upside down triangle.
    // std::vector<float> triangle2D = getShapeVertices(ShapeType::UpsideDownTriangle);

    glGenVertexArrays(1, VAO);  
    glGenBuffers(1, VBO);

    glBindVertexArray(*VAO);

    // Binding the buffer. Can bind multiple buffers as long as they are different types.
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBufferData(GL_ARRAY_BUFFER, triangle2D.size() * sizeof(float), triangle2D.data(), GL_STATIC_DRAW);
}

void rectangleSetup(unsigned int *VAO, unsigned int *VBO, unsigned int *EBO) {
    std::vector<float> rectangle2D = getShapeVertices(ShapeType::Rectangle);
    unsigned int rectangleIndices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    glGenVertexArrays(1, VAO);  
    glGenBuffers(1, VBO);
    glGenBuffers(1, EBO);

    glBindVertexArray(*VAO);

    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glBufferData(GL_ARRAY_BUFFER, rectangle2D.size() * sizeof(float), rectangle2D.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rectangleIndices), rectangleIndices, GL_STATIC_DRAW);
}


void setUniformColor (int shaderProgram) {
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    float redValue = (cos(timeValue) / 2.0f) + 0.7f;
    float blueValue = (tan(timeValue) / 2.0f) + 0.6f;
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
    glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);
}

void setUniformPosition (int shaderProgram, int *counter, float *offset) {
    if (*counter % 100 == 0) {
        *offset += 0.1f;
        if (*offset > 1.5f) {
            *offset = -1.5f;
        }
        int offsetLocation = glGetUniformLocation(shaderProgram, "offset");
        glUniform1f(offsetLocation, *offset);
    }
    (*counter)++;
}