#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp> // Убедитесь, что GLM подключен здесь

namespace CacTus::Graphics {

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void bind() const;
    void unbind() const;

    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void setUniformMatrix4fv(const std::string& name, const glm::mat4& matrix); // Добавляем функцию для установки матрицы

private:
    GLuint m_programID;

    std::string loadShaderSource(const std::string& filepath);
    GLuint compileShader(GLenum type, const std::string& source);
};

}