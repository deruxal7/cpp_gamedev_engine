#pragma once

#include <string>
#include <GL/glew.h>

namespace CacTus::Graphics {

class Shader {

public:

    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void bind() const;
    void unbind() const;
    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:

    GLuint m_programID;

    std::string loadShaderSource(const std::string& filepath);
    GLuint compileShader(GLenum type, const std::string& source);

};

}