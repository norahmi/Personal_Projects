#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

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


// Vertex Shader. 3D Vector that gets transformed into 4D Vector. 
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

// Fragment Shader. 4D vector for color. RGBA where "A" is for alpha (opacity).
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
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
    
    // Initialize GLAD (manages function pointers for OpenGL).
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "GLAD failed!\n";
        return -1;
    }
    
    // Sets rendering window's size.
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

// ---------------------------BUFFERS SET UP-----------------------------------------------

    // 2D Triangle.
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    unsigned int VBO; // Vertex Buffer Object -> OpenGL object of type GL_ARRAY_BUFFER.
    glGenBuffers(1, &VBO);
    
    unsigned int VAO; // Vertex Array Object -> mandatory when using 'core'
    glGenVertexArrays(1, &VAO);  

    // Binding the buffer. Can bind multiple buffers as long as they are different types.
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);

    // Copies the vertex data into the buffer's memory.
    // GL_STATIC_DRAW: indicates how the graphic card is to manage the given data.
    // In this case the data is set once and used multiple times.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

// ---------------------------SHADERS SET UP-----------------------------------------------

    unsigned int vertexShader = createVertexShader();
    unsigned int fragmentShader = createFragmentShader();
    unsigned int shaderProgram = activateShaderProgram(vertexShader, fragmentShader);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    
// ---------------------------RENDER LOOP--------------------------------------------------
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Sets the new color with which the buffer will be filled. 
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        // // Clears the color buffer.
        glClear(GL_COLOR_BUFFER_BIT);

        // Set correct shader, bind to needed VAO and draw triangle.
        glUseProgram(shaderProgram);
        // Seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swaps buffer once back buffer ready to be rendered. 
        glfwSwapBuffers(window);

        // Checks for any even triggered and calls call back functions.
        glfwPollEvents(); 

        // static int frame = 0;
        // std::cout << "Frame: " << frame++ << "\r";
    }

// ---------------------------CLEAN UP-----------------------------------------------------
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
