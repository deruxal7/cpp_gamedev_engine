# Required version of cmake
cmake_minimum_required(VERSION 3.10)

# Project name
project(CacTusEngine)

# Set C++ standart to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Ищем зависимости
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Включаем директории для библиотек
include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
    engine/graphics/include
    engine/core/include
)

# Указываем исходники для движка
set(ENGINE_SOURCES
    engine/core/Window.cpp
    engine/core/EntityManager.cpp
    engine/core/Entity.cpp
    engine/graphics/Renderer.cpp
    engine/graphics/Shader.cpp
)

# Конфигурирует шейдеры
configure_file(engine/graphics/shaders/vertex.glsl ${CMAKE_BINARY_DIR}/engine/graphics/shaders/vertex.glsl COPYONLY)
configure_file(engine/graphics/shaders/fragment.glsl ${CMAKE_BINARY_DIR}/engine/graphics/shaders/fragment.glsl COPYONLY)
configure_file(engine/graphics/textures/cat.png ${CMAKE_BINARY_DIR}/textures/cat.png COPYONLY)

# Указываем исходники для тестовой игры
set(TESTGAME_SOURCES
    testgame/main.cpp
)

# Собираем основной исполняемый файл
add_executable(CacTusEngine
    ${ENGINE_SOURCES}
    ${TESTGAME_SOURCES}
)

# Линкуем библиотеки
target_link_libraries(CacTusEngine
    GLEW::GLEW
    OpenGL::GL
    SDL2::SDL2
    SDL2_image
)
