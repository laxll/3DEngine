#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

#include "shaderClass.h"


// Notes
/* 

1.  Initialize Opengl and window context
2.  Shader Program of Vertex and Fragment 
3.  Define vertex data
4.  Generate and Bind VAO 
5.  Generate and Bind VBO 
6.  Set Vertex Attribute Pointers
7.  Generate & Bind EBO (If needed)
8.  Unbind VAO and VBO
9.  Render
10. Clean Up



*/
int main() {

    //opengl context
    glfwInit();
    
    //window context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Bindow", NULL, NULL);
    if (window == NULL) {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Load OpenGL functions using glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cerr << "Failed to initialize GLAD" << endl;
        return -1;
    }


    // Shader initialization
  
  



    // Define vertex
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,  // Bottom left
         0.5f, -0.5f, 0.0f,  // Bottom right
         0.5f,  0.5f, 0.0f,  // Top right
        -0.5f,  0.5f, 0.0f   // Top left
    };


    
     // Indices
    GLuint indices[] = {
         0, 1, 2,  // First triangle
         2, 3, 0   // Second triangle
    };


    // Generate VAO , VBO and etc..

    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);


    // Binding
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);


    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    // Set Vertex Attribute Pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    // Unbinding VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Shader setup
    Shader shaderProgram("shaders/default.vert", "shaders/default.frag");


    cout << "Well it worked!!" << endl;
    while (!glfwWindowShouldClose(window)) {

        // Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  //bg color
        glClear(GL_COLOR_BUFFER_BIT);
        

        
        // Use the shader setup we have setup earlier
        shaderProgram.Activate();


        // Activates the setup of buffers
        glBindVertexArray(VAO); 


        // draws
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //glDrawArrays(GL_TRIANGLES, 3, 3); // Draw inner triangle

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}