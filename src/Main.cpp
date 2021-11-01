#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// The callback function to call when the GLFW window is resized.
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// The callback function called within the rendering loop to process events 
// (inputs).
// This function is called when GLFW pools the window system for events 
// (glfwPollEvents function at the end of the rendering loop).
void handleKeyInputs(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Closes the window when the escape key is pressed.
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) { glfwSetWindowShouldClose(window, 1); }
}

int main() {

    // Configuring GLFW.
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Required for Mac OS X.
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // Creating a GLFW window.
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL app", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Sets the callback function to use when the window is resized.
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    // Sets the callback function that GLFW needs to call upon key inputs.
    glfwSetKeyCallback(window, handleKeyInputs);

    // Initializing GLAD (before any OpenGL stuff).
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // OPENGL CODE CAN START HERE!

    // Setting the viewport used for rendering.
    glViewport(0, 0, 800, 600);

    // THE RENDERING LOOP!
    while(!glfwWindowShouldClose(window)) {

        // Clear screen with an opaque black.
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        // RENDERING HERE!


        // END RENDERING HERE!

        // Swapping drawing buffers and shit!
        glfwSwapBuffers(window);
        // Checking for events and calling callback event handling functions if they were set.
        glfwPollEvents();
    }

    // Free resources allocated by GLFW.
    glfwTerminate();
    // Exiting program successfully.
	return 0;
}