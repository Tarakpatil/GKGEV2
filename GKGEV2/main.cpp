//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColor;\n"
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos, 1.0);\n"
//"   ourColor = aColor;\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(ourColor, 1.0f);\n"
//"}\n\0";
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//
//void processInput(GLFWwindow* window);
//
//int main(void)
//{
//    //initializing glfw 
//
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    // creating a glfw window
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "GKGEV2", NULL, NULL);
//
//    if (window == NULL) {
//        std::cout << "Failed to create GLFW Window" << std::endl;
//        
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    // initializing glad
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//
//        std::cout << "Failed to Initialize GLAD" << std::endl;
//        return -1;
//    }
//    
//
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//
//
//
//    // vertex indices for the triangle
//
//    float vertices[] = {
//        // positions         // colors
//        -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom left, red
//         0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom right, green
//         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top, blue
//    };
//
//    // generating vertex array objects
//
//    unsigned int VAO;
//    glGenVertexArrays(1, &VAO);
//
//   
//    //generating vertex buffer objects
//
//    unsigned int VBO;
//    glGenBuffers(1, &VBO);
//
//
//    //Vertex shader
//    unsigned int vertexShader;
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//    //compiling the vertex shader
//
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    //compiling the fragment shader
//
//    unsigned int fragmentShader;
//    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    // combining the shaders with shader program
//
//    unsigned int shaderProgram;
//    shaderProgram = glCreateProgram();
//
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//
//    // Linking the program
//
//    glLinkProgram(shaderProgram);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    //Linking vertex attributes
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    //loop for window to run (render loop)
//
//    while (!glfwWindowShouldClose(window))
//    {
//        processInput(window);
//
//        //rendering components always comes in the render loop
//
//        glClearColor(0.43f, 1.0f, 0.88f, 1.0f);
//
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        //using the program 
//
//        glUseProgram(shaderProgram);
//
//        double timeValue = glfwGetTime();
//        double greenValue = sin(timeValue) / 2.0f + 0.5f;
//
//
//        //using vao here at end after using program
//
//        glBindVertexArray(VAO);
//
//        // drawing the array/traingle
//
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        glfwSwapBuffers(window);
//
//        glfwPollEvents();
//    }
//
//    //deleting the shaders
//    
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    //terminate the window
//
//    glfwTerminate();
//    return 0;
//}
//
////for opengl to give size of the window through glfw
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
//{
//
//    glViewport(0, 0, width, height);
//}
//
//// key events example for glfw
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE))
//    {
//        glfwSetWindowShouldClose(window, true);
//    }
//}