#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
int main(void)
{
    //initializing glfw 

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // creating a glfw window

    GLFWwindow* window = glfwCreateWindow(800, 600, "GKGEV2", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create GLFW Window" << std::endl;
        
        return -1;
    }
    glfwMakeContextCurrent(window);

    // initializing glad

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

        std::cout << "Failed to Initialize GLAD" << std::endl;
        return -1;
    }
    

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //loop for window to run (render loop)

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        //rendering components always comes in the render loop

        glClearColor(0.43f, 1.0f, 0.88f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
   
    //terminate the window

    glfwTerminate();
    return 0;
}

//for opengl to give size of the window through glfw
void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{

    glViewport(0, 0, 800, 600);
}

// key events example for glfw
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window, true);
    }
}