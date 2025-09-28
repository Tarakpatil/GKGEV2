// Shader.h
// Header file for the Shader class

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    unsigned int ID;  // The OpenGL program ID

    // Constructor: Takes paths to vertex and fragment shader files
    Shader(const char* vertexPath, const char* fragmentPath);

    // Destructor: Clean up the program
    ~Shader();

    // Activate the shader program
    void use() const;

    // Utility functions for setting uniforms
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    // Add more for vec2, vec3, mat4, etc., using glUniform* functions

private:
    // Helper to check for compile/link errors
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif // SHADER_H
