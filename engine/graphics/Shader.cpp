#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

#include "Shader.h"
#include <glm/gtc/type_ptr.hpp> // Для glm::value_ptr

namespace CacTus::Graphics {

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    std::string vertexSource = loadShaderSource(vertexPath);
    std::string fragmentSource = loadShaderSource(fragmentPath);
    
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

    m_programID = glCreateProgram();
    glAttachShader(m_programID, vertexShader);
    glAttachShader(m_programID, fragmentShader);
    glLinkProgram(m_programID);

    GLint success;
    glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(m_programID, 512, nullptr, infoLog);
        std::cerr << "[Error] Shader linking failed: " << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() {
    glDeleteProgram(m_programID);
}

void Shader::bind() const {
    glUseProgram(m_programID);
}

void Shader::unbind() const {
    glUseProgram(0);
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
    int location = glGetUniformLocation(m_programID, name.c_str());
    glUniform4f(location, v0, v1, v2, v3);
}

void Shader::setUniformMatrix4fv(const std::string& name, const glm::mat4& matrix) {
    int location = glGetUniformLocation(m_programID, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

std::string Shader::loadShaderSource(const std::string& filepath) {
    std::ifstream file(filepath);
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

GLuint Shader::compileShader(GLenum type, const std::string& source) {
    GLuint shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "[Error] Shader compilation failed: " << infoLog << std::endl;
    }

    return shader;
}

}