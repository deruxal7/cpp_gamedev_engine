#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include <stdexcept>
#include <vector>

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
        GLint logLength = 0;
        glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<char> infoLog(logLength > 0 ? logLength : 1);
        glGetProgramInfoLog(m_programID, logLength, nullptr, infoLog.data());
        std::cerr << "[Error] Shader linking failed: " << infoLog.data() << std::endl;
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
    if (location == -1) {
        // uniform not found (might be optimized out) - skip
        return;
    }
    glUniform4f(location, v0, v1, v2, v3);
}

void Shader::setUniformMatrix4fv(const std::string& name, const glm::mat4& matrix) {
    int location = glGetUniformLocation(m_programID, name.c_str());
    if (location == -1) {
        // uniform not found - skip
        return;
    }
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

std::string Shader::loadShaderSource(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open shader file: " + filepath);
    }
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
        GLint logLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<char> infoLog(logLength > 0 ? logLength : 1);
        glGetShaderInfoLog(shader, logLength, nullptr, infoLog.data());
        std::cerr << "[Error] Shader compilation failed: " << infoLog.data() << std::endl;
    }

    return shader;
}

}