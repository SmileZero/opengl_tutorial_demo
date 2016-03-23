//
//  main.cpp
//  opengltest
//
//  Created by yan_runchen on 2016/03/23.
//  Copyright © 2016年 yan_runchen. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stdexcept>
#include <sstream>
#include <fstream>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

GLfloat triangleData[] = {
    0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
   -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
};

GLfloat vertexData[]  = {
    
    // 前面
    -0.5f, -0.5f, -0.5f,   1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,
    0.5f, -0.5f,  -0.5f,   1.0f, 0.0f, 0.0f,
    0.5f,  0.5f,  -0.5f,   1.0f, 0.0f, 0.0f,
    
    // 右面
    0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,   0.0f, 1.0f, 0.0f,
    0.5f, -0.5f,  0.5f,   0.0f, 1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,   0.0f, 1.0f, 0.0f,
    
    // 奥面
    0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 1.0f,
    0.5f,  0.5f, 0.5f,   0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f, 0.5f,   0.0f, 0.0f, 1.0f,
    
    // 左面
    -0.5f, -0.5f,  0.5f,   1.0f, 1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,   1.0f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,   1.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 1.0f,
};

GLuint gVAO = 0;
GLuint gVBO = 0;

GLfloat gDegreesRotated = 0.0f;
GLfloat gTranslate = -4.f;

static void OnError(int errorCode, const char* msg) {
    throw std::runtime_error(msg);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

GLuint createShader(GLenum type, const std::string& filePath)
{
    ifstream f;
    f.open(filePath.c_str(), ios::in | ios::binary);
    if(!f.is_open()){
        throw std::runtime_error("Failed to open file");
    }
    
    stringstream buffer;
    buffer << f.rdbuf();
    
    GLuint shader = glCreateShader(type);
    const char* shaderCode = buffer.str().c_str();
    glShaderSource(shader, 1, (const GLchar**)(&shaderCode), nullptr);
    glCompileShader(shader);
    return shader;
}

int main(int argc, char ** argv) {
    cout << "Begin" << endl;
    
    glfwSetErrorCallback(OnError);
    if(!glfwInit()){
        throw std::runtime_error("glfwInit failed");
    }
    
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(500, 500, "Test", nullptr, nullptr);
    
    if(!window){
        glfwTerminate();
        throw std::runtime_error("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    }
    
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit()) {
        throw std::runtime_error("glewInit failed");
    }
    
    glfwSwapInterval(1);
    
    glfwSetKeyCallback(window, key_callback);
    
    cout << "OpenGL version: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    cout << "Vendor: " << glGetString(GL_VENDOR) << endl;
    cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glGenVertexArrays(1, &gVAO);
    glBindVertexArray(gVAO);
    
    glGenBuffers(1, &gVBO);
    glBindBuffer(GL_ARRAY_BUFFER, gVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(triangleData), triangleData, GL_STATIC_DRAW);
    
    GLuint vertexShader   = createShader(GL_VERTEX_SHADER, "vertex_shader.vsh");
    GLuint fragmentShader = createShader(GL_FRAGMENT_SHADER, "fragment_shader.fsh");
    
    GLuint shaderProgram  = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    
    GLint posAttrib = glGetAttribLocation(shaderProgram, "vert");
    
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), nullptr);
    
    GLint colorAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colorAttrib);
    glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    
    glm::mat4 camera = glm::lookAt(glm::vec3(0.f, 0.f, 5.f), glm::vec3(0,0,0), glm::vec3(0,1,0));
    GLint cameraAttrib = glGetUniformLocation(shaderProgram, "camera");
    glUniformMatrix4fv(cameraAttrib, 1, GL_FALSE, glm::value_ptr(camera));
    
    glm::mat4 projection = glm::perspective(glm::radians(65.0f), 500.0f/500.0f, 0.1f, 100.0f);
    GLint projectionAttrib = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(projectionAttrib, 1, GL_FALSE, glm::value_ptr(projection));
    
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        gTranslate += 0.01f;
        gDegreesRotated += 1.0f;
        while(gTranslate >= 4.f ) gTranslate = -4.f;
        while(gDegreesRotated > 360.0f) gDegreesRotated -= 360.0f;
        
        glm::mat4 model = glm::translate(glm::mat4(), glm::vec3(0.f, gTranslate, 0.f));
        
        model =  model * glm::rotate(glm::mat4(), glm::radians(gDegreesRotated), glm::vec3(0, 1, 0));
        
        GLint modelAttrib = glGetUniformLocation(shaderProgram, "model");
        glUniformMatrix4fv(modelAttrib, 1, GL_FALSE, glm::value_ptr(model));
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4 * 4);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);
    
    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    
    glDeleteBuffers(1, &gVBO);
    glDeleteVertexArrays(1, &gVAO);
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
    return 0;
}
