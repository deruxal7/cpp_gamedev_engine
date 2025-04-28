cmake_minimum_required(VERSION 3.10)
project(CacTusEngine)

set(CMAKE_CXX_STANDARD 17)

# Ищем зависимости
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

# Включаем директории для библиотек
include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIR}
    engine/graphics
    engine/core
    engine/graphics/shaders
)

# Указываем исходники для движка
set(ENGINE_SOURCES
    engine/core/Window.cpp
    engine/core/EntityManager.cpp
    engine/core/Entity.cpp
    engine/graphics/Renderer.cpp
    engine/graphics/Shader.cpp
    engine/graphics/shaders
)

# Конфигурирует шейдеры
configure_file(engine/graphics/shaders/vertex.glsl ${CMAKE_BINARY_DIR}/engine/graphics/shaders/vertex.glsl COPYONLY)
configure_file(engine/graphics/shaders/fragment.glsl ${CMAKE_BINARY_DIR}/engine/graphics/shaders/fragment.glsl COPYONLY)

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
)
